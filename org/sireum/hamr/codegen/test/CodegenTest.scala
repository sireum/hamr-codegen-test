package org.sireum.hamr.codegen.test

import org.sireum.$internal.RC
import org.sireum._
import org.sireum.hamr.act.templates.{CakeMLTemplate, SlangEmbeddedTemplate}
import org.sireum.hamr.act.utils.CMakeOption
import org.sireum.hamr.act.vm.VM_Template
import org.sireum.hamr.codegen._
import org.sireum.hamr.codegen.common.containers.TranspilerConfig
import org.sireum.hamr.codegen.common.util.test.{TestJSON, TestMsgPack, TestResource, TestResult, TestUtil}
import org.sireum.hamr.codegen.test.util.TestModes
import org.sireum.hamr.ir._
import org.sireum.message._
import org.sireum.test.TestSuite

/** Can regenerate AIR JSON files via 
* https://github.com/sireum/osate-plugin/blob/d0015531e9d2039f7f186c4fa7a124521ee664b6/org.sireum.aadl.osate.tests/src/org/sireum/aadl/osate/tests/extras/AirUpdater.java#L46-L54
*/
trait CodeGenTest extends TestSuite {

  import CodeGenTest._

  def generateExpected: B = F
  def delResultDirIfEqual: B = F

  def testMode: TestModes.Type = TestModes.Base
  //def testMode: TestModes.Type = TestModes.Base_TranspileNix_Camkes

  def ignoreBuildSbtChanges: B = F // temporarily ignore build.sbt changes due to build.properties updates

  def filter: B = if(filterTestsSet().nonEmpty) filterTestsSet().get else F
  def filters: ISZ[String] = ISZ("test_event_data_port_fan_out")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4" // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

  def timeout: Z = 10000

