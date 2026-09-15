package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.common.types.TypeUtil
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.codegen.test.microkit.MicrokitTests.baseOptions
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.hamr.codegen.test.util.TestModeHelper.getEnvTestModes

// Codegen tests for the AADL models carrying GUMBO monitor subclauses, i.e. the models
// that exercise R2U2 monitor generation.
//
// Each model provides the same system twice, one AADL package per component language:
//   aadl/rust/<Pkg>.aadl   -> Rust components, generated into hamr/microkit_mcs
//   aadl/c/<Pkg>_C.aadl    -> C components,    generated into hamr/microkit_mcs_c
// Both declare a system implementation named 'Sys.i', which is why they live in separate
// directories: one AADL package per directory keeps phantom and the AIR unambiguous.
//
// These tests generate into the results directory and diff against recorded expectations.
// See R2U2MonitorBehaviorTests for the in-place variant that preserves behavior code.
class R2U2MonitorTests extends CodegenTest {

  override def generateExpected: B = F || super.generateExpected

  override def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  // Initialize to use only test modes received from environment
  override def testModes: ISZ[TestMode.Type] = getEnvTestModes() ++
    ISZ(TestMode.sergen, TestMode.slangcheck)

  override def filter: B = F

  override def filters: ISZ[String] = ISZ()

  override def ignores: ISZ[String] = ISZ()

  override val verbose: B = ops.ISZOps(testModes).contains(TestMode.verbose)

  val r2u2Dir: Os.Path = testResources.modelsDir / "micro-examples" / "microkit" / "r2u2_monitor"

  for (modelDirName <- R2U2MonitorTests.models) {
    for (variantName <- R2U2MonitorTests.variants) {
      val aadlDir = r2u2Dir / modelDirName / "aadl" / variantName

      assert(aadlDir.exists, s"Model directory does not exist: ${aadlDir.toUri}")

      val cands = Os.Path.walk(aadlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
      assert(cands.size == 1, s"Found ${cands.size} AIR files under ${aadlDir.toUri}")

      var testName = s"micro-examples_microkit_r2u2_monitor_${modelDirName}_$variantName"

      // add a small sha to resolve common prefixes in test names
      testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

      test(
        testName = testName,
        modelDir = aadlDir,
        airFile = Some(cands(0)),
        // MCS must be requested via the CLI: the HAMR_Microkit property set defines only SMC
        // and Passive, so an AADL model cannot declare HAMR_Microkit::Scheduling the way its
        // SysML sibling does ('attribute :>> Scheduling = MCS'). Per MicrokitUtil.isMCS, MCS
        // holds when the CLI says UserLand OR the model says MCS, so the flag is the only
        // route from AADL. This matches how the committed hamr/microkit_mcs* trees were made.
        ops = baseOptions(scheduling = HamrCli.CodegenScheduling.UserLand),
        description = Some(s"R2U2 monitor generation for $modelDirName ($variantName components)"),
        modelUri = None(),
        expectedErrorReasons = ISZ())
    }
  }
}

object R2U2MonitorTests {

  val models: ISZ[String] = ISZ(
    "r2u2_component_monitor",
    "r2u2_exhaustive_monitor",
    "r2u2_system_monitor")

  // aadl/<variant> holds that variant's single AADL package
  val variants: ISZ[String] = ISZ("rust", "c")

  // the sel4 output directory of each model's SysMLv2 sibling, which has no per-language split
  val sel4SysmlOutputDirName: String = "microkit_mcs_sysml"

  // the sel4 output directory committed under each model's hamr/
  @pure def sel4OutputDirName(variant: String): String = {
    return if (variant == string"rust") string"microkit_mcs" else string"microkit_mcs_c"
  }
}
