// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art.{Art, ArtNative, Empty}
import prod_cons__JVM._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
@msig trait Producer_p_producer_TestApi {

  def BeforeEntrypoint(): Unit = {
    Art.initTest(Arch.s_i_Instance_p_producer)
  }

  def AfterEntrypoint(): Unit = {
    Art.finalizeTest(Arch.s_i_Instance_p_producer)
  }

  def testCompute(): Unit = {
    Art.manuallyClearOutput()
    Art.testCompute(Arch.s_i_Instance_p_producer)
  }

  def testInitialise(): Unit = {
    Art.manuallyClearOutput()
    Art.testInitialise(Arch.s_i_Instance_p_producer)
  }

  /** helper function to check Producer_p_producer's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param a_data_out method that will be called with the value of the outgoing data
   *        port 'a_data_out'.
   * @param b_event_data_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'b_event_data_out'.
   * @param c_event_data_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'c_event_data_out'.
   * @param d_event_out method that will be called with the number of events to be sent
   *        on the outgoing event port 'd_event_out'.
   */
  def check_concrete_output(a_data_out: ProdConsFlows.Container_i => B,
                            b_event_data_out: ISZ[ProdConsFlows.Container_i] => B,
                            c_event_data_out: ISZ[ProdConsFlows.Container_i] => B,
                            d_event_out: Z => B): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    val a_data_outValue: ProdConsFlows.Container_i = get_a_data_out().get
    if(!a_data_out(a_data_outValue)) {
      testFailures = testFailures :+ st"'a_data_out' did not match expected: value of the outgoing data port is ${a_data_outValue}"
    }
    var b_event_data_outValue: ISZ[ProdConsFlows.Container_i] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_b_event_data_out().nonEmpty) { b_event_data_outValue = b_event_data_outValue :+ get_b_event_data_out().get }
    if(!b_event_data_out(b_event_data_outValue)) {
      testFailures = testFailures :+ st"'b_event_data_out' did not match expected: received ${b_event_data_outValue.size} events with the following payloads ${b_event_data_outValue}"
    }
    var c_event_data_outValue: ISZ[ProdConsFlows.Container_i] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_c_event_data_out().nonEmpty) { c_event_data_outValue = c_event_data_outValue :+ get_c_event_data_out().get }
    if(!c_event_data_out(c_event_data_outValue)) {
      testFailures = testFailures :+ st"'c_event_data_out' did not match expected: received ${c_event_data_outValue.size} events with the following payloads ${c_event_data_outValue}"
    }
    // TODO: event port getter should return the number of events in
    //       the output queue when queue sizes > 1 support is added to ART
    val d_event_outValue: Z = if(get_d_event_out().nonEmpty) z"1" else z"0"
    if(!d_event_out(d_event_outValue)) {
      testFailures = testFailures :+ st"'d_event_out' did not match expected: ${d_event_outValue} events were in the outgoing event queue"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // getter for out DataPort
  def get_a_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_a_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port a_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out DataPort
  def get_a_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_producer.initialization_api.a_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventDataPort
  def get_b_event_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_b_event_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port b_event_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_b_event_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_producer.initialization_api.b_event_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventDataPort
  def get_c_event_data_out(): Option[ProdConsFlows.Container_i] = {
    val value: Option[ProdConsFlows.Container_i] = get_c_event_data_out_payload() match {
      case Some(ProdConsFlows.Container_i_Payload(v)) => Some(v)
      case Some(v) => halt(s"Unexpected payload on port c_event_data_out.  Expecting 'ProdConsFlows.Container_i_Payload' but received ${v}")
      case _ => None[ProdConsFlows.Container_i]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_c_event_data_out_payload(): Option[ProdConsFlows.Container_i_Payload] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_producer.initialization_api.c_event_data_out_Id).asInstanceOf[Option[ProdConsFlows.Container_i_Payload]]
  }

  // getter for out EventPort
  def get_d_event_out(): Option[art.Empty] = {
    val value: Option[art.Empty] = get_d_event_out_payload() match {
      case Some(Empty()) => Some(Empty())
      case Some(v) => halt(s"Unexpected payload on port d_event_out.  Expecting 'Empty' but received ${v}")
      case _ => None[art.Empty]()
    }
    return value
  }

  // payload getter for out EventPort
  def get_d_event_out_payload(): Option[Empty] = {
    return ArtNative.observeOutPortValue(Arch.s_i_Instance_p_producer.initialization_api.d_event_out_Id).asInstanceOf[Option[Empty]]
  }

}