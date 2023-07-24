// #Sireum #Logika
// @ Logika: --par --par-branch-mode all --par-branch --strictpure-mode flip --timeout 7

// FIXME 'flipping' globablly leads to encoding errors like
//; Output:
//; (error "line 2565 column 17: unknown constant l:e_data_out:prod_cons__JVM.ProdConsFlows.Filter_p_Api.e_gt_6")

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Filter_p_p_filterp {

  def initialise(api: Filter_p_Initialization_Api): Unit = {
    Contract(
      Requires(
        // BEGIN INITIALIZES REQUIRES
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.f_event_data_out.isEmpty,
        api.g_event_data_out.isEmpty,
        api.h_event_out.isEmpty
        // END INITIALIZES REQUIRES
      ),
      Modifies(api),
      Ensures(
        // BEGIN INITIALIZES ENSURES
        // guarantee e_data_out_initializes
        //   Must initialize outgoing data ports.
        //   Perhaps this should be a built-in emitted Logika check
        //   to match GUMBOX. e.g., GUMBOX adds post checks
        //   that ensures all outgoing data/event-data ports satisify
        //   data type invariants and/or integration constraints
        //   regardless of whether a component has contracts
        api.e_data_out.value == 7
        // END INITIALIZES ENSURES
      )
    )
    api.put_e_data_out(Container_i(7))
    api.logInfo("Periodic Filter init: Placed 7 on outgoing data port")
  }

  def timeTriggered(api: Filter_p_Operational_Api): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES timeTriggered
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.f_event_data_out.isEmpty,
        api.g_event_data_out.isEmpty,
        api.h_event_out.isEmpty
        // END COMPUTE REQUIRES timeTriggered
      ),
      Modifies (api),
      Ensures(
        // BEGIN COMPUTE ENSURES timeTriggered
        // case data_in
        //   a_data_in 'flows to' e_data_out
        (T) -->: (api.a_data_in == api.e_data_out),
        // case b_event_data
        //   If an event was received on b then its value
        //   is propagated to f
        (api.b_event_data_in.nonEmpty) -->: (api.f_event_data_out.nonEmpty &&
          api.f_event_data_out.get.value == api.b_event_data_in.get.value)
        // END COMPUTE ENSURES timeTriggered
      )
    )
    api.put_e_data_out(api.get_a_data_in().get)

    api.logInfo("Periodic Filter compute: Placed a_data_in on e_data_out as per contract")

    if (api.get_b_event_data_in().nonEmpty) {

      // without 'flipping' smt can't deduce the following and thus can't show b's value satisfies f's
      // integration constraint
      //assert (api.get_b_event_data_in().get.value > 8)

      // can't do global 'flipping' but local flipping allows smt to prove b's value satisfies f's integration constraint
      setOptions("Logika", """--par --par-branch-mode all --par-branch --strictpure-mode flip --timeout 7""")

      api.put_f_event_data_out(api.get_b_event_data_in().get)
      api.logInfo("Periodic Filter compute: b_event_data_in nonEmpty so placed it on f_event_data_out")

      // the merging of the if/else branch causes smt to return unknown for
      // the ensures part of the b_event_data case. Workaround is to add a
      // return statement to avoid the merging.
      return
    }
  }

  def activate(api: Filter_p_Operational_Api): Unit = { }

  def deactivate(api: Filter_p_Operational_Api): Unit = { }

  def finalise(api: Filter_p_Operational_Api): Unit = { }

  def recover(api: Filter_p_Operational_Api): Unit = { }
}
