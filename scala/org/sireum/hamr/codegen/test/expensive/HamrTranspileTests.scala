package org.sireum.hamr.codegen.test.expensive

import org.scalatest.BeforeAndAfterAll
import org.sireum._
import org.sireum.hamr.codegen.common.util.HamrCli.CodegenHamrPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}

class HamrTranspileTests extends CodeGenTest with BeforeAndAfterAll {

  override def generateExpected: B = super.generateExpected || F

  val isKekinianCi: B = {
    Os.env("GITHUB_REPOSITORY") match {
      case Some(r) if r == string"sireum/kekinian" =>
        val buildcmd = TestUtil.getCodegenDir / "bin" / "build.cmd"
        val results = proc"$buildcmd install-sbt-mill".at(TestUtil.getCodegenDir).run()
        if (!results.ok) {
          println(results.err)
          assert(F, s"${getClass.getName} attempt to install sbt and mill failed: ${results.exitCode}")
        }
        T
      case _ => F
    }
  }

  override def testModes: ISZ[TestMode.Type] = {
    (super.testModes :+ TestMode.sergen :+ TestMode.slangcheck) ++ (
      // if we're kekinian and on github then also compile proyek projects via sbt and mill
      // so that regressions introduced by changes to sireum's dependencies, e.g. Java,
      // are caught when they are pushed
      if (isKekinianCi) ISZ(TestMode.compile)
      else ISZ())
  }

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  val (linux, sel4, sel4_tb, sel4_only) = (CodegenHamrPlatform.Linux, CodegenHamrPlatform.SeL4, CodegenHamrPlatform.SeL4_TB, CodegenHamrPlatform.SeL4_Only)

  def gen(name: String, dir: Os.Path, json: String, platforms: ISZ[CodegenHamrPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodegenHamrPlatform.Type]) = {
    val modelDir = dir / name
    val testName = name.native.replaceAll("/", "__")
    return (testName, modelDir, modelDir / ".slang" / json, platforms)
  }

  val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodegenHamrPlatform.Type])] = ISZ(
    gen("building_control_gen_mixed", testResources.modelsDir, "BuildingControl_BuildingControlDemo_i_Instance.json", ISZ(linux)),

    gen("attestation-gate", testResources.modelsDir, "SysContext_top_Impl_Instance.json", ISZ(sel4)),
  )

  for (proj <- tests) {
    for (platform <- proj._4) {
      // append classname so it doesn't use the expected results from the 'normal' tests
      val testName = s"${getClass.getSimpleName}_${proj._1}--${platform}"
      val ops = baseOptions(
        platform = platform,
        runTranspiler = T)
      test(
        testName = testName,
        modelDir = proj._2,
        airFile = Some(proj._3),
        ops = ops,
        description = None(),
        modelUri = None(),
        expectedErrorReasons = ISZ())
    }
  }

  override def afterAll(): Unit = {
    if (Os.isWin && isKekinianCi) {
      val binDir = TestUtil.getCodegenDir / "bin" / "win"
      val resultsDir = TestUtil.getCodegenDir / "jvm" / "src" / "test" / "results"
      if (binDir.exists) {
        binDir.removeAll()
        println(s"Removed ${binDir}")
      }
      if (resultsDir.exists) {
        resultsDir.removeAll()
        println(s"Removed $resultsDir")
      }
    }
  }
}
