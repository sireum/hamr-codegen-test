// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

@sig trait Producer_Api {
  def id: Art.BridgeId
  def a_data_out_Id : Art.PortId
  def b_event_data_out_Id : Art.PortId
  def c_event_data_out_Id : Art.PortId
  def d_event_out_Id : Art.PortId

  // Logika spec var representing port state for outgoing data port
  @spec var a_data_out: ProdConsFlows.Container_i = $

  def put_a_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Modifies(a_data_out),
      Ensures(
        a_data_out == value
      )
    )
    Spec {
      a_data_out = value
    }

    Art.putValue(a_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var b_event_data_out: Option[ProdConsFlows.Container_i] = $

  def put_b_event_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Modifies(b_event_data_out),
      Ensures(
        b_event_data_out == Some(value)
      )
    )
    Spec {
      b_event_data_out = Some(value)
    }

    Art.putValue(b_event_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var c_event_data_out: Option[ProdConsFlows.Container_i] = $

  def put_c_event_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Modifies(c_event_data_out),
      Ensures(
        c_event_data_out == Some(value)
      )
    )
    Spec {
      c_event_data_out = Some(value)
    }

    Art.putValue(c_event_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event port
  @spec var d_event_out: Option[art.Empty] = $

  def put_d_event_out() : Unit = {
    Contract(
      Modifies(d_event_out),
      Ensures(
        d_event_out == Some(Empty())
      )
    )
    Spec {
      d_event_out = Some(Empty())
    }

    Art.putValue(d_event_out_Id, art.Empty())
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
  val a_data_out_Id : Art.PortId,
  val b_event_data_out_Id : Art.PortId,
  val c_event_data_out_Id : Art.PortId,
  val d_event_out_Id : Art.PortId) extends Producer_Api

@datatype class Producer_Operational_Api (
  val id: Art.BridgeId,
  val a_data_out_Id : Art.PortId,
  val b_event_data_out_Id : Art.PortId,
  val c_event_data_out_Id : Art.PortId,
  val d_event_out_Id : Art.PortId) extends Producer_Api {

}
