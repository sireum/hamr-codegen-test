package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.common.util.{CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults}
import org.sireum.hamr.codegen.test.util.TestUtil
import org.sireum.message.Reporter
import org.sireum.test.TestSuite
import Ros2Tests._
import org.sireum.hamr.codegen.CodeGen
import org.sireum.hamr.codegen.common.containers.IResource

class Ros2Tests extends TestSuite with Ros2TestUtil {

  val generateExpected: B = F

  val verbose: B = F

  val root = Os.path(implicitly[sourcecode.File].value).up.up.up.up.up.up.up.up
  val resourceDir: Os.Path = root / "resources"
  val expectedRoot: Os.Path = resourceDir / "expected" / "ros2"
  val resultsRoot: Os.Path = root / "results" / "ros2"

  val codegen_base = resourceDir / "models" / "CodeGenTest_Base"

  "building_control_gen_mixed" in {
    val testName = "building_control_gen_mixed"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions, verbose)
  }

  "isolette" in {
    val testName = "isolette"
    val root = codegen_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions, verbose)
  }

  "pca-pump" in {
    val testName = "pca-pump"
    val root = codegen_base / testName
    val airFile = getAir(root / "pca")
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions, verbose)
  }

  def testRos(testName: String, airFile: Os.Path, modelDir: Os.Path, config: CodeGenConfig, verbose: B): Unit = {
    val reporter = Reporter.create

    val filter: Os.Path => B = _ => T

    copy(testName, filter)

    var failureReasons: ISZ[String] = ISZ()

    val model = TestUtil.getModel(airFile = Some(airFile), phantomOptions = None(), rootAadlDir = modelDir, testModes = ISZ(), testName = testName, verbose = verbose)

    var testOps = config(
      workspaceRootDir = if (config.workspaceRootDir.nonEmpty) config.workspaceRootDir else Some(modelDir.canon.value)
    )

    val results: CodeGenResults = CodeGen.codeGen(
      model = model, options = testOps, plugins = MSZ(), reporter = reporter,
      transpilerCallback = (_, _) => 0,
      proyekIveCallback = _ => 0,
      sergenCallback = (_, _) => 0,
      slangCheckCallback = (_, _) => 0)

    failureReasons = failureReasons ++ (for (e <- reporter.errors) yield e.text)

    val destDir = getResultsDir(testName)
    destDir.removeAll()
    println(s"Result Dir: ${destDir.up.toUri}")

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

    if (generateExpected) {
      assert (!isCI, "generateExpected should be F when code is pushed to github")

      val expectedDir = this.expectedRoot / testName
      expectedDir.removeAll()
      getResultsDir(testName).copyOverTo(expectedDir)
      println(s"Replaced: ${expectedDir}")
    } else {
      if (!compare(testName, filter)) {
        failureReasons = failureReasons :+ "Results did not match expected"
      }
    }

    assert (failureReasons.size == 0)
  }
}


object Ros2Tests {
  val baseOptions = CodeGenConfig(
    writeOutResources = T,
    ipc = CodeGenIpcMechanism.SharedMemory,

    runtimeMonitoring = F,
    verbose = F,
    platform = CodeGenPlatform.Ros2,
    slangOutputDir = None(),
    packageName = None(),
    noProyekIve = T,
    noEmbedArt = F,
    devicesAsThreads = T,
    genSbtMill = T,
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = F,
    camkesOutputDir = None(),
    camkesAuxCodeDirs = ISZ(),
    workspaceRootDir = None(),
    experimentalOptions = ISZ()
  )

  def getAir(path: Os.Path): Os.Path = {
    val p = path / ".slang"
    val ps = Os.Path.walk(path = p, includeDir = F, followLink = F, p => p.ext.native == "json")
    assert (ps.size == 1, ps.size)
    return ps(0)
  }
}