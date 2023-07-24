// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import prod_cons__JVM._

// This file will not be overwritten so is safe to edit
object Producer_p_producer {

  def initialise(api: Producer_Initialization_Api): Unit = {
    api.put_a_data_out(ProdConsFlows.Container_i(4))
    api.logInfo("Producer initialize: placed 4 on outgoing data port to satisfy the datatype invariant")
  }

  def timeTriggered(api: Producer_Operational_Api): Unit = {
    api.put_a_data_out(ProdConsFlows.Container_i(4))
    api.logInfo("Producer compute: placed 4 on outgoing data port to satisfy the datatype invariant")
  }

  def activate(api: Producer_Operational_Api): Unit = { }

  def deactivate(api: Producer_Operational_Api): Unit = { }

  def finalise(api: Producer_Operational_Api): Unit = { }

  def recover(api: Producer_Operational_Api): Unit = { }
}
