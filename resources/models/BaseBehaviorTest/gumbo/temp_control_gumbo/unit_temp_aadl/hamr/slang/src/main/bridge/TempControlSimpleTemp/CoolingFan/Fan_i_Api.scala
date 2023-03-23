// #Sireum

package TempControlSimpleTemp.CoolingFan

import org.sireum._
import art._
import TempControlSimpleTemp._

object Fan_i_Api {
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
  @strictpure def fanCmd_PAPred(x: FanCmd.Type): B = T

  // --- o u t p u t s ---
  @strictpure def fanAck_PAPred(x: FanAck.Type): B = T
}

import Fan_i_Api._
@sig trait Fan_i_Api {
  def id: Art.BridgeId
  def fanCmd_Id : Art.PortId
  def fanAck_Id : Art.PortId

  // =====================================================
  //   S p e c i f i c a t i o n    V a r i a b l e s
  //   R e p r e s e n t i n g    P o r t   V a r i a b l e s
  //
  //    with associated invariants
  // =====================================================

  // --- i n p u t s  ---
  @spec var fanCmd: FanCmd.Type = $
  @spec def fanCmd_Inv = Invariant(
    fanCmd_PAPred(fanCmd)
  )

  // --- o u t p u t s ---

  @spec var fanAck: Option[FanAck.Type] = $
  @spec def fanAck_Inv = Invariant(
    fanAck.nonEmpty ->: fanAck_PAPred(fanAck.get)
  )


  def put_fanAck(value : CoolingFan.FanAck.Type) : Unit = {
    Contract(
      // Requires(fanAck_PAPred(value))
      //   -- don't think the above requires is needed since port invariant will be checked
      //      in any case due to association with spec variable
      Modifies(fanAck),
      // output port variable is set to the value of the parameter
      Ensures(fanAck == Some(value))
    )
    Spec {
      fanAck = Some(value)
    }
    Art.putValue(fanAck_Id, CoolingFan.FanAck_Payload(value))
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

@datatype class Fan_i_Initialization_Api (
  val id: Art.BridgeId,
  val fanCmd_Id : Art.PortId,
  val fanAck_Id : Art.PortId) extends Fan_i_Api

@datatype class Fan_i_Operational_Api (
  val id: Art.BridgeId,
  val fanCmd_Id : Art.PortId,
  val fanAck_Id : Art.PortId) extends Fan_i_Api {

  def get_fanCmd() : Option[CoolingFan.FanCmd.Type] = {
    Contract(
      Ensures(fanCmd_PAPred(fanCmd),
        // Not sure how we can conclude that this is definitely "Some"
        //  instead of possibly "None"
        Res == Some(fanCmd))
    )
    val value : Option[CoolingFan.FanCmd.Type] = Art.getValue(fanCmd_Id) match {
      case Some(CoolingFan.FanCmd_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port fanCmd.  Expecting 'CoolingFan.FanCmd_Payload' but received ${v}")
        None[CoolingFan.FanCmd.Type]()
      case _ => None[CoolingFan.FanCmd.Type]()
    }
    return value
  }
}
