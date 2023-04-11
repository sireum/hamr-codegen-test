// #Sireum

package tc.TempSensor

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object Temperature_i_GumboX {
  /** invariant AbsZero
    */
  @strictpure def AbsZero_Invariant(value: TempSensor.Temperature_i): B =
    GUMBO_Definitions.GUMBO__Library.atLeastAbsoluteZeroRaw(value.degrees, value.unit)

  @strictpure def Temperature_i_Invariant(value: TempSensor.Temperature_i): B =
    AbsZero_Invariant(value)
}