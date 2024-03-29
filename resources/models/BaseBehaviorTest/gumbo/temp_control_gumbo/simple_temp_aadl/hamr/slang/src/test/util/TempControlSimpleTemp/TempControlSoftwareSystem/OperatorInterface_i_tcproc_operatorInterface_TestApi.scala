package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import art.{ArtNative_Ext, Empty}
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit
abstract class OperatorInterface_i_tcproc_operatorInterface_TestApi extends BridgeTestSuite[OperatorInterface_i_tcproc_operatorInterface_Bridge](Arch.TempControlSoftwareSystem_i_Instance_tcproc_operatorInterface) {

  /** helper function to set the values of all input ports.
   * @param currentTemp payload for data port currentTemp
   * @param tempChanged the number of events to place in the tempChanged event port queue.
   *   ART currently supports single element event queues so at most
   *   one event will be placed in the queue.
   */
  def put_concrete_inputs(currentTemp : TempSensor.Temperature_i,
                          tempChanged : Z): Unit = {
    put_currentTemp(currentTemp)
    for(i <- 0 until tempChanged) {
      put_tempChanged()
    }
  }


  /** helper function to check OperatorInterface_i_tcproc_operatorInterface's
   * output ports.  Use named arguments to check subsets of the output ports.
   * @param setPoint method that will be called with the payloads to be sent
   *        on the outgoing event data port 'setPoint'.
   */
  def check_concrete_output(setPoint: ISZ[TempControlSoftwareSystem.SetPoint_i] => B = setPointParam => {T}): Unit = {
    var testFailures: ISZ[ST] = ISZ()

    var setPointValue: ISZ[TempControlSoftwareSystem.SetPoint_i] = ISZ()
    // TODO: event data port getter should return all of the events/payloads
    //       received on event data ports when queue sizes > 1 support is added
    //       to ART
    if(get_setPoint().nonEmpty) setPointValue = setPointValue :+ get_setPoint().get
    if(!setPoint(setPointValue)) {
      testFailures = testFailures :+ st"'setPoint' did not match expected: received ${setPointValue.size} events with the following payloads ${setPointValue}"
    }

    assert(testFailures.isEmpty, st"${(testFailures, "\n")}".render)
  }


  // setter for in DataPort
  def put_currentTemp(value : TempSensor.Temperature_i): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.currentTemp_Id, TempSensor.Temperature_i_Payload(value))
  }

  // setter for in EventPort
  def put_tempChanged(): Unit = {
    ArtNative_Ext.insertInPortValue(bridge.operational_api.tempChanged_Id, Empty())
  }

  // getter for out EventDataPort
  def get_setPoint(): Option[TempControlSoftwareSystem.SetPoint_i] = {
    val value: Option[TempControlSoftwareSystem.SetPoint_i] = get_setPoint_payload() match {
      case Some(TempControlSoftwareSystem.SetPoint_i_Payload(v)) => Some(v)
      case Some(v) => fail(s"Unexpected payload on port setPoint.  Expecting 'TempControlSoftwareSystem.SetPoint_i_Payload' but received ${v}")
      case _ => None[TempControlSoftwareSystem.SetPoint_i]()
    }
    return value
  }

  // payload getter for out EventDataPort
  def get_setPoint_payload(): Option[TempControlSoftwareSystem.SetPoint_i_Payload] = {
    return ArtNative_Ext.observeOutPortValue(bridge.initialization_api.setPoint_Id).asInstanceOf[Option[TempControlSoftwareSystem.SetPoint_i_Payload]]
  }

}
