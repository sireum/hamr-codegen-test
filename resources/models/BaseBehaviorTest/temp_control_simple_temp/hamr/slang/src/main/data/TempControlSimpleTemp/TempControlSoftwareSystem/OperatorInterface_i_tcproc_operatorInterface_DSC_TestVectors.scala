// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

// Test vector containers for Distributed SlangCheck testing

@datatype class OperatorInterface_i_tcproc_operatorInterface_DSC_TestVector (
  val api_tempChanged: Option[art.Empty],
  val api_currentTemp: TempSensor.Temperature_i)
