package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.codegen._
import org.sireum.hamr.codegen.common.containers.{ProyekIveConfig, TranspilerConfig}
import org.sireum.hamr.codegen.common.util._
import org.sireum.hamr.codegen.common.util.test.{ETestResource, ITestResource, TestResult, TestUtil => CommonTestUtil}
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import org.sireum.hamr.ir._
import org.sireum.message._
import org.sireum.ops.ISZOps
import org.sireum.test.TestSuite

/** Can regenerate AIR JSON files via 
* https://github.com/sireum/osate-plugin/blob/d0015531e9d2039f7f186c4fa7a124521ee664b6/org.sireum.aadl.osate.tests/src/org/sireum/aadl/osate/tests/extras/AirUpdater.java#L46-L54
*/
trait CodeGenTest extends TestSuite {

  import CodeGenTest._

  def generateExpected: B = F

  def delResultDirIfEqual: B = F

  def ignoreBuildDefChanges: B = F // temporarily ignore build.sbt and build.sc changes due to build.properties updates

  // e.g. from command line:
  //   HamrTestModes=generated_unit_test,compile,camkes sireum proyek test ...
  def testModes: ISZ[TestMode.Type] = Os.env("HamrTestModes") match {
    case Some(list) => ops.StringOps(list).split((c: C) => c == C(',')).map((m: String) => TestMode.byName(m).get)
    case _ => ISZ(TestMode.codegen, TestMode.transpile)
    //case _ => ISZ(TestMode.codegen, TestMode.smt2)
  }

  def smt2Timeout: Z = Os.env("SMT2_TIMEOUT") match {
    case Some(t) => Z(t).get
    case _ => 2 * 60000
  }

  def verbose: B = {
    return ops.ISZOps(testModes).contains(TestMode.verbose)
  }

  def testResources: TestResources

  def filter: B = if (filterTestsSet().nonEmpty) filterTestsSet().get else F

  def filters: ISZ[String] = ISZ("vm")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4", // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

