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

  val filter: B = F
  val filters: ISZ[String] = ISZ("uav_alt_ext")
  
  val tests = Tests {

    { // UAV_ALT tests
      val name = "uav_alt"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/tool-eval-2/ACT_Demo_Dec2018_alt")
      
      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model, 
        baseOptions(platform = platform),
        None(), uri)

      platform = CodeGenPlatform.MacOS
      test(s"$name--${platform}", modelDir, model, 
        baseOptions(platform = platform),
        None(), uri)

      platform = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), uri)

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), uri)      
    }
    
    { // UAV_ALT_DOMAINS
      val name = "uav_alt_domains"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/experiments/Simple_UAV_Example_domains")
      val description: Option[String] = Some("Incomplete - need to introduce pacer component for seL4_Only profile")
      
      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        description, uri)

      platform = CodeGenPlatform.SeL4_Only
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        description, uri)
    }
    
    { // UAV extern
      val name = "uav_alt_extern"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "UAV_UAV_Impl_Instance.json"
      val uri: Option[String] = Some("https://github.com/ku-sldg/CASETeam/tree/8a96b31cf7b466ee3d558d349f21835e427d37c9/examples/ksu-proprietary/simple-uav-slang-example/uav-project-extern/src/aadl/ACT_Demo_Dec2018")
      
      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4
      test(s"$name--${platform}", modelDir, model,
        baseOptions(
          platform = platform,
          camkesAuxCodeDirs = ISZ((modelDir / "aux_code").value)
        ),
        None(), uri)
    }

    { // Data port micro example
      {
        val name = "testdpmon"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testdpmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testdpmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Data port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Data port micro-example - New Adventium translation profile: ${jimUri}"), uri
        )
      }
    }

    { // Data port micro example
      {
        val name = "testdpmon-periodic"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testdpmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testdpmon-periodic")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Data port micro-example with periodic threads - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val jimUri = "https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/experiments/Simple_UAV_Example_domains/CAmkES"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Data port micro-example with periodic threads - New Adventium translation profile: ${jimUri}"), uri
        )
      }
    }
    

    { // Event Data port micro example
      {
        val name = "testepmon"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testepmon_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testepmon")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event Data port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri ="https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-eventdata-monitor"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event Data port micro-example - Ihor aadl-eventdata-monitor profile: ${ihorUri}"), uri
        )
      }

      { // Event port micro example
        {
          val name = "testevent"
          val modelDir = modelsDir / name
          val model = modelDir / ".slang" / "testevent_top_impl_Instance.json"
          val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

          var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            Some("Event port micro-example - Trusted Build profile"), uri
          )

          platform = CodeGenPlatform.SeL4_Only
          val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
          test(s"$name--${platform}", modelDir, model,
            baseOptions(platform = platform),
            Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri
          )
        }
      }
    }

    { // Event port micro example
      {
        val name = "testevent_MultQueue"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testevent_top_impl_Instance.json"
        val uri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/d06e4def37c2ff9388f51b36c18d61fba00bce8e/TA5/unit-tests/AADL/testevent")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some("Event port micro-example - Trusted Build profile"), uri
        )

        platform = CodeGenPlatform.SeL4_Only
        val ihorUri = "https://github.com/ikuz/camkes/tree/33d68bd75a8c4903932203cc6dba5cf545a8f152/apps/aadl-event-direct"
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          Some(s"Event port micro-example - Ihor aadl-event-direct: ${ihorUri}"), uri
        )
      }
    }
  
    { // Shared Data micro example
      {
        val name = "testshare"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testshare_top_impl_Instance.json"
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testshare")

        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          None(), modelUri
        )
      }
    }

    { // Subprogram micro example
      {
        val name = "testsubprogram"
        val modelDir = modelsDir / name
        val model = modelDir / ".slang" / "testsubprogram_top_impl_Instance.json"
        val modelUri: Option[String] = Some("https://github.com/loonwerks/CASE/tree/a7782a8fb405e6502c5f176d381f50a03f915ca6/TA5/unit-tests/AADL/testsubprogram")
        
        var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
        test(s"$name--${platform}", modelDir, model,
          baseOptions(platform = platform),
          None(), modelUri
        )
      }
    }

    { // Periodic dispatch
      val name = "periodicDispatch"
      val modelDir = modelsDir / name
      val model = modelDir / ".slang" / "periodic_Critical_Impl_Instance.json"

      var platform: CodeGenPlatform.Type = CodeGenPlatform.SeL4_TB
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform)
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
    test(testName, modelDir, airFile, ops, None(), None())
  }

  def test(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig, description: Option[String], modelUri: Option[String])(implicit position: org.scalactic.source.Position) : Unit = {
    if(!filter || filters.elements.exists(elem => org.sireum.ops.StringOps(testName).startsWith(elem))) {
      registerTest(s"${testName} L${position.lineNumber}")(testAir(testName, modelDir, airFile, ops, description, modelUri))
    }
  }

  def testAir(testName: String, modelDir: Os.Path, airFile: Os.Path, ops: CodeGenConfig,
              description: Option[String], modelUri: Option[String]): Unit = {

    if(description.nonEmpty) {
      println(st"""Test Description: ${description.get}
                  |----------------""".render)
    }
    
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
          println(expectedMap.map.get(k))
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
      Os.path(s"${rdir.value}/actual/${r._1}").canon.writeOver(r._2.content)
      
      if(expectedMap.map.contains(r._1)) {
        val e = expectedMap.map.get(r._1).get
        allEqual &= r._2 == e

        Os.path(s"${rdir.value}/expected/${r._1}").canon.writeOver(e.content)
      }
    }
    
    if(isSeL4(ops)) {
      Os.env(CodeGenTest.CAMKES_APPS_DIR) match {
        case Some(x) =>
          val dir = Os.path(x)
          if (dir.exists) {
            for (r <- resultMap.map.entries) {
              Os.path(s"${dir.value}/hamr_${r._1}").writeOver(r._2.content)
            }
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
