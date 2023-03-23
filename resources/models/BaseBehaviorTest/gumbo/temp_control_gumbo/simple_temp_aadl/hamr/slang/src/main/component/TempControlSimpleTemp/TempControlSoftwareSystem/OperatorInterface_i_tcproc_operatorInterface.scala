// #Sireum #Logika

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file will not be overwritten so is safe to edit
object OperatorInterface_i_tcproc_operatorInterface {
  //===============================================
  //  C o m p o n e n t    L o c a l    S t a t e
  //===============================================

  // -- S e t  P o i n t
  //     ...holds the current set point values (both low and high set points).
  //     This will be the most recent set points received over the setPoint in event data port
  //     (from the operator interface) or the initial (default) set points if no
  //     setpoints have been received yet.
  //
  // Note: Slang requires all declared variables to be initialized, so initialize to initial
  //    value even though the Initialize Entry Point should also do this.
  var dispatch_count: Z = 0

  //=================================================
  //  I n i t i a l i z e    E n t r y    P o i n t
  //=================================================
  def initialise(api: OperatorInterface_i_Initialization_Api): Unit = {
    // The Initialize Entry Point must initialize all component local state and all output data ports.

    // initialize component local state
    //   (no component local state to initialize)

    // initialize output data ports
    //   (no output data ports to initialize)
  }

  //=================================================
  //  C o m p u t e    E n t r y    P o i n t
  //=================================================
  def timeTriggered(api: OperatorInterface_i_Operational_Api): Unit = {
    // currently we are simulating the operator interface

    // increment the dispatch_count
    dispatch_count = dispatch_count + 1

    // report (via logging the current values of input ports)
    val apiUsage_currentTemp: Option[TempSensor.Temperature_i] = api.get_currentTemp()
    api.logInfo(s"Received on currentTemp: ${apiUsage_currentTemp}")
    val apiUsage_tempChanged: Option[art.Empty] = api.get_tempChanged()
    api.logInfo(s"Received on tempChanged: ${apiUsage_tempChanged}")

    // when we have had 10 dispatches, send another set point
    // structure to the temperature controller, and reset dispatch count

    if (dispatch_count == 10) {
      val newSetPoint: SetPoint_i = Defs.initialSetPoint
      api.put_setPoint(newSetPoint)
      api.logInfo(s"Send set point from Operator Interface: ${newSetPoint}")
      dispatch_count = 0
    }
  }

  //=================================================
  //  AADL entry points below are unused
  //=================================================
  def activate(api: OperatorInterface_i_Operational_Api): Unit = { }

  def deactivate(api: OperatorInterface_i_Operational_Api): Unit = { }

  def finalise(api: OperatorInterface_i_Operational_Api): Unit = { }

  def recover(api: OperatorInterface_i_Operational_Api): Unit = { }
}