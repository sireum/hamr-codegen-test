package org.sireum.hamr.codegen.test.behavior

import org.sireum._
import org.sireum.hamr.codegen.test.CodegenBehaviorTest
import org.sireum.hamr.codegen.test.util.TestUtil

class BaseBehaviorTestDynamic extends CodegenBehaviorTest {

  override def disablePhantom: B = T // useful when changes to OSATE/AIR have not yet been pushed as plugin releases

  override def filter: B = F

  override def filters: ISZ[String] = ISZ("prod")

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