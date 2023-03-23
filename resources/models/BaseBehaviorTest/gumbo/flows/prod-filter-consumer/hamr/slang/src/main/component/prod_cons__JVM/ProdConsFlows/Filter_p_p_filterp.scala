// #Sireum #Logika

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Filter_p_p_filterp {

  // BEGIN STATE VARS
  var last_a_in: Base_Types.Float_32 = Base_Types.Float_32_example()

  var last_b_in: Base_Types.Float_32 = Base_Types.Float_32_example()
  // END STATE VARS

  def initialise(api: Filter_p_Initialization_Api): Unit = {
    Contract(
      Modifies(api)
    )
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_a_out(Base_Types.Float_32_example())
    api.put_b_out(Base_Types.Float_32_example())
  }

  def compute(a_in: F32): Unit = {
    Contract(
      Modifies(last_a_in),
      Ensures(last_a_in == In(last_a_in) + 1f),
      InfoFlows(
        Flow("m1 a",
          From(last_a_in),
          To(last_a_in)
        )
      )
    )
    last_a_in = last_a_in + 1f
  }

  def timeTriggered(api: Filter_p_Operational_Api): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES timeTriggered
        // assume AADL_Requirement
        //   All outgoing event data ports must be empty
        api.a_out.isEmpty,
        api.b_out.isEmpty
        // END COMPUTE REQUIRES timeTriggered
      ),
      Modifies(api, last_a_in),
      //Ensures(F),
      InfoFlows(
        // BEGIN COMPUTE FLOW filterp
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
        // END COMPUTE FLOW filterp
      )
    )
    // example api usage

    val apiUsage_a_in: Option[Base_Types.Float_32] = api.get_a_in()
    api.logInfo(s"Received on a_in: ${apiUsage_a_in}")
    val apiUsage_b_in: Option[Base_Types.Float_32] = api.get_b_in()
    api.logInfo(s"Received on b_in: ${apiUsage_b_in}")

    var i: Z = 10

    while(i > 0) {
      Invariant(
        Modifies(last_a_in, i),
        i >= 0,
        InfoFlowInvariant(
          FlowCase("a_channel",
            InAgree(api.a_in, last_a_in),
            OutAgree(last_a_in)
          )
        )
      )
      last_a_in = last_a_in + api.get_a_in().get
      compute(api.get_a_in().get)
      i = i - 1
    }
    api.put_a_out(last_a_in)
  }

  def activate(api: Filter_p_Operational_Api): Unit = { }

  def deactivate(api: Filter_p_Operational_Api): Unit = { }

  def finalise(api: Filter_p_Operational_Api): Unit = { }

  def recover(api: Filter_p_Operational_Api): Unit = { }
}
