// #Sireum #Logika

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._
import TempControlSimpleTemp.TempSensor._
import TempControlSimpleTemp.CoolingFan._

// This file will not be overwritten so is safe to edit
object TempControlPeriodic_i_tcproc_tempControl {

  // This thread local variable is needed to implement the property that
  // if the current temp is between the high and low set points, then the
  // state of the fan should be set to whatever it was on the last dispatch
  // Note: if we had the ability to directly reference the value of a data port
  // on the previous dispatch, then we would not need this variable.
  var latestFanCmd: FanCmd.Type = TempControlSoftwareSystem.Defs.initialFanState

  //=================================================
  //  I n i t i a l i z e    E n t r y    P o i n t
  //=================================================
  def initialise(api: TempControlPeriodic_i_Initialization_Api): Unit = {
    Contract(Modifies(latestFanCmd))
    // initialize thread local variables
    latestFanCmd = FanCmd.Off
    // initialize output data port
    api.put_fanCmd(latestFanCmd)
  }

  //=================================================
  //  C o m p u t e    E n t r y    P o i n t
  //=================================================
  def timeTriggered(api: TempControlPeriodic_i_Operational_Api): Unit = {
    Contract(
      Modifies(latestFanCmd),  // ToDo:  This needs to support modification/frame conditions of API
      Case(Requires(api.currentTemp.degrees < api.setPoint.low.degrees),
           Ensures(latestFanCmd == FanCmd.Off & api.fanCmd == FanCmd.Off)),
      Case(Requires(api.currentTemp.degrees > api.setPoint.high.degrees),
           Ensures(latestFanCmd == FanCmd.On & api.fanCmd == FanCmd.On)),
      Case(Requires((api.setPoint.low.degrees <= api.currentTemp.degrees) &
                    (api.currentTemp.degrees <= api.setPoint.high.degrees)),
           Ensures(latestFanCmd == In(latestFanCmd) & api.fanCmd == latestFanCmd))
    )
    // Note the following was originally needed to help SMT out
    // Deduce( |- (api.setPoint.high.degrees >= api.setPoint.low.degrees))
    // get the current temperature
    val currentTemp: Temperature_i = api.get_currentTemp().get

    // get the current set point
    val setPoint: SetPoint_i = api.get_setPoint().get
    // Deduce( |- (setPoint.high.degrees >= setPoint.low.degrees))


    // get the current fan acknowledge
    //  Note: in a more complete system, we might set up a status or error mode for the entire system
    val fanAck: FanAck.Type = api.get_fanAck().get

    // enforce control laws for fanCmd
    if (currentTemp.degrees < setPoint.low.degrees) {
      // if current temp is below low set point,
      latestFanCmd = FanCmd.Off
      api.logInfo("Set fan command: Off")
    } else if (currentTemp.degrees > setPoint.high.degrees) {
      // if current temp exceeds high set point,
      latestFanCmd = FanCmd.On
      api.logInfo("Set fan command: On")
    } else {
      // Note: This is a situation where it would be nice to have the options of the true data flow model
      // where we could read the previous value of an output data port
      api.logInfo("Fan state unchanged")
    }

    // Deduce( |- (setPoint.high.degrees >= setPoint.low.degrees))
    // Deduce( |- (currentTemp.degrees > setPoint.high.degrees))
    api.put_fanCmd(latestFanCmd)
  }

  // version 2, using only Ensures and Implication, instead of Case
  def timeTriggeredv2(api: TempControlPeriodic_i_Operational_Api): Unit = {
    Contract(
      Modifies(latestFanCmd),
      Ensures(
        (api.currentTemp.degrees < api.setPoint.low.degrees) ->:
          (latestFanCmd == FanCmd.Off & api.fanCmd == FanCmd.Off),
        (api.currentTemp.degrees > api.setPoint.high.degrees) ->:
          (latestFanCmd == FanCmd.On & api.fanCmd == FanCmd.On),
        (api.setPoint.low.degrees <= api.currentTemp.degrees &
          api.currentTemp.degrees <= api.setPoint.high.degrees) ->:
          (latestFanCmd == In(latestFanCmd) & api.fanCmd == latestFanCmd))
    )
    // Note: the following was originally needed to help SMT out
    Deduce( |- (api.setPoint.high.degrees >= api.setPoint.low.degrees))
    // get the current temperature
    val currentTemp: Temperature_i = api.get_currentTemp().get

    // get the current set point
    val setPoint: SetPoint_i = api.get_setPoint().get
    // Deduce( |- (setPoint.high.degrees >= setPoint.low.degrees))


    // get the current fan acknowledge
    //  Note: in a more complete system, we might set up a status or error mode for the entire system
    val fanAck: FanAck.Type = api.get_fanAck().get

    // enforce control laws for fanCmd
    // ToDo: Figure out why Logika is telling me that these branches are unreachable
    if (currentTemp.degrees < setPoint.low.degrees) {
      // if current temp is below low set point,
      latestFanCmd = FanCmd.Off
      api.logInfo("Set fan command: Off")
    } else if (currentTemp.degrees > setPoint.high.degrees) {
      // if current temp exceeds high set point,
      latestFanCmd = FanCmd.On
      api.logInfo("Set fan command: On")
    } else {
      // Note: This is a situation where it would be nice to have the options of the true data flow model
      // where we could read the previous value of an output data port
      api.logInfo("Fan state unchanged")
    }

    // Deduce( |- (setPoint.high.degrees >= setPoint.low.degrees))
    // Deduce( |- (currentTemp.degrees > setPoint.high.degrees))
    api.put_fanCmd(latestFanCmd)
  }


  //=================================================
  //  AADL entry points below are unused
  //=================================================
  def activate(api: TempControlPeriodic_i_Operational_Api): Unit = { }

  def deactivate(api: TempControlPeriodic_i_Operational_Api): Unit = { }

  def finalise(api: TempControlPeriodic_i_Operational_Api): Unit = { }

  def recover(api: TempControlPeriodic_i_Operational_Api): Unit = { }
}
