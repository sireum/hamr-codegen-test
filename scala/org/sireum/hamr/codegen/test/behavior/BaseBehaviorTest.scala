package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import TestUtil._

class BaseBehaviorTest extends CodegenBehaviorTest{

  val modelsDir = TestUtil.getRootDirectory(getClass) / "resources" / "models"

  "Separate-example" in {
    val modelDir = modelsDir / "CodeGenTest_Base" / "building_control_gen_mixed"
    val description = ""

    testAir(
      testName = modelDir.name,
      testDescription = description,
      testOptions = baseOptions(
        slangOutputDir = Some((modelDir / "hamr" / "slang").value),
        aadlRootDir = Some(modelDir.value),
        verbose = verbose
      ),
      // include test modes from super (e.g. maybe from env var)
      testModes = testModes :+ TestMode.generated_unit_tests
    )
  }

  val tests = Tests {

    { // static approach
      {
        val modelDir = modelsDir / "CodeGenTest_Base" / "building_control_gen_mixed"
        val description = ""

        test(
          testName = modelDir.name,
          testDescription = description,
          testOptions = baseOptions(
            slangOutputDir = Some((modelDir / "hamr" / "slang").value),
            aadlRootDir = Some(modelDir.value),
            verbose = verbose
          ),
          // include test modes from super (e.g. maybe from env var)
          testModes = testModes :+ TestMode.generated_unit_tests
        )
      }
    }

    { // dynamic approach
      var testRoots: ISZ[Os.Path] = locateHamrTestFiles(modelsDir)

      for (hamrTestFile <- testRoots) {
        genTestFromFile(hamrTestFile)
      }
    }
  }
}
