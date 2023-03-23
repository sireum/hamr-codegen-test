// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

object Temperature_i {
  def example(): TempSensor.Temperature_i = {
    return TempSensor.Temperature_i(Base_Types.Float_32_example())
  }
}

@datatype class Temperature_i(
  degrees : F32) {
  @spec def temperature_Inv = Invariant(
    degrees >= -459.67F
  )
}

object Temperature_i_Payload {
  def example(): Temperature_i_Payload = {
    return Temperature_i_Payload(TempSensor.Temperature_i.example())
  }
}

@datatype class Temperature_i_Payload(value: TempSensor.Temperature_i) extends art.DataContent
