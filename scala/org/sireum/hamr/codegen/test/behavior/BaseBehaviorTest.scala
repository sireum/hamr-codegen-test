package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import TestUtil._

class BaseBehaviorTest extends CodegenBehaviorTest{

  val modelsDir = TestUtil.getRootDirectory(getClass) / "resources" / "models"

  val tests = Tests {

//    { // static approach
//      {
//        val modelDir = modelsDir / "CodeGenTest_Base" / "building_control_gen_mixed"
//        val description = ""
//
//        test(
//          testName = modelDir.name,
//          testDescription = description,
//          testOptions = baseOptions(
//            slangOutputDir = Some((modelDir / "hamr" / "slang").value),
//            aadlRootDir = Some(modelDir.value),
//            verbose = verbose
//          ),
//          // include test modes from super (e.g. maybe from env var)
//          testModes = testModes :+ TestMode.generated_unit_tests
//        )
//      }
//    }

    { // Temp_control_simple_temp
      {
        val modelDir = modelsDir / "CodeGenTest_Base" / "temp_control_simple_temp"
        val description = "Temp Control model with temp data structure with 1 field"

        test(
          testName = modelDir.name,
          testDescription = description,
          testOptions = baseOptions(
            slangOutputDir = Some((modelDir / "hamr" / "slang").value),
            aadlRootDir = Some((modelDir / "aadl").value),
            verbose = verbose
          ),
          // include test modes from super (e.g. maybe from env var)
          testModes = testModes :+ TestMode.generated_unit_tests
        )
      }
    }

//    { // dynamic approach
//      var testRoots: ISZ[Os.Path] = locateHamrTestFiles(modelsDir)
//
//      for (hamrTestFile <- testRoots) {
//        genTestFromFile(hamrTestFile)
//      }
//    }
  }
}
