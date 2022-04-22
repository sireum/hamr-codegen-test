// #Sireum

package slang.BuildingControl

import org.sireum._
import slang._

// This file was auto-generated.  Do not edit

@enum object FanCmd {
  "On"
  "Off"
}

object FanCmd_Payload {
  def example(): FanCmd_Payload = {
    return FanCmd_Payload(BuildingControl.FanCmd.byOrdinal(0).get)
  }
}

@datatype class FanCmd_Payload(value: BuildingControl.FanCmd.Type) extends art.DataContent
