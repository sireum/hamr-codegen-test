// #Sireum #Logika

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Consumer_p_consumer {

  // BEGIN STATE VARS
  var from_b: Base_Types.Float_32 = Base_Types.Float_32_example()
  // END STATE VARS

  def initialise(api: Consumer_Initialization_Api): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

  }

  def handle_a_in(api: Consumer_Operational_Api, value : Base_Types.Float_32): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES a_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.a_in.nonEmpty &&
        api.a_in.get == value
        // END COMPUTE REQUIRES a_in
      ),
      Modifies(from_b),
      InfoFlows(
        // BEGIN COMPUTE FLOW a_in
        // infoflow a_sink
        //   Consumer is a sink for a_in
        //   The generated sequent will just conclude T since the to clause is empty
        //   so currently sinks are effectively just for documentation.
        Flow("a_sink",
          From(api.a_in),
          To()
        ),
        // infoflow b_sink
        //   Consumer is a sink for b_in
        Flow("b_sink",
          From(api.b_in),
          To(from_b)
        )
        // END COMPUTE FLOW a_in
      )
    )

    from_b = 1f // force both traces to agree on from_b

    api.logInfo("example handle_a_in implementation")
    api.logInfo(s"received ${value}")
    // example api usage

    val apiUsage_a_in: Option[Base_Types.Float_32] = api.get_a_in()
    api.logInfo(s"Received on a_in: ${apiUsage_a_in}")
    val apiUsage_b_in: Option[Base_Types.Float_32] = api.get_b_in()
    api.logInfo(s"Received on b_in: ${apiUsage_b_in}")
  }

  def handle_b_in(api: Consumer_Operational_Api, value : Base_Types.Float_32): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES b_in
        // assume HAMR-Guarantee built-in
        //   The spec var corresponding to the handled event must be non-empty and
        //   the passed in payload must be the same as the spec var's value
        api.b_in.nonEmpty &&
        api.b_in.get == value
        // END COMPUTE REQUIRES b_in
      ),
      InfoFlows(
        // BEGIN COMPUTE FLOW b_in
        // infoflow a_sink
        //   Consumer is a sink for a_in
        //   The generated sequent will just conclude T since the to clause is empty
        //   so currently sinks are effectively just for documentation.
        Flow("a_sink",
          From(api.a_in),
          To()
        ),
        // infoflow b_sink
        //   Consumer is a sink for b_in
        Flow("b_sink",
          From(api.b_in),
          To(from_b)
        )
        // END COMPUTE FLOW b_in
      )
    )
    // assume we have an agreement on from_b at the start of the method
    Deduce (|- (AssumeAgree("b_sink", InAgree(from_b))))

    api.logInfo("example handle_b_in implementation")
    api.logInfo(s"received ${value}")
  }

  def activate(api: Consumer_Operational_Api): Unit = { }

  def deactivate(api: Consumer_Operational_Api): Unit = { }

  def finalise(api: Consumer_Operational_Api): Unit = { }

  def recover(api: Consumer_Operational_Api): Unit = { }
}
