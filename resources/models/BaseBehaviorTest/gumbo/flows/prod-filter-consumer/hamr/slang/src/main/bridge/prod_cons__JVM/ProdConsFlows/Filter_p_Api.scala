// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

@sig trait Filter_p_Api {
  def id: Art.BridgeId
  def a_in_Id : Art.PortId
  def b_in_Id : Art.PortId
  def a_out_Id : Art.PortId
  def b_out_Id : Art.PortId

  // Logika spec var representing port state for outgoing event data port
  @spec var a_out: Option[Base_Types.Float_32] = $

  def put_a_out(value : Base_Types.Float_32) : Unit = {
    Contract(
      Modifies(a_out),
      Ensures(
        a_out == Some(value)
      )
    )
    Spec {
      a_out = Some(value)
    }

    Art.putValue(a_out_Id, Base_Types.Float_32_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var b_out: Option[Base_Types.Float_32] = $

  def put_b_out(value : Base_Types.Float_32) : Unit = {
    Contract(
      Modifies(b_out),
      Ensures(
        b_out == Some(value)
      )
    )
    Spec {
      b_out = Some(value)
    }

    Art.putValue(b_out_Id, Base_Types.Float_32_Payload(value))
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

@datatype class Filter_p_Initialization_Api (
  val id: Art.BridgeId,
  val a_in_Id : Art.PortId,
  val b_in_Id : Art.PortId,
  val a_out_Id : Art.PortId,
  val b_out_Id : Art.PortId) extends Filter_p_Api

@datatype class Filter_p_Operational_Api (
  val id: Art.BridgeId,
  val a_in_Id : Art.PortId,
  val b_in_Id : Art.PortId,
  val a_out_Id : Art.PortId,
  val b_out_Id : Art.PortId) extends Filter_p_Api {

  // Logika spec var representing port state for incoming event data port
  @spec var a_in: Base_Types.Float_32 = $

  def get_a_in() : Option[Base_Types.Float_32] = {
    Contract(
      Ensures(
        Res == Some(a_in)
      )
    )
    val value : Option[Base_Types.Float_32] = Art.getValue(a_in_Id) match {
      case Some(Base_Types.Float_32_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port a_in.  Expecting 'Base_Types.Float_32_Payload' but received ${v}")
        None[Base_Types.Float_32]()
      case _ => None[Base_Types.Float_32]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var b_in: Base_Types.Float_32 = $

  def get_b_in() : Option[Base_Types.Float_32] = {
    Contract(
      Ensures(
        Res == Some(b_in)
      )
    )
    val value : Option[Base_Types.Float_32] = Art.getValue(b_in_Id) match {
      case Some(Base_Types.Float_32_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port b_in.  Expecting 'Base_Types.Float_32_Payload' but received ${v}")
        None[Base_Types.Float_32]()
      case _ => None[Base_Types.Float_32]()
    }
    return value
  }
}
