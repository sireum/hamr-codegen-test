package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.hamr.act.templates.{CakeMLTemplate, SlangEmbeddedTemplate}
import org.sireum.hamr.act.util.CMakeOption
import org.sireum.hamr.act.vm.VM_Template
import org.sireum.hamr.codegen._
import org.sireum.hamr.codegen.common.containers.TranspilerConfig
import org.sireum.hamr.codegen.common.util.{CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults}
import org.sireum.hamr.codegen.common.util.test.{TestResult, TestUtil}
import org.sireum.hamr.codegen.test.util.TestMode
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

  def testMode: TestMode.Type = Os.env("HamrTestMode") match {
    case Some(t) => TestMode.byName(t).get
    case _ => TestMode.Codegen
  }

  def testResources(): scala.collection.Map[scala.Vector[Predef.String], Predef.String]

  def filter: B = if(filterTestsSet().nonEmpty) filterTestsSet().get else F
  def filters: ISZ[String] = ISZ("test_event_data_port_periodic_domains--SeL4")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4", // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

  def timeout: Z = 10000

  val (expectedJsonDir, baseModelsDir) = getDirectories(testResources())

  //def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig)(implicit position: org.scalactic.source.Position) : Unit = {
  //  test(testName, modelDir, airFile, ops, T)
  //}

  //def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig, shouldPass: B)(implicit position: org.scalactic.source.Position) : Unit = {
  //  test(testName, modelDir, airFile, ops, None(), None(), None(), shouldPass)
  //}

  def test(testName: String,
           modelDir: Os.Path,
           airFile: Os.Path,
           ops: CodeGenConfig,
           resultDir:Option[String],
           description: Option[String],
           modelUri: Option[String],
           expectedErrorReasons: ISZ[String] // empty if errors not expected
          )(implicit position: org.scalactic.source.Position) : Unit = {
    var tags: ISZ[org.scalatest.Tag] = ISZ()

    if(ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))){
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri, expectedErrorReasons))
    }
    else if(!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).contains(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri, expectedErrorReasons))
    }
  }

  def testAir(testName: String,
              modelDir: Os.Path,
              airFile: Os.Path,
              ops: CodeGenConfig,
              resultDir: Option[String],
              description: Option[String],
              modelUri: Option[String],
              expectedErrorReasons: ISZ[String] // empty if errors not expected
              ): Unit = {

    val expectedJson = expectedJsonDir / getClass.getSimpleName / s"${testName}.json"

    val rootTestOutputDir = if(resultDir.nonEmpty) rootResultDir / resultDir.get / testName else rootResultDir / testName
    val expectedDir = rootTestOutputDir / "expected"
    val resultsDir = rootTestOutputDir / "results"
    val slangOutputDir = resultsDir / testName

    var testOps = ops(
      slangOutputDir = if(ops.slangOutputDir.nonEmpty) ops.slangOutputDir else Some(slangOutputDir.canon.value),
    )

    if(isSeL4(testOps.platform)) {
      testOps = testOps(
        slangOutputDir = Some(s"${testOps.slangOutputDir.get}/slang-embedded"),

        camkesOutputDir = if(testOps.camkesOutputDir.nonEmpty) testOps.camkesOutputDir  else testOps.slangOutputDir,
        aadlRootDir = if(testOps.aadlRootDir.nonEmpty) testOps.aadlRootDir else Some(modelDir.canon.value),
      )
    }

    rootTestOutputDir.removeAll()
    rootTestOutputDir.mkdirAll()

    val reporter = Reporter.create

    val model = getModel(airFile.read)

    println(s"Result Dir: ${rootTestOutputDir.canon.toUri}")

    val results: CodeGenResults = CodeGen.codeGen(model.get, testOps, reporter,
      if(shouldTranspile(testOps.platform)) transpile _ else (TranspilerConfig) => { println("Dummy transpiler"); 0 },
      (ProyekIveConfig) => { println("Dummy Proyek IVE"); 0 }
    )

    if(expectedErrorReasons.isEmpty) {
      assert(!reporter.hasError, "Expecting no errors but codegen did not complete successfully")
    }
    else {
      assert(reporter.hasError, "Expecting errors but codegen completed successfully")
      assert(reporter.errors.size == expectedErrorReasons.size)

      for(m <- reporter.errors) {
        assert(org.sireum.ops.ISZOps(expectedErrorReasons).contains(m.text), s"Expected errors doesn't contain ${m.text}")
      }

      return
    }

    if(shouldCompile(testOps.platform) && !reporter.hasError) {
      println("Compiling JVM")
      val sireum: Os.Path = Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")
      val slangDir = Os.path(testOps.slangOutputDir.get)

      val proyekResults = proc"${sireum.string} proyek compile --par ${slangDir.string}".at(slangDir).console.run()
      assert(proyekResults.ok, "Proyek compilation failed")

      if(shouldRunGeneratedUnitTests(testOps.platform)) {
        val proyekResults = proc"${sireum.string} proyek test --par ${slangDir.string}".at(slangDir).console.run()
        assert(proyekResults.ok, "Proyek test failed")
      }

      if(isLinux(testOps.platform)) {
        println("Compiling C")
        val compileScript = testOps.slangOutputCDir match {
          case Some(d) => Os.path(d) / "bin" / "compile.cmd"
          case _ => slangDir / "src" / "c" / "bin" / "compile.cmd"
        }
        val cCompileResults = proc"bash -c ${compileScript.string}".env(ISZ(("SIREUM_HOME", sireum.up.up.string), ("MAKE_ARGS", "-j4"))).at(compileScript.up).console.run()
        assert(cCompileResults.ok, "C Compilation failed")
      }
    }

    if(runCamkesNinja(testOps.platform) && !reporter.hasError) {
      val hasVMs: B = reporter.messages.filter(m => org.sireum.ops.StringOps(m.text)
        .contains("Execute the following to install the CAmkES-ARM-VM project:")).nonEmpty

      val rootCamkesDir: Option[Os.Path] =
        if(hasVMs) { camkesArmVMDir() }
        else { camkesDir() }

      rootCamkesDir match {
        case Some(camkesDir) => {
          val name = s"hamr_${testName}"
          val camkesAppsDir = camkesDir / s"projects/camkes/apps/${name}"
          camkesAppsDir.removeAll()
          camkesAppsDir.mklink(slangOutputDir)
          println(s"Created symlink to ${camkesAppsDir.value}")

          var camkesArgs: ISZ[String] = ISZ("../init-build.sh")

          if(testOps.platform == CodeGenPlatform.SeL4) {
            val toptions = SlangEmbeddedTemplate.TRANSPILER_OPTIONS.filter(c => c.name != string"NO_PRINT")
            camkesArgs = camkesArgs ++ onOptions(toptions)
          }

          if(hasVMs) {
            camkesArgs = camkesArgs ++ onOptions(VM_Template.VM_CMAKE_OPTIONS) ++
              ISZ("-DPLATFORM=qemu-arm-virt", "-DARM_HYP=ON")
          }

          // would only want to enable cakeml assemblies if they are built ahead of time
          // which would mean the CI would need to do that as too expensive/large to
          // check the binaries into git
          //camkesArgs = camkesArgs ++ onOptions(CakeMLTemplate.CAKEML_OPTIONS)

          camkesArgs = camkesArgs :+ s"-DCAMKES_APP=${name}"

          val camkesBuildDir = camkesDir / s"build_${name}"
          camkesBuildDir.removeAll()
          camkesBuildDir.mkdir()

          Os.proc(camkesArgs).at(camkesBuildDir).console.runCheck()

          Os.proc(ISZ("ninja")).at(camkesBuildDir).console.runCheck()

          //val results = Proc(ISZ("simulate"), Os.cwd, Map.empty, T, None(), F, F, F, F, F, timeout, F).at(camkesBuildDir).run()
          //println(results.out)
          //println(results.err)
        }
        case _ =>
          assert(F, "CAmkES directory not found")
      }
    }

    val resultMap = TestUtil.convertToTestResult(results.resources, resultsDir)

    var testFail = F
    val expectedMap: TestResult = if(generateExpected) {
      TestUtil.writeExpected(resultMap, expectedJson)
      println(s"Wrote: ${expectedJson}")
      resultMap
    }
    else if(expectedJson.exists) {
      TestUtil.readExpected(expectedJson)
    }
    else {
      testFail = T
      Console.err.println(s"Expected does not exist: ${expectedJson}")
      TestResult(Map.empty)
    }

    if(resultMap.map.size != expectedMap.map.size) {
      val ekeys = expectedMap.map.keySet
      val rkeys = resultMap.map.keySet

      val missingEkeys = (ekeys.union(rkeys) -- ekeys.elements).elements
      val missingRkeys = (ekeys.union(rkeys) -- rkeys.elements).elements

      if (missingEkeys.nonEmpty) {
        for(k <- missingEkeys) {
          println(s"Expected missing entry ${k}")
          //println(s"  - ${resultMap.map.get(k).get}")
        }
      } else {
        for(k <- missingRkeys) {
          println(s"Results missing entry ${k}")
          //println(s"  - ${expectedMap.map.get(k)}")
        }
        //rkeys.elements.foreach(f => println(f))
      }
      testFail = T
    }

    var allEqual = T

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {

      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= {
          val ignores = ISZOps(ISZ("build.sbt", "build.sc", "versions.properties", "project.cmd"))
          val ignoreFile = ignoreBuildDefChanges && ignores.exists(p => r._1.native.endsWith(p))
          val sameContents = r._2 == e
          if(!sameContents) {
            var reason: ISZ[String] = ISZ()
            if(r._2.content != e.content) reason = reason :+ "content is not the same"
            if(r._2.overwrite != e.overwrite) reason = reason :+ "overwrite flag is not the same"
            if(r._2.makeExecutable != e.makeExecutable) reason = reason :+ "makeExecutable flag is not the same"
            if(r._2.makeCRLF != e.makeCRLF) reason = reason :+ "makeCRLF flag is not the same"
            eprintln(st"${r._1} ${(reason, ", ")}".render)
          }
          ignoreFile || sameContents
        }
      } else if(!generateExpected) {
        allEqual = F
        expectedMap.map.keySet.elements.foreach(p => println(p))
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

    for(e <- expectedMap.map.entries) {
      (expectedDir / e._1).canon.writeOver(e._2.content)
    }

    if(allEqual && delResultDirIfEqual) rootTestOutputDir.removeAll()

    if(modelUri.nonEmpty) {
      println(s"Model URI: ${modelUri.get}")
    }

    if(description.nonEmpty) {
      println(st"""Test Description: ${description.get}
                  |----------------""".render)
    }

    assert(allEqual, s"Mismatches in ${rootTestOutputDir.canon.toUri}")

    assert(!testFail, s"test fail in ${rootTestOutputDir.canon.toUri}")
  }

  def getModel(s: String): Option[Aadl] = {
    return JSON.toAadl(s) match {
      case Either.Left(m) => Some(m)
      case Either.Right(m) =>
        eprintln(s"Json deserialization error at (${m.line}, ${m.column}): ${m.message}")
        None()
    }
  }

  def isLinux(platform: CodeGenPlatform.Type): Boolean = {
    return platform match {
      case CodeGenPlatform.Linux => T
      case CodeGenPlatform.MacOS => T
      case CodeGenPlatform.Cygwin => T
      case _ => F
    }
  }

  def isSeL4(platform: CodeGenPlatform.Type): Boolean = {
    return platform match {
      case CodeGenPlatform.SeL4 => T
      case CodeGenPlatform.SeL4_TB => T
      case CodeGenPlatform.SeL4_Only => T
      case _ => F
    }
  }

  def runCamkesNinja(platform: CodeGenPlatform.Type): B = {
    val isCamkes: B = testMode match {
      case TestMode.Camkes => T
      case TestMode.Camkes_TranspileNix => T
      case TestMode.All => T
      case _ => F
    }
    return isCamkes && isSeL4(platform)
  }

  def shouldCompile(platform: CodeGenPlatform.Type): B = {
    val should: B = testMode match {
      case TestMode.All =>
        platform match {
          case CodeGenPlatform.JVM |
            CodeGenPlatform.Cygwin |
            CodeGenPlatform.MacOS |
            CodeGenPlatform.Linux => T
          case _ => F
        }
      case _ => F
    }
    return should
  }

  def shouldRunGeneratedUnitTests(platform: CodeGenPlatform.Type): B = {
    return testMode == TestMode.All_plus_generated_unit_tests
  }

  def shouldTranspile(platform: CodeGenPlatform.Type): B = {
    val shouldRun: B = (testMode, platform) match {
      case (TestMode.Codegen, _) => F

      case (TestMode.Transpile, _) => T

      case (TestMode.TranspileNix, CodeGenPlatform.Linux) |
           (TestMode.TranspileNix, CodeGenPlatform.MacOS) |
           (TestMode.TranspileNix, CodeGenPlatform.Cygwin) => T

      case (TestMode.Camkes, CodeGenPlatform.SeL4) => T

      case (TestMode.Camkes_TranspileNix, _) => T

      case (TestMode.All, _) => T

      case _ => F
    }
    return shouldRun
  }

  def onOptions(options: ISZ[CMakeOption]): ISZ[String] = { return options.map(o => s"-D${o.name}=ON") }
}

