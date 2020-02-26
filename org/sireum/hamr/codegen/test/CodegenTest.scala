package org.sireum.hamr.codegen.test

import org.sireum._
import org.sireum.test.TestSuite
import org.sireum.hamr.codegen.{CodeGen, CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform, CodeGenResults}
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
    var _ops = ops(
      slangOutputDir = if(ops.slangOutputDir.nonEmpty) ops.slangOutputDir else Some(testName)
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
    
    val results: CodeGenResults = CodeGen.codeGen(model.get, _ops, reporter, (TranspilerConfig) => { println(s"Dummy transpiler"); 0 })

    if(reporter.hasError) {
      reporter.printMessages()
      assert(F)
    }

    val resultMap = util.TestResult(Map.empty ++ (results.resources.map(m => (m.path, util.Resource(m.content.render)))))
    val expected = expectedDir / s"${testName}.${CodeGenTest.outputFormat}"

    var testFail = F
    val expectedMap: util.TestResult = if(generateExpected) {
      CodeGenTest.writeExpected(resultMap, expected)
      println(s"Wrote: ${expected}")
      resultMap
    }
    else if(expected.exists) {
      CodeGenTest.readExpected(expected)
    }
    else {
      testFail = T
      Console.err.println(s"Expected does not exist: ${expected}")      
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
    
    val rdir = if(resultDir.nonEmpty) rootResultDir / resultDir.get / testName else rootResultDir / testName 
    rdir.removeAll()
    rdir.mkdirAll()

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {
      val output = Os.path(s"${rdir.value}/results/${r._1}")
      output.canon.writeOver(r._2.content)
      
      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= r._2 == e
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
      Os.path(s"${rdir.value}/expected/${e._1}").canon.writeOver(e._2.content)      
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
    
    if(allEqual && delResultDirIfEqual) rdir.removeAll()

    if(modelUri.nonEmpty) {
      println(s"Model URI: ${modelUri.get}")
    }

    if(description.nonEmpty) {
      println(st"""Test Description: ${description.get}
                  |----------------""".render)
    }
    
    assert(allEqual, s"Mismatches in ${rdir.canon.toUri}")
    
    assert(!testFail, s"test fail in ${rdir.canon.toUri}")
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
  
  val expectedDir = testDir / "expected"

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
