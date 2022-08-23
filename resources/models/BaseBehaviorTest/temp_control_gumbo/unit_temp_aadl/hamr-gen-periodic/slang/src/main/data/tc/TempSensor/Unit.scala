// #Sireum

package tc.TempSensor

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit

@enum object Unit {
  "Kelvin"
  "Celsius"
  "Fahrenheit"
}

object Unit_Payload {
  def example(): Unit_Payload = {
    return Unit_Payload(TempSensor.Unit.byOrdinal(0).get)
  }
}

@datatype class Unit_Payload(value: TempSensor.Unit.Type) extends art.DataContent
