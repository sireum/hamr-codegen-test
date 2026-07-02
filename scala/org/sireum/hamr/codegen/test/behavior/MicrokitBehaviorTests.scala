package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.common.types.TypeUtil
import org.sireum.hamr.codegen.common.util.ExperimentalOptions
import org.sireum.hamr.codegen.common.util.HamrCli
import org.sireum.hamr.codegen.test.microkit.MicrokitTestUtil
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.hamr.codegen.test.{CodegenBehaviorTest, CodegenTest}

class MicrokitBehaviorTests extends CodegenBehaviorTest {

  def testResources: CodegenTest.TestResources = MicrokitTestUtil.testResources

  override def disablePhantom: B = super.disablePhantom || F // useful when changes to OSATE/AIR have not yet been pushed as plugin releases

  override def justRegenerate: B = super.justRegenerate || F

  override def filter: B = F || super.filter

  override def filters: ISZ[String] = ISZ("sysml_isolette")

  override def ignores: ISZ[String] = super.ignores ++ ISZ(
    "case-transition-models",
    "sys_assert_compositions"
  )

  for (aadlDir <- MicrokitTestUtil.getAadlModels(testResources)) {
    val t = ops.StringOps(aadlDir.up.value)
    var testName = ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")

    // add a small sha to resolve common prefixes in test names
    testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

    var testOptions = MicrokitBehaviorTests.baseOptions

    val cands = Os.Path.walk(aadlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
    assert (cands.size == 1, s"Found ${cands.size} JSON files under $aadlDir")

    assert (ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem)) ||
      (cands(0).up.up.up / "hamr").exists, s"Directory doesn't exist: ${cands(0).up.up.up / "hamr"}  $testName")

    testOptions = testOptions(
      runtimeMonitoring = !ops.StringOps(testName).contains("vms"),
      outputDir = Some((cands(0).up.up.up / "hamr").value),
      workspaceRootDir = Some(cands(0).up.up.value))

    val clean = {
      val aadlDir = cands(0).up.up
      val t = aadlDir / "bin" / "clean.cmd"
      assert (ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem)) ||
        t.exists, s"$t doesn't exist")
      () => proc"$t ${(aadlDir.up / "hamr" / "microkit").value}".run().ok
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

  val sysmlModels = ISZ() :+
    testResources.modelsDir / "isolette" / "sysml" :+
    testResources.modelsDir / "micro-examples" / "microkit" / "system-verification"/ "temp-control" / "sysml"

  for (sysmlDir <- sysmlModels) {
    val t = ops.StringOps(sysmlDir.up.value)
    var testName = s"sysml_${ops.StringOps(t.substring(t.stringIndexOf("INSPECTA-models") + 16, t.s.size)).replaceAllLiterally(Os.fileSep, "_")}"

    // add a small sha to resolve common prefixes in test names
    testName = s"${testName}__${TypeUtil.stableTypeSig(testName, 2)}"

    var testOptions = MicrokitBehaviorTests.baseOptions

    val cands = Os.Path.walk(sysmlDir, T, T, p => p.up.name.native == ".slang" && p.ext.native == "json")
    val airs = cands.filter(p => !ops.StringOps(p.name).contains("_result"))
    assert (airs.size == 1, s"Found ${airs.size} JSON files under ${sysmlDir.toUri}")

    assert ((airs(0).up.up.up / "hamr").exists, s"Directory doesn't exist: ${(airs(0).up.up.up / "hamr").canon}")

    if (testName._value.contains("sysml_iso") || testName._value.contains("temp-control__9F67")) {
      testOptions = testOptions(
        scheduling = HamrCli.CodegenScheduling.UserLand,
        verusAttributeSyntax = T)
    }

    val mdir: Os.Path =
      if (testOptions.scheduling == HamrCli.CodegenScheduling.UserLand)
        airs(0).up.up.up / "hamr" / "microkit_mcs"
      else airs(0).up.up.up / "hamr" / "microkit"

    assert (mdir.exists, mdir.value)

    testOptions = testOptions(
      runtimeMonitoring = !ops.StringOps(testName).contains("vms"),
      sel4OutputDir = Some(mdir.value),
      workspaceRootDir = Some(airs(0).up.up.value))

    val clean = {
      val aadlDir = airs(0).up.up.up / "aadl"
      var t = aadlDir / "bin" / "clean.cmd"
      if (!t.exists) {
        val sysmlDir = airs(0).up.up.up / "sysml"
        t = sysmlDir / "bin" / "clean.cmd"
      }

      assert (t.exists, s"$t doesn't exist")

      () => proc"$t $mdir".run().ok
    }

    test(
      testName = testName,
      testDescription = "",
      testOptions = testOptions,
      testModes = testModes - TestMode.phantom, // don't run phantom on sysml projects
      phantomOptions = None(),
      logikaOptions = None(),
      clean,
      airFile = Some(airs (0)))
  }
}

object MicrokitBehaviorTests {

  val baseOptions: HamrCli.CodegenOption = HamrCli.CodegenOption(
    help = "",
    args = ISZ(),
    msgpack = F,
    verbose = F,
    runtimeMonitoring = F,
    platform = HamrCli.CodegenHamrPlatform.Microkit,
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
    scheduling = HamrCli.CodegenScheduling.Domain,
    verusAttributeSyntax = F,
    sel4OutputDir = None(),
    sel4AuxCodeDirs = ISZ(),
    workspaceRootDir = None(),
    //
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = HamrCli.CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = HamrCli.CodegenLaunchCodeLanguage.Xml,
    invertTopicBinding = F,
    //
    experimentalOptions = ISZ(ExperimentalOptions.GENERATE_REFINEMENT_PROOF)
  )
}