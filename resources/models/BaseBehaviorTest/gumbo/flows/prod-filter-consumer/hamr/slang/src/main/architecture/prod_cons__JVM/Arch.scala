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
    val a_out = Port[Base_Types.Float_32] (id = portId"0", name = "s_i_Instance_p_producer_a_out", mode = EventOut)
    val b_out = Port[Base_Types.Float_32] (id = portId"1", name = "s_i_Instance_p_producer_b_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Producer_p_producer_Bridge(
      id = bridgeId"0",
      name = "s_i_Instance_p_producer",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      a_out = a_out,
      b_out = b_out
    )
  }
  val s_i_Instance_p_filterp : prod_cons__JVM.ProdConsFlows.Filter_p_p_filterp_Bridge = {
    val a_in = Port[Base_Types.Float_32] (id = portId"2", name = "s_i_Instance_p_filterp_a_in", mode = EventIn)
    val b_in = Port[Base_Types.Float_32] (id = portId"3", name = "s_i_Instance_p_filterp_b_in", mode = EventIn)
    val a_out = Port[Base_Types.Float_32] (id = portId"4", name = "s_i_Instance_p_filterp_a_out", mode = EventOut)
    val b_out = Port[Base_Types.Float_32] (id = portId"5", name = "s_i_Instance_p_filterp_b_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Filter_p_p_filterp_Bridge(
      id = bridgeId"1",
      name = "s_i_Instance_p_filterp",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      a_in = a_in,
      b_in = b_in,
      a_out = a_out,
      b_out = b_out
    )
  }
  val s_i_Instance_p_filters : prod_cons__JVM.ProdConsFlows.Filter_s_p_filters_Bridge = {
    val a_in = Port[Base_Types.Float_32] (id = portId"6", name = "s_i_Instance_p_filters_a_in", mode = EventIn)
    val b_in = Port[Base_Types.Float_32] (id = portId"7", name = "s_i_Instance_p_filters_b_in", mode = EventIn)
    val a_out = Port[Base_Types.Float_32] (id = portId"8", name = "s_i_Instance_p_filters_a_out", mode = EventOut)
    val b_out = Port[Base_Types.Float_32] (id = portId"9", name = "s_i_Instance_p_filters_b_out", mode = EventOut)

    prod_cons__JVM.ProdConsFlows.Filter_s_p_filters_Bridge(
      id = bridgeId"2",
      name = "s_i_Instance_p_filters",
      dispatchProtocol = Sporadic(min = 1),
      dispatchTriggers = None(),

      a_in = a_in,
      b_in = b_in,
      a_out = a_out,
      b_out = b_out
    )
  }
  val s_i_Instance_p_consumer : prod_cons__JVM.ProdConsFlows.Consumer_p_consumer_Bridge = {
    val a_in = Port[Base_Types.Float_32] (id = portId"10", name = "s_i_Instance_p_consumer_a_in", mode = EventIn)
    val b_in = Port[Base_Types.Float_32] (id = portId"11", name = "s_i_Instance_p_consumer_b_in", mode = EventIn)

    prod_cons__JVM.ProdConsFlows.Consumer_p_consumer_Bridge(
      id = bridgeId"3",
      name = "s_i_Instance_p_consumer",
      dispatchProtocol = Sporadic(min = 1),
      dispatchTriggers = None(),

      a_in = a_in,
      b_in = b_in
    )
  }

  val ad : ArchitectureDescription = {

    ArchitectureDescription(
      components = IS[Art.BridgeId, Bridge] (s_i_Instance_p_producer, s_i_Instance_p_filterp, s_i_Instance_p_filters, s_i_Instance_p_consumer),

      connections = IS[Art.ConnectionId, UConnection] (Connection(from = s_i_Instance_p_producer.a_out, to = s_i_Instance_p_filterp.a_in),
                                                       Connection(from = s_i_Instance_p_producer.a_out, to = s_i_Instance_p_filters.a_in),
                                                       Connection(from = s_i_Instance_p_producer.b_out, to = s_i_Instance_p_filterp.b_in),
                                                       Connection(from = s_i_Instance_p_producer.b_out, to = s_i_Instance_p_filters.b_in),
                                                       Connection(from = s_i_Instance_p_filterp.a_out, to = s_i_Instance_p_consumer.a_in),
                                                       Connection(from = s_i_Instance_p_filterp.b_out, to = s_i_Instance_p_consumer.b_in),
                                                       Connection(from = s_i_Instance_p_filters.a_out, to = s_i_Instance_p_consumer.a_in),
                                                       Connection(from = s_i_Instance_p_filters.b_out, to = s_i_Instance_p_consumer.b_in))
    )
  }
}
