// #Sireum

package a.Arrays

import org.sireum._
import art._
import a._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

@sig trait Consumer_Api {
  def id: Art.BridgeId
  def coordinates_Id : Art.PortId
  def vector_of_coordinates_Id : Art.PortId
  def integers_Id : Art.PortId


  def logInfo(msg: String): Unit = {
    Art.logInfo(id, msg)
  }

  def logDebug(msg: String): Unit = {
    Art.logDebug(id, msg)
  }

  def logError(msg: String): Unit = {
    Art.logError(id, msg)
  }
}

@datatype class Consumer_Initialization_Api (
  val id: Art.BridgeId,
  val coordinates_Id : Art.PortId,
  val vector_of_coordinates_Id : Art.PortId,
  val integers_Id : Art.PortId) extends Consumer_Api

@datatype class Consumer_Operational_Api (
  val id: Art.BridgeId,
  val coordinates_Id : Art.PortId,
  val vector_of_coordinates_Id : Art.PortId,
  val integers_Id : Art.PortId) extends Consumer_Api {

  // Logika spec var representing port state for incoming event data port
  @spec var coordinates: Option[Arrays.Array_of_Coordinates] = $

  def get_coordinates() : Option[Arrays.Array_of_Coordinates] = {
    Contract(
      Ensures(
        Res == coordinates
      )
    )
    val value : Option[Arrays.Array_of_Coordinates] = Art.getValue(coordinates_Id) match {
      case Some(Arrays.Array_of_Coordinates_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port coordinates.  Expecting 'Arrays.Array_of_Coordinates_Payload' but received ${v}")
        None[Arrays.Array_of_Coordinates]()
      case _ => None[Arrays.Array_of_Coordinates]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var vector_of_coordinates: Option[Arrays.Vector_of_Coordinates] = $

  def get_vector_of_coordinates() : Option[Arrays.Vector_of_Coordinates] = {
    Contract(
      Ensures(
        Res == vector_of_coordinates
      )
    )
    val value : Option[Arrays.Vector_of_Coordinates] = Art.getValue(vector_of_coordinates_Id) match {
      case Some(Arrays.Vector_of_Coordinates_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port vector_of_coordinates.  Expecting 'Arrays.Vector_of_Coordinates_Payload' but received ${v}")
        None[Arrays.Vector_of_Coordinates]()
      case _ => None[Arrays.Vector_of_Coordinates]()
    }
    return value
  }

  // Logika spec var representing port state for incoming event data port
  @spec var integers: Option[Arrays.Array_of_Integers] = $

  def get_integers() : Option[Arrays.Array_of_Integers] = {
    Contract(
      Ensures(
        Res == integers
      )
    )
    val value : Option[Arrays.Array_of_Integers] = Art.getValue(integers_Id) match {
      case Some(Arrays.Array_of_Integers_Payload(v)) => Some(v)
      case Some(v) =>
        Art.logError(id, s"Unexpected payload on port integers.  Expecting 'Arrays.Array_of_Integers_Payload' but received ${v}")
        None[Arrays.Array_of_Integers]()
      case _ => None[Arrays.Array_of_Integers]()
    }
    return value
  }
}
