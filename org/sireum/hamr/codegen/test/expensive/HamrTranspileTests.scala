package org.sireum.hamr.codegen.test.expensive

import org.sireum._
import org.sireum.hamr.codegen.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.baseOptions
import org.sireum.hamr.codegen.test.util.TestMode

class HamrTranspileTests extends CodeGenTest {

  override def testMode: TestMode.Type = TestMode.Transpile

  override def generateExpected: B = if (super.generateExpected) T else F

  val (linux, sel4, sel4_tb, sel4_only) = (CodeGenPlatform.Linux, CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

  val base_dir = baseModelsDir / "CodeGenTest_Base"
  val case_dir = baseModelsDir / "CodegenTest_CASE"
  val resultDir: Option[String] = Some(getClass.getSimpleName)

  def gen(name: String, dir: Os.Path, json: String, platforms: ISZ[CodeGenPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
    val modelDir = dir / name
    val testName = name.native.replaceAll("/", "__")
    return (testName, modelDir, modelDir / ".slang" / json, platforms)
  }

  val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type])] = ISZ(
    gen("building_control_gen_mixed", base_dir, "BuildingControl_BuildingControlDemo_i_Instance.json", ISZ(linux)),

    gen("attestation-gate", case_dir, "SysContext_top_Impl_Instance.json", ISZ(sel4)),
  )

  for (proj <- tests) {
    for (platform <- proj._4) {
      // append classname so it doesn't use the expected results from the 'normal' tests
      test(s"${getClass.getSimpleName}_${proj._1}--${platform}", proj._2, proj._3,
        baseOptions(platform = platform, verbose = F), resultDir, None(), None())
    }
  }
}
