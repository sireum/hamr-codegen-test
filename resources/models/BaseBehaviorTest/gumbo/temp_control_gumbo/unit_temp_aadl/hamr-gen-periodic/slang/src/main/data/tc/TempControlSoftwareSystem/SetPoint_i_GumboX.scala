// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object SetPoint_i_GumboX {
  /** invariant SetPoint_Data_Invariant
    */
  @strictpure def SetPoint_Data_Invariant_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    value.low.degrees >= 50.0f & value.high.degrees <= 110.0f & value.low.degrees <= value.high.degrees

  @strictpure def SetPoint_i_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    SetPoint_Data_Invariant_Invariant(value)
}