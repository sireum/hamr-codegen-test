// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit
object SetPoint_i_GumboX {
  /** invariant SetPointDataInvariant
    *   SetPoint Data Invariant
    */
  @strictpure def SetPointDataInvariant_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    value.low.degrees >= 50.0f & value.high.degrees <= 110.0f & value.low.degrees <= value.high.degrees

  @strictpure def SetPoint_i_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    SetPointDataInvariant_Invariant(value)
}