// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

// SlangCheck test container to hold the incoming port values for operatorInterface
@datatype class OperatorInterface_i_tcproc_operatorInterface_SlangCheckContainer (
  val api_tempChanged: Option[art.Empty],
  val api_currentTemp: TempSensor.Temperature_i)
