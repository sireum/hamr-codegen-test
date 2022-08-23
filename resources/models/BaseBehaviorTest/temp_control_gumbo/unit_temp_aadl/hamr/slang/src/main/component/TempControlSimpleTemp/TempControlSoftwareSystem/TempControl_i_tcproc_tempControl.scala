// #Sireum #Logika

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._
import TempControlSimpleTemp.CoolingFan._
import TempControlSimpleTemp.TempSensor._

// This file will not be overwritten so is safe to edit
object TempControl_i_tcproc_tempControl {

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

  var currentSetPoint: SetPoint_i = TempControlSoftwareSystem.Defs.initialSetPoint // Traces to currentSetPoint in AADL TempControl thread
  var currentFanState: FanCmd.Type = TempControlSoftwareSystem.Defs.initialFanState // Traces to currentFanState in AADL TempControl thread

  // private local state - latestTemp is only used to communicate information between main and helper functions, so it does
  // not impact externally visible behavior.
  var latestTemp: TempSensor.Temperature_i = TempSensor.Defs.defaultTemp

  //=================================================
  //  I n i t i a l i z e    E n t r y    P o i n t
  //=================================================
  def initialise(api: TempControl_i_Initialization_Api): Unit = {
    Contract(
      Modifies(currentSetPoint,currentFanState,latestTemp),
      Ensures(
        //currentSetPoint == TempControlSoftwareSystem.Defs.initialSetPoint,
        //currentFanState == TempControlSoftwareSystem.Defs.initialFanState,
        //latestTemp == TempSensor.Defs.defaultTemp
        currentSetPoint == SetPoint_i(Temperature_i(70f), Temperature_i(80f)),
        currentFanState == FanCmd.Off,
        latestTemp == Temperature_i(72f)
      )
    )
    api.logInfo("Initialize Entry Point")

    // The Initialize Entry Point must initialize all component local state and all output data ports.

    // initialize component local state
    //currentSetPoint = TempControlSoftwareSystem.Defs.initialSetPoint
    //currentFanState = TempControlSoftwareSystem.Defs.initialFanState
    //latestTemp = TempSensor.Defs.defaultTemp
    currentSetPoint = SetPoint_i(Temperature_i(70f), Temperature_i(80f))
    currentFanState = FanCmd.Off
    latestTemp = Temperature_i(72f)

    // initialize output data ports
    //  (no output data ports to initialize)
  }

  //=================================================
  //  C o m p u t e    E n t r y    P o i n t
  //
  //  Event handlers for sporadic AADL thread component
  //=================================================

  //------------------------------------------------
  //  f a n A c k   event data handler
  //
  // Handler for event data arriving on fanAck in event data port
  //------------------------------------------------
  def handle_fanAck(api: TempControl_i_Operational_Api, value: CoolingFan.FanAck.Type): Unit = {
    // Contract
    //   Since the fan acknowledge of the fan is not important to the rest of the component's behavior,
    //   we don't need to have a contract here.   The frame reasoning (e.g., lack of a modifies clause)
    //   should be sufficient to allow to us conclude that rest of the control laws in the component
    //   continue to be maintained.
    //   However, for now, due to the "unsmart" treatment of modifies across entry points and general handlers,
    //   we must explicitly list the modifies clauses and frame-conditions.
    Contract(
      Modifies(api,currentSetPoint,currentFanState,latestTemp),
      Ensures(
        api == In(api),  // we could consider this "not quite true" since the fanAck event is dequeued from the input port
        currentSetPoint == In(currentSetPoint),
        currentFanState == In(currentFanState),
        latestTemp == In(latestTemp)
      )
    )
    api.logInfo("received fanAck") // remove for now because Logika cannot handle string interpolation
    if (value == FanAck.Error) {
      // In a more complete implementation, we would implement some sort
      // of mitigation or recovery action at this point.
      // For now, we just log that fan is telling us that it did not
      // respond as expected to the last sent command.
      api.logError("Actuation failed!")
    } else {
      // Log actuation succeeded
      api.logInfo("Actuation worked.")
    }
  }

