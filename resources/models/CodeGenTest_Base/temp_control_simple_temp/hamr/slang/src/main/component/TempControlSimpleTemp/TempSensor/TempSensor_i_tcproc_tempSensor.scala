// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp._

// This file will not be overwritten so is safe to edit
object TempSensor_i_tcproc_tempSensor {

  def initialise(api: TempSensor_i_Initialization_Api): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_currentTemp(TempSensor.Temperature_i.example())
    api.put_tempChanged()
  }

  def timeTriggered(api: TempSensor_i_Operational_Api): Unit = {
    // example api usage


  }

  def activate(api: TempSensor_i_Operational_Api): Unit = { }

  def deactivate(api: TempSensor_i_Operational_Api): Unit = { }

  def finalise(api: TempSensor_i_Operational_Api): Unit = { }

  def recover(api: TempSensor_i_Operational_Api): Unit = { }
}
