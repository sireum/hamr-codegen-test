// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art.{Art, ArtNative, Empty}
import prod_cons__JVM._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait Filter_p_p_filterp_TestApi {

  def BeforeEntrypoint(): Unit = {
    Art.initTest(Arch.s_i_Instance_p_filterp)
  }

  def AfterEntrypoint(): Unit = {
    Art.finalizeTest(Arch.s_i_Instance_p_filterp)
  }

  def testCompute(): Unit = {
    Art.manuallyClearOutput()
    Art.testCompute(Arch.s_i_Instance_p_filterp)
  }

  def testInitialise(): Unit = {
    Art.manuallyClearOutput()
    Art.testInitialise(Arch.s_i_Instance_p_filterp)
  }

  /** helper function to set the values of all input ports.
   * @param a_data_in payload for data port a_data_in
   * @param b_event_data_in payloads for event data port b_event_data_in.
   *   ART currently supports single element event data queues so
   *   only the last element of b_event_data_in will be used
   * @param c_event_data_in payloads for event data port c_event_data_in.
   *   ART currently supports single element event data queues so
   *   only the last element of c_event_data_in will be used
   * @param d_event_in the number of events to place in the d_event_in event port queue.
   *   ART currently supports single element event queues so at most
   *   one event will be placed in the queue.
   */
  def put_concrete_inputs(a_data_in : ProdConsFlows.Container_i,
                          b_event_data_in : ISZ[ProdConsFlows.Container_i],
                          c_event_data_in : ISZ[ProdConsFlows.Container_i],
                          d_event_in : Z): Unit = {
    put_a_data_in(a_data_in)
    for(v <- b_event_data_in){
      put_b_event_data_in(v)
    }
    for(v <- c_event_data_in){
      put_c_event_data_in(v)
    }
    for(i <- 0 until d_event_in) {
      put_d_event_in()
    }
  }


  /** helper function to check Filter_p_p_filterp's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param e_data_out method that will be called with the value of the outgoing data
   *        port 'e_data_out'.
   * @param f_event_data_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'f_event_data_out'.
   * @param g_event_data_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'g_event_data_out'.
   * @param h_event_out method that will be called with the number of events to be sent
   *        on the outgoing event port 'h_event_out'.
   */
  def check_concrete_output(e_data_out: ProdConsFlows.Container_i => B,
                            f_event_data_out: ISZ[ProdConsFlows.Container_i] => B,
                            g_event_data_out: ISZ[ProdConsFlows.Container_i] => B,
                            h_event_out: Z => B): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    val e_data_outValue: ProdConsFlows.Container_i = get_e_data_out().get
    if(!e_data_out(e_data_outValue)) {
      testFailures = testFailures :+ st"'e_data_out' did not match expected: value of the outgoing data port is ${e_data_outValue}"
    }
    var f_event_data_outValue: ISZ[ProdConsFlows.Container_i] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_f_event_data_out().nonEmpty) { f_event_data_outValue = f_event_data_outValue :+ get_f_event_data_out().get }
    if(!f_event_data_out(f_event_data_outValue)) {
      testFailures = testFailures :+ st"'f_event_data_out' did not match expected: received ${f_event_data_outValue.size} events with the following payloads ${f_event_data_outValue}"
    }
    var g_event_data_outValue: ISZ[ProdConsFlows.Container_i] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_g_event_data_out().nonEmpty) { g_event_data_outValue = g_event_data_outValue :+ get_g_event_data_out().get }
    if(!g_event_data_out(g_event_data_outValue)) {
      testFailures = testFailures :+ st"'g_event_data_out' did not match expected: received ${g_event_data_outValue.size} events with the following payloads ${g_event_data_outValue}"
    }
    // TODO: event port getter should return the number of events in
    //       the output queue when queue sizes > 1 support is added to ART
    val h_event_outValue: Z = if(get_h_event_out().nonEmpty) z"1" else z"0"
    if(!h_event_out(h_event_outValue)) {
      testFailures = testFailures :+ st"'h_event_out' did not match expected: ${h_event_outValue} events were in the outgoing event queue"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // setter for in DataPort
  def put_a_data_in(value : ProdConsFlows.Container_i): Unit = {
    ArtNative.insertInPortValue(Arch.s_i_Instance_p_filterp.operational_api.a_data_in_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // setter for in EventDataPort
  def put_b_event_data_in(value : ProdConsFlows.Container_i): Unit = {
    ArtNative.insertInPortValue(Arch.s_i_Instance_p_filterp.operational_api.b_event_data_in_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // setter for in EventDataPort
  def put_c_event_data_in(value : ProdConsFlows.Container_i): Unit = {
    ArtNative.insertInPortValue(Arch.s_i_Instance_p_filterp.operational_api.c_event_data_in_Id, ProdConsFlows.Container_i_Payload(value))
  }

  // setter for in EventPort
  def put_d_event_in(): Unit = {
    ArtNative.insertInPortValue(Arch.s_i_Instance_p_filterp.operational_api.d_event_in_Id, Empty())
  }

  // getter for out DataPort
  def get_e_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_e_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port e_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out DataPort
  def get_e_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_filterp.initialization_api.e_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventDataPort
  def get_f_event_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_f_event_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port f_event_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_f_event_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_filterp.initialization_api.f_event_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventDataPort
  def get_g_event_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_g_event_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port g_event_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_g_event_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_filterp.initialization_api.g_event_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventPort
  def get_h_event_out(): Option[art.Empty] = {
    val value: Option[art.Empty] = get_h_event_out_payload() match {
      case Some(Empty()) => Some(Empty())
      case Some(v) => halt(s"Unexpected payload on port h_event_out.  Expecting 'Empty' but received ${v}")
      case _ => None[art.Empty]()
    }
    return value
  }

  // payload getter for out EventPort
  def get_h_event_out_payload(): Option[Empty] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_filterp.initialization_api.h_event_out_Id).asInstanceOf[Option[Empty]]
  }

}