package a.Arrays

import org.sireum._
import art.{ArtNative_Ext, Empty}
import a._

// This file was auto-generated.  Do not edit
abstract class Producer_proc_producer_TestApi extends BridgeTestSuite[Producer_proc_producer_Bridge](Arch.PC_Sys_Impl_Instance_proc_producer) {

  /** helper function to check Producer_proc_producer's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param coordinates method that will be called with the payloads to be sent
   *        on the outgoing event data port 'coordinates'.
   * @param vector_of_coordinates method that will be called with the payloads to be sent
   *        on the outgoing event data port 'vector_of_coordinates'.
   * @param integers method that will be called with the payloads to be sent
   *        on the outgoing event data port 'integers'.
   */
  def check_concrete_output(coordinates: ISZ[Arrays.Array_of_Coordinates] => B = coordinatesParam => {T},
                            vector_of_coordinates: ISZ[Arrays.Vector_of_Coordinates] => B = vector_of_coordinatesParam => {T},
                            integers: ISZ[Arrays.Array_of_Integers] => B = integersParam => {T}): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    var coordinatesValue: ISZ[Arrays.Array_of_Coordinates] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_coordinates().nonEmpty) coordinatesValue = coordinatesValue :+ get_coordinates().get
    if(!coordinates(coordinatesValue)) {
      testFailures = testFailures :+ st"'coordinates' did not match expected: received ${coordinatesValue.size} events with the following payloads ${coordinatesValue}"
    }
    var vector_of_coordinatesValue: ISZ[Arrays.Vector_of_Coordinates] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_vector_of_coordinates().nonEmpty) vector_of_coordinatesValue = vector_of_coordinatesValue :+ get_vector_of_coordinates().get
    if(!vector_of_coordinates(vector_of_coordinatesValue)) {
      testFailures = testFailures :+ st"'vector_of_coordinates' did not match expected: received ${vector_of_coordinatesValue.size} events with the following payloads ${vector_of_coordinatesValue}"
    }
    var integersValue: ISZ[Arrays.Array_of_Integers] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_integers().nonEmpty) integersValue = integersValue :+ get_integers().get
    if(!integers(integersValue)) {
      testFailures = testFailures :+ st"'integers' did not match expected: received ${integersValue.size} events with the following payloads ${integersValue}"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // getter for out EventDataPort
  def get_coordinates(): Option[Arrays.Array_of_Coordinates] = {
    val value: Option[Arrays.Array_of_Coordinates] = get_coordinates_payload() match {
      case Some(Arrays.Array_of_Coordinates_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port coordinates.  Expecting 'Arrays.Array_of_Coordinates_Payload' but received ${v}")
      case _ => None[Arrays.Array_of_Coordinates]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_coordinates_payload(): Option[Arrays.Array_of_Coordinates_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.coordinates_Id).asInstanceOf[Option[Arrays.Array_of_Coordinates_Payload]]
  }

  // getter for out EventDataPort
  def get_vector_of_coordinates(): Option[Arrays.Vector_of_Coordinates] = {
    val value: Option[Arrays.Vector_of_Coordinates] = get_vector_of_coordinates_payload() match {
      case Some(Arrays.Vector_of_Coordinates_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port vector_of_coordinates.  Expecting 'Arrays.Vector_of_Coordinates_Payload' but received ${v}")
      case _ => None[Arrays.Vector_of_Coordinates]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_vector_of_coordinates_payload(): Option[Arrays.Vector_of_Coordinates_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.vector_of_coordinates_Id).asInstanceOf[Option[Arrays.Vector_of_Coordinates_Payload]]
  }

  // getter for out EventDataPort
  def get_integers(): Option[Arrays.Array_of_Integers] = {
    val value: Option[Arrays.Array_of_Integers] = get_integers_payload() match {
      case Some(Arrays.Array_of_Integers_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port integers.  Expecting 'Arrays.Array_of_Integers_Payload' but received ${v}")
      case _ => None[Arrays.Array_of_Integers]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_integers_payload(): Option[Arrays.Array_of_Integers_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.integers_Id).asInstanceOf[Option[Arrays.Array_of_Integers_Payload]]
  }

}