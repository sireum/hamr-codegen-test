// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit
object Temperature_i_GumboX {
  /** invariant AbsZero
    */
  @strictpure def AbsZero_Invariant(value: TempSensor.Temperature_i): B =
    value.degrees >= -459.67f

  @strictpure def Temperature_i_Invariant(value: TempSensor.Temperature_i): B =
    AbsZero_Invariant(value)
}