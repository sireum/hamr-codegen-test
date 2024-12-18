// #Sireum #Logika

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Filter_s_p_filters {

  // BEGIN STATE VARS
  var last_a_in: Base_Types.Float_32 = Base_Types.Float_32_example()

  var last_b_in: Base_Types.Float_32 = Base_Types.Float_32_example()
  // END STATE VARS

  def initialise(api: Filter_s_Initialization_Api): Unit = {
    Contract(
      Requires(
        // BEGIN INITIALIZES REQUIRES
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.a_out.isEmpty,
        api.b_out.isEmpty
        // END INITIALIZES REQUIRES
      ),
      Modifies(api, last_a_in, last_b_in),
      InfoFlows(
        // BEGIN INITIALIZES FLOWS
        // infoflow set_last_a_in
        //   Can also flow to state variable in the initialization phase
        Flow("set_last_a_in",
          From(),
          To(last_a_in)
        ),
        // infoflow set_last_b_in
        //   Can also flow to state variable in the initialization phase
        Flow("set_last_b_in",
          From(),
          To(last_b_in)
        )
        // END INITIALIZES FLOWS
      )
    )
    // example api usage

    last_a_in = 0f
    last_b_in = 0f

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_a_out(Base_Types.Float_32_example())
    api.put_b_out(Base_Types.Float_32_example())
  }

  def handle_a_in(api: Filter_s_Operational_Api, value : Base_Types.Float_32): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES a_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.a_in.nonEmpty &&
        api.a_in.get == value,
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.a_out.isEmpty,
        api.b_out.isEmpty
        // END COMPUTE REQUIRES a_in
      ),
      Modifies(api),
      InfoFlows(
        // BEGIN COMPUTE FLOW a_in
        // infoflow a_channel
        //   A channel
        Flow("a_channel",
          From(api.a_in, last_a_in),
          To(api.a_out)
        ),
        // infoflow b_channel
        //   B channel
        Flow("b_channel",
          From(api.b_in, last_b_in),
          To(api.b_out)
        )
        // END COMPUTE FLOW a_in
      )
    )
    api.logInfo("example handle_a_in implementation")
    api.logInfo(s"received ${value}")
    // example api usage

    val apiUsage_a_in: Option[Base_Types.Float_32] = api.get_a_in()
    api.logInfo(s"Received on a_in: ${apiUsage_a_in}")
    val apiUsage_b_in: Option[Base_Types.Float_32] = api.get_b_in()
    api.logInfo(s"Received on b_in: ${apiUsage_b_in}")
  }

  def handle_b_in(api: Filter_s_Operational_Api, value : Base_Types.Float_32): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES b_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.b_in.nonEmpty &&
        api.b_in.get == value,
        // assume AADL_Requirement
        //   All outgoing event ports must be empty
        api.a_out.isEmpty,
        api.b_out.isEmpty
        // END COMPUTE REQUIRES b_in
      ),
      InfoFlows(
        // BEGIN COMPUTE FLOW b_in
        // infoflow a_channel
        //   A channel
        Flow("a_channel",
          From(api.a_in, last_a_in),
          To(api.a_out)
        ),
        // infoflow b_channel
        //   B channel
        Flow("b_channel",
          From(api.b_in, last_b_in),
          To(api.b_out)
        )
        // END COMPUTE FLOW b_in
      )
    )
    api.logInfo("example handle_b_in implementation")
    api.logInfo(s"received ${value}")
  }

  def activate(api: Filter_s_Operational_Api): Unit = { }

  def deactivate(api: Filter_s_Operational_Api): Unit = { }

  def finalise(api: Filter_s_Operational_Api): Unit = { }

  def recover(api: Filter_s_Operational_Api): Unit = { }
}
