// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM.util.Profile
import prod_cons__JVM.util.EmptyContainer
import prod_cons__JVM.RandomLib

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Profile for initialise entrypoint
@msig trait Consumer_p_consumer_Profile_Trait extends Profile

@record class Consumer_p_consumer_Profile (
  val name: String,
) extends Consumer_p_consumer_Profile_Trait {

  override def next: EmptyContainer = {
    return EmptyContainer()
  }
}

// Profile with generators for incoming ports
@msig trait Consumer_p_consumer_Profile_P_Trait extends Profile {
  def api_h_event_in: RandomLib // random lib for generating art.Empty
  def api_f_event_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  def api_g_event_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  def api_e_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
}

@record class Consumer_p_consumer_Profile_P(
  val name: String,
  var api_h_event_in: RandomLib, // random lib for generating art.Empty
  var api_f_event_data_in: RandomLib, // random lib for generating ProdConsFlows.Container_i
  var api_g_event_data_in: RandomLib, // random lib for generating ProdConsFlows.Container_i
  var api_e_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  ) extends Consumer_p_consumer_Profile_P_Trait {

  override def next: Consumer_p_consumer_PreState_Container_P = {
    return (Consumer_p_consumer_PreState_Container_P (
      api_h_event_in = api_h_event_in.nextOption_artEmpty(),
      api_f_event_data_in = api_f_event_data_in.nextOptionProdConsFlowsContainer_i(),
      api_g_event_data_in = api_g_event_data_in.nextOptionProdConsFlowsContainer_i(),
      api_e_data_in = api_e_data_in.nextProdConsFlowsContainer_i()))
  }
}

// Profile with generators for state variables and incoming ports
@msig trait Consumer_p_consumer_Profile_PS_Trait extends Consumer_p_consumer_Profile_P_Trait {
  def api_h_event_in: RandomLib // random lib for generating art.Empty
  def api_f_event_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  def api_g_event_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  def api_e_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
}

@record class Consumer_p_consumer_Profile_PS(
  val name: String,
  var api_h_event_in: RandomLib, // random lib for generating art.Empty
  var api_f_event_data_in: RandomLib, // random lib for generating ProdConsFlows.Container_i
  var api_g_event_data_in: RandomLib, // random lib for generating ProdConsFlows.Container_i
  var api_e_data_in: RandomLib // random lib for generating ProdConsFlows.Container_i
  ) extends Consumer_p_consumer_Profile_PS_Trait {

  override def next: Consumer_p_consumer_PreState_Container_PS = {
    return (Consumer_p_consumer_PreState_Container_PS (
      api_h_event_in = api_h_event_in.nextOption_artEmpty(),
      api_f_event_data_in = api_f_event_data_in.nextOptionProdConsFlowsContainer_i(),
      api_g_event_data_in = api_g_event_data_in.nextOptionProdConsFlowsContainer_i(),
      api_e_data_in = api_e_data_in.nextProdConsFlowsContainer_i()))
  }
}