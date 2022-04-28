// #Sireum

package slang.TempControlSoftwareSystem

import org.sireum._
import slang._

// This file will not be overwritten so is safe to edit
object OperatorInterface_i_tcproc_operatorInterface {

  def initialise(api: OperatorInterface_i_Initialization_Api): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_setPoint(TempControlSoftwareSystem.SetPoint_i.example())
  }

  def timeTriggered(api: OperatorInterface_i_Operational_Api): Unit = {
    // example api usage

    val apiUsage_currentTemp: Option[TempSensor.Temperature_i] = api.get_currentTemp()
    api.logInfo(s"Received on currentTemp: ${apiUsage_currentTemp}")
    val apiUsage_tempChanged: Option[art.Empty] = api.get_tempChanged()
    api.logInfo(s"Received on tempChanged: ${apiUsage_tempChanged}")
  }

  def activate(api: OperatorInterface_i_Operational_Api): Unit = { }

  def deactivate(api: OperatorInterface_i_Operational_Api): Unit = { }

  def finalise(api: OperatorInterface_i_Operational_Api): Unit = { }

  def recover(api: OperatorInterface_i_Operational_Api): Unit = { }
}
