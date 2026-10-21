package org.sireum.hamr.codegen.test.microkit

// Regression tests for the test controller's run-time contract checking
// (hamr/codegen/doc/TestScheduler-design.md, stage 7).
//
// Each test generates models/SystemTesting with the test scheduler.  The model has
//
//   src   (Rust) reads an injected `mode`, sends it on `val` and remembers it,
//   dst1  (Rust) latches what arrives on `val`,
//   dst2  (C)    forwards what arrives on `val`,
//
// so `val` has two consumers, one of them a C thread, and a composition whose `Echoed`
// assertion relates dst1 to src.  The behaviour code in models/SystemTesting/qemu breaks a
// contract on request -- a test injects the mode that triggers it -- and overruns its
// watchdog once, so a single image holds both the faults and the nominal behaviour.
//
// Most tests check the generated code.  The opt-in one boots the system under QEMU in four
// builds -- default, GUMBO_CHECKS=off, both checks off, and a listing -- and checks every
// system test's verdict and TEST lines against what that build must produce.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.common.util.{ExperimentalOptions, HamrCli}
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.hamr.ir
import org.sireum.hamr.ir.Aadl
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class SystemTestingTests extends TestSuite {

  val modelDir: Os.Path = MicrokitTestUtil.resourcesDir / "models" / "SystemTesting"
  val sysmlDir: Os.Path = modelDir / "sysml"
  val fixtures: Os.Path = modelDir / "qemu"
  val scratch: Os.Path = Os.tempDir() / "hamr-system-testing-test"

  def loadModel(): Aadl =
    TestUtil.getModel(Some(sysmlDir / ".slang" / "top_impl_Instance.json"), None(), sysmlDir, ISZ(), "st", F)

  def runCodegen(out: Os.Path): Reporter = runCodegen(out, F)

  def runCodegen(out: Os.Path, runtimeMonitoring: B): Reporter = runCodegen(out, runtimeMonitoring, loadModel())

  def runCodegen(out: Os.Path, runtimeMonitoring: B, model: Aadl): Reporter =
    runCodegenIn(out, sysmlDir, runtimeMonitoring, model)

  def runCodegenIn(out: Os.Path, workspace: Os.Path, runtimeMonitoring: B, model: Aadl, testScheduler: B = T): Reporter = {
    out.removeAll()
    val opts = MicrokitTests.baseOptions(
      workspaceRootDir = Some(workspace.canon.value),
      packageName = Some("st"),
      outputDir = Some(out.canon.value),
      slangOutputDir = Some((out / "slang").value),
      slangOutputCDir = Some((out / "c").value),
      sel4OutputDir = Some((out / "microkit").value),
      runtimeMonitoring = runtimeMonitoring,
      scheduling = HamrCli.CodegenScheduling.UserLand,
      verusAttributeSyntax = T,
      experimentalOptions =
        if (testScheduler) MicrokitTests.baseOptions.experimentalOptions :+ ExperimentalOptions.ENABLE_TEST_SCHEDULER
        else MicrokitTests.baseOptions.experimentalOptions)
    val reporter = Reporter.create
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    CodeGen.codeGen(model, T, opts, ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins,
      store, reporter, (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)
    return reporter
  }

  // The model with the Queue_Size of the port at `port` set to `size`.
  def withQueueSize(model: Aadl, port: ISZ[String], size: Z): Aadl = {
    def isQueueSize(p: ir.Property): B =
      p.name.name.nonEmpty && ops.StringOps(p.name.name(p.name.name.size - 1)).endsWith("Queue_Size")
    def feature(f: ir.Feature): ir.Feature = f match {
      case fe: ir.FeatureEnd if fe.identifier.name == port =>
        fe(properties = fe.properties.map((p: ir.Property) =>
          if (isQueueSize(p)) p(propertyValues = ISZ[ir.PropertyValue](ir.UnitProp(value = size.string, unit = None()))) else p))
      case _ => f
    }
    def component(c: ir.Component): ir.Component =
      c(features = c.features.map(feature _), subComponents = c.subComponents.map(component _))
    return model(components = model.components.map(component _))
  }

  // The model without its GUMBO annexes -- for the model without thread contracts, its
  // compositions.
  def withoutAnnexes(model: Aadl): Aadl = {
    def component(c: ir.Component): ir.Component =
      c(annexes = ISZ(), subComponents = c.subComponents.map(component _))
    return model(components = model.components.map(component _))
  }

  // The model with the connection into `dstPort` rerouted to come from `srcPort` of
  // `srcComponent` instead.
  def withConnectionFrom(model: Aadl, dstPort: ISZ[String], srcComponent: ISZ[String], srcPort: ISZ[String]): Aadl = {
    def conn(ci: ir.ConnectionInstance): ir.ConnectionInstance =
      if (ci.dst.feature.nonEmpty && ci.dst.feature.get.name == dstPort)
        ci(src = ci.src(component = ci.src.component(name = srcComponent), feature = Some(ci.src.feature.get(name = srcPort))))
      else ci
    def component(c: ir.Component): ir.Component =
      c(connectionInstances = c.connectionInstances.map(conn _), subComponents = c.subComponents.map(component _))
    return model(components = model.components.map(component _))
  }

  // Generated once and shared by the tests that inspect the output.
  lazy val generated: Os.Path = {
    val out = scratch / "generated"
    val r = runCodegen(out)
    r.printMessages()
    assert(!r.hasError, "codegen of models/SystemTesting reported errors")
    out / "microkit"
  }

  def read(rel: String): ops.StringOps = ops.StringOps((generated / rel).read)

  // ------------------------------------------------------------------------------------------
  // The generated code
  // ------------------------------------------------------------------------------------------

  "a C thread's contracts are checked, from executable GUMBOX predicates" in {
    val components = read("crates/observers/src/components.rs")
    assert(components.contains("crate::Thread::d2p_dst => {"), "dst2 (C) has no checks")
    assert((generated / "crates" / "observers" / "src" / "gumbox" / "d2p_dst_GUMBOX.rs").exists,
      "no GUMBOX predicates for dst2 (C)")
    // and nothing for it in a Rust crate, which a C thread does not have
    assert(!(generated / "crates" / "d2p_dst").exists, "a C thread got a Rust crate")
  }

  "MustSend's expected value may name a port" in {
    // dst2's `forward` is MustSend(fwd, val): the expected value is the incoming port, which
    // must be read through the API like any other port reference -- it was left as a bare
    // `val` that nothing declares
    val gumbox = read("crates/observers/src/gumbox/d2p_dst_GUMBOX.rs")
    assert(gumbox.contains("api_fwd.unwrap() == api_val"), "MustSend's expected value was not rewritten to the port")
  }

  "an event port with two consumers is observed through one cursor per consumer" in {
    val observe = read("crates/test_controller/src/system_tests/observe.rs")
    for (reader <- ISZ[String]("srcp_src", "d1p_dst", "d2p_dst", "sys")) {
      assert(observe.contains(s"fn test_obs_get_srcp_src_val__$reader("), s"no cursor on val for $reader")
    }
  }

  "a rejected dispatch puts back what its thread received, as well as its cursors" in {
    // src's ack is a connected input nominal aliases (s_ack): latched at src's dispatch, so a
    // rejected one (D36) must restore the latch, or a later frame's places see an event src
    // never received
    val observe = read("crates/test_controller/src/system_tests/observe.rs")
    assert(observe.contains("self.saved_recv_d1p_dst_ack__srcp_src = self.recv_d1p_dst_ack__srcp_src.clone();"),
      "mark_cursors does not save src's latched ack")
    assert(observe.contains("self.recv_d1p_dst_ack__srcp_src = self.saved_recv_d1p_dst_ack__srcp_src.clone();"),
      "rewind_cursors does not restore src's latched ack")
  }

  "the checks' switches are restored when a test ends, before the runner's normalization" in {
    // normalization dispatches, and so rejects, as the build says -- not as the last test left
    // the switches
    val observe = read("crates/test_controller/src/system_tests/observe.rs")
    val i = observe.stringIndexOf("pub(crate) fn end_test()")
    assert(i >= 0, "no end_test")
    val body = ops.StringOps(observe.substring(i, observe.s.size))
    val end = body.stringIndexOf("\n}\n")
    val endTest = ops.StringOps(body.substring(0, end))
    assert(endTest.contains("GUMBO_ON = GUMBO_LIVE;") && endTest.contains("SYSVERIF_ON = SYSVERIF_LIVE;"),
      "end_test does not restore the build's switches")
  }

  "an output whose consumers have different queue sizes is rejected, not given clashing accessors" in {
    // src's val goes to dst1 with queue size 1, and here to dst2 with 2: two regions for one
    // port, which the controller's accessors, named after the port, cannot tell apart.  On the
    // model without thread contracts, and without its compositions, which read both inputs:
    // only there is a deeper queue allowed (see the next two tests)
    val dir = modelDir / "compositions-only" / "sysml"
    val model = TestUtil.getModel(Some(dir / ".slang" / "top_impl_Instance.json"), None(), dir, ISZ(), "sco", F)
    val r = runCodegenIn(scratch / "queue-sizes", dir, F,
      withQueueSize(withoutAnnexes(model), ISZ("top_impl_Instance", "d2p", "dst", "val"), 2))
    assert(r.hasError, "codegen accepted an output whose consumers have different queue sizes")
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isError &&
      ops.StringOps(m.text).contains("'srcp_src_val': its consumers have different queue sizes (")),
      "no error naming the port")
  }

  "a thread with contracts may not have an event queue deeper than one" in {
    // the contracts and their run-time checks see one element per dispatch, which matches the
    // thread only when its queue holds one -- for C threads as for Rust ones
    val r = runCodegen(scratch / "deep-queue", F,
      withQueueSize(loadModel(), ISZ("top_impl_Instance", "d2p", "dst", "val"), 2))
    assert(r.hasError, "codegen accepted a deeper queue on a thread with contracts")
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isError &&
      ops.StringOps(m.text).contains("d2p_dst has GUMBO contracts, so its event ports must have single-element queues, but val has a Queue_Size of 2")),
      "no error naming the thread and the port")
  }

  "without system testing or runtime monitoring, a deeper queue on a thread with contracts is a warning" in {
    // nothing then reads the queue one element per dispatch at run time; a Verus proof of the
    // thread does not read it that way
    val r = runCodegenIn(scratch / "deep-queue-unchecked", sysmlDir, F,
      withQueueSize(loadModel(), ISZ("top_impl_Instance", "d2p", "dst", "val"), 2), testScheduler = F)
    assert(!r.hasError, "codegen rejected a deeper queue though no run-time checks were requested")
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isWarning &&
      ops.StringOps(m.text).contains("d2p_dst has GUMBO contracts, so its event ports must have single-element queues, but val has a Queue_Size of 2; this is an error when system testing or runtime monitoring is requested")),
      "no warning naming the thread and the port")
  }

  "an event port a composition reads may not have a queue deeper than one, on a thread without contracts too" in {
    // the system assertions see one element per dispatch as well: nominal reads dst2's val
    val dir = modelDir / "compositions-only" / "sysml"
    val model = TestUtil.getModel(Some(dir / ".slang" / "top_impl_Instance.json"), None(), dir, ISZ(), "sco", F)
    val r = runCodegenIn(scratch / "deep-queue-composition", dir, F,
      withQueueSize(model, ISZ("top_impl_Instance", "d2p", "dst", "val"), 2))
    assert(r.hasError, "codegen accepted a deeper queue on a port a composition reads")
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isError &&
      ops.StringOps(m.text).contains("Composition nominal reads d2p_dst's val, so it must have a single-element queue, but it has a Queue_Size of 2")),
      "no error naming the composition, the thread and the port")
  }

  "the scheduler on the host: stale expiries, late completions, parks, UNREACHABLE, saturated counts" in {
    // Cases QEMU cannot time: models/SystemTesting/host/scheduler_harness.c includes the
    // generated scheduler, stubs Microkit and the sDDF timer, and drives notified() itself.
    val cc: Predef.String = Os.env("CC") match {
      case Some(c) => c.value
      case _ => "cc"
    }
    if (!Os.proc(ISZ(cc, "--version")).run().ok)
      cancel(s"needs a C compiler ($cc, or set CC)")
    val host = modelDir / "host"
    val sched = generated / "scheduler"
    val bin = scratch / "scheduler_harness"
    val build = Os.proc(ISZ(cc, "-std=gnu11", "-Wall", "-Werror", "-Wno-unused-function",
      s"-I${host / "include"}", s"-I${sched / "include"}", s"-I${sched / "src"}",
      // Mach-O rejects the scheduler's ELF section names; the sections do not matter here
      "-D__section__(x)=unused",
      (host / "scheduler_harness.c").value, "-o", bin.value)).console.run()
    assert(build.ok, s"the harness did not build:\n${build.out}${build.err}")
    val run = Os.proc(ISZ(bin.value)).run()
    assert(run.ok && ops.StringOps(run.out).contains("HARNESS OK"), s"the harness failed:\n${run.out}${run.err}")
  }

  "a composition's alias of a connected input reads what the reader received" in {
    // Acked reads src.ack, fed back from dst1 which runs later: the value src got, latched at
    // its dispatch -- not what dst1 sent this frame, which it has not yet at "after src"
    val lib = read("crates/observers/src/lib.rs")
    assert(lib.contains("fn get_recv_srcp_src_ack(&mut self)"), "the alias has no getter of its own")
    val observe = read("crates/test_controller/src/system_tests/observe.rs")
    assert(observe.contains("fn latch_received(&mut self, t: Thread)") &&
      observe.contains("let got = unsafe { test_obs_get_d1p_dst_ack__srcp_src(&mut v) };"),
      "the controller does not latch what src receives at its dispatch")
  }

  "a thread connected directly to itself is rejected" in {
    // reroute the feedback edge dst1.ack -> src.ack to come from src itself
    val src = ISZ[String]("top_impl_Instance", "srcp", "src")
    val r = runCodegen(scratch / "self", F,
      withConnectionFrom(loadModel(), src :+ "ack", src, src :+ "val"))
    val selfErrors = r.messages.filter((m: org.sireum.message.Message) => m.isError &&
      ops.StringOps(m.text).contains("A component cannot be connected directly to itself but src is (val -> ack)"))
    assert(selfErrors.size == 1, s"expected one error for a thread connected to itself, got ${selfErrors.size}")
  }

  "a composition may leave threads out: the schedule check passes over them, and codegen warns about feeding writes" in {
    // `partial` covers src and dst2; dst1, which runs between them and writes ack (read by
    // src), is left out
    val r = runCodegen(scratch / "partial")
    assert(!r.hasError, "codegen failed")
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isWarning &&
      ops.StringOps(m.text).contains("d1p_dst is not in composition 'partial' but writes ack, which srcp_src in it reads")),
      "no warning that a left-out thread writes what the composition reads")
    // `head` reads dst2's output but never fires it; dst2 feeds nothing head reads, so no
    // feed warning.  Both warnings count only aliases a property reads (Noted, Untracked).
    assert(ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isWarning &&
      ops.StringOps(m.text).contains("d2p_dst is named in composition 'head' but its schema never fires it")),
      "no warning that a composition names a thread its schema never fires")
    assert(!ops.ISZOps(r.messages).exists((m: org.sireum.message.Message) => m.isWarning &&
      ops.StringOps(m.text).contains("in composition 'head' but writes")),
      "a feed warning for a thread whose output head does not read")
    val partial = ops.StringOps((scratch / "partial" / "microkit" / "crates" / "observers" / "src" / "sys_partial.rs").read)
    assert(partial.contains("if !COMPONENT_TRANSITIONS.iter().any(|&(t_th, _, _)| th == Some(t_th)) {"),
      "the schedule check does not pass over threads the composition leaves out")
    assert(!partial.contains("crate::Thread::d1p_dst, "), "dst1 got a transition in a composition that leaves it out")
  }

  "each generated layer can be switched, and only those" in {
    val observe = read("crates/test_controller/src/system_tests/observe.rs")
    assert(observe.contains("pub fn set_gumbo(on: bool)"), "no GUMBO switch")
    assert(observe.contains("pub fn set_sysverif(on: bool)"), "no system-verification switch")
    assert(observe.contains("pub const Echoed: &str = \"Echoed\";"), "no constant naming the Echoed property")
    val mk = read("system.mk")
    // each named, so GUMBO_CHECKS=off and SYSVERIF_CHECKS=off do not hash alike
    assert(mk.contains("GUMBO_CHECKS=${GUMBO_CHECKS} SYSVERIF_CHECKS=${SYSVERIF_CHECKS}"),
      "the switches are not in the rebuild hash, by name")
  }

  "the shipping build does not compile the test controller, and the system proofs leave it out" in {
    val ctrl = "test_controller_process_test_controller_thread"
    val mk = read("system.mk")
    val images = ops.StringOps(mk.substring(mk.stringIndexOf("IMAGES := "), mk.size))
    val imagesDecl = images.substring(0, images.stringIndexOf("\n\n"))
    assert(!ops.StringOps(imagesDecl).contains(ctrl), "system.mk builds the test controller by default")
    assert(ops.StringOps(imagesDecl).contains("$(EXTRA_IMAGES)"), "system.mk has no hook for variant-only images")
    assert(read("test_scheduler.mk").contains(s"export EXTRA_IMAGES := $ctrl.elf ${ctrl}_MON.elf"),
      "the test variant does not add the test controller's images")
    for (comp <- ISZ[String]("nominal", "partial", "head")) {
      val actions = read(s"crates/sys_${comp}_proof/src/actions.rs")
      assert(!actions.contains("test_controller"), s"the $comp system proof models the test controller")
      val state = read(s"crates/sys_${comp}_proof/src/system_state.rs")
      assert(!state.contains("sv_last"), s"the $comp system proof models the synthetic sv_ ports")
    }
    // the synthetic sv_ ports get no test accessors
    assert(!read("crates/srcp_src/src/test/util/test_apis.rs").contains("get_sv_"),
      "the component test API exposes a synthetic port")
  }

  "the image that ships has no test controller, and the test variant keeps its pad where production has it" in {
    // generated without --runtime-monitoring: no monitor rebuilt "normal", so the test
    // scheduler must strip its controller from it itself
    val normal = read("meta.py")
    assert(!normal.contains("test_controller"), "the default image contains the test controller")
    // nor the state variables' regions, which would make the threads publish their state
    assert(!normal.contains("srcp_src_sv_last"), "the default image carries the sv_ regions")
    val test = read("test_scheduler.meta.py")
    assert(test.contains("test_controller"), "the test variant has no test controller")
    def padLast(meta: ops.StringOps): B = {
      val sched = ops.StringOps(meta.substring(meta.stringIndexOf("user_schedule = schedule("), meta.size))
      val body = sched.substring(0, sched.stringIndexOf(")\n"))
      return ops.StringOps(ops.StringOps(body).trim).endsWith("ts_pad")
    }
    assert(padLast(normal) == padLast(test), "the test variant puts the pad elsewhere than production")
  }

  "with runtime monitoring too, the test variant keeps its pad where the shipped image has it" in {
    // a monitor rebuilds the shipped schedule with the pad first; the test variant must follow
    val r = runCodegen(scratch / "rm-pad", T)
    assert(!r.hasError, "codegen failed")
    val dir = scratch / "rm-pad" / "microkit"
    def firstSlot(meta: Predef.String): Predef.String = {
      val m = ops.StringOps(meta)
      val sched = ops.StringOps(m.substring(m.stringIndexOf("user_schedule = schedule("), m.size))
      return ops.StringOps(sched.substring(0, sched.stringIndexOf(")\n"))).split((c: C) => c == C('\n'))(1).value.trim
    }
    assert(firstSlot((dir / "meta.py").read.value) == "ts_pad,", "the shipped image does not start with the pad")
    assert(firstSlot((dir / "test_scheduler.meta.py").read.value) == "ts_pad,",
      "the test variant puts the pad elsewhere than the shipped image")
    // a monitor drains each event port at the start of a run and keeps the latest, as the
    // controller does -- one element per run would leave the rest to arrive later as new events
    val mon = ops.StringOps((dir / "crates" / "sys_nominal_monitor" / "src" / "component" /
      "sys_nominal_monitor_process_sys_nominal_monitor_thread_app.rs").read)
    assert(mon.contains("while let Some(v) = api.get_srcp_src_val() {"), "a monitor takes one event per run")
    assert(!mon.contains("if let Some(v) = api.get_srcp_src_val() {"), "a monitor takes one event per run")
    // a pure event port read by a contract and by a composition: one getter type, Option of
    // the empty payload, polled through the bool API (`Pinged`, src's `pinged`)
    assert(mon.contains("while api.get_srcp_src_ping() {"), "the composition's pure event port is not polled through its bool API")
    val lib = ops.StringOps((dir / "crates" / "observers" / "src" / "lib.rs").read)
    assert(lib.contains("fn get_srcp_src_ping(&mut self) -> Option<"), "a pure event port's getter is not Option of its payload")
    assert(lib.contains("fn get_recv_d1p_dst_ping(&mut self) -> Option<"), "the received pure event alias is not Option of its payload")
  }

  "a monitor polls a pure event port a contract reads through its bool API" in {
    // the contract (GUMBOX) reads a pure event port as Option<payload>; the monitor's API
    // returns bool.  The poll must follow the port kind, not the getter's type, or the
    // monitor crate does not compile (gumbo-verus/pure_event_port)
    val dir = MicrokitTestUtil.resourcesDir / "models" / "INSPECTA-models" / "micro-examples" / "microkit" /
      "gumbo-verus" / "pure_event_port" / "sysml"
    val model = TestUtil.getModel(Some(dir / ".slang" / "top_impl_Instance.json"), None(), dir, ISZ(), "pep", F)
    val out = scratch / "pure-event"
    val r = runCodegenIn(out, dir, T, model)
    assert(!r.hasError, "codegen failed")
    val app = ops.StringOps((out / "microkit" / "crates" / "gumbo_monitor" / "src" / "component" /
      "gumbo_monitor_process_gumbo_monitor_thread_app.rs").read)
    assert(app.contains("while api.get_snd_p_snd_evt() {"), "the pure event port is not polled through its bool API")
    assert(!app.contains("while let Some(v) = api.get_snd_p_snd_evt()"), "the pure event port is polled as event data")
    // Opt-in, as the QEMU tests: the monitor image must actually build
    if (Os.env("HAMR_ST_QEMU").nonEmpty || Os.prop("HAMR_ST_QEMU").nonEmpty) {
      val build = Os.proc(ISZ[String]("make", "-C", (out / "microkit").value, "CONFIG=gumbo_monitor.mk",
        "RUST_MAKE_TARGET=build-release")).run()
      assert(build.ok, s"the gumbo monitor image does not build:\n${build.out}\n${build.err}")
    }
  }

  "with runtime monitoring, contracts without state variables still get the GUMBO and composition monitors" in {
    // the monitors check a thread's contracts over its ports alone; they used to be gated on
    // state variables, and a model with none got only the userland monitor, silently
    val dir = modelDir / "stateless" / "sysml"
    val model = TestUtil.getModel(Some(dir / ".slang" / "top_impl_Instance.json"), None(), dir, ISZ(), "sts", F)
    val out = scratch / "stateless"
    val r = runCodegenIn(out, dir, T, model)
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    val monitors = ISZ[Predef.String]("gumbo_monitor", "sys_nominal_monitor", "sys_head_monitor")
    for (m <- monitors) {
      assert((microkit / "crates" / m).exists, s"no $m crate")
      assert((microkit / s"$m.mk").exists, s"no $m variant")
    }
    assert((microkit / "crates" / "observers").exists, "no observers crate")
    // every thread has an event output, so the match on Thread in note_dispatch covers them
    // all: a catch-all arm would be unreachable, and rustc warns about it
    val app = ops.StringOps((microkit / "crates" / "gumbo_monitor" / "src" / "component" /
      "gumbo_monitor_process_gumbo_monitor_thread_app.rs").read)
    val begin = app.stringIndexOf("pub fn note_dispatch(")
    assert(begin >= 0, "no note_dispatch")
    val noteDispatch = ops.StringOps(app.substring(begin, app.stringIndexOfFrom("\n}\n", begin)))
    assert(noteDispatch.contains("observers::Thread::d2p_dst =>"), "note_dispatch does not cover every thread")
    assert(!noteDispatch.contains("_ => {}"), "note_dispatch has an unreachable catch-all arm")
    // Opt-in, as the QEMU tests: the monitor images must actually build
    if (Os.env("HAMR_ST_QEMU").nonEmpty || Os.prop("HAMR_ST_QEMU").nonEmpty) {
      for (m <- monitors) {
        val build = Os.proc(ISZ[String]("make", "-C", microkit.value, s"CONFIG=$m.mk",
          "RUST_MAKE_TARGET=build-release")).run()
        assert(build.ok, s"the $m image does not build:\n${build.out}\n${build.err}")
      }
    }
  }

  "with runtime monitoring, compositions over threads without contracts still get their monitors" in {
    // the system layer reads ports and state variables, not the threads' contracts; the
    // sys-assert monitors used to be built on the GUMBO monitor's generated code, so a model
    // with no thread contracts got no monitor at all, silently
    val dir = modelDir / "compositions-only" / "sysml"
    val model = TestUtil.getModel(Some(dir / ".slang" / "top_impl_Instance.json"), None(), dir, ISZ(), "sco", F)
    val out = scratch / "compositions-only"
    val r = runCodegenIn(out, dir, T, model)
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    val crates = microkit / "crates"
    val monitors = ISZ[Predef.String]("sys_nominal_monitor", "sys_head_monitor")
    for (m <- monitors) {
      assert((crates / m).exists, s"no $m crate")
      assert((microkit / s"$m.mk").exists, s"no $m variant")
      val app = ops.StringOps((crates / m / "src" / "component" / s"${m}_process_${m}_thread_app.rs").read)
      assert(app.contains("pub fn sys_assert_monitor<"), s"$m has no sys_assert_monitor")
      assert(!app.contains("gumbo_monitor"), s"$m refers to the GUMBO layer, which the model does not have")
      assert(app.contains("begin_monitor_run(api);\n    self.sys_assert_monitor(api);"), s"$m's timeTriggered does not start the run and check")
    }
    // no thread contracts: no GUMBO monitor, and an observers crate with the system layer only
    assert(!(crates / "gumbo_monitor").exists, "a GUMBO monitor for a model without thread contracts")
    assert((crates / "observers").exists, "no observers crate")
    assert(!(crates / "observers" / "src" / "components.rs").exists, "a component layer without thread contracts")
    // the test controller hosts the system layer too
    assert((crates / "test_controller" / "src" / "system_tests" / "observe.rs").exists, "the test controller hosts no checks")
    // Opt-in, as the QEMU tests: each monitor image builds, validates the schedule, and runs
    // clean -- the stub behaviour sends nothing, so every assertion holds
    if (Os.env("HAMR_ST_QEMU").nonEmpty || Os.prop("HAMR_ST_QEMU").nonEmpty) {
      val violations = List("SYS ASSERT VIOLATION", "SCHEDULE CONFORMANCE VIOLATION", "conformance check failed",
        "panicked", "PANIC")
      for (m <- monitors) {
        val log = boot(microkit, s"$m.mk", 30)
        val bad = log.split('\n').filter(l => violations.exists(v => l.contains(v)))
        assert(bad.isEmpty, s"$m reported:\n${bad.take(12).mkString("\n")}")
        assert(log.contains("Schedule conformance check passed"), s"$m: the schedule was not validated")
      }
    }
  }

  "run-tests.cmd rejects a filter make would rewrite" in {
    // make expands `$` in the value it hashes and hands on, and the hash's echo reads `\`
    for (f <- ISZ[Predef.String]("a$b", "a\\c")) {
      val r = Os.proc(ISZ[String](sireum.value, "slang", "run", (generated / "bin" / "run-tests.cmd").value, String(f))).run()
      assert(!r.ok, s"run-tests.cmd accepted the filter '$f'")
      assert(r.err.value.contains("a test filter cannot contain"), s"no reason given for the filter '$f':\n${r.out}\n${r.err}")
    }
  }

  "meta.py's plugin contributions are regenerated, not written once" in {
    // the state-variable injection regions depend on the model, so they sit in a marker
    // region of their own, as does the test-selection block
    val test = read("test_scheduler.meta.py")
    val begin = test.stringIndexOf("BEGIN META TEMPLATE MARKER")
    val end = test.stringIndexOf("END META TEMPLATE MARKER")
    assert(begin >= 0 && end > begin, "no template marker region")
    assert(ops.StringOps(test.substring(begin, end)).contains("inj_srcp_src_sv_last = MemoryRegion("),
      "the injection regions are outside the template marker region")
    val tBegin = test.stringIndexOf("BEGIN META TAIL MARKER")
    val tEnd = test.stringIndexOf("END META TAIL MARKER")
    assert(tBegin >= 0 && tEnd > tBegin && ops.StringOps(test.substring(tBegin, tEnd)).contains("TEST SELECTION"),
      "the test-selection block is outside the tail marker region")
  }

  // ------------------------------------------------------------------------------------------
  // Under QEMU
  // ------------------------------------------------------------------------------------------

  /** One system test's verdict and the TEST lines between its BEGIN and its verdict. */
  case class Outcome(passed: scala.Boolean, lines: List[Predef.String]) {
    def has(s: Predef.String): scala.Boolean = lines.exists(_.contains(s))
    def count(s: Predef.String): Int = lines.count(_.contains(s))
  }

  case class Run(tests: scala.collection.immutable.Map[Predef.String, Outcome], lines: List[Predef.String]) {
    def apply(name: Predef.String): Outcome = {
      assert(tests.contains(name), s"$name did not run")
      tests(name)
    }
    def has(s: Predef.String): scala.Boolean = lines.exists(_.contains(s))
  }

  /** Groups the TEST lines by the test that printed them -- from its BEGIN to the next BEGIN
    * or DONE, which includes its FAIL line -- and takes its verdict from its PASS line. */
  def parse(out: Predef.String): Run = {
    val lines = out.replace("\r", "").split('\n').toList.filter(_.startsWith("TEST | "))
    var tests = scala.collection.immutable.Map[Predef.String, Outcome]()
    var current: scala.Option[Predef.String] = scala.None
    var acc: List[Predef.String] = Nil
    def close(): Unit = current.foreach { n =>
      tests = tests + (n -> Outcome(passed = acc.exists(_.startsWith("TEST | PASS  ")), lines = acc.reverse))
    }
    for (l <- lines) {
      if (l.startsWith("TEST | BEGIN ")) {
        close()
        current = scala.Some(l.stripPrefix("TEST | BEGIN ").trim)
        acc = Nil
      } else if (l.startsWith("TEST | DONE ")) {
        close()
        current = scala.None
      } else if (current.nonEmpty) {
        acc = l :: acc
      }
    }
    Run(tests, lines)
  }

  lazy val sireum: Os.Path = TestUtil.getSireum

  /** Builds and runs the system tests under QEMU with `env`, via the generated host driver. */
  def runSystemTests(microkit: Os.Path, args: ISZ[String], env: ISZ[(String, String)]): Run = {
    val r = Os.proc(ISZ[String](sireum.value, "slang", "run", (microkit / "bin" / "run-tests.cmd").value) ++ args)
      .env(env).run()
    val out = r.out.value
    println(out.split('\n').filter(l => l.startsWith("TEST | ") || l.startsWith("OK") || l.startsWith("FAILED")).mkString("\n"))
    assert(out.contains("TEST | DONE"), s"the run produced no DONE line:\n${r.out}\n${r.err}")
    parse(out)
  }

  def failsWith(r: Run, test: Predef.String, expected: Predef.String*): Unit = {
    val o = r(test)
    assert(!o.passed, s"$test passed")
    assert(o.count("TEST | FAIL  ") == 1, s"$test printed ${o.count("TEST | FAIL  ")} FAIL lines:\n${o.lines.mkString("\n")}")
    for (e <- expected) assert(o.has(e), s"$test: no line containing '$e':\n${o.lines.mkString("\n")}")
  }

  def passes(r: Run, test: Predef.String, expected: Predef.String*): Unit = {
    val o = r(test)
    assert(o.passed, s"$test failed:\n${o.lines.mkString("\n")}")
    for (e <- expected) assert(o.has(e), s"$test: no line containing '$e':\n${o.lines.mkString("\n")}")
  }

  def installFixtures(microkit: Os.Path): Unit = {
    (fixtures / "srcp_src_app.rs").copyOverTo(microkit / "crates" / "srcp_src" / "src" / "component" / "srcp_src_app.rs")
    (fixtures / "d1p_dst_app.rs").copyOverTo(microkit / "crates" / "d1p_dst" / "src" / "component" / "d1p_dst_app.rs")
    (fixtures / "d2p_dst_user.c").copyOverTo(microkit / "components" / "d2p_dst" / "src" / "d2p_dst_user.c")
    (fixtures / "tests.rs").copyOverTo(microkit / "crates" / "test_controller" / "src" / "system_tests" / "tests.rs")
  }

  /** Boots `config` under QEMU for `seconds` and returns the console log. */
  def boot(microkit: Os.Path, config: Predef.String, seconds: Int): Predef.String = {
    val build = Os.proc(ISZ[String]("make", "-C", microkit.value, s"CONFIG=$config", "RUST_MAKE_TARGET=build-release")).run()
    assert(build.ok, s"$config did not build:\n${build.out}\n${build.err}")
    val log = scratch / s"$config.log"
    val driver =
      """set -u
        |"$@" > "$LOG" 2>&1 &
        |mpid=$!
        |sleep "$SECS"
        |pkill -P $mpid 2>/dev/null
        |kill $mpid 2>/dev/null
        |wait $mpid 2>/dev/null
        |exit 0""".stripMargin
    Os.proc(ISZ[String]("sh", "-c", driver, "sh", "make", "-C", microkit.value, s"CONFIG=$config",
      "RUST_MAKE_TARGET=build-release", "qemu"))
      .env(ISZ(("LOG", log.value), ("SECS", seconds.toString))).timeout((seconds + 60) * 1000).run()
    log.read.value.replace("\r", "")
  }

  // Opt-in: needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo, and takes several minutes.
  "under QEMU: a contract violation fails the test that caused it, and the switches, expectations and watchdog behave" in {
    if (Os.env("HAMR_ST_QEMU").isEmpty && Os.prop("HAMR_ST_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_ST_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo)")

    val out = scratch / "qemu"
    val r = runCodegen(out)
    r.printMessages()
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    installFixtures(microkit)

    // ---- default build: both layers live and on
    val d = runSystemTests(microkit, ISZ(), ISZ())
    assert(d.has("DONE  matched=33 passed=23 failed=10 init=ok"), "unexpected totals")
    passes(d, "checks::nominal_frame")
    // one FAIL for two violations: src's guarantee and the composition's assertion
    failsWith(d, "checks::thread_and_system_violation",
      "VIOLATION CEP_Post srcp_src", "VIOLATION SysAssert nominal/Echoed", "contract violation (2 in this test)")
    passes(d, "checks::expected_violations_pass",
      "expected violation: CEP_Post srcp_src", "expected violation: SysAssert nominal/Echoed")
    failsWith(d, "checks::expected_but_absent", "expected violation did not occur: CepPost(srcp_src)")
    passes(d, "checks::taken_violations_pass")
    // a negative test leaves nothing behind
    passes(d, "checks::nominal_after_negative")
    assert(!d("checks::nominal_after_negative").has("VIOLATION"), "a violation leaked into the next test")
    // a broken assumption is a violation, and its dispatch is rejected: src does not run (D36)
    passes(d, "checks::assumption_not_met_rejects_the_dispatch",
      "expected violation: CEP_Pre srcp_src", "not dispatched at hp=")
    assert(!d("checks::assumption_not_met_rejects_the_dispatch").has("CEP_Post srcp_src"),
      "a rejected dispatch was checked for its guarantee")
    failsWith(d, "checks::assumption_not_met_fails", "VIOLATION CEP_Pre srcp_src", "not dispatched at hp=")
    // the C thread's guarantee, through the second consumer's own cursor
    failsWith(d, "checks::c_thread_violation", "VIOLATION CEP_Post d2p_dst")
    // src's first dispatch after its rejected ones: the ack it did not consume then is still
    // there for it, and for its check -- the rejection put the check's cursor back
    assert(!d("checks::c_thread_violation").has("CEP_Post srcp_src"),
      "a rejected dispatch consumed an event its thread never received")
    // the violating dispatch is the command's last: still this test's
    failsWith(d, "checks::last_slot_violation_charged", "VIOLATION CEP_Post srcp_src")
    // a rejected dispatch of a C thread, the hyperperiod's last: what its check latched for the
    // system layers is put back, so the next frame's places before it see nothing it received
    passes(d, "checks::rejected_last_dispatch_leaves_nothing_received",
      "expected violation: CEP_Pre d2p_dst", "not dispatched at hp=", "system assertions resumed")
    assert(!d("checks::rejected_last_dispatch_leaves_nothing_received").has("VIOLATION SysAssert"),
      "a rejected dispatch left what it latched visible to the next frame")
    // a test's injection into an event port is not read back as its producer's output
    passes(d, "checks::injected_output_is_not_the_producers")
    assert(!d("checks::injected_output_is_not_the_producers").has("VIOLATION"),
      "an injected value was taken for the producer's own output")
    passes(d, "checks::nothing_dispatched_nothing_checked")
    assert(!d("checks::nothing_dispatched_nothing_checked").has("VIOLATION"), "a command that dispatched nothing was checked")
    // ... but its consumers do receive it, and so the system assertions see it
    passes(d, "checks::injected_output_reaches_the_system_assertions", "expected violation: SysAssert nominal/Sent")
    // ... also when injected at the frame's start, before its first park
    passes(d, "checks::injection_at_frame_start_belongs_to_that_frame", "expected violation: SysAssert nominal/Sent")
    // an injection after a consumer ran reaches it next hyperperiod; the controller says so
    passes(d, "checks::injection_after_a_consumer_ran_is_noted",
      "srcp_src_val injected after d1p_dst ran in hp=")
    // an event on an unconnected input is this frame's for every assertion that reads it
    passes(d, "checks::injected_input_is_seen_by_every_assertion")
    assert(!d("checks::injected_input_is_seen_by_every_assertion").has("VIOLATION"),
      "a second assertion did not see the event the first one read")
    // an injected state variable is its owner's next pre-state, not its state for everyone now
    passes(d, "checks::injected_state_is_the_owners_only")
    assert(!d("checks::injected_state_is_the_owners_only").has("VIOLATION"),
      "the system assertions read a state variable's injected value before its thread adopted it")
    // suite and test switches
    failsWith(d, "switched::expecting_a_switched_off_layer_fails",
      "expected violation CepPost(srcp_src) cannot be reported: the GUMBO checks are off")
    passes(d, "switched::suite_hides_gumbo")
    assert(!d("switched::suite_hides_gumbo").has("CEP_Post"), "gumbo = off still reported a CEP_Post")
    // the normalization after a gumbo = off test checks, and rejects, as the build says: the
    // rejection happens between the two tests, so its INFO line is in the first one's output --
    // without it the second test's check would hold vacuously
    passes(d, "switched::leaves_dst2_out_of_contract", "not dispatched at hp=")
    passes(d, "switched::normalization_checks_as_the_build_says")
    passes(d, "toggles::next_suite_checks_again", "VIOLATION CEP_Post srcp_src")
    // same name as checks::nominal_frame, in another suite
    passes(d, "toggles::nominal_frame")
    passes(d, "toggles::off_then_on_within_a_test")
    assert(d("toggles::off_then_on_within_a_test").count("VIOLATION CEP_Post") == 1, "off then on: expected one CEP_Post")
    passes(d, "toggles::reenable_gumbo")
    passes(d, "toggles::parks_only_while_live")
    // the watchdog
    // the system assertions stay suspended for the rest of the frame the overrun is in (the
    // aborted dispatch's output still reaches the consumers there) and resume in the next
    // hyperperiod, in the next test; the GUMBO checks see the 13 fault at once
    failsWith(d, "watchdog::overrun_fails_the_test",
      "overran its slot; saved pre-states dropped, system assertions suspended until the next frame",
      "sstep failed: a thread overran its slot's watchdog",
      "VIOLATION CEP_Post srcp_src")
    assert(!d("watchdog::overrun_fails_the_test").has("SysAssert") &&
      !d("watchdog::overrun_fails_the_test").has("system assertions resumed"),
      "the system assertions checked the frame the overrun is in")
    passes(d, "watchdog::after_overrun", "system assertions resumed")
    assert(!d("watchdog::after_overrun").has("VIOLATION"), "an overrun produced false violations")
    // what the overran dispatch sent is not taken for its re-dispatch's output
    failsWith(d, "watchdog::overrun_then_quiet", "sstep failed: a thread overran its slot's watchdog")
    assert(!d("watchdog::overrun_then_quiet").has("VIOLATION"),
      "the overran dispatch's output was taken for its re-dispatch's")
    // the frame the system assertions resume in starts at the hyperperiod, not at the resume:
    // what the test injected at its first stop is that frame's
    passes(d, "watchdog::injection_at_frame_start_after_overrun",
      "system assertions resumed", "expected violation: SysAssert nominal/Sent")
    // ... also when the stop before the resume is on the trailing pad of the frame before
    failsWith(d, "watchdog::injection_on_the_trailing_pad_after_overrun",
      "sstep failed: a thread overran its slot's watchdog", "system assertions resumed",
      "expected violation: SysAssert nominal/Sent")
    // after the hyperperiod's last dispatch an injection is the next frame's: nothing to note
    assert(!d("watchdog::injection_on_the_trailing_pad_after_overrun").has("injected after"),
      "an injection on the trailing pad was noted as if it were in the frame before")
    failsWith(d, "watchdog::stop_is_a_failure", "sstep failed: the session was stopped")

    // ---- GUMBO_CHECKS=off: no thread contract is tracked; system assertions still are
    val g = runSystemTests(microkit, ISZ(), ISZ(("GUMBO_CHECKS", "off")))
    passes(g, "checks::nominal_frame")
    failsWith(g, "checks::thread_and_system_violation", "VIOLATION SysAssert nominal/Echoed")
    assert(!g.has("VIOLATION CEP_Post"), "GUMBO_CHECKS=off still reported a CEP_Post")
    passes(g, "checks::c_thread_violation")
    failsWith(g, "toggles::reenable_gumbo", "(GUMBO_CHECKS=off); a test cannot turn them back on")
    passes(g, "toggles::parks_only_while_live")

    // ---- both off: nothing tracked, no parks; command failures still fail a test
    val n = runSystemTests(microkit, ISZ(), ISZ(("GUMBO_CHECKS", "off"), ("SYSVERIF_CHECKS", "off")))
    assert(!n.has("VIOLATION"), "a run with both checks off reported a violation")
    passes(n, "checks::thread_and_system_violation")
    passes(n, "toggles::parks_only_while_live")
    failsWith(n, "watchdog::overrun_fails_the_test", "sstep failed: a thread overran its slot's watchdog")

    // ---- a listing: the table, and nothing run
    val l = runSystemTests(microkit, ISZ("--list", "checks::"), ISZ())
    assert(l.has("DONE  matched=18 passed=0 failed=0 init=ok list=1"), "unexpected listing totals")
    assert(l.lines.count(_.startsWith("TEST | LIST  ")) == 33, "the table does not list every test")
    assert(l.lines.count(x => x.startsWith("TEST | LIST  ") && x.endsWith("(not selected)")) == 15,
      "the table does not mark the unselected tests")
    assert(!l.has("TEST | BEGIN"), "a listing ran a test")
  }

  "under QEMU: a monitor reports a thread that overran its slot instead of checking it mid-dispatch" in {
    if (Os.env("HAMR_ST_QEMU").isEmpty && Os.prop("HAMR_ST_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_ST_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo)")

    // The monitor variants' scheduler gives each slot a fixed time and does not wait for the
    // thread.  A thread still running when the monitor's slot starts was read mid-dispatch and
    // reported as breaking its contract; the scheduler now publishes whether it completed.
    val out = scratch / "monitor-overrun"
    val r = runCodegen(out, T)
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    installFixtures(microkit)
    // dst1 spins far past its 50 ms slot once, between receiving val and acknowledging it
    val app = microkit / "crates" / "d1p_dst" / "src" / "component" / "d1p_dst_app.rs"
    val original = app.read.value
    val ack = "      self.latest = v;\n      api.put_ack(v);"
    assert(original.contains(ack) && original.contains("pub struct d1p_dst {"), "the dst1 fixture changed")
    app.writeOver(String(original
      .replace("#[verus_verify]\npub struct d1p_dst {", "static mut DISPATCHES: u32 = 0;\n\n#[verus_verify]\npub struct d1p_dst {")
      .replace(ack,
        """      self.latest = v;
          |      unsafe {
          |        DISPATCHES += 1;
          |        if DISPATCHES == 10 {
          |          log_info("OVERRUN TEST: spinning past the slot");
          |          let mut x: u64 = 0;
          |          for i in 0..400_000_000u64 { x = core::hint::black_box(x.wrapping_add(i)); }
          |          log_info("OVERRUN TEST: done spinning");
          |        }
          |      }
          |      api.put_ack(v);""".stripMargin)))
    val violations = List("CONTRACT VIOLATION", "SYS ASSERT VIOLATION", "panicked", "PANIC")
    for (config <- List("gumbo_monitor.mk", "sys_head_monitor.mk")) {
      val log = boot(microkit, config, 40)
      assert(log.contains("OVERRUN TEST: done spinning"), s"$config: dst1 did not overrun")
      assert(log.contains("*** OVERRUN: d1p_dst did not complete within its slot"), s"$config: the overrun was not reported")
      val bad = log.split('\n').filter(l => violations.exists(v => l.contains(v)))
      assert(bad.isEmpty, s"$config reported:\n${bad.take(12).mkString("\n")}")
      if (config == "sys_head_monitor.mk")
        assert(log.contains("system assertions of composition head resumed"), s"$config: the system assertions did not resume")
    }
  }

  "under QEMU: a thread that faults or panics does not stop the monitors checking the others" in {
    if (Os.env("HAMR_ST_QEMU").isEmpty && Os.prop("HAMR_ST_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_ST_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo)")

    // A faulted thread is left suspended and never notifies back.  The monitor variants'
    // scheduler counts each dispatch until it does, and a monitor treats any dispatch still
    // counted as an overrun -- so one fault used to stop every check for the rest of the run.
    // The faulted thread's _MON now answers its dispatches: no OVERRUN is reported, and the
    // GUMBO layer goes on checking -- here it reports dst1, which no longer acknowledges what
    // arrives -- and the system layer is never suspended.
    val out = scratch / "monitor-fault"
    val r = runCodegen(out, T)
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    installFixtures(microkit)
    val app = microkit / "crates" / "d1p_dst" / "src" / "component" / "d1p_dst_app.rs"
    val original = app.read.value
    val ack = "      self.latest = v;\n      api.put_ack(v);"
    assert(original.contains(ack) && original.contains("pub struct d1p_dst {"), "the dst1 fixture changed")
    // dst1 stops once, at its 10th dispatch, between receiving val and acknowledging it: with a
    // fault, or with a panic, which the generated panic handler turns into one
    def stopDst1(how: Predef.String): Unit =
      app.writeOver(String(original
        .replace("#[verus_verify]\npub struct d1p_dst {", "static mut DISPATCHES: u32 = 0;\n\n#[verus_verify]\npub struct d1p_dst {")
        .replace(ack,
          s"""      self.latest = v;
             |      unsafe {
             |        DISPATCHES += 1;
             |        if DISPATCHES == 10 {
             |          log_info("FAULT TEST: faulting");
             |          $how
             |        }
             |      }
             |      api.put_ack(v);""".stripMargin)))
    // After the fault dst1 "completes" every dispatch doing nothing, so it no longer acknowledges
    // what arrives: the checks that go on running report that again every hyperperiod -- dst1's
    // own guarantee in the GUMBO layer, and head's Acks in the system layer.  Requiring several
    // shows checking continues, not just the first run after the fault.
    def countOf(text: Predef.String, s: Predef.String): Int = text.sliding(s.length).count(_ == s)
    for (how <- List("core::ptr::write_volatile(8 as *mut u32, 1);", "panic!(\"FAULT TEST: panicking\");");
         (config, evidence) <- List(
           ("gumbo_monitor.mk", "CONTRACT VIOLATION: d1p_dst CEP_Post"),
           ("sys_head_monitor.mk", "SYS ASSERT VIOLATION: property Acks"))) {
      stopDst1(how)
      val log = boot(microkit, config, 40)
      assert(log.contains("FAULT TEST: faulting") && log.contains("d1p_dst_MON | FAULT in user PD"), s"$config: dst1 did not fault")
      val after = log.substring(log.indexOf("FAULT in user PD"))
      // the stopped thread taken for one still running is the failure; another thread's
      // occasional overrun is a real one -- the violations now logged every frame are slow
      // debug output, which can push a later slot past its end -- and checking resumes after it
      assert(!log.contains("OVERRUN: d1p_dst"), s"$config: the stopped thread was taken for one still running:\n${log.split('\n').filter(_.contains("OVERRUN")).take(4).mkString("\n")}")
      assert(countOf(after, evidence) >= 3, s"$config: checking did not go on after the fault (${countOf(after, evidence)} x '$evidence')")
      assert(!after.contains("suspended"), s"$config: the system assertions were suspended after the fault")
      // dst1's own panic is the one expected; any other is a monitor's
      val panics = log.split('\n').filter(l => (l.contains("panicked") || l.contains("PANIC")) && !l.contains("FAULT TEST"))
      assert(how.startsWith("panic") && panics.forall(_.contains("d1p_dst")) || panics.isEmpty,
        s"$config: an unexpected panic:\n${panics.take(4).mkString("\n")}")
    }

    // The monitor variants compile _MON with the fault answer (MON_CFLAGS); the test variant
    // must not link their objects, which share build/ with it: switching variant recompiles them.
    // (system.mk's CFLAGS stamp guarantees it; sDDF's stamp, which the HAMR stamp's rule deletes,
    // happens to as well, so this guards the outcome rather than either mechanism.)
    val switched = Os.proc(ISZ[String]("make", "-C", microkit.value, "CONFIG=test_scheduler.mk", "RUST_MAKE_TARGET=build-release")).run()
    assert(switched.ok, s"test_scheduler.mk did not build:\n${switched.out}\n${switched.err}")
    assert(switched.out.value.contains("-o d1p_dst_MON.o") || switched.out.value.contains("d1p_dst_MON.c -o d1p_dst_MON.o"),
      "switching to the test variant reused the monitor variant's _MON object")
  }

  "under QEMU: a thread that panics before the schedule starts fails the run at once, saying why" in {
    if (Os.env("HAMR_ST_QEMU").isEmpty && Os.prop("HAMR_ST_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_ST_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo)")

    // A thread that panics while initializing never reports ready, so the test scheduler never
    // hands over and no DONE can come.  run-tests.cmd stops QEMU as soon as it sees the panic,
    // instead of waiting out its timeout, and quotes it.
    val out = scratch / "init-panic"
    val r = runCodegen(out)
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    installFixtures(microkit)
    val app = microkit / "crates" / "d1p_dst" / "src" / "component" / "d1p_dst_app.rs"
    val original = app.read.value
    val init = """    log_info("initialize entrypoint invoked");"""
    assert(original.contains(init), "the dst1 fixture changed")
    app.writeOver(String(original.replace(init, init + "\n    panic!(\"INIT PANIC TEST\");")))
    // built first, so the time below is QEMU's (and a relink), not a cold build's
    val build = Os.proc(ISZ[String]("make", "-C", microkit.value, "CONFIG=test_scheduler.mk", "RUST_MAKE_TARGET=build-release")).run()
    assert(build.ok, s"test_scheduler.mk did not build:\n${build.out}\n${build.err}")
    val start = System.currentTimeMillis()
    val run = Os.proc(ISZ[String](sireum.value, "slang", "run", (microkit / "bin" / "run-tests.cmd").value)).run()
    val seconds = (System.currentTimeMillis() - start) / 1000
    assert(!run.ok, "a run whose thread panicked during initialization passed")
    val err = run.err.value
    assert(err.contains("faulted or panicked") && err.contains("INIT PANIC TEST"),
      s"the failure does not quote the panic:\n${err.take(2000)}")
    assert(seconds < 240, s"run-tests.cmd waited ${seconds}s: it did not stop at the panic")
  }

  // Opt-in, as above.  With runtime monitoring and no injected faults (src's mode stays 0), the
  // monitors must report nothing.  dst2's dispatch is not in the monitor slot after src's
  // completion -- dst1 runs between them -- so a monitor reading `val` through one cursor gave
  // dst2's check no event, and its `quiet` guarantee a false violation; each reader now keeps
  // its own count.
  "under QEMU: the monitor images check every thread, the C one included, with no false violations" in {
    if (Os.env("HAMR_ST_QEMU").isEmpty && Os.prop("HAMR_ST_QEMU").isEmpty)
      cancel("set the environment variable or system property HAMR_ST_QEMU to run (needs MICROKIT_SDK, sDDF, qemu-system-aarch64 and cargo)")

    val out = scratch / "monitors"
    val r = runCodegen(out, T)
    r.printMessages()
    assert(!r.hasError, "codegen failed")
    val microkit = out / "microkit"
    installFixtures(microkit)
    val violations = List("CONTRACT VIOLATION", "SYS ASSERT VIOLATION", "SCHEDULE CONFORMANCE VIOLATION",
      "conformance check failed", "panicked", "PANIC")
    // sys_partial_monitor checks a composition that leaves dst1 out: its schedule check must
    // pass over dst1's slot
    // sys_head_monitor checks a composition that ends at dst1, before the others
    for (config <- List("gumbo_monitor.mk", "sys_nominal_monitor.mk", "sys_partial_monitor.mk", "sys_head_monitor.mk")) {
      val log = boot(microkit, config, 30)
      val bad = log.split('\n').filter(l => violations.exists(v => l.contains(v)))
      assert(bad.isEmpty, s"$config reported:\n${bad.take(12).mkString("\n")}")
      // and the system ran: the threads computed, and the sys-assert monitor validated the schedule
      assert(log.contains("compute entrypoint invoked"), s"$config: no thread ran")
      if (config != "gumbo_monitor.mk")
        assert(log.contains("Schedule conformance check passed"), s"$config: the schedule was not validated")
    }
  }
}
