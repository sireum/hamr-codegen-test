// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._

object Filter_s_Api {
  // assume a_gt_10
  //   Value received on a will always be greater than 10
  @strictpure def a_gt_1_(a_data_in: ProdConsFlows.Container_i): B =
    a_data_in.value > 10

  // assume b_gt_8
  //   Value received on b will always be greater than 8
  @strictpure def b_gt_8(b_event_data_in: ProdConsFlows.Container_i): B =
    b_event_data_in.value > 8

  // guarantee e_gt_6
  //   Values placed on e must always be greate than 6
  @strictpure def e_gt_6(e_data_out: ProdConsFlows.Container_i): B =
    e_data_out.value > 6

  // guarantee f_gt_4
  //   Values placed on f must always be greate than 4
  @strictpure def f_gt_4(f_event_data_out: ProdConsFlows.Container_i): B =
    f_event_data_out.value > 4
}

import Filter_s_Api._

@sig trait Filter_s_Api {
  def id: Art.BridgeId
  def a_data_in_Id : Art.PortId
  def e_data_out_Id : Art.PortId
  def b_event_data_in_Id : Art.PortId
  def c_event_data_in_Id : Art.PortId
  def f_event_data_out_Id : Art.PortId
  def g_event_data_out_Id : Art.PortId
  def d_event_in_Id : Art.PortId
  def h_event_out_Id : Art.PortId

  // Logika spec var representing port state for outgoing data port
  @spec var e_data_out: ProdConsFlows.Container_i = $
  @spec def e_data_out_Inv = Invariant(
    e_gt_6(e_data_out)
  )

  def put_e_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Requires(
        e_gt_6(value)
      ),
      Modifies(e_data_out),
      Ensures(
        e_data_out == value
      )
    )
    Spec {
      e_data_out = value
    }

    Art.putValue(e_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var f_event_data_out: Option[ProdConsFlows.Container_i] = $
  @spec def f_event_data_out_Inv = Invariant(
    f_event_data_out.isEmpty || f_gt_4(f_event_data_out.get)
  )

  def put_f_event_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Requires(
        f_gt_4(value)
      ),
      Modifies(f_event_data_out),
      Ensures(
        f_event_data_out == Some(value)
      )
    )
    Spec {
      f_event_data_out = Some(value)
    }

    Art.putValue(f_event_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var g_event_data_out: Option[ProdConsFlows.Container_i] = $

  def put_g_event_data_out(value : ProdConsFlows.Container_i) : Unit = {
    Contract(
      Modifies(g_event_data_out),
      Ensures(
        g_event_data_out == Some(value)
      )
    )
    Spec {
      g_event_data_out = Some(value)
    }

    Art.putValue(g_event_data_out_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event port
  @spec var h_event_out: Option[art.Empty] = $

  def put_h_event_out() : Unit = {
    Contract(
      Modifies(h_event_out),
      Ensures(
        h_event_out == Some(Empty())
      )
    )
    Spec {
      h_event_out = Some(Empty())
    }

    Art.putValue(h_event_out_Id, art.Empty())
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

@datatype class Filter_s_Initialization_Api (
  val id: Art.BridgeId,
  val a_data_in_Id : Art.PortId,
  val e_data_out_Id : Art.PortId,
  val b_event_data_in_Id : Art.PortId,
  val c_event_data_in_Id : Art.PortId,
  val f_event_data_out_Id : Art.PortId,
  val g_event_data_out_Id : Art.PortId,
  val d_event_in_Id : Art.PortId,
  val h_event_out_Id : Art.PortId) extends Filter_s_Api

@datatype class Filter_s_Operational_Api (
  val id: Art.BridgeId,
  val a_data_in_Id : Art.PortId,
  val e_data_out_Id : Art.PortId,
  val b_event_data_in_Id : Art.PortId,
  val c_event_data_in_Id : Art.PortId,
  val f_event_data_out_Id : Art.PortId,
  val g_event_data_out_Id : Art.PortId,
  val d_event_in_Id : Art.PortId,
  val h_event_out_Id : Art.PortId) extends Filter_s_Api {

  // Logika spec var representing port state for incoming data port
  @spec var a_data_in: ProdConsFlows.Container_i = $
  @spec def a_data_in_Inv = Invariant(
    a_gt_1_(a_data_in)
  )

  def get_a_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        a_gt_1_(a_data_in),
        Res == Some(a_data_in)
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(a_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port a_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var b_event_data_in: Option[ProdConsFlows.Container_i] = $
  @spec def b_event_data_in_Inv = Invariant(
    b_event_data_in.isEmpty || b_gt_8(b_event_data_in.get)
  )

  def get_b_event_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        b_event_data_in.isEmpty || b_gt_8(b_event_data_in.get),
        Res == b_event_data_in
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(b_event_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port b_event_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var c_event_data_in: Option[ProdConsFlows.Container_i] = $

  def get_c_event_data_in() : Option[ProdConsFlows.Container_i] = {
    Contract(
      Ensures(
        Res == c_event_data_in
      )
    )
    val value : Option[ProdConsFlows.Container_i] = Art.getValue(c_event_data_in_Id) match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port c_event_data_in.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
        None[ProdConsFlows.Container_i]()
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event port
  @spec var d_event_in: Option[art.Empty] = $

  def get_d_event_in() : Option[art.Empty] = {
    Contract(
      Ensures(
        Res == d_event_in
      )
    )
    val value : Option[art.Empty] = Art.getValue(d_event_in_Id) match {
      case Some(Empty()) => Some(Empty())
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port d_event_in.  Expecting 'Empty' but received ${v}")
        None[art.Empty]()
      case _ => None[art.Empty]()
    }
    return value
  }
}
