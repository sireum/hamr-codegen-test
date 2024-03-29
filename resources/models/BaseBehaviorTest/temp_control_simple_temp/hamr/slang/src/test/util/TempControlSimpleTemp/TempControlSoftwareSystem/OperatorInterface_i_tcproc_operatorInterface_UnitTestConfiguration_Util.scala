// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

import org.sireum._
import TempControlSimpleTemp.GumboXUtil.GumboXResult
import TempControlSimpleTemp.util.{Container, Profile, UnitTestConfigurationBatch}
import TempControlSimpleTemp.RandomLib
import org.sireum.Random.Impl.Xoshiro256

object OperatorInterface_i_tcproc_operatorInterface_UnitTestConfiguration_Util {

  def freshRandomLib: RandomLib = {
    return RandomLib(Random.Gen64Impl(Xoshiro256.create))
  }

  def defaultInitializeConfig: OperatorInterface_i_tcproc_operatorInterface_Initialize_UnitTestConfiguration = {
    return (OperatorInterface_i_tcproc_operatorInterface_Initialize_UnitTestConfiguration (
      verbose = F,
      name = "Default_Initialize_Config",
      description = "Default Initialize Configuration",
      numTests = 100,
      numTestVectorGenRetries = 100,
      failOnUnsatPreconditions = F,
      profile = OperatorInterface_i_tcproc_operatorInterface_Profile (
        name = "Initialize_Default_Profile", // needed for old framework
        numTests = 100, // needed for old framework
      ),
      genReplay = (c: Container, r: GumboXResult.Type) => None())
    )
  }

  def defaultComputeConfig: OperatorInterface_i_tcproc_operatorInterface_Compute_UnitTestConfiguration = {
    return (OperatorInterface_i_tcproc_operatorInterface_Compute_UnitTestConfiguration (
      verbose = F,
      name = "Default_Compute_Config",
      description = "Default Compute Configuration",
      numTests = 100,
      numTestVectorGenRetries = 100,
      failOnUnsatPreconditions = F,
      profile = OperatorInterface_i_tcproc_operatorInterface_Profile_P (
        name = "Compute_Default_Profile", // needed for old framework
        numTests = 100, // needed for old framework
        numTestVectorGenRetries = 100, // needed for old framework,
        api_tempChanged = freshRandomLib,
        api_currentTemp = freshRandomLib
      ),
      genReplay = (c: Container, r: GumboXResult.Type) => Some(
        st"""val testVector = TempControlSimpleTemp.JSON.toTempControlSoftwareSystemOperatorInterface_i_tcproc_operatorInterface_PreState_Container_P(json).left
            |assert (testComputeCBV(testVector) == results)""".render))
    )
  }
}

@record class OperatorInterface_i_tcproc_operatorInterface_Initialize_UnitTestConfiguration (
  var verbose: B,
  var name: String,
  var description: String,
  var numTests: Z,
  var numTestVectorGenRetries: Z,
  var failOnUnsatPreconditions: B,
  var profile: OperatorInterface_i_tcproc_operatorInterface_Profile,
  var genReplay: (Container, GumboXResult.Type) => Option[String])
  extends UnitTestConfigurationBatch with OperatorInterface_i_tcproc_operatorInterface_GumboX_TestHarness {

  override def test(c: Container): GumboXResult.Type = {
    return testInitialiseCB()
  }
}

@record class OperatorInterface_i_tcproc_operatorInterface_Compute_UnitTestConfiguration (
  var verbose: B,
  var name: String,
  var description: String,
  var numTests: Z,
  var numTestVectorGenRetries: Z,
  var failOnUnsatPreconditions: B,
  var profile: OperatorInterface_i_tcproc_operatorInterface_Profile_P,
  var genReplay: (Container, GumboXResult.Type) => Option[String])
  extends UnitTestConfigurationBatch with OperatorInterface_i_tcproc_operatorInterface_GumboX_TestHarness {

  override def test(c: Container): GumboXResult.Type = {
    return testComputeCBV(c.asInstanceOf[OperatorInterface_i_tcproc_operatorInterface_PreState_Container_P])
  }
}
