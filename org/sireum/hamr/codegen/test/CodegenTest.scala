package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.test.TestSuite
import org.sireum.hamr.codegen.{CodeGen, CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults, TranspilerConfig}
import org.sireum.hamr.ir._
import org.sireum.message._
import CodeGenTest._
import org.sireum.hamr.codegen.test.util.{TestModes, TestResult}

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
  def ignoreTranspileCmakeChanges: B = T // organization of transpiler generated CMakeLists.txt artifacts can differ

  def filter: B = if(filterTestsSet().nonEmpty) filterTestsSet().get else F
  def filters: ISZ[String] = ISZ("uav_alt_extern--SeL4")

  def ignores: ISZ[String] = ISZ(
    "uav_alt_extern--SeL4" // ignoring as has sel4 dataport with 512 elems so bigger than 4096
  )

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
    
    val expectedJson = expectedJsonDir / s"${testName}.${CodeGenTest.outputFormat}"
    
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

          val camkesArgs: ISZ[String] =
            if(hasVMs) ISZ("../init-build.sh", "-DUSE_PRECONFIGURED_ROOTFS=true", "-DPLATFORM=qemu-arm-virt", "-DARM_HYP=ON", s"-DCAMKES_APP=${name}")
            else ISZ("../init-build.sh", s"-DCAMKES_APP=${name}")

          val camkesBuildDir = camkesDir / s"build_${name}"
          camkesBuildDir.removeAll()
          camkesBuildDir.mkdir()

          Os.proc(camkesArgs).at(camkesBuildDir).console.runCheck()

          Os.proc(ISZ("ninja")).at(camkesBuildDir).console.runCheck()
        }
        case _ =>
      }
    }

    val resultMap = util.TestResult(Map.empty ++ (results.resources.map(m => {
      val key = resultsDir.relativize(Os.path(m.path)).value
      (key, util.Resource(m.content.render, m.overwrite, m.makeExecutable))
    })))

    var testFail = F
    val expectedMap: util.TestResult = if(generateExpected) {
      CodeGenTest.writeExpected(resultMap, expectedJson)
      println(s"Wrote: ${expectedJson}")
      resultMap
    }
    else if(expectedJson.exists) {
      CodeGenTest.readExpected(expectedJson)
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
          println(s"  - ${resultMap.map.get(k).get}")
        }
      } else {
        for(k <- missingRkeys) {
          println(s"Results missing entry ${k}")
          println(s"  - ${expectedMap.map.get(k)}")
        }
        rkeys.elements.foreach(f => println(f))
      }
      testFail = T
    }

    var allEqual = T

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {

      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= {
          var ignoreFile = ignoreBuildSbtChanges && r._1.native.endsWith("build.sbt")
          ignoreFile |= ignoreTranspileCmakeChanges && r._1.native.endsWith("CMakeLists.txt") && r._2.content.native.contains("HAMR_LIB_")
          ignoreFile || r._2 == e
        }
      } else if(!generateExpected) {
        allEqual = F
        expectedMap.map.keySet.elements.foreach(p => println(p))
        println(s"Expected missing: ${r._1}")
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
}

object CodeGenTest {

  val CAMKES_DIR = "CAMKES_DIR"
  val CAMKES_ARM_VM_DIR = "CAMKES_ARM_VM_DIR"

  val FILTER = "FILTER"
  
  val outputFormat = "json" 
    
  val rootDir = Os.path("./hamr/codegen/jvm/src/test")
  val rootResultDir = rootDir / "results"
  val testDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test"
  val modelsDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test" / "models"
  
  val expectedJsonDir = testDir / "expected"

  rootResultDir.mkdirAll()

  val baseOptions = CodeGenConfig (
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
    aadlRootDir = None()
  )

  def writeExpected(resultMap: TestResult, expected: Os.Path) = {
    if(outputFormat == "json") {
      expected.writeOver(util.JSON.fromTestResult(resultMap, F))
    } 
    else if(outputFormat == "msgpack") {
      val r = util.MsgPack.fromTestResult(resultMap, T)
      expected.writeOver(org.sireum.conversions.String.toBase64(r).native)
    }
  }

  def readExpected(expected: Os.Path): TestResult = {
    if(outputFormat == "json") {
      util.JSON.toTestResult(expected.read).left
    } 
    else if(outputFormat == "msgpack") {
      val b64 = org.sireum.conversions.String.fromBase64(expected.read).left
      return util.MsgPack.toTestResult(b64).left
    }
    else {
      throw new RuntimeException("Unexpected " + outputFormat)
    }
  }
  
  def filterTestsSet(): Option[B] = {
    return if(Os.env(FILTER).nonEmpty) return Some(Os.env(FILTER).get.native.toBoolean) else None()
  }

  def camkesDir(): Option[Os.Path] = {
    return Os.env(CodeGenTest.CAMKES_DIR) match {
      case Some(x) => Some(Os.path(x))
      case _ =>
        eprintln(s"${CodeGenTest.CAMKES_DIR} not set !!!!")
        val candidate = Os.home / "CASE/camkes"
        if(candidate.exists) {
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
        eprintln(s"${CodeGenTest.CAMKES_ARM_VM_DIR} nos set!!!")
        val candidate = Os.home / "CASE/camkes-arm-vm"
        if(candidate.exists) {
          eprintln(s"Found ${candidate} so using that")
          Some(candidate)
        } else {
          None()
        }
    }
  }


  def transpile(tc: TranspilerConfig): Z = {
    var args: ISZ[String] = ISZ()

    def addKey(key: String): Unit = { args = args :+ key }
    def add(key: String, value: String): Unit = { args = args :+ key :+ value }

    args = args :+ "--sourcepath" :+ st"""${(tc.sourcepath, ":")}""".render
    tc.output.map(s => add("--output-dir", s))
    tc.projectName.map(s => add("--name", s))
    add("--apps", st"""${(tc.apps, ",")}""".render)
    add("--fingerprint", tc.fingerprint.string)
    add("--bits", tc.bitWidth.string)
    add("--string-size", tc.maxStringSize.string)
    add("--sequence-size", tc.maxArraySize.string)
    if(tc.customArraySizes.nonEmpty) add("--sequence", st"""${(tc.customArraySizes, ";")}""".render)
    if(tc.customConstants.nonEmpty) add("--constants", st"""${(tc.customConstants, ";")}""".render)
    if(tc.forwarding.nonEmpty) add("--forward", st"""${(tc.forwarding, ",")}""".render)
    tc.stackSize.map(s => add("--stack-size", s))
    if(tc.stableTypeId) addKey("--stable-type-id")
    if(tc.exts.nonEmpty) add("--exts", st"""${(tc.exts, ":")}""".render)
    if(tc.libOnly) addKey("--lib-only")
    if(tc.verbose) addKey("--verbose")
    if(tc.cmakeIncludes.nonEmpty) add("--cmake-includes", st"""${(tc.cmakeIncludes, ",")}""".render)

    //args.foreach(p => println(p))
    
    val sireum = Os.path(Os.env("PWD").get) / "bin" / "sireum"

    args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args

    val results = Os.proc(args).console.run()

    results.exitCode
  }
}
