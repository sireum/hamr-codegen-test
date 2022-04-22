// #Sireum

package bc.BuildingControl

import org.sireum._
import art._
import bc._

@sig trait TempControl_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId
  def fanAck_Id : Art.PortId
  def setPoint_Id : Art.PortId
  def fanCmd_Id : Art.PortId
  def tempChanged_Id : Art.PortId

  def put_fanCmd(value : BuildingControl.FanCmd.Type) : Unit = {
    Art.putValue(fanCmd_Id, BuildingControl.FanCmd_Payload(value))
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

  def get_currentTemp() : Option[BuildingControl.Temperature_impl] = {
    val value : Option[BuildingControl.Temperature_impl] = Art.getValue(currentTemp_Id) match {
      case Some(BuildingControl.Temperature_impl_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port currentTemp.  Expecting 'BuildingControl.Temperature_impl_Payload' but received ${v}")
        None[BuildingControl.Temperature_impl]()
      case _ => None[BuildingControl.Temperature_impl]()
    }
    return value
  }

  def get_fanAck() : Option[BuildingControl.FanAck.Type] = {
    val value : Option[BuildingControl.FanAck.Type] = Art.getValue(fanAck_Id) match {
      case Some(BuildingControl.FanAck_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port fanAck.  Expecting 'BuildingControl.FanAck_Payload' but received ${v}")
        None[BuildingControl.FanAck.Type]()
      case _ => None[BuildingControl.FanAck.Type]()
    }
    return value
  }

  def get_setPoint() : Option[BuildingControl.SetPoint_impl] = {
    val value : Option[BuildingControl.SetPoint_impl] = Art.getValue(setPoint_Id) match {
      case Some(BuildingControl.SetPoint_impl_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port setPoint.  Expecting 'BuildingControl.SetPoint_impl_Payload' but received ${v}")
        None[BuildingControl.SetPoint_impl]()
      case _ => None[BuildingControl.SetPoint_impl]()
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
