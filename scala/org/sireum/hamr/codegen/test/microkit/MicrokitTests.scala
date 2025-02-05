package org.sireum.hamr.codegen.test.microkit

import org.sireum._
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}
import org.sireum.hamr.codegen.common.util.ExperimentalOptions
import org.sireum.hamr.codegen.test.CodegenTest
import org.sireum.hamr.codegen.test.microkit.MicrokitTests.baseOptions
import org.sireum.hamr.codegen.test.util.TestModeHelper.getEnvTestModes
import org.sireum.hamr.codegen.test.util.TestMode

class MicrokitTests extends CodegenTest {

  override def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  // Initialize to use only test modes received from environment
  override def testModes: ISZ[TestMode.Type] = getEnvTestModes() ++
    ISZ(TestMode.sergen, TestMode.slangcheck)
  
  override def generateExpected: B = super.generateExpected || F

  override def filter: B = F

  override def filters: ISZ[String] = ISZ("simple_temp_aadl-sporadic")

  override def ignores: ISZ[String] = ISZ("case-transition-models")

  override val verbose: B = ops.ISZOps(testModes).contains(TestMode.verbose)

  for (aadlDir <- MicrokitTestUtil.getAadlModels(testResources)) {
    val t = ops.StringOps(aadlDir.up.value)
    val testName = ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")

    val testOptions = baseOptions

    val cands = Os.Path.walk(aadlDir, T, T, p => p.ext.native == "json")
    assert (cands.size <= 1)

    test(
      testName = testName,
      modelDir = aadlDir,
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
