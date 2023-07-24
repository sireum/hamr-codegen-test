// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

@sig trait Consumer_Api {
  def id: Art.BridgeId
  def a_in_Id : Art.PortId
  def b_in_Id : Art.PortId


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

@datatype class Consumer_Initialization_Api (
  val id: Art.BridgeId,
  val a_in_Id : Art.PortId,
  val b_in_Id : Art.PortId) extends Consumer_Api

@datatype class Consumer_Operational_Api (
  val id: Art.BridgeId,
  val a_in_Id : Art.PortId,
  val b_in_Id : Art.PortId) extends Consumer_Api {

  // Logika spec var representing port state for incoming event data port
  @spec var a_in: Option[Base_Types.Float_32] = $

  def get_a_in() : Option[Base_Types.Float_32] = {
    Contract(
      Ensures(
        Res == a_in
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
  @spec var b_in: Option[Base_Types.Float_32] = $

  def get_b_in() : Option[Base_Types.Float_32] = {
    Contract(
      Ensures(
        Res == b_in
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
