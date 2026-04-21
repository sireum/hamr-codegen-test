package org.sireum.hamr.codegen.test.ros2

import org.sireum._
import org.sireum.hamr.codegen.test.util.TestMode
import org.sireum.test.TestSuite
import Ros2Tests._

class MicroRosTests extends TestSuite with Ros2TestUtil {

  override val generateExpected: B = F || super.generateExpected

  val verbose: B = F

  override def testModes: ISZ[TestMode.Type] =
    super.testModes // :+ TestMode.compile

  val root: Os.Path = Os.path(implicitly[sourcecode.File].value).up.up.up.up.up.up.up.up
  val resourceDir: Os.Path = root / "resources"
  val expectedRoot: Os.Path = resourceDir / "expected" / "ros2"
  val resultsRoot: Os.Path = root / "results" / "ros2"

  val ros_base: Os.Path = resourceDir / "models" / "Ros2"

  "sysml_temp_control_mixed_microros_lax" in {
    val testName = "sysml-temp-control-mixed-microros"
    val root = ros_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = false, invertTopicBinding = false), T, verbose)
  }

  "sysml_temp_control_mixed_microros_strict" in {
    val testName = "sysml-temp-control-mixed-microros"
    val root = ros_base / testName
    val airFile = getAir(root)
    assert (root.exists)

    testRos(testName, airFile, airFile.up, baseOptions.apply(strictAadlMode = true, invertTopicBinding = false), T, verbose)
  }
}
