package org.sireum.hamr.codegen.test.gumbo

import org.scalatest.BeforeAndAfterAll
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.{B, F, ISZ, None, Os, Some, T, ops}

class GumboTest extends CodeGenTest with BeforeAndAfterAll {

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  override def generateExpected: B = super.generateExpected || F

  val phantomReady: B = T

  val superModes: ISZ[TestMode.Type] = {
    if (!phantomReady && ops.ISZOps(super.testModes).contains(TestMode.phantom)) {
      println(s"\n\n\nRemoving ${TestMode.phantom} test mode from ${this.getClass.getSimpleName}\n\n\n")
      super.testModes - TestMode.phantom
    }
    else {
      super.testModes
    }
  }

  println(s"""\nRemoving ${TestMode.generated_unit_tests} test mode from ${this.getClass.getSimpleName}
             |as testComputeCB may try to fetch from outgoing data ports that are not populated
             |via the example behavior code that Codegen generates for compute entrypoints.\n""".stripMargin)

  override def testModes: ISZ[TestMode.Type] = {
    return (superModes :+ TestMode.sergen :+ TestMode.slangcheck :+ TestMode.logika) - TestMode.generated_unit_tests
  }

  override def afterAll(): Unit = {
    /*
    val rdir = rootResultDir / resultDir.get
    assert(rdir.exists, rdir.value)
    val t = Os.home / "temp" / "gtest"
    rdir.copyOverTo(t)
    */
  }

  "data-invariants" in {
    val name = "data-invariants"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "integration-contracts" in {
    val name = "integration-contracts"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "enum-test" in {
    val name = "enum-test"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "initialize-entrypoint" in {
    val name = "initialize-entrypoint"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "compute-entrypoint" in {
    val name = "compute-entrypoint"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "isolette" in {
    val name = "isolette"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }

  "rts" in {
    val name = "RTS-aadl"
    val modelDir = testResources.modelsDir / name
    val model = Some(getJson(modelDir))

    var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
    testAir(s"$name--${platform}", modelDir, model, None(),
      baseOptions(platform = platform),
      None(), None(), ISZ())
  }


  def getJson(d: Os.Path): Os.Path = {
    val cands = Os.Path.walk(d, T, F, p => p.isFile && p.up.name.native == ".slang" && p.ext.native == "json")
    assert(cands.size == 1, s": Inspect json files in ${d.toUri}: $cands")
    return cands(0)
  }
}