object CodeGenTest {

  val CAMKES_DIR = "CAMKES_DIR"
  val CAMKES_ARM_VM_DIR = "CAMKES_ARM_VM_DIR"

  val FILTER = "FILTER"

  val rootDir = Os.path("./hamr/codegen/jvm/src/test")
  val rootResultDir: Os.Path = if(rootDir.exists) {
    rootDir / "results" // probably running inside intellij so emit results locally
  } else {
    Os.tempDir() / "results" // probably running from jar
  }

  rootResultDir.mkdirAll()

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
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 1,
    runTranspiler = T,
    camkesOutputDir = None(),
    camkesAuxCodeDirs = ISZ(),
    aadlRootDir = None(),
    experimentalOptions = ISZ()
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

  def camkesArmVMDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_ARM_VM_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_ARM_VM_DIR} environment variable not set!!!")
        val candidate = Os.home / "CASE" / "camkes-arm-vm"
        if (candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }


  def transpile(tc: TranspilerConfig): Z = {
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

    val sireum: Os.Path = Os.cwd / "bin" / (if (Os.isWin) "sireum.bat" else "sireum")

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    val results = Os.proc(args).console.run()

    return results.exitCode
  }

  def getDirectories(testResources : scala.collection.Map[scala.Vector[Predef.String], Predef.String]): (Os.Path, Os.Path) = {
    val intellijTestDir = Os.path("./hamr/codegen/jvm/src/test/scala")
    val rootResultsDir: Os.Path = if(intellijTestDir.exists) {
      // use local/intellij copy
      intellijTestDir
    } else {
      // probably running from jar so copy resources to a temp directory
      val temp: Os.Path = Os.tempDir()
      for (entry <- testResources) {
        assert(entry._1.head == "expected" || entry._1.head == "models")

        val f = temp / entry._1.mkString("/")

        f.writeOverU8s(conversions.String.fromBase64(entry._2).left)

        //println(s"Wrote: ${f}")

        if(f.up.name.native == ".slang" && f.ext.native == "zip") {
          Os.proc(ISZ("unzip", f.value, "-d", f.up.value)).run()//.runCheck()

          //println(s"Unzipped: ${f}")
        }
      }
      temp
    }
    return (rootResultsDir / "expected", rootResultsDir / "models")
  }
}
