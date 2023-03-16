package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.TestUtil

class BaseBehaviorTestDynamic extends CodegenBehaviorTest {

  // set base directory for AADL models to be used in behavior tests
  val modelsDirs = TestUtil.getRootDirectory(getClass) / "resources" / "models"

  val testDir = modelsDirs / "BaseBehaviorTest"


  val tests = Tests {
    val testRoots: ISZ[Os.Path] = locateHamrTestFiles(testDir)

    for (hamrTestFile <- testRoots) {
      genTestFromFile(hamrTestFile)
    }
  }
}
