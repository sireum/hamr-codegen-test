// #Sireum

package a.Arrays

import org.sireum._
import a._

import Array_of_Integers.I._          // can only import one I's interpolator
import Array_of_Integers.{i => ii}    // alternative is to rename the I's helper methods
import Array_of_Coordinates.{i => ic}

// This file will not be overwritten so is safe to edit
object Consumer_proc_consumer {

  def initialise(api: Consumer_Initialization_Api): Unit = {}

  def handle_coordinates(api: Consumer_Operational_Api, value : Arrays.Array_of_Coordinates): Unit = {
    println("example handle_coordinates implementation")
    println(s"received ${value}")

    println(s"The 2nd value using helper method: ${value.value(ic(1))}")
    println()
  }

  def handle_integers(api: Consumer_Operational_Api, value : Arrays.Array_of_Integers): Unit = {
    println("example handle_integers implementation")
    println(s"received ${value}")

    println(s"The 1st value using interpolator: ${value.value(i"0")}")
    println(s"The 1st value using helper method: ${value.value(ii(0))}")
    println()
  }

  def handle_vector_of_coordinates(api: Consumer_Operational_Api, value: Arrays.Vector_of_Coordinates): Unit = {
    println("example handle_vector_of_coordinates implementation")
    println(s"received ${value}")
    println()
  }

  def activate(api: Consumer_Operational_Api): Unit = { }

  def deactivate(api: Consumer_Operational_Api): Unit = { }

  def finalise(api: Consumer_Operational_Api): Unit = { }

  def recover(api: Consumer_Operational_Api): Unit = { }
}
