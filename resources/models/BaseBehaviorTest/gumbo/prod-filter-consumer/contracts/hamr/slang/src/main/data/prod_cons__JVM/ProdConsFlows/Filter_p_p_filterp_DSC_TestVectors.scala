// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

// Test vector containers for Distributed SlangCheck testing

@datatype class Filter_p_p_filterp_DSC_TestVector (
  val api_d_event_in: Option[art.Empty],
  val api_b_event_data_in: Option[ProdConsFlows.Container_i],
  val api_c_event_data_in: Option[ProdConsFlows.Container_i],
  val api_a_data_in: ProdConsFlows.Container_i)