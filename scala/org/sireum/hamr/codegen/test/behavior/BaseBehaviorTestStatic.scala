package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.common.util.CodeGenPlatform
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.{TestMode, TestUtil}

class BaseBehaviorTestStatic extends CodegenBehaviorTest {

  // set base directory for AADL models to be used in behavior tests
  val modelsDirs = TestUtil.getRootDirectory(getClass) / "resources" / "models"

  val testDir = modelsDirs / "BaseBehaviorTest"

  "temp_control_simple_temp" in {
    // directory of model to use in this test
    val modelDir = testDir / "temp_control_simple_temp"
    // description to be used in reporting (where ??)
    val description = "Temp Control model with temp data structure with 1 field"
    // basePackageName ???  used in HAMR code generation ???
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
        workspaceRootDir = Some((modelDir / "aadl").value),
        packageName = packageName,
        verbose = verbose
      ),
      phantomOptions = Some(st"${(phantomOps, " ")}".render),
      logikaOptions = logikaOptions,
      // include test modes from super (e.g. maybe from env var)
      testModes = testModes :+ TestMode.generated_unit_tests
    )
  }

  "arrays_excludes" in {
    val modelDir = testDir / "arrays"
    val description = ""

    testAir(
      testName = s"${modelDir.name}_excludes",
      testDescription = description,
      testOptions = baseOptions(
        platform = CodeGenPlatform.Linux,
        packageName = Some("a"),
        slangOutputDir = Some((modelDir / "hamr-excludes" / "slang").value),
        slangOutputCDir = Some((modelDir / "hamr-excludes" / "c").value),
        workspaceRootDir = Some(modelDir.value),
        verbose = verbose,
        excludeComponentImpl = T,
        maxArraySize = 4
      ),
      phantomOptions = None(),
      logikaOptions = logikaOptions,
      testModes = testModes :+ TestMode.compile
    )
  }

  "arrays" in {
    val modelDir = testDir / "arrays"
    val description = ""

    testAir(
      testName = s"${modelDir.name}",
      testDescription = description,
      testOptions = baseOptions(
        platform = CodeGenPlatform.Linux,
        packageName = Some("a"),
        slangOutputDir = Some((modelDir / "hamr" / "slang").value),
        slangOutputCDir = Some((modelDir / "hamr" / "c").value),
        workspaceRootDir = Some(modelDir.value),
        verbose = verbose,
        maxArraySize = 4
      ),
      phantomOptions = None(),
      logikaOptions = logikaOptions,
      testModes = testModes :+ TestMode.compile
    )
  }

  val tests = Tests {

    { // static approach
      val modelDir = testDir / "building_control_gen_mixed"
      val description = ""

      test(
        testName = modelDir.name,
        testDescription = description,
        testOptions = baseOptions(
          packageName = Some("bc"),
          slangOutputDir = Some((modelDir / "hamr" / "slang").value),
          workspaceRootDir = Some(modelDir.value),
          verbose = verbose
        ),
        phantomOptions = None(),
        logikaOptions = logikaOptions,
        // include test modes from super (e.g. maybe from env var)
        testModes = testModes :+ TestMode.generated_unit_tests
      )
    }
  }
}
