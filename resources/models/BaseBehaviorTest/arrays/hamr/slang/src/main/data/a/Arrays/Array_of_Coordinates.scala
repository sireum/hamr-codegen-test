// #Sireum

package a.Arrays

import org.sireum._
import a._

// This file was auto-generated.  Do not edit

object Array_of_Coordinates {
  // Import I's interpolator to create instances of I.  For e.g.,
  //   import Arrays.Array_of_Coordinates.I._
  //   object Example {
  //     val value: Arrays.Array_of_Coordinates.I = i"0"
  //     ...

  @range(min = 0, max = 2, index = T) class I

  // Import and rename the following when using multiple <array-def>.I indexing types in the same context.  For e.g.
  //   import Arrays.Array_of_Coordinates.{i => i0}
  //   import <other-array-def>.{i => i1}
  //   object Example {
  //     val value: Arrays.Array_of_Coordinates.I = i0(0)
  //     ...

  @pure def i(value: Z): I = {
    Contract(Requires(0 <= value && value <= 2))
    return I(value.string).get
  }

  def example(): Arrays.Array_of_Coordinates = {
    return Arrays.Array_of_Coordinates(
      value = IS.create[I, Arrays.Coordinate_Impl](3, Arrays.Coordinate_Impl.example()))
  }
}

@datatype class Array_of_Coordinates(
  val value: IS[Array_of_Coordinates.I, Arrays.Coordinate_Impl]) {
}

object Array_of_Coordinates_Payload {
  def example(): Array_of_Coordinates_Payload = {
    return Array_of_Coordinates_Payload(Arrays.Array_of_Coordinates.example())
  }
}

@datatype class Array_of_Coordinates_Payload(value: Arrays.Array_of_Coordinates) extends art.DataContent
