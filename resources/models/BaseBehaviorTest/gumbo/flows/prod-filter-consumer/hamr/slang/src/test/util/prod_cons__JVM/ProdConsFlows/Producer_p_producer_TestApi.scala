package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art.{ArtNative_Ext, Empty}
import prod_cons__JVM._

// This file was auto-generated.  Do not edit
abstract class Producer_p_producer_TestApi extends BridgeTestSuite[Producer_p_producer_Bridge](Arch.s_i_Instance_p_producer) {

  /** helper function to check Producer_p_producer's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param a_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'a_out'.
   * @param b_out method that will be called with the payloads to be sent
   *        on the outgoing event data port 'b_out'.
   */
  def check_concrete_output(a_out: ISZ[Base_Types.Float_32] => B = a_outParam => {T},
                            b_out: ISZ[Base_Types.Float_32] => B = b_outParam => {T}): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    var a_outValue: ISZ[Base_Types.Float_32] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_a_out().nonEmpty) a_outValue = a_outValue :+ get_a_out().get
    if(!a_out(a_outValue)) {
      testFailures = testFailures :+ st"'a_out' did not match expected: received ${a_outValue.size} events with the following payloads ${a_outValue}"
    }
    var b_outValue: ISZ[Base_Types.Float_32] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_b_out().nonEmpty) b_outValue = b_outValue :+ get_b_out().get
    if(!b_out(b_outValue)) {
      testFailures = testFailures :+ st"'b_out' did not match expected: received ${b_outValue.size} events with the following payloads ${b_outValue}"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // getter for out EventDataPort
  def get_a_out(): Option[Base_Types.Float_32] = {
    val value: Option[Base_Types.Float_32] = get_a_out_payload() match {
      case Some(Base_Types.Float_32_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port a_out.  Expecting 'Base_Types.Float_32_Payload' but received ${v}")
      case _ => None[Base_Types.Float_32]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_a_out_payload(): Option[Base_Types.Float_32_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.a_out_Id).asInstanceOf[Option[Base_Types.Float_32_Payload]]
  }

  // getter for out EventDataPort
  def get_b_out(): Option[Base_Types.Float_32] = {
    val value: Option[Base_Types.Float_32] = get_b_out_payload() match {
      case Some(Base_Types.Float_32_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port b_out.  Expecting 'Base_Types.Float_32_Payload' but received ${v}")
      case _ => None[Base_Types.Float_32]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_b_out_payload(): Option[Base_Types.Float_32_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.b_out_Id).asInstanceOf[Option[Base_Types.Float_32_Payload]]
  }

}
