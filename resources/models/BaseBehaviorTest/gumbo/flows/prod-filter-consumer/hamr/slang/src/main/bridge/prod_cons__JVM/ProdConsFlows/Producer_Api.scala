// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

@sig trait Producer_Api {
  def id: Art.BridgeId
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

@datatype class Producer_Initialization_Api (
  val id: Art.BridgeId,
  val a_out_Id : Art.PortId,
  val b_out_Id : Art.PortId) extends Producer_Api

@datatype class Producer_Operational_Api (
  val id: Art.BridgeId,
  val a_out_Id : Art.PortId,
  val b_out_Id : Art.PortId) extends Producer_Api {

}