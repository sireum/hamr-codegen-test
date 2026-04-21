package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.containers.FileResource
import org.sireum.hamr.codegen.common.util.HamrCli.{CodegenLaunchCodeLanguage, CodegenNodesCodeLanguage, CodegenOption}
import org.sireum.hamr.codegen.test.util.{TestMode, TestModeHelper, TestUtil}
import org.sireum.message.Reporter

trait  Ros2TestUtil {

  def testModes: ISZ[TestMode.Type] = TestModeHelper.getEnvTestModes()

  def generateExpected: B = F

  val isCI: B = Os.env("GITLAB_CI").nonEmpty || Os.env("GITHUB_ACTIONS").nonEmpty || Os.env("BUILD_ID").nonEmpty

  def verbose: B

  assert (!isCI || !verbose, "verbose must be F when pushed to github")

  val ros2SetupPath: Option[Os.Path] = Os.env("ROS2_HOME") match {
    case Some(dist) =>
      if ((Os.path(dist) / "setup.bash").exists) Some((Os.path(dist) / "setup.bash"))
      else None()
    case _ => None()
  }

  val dockerAvailable: B =
    ros2SetupPath match {
      case None() if !isCI =>
        val dockerOnPath = scala.Option(System.getenv("PATH")).getOrElse("").split(java.io.File.pathSeparator)
          .exists(d => new java.io.File(d, "docker").canExecute)
        dockerOnPath && proc"docker info".run().ok
      case _ => F
    }

  val microrosWsOpt: Option[Os.Path] = Os.env("MICROROS_WS") match {
    case Some(ws) =>
      val p = Os.path(ws)
      if ((p / "install" / "setup.bash").exists) Some(p)
      else None()
    case _ => None()
  }

  def expectedRoot: Os.Path
  def resultsRoot: Os.Path

  def copy(testName: String, filter: Os.Path => B = x => T, strictModeString: String): Os.Path = {
    val srcDir = expectedRoot / testName / strictModeString
    val resultDir = getExpectedDir(testName, strictModeString)
    resultDir.removeAll()

    for (r <- Os.Path.walk(srcDir, F, F, filter)) {
      val dest = resultDir / srcDir.relativize(r).value
      r.copyOverTo(dest)
    }
    return resultDir
  }

  def getExpectedDir(testName: String, strictModeString: String): Os.Path = resultsRoot / testName / "expected" / strictModeString
  def getResultsDir(testName: String, strictModeString: String): Os.Path = resultsRoot / testName / "results" / strictModeString

