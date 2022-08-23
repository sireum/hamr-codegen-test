// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import art._
import TempControlSimpleTemp._

object TempControlPeriodic_i_Api {
  // =====================================================
  //   S p e c    H e l p e r s
  //
  //      - Port Invariant Predicates
  //
  //   Ideally, these should be held in separate files (e.g., one per component)
  //   where they can be referenced by both verification contracts and run-time monitoring.
  //   e.g., ComponentName.Specs.PIName
  // =====================================================

  // representation of port invariant constraints
  //    -- an predicate that should always hold for data flowing across a particular port

  // --- i n p u t s ---
  @strictpure def currentTemp_PAPred(x: TempSensor.Temperature_i): B =
  // AADL contract: currentTemp.degrees >= -70.0F & currentTemp.degrees <= 180.0F;
    -70.0f <= x.degrees & x.degrees <= 180.0f

  // predicate for event port has no arguments
  @strictpure def tempChanged_PAPred(): B = T
  // no integration constraints defined for other ports
  @strictpure def fanAck_PAPred(x: CoolingFan.FanAck.Type): B = T
  @strictpure def setPoint_PAPred(x: SetPoint_i): B = { return T }

  // --- o u t p u t s ---
  @strictpure def fanCmd_PAPred(x: CoolingFan.FanCmd.Type): B = { return T }
}

import TempControlPeriodic_i_Api._
@sig trait TempControlPeriodic_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId
  def fanAck_Id : Art.PortId
  def setPoint_Id : Art.PortId
  def fanCmd_Id : Art.PortId

  // =====================================================
  //   S p e c i f i c a t i o n    V a r i a b l e s
  //   R e p r e s e n t i n g    P o r t   V a r i a b l e s
  //
  //    with associated invariants
  // =====================================================

  // --- i n p u t s  ---
  @spec var currentTemp: TempSensor.Temperature_i = $
  @spec def currentTemp_Inv = Invariant(
    TempControlPeriodic_i_Api.currentTemp_PAPred(currentTemp)
  )

  @spec var fanAck: CoolingFan.FanAck.Type = $
  @spec def fanAck_Inv = Invariant(
    TempControlPeriodic_i_Api.fanAck_PAPred(fanAck)
  )

  @spec var setPoint: SetPoint_i = $
  @spec def setPoint_Inv = Invariant(
    TempControlPeriodic_i_Api.setPoint_PAPred(setPoint)
  )
  // --- o u t p u t s ---

  @spec var fanCmd: CoolingFan.FanCmd.Type = $
  @spec def fanCmd_Inv = Invariant(
    TempControlPeriodic_i_Api.fanCmd_PAPred(fanCmd)
  )

  def put_fanCmd(value : CoolingFan.FanCmd.Type) : Unit = {
    Contract(
      // Requires(fanCmd_PAPred(value)),
      Modifies(fanCmd),
      // output port variable is set to the value of the parameter
      Ensures(fanCmd == value)
    )
    Spec {
      fanCmd = value
    }
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

@datatype class TempControlPeriodic_i_Initialization_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val fanAck_Id : Art.PortId,
  val setPoint_Id : Art.PortId,
  val fanCmd_Id : Art.PortId) extends TempControlPeriodic_i_Api

@datatype class TempControlPeriodic_i_Operational_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val fanAck_Id : Art.PortId,
  val setPoint_Id : Art.PortId,
  val fanCmd_Id : Art.PortId) extends TempControlPeriodic_i_Api {

  def get_currentTemp() : Option[TempSensor.Temperature_i] = {
    Contract(
      Ensures(currentTemp_PAPred(currentTemp),
        Res == Some(currentTemp))
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
    Contract(
      Ensures(fanAck_PAPred(fanAck),
        Res == Some(fanAck))
    )
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
    Contract(
      Ensures(setPoint_PAPred(setPoint),
        Res == Some(setPoint))
    )
    val value : Option[TempControlSoftwareSystem.SetPoint_i] = Art.getValue(setPoint_Id) match {
      case Some(TempControlSoftwareSystem.SetPoint_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port setPoint.  Expecting 'TempControlSoftwareSystem.SetPoint_i_Payload' but received ${v}")
        None[TempControlSoftwareSystem.SetPoint_i]()
      case _ => None[TempControlSoftwareSystem.SetPoint_i]()
    }
    return value
  }
}
