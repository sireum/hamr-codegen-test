// #Sireum

package slang.BuildingControl

import org.sireum._
import slang._

// This file was auto-generated.  Do not edit

object Temperature_impl {
  def example(): BuildingControl.Temperature_impl = {
    return BuildingControl.Temperature_impl(Base_Types.Float_32_example(), BuildingControl.TempUnit.byOrdinal(0).get)
  }
}

@datatype class Temperature_impl(
  degrees : F32,
  unit : BuildingControl.TempUnit.Type) {
}

object Temperature_impl_Payload {
  def example(): Temperature_impl_Payload = {
    return Temperature_impl_Payload(BuildingControl.Temperature_impl.example())
  }
}

@datatype class Temperature_impl_Payload(value: BuildingControl.Temperature_impl) extends art.DataContent
