package a.Arrays

import org.sireum._
import art.{ArtNative_Ext, Empty}
import a._

// This file was auto-generated.  Do not edit
abstract class Consumer_proc_consumer_TestApi extends BridgeTestSuite[Consumer_proc_consumer_Bridge](Arch.PC_Sys_Impl_Instance_proc_consumer) {

  /** helper function to set the values of all input ports.
   * @param coordinates payloads for event data port coordinates.
   *   ART currently supports single element event data queues so
   *   only the last element of coordinates will be used
   * @param vector_of_coordinates payloads for event data port vector_of_coordinates.
   *   ART currently supports single element event data queues so
   *   only the last element of vector_of_coordinates will be used
   * @param integers payloads for event data port integers.
   *   ART currently supports single element event data queues so
   *   only the last element of integers will be used
   */
  def put_concrete_inputs(coordinates : ISZ[Arrays.Array_of_Coordinates],
                          vector_of_coordinates : ISZ[Arrays.Vector_of_Coordinates],
                          integers : ISZ[Arrays.Array_of_Integers]): Unit = {
    for(v <- coordinates){
      put_coordinates(v)
    }
    for(v <- vector_of_coordinates){
      put_vector_of_coordinates(v)
    }
    for(v <- integers){
      put_integers(v)
    }
  }


  // setter for in EventDataPort
  def put_coordinates(value : Arrays.Array_of_Coordinates): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.coordinates_Id, Arrays.Array_of_Coordinates_Payload(value))
  }

  // setter for in EventDataPort
  def put_vector_of_coordinates(value : Arrays.Vector_of_Coordinates): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.vector_of_coordinates_Id, Arrays.Vector_of_Coordinates_Payload(value))
  }

  // setter for in EventDataPort
  def put_integers(value : Arrays.Array_of_Integers): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.integers_Id, Arrays.Array_of_Integers_Payload(value))
  }

}