package org.sireum.hamr.codegen.test.normal

import org.scalatest.BeforeAndAfterAll
import org.sireum.$internal.RC
import org.sireum.{B, F, ISZ, None, Option, Os, Some, String, T, ops}
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.baseOptions
import org.sireum.hamr.codegen.test.util.TestMode

class GumboTest extends CodeGenTest with BeforeAndAfterAll {
  val resultDir: Option[String] = Some(getClass.getSimpleName)
  val modelsDir = baseModelsDir / getClass.getSimpleName

  override def generateExpected: B = F

  override def testModes: ISZ[TestMode.Type] = {
    return super.testModes :+ TestMode.logika
  }

  override def afterAll(): Unit = {
    val rdir = rootResultDir / resultDir.get
    assert(rdir.exists, rdir.value)
    val t = Os.home / "temp" / "gtest"
    rdir.copyOverTo(t)
  }

  val tests = Tests {
    {
      val name = "data-invariants"
      val modelDir = modelsDir / name
      val model = Some(getJson(modelDir))

      var platform: CodeGenPlatform.Type = CodeGenPlatform.JVM
      test(s"$name--${platform}", modelDir, model,
        baseOptions(platform = platform),
        resultDir, None(), None(), ISZ())
    }

  }

  def getJson(d: Os.Path) : Os.Path = {
    val s = d / ".slang"
    val cands = s.list.filter(f => f.name.native.endsWith("json"))
    assert(cands.size == 1, s"${cands} : ${s.value}")
    return cands(0)
  }

  def testResources(): scala.collection.Map[scala.Vector[Predef.String], Predef.String] = {
    // scala/java 'resources' directories don't play nicely with mill so instead embed the contents
    // of 'expected' and 'models' into the test class via the RC macros .  These can then
    // be retrieved as a map from 'exploded path' to 'contents' via a call to 'testResources()'

    RC.base64(Vector("../../../../../../")) { (p, f) =>
      val cname = "gumbo"
      val allowedDirs: ISZ[Predef.String] = ISZ(s"expected/${cname}", s"models/${cname}")

      val dirAllowed: B = {
        var matched: B = F
        for(allowedDir <- allowedDirs if !matched) {
          val split: Array[Predef.String] = allowedDir.split("/")
          var index: Int = 0
          while(index < split.length && index < p.length && split(index) == p(index)) { index = index + 1 }
          matched = index == split.length
        }
        matched
      }

      // exclude unneeded files by their extension
      val excludedResources: ISZ[org.sireum.String] =
        ISZ("aadlbin", "aaxl2", "png", "pdf", "md", "dot", "aadl_diagram", "reqspec",
          "alisa", "org", "cat", "verify", "methodregistry", "gitignore", "goals", "xassure")

      val filename = Os.path(p.last)

      val allow = dirAllowed &&
        !ops.ISZOps(excludedResources).contains(filename.ext) &&
        ((p.size > 1 && p(p.size - 2) != ".slang") || filename.ext.native != "json") // exclude json files in the .slang directories

      if(allow) {
        //println(s"allowed: ${p} - ${f.length()}")
        //println(f.length())
      } else {
        //println(s"NOT allowed: ${p} - ${f.length()}")
      }

      allow
    }
  }
}
