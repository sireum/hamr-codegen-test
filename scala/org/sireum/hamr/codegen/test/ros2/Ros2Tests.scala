package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.message.Reporter
import org.sireum.test.TestSuite
import Ros2Tests._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.util.CodeGenResults
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenHamrPlatform, CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}

class Ros2Tests extends TestSuite with Ros2TestUtil {

  val generateExpected: B = F

  val verbose: B = F

  // TODO: The ROS2 setup file is currently hardcoded!  Will need to change
  val ros2SetupPath: String = "/opt/ros/humble/setup.bash"
  val buildRosPkgs: B = F

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

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false), verbose)
  }

  "building_control_gen_mixed_strict" in {
    val testName = "building_control_gen_mixed"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true), verbose)
  }

  "isolette_lax" in {
    val testName = "isolette"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false), verbose)
  }

  "isolette_strict" in {
    val testName = "isolette"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true), verbose)
  }

  // TODO: Fix/implement PCA Pump to-do types
  "pca-pump_lax" in {
    val testName = "pca-pump"
    val root = codegen_base / testName
    val airFile = getAir(root / "pca")
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false), verbose)
  }

  // TODO: Fix/implement PCA Pump to-do types
  "pca-pump_strict" in {
    val testName = "pca-pump"
    val root = codegen_base / testName
    val airFile = getAir(root / "pca")
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true), verbose)
  }

  "datatype-examples_lax" in {
    val testName = "datatype-examples"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false), verbose)
  }

  "datatype-examples_strict" in {
    val testName = "datatype-examples"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true), verbose)
  }

  def testRos(testName: String, airFile: Os.Path, modelDir: Os.Path, config: CodegenOption, verbose: B): Unit = {
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

    destDir.removeAll()
    println(s"Result Dir: ${destDir.up.toUri}")

    val results: CodeGenResults = CodeGen.codeGen(
      model = model, shouldWriteOutResources = T, options = testOps, plugins = MSZ(), reporter = reporter,
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

    if (generateExpected) {
      assert (!isCI, "generateExpected should be F when code is pushed to github")

      val expectedDir = this.expectedRoot / testName / strictModeString
      expectedDir.removeAll()
      getResultsDir(testName, strictModeString).copyOverTo(expectedDir)
      println(s"Replaced: ${expectedDir}")
    } else {
      if (!compare(testName, filter, strictModeString)) {
        failureReasons = failureReasons :+ "Results did not match expected"
      }
    }

    // Currently, the results directory is compared with the expected directory before running "colcon build".
    // For an unknown reason, the compare() method halts and does not complete when run after building.
    // Additionally, some details of the building process appear to be version dependent, so comparing before
    // building is probably preferable - Clint
    if (buildRosPkgs) {
      val longResourcePath = ops.StringOps(results.resources.apply(0).dstPath)
      val resourcePath = longResourcePath.replaceAllLiterally((resultsRoot / testName / "results" / strictModeString / "src").value, "")
      val pkgName = ops.StringOps(resourcePath).split(c => c.toString == "/".toString).apply(0)

      // Building all three packages at the same time seems to be significantly more resource-intensive (my VM just stops halfway through),
      // so I split it up - Clint
      Os.proc(ISZ("bash", "-c", s"source ${ros2SetupPath}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select ${pkgName}_interfaces"))
        .apply(wd = resultsRoot / testName / "results" / strictModeString).console.run()

      val buildResults = Os.proc(ISZ("bash", "-c", s"source ${ros2SetupPath}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select ${pkgName} ${pkgName}_bringup"))
        .apply(wd = resultsRoot / testName / "results" / strictModeString).console.run()

      // The last two packages will only finish if the first package finished
      if (!buildResults.out.toString.contains("Summary: 2 packages finished")) {
        failureReasons = failureReasons :+ "Colcon build failed"
      }
    }

    // The PCA Pump model should fail with 63 unknown-datatype-related errors
    if (testName.toString.compareTo("pca-pump") == 0) {
      assert(failureReasons.size == 63)
    }
    else {
      assert(failureReasons.size == 0)
    }
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
    camkesOutputDir = None(),
    camkesAuxCodeDirs = ISZ(),
    workspaceRootDir = None(),
    // ros2 options
    strictAadlMode = F,
    ros2OutputWorkspaceDir = None(),
    ros2Dir = None(),
    ros2NodesLanguage = CodegenNodesCodeLanguage.Cpp,
    ros2LaunchLanguage = CodegenLaunchCodeLanguage.Xml,
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