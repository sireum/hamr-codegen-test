package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.common.types.TypeUtil
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.test.microkit.{MicrokitTestUtil, R2U2MonitorTests}
import org.sireum.hamr.codegen.test.{CodegenBehaviorTest, CodegenTest}

// Behavior tests for the AADL models carrying GUMBO monitor subclauses.
//
// Unlike R2U2MonitorTests -- which generates into the results directory and diffs against
// recorded expectations -- these regenerate in place over the trees committed under each
// model's hamr/ directory. The point is that hand-written behavior code survives: codegen
// will not overwrite *_app.rs, *_user.c, *_MON_user.c or tests.rs, and aadl/bin/clean.cmd
// preserves exactly those while removing everything marked "Do not edit".
//
// Layout, per model:
//   aadl/rust/<Pkg>.aadl   -> hamr/microkit_mcs     (Rust components)
//   aadl/c/<Pkg>_C.aadl    -> hamr/microkit_mcs_c   (C components)
//   sysml/                 -> hamr/microkit_mcs_sysml, produced by the model's own
//                             run-hamr.cmd and never touched here
// Each variant directory holds one AADL package and its own .slang AIR, so the two
// same-named 'Sys.i' system implementations never collide.
class R2U2MonitorBehaviorTests extends CodegenBehaviorTest {

  def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  override def disablePhantom: B = super.disablePhantom || F

  override def justRegenerate: B = super.justRegenerate || F

  override def filter: B = F || super.filter

  override def filters: ISZ[String] = ISZ()

  override def ignores: ISZ[String] = super.ignores ++ ISZ()

  val r2u2Dir: Os.Path = testResources.modelsDir / "micro-examples" / "microkit" / "r2u2_monitor"

  for (modelDirName <- R2U2MonitorTests.models) {
    val modelDir = r2u2Dir / modelDirName
    val hamrDir = modelDir / "hamr"

    assert(hamrDir.exists, s"Generated directory does not exist: ${hamrDir.toUri}")

    for (variantName <- R2U2MonitorTests.variants) {
      val aadlDir = modelDir / "aadl" / variantName
      val sel4OutputDir = hamrDir / R2U2MonitorTests.sel4OutputDirName(variantName)

      assert(aadlDir.exists, s"Model directory does not exist: ${aadlDir.toUri}")
      assert(sel4OutputDir.exists, s"Output directory does not exist: ${sel4OutputDir.toUri}")

      val cands = Os.Path.walk(aadlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
      assert(cands.size == 1, s"Found ${cands.size} AIR files under ${aadlDir.toUri}")

      var testName = s"micro-examples_microkit_r2u2_monitor_${modelDirName}_$variantName"

      // add a small sha to resolve common prefixes in test names
      testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

      // See R2U2MonitorTests for why MCS has to come from the CLI rather than the model.
      val testOptions = MicrokitBehaviorTests.baseOptions(
        scheduling = HamrCli.CodegenScheduling.UserLand,
        outputDir = Some(hamrDir.value),
        sel4OutputDir = Some(sel4OutputDir.value),
        workspaceRootDir = Some(aadlDir.value))

      // clean only this variant's output, leaving the sibling variant and the SysML tree intact
      val clean = {
        val c = modelDir / "aadl" / "bin" / "clean.cmd"
        assert(c.exists, s"${c.toUri} doesn't exist")
        (env: ISZ[(String, String)]) => proc"$c ${sel4OutputDir.value}".env(env).run().ok
      }

      test(
        testName = testName,
        testDescription = s"R2U2 monitor behavior for $modelDirName ($variantName components)",
        testOptions = testOptions,
        testModes = testModes,
        phantomOptions = None(),
        logikaOptions = None(),
        clean = clean,
        env = ISZ(),
        airFile = Some(cands(0)))
    }
  }
}
