// #Sireum

package tc.TempSensor

import org.sireum._
import tc._
import tc.util.Container

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// containers for the pre and post state values of ports and state variables

@sig trait TempSensor_s_tcproc_tempSensor_PreState_Container extends Container {
}

// container for incoming ports
@datatype class TempSensor_s_tcproc_tempSensor_PreState_Container_P (
  ) extends TempSensor_s_tcproc_tempSensor_PreState_Container

// container for incoming ports and state variables
@datatype class TempSensor_s_tcproc_tempSensor_PreState_Container_PS (
  ) extends TempSensor_s_tcproc_tempSensor_PreState_Container

@sig trait TempSensor_s_tcproc_tempSensor_PostState_Container extends Container {
  def api_tempChanged: Option[art.Empty]
  def api_currentTemp: TempSensor.Temperature_i
}

// container for outgoing ports
@datatype class TempSensor_s_tcproc_tempSensor_PostState_Container_P (
  val api_tempChanged: Option[art.Empty],
  val api_currentTemp: TempSensor.Temperature_i) extends TempSensor_s_tcproc_tempSensor_PostState_Container

// container for outgoing ports and state variables
@datatype class TempSensor_s_tcproc_tempSensor_PostState_Container_PS (
  val api_tempChanged: Option[art.Empty],
  val api_currentTemp: TempSensor.Temperature_i) extends TempSensor_s_tcproc_tempSensor_PostState_Container