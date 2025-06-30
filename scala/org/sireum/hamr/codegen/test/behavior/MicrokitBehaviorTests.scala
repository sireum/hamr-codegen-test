package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.common.types.TypeUtil
import org.sireum.hamr.codegen.common.util.ExperimentalOptions
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}
import org.sireum.hamr.codegen.test.microkit.MicrokitTestUtil
import org.sireum.hamr.codegen.test.{CodegenBehaviorTest, CodegenTest}

class MicrokitBehaviorTests extends CodegenBehaviorTest {

  def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  override def disablePhantom: B = super.disablePhantom || F // useful when changes to OSATE/AIR have not yet been pushed as plugin releases

  override def justRegenerate: B = super.justRegenerate || F

  override def filter: B = super.filter || F

  override def filters: ISZ[String] = ISZ("isolette")

  override def ignores: _root_.org.sireum.ISZ[String] = super.ignores ++ ISZ(
    "case-transition-models",

    // TODO: adapt to crust/verus
    "micro-examples_microkit_aadl_port_types_event__FF6D",
  )

  for (aadlDir <- MicrokitTestUtil.getAadlModels(testResources)) {
    val t = ops.StringOps(aadlDir.up.value)
    var testName = ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")

    // add a small sha to resolve common prefixes in test names
    testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

    var testOptions = MicrokitBehaviorTests.baseOptions

    val cands = Os.Path.walk(aadlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
    assert (cands.size == 1, s"Found ${cands.size} JSON files under $aadlDir")

    assert ((cands(0).up.up.up / "hamr").exists, s"Directory doesn't exist: ${cands(0).up.up.up / "hamr"}")

    testOptions = testOptions(
      outputDir = Some((cands(0).up.up.up / "hamr").value),
      workspaceRootDir = Some(cands(0).up.up.value))

    val clean = {
      val t = cands(0).up.up / "bin" / "clean.cmd"
      assert (t.exists, s"$t doesn't exist")
      () => proc"$t ../../hamr/microkit".run().ok
    }

    test(
      testName = testName,
      testDescription = "",
      testOptions = testOptions,
      testModes = testModes,
      phantomOptions = None(),
      logikaOptions = None(),
      clean,
      airFile = Some(cands (0)))
  }
}

object MicrokitBehaviorTests {

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