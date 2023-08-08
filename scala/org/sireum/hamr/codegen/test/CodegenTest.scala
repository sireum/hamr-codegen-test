package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.arsit.plugin.ArsitPlugin
import org.sireum.hamr.codegen._
import org.sireum.hamr.codegen.common.containers.{SireumProyekIveOption, SireumSlangTranspilersCOption, SireumToolsSergenOption, SireumToolsSlangcheckGeneratorOption}
import org.sireum.hamr.codegen.common.util._
import org.sireum.hamr.codegen.common.util.test.{ETestResource, ITestResource, TestResult, TestUtil => CommonTestUtil}
import org.sireum.hamr.codegen.test.util.TestModeHelper.getEnvTestModes
import org.sireum.hamr.codegen.test.util.{CodegenTestSuite, TestMode, TestUtil}
import org.sireum.hamr.ir._
import org.sireum.message._
import org.sireum.ops.ISZOps
import org.sireum.test.TestSuite

/** Can regenerate AIR JSON files via 
* https://github.com/sireum/osate-plugin/blob/d0015531e9d2039f7f186c4fa7a124521ee664b6/org.sireum.aadl.osate.tests/src/org/sireum/aadl/osate/tests/extras/AirUpdater.java#L46-L54
*/
trait CodeGenTest extends CodegenTestSuite {

  import CodeGenTest._

  def generateExpected: B = F

  assert (generateExpected.->:(!TestUtil.isCI), s"generateExpected must be false when pushed to github")

  def ignoreBuildDefChanges: B = F // temporarily ignore build.sbt and build.sc changes due to build.properties updates

  // e.g. from command line:
  //   testmodes=generated_unit_test,compile,camkes sireum proyek test ...
  def testModes: ISZ[TestMode.Type] = getEnvTestModes() ++
    ISZ(TestMode.codegen)
  //ISZ(TestMode.codegen, TestMode.smt2)

  def filter: B = if (filterTestsSet().nonEmpty) filterTestsSet().get else F

  def filters: ISZ[String] = ISZ("isolette")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4", // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

  def smt2Timeout: Z = Os.env("SMT2_TIMEOUT") match {
    case Some(t) => Z(t).get
    case _ => 2 * 60000
  }

  def logikaOptions: Option[String] = {
    return Some(s"--timeout ${smt2Timeout}")
  }

  def verbose: B = {
    return ops.ISZOps(testModes).contains(TestMode.verbose)
  }

  def testResources: TestResources

  def test(testName: String,
           modelDir: Os.Path,
           airFile: Option[Os.Path],
           ops: CodeGenConfig,
           description: Option[String],
           modelUri: Option[String],
           expectedErrorReasons: ISZ[String] // empty if errors not expected
          )(implicit position: org.scalactic.source.Position): Unit = {
    testPhantom(testName, modelDir, airFile, None(), ops, description, modelUri, expectedErrorReasons)(position)
  }

