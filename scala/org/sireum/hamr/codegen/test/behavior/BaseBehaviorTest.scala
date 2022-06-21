package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}
import TestUtil._

class BaseBehaviorTest extends CodegenBehaviorTest {

  val modelsDir = TestUtil.getRootDirectory(getClass) / "resources" / "models"


  "temp_control_simple_temp" in {
    val modelDir = modelsDir / getClass.getSimpleName / "temp_control_simple_temp"
    val description = "Temp Control model with temp data structure with 1 field"
    val packageName: Option[org.sireum.String] = Some("TempControlSimpleTemp")

    // there are multiple system implementations in this project so need to
    // help phantom out if it's used (e.g. CI reg testing)
    val phantomOps: ISZ[String] = ISZ(
      "--main-package", "./packages/TempControlSoftwareSystem.aadl",
      "--sys-impl", "TempControlSoftwareSystem.i",
      "--projects", ".")

    testAir(
      testName = modelDir.name,
      testDescription = description,
      testOptions = baseOptions(
        slangOutputDir = Some((modelDir / "hamr" / "slang").value),
        aadlRootDir = Some((modelDir / "aadl").value),
        packageName = packageName,
        verbose = verbose
      ),
      phantomOptions = Some(st"${(phantomOps, " ")}".render),
      logikaOptions = logikaOptions,
      // include test modes from super (e.g. maybe from env var)
      testModes = testModes :+ TestMode.generated_unit_tests
    )
  }

  val tests = Tests {

    { // static approach
      {
        val modelDir = modelsDir / getClass.getSimpleName / "building_control_gen_mixed"
        val description = ""

        test(
          testName = modelDir.name,
          testDescription = description,
          testOptions = baseOptions(
            packageName = Some("bc"),
            slangOutputDir = Some((modelDir / "hamr" / "slang").value),
            aadlRootDir = Some(modelDir.value),
            verbose = verbose
          ),
          phantomOptions = None(),
          logikaOptions = logikaOptions,
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
