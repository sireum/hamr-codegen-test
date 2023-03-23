// #Sireum #Logika

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Producer_p_producer {
var x: F32 = 3f
  def initialise(api: Producer_Initialization_Api): Unit = {
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

  def timeTriggered(api: Producer_Operational_Api): Unit = {
    Contract(
      Requires(
        // BEGIN COMPUTE REQUIRES timeTriggered
        // assume AADL_Requirement
        //   All outgoing event data ports must be empty
        api.a_out.isEmpty,
        api.b_out.isEmpty
        // END COMPUTE REQUIRES timeTriggered
      ),
      Modifies(api, x),
      InfoFlows(
        // BEGIN COMPUTE FLOW producer
        // infoflow a_source
        //   Producer is the source a flow
        Flow("a_source",
          From(),
          To(api.a_out)
        ),
        // infoflow b_source
        //   Producer is the source of a flow
        Flow("b_source",
          From(),
          To(api.b_out)
        )
        // END COMPUTE FLOW producer
      )
    )
    x = 1f
    // example api usage
    api.put_b_out(x)
    api.put_a_out(70f)
  }

  def activate(api: Producer_Operational_Api): Unit = { }

  def deactivate(api: Producer_Operational_Api): Unit = { }

  def finalise(api: Producer_Operational_Api): Unit = { }

  def recover(api: Producer_Operational_Api): Unit = { }
}
