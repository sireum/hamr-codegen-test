// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object TempControl_s_tcproc_tempControl_Bridge_GumboX {
  /** invariant AbsZero
    */
  @strictpure def tc_TempSensor_Temperature_i_AbsZero_Invariant(value: TempSensor.Temperature_i): B =
    GUMBO_Definitions.GUMBO__Library.atLeastAbsoluteZeroRaw(value.degrees, value.unit)

  @strictpure def tc_TempSensor_Temperature_i_Invariant(value: TempSensor.Temperature_i): B =
    tc_TempSensor_Temperature_i_AbsZero_Invariant(value)

  /** invariant SetPoint_Data_Invariant
    */
  @strictpure def tc_TempControlSoftwareSystem_SetPoint_i_SetPoint_Data_Invariant_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    value.low.degrees >= 50.0f & value.high.degrees <= 110.0f & value.low.degrees <= value.high.degrees

  @strictpure def tc_TempControlSoftwareSystem_SetPoint_i_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    tc_TempControlSoftwareSystem_SetPoint_i_SetPoint_Data_Invariant_Invariant(value)


  /** guarantees TC_Req_01
    *   If the current temperature is less than the set point, then the fan state shall be Off.
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_spec_TC_Req_01_guarantee(
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    (latestTemp.degrees < currentSetPoint.low.degrees) ->: (currentFanState == CoolingFan.FanCmd.Off)

  /** guarantees TC_Req_02
    *   If the current temperature is greater than the set point,
    *   then the fan state shall be On.
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_spec_TC_Req_02_guarantee(
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    (latestTemp.degrees > currentSetPoint.high.degrees) ->: (currentFanState == CoolingFan.FanCmd.On)

  /** guarantees TC_Req_03
    *   If the current temperature is greater than or equal to the
    *   current low set point and less than or equal to the current high set point,
    *   then the current fan state is maintained.
    * @param In_currentFanState pre-state state variable
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_spec_TC_Req_03_guarantee(
      In_currentFanState: CoolingFan.FanCmd.Type,
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    (latestTemp.degrees >= currentSetPoint.low.degrees & latestTemp.degrees <= currentSetPoint.high.degrees) ->: (currentFanState == In_currentFanState)

  /** guarantees mustSendFanCmd
    *   If the local record of the fan state was updated, 
    *   then send a fan command event with this updated value.
    * @param In_currentFanState pre-state state variable
    * @param currentFanState post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def compute_spec_mustSendFanCmd_guarantee(
      In_currentFanState: CoolingFan.FanCmd.Type,
      currentFanState: CoolingFan.FanCmd.Type,
      api_fanCmd: Option[CoolingFan.FanCmd.Type]): B =
    (In_currentFanState != currentFanState) ->: (api_fanCmd.nonEmpty && api_fanCmd.get == currentFanState) && (currentFanState == In_currentFanState) ->: api_fanCmd.isEmpty && (In_currentFanState != currentFanState) ->: api_fanCmd.nonEmpty

  /** guarantees setPointNotModified
    * @param In_currentSetPoint pre-state state variable
    * @param currentSetPoint post-state state variable
    */
  @strictpure def compute_fanAck_setPointNotModified_guarantee(
      In_currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i): B =
    currentSetPoint == In_currentSetPoint

  /** guarantees lastTempNotModified
    * @param In_latestTemp pre-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_fanAck_lastTempNotModified_guarantee(
      In_latestTemp: TempSensor.Temperature_i,
      latestTemp: TempSensor.Temperature_i): B =
    latestTemp == In_latestTemp

  /** guarantees currentFanState
    * @param In_currentFanState pre-state state variable
    * @param currentFanState post-state state variable
    */
  @strictpure def compute_fanAck_currentFanState_guarantee(
      In_currentFanState: CoolingFan.FanCmd.Type,
      currentFanState: CoolingFan.FanCmd.Type): B =
    currentFanState == In_currentFanState

  /** guarantees noEventsSent
    * @param api_fanCmd port variable
    */
  @strictpure def compute_fanAck_noEventsSent_guarantee(
      api_fanCmd: Option[CoolingFan.FanCmd.Type]): B =
    api_fanCmd.isEmpty

  /** guarantees setPointChanged
    * @param currentSetPoint post-state state variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_setPoint_setPointChanged_guarantee(
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    currentSetPoint == api_setPoint

  /** guarantees latestTempNotModified
    * @param In_latestTemp pre-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_setPoint_latestTempNotModified_guarantee(
      In_latestTemp: TempSensor.Temperature_i,
      latestTemp: TempSensor.Temperature_i): B =
    latestTemp == In_latestTemp

  /** guarantees tempChanged
    * @param latestTemp post-state state variable
    * @param api_currentTemp port variable
    */
  @strictpure def compute_tempChanged_tempChanged_guarantee(
      latestTemp: TempSensor.Temperature_i,
      api_currentTemp: TempSensor.Temperature_i): B =
    latestTemp == api_currentTemp

  /** guarantees setPointNotModified
    * @param In_currentSetPoint pre-state state variable
    * @param currentSetPoint post-state state variable
    */
  @strictpure def compute_tempChanged_setPointNotModified_guarantee(
      In_currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i): B =
    currentSetPoint == In_currentSetPoint


  /**
    * @param In_currentFanState pre-state state variable
    * @param In_currentSetPoint pre-state state variable
    * @param In_latestTemp pre-state state variable
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def fanAck_oracle(
      In_currentFanState: CoolingFan.FanCmd.Type,
      In_currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      In_latestTemp: TempSensor.Temperature_i,
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i,
      api_fanCmd: Option[CoolingFan.FanCmd.Type]): B =
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(In_currentSetPoint) &
    tc_TempSensor_Temperature_i_Invariant(In_latestTemp) &
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    tc_TempSensor_Temperature_i_Invariant(latestTemp) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_03_guarantee(In_currentFanState, currentFanState, currentSetPoint, latestTemp) &
    compute_spec_mustSendFanCmd_guarantee(In_currentFanState, currentFanState, api_fanCmd) &
    compute_fanAck_setPointNotModified_guarantee(In_currentSetPoint, currentSetPoint) &
    compute_fanAck_lastTempNotModified_guarantee(In_latestTemp, latestTemp) &
    compute_fanAck_currentFanState_guarantee(In_currentFanState, currentFanState) &
    compute_fanAck_noEventsSent_guarantee(api_fanCmd)

  /**
    * @param In_currentFanState pre-state state variable
    * @param In_latestTemp pre-state state variable
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def setPoint_oracle(
      In_currentFanState: CoolingFan.FanCmd.Type,
      In_latestTemp: TempSensor.Temperature_i,
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i,
      api_fanCmd: Option[CoolingFan.FanCmd.Type],
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    tc_TempSensor_Temperature_i_Invariant(In_latestTemp) &
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    tc_TempSensor_Temperature_i_Invariant(latestTemp) &
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(api_setPoint) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_03_guarantee(In_currentFanState, currentFanState, currentSetPoint, latestTemp) &
    compute_spec_mustSendFanCmd_guarantee(In_currentFanState, currentFanState, api_fanCmd) &
    compute_setPoint_setPointChanged_guarantee(currentSetPoint, api_setPoint) &
    compute_setPoint_latestTempNotModified_guarantee(In_latestTemp, latestTemp)

  /**
    * @param In_currentFanState pre-state state variable
    * @param In_currentSetPoint pre-state state variable
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    */
  @strictpure def tempChanged_oracle(
      In_currentFanState: CoolingFan.FanCmd.Type,
      In_currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: Option[CoolingFan.FanCmd.Type]): B =
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(In_currentSetPoint) &
    tc_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    tc_TempSensor_Temperature_i_Invariant(latestTemp) &
    tc_TempSensor_Temperature_i_Invariant(api_currentTemp) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_03_guarantee(In_currentFanState, currentFanState, currentSetPoint, latestTemp) &
    compute_spec_mustSendFanCmd_guarantee(In_currentFanState, currentFanState, api_fanCmd) &
    compute_tempChanged_tempChanged_guarantee(latestTemp, api_currentTemp) &
    compute_tempChanged_setPointNotModified_guarantee(In_currentSetPoint, currentSetPoint)
}
