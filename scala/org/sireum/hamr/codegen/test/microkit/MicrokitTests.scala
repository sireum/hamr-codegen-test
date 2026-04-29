package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.common.types.TypeUtil
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}
import org.sireum.hamr.codegen.common.util.ExperimentalOptions
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.codegen.test.microkit.MicrokitTests.baseOptions
import org.sireum.hamr.codegen.test.util.TestModeHelper.getEnvTestModes
import org.sireum.hamr.codegen.test.util.TestMode

class MicrokitTests extends CodegenTest {

  override def generateExpected: B = F || super.generateExpected

  override def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  // Initialize to use only test modes received from environment
  override def testModes: ISZ[TestMode.Type] = getEnvTestModes() ++
    ISZ(TestMode.sergen, TestMode.slangcheck)

  override def filter: B = F

  override def filters: ISZ[String] = ISZ("_types_event_data")

  override def ignores: ISZ[String] = ISZ(
    "case-transition-models"
  )

  override val verbose: B = ops.ISZOps(testModes).contains(TestMode.verbose)

  for (aadlDir <- MicrokitTestUtil.getAadlModels(testResources)) {
    val t = ops.StringOps(aadlDir.up.value)
    var testName = ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")

    // add a small sha to resolve common prefixes in test names
    testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

    // runtime monitoring is not currently supported for vms, also ensure at least one project
    // can be built/simulated when runtime monitoring is not used
    val testOptions = baseOptions(runtimeMonitoring = !testName.value.contains("vms") && !testName.value.contains("aadl_datatypes"))

    val cands = Os.Path.walk(aadlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
    assert (cands.size <= 1, s"Found ${cands.size} JSON files under $aadlDir")

    test(
      testName = testName,
      modelDir = aadlDir,
      airFile = if (cands.size == 1) Some(cands(0)) else None(),
      ops = testOptions,
      description = None(),
      modelUri = None(),
      expectedErrorReasons = ISZ())
  }

  for (sysmlDir <- MicrokitTestUtil.getSysmlModels(testResources.copy(modelsDir = testResources.modelsDir / "micro-examples" / "microkit"))) {
    val t = ops.StringOps(sysmlDir.up.value)
    var testName: String = s"sysml_${ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")}"

    // add a small sha to resolve common prefixes in test names
    testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

    // runtime monitoring is not currently supported for vms, also ensure at least one project
    // can be built/simulated when runtime monitoring is not used
    val testOptions = baseOptions(runtimeMonitoring = !testName.value.contains("vms") && !testName.value.contains("aadl_datatypes"))

    val cands = Os.Path.walk(sysmlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
    assert (cands.size <= 1, s"Found ${cands.size} JSON files under $sysmlDir")

    test(
      testName = testName,
      modelDir = sysmlDir,
      airFile = if (cands.size == 1) Some(cands(0)) else None(),
      ops = testOptions,
      description = None(),
      modelUri = None(),
      expectedErrorReasons = ISZ())
  }
}

object MicrokitTests {

  val baseOptions: CodegenOption = CodegenOption(
    help = "",
    args = ISZ(),
    msgpack = F,
    verbose = F,
    runtimeMonitoring = F,
    platform = CodegenHamrPlatform.Microkit,
    outputDir = None(),
    parseableMessages = F,
    //
    slangOutputDir = None(),
    packageName = None(),
    noProyekIve = T,
    noEmbedArt = F,
    devicesAsThreads = T,
    genSbtMill = T,
    //
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = F,
    //
    sel4OutputDir = None(),
    sel4AuxCodeDirs = ISZ(),
    workspaceRootDir = None(),
    //
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = CodegenLaunchCodeLanguage.Xml,
    invertTopicBinding = F,
    //
    experimentalOptions = ISZ(ExperimentalOptions.GENERATE_REFINEMENT_PROOF)
  )
}
