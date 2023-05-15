package org.sireum.hamr.codegen.test.expensive

import org.sireum._
import org.sireum.hamr.codegen.common.util.{CodeGenPlatform, ExperimentalOptions}
import org.sireum.hamr.codegen.test.CodeGenTest
import org.sireum.hamr.codegen.test.CodeGenTest.{TestResources, baseOptions}

class HamrTranspileTests extends CodeGenTest {

  override def generateExpected: B = if (super.generateExpected) T else F

  val testResources: TestResources = CodeGenTest.defaultTestLayout(getClass())

  val (linux, sel4, sel4_tb, sel4_only) = (CodeGenPlatform.Linux, CodeGenPlatform.SeL4, CodeGenPlatform.SeL4_TB, CodeGenPlatform.SeL4_Only)

  def gen(name: String, dir: Os.Path, json: String, platforms: ISZ[CodeGenPlatform.Type]): (String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type]) = {
    val modelDir = dir / name
    val testName = name.native.replaceAll("/", "__")
    return (testName, modelDir, modelDir / ".slang" / json, platforms)
  }

  val tests: ISZ[(String, Os.Path, Os.Path, ISZ[CodeGenPlatform.Type])] = ISZ(
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

        // kekinian also runs these tests so disable slang check until it's included
        // in kekinian's dist
        ops = ops(experimentalOptions = ops.experimentalOptions :+ ExperimentalOptions.DISABLE_SLANG_CHECK),

        description = None(),
        modelUri = None(),
        expectedErrorReasons = ISZ())
    }
  }
}
