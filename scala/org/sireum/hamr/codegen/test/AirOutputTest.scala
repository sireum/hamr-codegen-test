package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.common.util.CodeGenResults
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenAirOutputFormat, CodegenHamrPlatform, CodegenOption}
import org.sireum.hamr.codegen.test.microkit.MicrokitTestUtil
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.ir
import org.sireum.hamr.ir.{JSON => irJSON, MsgPack => irMsgPack}
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

// The --air-output option (doc/TODO.md, "Option to write out the AIR model"): CodeGen.codeGen
// writes the model it was given, before any check, and stops with an error when it cannot.  The
// command-line side (SysML frontend, //@ HAMR: directives, re-running hamr codegen on the export)
// is not reachable from here.
class AirOutputTest extends TestSuite {

  val modelsDir: Os.Path = MicrokitTestUtil.resourcesDir / "models"
  val resultsDir: Os.Path = (MicrokitTestUtil.resourcesDir.up / "results" / "AirOutputTest").canon

  // an AADL (OSATE) AIR and a SysML-derived AIR whose components carry GUMBO
  val aadlAir: Os.Path = modelsDir / "CodeGenTest_Base" / "testevent" / ".slang" / "testevent_top_impl_Instance.json"
  val gumboAir: Os.Path = modelsDir / "SystemTesting" / "stateless" / "sysml" / ".slang" / "top_impl_Instance.json"

  case class Run(reporter: Reporter, results: CodeGenResults, out: Predef.String, err: Predef.String)

