// #Sireum

package tc.TempControlSoftwareSystem

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object TempControlPeriodic_p_tcproc_tempControl_GumboX {
  /** I-Assm: Integration constraint on tempControl's incoming data port currentTemp
    *
    * assume currentTempRange
    */
  @strictpure def I_Assm_currentTemp(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -70.0f & currentTemp.degrees <= 80.0f

  // I-Assm-Guard: Integration constraint on tempControl's incoming data port currentTemp
  @strictpure def I_Assm_Guard_currentTemp(currentTemp: Option[TempSensor.Temperature_i]): B =
    currentTemp.nonEmpty -->: I_Assm_currentTemp(currentTemp.get)

  /** Initialize Entrypoint Contract
    *
    * guarantees initLatestFanCmd
    *   Initialize state variable
    * @param latestFanCmd post-state state variable
    */
  @strictpure def initialize_initLatestFanCmd (
      latestFanCmd: CoolingFan.FanCmd.Type): B =
    latestFanCmd == CoolingFan.FanCmd.Off

  /** Initialize Entrypoint Contract
    *
    * guarantees initFanCmd
    *   Initial fan command
    * @param api_fanCmd port variable
    */
  @strictpure def initialize_initFanCmd (
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    api_fanCmd == CoolingFan.FanCmd.Off

  /** IEP-Guar: Initialize Entrypoint Contracts for tempControl
    *
    * @param latestFanCmd post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def initialize_IEP_Guar (
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    initialize_initLatestFanCmd(latestFanCmd) &
    initialize_initFanCmd(api_fanCmd)

  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param latestFanCmd post-state state variable
    * @param api_fanCmd port variable
    */
  @strictpure def inititialize_IEP_Post (
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_fanCmd: CoolingFan.FanCmd.Type): B =
    (
     // IEP-Guar: Initialize Entrypoint contract for tempControl
     initialize_IEP_Guar(latestFanCmd, api_fanCmd))

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
    * guarantees altCurrentTempLTSetPoint
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

  /** Compute Entrypoint Contract
    *
    * guarantees altCurrentTempGTSetPoint
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

  /** Compute Entrypoint Contract
    *
    * guarantees altCurrentTempInRange
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

  /** CEP-T-Guar: Top-level guarantee contracts for tempControl's compute entrypoint
    *
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_CEP_T_Guar (
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    compute_spec_altCurrentTempLTSetPoint_guarantee(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_spec_altCurrentTempGTSetPoint_guarantee(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_spec_altCurrentTempInRange_guarantee(In_latestFanCmd, latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint)

  /** guarantees currentTempLTSetPoint
    *   If current temperature is less than
    *   the current low set point, then the fan state shall be Off
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_case_currentTempLTSetPoint(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees < api_setPoint.low.degrees) -->:
      (latestFanCmd == CoolingFan.FanCmd.Off & api_fanCmd == CoolingFan.FanCmd.Off)

  /** guarantees currentTempGTSetPoint
    *   If current temperature is greater than
    *   the current high set point, then the fan state shall be On
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_case_currentTempGTSetPoint(
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees > api_setPoint.high.degrees) -->:
      (latestFanCmd == CoolingFan.FanCmd.On & api_fanCmd == CoolingFan.FanCmd.On)

  /** guarantees currentTempInRange
    *   If current temperature is greater than or equal to the 
    *   current low set point and less than or equal to the current high set point, 
    *   then the current fan state is maintained.
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_case_currentTempInRange(
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (api_currentTemp.degrees >= api_setPoint.low.degrees & api_currentTemp.degrees <= api_setPoint.high.degrees) -->:
      (latestFanCmd == In_latestFanCmd & api_fanCmd == latestFanCmd)

  /** CEP-T-Case: Top-Level case contracts for tempControl's compute entrypoint
    *
    * @param In_latestFanCmd pre-state state variable* @param latestFanCmd post-state state variable* @param api_currentTemp port variable* @param api_fanCmd port variable* @param api_setPoint port variable
    */
  @strictpure def compute_CEP_T_Case (
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i: B =
    compute_case_currentTempLTSetPoint(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_case_currentTempGTSetPoint(latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) &
    compute_case_currentTempInRange(In_latestFanCmd, latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint)"

  /** CEP-Post: Compute Entrypoint Post-Condition for tempControl
    *
    * @param In_latestFanCmd pre-state state variable
    * @param latestFanCmd post-state state variable
    * @param api_currentTemp port variable
    * @param api_fanCmd port variable
    * @param api_setPoint port variable
    */
  @strictpure def compute_CEP_Post (
      In_latestFanCmd: CoolingFan.FanCmd.Type,
      latestFanCmd: CoolingFan.FanCmd.Type,
      api_currentTemp: TempSensor.Temperature_i,
      api_fanCmd: CoolingFan.FanCmd.Type,
      api_setPoint: TempControlSoftwareSystem.SetPoint_i): B =
    (// CEP-Guar: guarantee clauses of tempControl's compute entrypoint
     compute_CEP_T_Guar (In_latestFanCmd, latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint) & 

     // CEP-T-Case: case clauses of tempControl's compute entrypoint
     compute_CEP_T_Case (In_latestFanCmd, latestFanCmd, api_currentTemp, api_fanCmd, api_setPoint))
}
