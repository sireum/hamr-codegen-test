package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import org.sireum.message.Reporter
import org.sireum.test.TestSuite
import Ros2Tests._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.containers.FileResource
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}

class Ros2Tests extends TestSuite with Ros2TestUtil {

  val generateExpected: B = F

  val verbose: B = F

  override def testModes: ISZ[TestMode.Type] =
    super.testModes // :+ TestMode.compile

  val root = Os.path(implicitly[sourcecode.File].value).up.up.up.up.up.up.up.up
  val resourceDir: Os.Path = root / "resources"
  val expectedRoot: Os.Path = resourceDir / "expected" / "ros2"
  val resultsRoot: Os.Path = root / "results" / "ros2"

  val codegen_base = resourceDir / "models" / "CodeGenTest_Base"

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
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "datatype-examples_strict" in {
    val testName = "datatype-examples"
    val root = codegen_base / testName
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

  def testRos(testName: String, airFile: Os.Path, modelDir: Os.Path, config: CodegenOption, clearDestDir: B, verbose: B): Unit = {
    val reporter = Reporter.create

    val strictMode = config.strictAadlMode
    val strictModeString = if (strictMode) "strict" else "lax"

    val destDir = getResultsDir(testName, strictModeString)

    val filter: Os.Path => B = _ => true

    copy(testName, filter, strictModeString)

    var failureReasons: ISZ[String] = ISZ()

    val model = TestUtil.getModel(airFile = Some(airFile), phantomOptions = None(), rootAadlDir = modelDir, testModes = ISZ(), testName = testName, verbose = verbose)

    var testOps = config(
      workspaceRootDir = if (config.workspaceRootDir.nonEmpty) config.workspaceRootDir else Some(modelDir.canon.value)
    )

    // TODO: Currently hardcoded, since I'm just working on cpp and xml
    testOps = testOps.apply(
      ros2OutputWorkspaceDir = Some(destDir.value),
      ros2NodesLanguage = CodegenNodesCodeLanguage.Cpp,
      ros2LaunchLanguage = CodegenLaunchCodeLanguage.Xml
    )

    if (clearDestDir) {
      destDir.removeAll()
    }

    println(s"Result Dir: ${destDir.up.toUri}")

    val results = CodeGen.codeGen(
      model = model, shouldWriteOutResources = T, options = testOps,
      plugins = ISZ(), store = Map.empty, reporter = reporter,
      transpilerCallback = (_, _) => 0,
      proyekIveCallback = _ => 0,
      sergenCallback = (_, _) => 0,
      slangCheckCallback = (_, _) => 0)

    failureReasons = failureReasons ++ (for (e <- reporter.errors) yield e.text)

    /*
    if (!reporter.hasError) {
      for (r <- results.resources) {
        val destFile = destDir / r.dstPath
        r match {
          case i: IResource =>
            destFile.writeOver(i.content.render)
            if (verbose) {
              println(s"Wrote: $destFile")
            }
          case _ =>
        }
      }
    }
    */
    if (!reporter.hasError) {
      if (generateExpected) {
        assert(!isCI, "generateExpected should be F when code is pushed to github")

        val expectedDir = this.expectedRoot / testName / strictModeString
        expectedDir.removeAll()
        getResultsDir(testName, strictModeString).copyOverTo(expectedDir)
        println(s"Replaced: ${expectedDir}")
      } else {
        if (!compare(testName, filter, strictModeString)) {
          failureReasons = failureReasons :+ "Results did not match expected"
        }
      }
    }

    if (ops.ISZOps(testModes).contains(TestMode.compile)) {
      // Currently, the results directory is compared with the expected directory before running "colcon build".
      // For an unknown reason, the compare() method halts and does not complete when run after building.
      // Additionally, some details of the building process appear to be version dependent, so comparing before
      // building is probably preferable - Clint
      val longResourcePath = ops.StringOps(results._1.resources(0).asInstanceOf[FileResource].dstPath)
      val resourcePath = longResourcePath.replaceAllLiterally((resultsRoot / testName / "results" / strictModeString / "src").value, "")
      val pkgName = ops.StringOps(resourcePath).split(c => c.toString == "/".toString).apply(0)
      if (ros2SetupPath.nonEmpty) {
        // Building all three packages at the same time seems to be significantly more resource-intensive (my VM just stops halfway through),
        // so I split it up - Clint
        Os.proc(ISZ("bash", "-c", s"source ${ros2SetupPath.get.value}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select ${pkgName}_interfaces"))
          .at(resultsRoot / testName / "results" / strictModeString).console.run()

        val buildResults = Os.proc(ISZ("bash", "-c", s"source ${ros2SetupPath.get.value}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select ${pkgName} ${pkgName}_bringup"))
          .at(resultsRoot / testName / "results" / strictModeString).console.run()

        // The last two packages will only finish if the first package finished
        if (!buildResults.out.toString.contains("Summary: 2 packages finished")) {
          failureReasons = failureReasons :+ "Colcon build failed"
        }
      } else if (dockerAvailable) {
        val platform: String =
          if (Os.isMacArm || Os.isLinuxArm || Os.isWinArm) "linux/arm64/v8"
          else "linux/amd64"

        val args = ISZ[String](
          "docker", "run", "--platform", platform, "--rm", "-v", s"${resultsRoot / testName / "results" / strictModeString}:/root/results", "ros:jazzy", "bash", "-c",
          s"cd /root/results && colcon build --cmake-args -DCMAKE_CXX_FLAGS=-w"
          //s"cd /root/results && colcon build --cmake-args -DCMAKE_CXX_FLAGS=-w --packages-select ${pkgName}_interfaces && colcon build --cmake-args -DCMAKE_CXX_FLAGS=-w --packages-select ${pkgName} ${pkgName}_bringup"
        )
        val buildResults = Os.proc(args).console.run()
        if (!buildResults.ok) {
          failureReasons = failureReasons :+ "Colcon build failed"
        }
      }
    }
    assert(failureReasons.size == 0)
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
