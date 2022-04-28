// #Sireum

package slang.TempControlSoftwareSystem

import org.sireum._
import art._
import slang._

object TempControl_i_Api {
  @strictpure def currentTempRange(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -70.0f & currentTemp.degrees <= 180.0f
}

import TempControl_i_Api._

@sig trait TempControl_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId
  def fanAck_Id : Art.PortId
  def setPoint_Id : Art.PortId
  def fanCmd_Id : Art.PortId
  def tempChanged_Id : Art.PortId

  def put_fanCmd(value : CoolingFan.FanCmd.Type) : Unit = {
    Art.putValue(fanCmd_Id, CoolingFan.FanCmd_Payload(value))
  }

  def logInfo(msg: String): Unit = {
    Art.logInfo(id, msg)
  }

  def logDebug(msg: String): Unit = {
    Art.logDebug(id, msg)
  }

  def logError(msg: String): Unit = {
    Art.logError(id, msg)
  }
}

@datatype class TempControl_i_Initialization_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val fanAck_Id : Art.PortId,
  val setPoint_Id : Art.PortId,
  val fanCmd_Id : Art.PortId,
  val tempChanged_Id : Art.PortId) extends TempControl_i_Api

@datatype class TempControl_i_Operational_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val fanAck_Id : Art.PortId,
  val setPoint_Id : Art.PortId,
  val fanCmd_Id : Art.PortId,
  val tempChanged_Id : Art.PortId) extends TempControl_i_Api {

  @spec var currentTemp: TempSensor.Temperature_i = $ // Logika spec var representing port state
  @spec def currentTemp_Inv = Invariant(
    currentTempRange(currentTemp)
  )


  def get_currentTemp() : Option[TempSensor.Temperature_i] = {
    Contract(
      Ensures(currentTempRange(currentTemp),
        Res == Some(currentTemp)
      )
    )
    val value : Option[TempSensor.Temperature_i] = Art.getValue(currentTemp_Id) match {
      case Some(TempSensor.Temperature_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port currentTemp.  Expecting 'TempSensor.Temperature_i_Payload' but received ${v}")
        None[TempSensor.Temperature_i]()
      case _ => None[TempSensor.Temperature_i]()
    }
    return value
  }

  def get_fanAck() : Option[CoolingFan.FanAck.Type] = {
    val value : Option[CoolingFan.FanAck.Type] = Art.getValue(fanAck_Id) match {
      case Some(CoolingFan.FanAck_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port fanAck.  Expecting 'CoolingFan.FanAck_Payload' but received ${v}")
        None[CoolingFan.FanAck.Type]()
      case _ => None[CoolingFan.FanAck.Type]()
    }
    return value
  }

  def get_setPoint() : Option[TempControlSoftwareSystem.SetPoint_i] = {
    val value : Option[TempControlSoftwareSystem.SetPoint_i] = Art.getValue(setPoint_Id) match {
      case Some(TempControlSoftwareSystem.SetPoint_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port setPoint.  Expecting 'TempControlSoftwareSystem.SetPoint_i_Payload' but received ${v}")
        None[TempControlSoftwareSystem.SetPoint_i]()
      case _ => None[TempControlSoftwareSystem.SetPoint_i]()
    }
    return value
  }

  def get_tempChanged() : Option[art.Empty] = {
    val value : Option[art.Empty] = Art.getValue(tempChanged_Id) match {
      case Some(Empty()) => Some(Empty())
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port tempChanged.  Expecting 'Empty' but received ${v}")
        None[art.Empty]()
      case _ => None[art.Empty]()
    }
    return value
  }
}
