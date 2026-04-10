package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.test.TestSuite
import Ros2Tests._
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}

class Ros2Tests extends TestSuite with Ros2TestUtil {

  val generateExpected: B = F

  val verbose: B = F

  override def testModes: ISZ[TestMode.Type] =
    super.testModes // :+ TestMode.compile

  val root: Os.Path = Os.path(implicitly[sourcecode.File].value).up.up.up.up.up.up.up.up
  val resourceDir: Os.Path = root / "resources"
  val expectedRoot: Os.Path = resourceDir / "expected" / "ros2"
  val resultsRoot: Os.Path = root / "results" / "ros2"

  val codegen_base: Os.Path = resourceDir / "models" / "CodeGenTest_Base"

  val ros_base: Os.Path = resourceDir / "models" / "Ros2"

  "building_control_gen_mixed_lax" in {
    val testName = "building_control_gen_mixed"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "building_control_gen_mixed_strict" in {
    val testName = "building_control_gen_mixed"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = false), T, verbose)
  }

  "isolette_lax" in {
    val testName = "isolette"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "isolette_strict" in {
    val testName = "isolette"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = false), T, verbose)
  }

  // TODO: Fix/implement PCA Pump to-do types
  "pca-pump_lax" ignore {
    val testName = "pca-pump"
    val root = codegen_base / testName
    val airFile = getAir(root / "pca")
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  // TODO: Fix/implement PCA Pump to-do types
  "pca-pump_strict" ignore {
    val testName = "pca-pump"
    val root = codegen_base / testName
    val airFile = getAir(root / "pca")
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = true), T, verbose)
  }

  "datatype-examples_lax" in {
    val testName = "datatype-examples"
    val root = ros_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "datatype-examples_strict" in {
    val testName = "datatype-examples"
    val root = ros_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = false), T, verbose)
  }

  "fan_in_fan_out_lax" in {
    val testName = "fan_in_fan_out"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "fan_in_fan_out_strict" in {
    val testName = "fan_in_fan_out"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = false), T, verbose)
  }

  // ----------------------------------
  // Inverted Port/Topic Binding Tests
  // ----------------------------------

  "building_control_gen_mixed_lax_inverted_topics" in {
    val testName = "building_control_gen_mixed_inverted_topics"
    val rootName = "building_control_gen_mixed"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = true), T, verbose)
  }

  "building_control_gen_mixed_strict_inverted_topics" in {
    val testName = "building_control_gen_mixed_inverted_topics"
    val rootName = "building_control_gen_mixed"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = true), T, verbose)
  }

  "isolette_lax_inverted_topics" in {
    val testName = "isolette_inverted_topics"
    val rootName = "isolette"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = true), T, verbose)
  }

  "isolette_strict_inverted_topics" in {
    val testName = "isolette_inverted_topics"
    val rootName = "isolette"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = true), T, verbose)
  }

  "fan_in_fan_out_lax_inverted_topics" in {
    val testName = "fan_in_fan_out_inverted_topics"
    val rootName = "fan_in_fan_out"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = true), T, verbose)
  }

  "fan_in_fan_out_strict_inverted_topics" in {
    val testName = "fan_in_fan_out_inverted_topics"
    val rootName = "fan_in_fan_out"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = true), T, verbose)
  }

  // ----------------------------------
  // File Change Persistence Tests
  // ----------------------------------

  // TODO: This test currently relies on modifying the 'results' directory, which is not included in the git repo.
  "marker_test_building_control_lax" ignore {
    val testName = "marker_test_building_control"
    val rootName = "building_control_gen_mixed"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false), F, verbose)
  }

  // TODO: This test currently relies on modifying the 'results' directory, which is not included in the git repo.
  "marker_test_building_control_strict" ignore {
    val testName = "marker_test_building_control"
    val rootName = "building_control_gen_mixed"
    val root = codegen_base / rootName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true), F, verbose)
  }
}

object Ros2Tests {
  val baseOptions = CodegenOption(
    help = "",
    args = ISZ(),
    msgpack = F,
    verbose = F,
    runtimeMonitoring = F,
    platform = CodegenHamrPlatform.Ros2,
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
    // ros2 options
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = CodegenLaunchCodeLanguage.Xml,
    invertTopicBinding = F,
    //
    experimentalOptions = ISZ()
  )

  def getAir(path: Os.Path): Os.Path = {
    val p = path / ".slang"
    val ps = Os.Path.walk(path = p, includeDir = F, followLink = F, p => p.ext.native == "json")
    assert (ps.size == 1, ps.size)
    return ps(0)
  }
}
