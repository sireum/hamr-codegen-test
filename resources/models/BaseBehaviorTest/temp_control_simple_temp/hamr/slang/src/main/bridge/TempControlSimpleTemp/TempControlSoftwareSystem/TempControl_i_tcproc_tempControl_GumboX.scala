// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp._

// This file was auto-generated.  Do not edit
object TempControl_i_tcproc_tempControl_GumboX {
  /** I-Assm: Integration constraint on tempControl's incoming data port currentTemp
    *
    * assume currentTempRange
    */
  @strictpure def I_Assm_currentTemp(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -70.0f & currentTemp.degrees <= 180.0f

  // I-Assm-Guard: Integration constraint on tempControl's incoming data port currentTemp
  @strictpure def I_Assm_Guard_currentTemp(currentTemp: Option[TempSensor.Temperature_i]): B =
    currentTemp.nonEmpty -->: I_Assm_currentTemp(currentTemp.get)

  /** Initialize Entrypoint Contract
    *
    * guarantees defautSetPoint
    * @param currentSetPoint post-state state variable
    */
  @strictpure def initialize_defautSetPoint (
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i): B =
    currentSetPoint.low.degrees == 70.0f && currentSetPoint.high.degrees == 80.0f

  /** Initialize Entrypoint Contract
    *
    * guarantees defaultFanStates
    * @param currentFanState post-state state variable
    */
  @strictpure def initialize_defaultFanStates (
      currentFanState: CoolingFan.FanCmd.Type): B =
    currentFanState == CoolingFan.FanCmd.Off

  /** Initialize Entrypoint Contract
    *
    * guarantees defaultLatestTemp
    * @param latestTemp post-state state variable
    */
  @strictpure def initialize_defaultLatestTemp (
      latestTemp: TempSensor.Temperature_i): B =
    latestTemp.degrees == 75.0f

  /** IEP-Guar: Initialize Entrypoint Contracts for tempControl
    *
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def initialize_IEP_Guar (
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    initialize_defautSetPoint(currentSetPoint) &
    initialize_defaultFanStates(currentFanState) &
    initialize_defaultLatestTemp(latestTemp)

  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def inititialize_IEP_Post (
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    (
     // IEP-Guar: Initialize Entrypoint contract for tempControl
     initialize_IEP_Guar(currentFanState, currentSetPoint, latestTemp))

  /** CEP-Pre: Compute Entrypoint Pre-Condition for tempControl
    *
    * @param currentTemp_IEP_Assm port variable
    */
  @strictpure def compute_CEP_Pre (
      currentTemp_IEP_Assm: Option[TempSensor.Temperature_i]): B =
    (// I-Assm-Guard: Integration constraints for tempControl's incoming ports
     I_Assm_Guard_currentTemp(currentTemp_IEP_Assm) & 

     // D-Inv-Guard: Datatype invariants for the types associated with tempControl incoming ports
     TempSensor.Temperature_i_GumboX.D_Inv_Guard_Temperature_i(currentTemp_IEP_Assm))

  /** Compute Entrypoint Contract
    *
    * guarantees TC_Req_01
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

  /** Compute Entrypoint Contract
    *
    * guarantees TC_Req_02
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

  /** CEP-T-Guar: Top-level guarantee contracts for tempControl's compute entrypoint
    *
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_CEP_T_Guar (
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    compute_spec_TC_Req_01_guarantee(currentFanState, currentSetPoint, latestTemp) &
    compute_spec_TC_Req_02_guarantee(currentFanState, currentSetPoint, latestTemp)

  /** CEP-Post: Compute Entrypoint Post-Condition for tempControl
    *
    * @param currentFanState post-state state variable
    * @param currentSetPoint post-state state variable
    * @param latestTemp post-state state variable
    */
  @strictpure def compute_CEP_Post (
      currentFanState: CoolingFan.FanCmd.Type,
      currentSetPoint: TempControlSoftwareSystem.SetPoint_i,
      latestTemp: TempSensor.Temperature_i): B =
    (// CEP-Guar: guarantee clauses of tempControl's compute entrypoint
     compute_CEP_T_Guar (currentFanState, currentSetPoint, latestTemp))
}
