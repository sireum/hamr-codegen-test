// #Sireum

package a.Arrays

import org.sireum._
import a._

// This file was auto-generated.  Do not edit

object Coordinate_Impl {
  def example(): Arrays.Coordinate_Impl = {
    return Arrays.Coordinate_Impl(
      latitude = Base_Types.Integer_32_example(),
      longitude = Base_Types.Integer_32_example(),
      altitude = Base_Types.Integer_32_example())
  }
}

@datatype class Coordinate_Impl(
  val latitude: S32,
  val longitude: S32,
  val altitude: S32) {
}

object Coordinate_Impl_Payload {
  def example(): Coordinate_Impl_Payload = {
    return Coordinate_Impl_Payload(Arrays.Coordinate_Impl.example())
  }
}

@datatype class Coordinate_Impl_Payload(value: Arrays.Coordinate_Impl) extends art.DataContent
