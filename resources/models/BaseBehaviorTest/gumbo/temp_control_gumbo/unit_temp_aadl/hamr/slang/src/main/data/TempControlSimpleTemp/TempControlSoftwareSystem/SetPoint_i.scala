// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

object SetPoint_i {
  def example(): TempControlSoftwareSystem.SetPoint_i = {
    return TempControlSoftwareSystem.SetPoint_i(TempSensor.Temperature_i.example(), TempSensor.Temperature_i.example())
  }
}

@datatype class SetPoint_i(
  low : TempSensor.Temperature_i,
  high : TempSensor.Temperature_i) {
  @spec def currentTemp_Inv = Invariant(
    low.degrees >= 50.0f &
    high.degrees <= 110.0f &
    low.degrees <= high.degrees
  )
}

object SetPoint_i_Payload {
  def example(): SetPoint_i_Payload = {
    return SetPoint_i_Payload(TempControlSoftwareSystem.SetPoint_i.example())
  }
}

@datatype class SetPoint_i_Payload(value: TempControlSoftwareSystem.SetPoint_i) extends art.DataContent
