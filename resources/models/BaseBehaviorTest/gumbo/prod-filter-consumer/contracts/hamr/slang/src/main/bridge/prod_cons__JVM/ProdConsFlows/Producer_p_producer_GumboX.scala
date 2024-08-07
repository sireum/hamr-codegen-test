// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
object Producer_p_producer_GumboX {
  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param api_d_event_out outgoing event port
    * @param api_b_event_data_out outgoing event data port
    * @param api_c_event_data_out outgoing event data port
    * @param api_a_data_out outgoing data port
    */
  @strictpure def inititialize_IEP_Post (
      api_d_event_out: Option[art.Empty],
      api_b_event_data_out: Option[ProdConsFlows.Container_i],
      api_c_event_data_out: Option[ProdConsFlows.Container_i],
      api_a_data_out: ProdConsFlows.Container_i): B =
    (// D-Inv-Guard: Datatype invariants for the types associated with producer's state variables and outgoing ports
     ProdConsFlows.Container_i.D_Inv_Guard_Container_i(api_b_event_data_out) &
     ProdConsFlows.Container_i.D_Inv_Guard_Container_i(api_c_event_data_out) &
     ProdConsFlows.Container_i.D_Inv_Container_i(api_a_data_out))

  /** IEP-Post: Initialize Entrypoint Post-Condition via container
    *
    * @param post Container holding the value of incoming ports and the pre-state values of state variables
    */
  @strictpure def inititialize_IEP_Post_Container (post: Producer_p_producer_PostState_Container_PS): B =
    inititialize_IEP_Post (
      api_d_event_out = post.api_d_event_out,
      api_b_event_data_out = post.api_b_event_data_out,
      api_c_event_data_out = post.api_c_event_data_out,
      api_a_data_out = post.api_a_data_out)

  /** CEP-Post: Compute Entrypoint Post-Condition for producer
    *
    * @param api_d_event_out outgoing event port
    * @param api_b_event_data_out outgoing event data port
    * @param api_c_event_data_out outgoing event data port
    * @param api_a_data_out outgoing data port
    */
  @strictpure def compute_CEP_Post (
      api_d_event_out: Option[art.Empty],
      api_b_event_data_out: Option[ProdConsFlows.Container_i],
      api_c_event_data_out: Option[ProdConsFlows.Container_i],
      api_a_data_out: ProdConsFlows.Container_i): B =
    (// D-Inv-Guard: Datatype invariants for the types associated with producer's state variables and outgoing ports
     ProdConsFlows.Container_i.D_Inv_Guard_Container_i(api_b_event_data_out) & 
     ProdConsFlows.Container_i.D_Inv_Guard_Container_i(api_c_event_data_out) & 
     ProdConsFlows.Container_i.D_Inv_Container_i(api_a_data_out))

  /** CEP-Post: Compute Entrypoint Post-Condition for producer via containers
    *
    * @param pre Container holding the values of incoming ports and the pre-state values of state variables
    * @param post Container holding the values of outgoing ports and the post-state values of state variables
    */
  @strictpure def compute_CEP_Post_Container(
      pre: Producer_p_producer_PreState_Container_PS,
      post: Producer_p_producer_PostState_Container_PS): B =
    compute_CEP_Post(
      api_d_event_out = post.api_d_event_out,
      api_b_event_data_out = post.api_b_event_data_out,
      api_c_event_data_out = post.api_c_event_data_out,
      api_a_data_out = post.api_a_data_out)
}
