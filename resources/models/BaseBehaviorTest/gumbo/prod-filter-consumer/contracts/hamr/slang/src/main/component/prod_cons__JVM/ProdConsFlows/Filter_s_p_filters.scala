// #Sireum #Logika

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Filter_s_p_filters {

  def initialise(api: Filter_s_Initialization_Api): Unit = {
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
        //   Perhaps this should be a built-in emitted check.
        api.e_data_out.value == 7
        // END INITIALIZES ENSURES
      )
    )
    api.put_e_data_out(Container_i(7))
    api.logInfo("Filter Sporadic initialize: placed 5 on outgoing data port")
  }

  def handle_b_event_data_in(api: Filter_s_Operational_Api, value: ProdConsFlows.Container_i): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES b_event_data_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.b_event_data_in.nonEmpty &&
        api.b_event_data_in.get == value,
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.f_event_data_out.isEmpty,
        api.g_event_data_out.isEmpty,
        api.h_event_out.isEmpty
        // END COMPUTE REQUIRES b_event_data_in
      ),
      Modifies(api),
      Ensures(
        // BEGIN COMPUTE ENSURES b_event_data_in
        // guarantees propagate_b
        //   If an event was received on b then it's value
        //   is propagated to f
        api.f_event_data_out.nonEmpty &&
          api.f_event_data_out.get == api.b_event_data_in.get
        // END COMPUTE ENSURES b_event_data_in
      )
    )

    // FIXME?
    //    need to add the following assert in order for Logika to prove that the passed in value
    //    satisfies f's integration constraint
    assert (api.get_b_event_data_in().get.value > 8)

    //assert (value.value > 8)

    api.put_f_event_data_out(value)
  }

  def handle_c_event_data_in(api: Filter_s_Operational_Api, value: ProdConsFlows.Container_i): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES c_event_data_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.c_event_data_in.nonEmpty &&
        api.c_event_data_in.get == value,
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.f_event_data_out.isEmpty,
        api.g_event_data_out.isEmpty,
        api.h_event_out.isEmpty
        // END COMPUTE REQUIRES c_event_data_in
      )
    )

  }

  def handle_d_event_in(api: Filter_s_Operational_Api): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES d_event_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty
        api.d_event_in.nonEmpty,
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.f_event_data_out.isEmpty,
        api.g_event_data_out.isEmpty,
        api.h_event_out.isEmpty
        // END COMPUTE REQUIRES d_event_in
      )
    )
  }

  def activate(api: Filter_s_Operational_Api): Unit = { }

  def deactivate(api: Filter_s_Operational_Api): Unit = { }

  def finalise(api: Filter_s_Operational_Api): Unit = { }

  def recover(api: Filter_s_Operational_Api): Unit = { }
}
