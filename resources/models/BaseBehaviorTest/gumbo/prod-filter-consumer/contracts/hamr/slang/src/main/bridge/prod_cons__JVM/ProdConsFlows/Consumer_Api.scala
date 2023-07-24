// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

@sig trait Consumer_Api {
  def id: Art.BridgeId
  def e_data_in_Id : Art.PortId
  def f_event_data_in_Id : Art.PortId
  def g_event_data_in_Id : Art.PortId
  def h_event_in_Id : Art.PortId


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
  val e_data_in_Id : Art.PortId,
  val f_event_data_in_Id : Art.PortId,
  val g_event_data_in_Id : Art.PortId,
  val h_event_in_Id : Art.PortId) extends Consumer_Api

@datatype class Consumer_Operational_Api (
  val id: Art.BridgeId,
  val e_data_in_Id : Art.PortId,
  val f_event_data_in_Id : Art.PortId,
  val g_event_data_in_Id : Art.PortId,
  val h_event_in_Id : Art.PortId) extends Consumer_Api {

  // Logika spec var representing port state for incoming data port
  @spec var e_data_in: ProdConsFlows.Container_i = $

  def get_e_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        Res == Some(e_data_in)
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(e_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port e_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var f_event_data_in: Option[ProdConsFlows.Container_i] = $

  def get_f_event_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        Res == f_event_data_in
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(f_event_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port f_event_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var g_event_data_in: Option[ProdConsFlows.Container_i] = $

  def get_g_event_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        Res == g_event_data_in
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(g_event_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port g_event_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event port
  @spec var h_event_in: Option[art.Empty] = $

  def get_h_event_in() : Option[art.Empty] = {
    Contract(
      Ensures(
        Res == h_event_in
      )
    )
    val value : Option[art.Empty] = Art.getValue(h_event_in_Id) match {
      case Some(Empty()) => Some(Empty())
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port h_event_in.  Expecting 'Empty' but received ${v}")
        None[art.Empty]()
      case _ => None[art.Empty]()
    }
    return value
  }
}
