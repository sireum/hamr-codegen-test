// #Sireum

package a.Arrays

import org.sireum._
import a._

import Array_of_Integers.I._          // can only import one I's interpolator
import Array_of_Integers.{I => II}    // alternative is to rename the Is and use their fromZ method
import Array_of_Coordinates.{I => IC}

// This file will not be overwritten so is safe to edit
object Consumer_proc_consumer {

  def initialise(api: Consumer_Initialization_Api): Unit = {}

  def handle_coordinates(api: Consumer_Operational_Api, value : Arrays.Array_of_Coordinates): Unit = {
    println("example handle_coordinates implementation")
    println(s"received ${value}")

    println(s"Min=${IC.Min}, Max=${IC.Max}, Size=${value.value.size}")

    println(s"Asserting size (${value.value.size}) is equal to I.Max (${IC.Max}) + 1 should succeed")
    assert(value.value.size == IC.Max.toZ + 1)

    println(s"The 2nd value using fromZ: ${value.value(IC.fromZ(1))}")

    println(s"Last value at ${value.value.size} - 1 is ${value.value(IC.fromZ(value.value.size - 1))}")
    println()
  }

  def handle_integers(api: Consumer_Operational_Api, value : Arrays.Array_of_Integers): Unit = {
    println("example handle_integers implementation")
    println(s"received ${value}")

    println(s"The 1st value using interpolator: ${value.value(i"0")}")
    println(s"The 1st value using Min: ${value.value(II.Min)}")
    println(s"The 1st value using fromZ: ${value.value(II.fromZ(0))}")
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