  def testPhantom(testName: String,
                  modelDir: Os.Path,
                  airFile: Option[Os.Path],
                  phantomOptions: Option[String],
                  ops: CodeGenConfig,
                  description: Option[String],
                  modelUri: Option[String],
                  expectedErrorReasons: ISZ[String] // empty if errors not expected
                 )(implicit position: org.scalactic.source.Position): Unit = {
    var tags: ISZ[org.scalatest.Tag] = ISZ()

    if (ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, modelDir, airFile, phantomOptions, ops, description, modelUri, expectedErrorReasons))
    }
    else if (!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, modelDir, airFile, phantomOptions, ops, description, modelUri, expectedErrorReasons))
    }
  }

  def testAir(testName: String,
              modelDir: Os.Path,
              airFile: Option[Os.Path],
              phantomOptions: Option[String],
              config: CodeGenConfig,
              description: Option[String],
              modelUri: Option[String],
              expectedErrorReasons: ISZ[String] // empty if errors not expected
             ): Unit = {

    val rootResultDir = testResources.resultsDir
    val rootExpectedDir = testResources.expectedDir

    val expectedJson = rootExpectedDir / s"${testName}.json"

    val rootTestOutputDir = rootResultDir / testName
    val expectedDir = rootTestOutputDir / "expected"
    val resultsDir = rootTestOutputDir / "results"

    assert(config.slangOutputDir.isEmpty, s"hmm, why custom output dir ${config.slangOutputDir}")
    assert(config.slangOutputCDir.isEmpty, s"hmm, why custom c dir ${config.slangOutputCDir}")
    assert(config.camkesOutputDir.isEmpty, s"hmm, why custom camkes dir ${config.camkesOutputDir}")

    var testOps = config(
      aadlRootDir = if (config.aadlRootDir.nonEmpty) config.aadlRootDir else Some(modelDir.canon.value),
      packageName = if (config.packageName.nonEmpty) config.packageName else Some(testName)
    )

    if (verbose) {
      println(s"Test Modes: ${testModes}")
      testOps = testOps(verbose = T)
    }

    if (TestUtil.isSlang(testOps.platform)) {
      testOps = testOps(slangOutputDir = Some((resultsDir / "slang").canon.value))
    }

    if (TestUtil.isLinux(testOps.platform)) {
      testOps = testOps(slangOutputCDir = Some((resultsDir / "c").canon.value))
    }

    if (TestUtil.isSeL4(testOps.platform)) {
      testOps = testOps(camkesOutputDir = Some((resultsDir / "camkes").canon.value))
    }

    rootTestOutputDir.removeAll()
    rootTestOutputDir.mkdirAll()

    val reporter = Reporter.create

    val model: Aadl = TestUtil.getModel(airFile, phantomOptions, Os.path(testOps.aadlRootDir.get), testModes, testName, verbose)

    println(s"Result Dir: ${rootTestOutputDir.canon.toUri}")

    // note transpiler will be run via the callback method and via the Slash scripts.
    // proyek ive will only be run via callback
    val results: CodeGenResults = CodeGen.codeGen(model, testOps, ArsitPlugin.gumboEnhancedPlugins, reporter,
      if (TestUtil.shouldTranspile(testOps, testModes)) TestUtil.transpile(testOps) _ else (SireumSlangTranspilersCOption, Reporter) => {
        println("Dummy transpiler");
        0
      },
      if (TestUtil.shouldProyekIve(testOps, testModes)) TestUtil.proyekive(testOps) _ else (SireumProyekIveOption) => {
        println("Dummy Proyek IVE");
        0
      },
      if (TestUtil.shouldSergen(testOps, testModes)) TestUtil.sergen(testOps) _ else (SireumToolsSergenOption, Reporter) => {
        0
      }
      ,
      if (TestUtil.shouldSlangCheck(testOps, testModes)) TestUtil.slangcheck(testOps) _ else (SireumToolsSlangcheckGeneratorOption, Reporter) => {
        0
      }
    )

    if (expectedErrorReasons.isEmpty) {
      assert(!reporter.hasError, "Expecting no errors but codegen did not complete successfully")
    }
    else {
      assert(reporter.hasError, "Expecting errors but codegen completed successfully")
      assert(reporter.errors.size == expectedErrorReasons.size)

      for (m <- reporter.errors) {
        assert(org.sireum.ops.ISZOps(expectedErrorReasons).contains(m.text), s"Expected errors doesn't contain ${m.text}")
      }

      return
    }

    var testSuccess = T
    if (!reporter.hasError) {
      testSuccess &= TestUtil.runAdditionalTasks(testName, testOps, testModes, logikaOptions, verbose, this, reporter)
    }

    val resultMap = CommonTestUtil.convertToTestResult(results.resources, resultsDir)

    val expectedMap: TestResult = if (generateExpected) {
      CommonTestUtil.writeExpected(resultMap, expectedJson)
      println(s"Wrote: ${expectedJson}")
      resultMap
    }
    else if (expectedJson.exists) {
      CommonTestUtil.readExpected(expectedJson)
    }
    else {
      testSuccess = F
      Console.err.println(s"Expected does not exist: ${expectedJson}")
      TestResult(Map.empty)
    }

    if (resultMap.map.size != expectedMap.map.size) {
      val ekeys = expectedMap.map.keySet
      val rkeys = resultMap.map.keySet

      val missingEkeys = (ekeys.union(rkeys) -- ekeys.elements).elements
      val missingRkeys = (ekeys.union(rkeys) -- rkeys.elements).elements

      if (missingEkeys.nonEmpty) {
        for (k <- missingEkeys) {
          println(s"Expected missing entry ${k}")
          //println(s"  - ${resultMap.map.get(k).get}")
        }
      } else {
        for (k <- missingRkeys) {
          println(s"Results missing entry ${k}")
          //println(s"  - ${expectedMap.map.get(k)}")
        }
        //rkeys.elements.foreach(f => println(f))
      }
      testSuccess &= F
    }

    var allEqual = T

    // could limit emitted files to only non-matching results
    for (r <- resultMap.map.entries) {

      if (expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= {
          val ignores = ISZOps(ISZ("build.sbt", "build.sc", "versions.properties", "project.cmd"))
          val ignoreFile = ignoreBuildDefChanges && ignores.exists(p => r._1.native.endsWith(p))
          val sameContents = r._2 == e
          if (!sameContents) {
            var reason: ISZ[String] = ISZ()
            ((r._2, e)) match {
              case ((ri: ITestResource, ei: ITestResource)) =>
                if (ri.content != ei.content) reason = reason :+ "content is not the same"
                if (ri.overwrite != ei.overwrite) reason = reason :+ "overwrite flag is not the same"
                if (ri.makeExecutable != ei.makeExecutable) reason = reason :+ "makeExecutable flag is not the same"
                if (ri.makeCRLF != ei.makeCRLF) reason = reason :+ "makeCRLF flag is not the same"
                if (ri.markers != ei.markers) reason = reason :+ "markers is not the same"
              case ((re: ETestResource, ee: ETestResource)) =>
                if (re.content != ee.content) reason = reason :+ "content is not the same"
                if (re.symlink != ee.symlink) reason = reason :+ "symLink flag is not the same"

              case _ => halt("Infeasible: TestResource types not the same")
            }
            eprintln(st"${r._1} ${(reason, ", ")}".render)
          }
          ignoreFile || sameContents
        }
      } else if (!generateExpected) {
        allEqual = F
        eprintln(s"Expected missing: ${r._1}")
      }

      /*
      if(r._1.native.endsWith("graph.dot")) {
        val dot = r._2.content
        val dotOutput = Os.path(s"${output.value}.pdf")

        val proc:ISZ[String] = ISZ("dot", "-Tpdf", output.canon.value, "-o", dotOutput.canon.value)
        println(proc)
        Os.proc(proc).run()
      }
      */
    }

    for (e <- expectedMap.map.entries) {
      (expectedDir / e._1).canon.writeOver(e._2.content)
    }

    if (modelUri.nonEmpty) {
      println(s"Model URI: ${modelUri.get}")
    }

    if (description.nonEmpty) {
      println(
        st"""Test Description: ${description.get}
            |----------------""".render)
    }

    assert(allEqual, s"Mismatches in ${rootTestOutputDir.canon.toUri}")

    assert(testSuccess, s"test fail in ${rootTestOutputDir.canon.toUri}")
  }
}

