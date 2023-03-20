// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object TempControlPeriodic_p_tcproc_tempControl_Bridge_GumboX {
  /** guarantees altCurrentTempLTSetPoint
    *   If current temperature is less than
    *   the current low set point, then the fan state shall be Off
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_spec_altCurrentTempLTSetPoint_guarantee(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees < api_setPoint.low.degrees) ->: (latestFanCmd == CoolingFan.FanCmd.Off && api_fanCmd == CoolingFan.FanCmd.Off)

  /** guarantees altCurrentTempGTSetPoint
    *   If current temperature is greater than
    *   the current high set point, then the fan state shall be On
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_spec_altCurrentTempGTSetPoint_guarantee(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees > api_setPoint.high.degrees) ->: (latestFanCmd == CoolingFan.FanCmd.On & api_fanCmd == CoolingFan.FanCmd.On)

  /** guarantees altCurrentTempInRange
    *   If current temperature is greater than or equal to the 
    *   current low set point and less than or equal to the current high set point, 
    *   then the current fan state is maintained.
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_spec_altCurrentTempInRange_guarantee(
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees >= api_setPoint.low.degrees & api_currentTemp.degrees <= api_setPoint.high.degrees) -->: (latestFanCmd == In_latestFanCmd & api_fanCmd == latestFanCmd)

  /** guarantees currentTempLTSetPoint
    *   If current temperature is less than
    *   the current low set point, then the fan state shall be Off
    * @param latestFanCmd post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def compute_case_currentTempLTSetPoint_guarantee(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    latestFanCmd == CoolingFan.FanCmd.Off & api_fanCmd == CoolingFan.FanCmd.Off

  /** guarantees currentTempGTSetPoint
    *   If current temperature is greater than
    *   the current high set point, then the fan state shall be On
    * @param latestFanCmd post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def compute_case_currentTempGTSetPoint_guarantee(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    latestFanCmd == CoolingFan.FanCmd.On & api_fanCmd == CoolingFan.FanCmd.On

  /** guarantees currentTempInRange
    *   If current temperature is greater than or equal to the 
    *   current low set point and less than or equal to the current high set point, 
    *   then the current fan state is maintained.
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def compute_case_currentTempInRange_guarantee(
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    latestFanCmd == In_latestFanCmd & api_fanCmd == latestFanCmd


  /**
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def time_triggered_oracle(
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    compute_spec_altCurrentTempLTSetPoint_guarantee(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_spec_altCurrentTempGTSetPoint_guarantee(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_spec_altCurrentTempInRange_guarantee(In_latestFanCmd, latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_case_currentTempLTSetPoint_guarantee(latestFanCmd, api_fanCmd) &
    compute_case_currentTempGTSetPoint_guarantee(latestFanCmd, api_fanCmd) &
    compute_case_currentTempInRange_guarantee(In_latestFanCmd, latestFanCmd, api_fanCmd)
}
