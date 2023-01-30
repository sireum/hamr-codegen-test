// #Sireum

package a.Arrays

import org.sireum._
import a._

// This file will not be overwritten so is safe to edit
object Consumer_proc_consumer {

  def initialise(api: Consumer_Initialization_Api): Unit = { }

  def handle_coordinates(api: Consumer_Operational_Api, value : Arrays.Array_of_Coordinates): Unit = { }

  def handle_vector_of_coordinates(api: Consumer_Operational_Api, value : Arrays.Vector_of_Coordinates): Unit = { }

  def handle_integers(api: Consumer_Operational_Api, value : Arrays.Array_of_Integers): Unit = { }

  def activate(api: Consumer_Operational_Api): Unit = { }

  def deactivate(api: Consumer_Operational_Api): Unit = { }

  def finalise(api: Consumer_Operational_Api): Unit = { }

  def recover(api: Consumer_Operational_Api): Unit = { }
}