  //------------------------------------------------
  //  s e t P o i n t   event data handler
  //
  // Handler for event data arriving on setPoint event data port
  //
  //  guarantee ON setPoint: SetPointChanged:
  //     currentSetPoint == setPoint;
  //------------------------------------------------
  def handle_setPoint(api: TempControl_i_Operational_Api, value: TempControlSoftwareSystem.SetPoint_i): Unit = {
    Contract(
      Requires(api.fanCmd == None[FanCmd.Type]()),
      Modifies(api,  // modifies fanCmd output port
               currentSetPoint,
               currentFanState,
               latestTemp),
      Ensures(
      // frame conditions on port variables
      // (this will eventually be unnecessary once read/write notions are implemented and modifies clause is enhanced)
      // current have to "manually" give frame-condition for all input data-like port states
      api.currentTemp == In(api).currentTemp,
      api.setPoint == In(api).setPoint,
      api.fanAck == In(api).fanAck,
      // post-condition - local state (and explicitly stated frame condition for unmodified variables)
      //   Note: the entire contract is identical to that of perform_fan_control except for the clause below,
      //   which updates currentSetPoint
      currentSetPoint == value,
      latestTemp == In(latestTemp),
        // post-conditions - control logic
      (latestTemp.degrees < currentSetPoint.low.degrees) ->:
        (currentFanState == FanCmd.Off),
      (latestTemp.degrees > currentSetPoint.high.degrees) ->:
        (currentFanState == FanCmd.On),
      // The following clause combines the control law logic with the logic for decided if we need to send a fan command
      //  (i.e., did our desired state for fan change).   It might be cleaner (better compositional reasoning) to
      // separate these.
      (latestTemp.degrees >= currentSetPoint.low.degrees & latestTemp.degrees <= currentSetPoint.high.degrees)
        ->: (currentFanState == In(currentFanState) & api.fanCmd == None[FanCmd.Type]()),
      // post-condition - communication logic
      (currentFanState != In(currentFanState)) ->: (api.fanCmd == Some(currentFanState))
      )
    )
    // log to indicate that that a setPoint event was received/handled
    // on the setPoint in event data port
    // api.logInfo(s"received setPoint $value")  // remove for now because Logika cannot handle string interpolation
    api.logInfo("received setPoint")
    // assign the setPoint record (containing both low and high set points)
    // to a component local variable "setPoint" that holds the current set point values
    currentSetPoint = value

    // compute command to send to fan
    perform_fan_control(api)
  }

  //------------------------------------------------
  //  t e m p  C h a n g e d    event handler
  //
  // Event handler for event arriving on tempChanged in event port
  //
  //------------------------------------------------
  def handle_tempChanged(api: TempControl_i_Operational_Api): Unit = {
    Contract(
      Requires(
        // this constraint should be handled automatically behind the scenes,
        // Specifically, when we are dispatch on a particular incoming event, according to AADL semantics,
        // the port variables of other incoming dispatching ports should be empty
        //  (we shouldn't even be able to observe the fanCmd port from this handler method)
        api.fanCmd == None[FanCmd.Type]()),
      Modifies(api,  // modifies api.fancmd
               latestTemp, // ToDo: This seems to be an interesting situation where we modify a persistent local state that we don't
                           //  need or want to be visible at the AADL level.  I'm not sure how we would handle this in our current
                           //  Slang contract notation.  It's like we need "aspects": an aspect of contracts that is visible only at the
                           //  Slang level
               currentSetPoint,
               currentFanState),
      Ensures(// frame conditions on port variables
              // (this will eventually be unnecessary once read/write notions are implemented and modifies clause is enhanced)
              // current have to "manually" give frame-condition for all input data-like port states
              api.currentTemp == In(api).currentTemp,
              api.setPoint == In(api).setPoint,
              api.fanAck == In(api).fanAck,
              // post-condition - local state (and explicitly stated frame condition for unmodified variables)
              //   Note: the entire contract is identical to that of perform_fan_control except for the clause below,
              //   which updates latest temp
              latestTemp == In(api).currentTemp,
              currentSetPoint == In(currentSetPoint),
              // post-conditions - control logic
              (latestTemp.degrees < currentSetPoint.low.degrees) ->:
                 (currentFanState == FanCmd.Off),
              (latestTemp.degrees > currentSetPoint.high.degrees) ->:
                 (currentFanState == FanCmd.On),
              // The following clause combines the control law logic with the logic for decided if we need to send a fan command
              //  (i.e., did our desired state for fan change).   It might be cleaner (better compositional reasoning) to
              // separate these.
              (latestTemp.degrees >= currentSetPoint.low.degrees & latestTemp.degrees <= currentSetPoint.high.degrees)  // ToDo: Further dev. related to undetected bug in old code. BUG Fix: was ">", now corrected to  ">=".  Desired capability: Exhaustive check of conditions (bug was related to non-exhaustivity)
                ->: (currentFanState == In(currentFanState) & api.fanCmd == None[FanCmd.Type]()),
              // post-condition - communication logic
              (currentFanState != In(currentFanState)) ->: (api.fanCmd == Some(currentFanState))
      )
    )
    // log to indicate that that a tempChanged event was received/handled
    api.logInfo("received tempChanged")

    // get current temp from currentTemp in data port
    latestTemp = api.get_currentTemp().get // since this is a data port, the .get always succeeds

    // assert(latestTemp.degrees >= -50.0F)

    // compute command to send to fan
    perform_fan_control(api)
  }

