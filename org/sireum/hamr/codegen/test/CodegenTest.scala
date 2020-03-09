package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.test.TestSuite
import org.sireum.hamr.codegen.{CodeGen, CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults, TranspilerConfig}
import org.sireum.hamr.ir._
import org.sireum.message._
import CodeGenTest._
import org.sireum.hamr.codegen.test.util.TestResult

trait CodeGenTest extends TestSuite {

  import CodeGenTest._
  
  def generateExpected: B = F
  def delResultDirIfEqual: B = F

  def filter: B = if(filterTestsSet().nonEmpty) filterTestsSet().get else F
  def filters: ISZ[String] = ISZ("testshare")
  
  /*
  val models: scala.collection.Map[String, String] = {
    val r = RC.text(Vector("models")) { (p, f) => p.last.endsWith(".json") }
    r.map(e => (org.sireum.String(e._1.mkString("/")), org.sireum.String(e._2)))
  }
 */

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig)(implicit position: org.scalactic.source.Position) : Unit = {
    test(testName, modelDir, airFile, ops, None(), None(), None())
  }

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig,
           resultDir:Option[String],        
           description: Option[String], modelUri: Option[String])(implicit position: org.scalactic.source.Position) : Unit = {
    if(!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).startsWith(elem))) {
      registerTest(s"${testName} L${position.lineNumber}")(testAir(testName, modelDir, airFile, ops, 
        resultDir, description, modelUri))
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

    var _ops = ops(
      slangOutputDir = if(ops.slangOutputDir.nonEmpty) ops.slangOutputDir else Some((resultsDir / testName).canon.value),
      writeOutResources = T
    )
    
    if(isSeL4(ops)) {
      _ops = _ops(
        slangOutputDir = Some(s"${_ops.slangOutputDir.get}/slang-embedded"),
          
        camkesOutputDir = if(_ops.camkesOutputDir.nonEmpty) _ops.camkesOutputDir  else _ops.slangOutputDir,
        aadlRootDir = if(_ops.aadlRootDir.nonEmpty) _ops.aadlRootDir else Some(modelDir.canon.value),
      )
    }

    val reporter = Reporter.create

    val model = getModel(airFile.read)

    println(s"Result Dir: ${rootTestOutputDir.canon.toUri}")
    
    val results: CodeGenResults = CodeGen.codeGen(model.get, _ops, reporter, 
      (tc: TranspilerConfig) => {
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
        add("--sequence", st"""${(tc.customArraySizes, ";")}""".render)
        add("--constants", st"""${(tc.customConstants, ";")}""".render)
        add("--forward", st"""${(tc.forwarding, ",")}""".render)
        tc.stackSize.map(s => add("--stack-size", s))
        if(tc.stableTypeId) addKey("--stable-type-id")
        add("--exts", st"""${(tc.exts, ":")}""".render)
        if(tc.verbose) addKey("--verbose")

        val sireum = Os.path(Os.env("PWD").get) / "bin" / "sireum"
        
        args = ISZ[String](sireum.value, "slang", "transpiler", "c") ++ args
        
        val results = Os.proc(args).console.run()
        
        results.exitCode 
      })


    if(reporter.hasError) {
      reporter.printMessages()
      assert(F)
    }

    val resultMap = util.TestResult(Map.empty ++ (results.resources.map(m => {
      val key = resultsDir.relativize(Os.path(m.path)).value
      (key, util.Resource(m.content.render))
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
    
    rootTestOutputDir.removeAll()
    rootTestOutputDir.mkdirAll()

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {
      val output = resultsDir / r._1
      output.canon.writeOver(r._2.content)
      
      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= r._2 == e
      } else if(!generateExpected) {
        allEqual = F
        expectedMap.map.keySet.elements.foreach(p => println(p))
        println(s"Expected missing: ${r._1}")
      }
      
      if(r._1.native.endsWith("graph.dot")) {
        val dot = r._2.content
        val dotOutput = Os.path(s"${output.value}.pdf")
        
        val proc:ISZ[String] = ISZ("dot", "-Tpdf", output.canon.value, "-o", dotOutput.canon.value)
        println(proc)
        Os.proc(proc).run()
      }
    }

    for(e <- expectedMap.map.entries) {
      (expectedDir / e._1).canon.writeOver(e._2.content)      
    }
      
    if(isSeL4(ops)) {
      camkesAppsDir() match {
        case Some(x) =>
          val dir = Os.path(x)
          if (dir.exists) {
            for (r <- resultMap.map.entries) {
              val p = Os.path(s"${dir.value}/hamr_${r._1}").canon
              p.writeOver(r._2.content)
            }
            println(s"Copied CAmkES code to ${dir.value}")
          } else {
            Console.err.println(s"${CodeGenTest.CAMKES_APPS_DIR}: ${x} does not exist")
          }
        case _ =>
      }
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

  def isSeL4(ops: CodeGenConfig): Boolean = {
    return ops.platform match {
      case CodeGenPlatform.SeL4 => T
      case CodeGenPlatform.SeL4_TB => T
      case CodeGenPlatform.SeL4_Only => T
      case _ => F
    }
  }
}

object CodeGenTest {

  val CAMKES_APPS_DIR = "CAMKES_APPS_DIR"
  val FILTER = "FILTER"
  
  val outputFormat = "json" 
    
  val rootDir = Os.path("./hamr/codegen/jvm/src/test")
  val rootResultDir = rootDir / "results"
  val testDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test"
  val modelsDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test" / "models"
  
  val expectedJsonDir = testDir / "expected"

  rootResultDir.mkdirAll()

  val baseOptions = CodeGenConfig (
    verbose = T,
    writeOutResources = F,
    platform = CodeGenPlatform.JVM,
    slangOutputDir = None(),
    packageName = None(),
    embedArt = T,
    devicesAsThreads = T,
    ipc = CodeGenIpcMechanism.SharedMemory,
    slangAuxCodeDirs = ISZ(),
    slangOutputCDir = None(),
    excludeComponentImpl = F,
    bitWidth = 64,
    maxStringSize = 256,
    maxArraySize = 16,
    camkesOutputDir = None(),
    camkesAuxCodeDirs = ISZ(),
    aadlRootDir = None()
  )

  def writeExpected(resultMap: TestResult, expected: Os.Path) = {
    if(outputFormat == "json") {
      expected.writeOver(util.JSON.fromTestResult(resultMap, T))
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
  
  def camkesAppsDir(): Option[String] = {
    return Os.env(CodeGenTest.CAMKES_APPS_DIR)
  }
}