object CodeGenTest {

  case class TestResources(resultsDir: Os.Path,
                           expectedDir: Os.Path,
                           modelsDir: Os.Path)

  val CAMKES_DIR = "CAMKES_DIR"
  val CAMKES_VM_EXAMPLES_DIR = "CAMKES_VM_EXAMPLES_DIR"

  val FILTER = "FILTER"

  val baseOptions = CodeGenConfig(
    writeOutResources = T,
    ipc = CodeGenIpcMechanism.SharedMemory,

    verbose = F,
    platform = CodeGenPlatform.JVM,
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
    aadlRootDir = None(),
    experimentalOptions = ISZ(ExperimentalOptions.GENERATE_REFINEMENT_PROOF)
  )

  def filterTestsSet(): Option[B] = {
    return if (Os.env(FILTER).nonEmpty) return Some(Os.env(FILTER).get.native.toBoolean) else None()
  }

  /*
   * - resources/
   *   - expected/
   *     - clsName/
   *   - models/
   *     - clsName/
   * - scala/
   *     <contains cls>
   */
  def defaultTestLayout(cls: Class[_]): TestResources = {
    def search(p: Os.Path): Option[(Os.Path, Os.Path)] = {
      assert(p.isDir, p)
      for (pp <- p.list) {
        if (pp.isFile && pp.name.native == s"${cls.getSimpleName}.scala") {
          val _package = ops.StringOps(cls.getPackage.getName).split((c: C) => c == C('.'))
          var dir = pp.up
          var ok = T
          var i = _package.size - 1
          while (ok && i >= 0) { // ensure we're in the right package
            ok = _package(i) == dir.name
            i = i - 1
            dir = dir.up
          }
          if (ok) {
            return Some((dir, pp))
          }
        }
        if (pp.isDir) {
          search(pp) match {
            case Some((a, b)) => return Some((a, b))
            case _ =>
          }
        }
      }
      return None()
    }

    search(Os.path(".").canon) match {
      case Some((scalaDir, p)) =>

        assert(scalaDir.name.native == "scala", s"Expecting ${cls.getName} to be in a 'scala' directory")

        val resourcesDir = scalaDir.up / "resources"
        assert(resourcesDir.exists && resourcesDir.isDir, s"Expected to find resources directory: ${resourcesDir}")

        val expectedDir = resourcesDir / "expected" / cls.getSimpleName
        //assert(expectedDir.exists && expectedDir.isDir, s"Expecting to find ${expectedDir}")

        val modelsDir = resourcesDir / "models" / cls.getSimpleName
        assert(modelsDir.exists && modelsDir.isDir, s"Expected to find model directory: ${modelsDir}")

        return TestResources(
          resultsDir = resourcesDir.up / "results" / cls.getSimpleName,
          expectedDir = expectedDir,
          modelsDir = modelsDir)
      case _ =>
        halt(s"Couldn't find resources for ${cls.getSimpleName}")
    }
  }
}
