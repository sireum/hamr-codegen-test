package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art.{ArtNative_Ext, Empty}
import prod_cons__JVM._

// This file was auto-generated.  Do not edit
abstract class Consumer_p_consumer_TestApi extends BridgeTestSuite[Consumer_p_consumer_Bridge](Arch.s_i_Instance_p_consumer) {

  /** helper function to set the values of all input ports.
   * @param a_in payloads for event data port a_in.
   *   ART currently supports single element event data queues so
   *   only the last element of a_in will be used
   * @param b_in payloads for event data port b_in.
   *   ART currently supports single element event data queues so
   *   only the last element of b_in will be used
   */
  def put_concrete_inputs(a_in : ISZ[Base_Types.Float_32],
                          b_in : ISZ[Base_Types.Float_32]): Unit = {
    for(v <- a_in){
      put_a_in(v)
    }
    for(v <- b_in){
      put_b_in(v)
    }
  }


  // setter for in EventDataPort
  def put_a_in(value : Base_Types.Float_32): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.a_in_Id, Base_Types.Float_32_Payload(value))
  }

  // setter for in EventDataPort
  def put_b_in(value : Base_Types.Float_32): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.b_in_Id, Base_Types.Float_32_Payload(value))
  }

}