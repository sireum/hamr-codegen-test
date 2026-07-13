package org.sireum.hamr.codegen.test.microkit

// Regression test for --sel4-aux-code-symlink: regeneration over an output that already
// contains the aux symlinks (or dangling ones) must be idempotent and must never modify
// the aux SOURCE directories. Guards against the destructive canon-through-existing-link
// bug where a re-run replaced the source dirs with self-referential symlinks.

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen.common.CommonUtil.Store
import org.sireum.hamr.codegen.common.reporting.CodegenReporting
import org.sireum.hamr.codegen.microkit.plugins.MicrokitPlugins
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.hamr.ir.Aadl
import org.sireum.message.Reporter
import org.sireum.test.TestSuite

class SymlinkAuxCodeTest extends TestSuite {

  val scratchRoot: Os.Path = Os.tempDir() / "hamr-symlink-aux-code-test"

  def runCodegen(auxRoot: Os.Path, resultsDir: Os.Path): Reporter = {
    val tr = MicrokitTestUtil.testResources
    val modelDir = tr.modelsDir / "micro-examples" / "microkit" / "system-verification" / "temp-control" / "sysml"
    val airFile = modelDir / ".slang" / "TempControlSystem_Instance.json"

    var opts = MicrokitTests.baseOptions
    opts = opts(
      workspaceRootDir = Some(modelDir.canon.value),
      packageName = Some("idem"),
      outputDir = Some(resultsDir.canon.value),
      slangOutputDir = Some((resultsDir / "slang").value),
      slangOutputCDir = Some((resultsDir / "c").value),
      sel4OutputDir = Some((resultsDir / "microkit").value),
      sel4AuxCodeDirs = ISZ(
        (auxRoot / "r2u2-lib").canon.value,
        (auxRoot / "sensor-spec").canon.value),
      sel4AuxCodeSymlink = T)

    val model: Aadl = TestUtil.getModel(Some(airFile), None(), modelDir, ISZ(), "idem", F)
    val reporter = Reporter.create
    val store: Store = CodegenReporting.addCodegenReport(CodegenReporting.KEY_TOOL_REPORT,
      CodegenReporting.emptyToolReport, Map.empty)
    val plugins = ArsitPlugin.gumboEnhancedPlugins ++ MicrokitPlugins.defaultMicrokitPlugins

    CodeGen.codeGen(model, T, opts, plugins, store, reporter,
      (_, _) => 0, _ => 0, (_, _) => 0, (_, _) => 0)
    return reporter
  }

  def checkIntact(auxRoot: Os.Path, out: Os.Path, round: String): Unit = {
    // the sources must remain REAL directories with their content
    assert(!(auxRoot / "r2u2-lib").isSymLink, s"$round: source r2u2-lib became a symlink!")
    assert(!(auxRoot / "sensor-spec").isSymLink, s"$round: source sensor-spec became a symlink!")
    assert((auxRoot / "r2u2-lib" / "README.md").isFile, s"$round: source README.md gone!")
    assert((auxRoot / "r2u2-lib" / "r2u2" / "lib.c").isFile, s"$round: source lib.c gone!")
    assert((auxRoot / "sensor-spec" / "sensor_spec.h").isFile, s"$round: source sensor_spec.h gone!")
    // and the output must contain working symlinks
    val lib = out / "microkit" / "aux_code" / "r2u2-lib"
    assert(lib.isSymLink, s"$round: aux_code/r2u2-lib is not a symlink")
    assert((lib / "r2u2" / "lib.c").exists, s"$round: engine not reachable through link")
  }

  "symlink regen twice over same output" in {
    val tr = MicrokitTestUtil.testResources
    val srcR2u2 = tr.modelsDir / "micro-examples" / "microkit" / "system-verification" / "temp-control" / "hamr" / "microkit_mcs" / "r2u2"

    scratchRoot.removeAll()
    val auxRoot = scratchRoot / "aux"
    auxRoot.mkdirAll()
    (srcR2u2 / "r2u2-lib").copyOverTo(auxRoot / "r2u2-lib")
    (srcR2u2 / "sensor-spec").copyOverTo(auxRoot / "sensor-spec")

    val resultsDir = scratchRoot / "results"

    val r1 = runCodegen(auxRoot, resultsDir)
    r1.printMessages()
    assert(!r1.hasError, "round 1: codegen reported errors")
    checkIntact(auxRoot, resultsDir, "round 1")

    // the destructive case: aux_code/* are now existing symlinks; re-run without cleanup
    val r2 = runCodegen(auxRoot, resultsDir)
    r2.printMessages()
    assert(!r2.hasError, "round 2: codegen reported errors")
    checkIntact(auxRoot, resultsDir, "round 2")

    // dangling-link recovery: point the link into the void, then regen
    (resultsDir / "microkit" / "aux_code" / "r2u2-lib").remove()
    Os_ExtShim.danglingLink(resultsDir / "microkit" / "aux_code" / "r2u2-lib")
    val r3 = runCodegen(auxRoot, resultsDir)
    r3.printMessages()
    assert(!r3.hasError, "round 3: codegen reported errors")
    checkIntact(auxRoot, resultsDir, "round 3")
  }
}

object Os_ExtShim {
  def danglingLink(at: Os.Path): Unit = {
    java.nio.file.Files.createSymbolicLink(
      java.nio.file.Paths.get(at.value.native),
      java.nio.file.Paths.get("does-not-exist"))
  }
}
