// #Sireum

package slang.BuildingControl

import org.sireum._
import slang._

// This file will not be overwritten so is safe to edit
object Fan_i_tcp_fan {

  def initialise(api: Fan_i_Initialization_Api): Unit = {
    // example api usage

    api.logInfo("Example info logging")
    api.logDebug("Example debug logging")
    api.logError("Example error logging")

    api.put_fanAck(BuildingControl.FanAck.byOrdinal(0).get)
  }

  def handle_fanCmd(api: Fan_i_Operational_Api, value : BuildingControl.FanCmd.Type): Unit = {
    api.logInfo("example handle_fanCmd implementation")
    api.logInfo(s"received ${value}")
    // example api usage

    val apiUsage_fanCmd: Option[BuildingControl.FanCmd.Type] = api.get_fanCmd()
    api.logInfo(s"Received on fanCmd: ${apiUsage_fanCmd}")
  }

  def activate(api: Fan_i_Operational_Api): Unit = { }

  def deactivate(api: Fan_i_Operational_Api): Unit = { }

  def finalise(api: Fan_i_Operational_Api): Unit = { }

  def recover(api: Fan_i_Operational_Api): Unit = { }
}
