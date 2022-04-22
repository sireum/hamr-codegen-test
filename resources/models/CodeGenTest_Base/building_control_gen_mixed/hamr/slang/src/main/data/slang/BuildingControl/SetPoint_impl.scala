// #Sireum

package slang.BuildingControl

import org.sireum._
import slang._

// This file was auto-generated.  Do not edit

object SetPoint_impl {
  def example(): BuildingControl.SetPoint_impl = {
    return BuildingControl.SetPoint_impl(BuildingControl.Temperature_impl.example(), BuildingControl.Temperature_impl.example())
  }
}

@datatype class SetPoint_impl(
  low : BuildingControl.Temperature_impl,
  high : BuildingControl.Temperature_impl) {
}

object SetPoint_impl_Payload {
  def example(): SetPoint_impl_Payload = {
    return SetPoint_impl_Payload(BuildingControl.SetPoint_impl.example())
  }
}

@datatype class SetPoint_impl_Payload(value: BuildingControl.SetPoint_impl) extends art.DataContent