  //--------------------------------------------
  //
  //  p e r f o r m _ f a n _ c o n t r o l
  //
  //  Helper function to control the fan after
  //    change to current temperature, or
  //    change to set point.
  //
  //  This function enforces the control laws for the system based on inputs from
  //    latestTemp (might be better named "storedTemp")
  //    currentSetPoint
  //  and will ensure that the output variable
  //    currentFanState
  //  is in the appropriate state.
  //
  //  There are some subtleties about how this is set up.
  //  First, the control law is enforced in terms of the latestTemp value instead of the currentTemp port value.
  //  This is due to the fact that (for demo/illustration/pedagogical purposes) the currentTemp port has an accompanying
  //  event notification port (tempChanged).  If we simply modeled with a currentTemp data port only, this subtlety would not
  //  arise.  The control property could be stated directly in terms of the currentTemp port and the currentTemp port would be
  //  read every time a setPoint or a tempChange event arrived.
  //  With the current port specifications, it is implied that the appropriate time to read the currentTemp port is when the
  //  the tempChanged event arrives.  However, a new setPoint could trigger a dispatch while the tempChanged event is queued,
  //  meaning that a new temperature value is available but a control action to adjust the temperature has not been
  //  performed.  If the control law is expressed as a contract between the currentTemp data port value directly,
  //  the fact that it is not read (when the setPoint arrives) will cause the contract to be violated.  So there
  //  are two relatively "clean" solutions.
  //  (1) express control law contracts in terms of the currentTemp port and read/use its value to perform fan control
  //      when either setPoint or tempChanged event arrives
  //  (2) express the control law and contracts in terms of the latestTemp variable, and only update the latestTemp
  //      variable when a tempChange event arrives.
  //  I chose to do (2) to "stay true" to the original pedagogical intent of the example (read currentTemp when tempChanged
  //  arives).   However, this will probably make end to end reasoning more difficult.
  //
  //  Second, a command is only sent to the fan through the fanCmd port when the value of currentFanState changes (since the
  //  port is specified as an event port).  Some some sense, like latestTemp is a proxy for the currentTemp port value,
  //  currentFanState is a proxy for the fanCmd port value.
  //  It would probably be easier from a contract reasoning perspective (especially end to end reasoning)
  //  to have both currentTemp and fanCmd be data ports.
  //--------------------------------------------

  def perform_fan_control(api: TempControl_i_Operational_Api) : Unit = {
    Contract(
      // For now we need to manually specify that we assume that output event ports are empty at start of method.
      // This is because if we do not call "put value" on them, we need to be able to conclude that the ports are still empty
      // in the post-condition.
      Requires(api.fanCmd == None[FanCmd.Type]()),
      Modifies(api, // modifies api.fancmd (since we don't have precise frame conditions for records, we have to assume that all
                    // ghost variables for ports are modified
               currentFanState),
      Ensures(// current have to "manually" give frame-condition for all input data-like port states
              api.currentTemp == In(api).currentTemp,
              api.setPoint == In(api).setPoint,
              api.fanAck == In(api).fanAck,
              // post-conditions - control logic
              (latestTemp.degrees < currentSetPoint.low.degrees) ->:
                (currentFanState == FanCmd.Off),
              (latestTemp.degrees > currentSetPoint.high.degrees) ->:
                (currentFanState == FanCmd.On),
              // The following clause combines the control law logic with the logic for decided if we need to send a fan command
              //  (i.e., did our desired state for fan change).   It might be cleaner (better compositional reasoning) to
              // separate these.
              (latestTemp.degrees >= currentSetPoint.low.degrees & latestTemp.degrees <= currentSetPoint.high.degrees)
                ->: (currentFanState == In(currentFanState) & api.fanCmd == None[FanCmd.Type]()),
              // post-condition - communication logic
              (currentFanState != In(currentFanState)) ->: (api.fanCmd == Some(currentFanState))
      )
    )
    val oldFanState = currentFanState
    if (latestTemp.degrees < currentSetPoint.low.degrees) {
      // if current temp is below low set point,
      currentFanState = FanCmd.Off
      api.logInfo("Set fan command: Off")
    } else if (latestTemp.degrees > currentSetPoint.high.degrees) {
      // if current temp exceeds high set point,
      currentFanState = FanCmd.On
      api.logInfo("Set fan command: On")
    } else {
      api.logInfo("Fan state unchanged")
      // DEMO: Uncommenting this line will lead Logika to find a post-condition violation
      //   i.e., a fan command is being sent when it shouldn't be sent
      // api.put_fanCmd(currentFanState)
    }
    if (currentFanState != oldFanState) {
      // if we change the desired fanState, send new command to fan to change its state
      api.put_fanCmd(currentFanState)
    }
  }

  //============================================================================
  //  D e m o    S e t p o i n t   D a t a   M o d e l    C o n s t r a i n t
  //============================================================================
  def demo_setPoint() : Unit = {
    val mySetPoint: SetPoint_i = SetPoint_i(
      Temperature_i(55f),
      Temperature_i(100f))
  }

  //=================================================
  //  AADL entry points below are unused
  //=================================================
  def activate(api: TempControl_i_Operational_Api): Unit = {}

  def deactivate(api: TempControl_i_Operational_Api): Unit = {}

  def finalise(api: TempControl_i_Operational_Api): Unit = {}

  def recover(api: TempControl_i_Operational_Api): Unit = {}
}