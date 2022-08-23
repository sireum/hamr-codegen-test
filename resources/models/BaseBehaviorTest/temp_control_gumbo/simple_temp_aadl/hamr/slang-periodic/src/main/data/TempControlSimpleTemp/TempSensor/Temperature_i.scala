// #Sireum #Logika

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit

object Temperature_i {
  def example(): TempSensor.Temperature_i = {
    Contract(Ensures(Res[Temperature_i].degrees == f32"0"))
    return TempSensor.Temperature_i(Base_Types.Float_32_example())
  }
}

@datatype class Temperature_i(
  degrees : F32) {
  @spec def AbsZero = Invariant(
    degrees >= -459.67f
  )
}

object Temperature_i_Payload {
  def example(): Temperature_i_Payload = {
    return Temperature_i_Payload(TempSensor.Temperature_i.example())
  }
}

@datatype class Temperature_i_Payload(value: TempSensor.Temperature_i) extends art.DataContent
