// #Sireum

package TempControlSimpleTemp.CoolingFan

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

@enum object FanCmd {
  "On"
  "Off"
}

object FanCmd_Payload {
  def example(): FanCmd_Payload = {
    return FanCmd_Payload(CoolingFan.FanCmd.byOrdinal(0).get)
  }
}

@datatype class FanCmd_Payload(value: CoolingFan.FanCmd.Type) extends art.DataContent