  def test(testName: String,
           modelDir: Os.Path,
           airFile: Option[Os.Path],
           ops: CodeGenConfig,
           description: Option[String],
           modelUri: Option[String],
           expectedErrorReasons: ISZ[String] // empty if errors not expected
          )(implicit position: org.scalactic.source.Position): Unit = {
    var tags: ISZ[org.scalatest.Tag] = ISZ()

    if (ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, modelDir, airFile, ops, description, modelUri, expectedErrorReasons))
    }
    else if (!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements: _*)(
        testAir(testName, modelDir, airFile, ops, description, modelUri, expectedErrorReasons))
    }
  }

  def testAir(testName: String,
              modelDir: Os.Path,
              airFile: Option[Os.Path],
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
    val slangOutputDir = resultsDir / testName

    assert(config.slangOutputDir.isEmpty, s"hmm, why custom output dir ${config.slangOutputDir}")

    var testOps = config(
      slangOutputDir = Some(slangOutputDir.canon.value),
      aadlRootDir = if (config.aadlRootDir.nonEmpty) config.aadlRootDir else Some(modelDir.canon.value)
    )

    if(verbose) {
      println(s"Test Modes: ${testModes}")
    }

    if (TestUtil.isSeL4(testOps.platform)) {
      assert(testOps.camkesOutputDir.isEmpty, s"hmm, why custom camkes dir ${config.camkesOutputDir}")

      testOps = testOps(
        slangOutputDir = Some(s"${slangOutputDir}/slang-embedded"),
        camkesOutputDir = testOps.slangOutputDir)
    }

    rootTestOutputDir.removeAll()
    rootTestOutputDir.mkdirAll()

    val reporter = Reporter.create

    val model: Aadl = TestUtil.getModel(airFile, Os.path(testOps.aadlRootDir.get), testModes, testName, verbose)

    println(s"Result Dir: ${rootTestOutputDir.canon.toUri}")

    // note transpiler will be run via the callback method and via the Slash scripts.
    // proyek ive will only be run via callback
    val results: CodeGenResults = CodeGen.codeGen(model, testOps, reporter,
      if (TestUtil.shouldTranspile(testOps, testModes)) transpile(testOps) _ else (TranspilerConfig) => {
        println("Dummy transpiler");
        0
      },
      if (TestUtil.shouldProyekIve(testOps, testModes)) proyekive(testOps) _ else (ProyekIveConfig) => {
        println("Dummy Proyek IVE");
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
      testSuccess &= TestUtil.runAdditionalTasks(testName, slangOutputDir, testOps, testModes, smt2Timeout, verbose, reporter)
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

    if (allEqual && delResultDirIfEqual) rootTestOutputDir.removeAll()

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

  def camkesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_DIR} environment variable not set !!!!")
        val candidate = Os.home / "CASE" / "camkes"
        if (candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }

  def camkesVmExamplesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_VM_EXAMPLES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_VM_EXAMPLES_DIR} environment variable not set!!!")
        val candidate = Os.home / "CASE" / "camkes-vm-examples"
        if (candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }

  def proyekive(config: CodeGenConfig)(pc: ProyekIveConfig): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    if (pc.force) addKey("--force")
    if (pc.ultimate) addKey("--ultimate")
    if (pc.ignoreRuntime) addKey("--ignore-runtime")
    if (pc.json.nonEmpty) add("--json", pc.json.get)
    if (pc.name.nonEmpty) add("--name", pc.name.get)
    if (pc.outputDirName.nonEmpty) add("--out", pc.outputDirName.get)
    if (pc.project.nonEmpty) add("--project", pc.project.get)
    if (pc.slice.nonEmpty) add("--slice", st"""${(pc.slice, ",")}""".render)
    if (pc.symlink) addKey("--symlink")
    if (pc.versions.nonEmpty) add("--versions", st"""${(pc.versions, pathSep)}""".render)
    if (pc.cache.nonEmpty) add("--cache", pc.cache.get)
    if (pc.docs) addKey("--no-docs")
    if (pc.sources) addKey("--no-sources")
    if (pc.repositories.nonEmpty) add("--repositories", st"""${(pc.repositories, ",")}""".render)
    if (pc.args.nonEmpty) args = args ++ pc.args

    val sireum: Os.Path = CodeGenTest.getSireum()

    args = ISZ[String](sireum.value, "proyek", "ive") ++ args

    println("Generating IVE project via callback ...")
    val results = Os.proc(args).console.run()

    return results.exitCode

  }

  def transpile(config: CodeGenConfig)(tc: TranspilerConfig): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = {
      args = args :+ key
    }

    def add(key: String, value: String): Unit = {
      args = args :+ key :+ value
    }

    val pathSep: String = Os.pathSep

    args = args :+ "--sourcepath" :+ st"""${(tc.sourcepath, pathSep)}""".render
    tc.output.map(s => add("--output-dir", s))
    tc.projectName.map(s => add("--name", s))
    addKey("--strict-aliasing")
    add("--apps", st"""${(tc.apps, ",")}""".render)
    add("--fingerprint", tc.fingerprint.string)
    add("--bits", tc.bitWidth.string)
    add("--string-size", tc.maxStringSize.string)
    add("--sequence-size", tc.maxArraySize.string)
    if (tc.customArraySizes.nonEmpty) add("--sequence", st"""${(tc.customArraySizes, ";")}""".render)
    if (tc.customConstants.nonEmpty) add("--constants", st"""${(tc.customConstants, ";")}""".render)
    if (tc.forwarding.nonEmpty) add("--forward", st"""${(tc.forwarding, ",")}""".render)
    tc.stackSize.map(s => add("--stack-size", s))
    if (tc.stableTypeId) addKey("--stable-type-id")
    if (tc.exts.nonEmpty) add("--exts", st"""${(tc.exts, pathSep)}""".render)
    if (tc.libOnly) addKey("--lib-only")
    if (tc.verbose) addKey("--verbose")
    if (tc.cmakeIncludes.nonEmpty) add("--cmake-includes", st"""${(tc.cmakeIncludes, ",")}""".render)

    //args.foreach(p => println(p))

    val sireum: Os.Path = CodeGenTest.getSireum()

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    // transpiler callback method will be expensive for sel4 projects since
    // each will be done in separate JVM instances (unlike when run from
    // OSATE or via the transpile scripts) so only do it when explicitly requested
    val ret: Z = if (Os.envs.contains("ALSO_TRANSPILE_VIA_CALLBACKS")) {
      println(s"Transpiling ${config.platform} via callback ...")
      val results = Os.proc(args).console.run()
      results.exitCode
    } else {
      0
    }

    return ret
  }

  def getSireum(): Os.Path = {
    return Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")
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
