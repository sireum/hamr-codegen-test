// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Test vector containers for Distributed SlangCheck testing

@datatype class OperatorInterface_s_tcproc_operatorInterface_DSC_TestVector (
  val api_tempChanged: Option[art.Empty],
  val api_currentTemp: TempSensor.Temperature_i)