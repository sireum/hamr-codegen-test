// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Consumer_p_consumer {

  def initialise(api: Consumer_Initialization_Api): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

  }

  def handle_f_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {
    api.logInfo("example handle_f_event_data_in implementation")
    api.logInfo(s"  received $value")
    // example api usage

    val apiUsage_e_data_in: Option[ProdConsFlows.Container_i] = api.get_e_data_in()
    api.logInfo(s"Received on data port e_data_in: ${apiUsage_e_data_in}")
    val apiUsage_f_event_data_in: Option[ProdConsFlows.Container_i] = api.get_f_event_data_in()
    api.logInfo(s"Received on event data port f_event_data_in: ${apiUsage_f_event_data_in}")
    val apiUsage_g_event_data_in: Option[ProdConsFlows.Container_i] = api.get_g_event_data_in()
    api.logInfo(s"Received on event data port g_event_data_in: ${apiUsage_g_event_data_in}")
    val apiUsage_h_event_in: Option[art.Empty] = api.get_h_event_in()
    api.logInfo(s"Received on event port h_event_in: ${apiUsage_h_event_in}")
  }

  def handle_g_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {
    api.logInfo("example handle_g_event_data_in implementation")
    api.logInfo(s"  received $value")
  }

  def handle_h_event_in(api: Consumer_Operational_Api): Unit = {
    api.logInfo("example handle_h_event_in implementation")
    api.logInfo("  received event")
  }

  def activate(api: Consumer_Operational_Api): Unit = { }

  def deactivate(api: Consumer_Operational_Api): Unit = { }

  def finalise(api: Consumer_Operational_Api): Unit = { }

  def recover(api: Consumer_Operational_Api): Unit = { }
}
