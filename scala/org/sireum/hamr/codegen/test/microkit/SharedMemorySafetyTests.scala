package org.sireum.hamr.codegen.test.microkit

// Regression tests for the shared memory defects reported by an external review of INSPECTA
// (Red Balloon Security) and designed out in hamr/codegen/doc/SharedMemorySafety-design.md:
//
//   F1  array copies used the model's declared Data_Size, not the type's size
//   F3  a shared memory region was sized for one element, not the queue it holds
//   F4  the two ends of a region were never checked to agree on its layout, and a peer's
//       invalid enum or bool bit pattern reached the receiver
//
// Each test generates models/SharedMemorySafety -- whose types give every defect something
// to hit -- and checks the generated system: codegen's lint, the generated C compiled and run
// on the host (models/SharedMemorySafety/harness/harness.c), and the system description.
// The C checks need a host C compiler and are cancelled without one.
//
// The harness also fails against code generated before the fix (verified when the fix was
// made): both large queues overflow their regions, a wrong Data_Size overflows the
// receiver's buffer, and all three invalid values are delivered.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.hamr.ir
import org.sireum.hamr.ir.Aadl
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class SharedMemorySafetyTests extends TestSuite {

  val modelDir: Os.Path = MicrokitTestUtil.resourcesDir / "models" / "SharedMemorySafety"
  val sysmlDir: Os.Path = modelDir / "sysml"
  val harness: Os.Path = modelDir / "harness" / "harness.c"
  val scratch: Os.Path = Os.tempDir() / "hamr-shared-memory-safety-test"

  val dataSize: String = "Memory_Properties::Data_Size"

  def loadModel(): Aadl =
    TestUtil.getModel(Some(sysmlDir / ".slang" / "top_impl_Instance.json"), None(), sysmlDir, ISZ(), "sms", F)

  def runCodegen(model: Aadl, out: Os.Path): Reporter = {
    out.removeAll()
    val opts = MicrokitTests.baseOptions(
      workspaceRootDir = Some(sysmlDir.canon.value),
      packageName = Some("sms"),
      outputDir = Some(out.canon.value),
      slangOutputDir = Some((out / "slang").value),
      slangOutputCDir = Some((out / "c").value),
      sel4OutputDir = Some((out / "microkit").value))
    val reporter = Reporter.create
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    CodeGen.codeGen(model, T, opts, ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins,
      store, reporter, (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)
    return reporter
  }

  // Replace the properties of one data type in the model.
  def withProperties(model: Aadl, classifier: String, f: ISZ[ir.Property] => ISZ[ir.Property]): Aadl =
    model(dataComponents = for (c <- model.dataComponents) yield
      if (c.classifier.nonEmpty && c.classifier.get.name == classifier) c(properties = f(c.properties)) else c)

  def dataSizeProperty(bits: Z): ir.Property =
    ir.Property(
      name = ir.Name(ISZ(dataSize), None()),
      propertyValues = ISZ(ir.UnitProp(value = bits.string, unit = Some("bits"))),
      appliesTo = ISZ())

  // Generated once and shared by the tests that inspect or compile the output.
  lazy val generated: Os.Path = {
    val out = scratch / "generated"
    val r = runCodegen(loadModel(), out)
    r.printMessages()
    assert(!r.hasError, "codegen of models/SharedMemorySafety reported errors")
    out / "microkit"
  }

  lazy val cc: Option[String] = {
    val c = ISZ[String]("clang", "cc", "gcc").filter(n => proc"which $n".run().ok)
    if (c.isEmpty) None() else Some(c(0))
  }

  // The generated queue header includes <printf.h> when no sDDF/libvmm is on the include
  // path; a host build has neither, so supply an empty one.
  lazy val hostStub: Os.Path = {
    val d = scratch / "hoststub"
    d.mkdirAll()
    (d / "printf.h").writeOver("")
    d
  }

  def compile(extraFlags: ISZ[String], sources: ISZ[Os.Path], output: Option[Os.Path]): OsProto.Proc.Result = {
    val types = generated / "types"
    val outArgs: ISZ[String] = output match {
      case Some(o) => ISZ("-o", o.value)
      case _ => ISZ("-fsyntax-only")
    }
    return Os.proc(ISZ[String](cc.get, "-std=c11", "-D_FORTIFY_SOURCE=0", "-Wall", "-Wno-unused-function",
      s"-I${(types / "include").value}", s"-I${hostStub.value}") ++ extraFlags ++ outArgs ++
      (for (s <- sources) yield s.value)).run()
  }

  def queueSources: ISZ[Os.Path] = Os.Path.walk(generated / "types" / "src", F, F, p => p.ext == string"c")

  // ------------------------------------------------------------------------------------------
  // D1: sizes come from the type; a declared Data_Size is checked, not trusted
  // ------------------------------------------------------------------------------------------

  "F1/D1: a Data_Size that disagrees with the type's size is a codegen error" in {
    // 5 bytes: what a developer gets by adding up Padded_i's fields, ignoring padding (F2)
    val model = withProperties(loadModel(), "SharedMemorySafety::Padded_i", ps => ps :+ dataSizeProperty(40))
    val r = runCodegen(model, scratch / "wrong-size")
    assert(r.hasError, "a wrong Data_Size was accepted")
    val msgs = r.errors.elements.map(_.text.value)
    assert(msgs.exists(m => m.contains(s"$dataSize of SharedMemorySafety::Padded_i is 5 bytes") &&
      m.contains("its Microkit size is 16 bytes")), s"unexpected errors: $msgs")
  }

  "F1/D1: a Data_Size that matches the type's size is accepted" in {
    val model = withProperties(loadModel(), "SharedMemorySafety::Padded_i", ps => ps :+ dataSizeProperty(128))
    val r = runCodegen(model, scratch / "matching-size")
    r.printMessages()
    assert(!r.hasError, "a correct Data_Size was rejected")
  }

  "D3: an array without a declared dimension is a codegen error" in {
    def without(names: ISZ[String]): Aadl =
      withProperties(loadModel(), "SharedMemorySafety::BigArray", ps => ps.filter(p => !names.elements.contains(p.name.name(0))))

    // a Fixed array with no dimension: rejected by HAMR's common type resolver
    val fixed = runCodegen(without(ISZ("Data_Model::Dimension")), scratch / "no-dimension-fixed")
    assert(fixed.hasError, "a Fixed array without a dimension was accepted")
    val fixedMsgs = fixed.errors.elements.map(_.text.value)
    assert(fixedMsgs.exists(m => m.contains("Dimensions must be provided") && m.contains("BigArray")), s"unexpected errors: $fixedMsgs")

    // no size kind and no dimension: an unbounded array, rejected by the Microkit lint (D3)
    val unbounded = runCodegen(without(ISZ("Data_Model::Dimension", "HAMR::Array_Size_Kind")), scratch / "no-dimension-unbounded")
    assert(unbounded.hasError, "an unbounded array was accepted")
    val unboundedMsgs = unbounded.errors.elements.map(_.text.value)
    assert(unboundedMsgs.exists(m => m.contains("SharedMemorySafety::BigArray does not declare its dimension")),
      s"unexpected errors: $unboundedMsgs")
  }

  "F1/D1: array copies use the type's own size" in {
    val header = (generated / "types" / "include" / "sb_aadl_types.h").read
    assert(ops.StringOps(header).contains(
      "#define SharedMemorySafety_BigArray_BYTE_SIZE (sizeof(SharedMemorySafety_BigArray))"))
  }

  // ------------------------------------------------------------------------------------------
  // D4, D5, D6: compiled and run on the host
  // ------------------------------------------------------------------------------------------

  "D4/D5: the generated C agrees with HAMR's layout and every queue fits its region" in {
    if (cc.isEmpty) cancel("no host C compiler")
    val r = compile(ISZ(), queueSources, None())
    assert(r.ok, s"generated queues do not compile:\n${r.err}")
  }

  "D5: a compiler that lays the types out differently fails the build" in {
    if (cc.isEmpty) cancel("no host C compiler")
    val header = generated / "types" / "include" / "sb_aadl_types.h"
    // -fshort-enums shrinks Mode to 1 byte; -fpack-struct removes Padded_i's padding
    for (flag <- ISZ[String]("-fshort-enums", "-fpack-struct")) {
      val r = compile(ISZ(flag, "-x", "c"), ISZ(header), None())
      assert(!r.ok, s"$flag: a layout that differs from HAMR's compiled")
      assert(ops.StringOps(r.err).contains("memory layout differs from HAMR's"), s"$flag: unexpected diagnostics:\n${r.err}")
    }
  }

  "F3/D4 and F4/D6: no queue overflows its region and no invalid value reaches a receiver" in {
    if (cc.isEmpty) cancel("no host C compiler")
    val bin = scratch / (if (Os.isWin) "harness.exe" else "harness")
    val built = compile(ISZ(), harness +: queueSources, Some(bin))
    assert(built.ok, s"harness does not compile:\n${built.err}")
    val run = Os.proc(ISZ(bin.value)).run()
    println(run.out)
    assert(run.ok && ops.StringOps(run.out).contains("PASS all shared memory safety checks"), s"harness failed:\n${run.out}")
  }

  "D6: only a queue whose element has invalid bit patterns stages and checks it" in {
    def queue(name: String): ops.StringOps = ops.StringOps((generated / "types" / "src" / s"sb_queue_SharedMemorySafety_$name.c").read)
    // Padded_i holds a bool and an enum, so a received element is checked before delivery
    for (q <- ISZ[String]("Padded_i_2")) {
      assert(queue(q).contains("static SharedMemorySafety_Padded_i staging;"), s"$q: element is not staged")
      assert(queue(q).contains("SharedMemorySafety_Padded_i_is_valid(&staging)"), s"$q: element is not checked")
    }
    // so does a string, which must hold its terminating NUL; a single char has nothing to check
    val stringQueue = ops.StringOps((generated / "types" / "src" / "sb_queue_Base_Types_String_1.c").read)
    assert(stringQueue.contains("Base_Types_String_is_valid(&staging)"), "a string queue does not check its element")
    assert(!ops.StringOps((generated / "types" / "src" / "sb_queue_char_1.c").read).contains("staging"), "a char queue stages its element")
    val header = ops.StringOps((generated / "types" / "include" / "sb_aadl_types.h").read)
    assert(header.contains("if ((*v)[i] == '\\0') {"), "the string validator does not look for the terminating NUL")
    // every bit pattern of an int array or a record of ints and bytes is a value: nothing to
    // check, so the element is copied straight to the receiver, one copy as before the check
    for (q <- ISZ[String]("BigArray_1", "BigRec_i_1")) {
      assert(!queue(q).contains("staging"), s"$q: element is staged although it cannot be invalid")
      assert(!queue(q).contains("_is_valid("), s"$q: element is checked although it cannot be invalid")
    }
  }

  "D6: a protection domain links only the queues it uses" in {
    val mk = ops.StringOps((generated / "system.mk").read)
    assert(mk.contains("TYPES_LIB := libhamr_types.a"), "the queue objects are not archived")
    assert(mk.contains("$(TYPES_LIB): $(TYPE_OBJS)"), "no rule builds the queue archive")
    // an ELF that depended on $(TYPE_OBJS) would link every queue in the system
    val elfRules = mk.split(c => c.value == '\n').filter(l => ops.StringOps(l).contains(".elf:"))
    assert(elfRules.nonEmpty, "no ELF rules found")
    for (rule <- elfRules) {
      assert(!ops.StringOps(rule).contains("$(TYPE_OBJS)"), s"links every queue object: $rule")
    }
  }

  // ------------------------------------------------------------------------------------------
  // D4, D7: the system description
  // ------------------------------------------------------------------------------------------

  "F3/D4 and D7: regions hold their whole queue and are separated by guard pages" in {
    val meta: Predef.String = (generated / "meta.py").read.value
    def hex(s: Predef.String): Long = java.lang.Long.parseLong(s.replace("_", "").substring(2), 16)

    // X = MemoryRegion(sdf, "X", 0x...)
    val sizes: scala.collection.immutable.Map[Predef.String, Long] =
      """(\w+) = MemoryRegion\(sdf, "\w+", (0x[0-9a-fA-F_]+)\)""".r
        .findAllMatchIn(meta).map(m => m.group(1) -> hex(m.group(2))).toMap
    // pd.add_map(Map(X, 0x..., ...
    val maps: scala.collection.immutable.Map[Predef.String, List[(Long, Predef.String)]] =
      """(\w+)\.add_map\(Map\((\w+), (0x[0-9a-fA-F_]+),""".r
        .findAllMatchIn(meta).map(m => (m.group(1), (hex(m.group(3)), m.group(2)))).toList
        .groupBy(_._1).map { case (pd, l) => pd -> l.map(_._2).sortBy(_._1) }

    // the large queues get the pages their queue needs, not one element's size
    def regionOf(port: Predef.String): Long = {
      val cands = sizes.filter(_._1.contains(s"producer_$port"))
      assert(cands.size == 1, s"expected one region for $port, found ${cands.size}")
      cands.head._2
    }
    assert(regionOf("big") >= 8 + 2 * 4400, s"big: region ${regionOf("big")} is smaller than its queue")
    assert(regionOf("rec") >= 8 + 2 * 5004, s"rec: region ${regionOf("rec")} is smaller than its queue")

    // in every protection domain, each mapped port region is followed by an unmapped guard page
    var checked = 0
    for ((pd, sorted) <- maps; (cur, next) <- sorted.zip(sorted.drop(1)) if cur._2.contains("producer_")) {
      val size = sizes(cur._2)
      assert(next._1 >= cur._1 + size + 4096,
        s"$pd: ${cur._2} at 0x${cur._1.toHexString} (size 0x${size.toHexString}) has no guard page before ${next._2}")
      checked += 1
    }
    assert(checked > 0, "no port regions were checked")
  }

  // ------------------------------------------------------------------------------------------
  // D5: the Rust side asserts the same layout
  // ------------------------------------------------------------------------------------------

  "D5: the Rust data crate asserts the layout HAMR computed" in {
    val rs = Os.Path.walk(generated / "crates" / "data", T, F, p => p.name.native == "Padded_i.rs")
    assert(rs.size == 1, s"expected one Padded_i.rs, found ${rs.size}")
    val content = ops.StringOps(rs(0).read)
    for (expected <- ISZ[String](
      "assert!(core::mem::size_of::<Padded_i>() == 16)",
      "assert!(core::mem::align_of::<Padded_i>() == 4)",
      "assert!(core::mem::offset_of!(Padded_i, b) == 4)",
      "assert!(core::mem::offset_of!(Padded_i, mode) == 12)")) {
      assert(content.contains(expected), s"Padded_i.rs is missing: $expected")
    }
    // and rustc agrees with those numbers
    if (proc"which cargo".run().ok) {
      val r = Os.proc(ISZ[String]("cargo", "check")).at(generated / "crates" / "data").env(ISZ(("RUSTC_BOOTSTRAP", "1"))).run()
      assert(r.ok, s"the data crate's layout assertions do not hold in rustc:\n${r.err}")
    }
  }

  // ------------------------------------------------------------------------------------------
  // Stages 2, 4 and 5 on seL4: the generated system booted under QEMU
  // ------------------------------------------------------------------------------------------

  "D6: each port's invalid-message counter is exposed to C and Rust components" in {
    val consumerC = ops.StringOps((generated / "components" / "consumer_p_consumer" / "src" / "consumer_p_consumer.c").read)
    val api = ops.StringOps((generated / "crates" / "consumer_p_consumer" / "src" / "bridge" / "consumer_p_consumer_api.rs").read)
    for (port <- ISZ[String]("big", "rec", "padded")) {
      assert(consumerC.contains(s"uintmax_t get_${port}_num_invalid(void)"), s"no C getter for $port's counter")
      assert(api.contains(s"pub fn get_${port}_num_invalid(&self) -> u64"), s"no Rust API method for $port's counter")
    }
  }

  // Opt-in: needs MICROKIT_SDK, sDDF, qemu-system-aarch64, cargo and Verus, and takes a few
  // minutes.  The producer (qemu/producer_p_producer_user.c) sends valid messages, then
  // writes an enum of 7 and a bool of 2 into its padded region, then a valid message, then
  // one byte past the end of its big region; the Rust consumer (qemu/consumer_p_consumer_app.rs)
  // checks every value it receives against what was sent and logs the invalid counters.
  "stages 2, 4 and 5 under QEMU: large queues arrive intact, invalid values never reach Rust, and a write past a region faults" in {
    if (Os.env("HAMR_SMS_QEMU").isEmpty && Os.prop("HAMR_SMS_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_SMS_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64, cargo and Verus)")
    val out = scratch / "qemu"
    val r = runCodegen(loadModel(), out)
    r.printMessages()
    assert(!r.hasError, "codegen failed")
    val log = scratch / "qemu.log"
    val run = Os.proc(ISZ[String]("bash", (modelDir / "qemu" / "run-qemu.sh").value, (out / "microkit").value, "25", log.value)).console.run()
    assert(run.ok, "the QEMU test system did not build")

    val lines: ISZ[Predef.String] = for (l <- log.readLines if ops.StringOps(l).contains("SMS|") || ops.StringOps(l).contains("FAULT") || ops.StringOps(l).contains("addr=")) yield l.value
    for (l <- lines) println(l)
    def has(s: Predef.String): scala.Boolean = lines.elements.exists(_.contains(s))
    val consumer = lines.elements.filter(_.contains("SMS|consumer"))

    // stage 2: the 4400- and 5004-byte messages arrive intact
    assert(consumer.nonEmpty, "the consumer logged nothing")
    assert(!consumer.exists(_.contains("CORRUPT")), "the consumer received a corrupted value")
    assert(has("big n=3 ok rec n=3 ok"), "the large messages did not arrive")
    assert(!has("consumer_p_consumer_MON | FAULT"), "the consumer faulted")

    // stage 4: both invalid messages are dropped and counted, and valid data still flows
    assert(has("invalid(big,rec,padded)=(0,0,1)") && has("invalid(big,rec,padded)=(0,0,2)"), "the invalid messages were not counted")
    assert(!has("padded a=4 ") && !has("padded a=5 "), "an invalid message reached Rust")
    assert(has("padded a=6 b=60 flag=false mode=Run ok"), "a valid message after the invalid ones did not arrive")

    // stage 5: the write just past the big region faults at that address ...
    val write = """write at ([0-9a-fA-F]+)\)""".r.findFirstMatchIn(lines.elements.mkString("\n"))
    assert(write.nonEmpty, "the producer did not attempt the write past its region")
    val faultAddr = """producer_p_producer_MON \|\s+ip=\S+ addr=0x([0-9a-fA-F]+)""".r.findFirstMatchIn(lines.elements.mkString("\n"))
    assert(faultAddr.nonEmpty, "the write past the region did not fault")
    assert(java.lang.Long.parseLong(faultAddr.get.group(1), 16) == java.lang.Long.parseLong(write.get.group(1), 16),
      s"faulted at 0x${faultAddr.get.group(1)}, not at the write 0x${write.get.group(1)}")
    assert(!has("did not fault"), "the write past the region did not fault")
    // ... and the neighbouring region, the rec queue, is still intact afterwards
    val afterFault = lines.elements.dropWhile(l => !l.contains("producer_p_producer_MON | FAULT"))
    assert(afterFault.exists(l => l.contains("rec n=3 ok")), "the rec queue was not intact after the fault")
  }
}
