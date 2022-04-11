package org.sireum.hamr.codegen.test.expensive

import org.sireum._
import org.sireum.$internal.RC
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.TestMode

class HamrTranspileTests extends CodeGenTest {

  override def generateExpected: B = if (super.generateExpected) T else F

  val (linux, sel4, sel4_tb, sel4_only) = (CodeGenPlatform.Linux, CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

  val transpiler_dir = baseModelsDir / getClass.getSimpleName
  val resultDir: Option[String] = Some(getClass.getSimpleName)

  def gen(name: String, dir: Os.Path, json: String, platforms: ISZ[CodeGenPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
    val modelDir = dir / name
    val testName = name.native.replaceAll("/", "__")
    return (testName, modelDir, modelDir / ".slang" / json, platforms)
  }

  val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type])] = ISZ(
    gen("building_control_gen_mixed", transpiler_dir, "BuildingControl_BuildingControlDemo_i_Instance.json", ISZ(linux)),

    gen("attestation-gate", transpiler_dir, "SysContext_top_Impl_Instance.json", ISZ(sel4)),
  )

  for (proj <- tests) {
    for (platform <- proj._4) {
      // append classname so it doesn't use the expected results from the 'normal' tests
      test(
        testName = s"${getClass.getSimpleName}_${proj._1}--${platform}",
        modelDir = proj._2,
        airFile = Some(proj._3),
        ops = baseOptions(
          platform = platform,
          runTranspiler = T),
        resultDir = resultDir,
        description = None(),
        modelUri = None(),
        expectedErrorReasons = ISZ())
    }
  }

  def testResources(): TestResources = {
    // scala/java 'resources' directories don't play nicely with mill so instead embed the contents
    // of 'expected' and 'models' into the test class via the RC macros .  These can then
    // be retrieved as a map from 'exploded path' to 'contents' via a call to 'testResources()'

    val files = RC.base64(Vector("../../../../../../")) { (p, f) =>
      val cname = "HamrTranspileTests"
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
    return TestResources(files)
  }
}
