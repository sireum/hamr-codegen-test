// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit
object TempControl_i_tcproc_tempControl_Bridge_GumboX {
  /** invariant AbsZero
    */
  @strictpure def TempControlSimpleTemp_TempSensor_Temperature_i_AbsZero_Invariant(value: TempSensor.Temperature_i): B =
    value.degrees >= -459.67f

  @strictpure def TempControlSimpleTemp_TempSensor_Temperature_i_Invariant(value: TempSensor.Temperature_i): B =
    TempControlSimpleTemp_TempSensor_Temperature_i_AbsZero_Invariant(value)

  /** invariant SetPointDataInvariant
    *   SetPoint Data Invariant
    */
  @strictpure def TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_SetPointDataInvariant_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    value.low.degrees >= 50.0f & value.high.degrees <= 110.0f & value.low.degrees <= value.high.degrees

  @strictpure def TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_Invariant(value: TempControlSoftwareSystem.SetPoint_i): B =
    TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_SetPointDataInvariant_Invariant(value)


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

  /** guarantees setPointChanged
    * @param currentSetPoint post-state state variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_setPoint_setPointChanged_guarantee(
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    currentSetPoint == api_setPoint

  /** guarantees tempChanged
    * @param latestTemp post-state state variable
    * @param api_currentTemp port variable
    */
  @strictpure def compute_tempChanged_tempChanged_guarantee(
      latestTemp: TempSensor.Temperature_i,
      api_currentTemp: TempSensor.Temperature_i): B =
    latestTemp == api_currentTemp


  /**
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def fanAck_oracle(
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    TempControlSimpleTemp_TempSensor_Temperature_i_Invariant(latestTemp) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp)

  /**
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    * @param api_setPoint port variable
    */
  @strictpure def setPoint_oracle(
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    TempControlSimpleTemp_TempSensor_Temperature_i_Invariant(latestTemp) &
    TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_Invariant(api_setPoint) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_setPoint_setPointChanged_guarantee(currentSetPoint, api_setPoint)

  /**
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    * @param api_currentTemp port variable
    */
  @strictpure def tempChanged_oracle(
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i,
      api_currentTemp: TempSensor.Temperature_i): B =
    TempControlSimpleTemp_TempControlSoftwareSystem_SetPoint_i_Invariant(currentSetPoint) &
    TempControlSimpleTemp_TempSensor_Temperature_i_Invariant(latestTemp) &
    TempControlSimpleTemp_TempSensor_Temperature_i_Invariant(api_currentTemp) &
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_tempChanged_tempChanged_guarantee(latestTemp, api_currentTemp)
}
