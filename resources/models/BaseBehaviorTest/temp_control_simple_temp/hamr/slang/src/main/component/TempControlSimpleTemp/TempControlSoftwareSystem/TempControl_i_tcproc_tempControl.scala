// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._
import TempControlSimpleTemp.CoolingFan._
import TempControlSimpleTemp.TempSensor._

// This file will not be overwritten so is safe to edit
object TempControl_i_tcproc_tempControl {

  // BEGIN STATE VARS
  var currentSetPoint: TempControlSoftwareSystem.SetPoint_i = TempControlSoftwareSystem.SetPoint_i.example()

  var latestTemp: TempSensor.Temperature_i = TempSensor.Temperature_i.example()

  var currentFanState: CoolingFan.FanCmd.Type = CoolingFan.FanCmd.byOrdinal(0).get
  // END STATE VARS

  // ToDo: currentTemp should not be included in the vars above (it should not be included in the
  //  state specified in the model.  It was included temporarily for demo purposes.
  //  currentFanState should be included but was omitted because enums were not handled.

  // FROM ORIGINAL CODE
  // var currentSetPoint: SetPoint_i = TempControlSoftwareSystem.Defs.initialSetPoint // Traces to currentSetPoint in AADL TempControl thread
  // var currentFanState: FanCmd.Type = TempControlSoftwareSystem.Defs.initialFanState // Traces to currentFanState in AADL TempControl thread
  // var latestTemp: TempSensor.Temperature_i = TempSensor.Defs.defaultTemp

  //=================================================
  //  I n i t i a l i z e    E n t r y    P o i n t
  //=================================================
  def initialise(api: TempControl_i_Initialization_Api): Unit = {
    Contract(
      Modifies(
        // BEGIN INITIALIZES MODIFIES
        currentSetPoint,
        currentFanState,
        latestTemp
        // END INITIALIZES MODIFIES
      ),
      Ensures(
        // BEGIN INITIALIZES ENSURES
        // guarantee defautSetPoint
        currentSetPoint.low.degrees == 70.0f && currentSetPoint.high.degrees == 80.0f,
        // guarantee defaultFanStates
        currentFanState == CoolingFan.FanCmd.Off,
        // guarantee defaultLatestTemp
        latestTemp.degrees == 75.0f
        // END INITIALIZES ENSURES
      )
    )
    api.logInfo("Initialize Entry Point")

    // The Initialize Entry Point must initialize all component local state and all output data ports.

    // initialize component local state
    //currentSetPoint = TempControlSoftwareSystem.Defs.initialSetPoint
    //currentFanState = TempControlSoftwareSystem.Defs.initialFanState
    //latestTemp = TempSensor.Defs.defaultTemp
    currentSetPoint = SetPoint_i(Temperature_i(55f), Temperature_i(100f))
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

  def handle_fanAck(api: TempControl_i_Operational_Api, value : CoolingFan.FanAck.Type): Unit = {
    Contract(
      Modifies(
        // BEGIN_COMPUTE_MODIFIES_fanAck
        currentSetPoint,
        currentFanState,
        latestTemp
        // END_COMPUTE MODIFIES_fanAck
      ),
      Ensures(
        // BEGIN_COMPUTE_ENSURES_fanAck
        // guarantee TC_Req_01
        //   If the current temperature is less than the set point, then the fan state shall be Off.
        (latestTemp.degrees < currentSetPoint.low.degrees) ->: (currentFanState == CoolingFan.FanCmd.Off),
        // guarantee TC_Req_02
        //   If the current temperature is greater than the set point,
        //   then the fan state shall be On.
        (latestTemp.degrees > currentSetPoint.high.degrees) ->: (currentFanState == CoolingFan.FanCmd.On)
        // END_COMPUTE ENSURES_fanAck
      )
    )
    api.logInfo("received fanAck")
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
  //------------------------------------------------
  def handle_setPoint(api: TempControl_i_Operational_Api, value : TempControlSoftwareSystem.SetPoint_i): Unit = {
    Contract(
      Modifies(
        // BEGIN_COMPUTE_MODIFIES_setPoint
        currentSetPoint,
        currentFanState,
        latestTemp,
        currentSetPoint
        // END_COMPUTE MODIFIES_setPoint
      ),
      Ensures(
        // BEGIN_COMPUTE_ENSURES_setPoint
        // guarantee TC_Req_01
        //   If the current temperature is less than the set point, then the fan state shall be Off.
        (latestTemp.degrees < currentSetPoint.low.degrees) ->: (currentFanState == CoolingFan.FanCmd.Off),
        // guarantee TC_Req_02
        //   If the current temperature is greater than the set point,
        //   then the fan state shall be On.
        (latestTemp.degrees > currentSetPoint.high.degrees) ->: (currentFanState == CoolingFan.FanCmd.On),
        // guarantees setPointChanged
        currentSetPoint == api.setPoint
        // END_COMPUTE ENSURES_setPoint
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
      Modifies(
        // BEGIN_COMPUTE_MODIFIES_tempChanged
        currentSetPoint,
        currentFanState,
        latestTemp,
        latestTemp
        // END_COMPUTE MODIFIES_tempChanged
      ),
      Ensures(
        // BEGIN_COMPUTE_ENSURES_tempChanged
        // guarantee TC_Req_01
        //   If the current temperature is less than the set point, then the fan state shall be Off.
        (latestTemp.degrees < currentSetPoint.low.degrees) ->: (currentFanState == CoolingFan.FanCmd.Off),
        // guarantee TC_Req_02
        //   If the current temperature is greater than the set point,
        //   then the fan state shall be On.
        (latestTemp.degrees > currentSetPoint.high.degrees) ->: (currentFanState == CoolingFan.FanCmd.On),
        // guarantees tempChanged
        latestTemp == api.currentTemp
        // END_COMPUTE ENSURES_tempChanged
      )
    )
    // log to indicate that that a tempChanged event was received/handled
    api.logInfo("received tempChanged")

    // get current temp from currentTemp in data port
    latestTemp = api.get_currentTemp().get // since this is a data port, the .get always succeeds

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
  //--------------------------------------------

  def perform_fan_control(api: TempControl_i_Operational_Api) : Unit = {
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

  //=================================================
  //  AADL entry points below are unused
  //=================================================
  def activate(api: TempControl_i_Operational_Api): Unit = { }

  def deactivate(api: TempControl_i_Operational_Api): Unit = { }

  def finalise(api: TempControl_i_Operational_Api): Unit = { }

  def recover(api: TempControl_i_Operational_Api): Unit = { }
}