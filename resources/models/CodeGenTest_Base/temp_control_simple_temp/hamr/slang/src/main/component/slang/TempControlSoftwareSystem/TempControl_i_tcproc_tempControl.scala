// #Sireum

package slang.TempControlSoftwareSystem

import org.sireum._
import slang._

// This file will not be overwritten so is safe to edit
object TempControl_i_tcproc_tempControl {

  // BEGIN STATE VARS
  var currentSetPoint: TempControlSoftwareSystem.SetPoint_i = TempControlSoftwareSystem.SetPoint_i.example()

  var currentTemp: TempSensor.Temperature_i = TempSensor.Temperature_i.example()

  var latestTemp: TempSensor.Temperature_i = TempSensor.Temperature_i.example()
  // END STATE VARS

  def initialise(api: TempControl_i_Initialization_Api): Unit = {
    Contract(
      Modifies(
        // BEGIN INITIALIZES MODIFIES
        currentSetPoint,
        latestTemp
        // END INITIALIZES MODIFIES
      ),
      Ensures(
        // BEGIN INITIALIZES ENSURES
        // guarantee "defautSetPoint"
        currentSetPoint.low.degrees == 70.0f && currentSetPoint.high.degrees == 80.0f,
        // guarantee "defaultLatestTemp"
        latestTemp.degrees == 75.0f
        // END INITIALIZES ENSURES
      )
    )
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_fanCmd(CoolingFan.FanCmd.byOrdinal(0).get)
  }

  def handle_fanAck(api: TempControl_i_Operational_Api, value : CoolingFan.FanAck.Type): Unit = {
    api.logInfo("example handle_fanAck implementation")
    api.logInfo(s"received ${value}")
    // example api usage

    val apiUsage_currentTemp: Option[TempSensor.Temperature_i] = api.get_currentTemp()
    api.logInfo(s"Received on currentTemp: ${apiUsage_currentTemp}")
    val apiUsage_fanAck: Option[CoolingFan.FanAck.Type] = api.get_fanAck()
    api.logInfo(s"Received on fanAck: ${apiUsage_fanAck}")
    val apiUsage_setPoint: Option[TempControlSoftwareSystem.SetPoint_i] = api.get_setPoint()
    api.logInfo(s"Received on setPoint: ${apiUsage_setPoint}")
    val apiUsage_tempChanged: Option[art.Empty] = api.get_tempChanged()
    api.logInfo(s"Received on tempChanged: ${apiUsage_tempChanged}")
  }

  def handle_setPoint(api: TempControl_i_Operational_Api, value : TempControlSoftwareSystem.SetPoint_i): Unit = {
    api.logInfo("example handle_setPoint implementation")
    api.logInfo(s"received ${value}")
  }

  def handle_tempChanged(api: TempControl_i_Operational_Api): Unit = {
    api.logInfo("example handle_tempChanged implementation")
    api.logInfo("received tempChanged event")
  }

  def activate(api: TempControl_i_Operational_Api): Unit = { }

  def deactivate(api: TempControl_i_Operational_Api): Unit = { }

  def finalise(api: TempControl_i_Operational_Api): Unit = { }

  def recover(api: TempControl_i_Operational_Api): Unit = { }
}