  def fromJson(s: String): ir.Aadl = {
    irJSON.toAadl(s) match {
      case Either.Left(m) => return m
      case Either.Right(m) => halt(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
    }
  }

  def fromMsgPack(data: ISZ[U8]): ir.Aadl = {
    irMsgPack.toAadl(data) match {
      case Either.Left(m) => return m
      case Either.Right(m) => halt(s"MsgPack deserialization error at offset ${m.offset}: ${m.message}")
    }
  }

  def base64Bytes(p: Os.Path): ISZ[U8] = {
    conversions.String.fromBase64(p.read) match {
      case Either.Left(u) => return u
      case Either.Right(m) => halt(m)
    }
  }

  // decodes an export the way hamr codegen reads it (Base64 before MsgPack, see HAMR.codeGen)
  def readExport(p: Os.Path, format: CodegenAirOutputFormat.Type): ir.Aadl = {
    return if (format == CodegenAirOutputFormat.Json) fromJson(p.read) else fromMsgPack(base64Bytes(p))
  }

  def options(name: String, platform: CodegenHamrPlatform.Type, airOutput: Os.Path,
              format: CodegenAirOutputFormat.Type): CodegenOption = {
    return CodegenTest.baseOptions(
      platform = platform,
      outputDir = Some((resultsDir / name / "hamr").value),
      airOutput = Some(airOutput.value),
      airOutputFormat = format)
  }

  def run(model: ir.Aadl, o: CodegenOption, writeOutResources: B): Run = {
    val reporter = Reporter.create
    // the Microkit reporter plugin expects the tool report the command line seeds
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    org.sireum.$internal.RuntimeConsole.beginCapture()
    var captured: Array[Predef.String] = Array("", "")
    val results = try CodeGen.codeGen(model, writeOutResources, o,
      ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins, store, reporter,
      (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)._1
    finally {
      captured = org.sireum.$internal.RuntimeConsole.endCapture()
    }
    return Run(reporter, results, captured(0), captured(1))
  }

  // c with the first port of its first thread (depth-first) made bi-directional; T when one was changed
  def inOutThreadPort(c: ir.Component): (ir.Component, B) = {
    if (c.category == ir.ComponentCategory.Thread) {
      val i = c.features.elements.indexWhere {
        case fe: ir.FeatureEnd => fe.category != ir.FeatureCategory.FeatureGroup && fe.direction != ir.Direction.InOut
        case _ => false
      }
      if (i >= 0) {
        val fe = c.features(i).asInstanceOf[ir.FeatureEnd]
        return (c(features = c.features(Z(i) ~> fe(direction = ir.Direction.InOut))), T)
      }
    }
    var subs = c.subComponents
    for (i <- subs.indices) {
      val (s, changed) = inOutThreadPort(subs(i))
      if (changed) {
        subs = subs(i ~> s)
        return (c(subComponents = subs), T)
      }
    }
    return (c, F)
  }

  def errors(r: Reporter): ISZ[String] = for (m <- r.errors) yield m.text

  def fresh(name: String): Os.Path = {
    val d = resultsDir / name
    d.removeAll()
    d.mkdirAll()
    return d
  }

  def roundTrip(name: String, air: Os.Path, platform: CodegenHamrPlatform.Type): Unit = {
    val model = fromJson(air.read)
    val dir = fresh(name)
    for (format <- ISZ(CodegenAirOutputFormat.Json, CodegenAirOutputFormat.Msgpack)) {
      val out = dir / "nested" / s"model.$format" // the parent does not exist yet
      val r = run(model, options(name, platform, out, format), F)
      assert(out.exists, s"$format: no export at $out (errors: ${errors(r.reporter)})")
      assert(readExport(out, format) == model, s"$format: the export differs from the model codegen was given")
      assert(r.out.contains(s"Wrote: $out"), s"$format: no 'Wrote: $out' line")
      if (format == CodegenAirOutputFormat.Msgpack) {
        val pooled = irMsgPack.fromAadl(model, T)
        assert(base64Bytes(out) == pooled, "the MsgPack export is not the pooled encoding")
        // the reader takes either encoding, whatever the writer chose
        assert(fromMsgPack(pooled) == model && fromMsgPack(irMsgPack.fromAadl(model, F)) == model)
      }
    }
  }

  // writes `model` (which codegen will reject) and checks that the export still equals it
  def exportedBeforeFailure(name: String, model: ir.Aadl, platform: CodegenHamrPlatform.Type,
                            expectedError: Predef.String): Unit = {
    val dir = fresh(name)
    for (format <- ISZ(CodegenAirOutputFormat.Json, CodegenAirOutputFormat.Msgpack)) {
      val out = dir / s"model.$format"
      val r = run(model, options(name, platform, out, format), F)
      assert(r.reporter.hasError, s"$format: expected codegen to fail")
      assert(errors(r.reporter).elements.exists(e => e.value.contains(expectedError)),
        s"$format: expected an error containing '$expectedError' but found ${errors(r.reporter)}")
      assert(out.exists, s"$format: no export at $out")
      assert(readExport(out, format) == model, s"$format: the export is not the model codegen was given")
    }
  }

  val tests = Tests {

    * - roundTrip("aadl-roundtrip", aadlAir, CodegenHamrPlatform.JVM)

    * - roundTrip("sysml-roundtrip", gumboAir, CodegenHamrPlatform.Microkit)

    * - {
      // CodeGen.codeGen's own structural check: exactly one root component
      val model = fromJson(aadlAir.read)
      exportedBeforeFailure("structural-check", model(components = model.components ++ model.components),
        CodegenHamrPlatform.JVM, "Expecting exactly one root component")
    }

    * - {
      // ModelUtil.resolve: thread ports must be uni-directional
      val model = fromJson(aadlAir.read)
      val broken = model(components = for (c <- model.components) yield inOutThreadPort(c)._1)
      assert(broken != model, "the fixture has no thread port to make bi-directional")
      exportedBeforeFailure("model-resolution", broken, CodegenHamrPlatform.JVM, "Invalid direction: InOut")
    }

    * - {
      // GUMBO resolution: the `echo` guarantee's `mode` (line 37, column 22 of the SysML source)
      // renamed to a port that does not exist
      val ident = java.util.regex.Pattern.compile(
        "(\"type\"\\s*:\\s*\"org\\.sireum\\.lang\\.ast\\.Id\"\\s*,\\s*\"value\"\\s*:\\s*)\"mode\"" +
          "(\\s*,\\s*\"attr\"\\s*:\\s*\\{\\s*\"type\"\\s*:\\s*\"org\\.sireum\\.lang\\.ast\\.Attr\"\\s*,\\s*\"posOpt\"\\s*:\\s*\\{\\s*" +
          "\"type\"\\s*:\\s*\"Some\"\\s*,\\s*\"value\"\\s*:\\s*\\{\\s*\"type\"\\s*:\\s*\"Position\"\\s*,\\s*\"uriOpt\"\\s*:\\s*\\{[^{}]*\\}\\s*,\\s*" +
          "\"beginLine\"\\s*:\\s*37\\s*,\\s*\"beginColumn\"\\s*:\\s*22\\b)")
      val m = ident.matcher(gumboAir.read.value)
      val mutated = m.replaceAll("$1\"noSuchPort\"$2")
      assert(mutated != gumboAir.read.value, "the fixture no longer has the `mode` identifier this test renames")
      exportedBeforeFailure("gumbo-resolution", fromJson(String(mutated)), CodegenHamrPlatform.Microkit, "noSuchPort")
    }

    * - {
      val name = "overwrite"
      val model = fromJson(aadlAir.read)
      val out = fresh(name) / "model.json"
      out.writeOver("stale content")
      run(model, options(name, CodegenHamrPlatform.JVM, out, CodegenAirOutputFormat.Json), F)
      assert(readExport(out, CodegenAirOutputFormat.Json) == model)
    }

    * - {
      // the export's parent is an existing file, so neither mkdirAll nor the write can succeed
      val name = "unwritable"
      val dir = fresh(name)
      val blocker = dir / "blocker"
      blocker.writeOver("a file, not a directory")
      val out = blocker / "model.json"
      val o = options(name, CodegenHamrPlatform.JVM, out, CodegenAirOutputFormat.Json)
      val r = run(fromJson(aadlAir.read), o, T)
      assert(errors(r.reporter).elements.exists(e => e.value.contains(s"Could not write the AIR model to $out: $blocker exists and is not a directory")),
        s"expected a write error but found ${errors(r.reporter)}")
      assert(!r.out.contains("Wrote:"), "reported a write that did not happen")
      assert((r.out + r.err).contains("Could not write the AIR model"), "the error was not printed")
      assert(!r.err.contains("Exception") && !r.err.contains("java.lang.Error"), s"a stack trace reached the console: ${r.err}")
      assert(r.results.resources.isEmpty, "generation went ahead")
      assert(!Os.path(o.outputDir.get).exists, "generation wrote output")
      assert(blocker.read == String("a file, not a directory"))
    }
  }
}