  def compare(testName: String, filter: Os.Path => B = _ => T, strictModeString: String): B = {
    val expected = getExpectedDir(testName, strictModeString)
    val results = getResultsDir(testName, strictModeString)

    def toMap(dir: Os.Path): Map[String, Os.Path] = {
      var ret = Map.empty[String, Os.Path]

      def iter(d: Os.Path): Unit = {
        if (d.isFile && filter(d)) ret = ret + dir.relativize(d).value ~> d
        else for (dd <- d.list) yield iter(dd)
      }

      iter(dir)
      return ret
    }

    val eMap = toMap(expected)
    val rMap = toMap(results)

    def compareKeys(a: Set[String], b: Set[String], dir: Os.Path): B = {
      val diff = a -- b.elements
      for (d <- diff.elements) {
        println(s"Couldn't match ${(dir / d).toUri}")
      }
      return diff.isEmpty
    }

    val (eSet, rSet) = (Set.empty ++ eMap.keys, Set.empty ++ rMap.keys)
    var sameContent = compareKeys(eSet, rSet, expected) & compareKeys(rSet, eSet, results)

    if (sameContent) {
      for (e <- eMap.keys) {
        val ef = expected / e
        val rf = results / e
        val expectedText = ops.StringOps(ef.read).replaceAllLiterally("\r\n", "\n")
        val resultsText = ops.StringOps(rf.read).replaceAllLiterally("\r\n", "\n")
        if (expectedText != resultsText) {
          sameContent = F
          val dmp = new DiffMatchPatch()
          println(s"File content differs: ${rf.toUri}")
          println(dmp.patch_toText(dmp.patch_make(expectedText.native, resultsText.native)))
        }
      }
    }
    return sameContent
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

    if (!reporter.hasError) {
      if (generateExpected) {
        assert(!isCI, "generateExpected should be F when code is pushed to github")

        val expectedDir = this.expectedRoot / testName / strictModeString
        expectedDir.removeAll()
        getResultsDir(testName, strictModeString).copyOverTo(expectedDir)
        println(s"Replaced: $expectedDir")
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
      val pkgName = ops.StringOps(resourcePath).split(c => c.toString == "/").apply(0)
      val microrosAppsDir = destDir / "microros_apps"
      val hasMicroros = microrosAppsDir.exists && microrosAppsDir.isDir
      if (ros2SetupPath.nonEmpty) {
        // Building all three packages at the same time seems to be significantly more resource-intensive (my VM just stops halfway through),
        // so I split it up - Clint
        val interfacesResults = Os.proc(ISZ("bash", "-c",
            s"source ${ros2SetupPath.get.value}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select ${pkgName}_interfaces"))
          .at(resultsRoot / testName / "results" / strictModeString).echo.run()
        if (interfacesResults.ok) {
          val bringUpResults = Os.proc(ISZ("bash", "-c",
              s"source ${ros2SetupPath.get.value}; colcon build --cmake-args -DCMAKE_CXX_FLAGS=\"-w\" --packages-select $pkgName ${pkgName}_bringup"))
            .at(resultsRoot / testName / "results" / strictModeString).echo.run()

          if (!bringUpResults.ok) {
            println("--std out--")
            cprintln(F, bringUpResults.out)
            println("--std err--")
            cprintln(T, bringUpResults.err)

            failureReasons = failureReasons :+ "Bringup colcon build failed"
          }

          if (hasMicroros) {
            microrosWsOpt match {
              case Some(microrosWs) =>
                val interfacesPkg = s"${pkgName}_interfaces"
                val microrosPkgs = microrosAppsDir.list.filter(p => p.isDir)
                (destDir / "src" / interfacesPkg).copyOverTo(microrosWs / "src" / interfacesPkg)
                for (pkg <- microrosPkgs) {
                  pkg.copyOverTo(microrosWs / "src" / pkg.name)
                }
                val microrosPkgNames = microrosPkgs.map(_.name).elements.mkString(" ")
                val microrosSetupPath = microrosWs / "install" / "setup.bash"
                val microrosResults = Os.proc(ISZ[String]("bash", "-c",
                    s"source ${ros2SetupPath.get.value} && source ${microrosSetupPath.value}; colcon build --packages-select $interfacesPkg $microrosPkgNames"))
                  .at(microrosWs).echo.run()
                if (!microrosResults.ok) {
                  println("--std out--")
                  cprintln(F, microrosResults.out)
                  println("--std err--")
                  cprintln(T, microrosResults.err)
                  failureReasons = failureReasons :+ "microROS colcon build failed"
                }
              case _ =>
                cprintln(T, "Warning: project has microROS nodes but MICROROS_WS is not set or initialized; skipping microROS build")
            }
          }
        } else {
          println("--std out--")
          cprintln(F, interfacesResults.out)
          println("--std err--")
          cprintln(T, interfacesResults.err)
          failureReasons = failureReasons :+ "Interfaces colcon build failed"
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
        val buildResults = Os.proc(args).echo.run()
        if (!buildResults.ok) {
          println("--std out--")
          cprintln(F, buildResults.out)
          println("--std err--")
          cprintln(T, buildResults.err)
          failureReasons = failureReasons :+ "Colcon build failed"
        }
        if (hasMicroros && microrosWsOpt.isEmpty) {
          cprintln(T, "Warning: project has microROS nodes but MICROROS_WS is not set or initialized; skipping microROS build")
        }
      }
    }
    assert(failureReasons.size == 0)
  }
}
