package org.sireum.hamr.codegen.test


import org.sireum._
import org.sireum.test.TestSuite
import org.sireum.hamr.codegen.{CodeGen, CodeGenConfig, CodeGenIpcMechanism, CodeGenPlatform}
import org.sireum.hamr.ir._
import org.sireum.message._
import CodeGenTest._
import org.sireum.hamr.codegen.test.util.TestResult

class CodeGenTest extends TestSuite {

  val generateExpected = F
  val delResultDirIfEqual = F

  val tests = Tests {

    { // UAV_ALT tests
      val name = "uav_alt"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      
      test(s"$name--jvm", modelDir, model, baseOptions)

      test(s"$name--macos", modelDir, model, 
        baseOptions(platform = CodeGenPlatform.MacOS))

      test(s"$name--sel4_tb", modelDir, model,
        baseOptions(platform = CodeGenPlatform.SeL4_TB))
    }
    
    { // UAV_ALT_DOMAINS
      val name = "uav_alt_domains"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"

      test(s"$name--sel4_tb", modelDir, model,
        baseOptions(platform = CodeGenPlatform.SeL4_TB))

      test(s"$name--sel4_only", modelDir, model,
        baseOptions(platform = CodeGenPlatform.SeL4_Only))
    }
    
    { // UAV extern
      val name = "uav_alt_extern"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"

      test(s"$name--sel4", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4,
          camkesAuxCodeDirs = ISZ((modelDir / "aux_code").value)
        ))
    }

    {
      val name = "testdpmon"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "testdpmon_top_impl_Instance.json"

      test(s"$name--sel4_Tb", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_TB)
      )

      test(s"$name--sel4_Only", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_Only)
      )
    }

    {
      val name = "testepmon"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "testepmon_top_impl_Instance.json"

      test(s"$name--sel4_Tb", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_TB)
      )

      test(s"$name--sel4_Only", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_Only)
      )
    }

    {
      val name = "testevent"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "testevent_top_impl_Instance.json"

      test(s"$name--sel4_Tb", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_TB)
      )
    }

    {
      val name = "testshare"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "testshare_top_impl_Instance.json"

      test(s"$name--sel4_Tb", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_TB)
      )
    }

    {
      val name = "testsubprogram"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "testsubprogram_top_impl_Instance.json"

      test(s"$name--sel4_Tb", modelDir, model,
        baseOptions(
          platform = CodeGenPlatform.SeL4_TB)
      )
    }
  }

  /*
  val models: scala.collection.Map[String, String] = {
    val r = RC.text(Vector("models")) { (p, f) => p.last.endsWith(".json") }
    r.map(e => (org.sireum.String(e._1.mkString("/")), org.sireum.String(e._2)))
  }
 */

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig)(implicit position: org.scalactic.source.Position) : Unit = {
    registerTest(s"${testName} L${position.lineNumber}" )(testAir(testName, modelDir, airFile, ops))
  }

  def testAir(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig): Unit = {

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
    
    val results = CodeGen.codeGen(model.get, _ops, reporter, (TranspilerConfig) => { println(s"Dummy transpiler"); 0 })

    if(reporter.hasError) {
      reporter.printMessages()
      assert(F)
    }

    val resultMap = util.TestResult(Map.empty ++ (results.resources.map(m => (m.path, util.Resource(m.content.render)))))
    val expected = expectedDir / s"${testName}.${CodeGenTest.outputFormat}"

    val expectedMap: util.TestResult = if(generateExpected) {
      CodeGenTest.writeExpected(resultMap, expected)
      println(s"Wrote: ${expected}")
      resultMap
    }
    else if(expected.exists){
      CodeGenTest.readExpected(expected)
    }
    else {
      throw new RuntimeException(s"Expected does not exist: ${expected}")
    }

    var testFail = F
    
    if(resultMap.map.size != expectedMap.map.size) {
      val ekeys = expectedMap.map.keySet
      val rkeys = resultMap.map.keySet

      val missingEkeys = (ekeys.union(rkeys) -- ekeys.elements).elements
      val missingRkeys = (ekeys.union(rkeys) -- rkeys.elements).elements
      
      if (missingEkeys.nonEmpty) {
        for(k <- missingEkeys) {
          println(s"Expected missing entry ${k}")
          println(resultMap.map.get(k).get)
        }
      } else {
        for(k <- missingRkeys) {
          println(s"Expected missing entry ${k}")
          println(resultMap.map.get(k))
        }
      }
      testFail = T
    }

    var allEqual = T
    
    val rdir = resultDir / testName
    rdir.removeAll()
    rdir.mkdirAll()

    // could limit emitted files to only non-matching results
    for(r <- resultMap.map.entries) {
      Os.path(s"${rdir.value}/actual/${r._1}").writeOver(r._2.content)
      
      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= r._2 == e

        Os.path(s"${rdir.value}/expected/${r._1}").writeOver(e.content)
      }
    }

    val camkesTestDir = Os.path("/home/sireum/devel/sel4/home/tests")
    for(r <- resultMap.map.entries) {
      Os.path(s"${camkesTestDir.value}/${r._1}").writeOver(r._2.content)
    }
    
    if(allEqual && delResultDirIfEqual) rdir.removeAll()

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

  val outputFormat = "json" 
    
  val rootDir = Os.path("./hamr/codegen/jvm/src/test")
  val resultDir = rootDir / "results"
  val testDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test"
  val modelsDir = rootDir / "scala" / "org" / "sireum" / "hamr" / "codegen" / "test" / "models"
  val expectedDir = testDir / "expected"

  resultDir.mkdirAll()

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
}
