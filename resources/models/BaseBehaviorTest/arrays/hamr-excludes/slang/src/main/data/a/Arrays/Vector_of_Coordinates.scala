// #Sireum

package a.Arrays

import org.sireum._
import a._

// This file was auto-generated.  Do not edit

object Vector_of_Coordinates {
  def example(): Arrays.Vector_of_Coordinates = {
    return Arrays.Vector_of_Coordinates(
      value = ISZ(Base_Types.Integer_example()))
  }
}

@datatype class Vector_of_Coordinates(
  val value: ISZ[Z]) {
}

object Vector_of_Coordinates_Payload {
  def example(): Vector_of_Coordinates_Payload = {
    return Vector_of_Coordinates_Payload(Arrays.Vector_of_Coordinates.example())
  }
}

@datatype class Vector_of_Coordinates_Payload(value: Arrays.Vector_of_Coordinates) extends art.DataContent