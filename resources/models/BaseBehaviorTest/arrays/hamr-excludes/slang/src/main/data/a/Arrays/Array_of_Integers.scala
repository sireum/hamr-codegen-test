// #Sireum

package a.Arrays

import org.sireum._
import a._

// This file was auto-generated.  Do not edit

object Array_of_Integers {
  // Import I's interpolator to create instances of I.  For e.g.,
  //   import Arrays.Array_of_Integers.I._
  //   object Example {
  //     val value: Arrays.Array_of_Integers.I = i"0"
  //     ...
  //
  // Rename I and use its fromZ method when using multiple <array-def>.I indexing types in the same context.  For e.g.
  //   import Arrays.Array_of_Integers.{I => I0}
  //   import <other-array-def>.{I => I1}
  //   object Example {
  //     val value: Arrays.Array_of_Integers.I = I0.fromZ(0)
  //     ...

  @range(min = 0, max = 0, index = T) class I

  def example(): Arrays.Array_of_Integers = {
    return Arrays.Array_of_Integers(
      value = IS.create[I, Base_Types.Integer](1, Base_Types.Integer_example()))
  }
}

@datatype class Array_of_Integers(
  val value: IS[Array_of_Integers.I, Z]) {
}

object Array_of_Integers_Payload {
  def example(): Array_of_Integers_Payload = {
    return Array_of_Integers_Payload(Arrays.Array_of_Integers.example())
  }
}

@datatype class Array_of_Integers_Payload(value: Arrays.Array_of_Integers) extends art.DataContent