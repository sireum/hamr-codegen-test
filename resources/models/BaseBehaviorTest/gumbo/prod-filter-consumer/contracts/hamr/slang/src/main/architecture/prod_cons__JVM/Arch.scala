// #Sireum

package prod_cons__JVM

import org.sireum._
import art._
import art.PortMode._
import art.DispatchPropertyProtocol._
import art.Art.BridgeId._
import art.Art.PortId._

// This file was auto-generated.  Do not edit

object Arch {
  val s_i_Instance_p_producer : prod_cons__JVM.ProdConsFlows.Producer_p_producer_Bridge = {
    val a_data_out = Port[ProdConsFlows.Container_i] (id = portId"0", name = "s_i_Instance_p_producer_a_data_out", mode = DataOut)
    val b_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"1", name = "s_i_Instance_p_producer_b_event_data_out", mode = EventOut)
    val c_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"2", name = "s_i_Instance_p_producer_c_event_data_out", mode = EventOut)
    val d_event_out = Port[art.Empty] (id = portId"3", name = "s_i_Instance_p_producer_d_event_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Producer_p_producer_Bridge(
      id = bridgeId"0",
      name = "s_i_Instance_p_producer",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      a_data_out = a_data_out,
      b_event_data_out = b_event_data_out,
      c_event_data_out = c_event_data_out,
      d_event_out = d_event_out
    )
  }
  val s_i_Instance_p_filterp : prod_cons__JVM.ProdConsFlows.Filter_p_p_filterp_Bridge = {
    val a_data_in = Port[ProdConsFlows.Container_i] (id = portId"4", name = "s_i_Instance_p_filterp_a_data_in", mode = DataIn)
    val e_data_out = Port[ProdConsFlows.Container_i] (id = portId"5", name = "s_i_Instance_p_filterp_e_data_out", mode = DataOut)
    val b_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"6", name = "s_i_Instance_p_filterp_b_event_data_in", mode = EventIn)
    val c_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"7", name = "s_i_Instance_p_filterp_c_event_data_in", mode = EventIn)
    val f_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"8", name = "s_i_Instance_p_filterp_f_event_data_out", mode = EventOut)
    val g_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"9", name = "s_i_Instance_p_filterp_g_event_data_out", mode = EventOut)
    val d_event_in = Port[art.Empty] (id = portId"10", name = "s_i_Instance_p_filterp_d_event_in", mode = EventIn)
    val h_event_out = Port[art.Empty] (id = portId"11", name = "s_i_Instance_p_filterp_h_event_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Filter_p_p_filterp_Bridge(
      id = bridgeId"1",
      name = "s_i_Instance_p_filterp",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      a_data_in = a_data_in,
      e_data_out = e_data_out,
      b_event_data_in = b_event_data_in,
      c_event_data_in = c_event_data_in,
      f_event_data_out = f_event_data_out,
      g_event_data_out = g_event_data_out,
      d_event_in = d_event_in,
      h_event_out = h_event_out
    )
  }
  val s_i_Instance_p_filters : prod_cons__JVM.ProdConsFlows.Filter_s_p_filters_Bridge = {
    val a_data_in = Port[ProdConsFlows.Container_i] (id = portId"12", name = "s_i_Instance_p_filters_a_data_in", mode = DataIn)
    val e_data_out = Port[ProdConsFlows.Container_i] (id = portId"13", name = "s_i_Instance_p_filters_e_data_out", mode = DataOut)
    val b_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"14", name = "s_i_Instance_p_filters_b_event_data_in", mode = EventIn)
    val c_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"15", name = "s_i_Instance_p_filters_c_event_data_in", mode = EventIn)
    val f_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"16", name = "s_i_Instance_p_filters_f_event_data_out", mode = EventOut)
    val g_event_data_out = Port[ProdConsFlows.Container_i] (id = portId"17", name = "s_i_Instance_p_filters_g_event_data_out", mode = EventOut)
    val d_event_in = Port[art.Empty] (id = portId"18", name = "s_i_Instance_p_filters_d_event_in", mode = EventIn)
    val h_event_out = Port[art.Empty] (id = portId"19", name = "s_i_Instance_p_filters_h_event_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Filter_s_p_filters_Bridge(
      id = bridgeId"2",
      name = "s_i_Instance_p_filters",
      dispatchProtocol = Sporadic(min = 1),
      dispatchTriggers = None(),

      a_data_in = a_data_in,
      e_data_out = e_data_out,
      b_event_data_in = b_event_data_in,
      c_event_data_in = c_event_data_in,
      f_event_data_out = f_event_data_out,
      g_event_data_out = g_event_data_out,
      d_event_in = d_event_in,
      h_event_out = h_event_out
    )
  }
  val s_i_Instance_p_consumer : prod_cons__JVM.ProdConsFlows.Consumer_p_consumer_Bridge = {
    val e_data_in = Port[ProdConsFlows.Container_i] (id = portId"20", name = "s_i_Instance_p_consumer_e_data_in", mode = DataIn)
    val f_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"21", name = "s_i_Instance_p_consumer_f_event_data_in", mode = EventIn)
    val g_event_data_in = Port[ProdConsFlows.Container_i] (id = portId"22", name = "s_i_Instance_p_consumer_g_event_data_in", mode = EventIn)
    val h_event_in = Port[art.Empty] (id = portId"23", name = "s_i_Instance_p_consumer_h_event_in", mode = EventIn)

    prod_cons__JVM.ProdConsFlows.Consumer_p_consumer_Bridge(
      id = bridgeId"3",
      name = "s_i_Instance_p_consumer",
      dispatchProtocol = Sporadic(min = 1),
      dispatchTriggers = None(),

      e_data_in = e_data_in,
      f_event_data_in = f_event_data_in,
      g_event_data_in = g_event_data_in,
      h_event_in = h_event_in
    )
  }

  val ad : ArchitectureDescription = {

    ArchitectureDescription(
      components = IS[Art.BridgeId, Bridge] (s_i_Instance_p_producer, s_i_Instance_p_filterp, s_i_Instance_p_filters, s_i_Instance_p_consumer),

      connections = IS[Art.ConnectionId, UConnection] (Connection(from = s_i_Instance_p_producer.a_data_out, to = s_i_Instance_p_filterp.a_data_in),
                                                       Connection(from = s_i_Instance_p_producer.a_data_out, to = s_i_Instance_p_filters.a_data_in),
                                                       Connection(from = s_i_Instance_p_producer.b_event_data_out, to = s_i_Instance_p_filterp.b_event_data_in),
                                                       Connection(from = s_i_Instance_p_producer.b_event_data_out, to = s_i_Instance_p_filters.b_event_data_in),
                                                       Connection(from = s_i_Instance_p_producer.c_event_data_out, to = s_i_Instance_p_filterp.c_event_data_in),
                                                       Connection(from = s_i_Instance_p_producer.c_event_data_out, to = s_i_Instance_p_filters.c_event_data_in),
                                                       Connection(from = s_i_Instance_p_producer.d_event_out, to = s_i_Instance_p_filterp.d_event_in),
                                                       Connection(from = s_i_Instance_p_producer.d_event_out, to = s_i_Instance_p_filters.d_event_in),
                                                       Connection(from = s_i_Instance_p_filterp.e_data_out, to = s_i_Instance_p_consumer.e_data_in),
                                                       Connection(from = s_i_Instance_p_filterp.f_event_data_out, to = s_i_Instance_p_consumer.f_event_data_in),
                                                       Connection(from = s_i_Instance_p_filterp.g_event_data_out, to = s_i_Instance_p_consumer.g_event_data_in),
                                                       Connection(from = s_i_Instance_p_filterp.h_event_out, to = s_i_Instance_p_consumer.h_event_in),
                                                       Connection(from = s_i_Instance_p_filters.e_data_out, to = s_i_Instance_p_consumer.e_data_in),
                                                       Connection(from = s_i_Instance_p_filters.f_event_data_out, to = s_i_Instance_p_consumer.f_event_data_in),
                                                       Connection(from = s_i_Instance_p_filters.g_event_data_out, to = s_i_Instance_p_consumer.g_event_data_in),
                                                       Connection(from = s_i_Instance_p_filters.h_event_out, to = s_i_Instance_p_consumer.h_event_in))
    )
  }
}
