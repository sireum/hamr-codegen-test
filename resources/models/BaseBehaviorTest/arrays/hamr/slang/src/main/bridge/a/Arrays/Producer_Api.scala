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

  def put_coordinates(value : Arrays.Array_of_Coordinates) : Unit = {
    Art.putValue(coordinates_Id, Arrays.Array_of_Coordinates_Payload(value))
  }

  def put_vector_of_coordinates(value : Arrays.Vector_of_Coordinates) : Unit = {
    Art.putValue(vector_of_coordinates_Id, Arrays.Vector_of_Coordinates_Payload(value))
  }

  def put_integers(value : Arrays.Array_of_Integers) : Unit = {
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