  val (expectedJsonDir, baseModelsDir) = getDirectories()

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig)(implicit position: org.scalactic.source.Position) : Unit = {
    test(testName, modelDir, airFile, ops, None(), None(), None())
  }

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig,
           resultDir:Option[String],
           description: Option[String], modelUri: Option[String])(implicit position: org.scalactic.source.Position) : Unit = {
    var tags: ISZ[org.scalatest.Tag] = ISZ()

    if(ignores.elements.exists(elem => org.sireum.ops.StringOps(testName).startsWith(elem))){
      registerIgnoredTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri))
    }
    else if(!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).startsWith(elem))) {
      registerTest(s"${testName} L${position.lineNumber}", tags.elements:_*)(
        testAir(testName, modelDir, airFile, ops, resultDir, description, modelUri))
    }
  }

  def testAir(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig,
              resultDir: Option[String],
              description: Option[String], modelUri: Option[String],
              ): Unit = {

    val expectedJson = expectedJsonDir / s"${testName}.json"

    val rootTestOutputDir = if(resultDir.nonEmpty) rootResultDir / resultDir.get / testName else rootResultDir / testName
    val expectedDir = rootTestOutputDir / "expected"
    val resultsDir = rootTestOutputDir / "results"
    val slangOutputDir = resultsDir / testName

    var testOps = ops(
      slangOutputDir = if(ops.slangOutputDir.nonEmpty) ops.slangOutputDir else Some(slangOutputDir.canon.value),
      writeOutResources = T
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
      if(shouldTranspile(testOps.platform)) transpile _ else (TranspilerConfig) => { println("Dummy transpiler"); 0 })

    if(reporter.hasError) {
      reporter.printMessages()
      assert(F)
    }

    if(runCamkesNinja(testOps.platform)) {
      val hasVMs: B = testName.native.toLowerCase().contains("vm")

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

          camkesArgs = camkesArgs ++ onOptions(CakeMLTemplate.CAKEML_OPTIONS)

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
      }
    }

    val resultMap = TestResult(Map.empty ++ (results.resources.map(m => {
      val key = resultsDir.relativize(Os.path(m.path)).value
      (key, TestResource(m.content.render, m.overwrite, m.makeExecutable))
    })))

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
          val ignoreFile = ignoreBuildSbtChanges && r._1.native.endsWith("build.sbt")
          val sameContents = r._2 == e
          if(!sameContents) {
            eprintln(s"${r._1} is not the same (NOTE comparing ${e.getClass.getSimpleName} objects)")
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
      case TestModes.Base_Camkes => T
      case TestModes.Base_TranspileNix_Camkes => T
      case _ => F
    }
    return isCamkes && isSeL4(platform)
  }

  def shouldTranspile(platform: CodeGenPlatform.Type): B = {
    val shouldRun: B = (testMode, platform) match {
      case (TestModes.Base, _) => F

      case (TestModes.Base_TranspileNix, CodeGenPlatform.Linux) |
           (TestModes.Base_TranspileNix, CodeGenPlatform.MacOS) |
           (TestModes.Base_TranspileNix, CodeGenPlatform.Cygwin) => T

      case (TestModes.Base_Camkes, CodeGenPlatform.SeL4) => T

      case (TestModes.Base_TranspileNix_Camkes, _) => T

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
    writeOutResources = F,
    ipc = CodeGenIpcMechanism.SharedMemory,

    verbose = T,
    platform = CodeGenPlatform.JVM,
    slangOutputDir = None(),
    packageName = None(),
    embedArt = T,
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
        eprintln(s"${CodeGenTest.CAMKES_DIR} not set !!!!")
        val candidate = Os.home / "CASE/camkes"
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
        eprintln(s"${CodeGenTest.CAMKES_ARM_VM_DIR} not set!!!")
        val candidate = Os.home / "CASE/camkes-arm-vm"
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

    args = args :+ "--sourcepath" :+ st"""${(tc.sourcepath, ":")}""".render
    tc.output.map(s => add("--output-dir", s))
    tc.projectName.map(s => add("--name", s))
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
    if (tc.exts.nonEmpty) add("--exts", st"""${(tc.exts, ":")}""".render)
    if (tc.libOnly) addKey("--lib-only")
    if (tc.verbose) addKey("--verbose")
    if (tc.cmakeIncludes.nonEmpty) add("--cmake-includes", st"""${(tc.cmakeIncludes, ",")}""".render)

    //args.foreach(p => println(p))

    val sireum = Os.path(Os.env("PWD").get) / "bin" / "sireum"

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    val results = Os.proc(args).console.run()

    results.exitCode
  }

  def getDirectories(): (Os.Path, Os.Path) = {
    val intellijTestDir = Os.path("./hamr/codegen/jvm/src/test/scala")
    val rootResultsDir: Os.Path = if(intellijTestDir.exists) {
      // use local/intellij copy
      intellijTestDir
    } else {
      // probably running from jar so copy resources to a temp directory
      val temp: Os.Path = Os.tempDir()
      for (entry <- testResources()) {
        assert(entry._1.head == "expected" || entry._1.head == "models")
        val f = temp / entry._1.mkString("/")
        f.writeOver(entry._2)
      }
      temp
    }
    return (rootResultsDir / "expected", rootResultsDir / "models")
  }

  def testResources(): scala.collection.Map[scala.Vector[Predef.String], Predef.String] = {
    // scala/java 'resources' directories don't play nicely with mill so instead add the contents
    // of 'expected' and 'models' into the binary via RC.text.  These can then
    // be retrieved as a map from 'exploded path' to 'contents' via a call to 'testResources()'
    RC.text(Vector("../../../../../")) { (p, f) =>
      val allowedDirs: ISZ[String] = ISZ("expected", "models")

      // exclude unneeded/binary files
      val excludedResources: ISZ[String] = ISZ("png", "pdf", "md", "dot", "aadl", "aadl_diagram")

      val filename = Os.path(p.last)

      val allow = ops.ISZOps(allowedDirs).contains(p.head) &&
        !ops.ISZOps(excludedResources).contains(filename.ext)

      if(allow) {
        //println(p)
      }

      allow
    }
  }
}
