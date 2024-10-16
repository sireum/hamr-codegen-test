// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp.util.Profile
import TempControlSimpleTemp.util.EmptyContainer
import TempControlSimpleTemp.RandomLib

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Profile for initialise entrypoint
@msig trait OperatorInterface_i_tcproc_operatorInterface_Profile_Trait extends Profile

@record class OperatorInterface_i_tcproc_operatorInterface_Profile (
  val name: String,
) extends OperatorInterface_i_tcproc_operatorInterface_Profile_Trait {

  override def next: EmptyContainer = {
    return EmptyContainer()
  }
}

// Profile with generators for incoming ports
@msig trait OperatorInterface_i_tcproc_operatorInterface_Profile_P_Trait extends Profile {
  def api_tempChanged: RandomLib // random lib for generating art.Empty
  def api_currentTemp: RandomLib // random lib for generating TempSensor.Temperature_i
}

@record class OperatorInterface_i_tcproc_operatorInterface_Profile_P(
  val name: String,
  var api_tempChanged: RandomLib, // random lib for generating art.Empty
  var api_currentTemp: RandomLib // random lib for generating TempSensor.Temperature_i
  ) extends OperatorInterface_i_tcproc_operatorInterface_Profile_P_Trait {

  override def next: OperatorInterface_i_tcproc_operatorInterface_PreState_Container_P = {
    return (OperatorInterface_i_tcproc_operatorInterface_PreState_Container_P (
      api_tempChanged = api_tempChanged.nextOption_artEmpty(),
      api_currentTemp = api_currentTemp.nextTempSensorTemperature_i()))
  }
}

// Profile with generators for state variables and incoming ports
@msig trait OperatorInterface_i_tcproc_operatorInterface_Profile_PS_Trait extends OperatorInterface_i_tcproc_operatorInterface_Profile_P_Trait {
  def api_tempChanged: RandomLib // random lib for generating art.Empty
  def api_currentTemp: RandomLib // random lib for generating TempSensor.Temperature_i
}

@record class OperatorInterface_i_tcproc_operatorInterface_Profile_PS(
  val name: String,
  var api_tempChanged: RandomLib, // random lib for generating art.Empty
  var api_currentTemp: RandomLib // random lib for generating TempSensor.Temperature_i
  ) extends OperatorInterface_i_tcproc_operatorInterface_Profile_PS_Trait {

  override def next: OperatorInterface_i_tcproc_operatorInterface_PreState_Container_PS = {
    return (OperatorInterface_i_tcproc_operatorInterface_PreState_Container_PS (
      api_tempChanged = api_tempChanged.nextOption_artEmpty(),
      api_currentTemp = api_currentTemp.nextTempSensorTemperature_i()))
  }
}
