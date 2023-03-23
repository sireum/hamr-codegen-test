// #Sireum

package a.Arrays

import org.sireum._
import art._
import a._

@sig trait Producer_Api {
  def id: Art.BridgeId
  def coordinates_Id : Art.PortId
  def vector_of_coordinates_Id : Art.PortId
  def integers_Id : Art.PortId

  // Logika spec var representing port state for outgoing event data port
  @spec var coordinates: Option[Arrays.Array_of_Coordinates] = $

  def put_coordinates(value : Arrays.Array_of_Coordinates) : Unit = {
    Contract(
      Modifies(coordinates),
      Ensures(
        coordinates == Some(value)
      )
    )
    Spec {
      coordinates = Some(value)
    }

    Art.putValue(coordinates_Id, Arrays.Array_of_Coordinates_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var vector_of_coordinates: Option[Arrays.Vector_of_Coordinates] = $

  def put_vector_of_coordinates(value : Arrays.Vector_of_Coordinates) : Unit = {
    Contract(
      Modifies(vector_of_coordinates),
      Ensures(
        vector_of_coordinates == Some(value)
      )
    )
    Spec {
      vector_of_coordinates = Some(value)
    }

    Art.putValue(vector_of_coordinates_Id, Arrays.Vector_of_Coordinates_Payload(value))
  }

  // Logika spec var representing port state for outgoing event data port
  @spec var integers: Option[Arrays.Array_of_Integers] = $

  def put_integers(value : Arrays.Array_of_Integers) : Unit = {
    Contract(
      Modifies(integers),
      Ensures(
        integers == Some(value)
      )
    )
    Spec {
      integers = Some(value)
    }

    Art.putValue(integers_Id, Arrays.Array_of_Integers_Payload(value))
  }

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

@datatype class Producer_Initialization_Api (
  val id: Art.BridgeId,
  val coordinates_Id : Art.PortId,
  val vector_of_coordinates_Id : Art.PortId,
  val integers_Id : Art.PortId) extends Producer_Api

@datatype class Producer_Operational_Api (
  val id: Art.BridgeId,
  val coordinates_Id : Art.PortId,
  val vector_of_coordinates_Id : Art.PortId,
  val integers_Id : Art.PortId) extends Producer_Api {

}
