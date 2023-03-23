// #Sireum

package tc.TempSensor

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit

object Temperature_i {
  def example(): TempSensor.Temperature_i = {
    return TempSensor.Temperature_i(
      degrees = Base_Types.Float_32_example(),
      unit = TempSensor.Unit.byOrdinal(0).get)
  }
}

@datatype class Temperature_i(
  val degrees: F32,
  val unit: TempSensor.Unit.Type) {
  @spec def AbsZero = Invariant(
    GUMBO_Definitions.GUMBO__Library.atLeastAbsoluteZeroRaw(degrees, unit)
  )
}

object Temperature_i_Payload {
  def example(): Temperature_i_Payload = {
    return Temperature_i_Payload(TempSensor.Temperature_i.example())
  }
}

@datatype class Temperature_i_Payload(value: TempSensor.Temperature_i) extends art.DataContent
