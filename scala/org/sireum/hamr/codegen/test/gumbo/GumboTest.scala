package org.sireum.hamr.codegen.test.gumbo

import org.scalatest.BeforeAndAfterAll
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.{B, F, ISZ, None, Os, Some, T, ops}

class GumboTest extends CodeGenTest with BeforeAndAfterAll {

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  override def generateExpected: B = if (super.generateExpected) T else F

  val phantomReady: B = T

  val superModes: ISZ[TestMode.Type] = {
    if (!phantomReady && ops.ISZOps(super.testModes).contains(TestMode.phantom)) {
      println(s"\n\n\nRemoving ${TestMode.phantom} test mode from ${this.getClass.getSimpleName}\n\n\n")
      super.testModes - TestMode.phantom
    }
    else { super.testModes }
  }

  override def testModes: ISZ[TestMode.Type] = {
    return superModes :+ TestMode.logika
  }

  override def afterAll(): Unit = {
    /*
    val rdir = rootResultDir / resultDir.get
    assert(rdir.exists, rdir.value)
    val t = Os.home / "temp" / "gtest"
    rdir.copyOverTo(t)
    */
  }

  val tests = Tests {
    {
      val name = "data-invariants"
      val modelDir = testResources.modelsDir / name
      val model = Some(getJson(modelDir))

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

    {
      val name = "integration-contracts"
      val modelDir = testResources.modelsDir / name
      val model = Some(getJson(modelDir))

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

    {
      val name = "initialize-entrypoint"
      val modelDir = testResources.modelsDir / name
      val model = Some(getJson(modelDir))

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        None(), None(), ISZ())
    }

  }

  def getJson(d: Os.Path): Os.Path = {
    val s = d / ".slang"
    val cands = s.list.filter(f => f.name.native.endsWith("json"))
    assert(cands.size == 1, s": Inspect json files in ${s.value}")
    return cands(0)
  }
}
