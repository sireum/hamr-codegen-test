// #Sireum

//=============================================================================
// Executable contracts auto-generated (mock up) for
//   TempControl_i_tcproc_tempControl
//
//=============================================================================

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import TempControlSimpleTemp.TempSensor.Temperature_i
import TempControlSimpleTemp.CoolingFan.FanCmd
import TempControlSimpleTemp.CoolingFan.FanAck

object TempControl_i_tcproc_tempControl_XContracts {

//=====================================================================
//  t e m p C h a n g e d     Dispatch Trigger
//
//    Contracts for tempChanged dispatch trigger
//
//=====================================================================

  // Traceability: compute currentTempLTSetPoint
  //  -- REQ: If current temperature is less than
  //  --  the current low set point, then the fan state shall be Off
  //  guarantee currentTempLTSetPoint:
  //    currentTemp < currentSetPoint.low implies currentFanState == FanState.Off
  def compute_tempChanged_currentTempLTSetPoint_guarantee(
                                              currentTempApi: Temperature_i,   // representing in data port
                                              fanCmdApi: Option[FanCmd.Type],  // representing out event data port
                                              currentSetPoint: SetPoint_i,     // representing out value of local variable
                                              currentSetPointIn: SetPoint_i,   // representing in value of local variable
                                              currentFanState: FanCmd.Type,    // representing out value of local variable
                                              currentFanStateIn: FanCmd.Type   // representing in value of local variable
                                             ): B = {
    (currentTempApi.degrees < currentSetPoint.low.degrees) ->:
      (currentFanState == FanCmd.Off)
  }

  // Traceability: compute currentTempGTSetPoint
  //  -- REQ: If current temperature is greater than
  //  --  the current high set point, then the fan state shall be On
  //  guarantee currentTempGTSetPoint:
  //    currentTemp > currentSetPoint.high implies currentFanState == FanState.On
  def compute_tempChanged_currentTempGTSetPoint_guarantee(
                                              currentTempApi: Temperature_i,   // representing in data port
                                              fanCmdApi: Option[FanCmd.Type],  // representing out event data port
                                              currentSetPoint: SetPoint_i,     // representing out value of local variable
                                              currentSetPointIn: SetPoint_i,   // representing in value of local variable
                                              currentFanState: FanCmd.Type,    // representing out value of local variable
                                              currentFanStateIn: FanCmd.Type   // representing in value of local variable
                                             ): B = {
    (currentTempApi.degrees > currentSetPoint.high.degrees) ->:
      (currentFanState == FanCmd.On)
  }

  // Traceability: compute currentTempInRange
  // -- REQ: If current temperature is greater than or equal to the
  // --  current low set point and less than or equal to the current high set point,
  // --  then the current fan state is maintained.
  def compute_tempChanged_currentTempInRange_guarantee(currentTempApi: Temperature_i,   // representing in data port
                                           fanCmdApi: Option[FanCmd.Type],  // representing out event data port
                                           currentSetPoint: SetPoint_i,     // representing out value of local variable
                                           currentSetPointIn: SetPoint_i,   // representing in value of local variable
                                           currentFanState: FanCmd.Type,    // representing out value of local variable
                                           currentFanStateIn: FanCmd.Type   // representing in value of local variable
                                          ): B = {
    (currentTempApi.degrees >= currentSetPoint.low.degrees & currentTempApi.degrees <= currentSetPoint.high.degrees) ->:
      (fanCmdApi == None[FanCmd.Type]())
  }

  // Traceability: guarantee compute newFanState guarantee
  //  -- if we updated the local record of the fan state state, then we
  //  -- must send out a new fan command.
  //  Old(currentFanState) != currentFanState implies MustSend[fanCmd|currentFanState]
  def compute_tempChanged_newFanState_guarantee(currentTempApi: Temperature_i,   // representing in data port
                                    fanCmdApi: Option[FanCmd.Type],  // representing out event data port
                                    currentSetPoint: SetPoint_i,     // representing out value of local variable
                                    currentSetPointIn: SetPoint_i,   // representing in value of local variable
                                    currentFanState: FanCmd.Type,    // representing out value of local variable
                                    currentFanStateIn: FanCmd.Type   // representing in value of local variable
                                   ): B = {
    (currentFanStateIn != currentFanState) ->:
      (fanCmdApi == Some(currentFanState))
  }

  //=====================================================================
  //  Compute Entry Point  P o s t - C o n d i t i o n   O r a c l e
  //
  //=====================================================================
  def tempChanged_oracle(
                    // in data ports
                    currentTempApi: Temperature_i, // representing in data port
                    // out event data ports
                    fanCmdApi: Option[FanCmd.Type], // representing out event data port
                    // local state
                    currentSetPoint: SetPoint_i, // representing out value of local variable
                    currentSetPointIn: SetPoint_i, // representing in value of local variable
                    currentFanState: FanCmd.Type, // representing out value of local variable
                    currentFanStateIn: FanCmd.Type // representing in value of local variable
                   ) : B = {
    //  Traceability: guarantee currentTempLTSetPoint
    val compute_tempChanged_currentTempLTSetPoint_guarantee_result =
      compute_tempChanged_currentTempLTSetPoint_guarantee(
        currentTempApi, fanCmdApi,
        currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    //  Traceability: guarantee currentTempGTSetPoint
    val compute_tempChanged_currentTempGTSetPoint_guarantee_result =
      compute_tempChanged_currentTempGTSetPoint_guarantee(
        currentTempApi, fanCmdApi,
        currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    // Traceability: compute currentTempInRange
    val compute_tempChanged_currentTempInRange_guarantee_result =
      compute_tempChanged_currentTempInRange_guarantee(
        currentTempApi, fanCmdApi,
        currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    // Traceability: compute newFanState
    val compute_tempChanged_newFanState_guarantee_result =
      compute_tempChanged_newFanState_guarantee(
        currentTempApi, fanCmdApi,
        currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    return (compute_tempChanged_currentTempLTSetPoint_guarantee_result &
            compute_tempChanged_currentTempGTSetPoint_guarantee_result &
            compute_tempChanged_currentTempInRange_guarantee_result &
            compute_tempChanged_newFanState_guarantee_result)
  }

  //=====================================================================
  //  s e t P o i n t     Dispatch Trigger
  //
  //    Contracts for setPoint dispatch trigger
  //
  //=====================================================================

  // Traceability: compute currentTempLTSetPoint
  //  -- REQ: If current temperature is less than
  //  --  the current low set point, then the fan state shall be Off
  //  guarantee currentTempLTSetPoint:
  //    currentTemp < currentSetPoint.low implies currentFanState == FanState.Off
  def compute_setPoint_currentSetPoint_guarantee(
                                                  setPointApi: SetPoint_i, // representing in event data port dispatch value
                                                  currentTempApi: Temperature_i, // representing in data port
                                                  fanCmdApi: Option[FanCmd.Type], // representing out event data port
                                                  latestTemp: Temperature_i, // representing out value of local variable
                                                  latestTempIn: Temperature_i, // representing in value of local variable
                                                  currentSetPoint: SetPoint_i, // representing out value of local variable
                                                  currentSetPointIn: SetPoint_i, // representing in value of local variable
                                                  currentFanState: FanCmd.Type, // representing out value of local variable
                                                  currentFanStateIn: FanCmd.Type // representing in value of local variable
                                                      ): B = {
    currentSetPoint == setPointApi
  }

  // Traceability: compute currentTempLTSetPoint
  //  -- REQ: If current temperature is less than
  //  --  the current low set point, then the fan state shall be Off
  //  guarantee currentTempLTSetPoint:
  //    currentTemp < currentSetPoint.low implies currentFanState == FanState.Off
  def compute_setPoint_currentTempLTSetPoint_guarantee(
                                                        setPointApi: SetPoint_i, // representing in event data port dispatch value
                                                        currentTempApi: Temperature_i, // representing in data port
                                                        fanCmdApi: Option[FanCmd.Type], // representing out event data port
                                                        latestTemp: Temperature_i, // representing out value of local variable
                                                        latestTempIn: Temperature_i, // representing in value of local variable
                                                        currentSetPoint: SetPoint_i, // representing out value of local variable
                                                        currentSetPointIn: SetPoint_i, // representing in value of local variable
                                                        currentFanState: FanCmd.Type, // representing out value of local variable
                                                        currentFanStateIn: FanCmd.Type // representing in value of local variable
                                                         ): B = {
    (latestTemp.degrees < currentSetPoint.low.degrees) ->:
      (currentFanState == FanCmd.Off)
  }

  // Traceability: compute currentTempGTSetPoint
  //  -- REQ: If current temperature is greater than
  //  --  the current high set point, then the fan state shall be On
  //  guarantee currentTempGTSetPoint:
  //    currentTemp > currentSetPoint.high implies currentFanState == FanState.On
  def compute_setPoint_currentTempGTSetPoint_guarantee(
                                                        setPointApi: SetPoint_i, // representing in event data port dispatch value
                                                        currentTempApi: Temperature_i, // representing in data port
                                                        fanCmdApi: Option[FanCmd.Type], // representing out event data port
                                                        latestTemp: Temperature_i, // representing out value of local variable
                                                        latestTempIn: Temperature_i, // representing in value of local variable
                                                        currentSetPoint: SetPoint_i, // representing out value of local variable
                                                        currentSetPointIn: SetPoint_i, // representing in value of local variable
                                                        currentFanState: FanCmd.Type, // representing out value of local variable
                                                        currentFanStateIn: FanCmd.Type // representing in value of local variable
                                                         ): B = {
    (latestTemp.degrees > currentSetPoint.high.degrees) ->:
      (currentFanState == FanCmd.On)
  }

  // Traceability: compute currentTempInRange
  // -- REQ: If current temperature is greater than or equal to the
  // --  current low set point and less than or equal to the current high set point,
  // --  then the current fan state is maintained.
  def compute_setPoint_currentTempInRange_guarantee(
                                                     setPointApi: SetPoint_i, // representing in event data port dispatch value
                                                     currentTempApi: Temperature_i, // representing in data port
                                                     fanCmdApi: Option[FanCmd.Type], // representing out event data port
                                                     latestTemp: Temperature_i, // representing out value of local variable
                                                     latestTempIn: Temperature_i, // representing in value of local variable
                                                     currentSetPoint: SetPoint_i, // representing out value of local variable
                                                     currentSetPointIn: SetPoint_i, // representing in value of local variable
                                                     currentFanState: FanCmd.Type, // representing out value of local variable
                                                     currentFanStateIn: FanCmd.Type // representing in value of local variable
                                                      ): B = {
    (latestTemp.degrees >= currentSetPoint.low.degrees & latestTemp.degrees <= currentSetPoint.high.degrees) ->:
      (fanCmdApi == None[FanCmd.Type]())
  }

  // Traceability: guarantee compute newFanState guarantee
  //  -- if we updated the local record of the fan state state, then we
  //  -- must send out a new fan command.
  //  Old(currentFanState) != currentFanState implies MustSend[fanCmd|currentFanState]
  def compute_setPoint_newFanState_guarantee(
                                              setPointApi: SetPoint_i, // representing in event data port dispatch value
                                              currentTempApi: Temperature_i, // representing in data port
                                              fanCmdApi: Option[FanCmd.Type], // representing out event data port
                                              latestTemp: Temperature_i, // representing out value of local variable
                                              latestTempIn: Temperature_i, // representing in value of local variable
                                              currentSetPoint: SetPoint_i, // representing out value of local variable
                                              currentSetPointIn: SetPoint_i, // representing in value of local variable
                                              currentFanState: FanCmd.Type, // representing out value of local variable
                                              currentFanStateIn: FanCmd.Type // representing in value of local variable
                                               ): B = {
    (currentFanStateIn != currentFanState) ->:
      (fanCmdApi == Some(currentFanState))
  }

  //=====================================================================
  //  Compute Entry Point  P o s t - C o n d i t i o n   O r a c l e
  //
  //=====================================================================
  def setPoint_oracle(
                          // in event data port (dispatching)
                          setPointApi: SetPoint_i, // representing in event data port dispatch value
                          // in data port
                          currentTempApi: Temperature_i, // representing in event data port dispatch value
                          // out event data ports
                          fanCmdApi: Option[FanCmd.Type], // representing out event data port
                          // local state
                          latestTemp: Temperature_i, // representing out value of local variable
                          latestTempIn: Temperature_i, // representing in value of local variable
                          currentSetPoint: SetPoint_i, // representing out value of local variable
                          currentSetPointIn: SetPoint_i, // representing in value of local variable
                          currentFanState: FanCmd.Type, // representing out value of local variable
                          currentFanStateIn: FanCmd.Type // representing in value of local variable
                        ) : B = {
    val compute_setPoint_currentSetPoint_guarantee_result =
      compute_setPoint_currentSetPoint_guarantee(
        setPointApi, currentTempApi, fanCmdApi,
        latestTemp, latestTempIn, currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
        //  Traceability: guarantee currentTempLTSetPoint
    val compute_setPoint_currentTempLTSetPoint_guarantee_result =
      compute_setPoint_currentTempLTSetPoint_guarantee(
        setPointApi, currentTempApi, fanCmdApi,
        latestTemp, latestTempIn, currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    //  Traceability: guarantee currentTempGTSetPoint
    val compute_setPoint_currentTempGTSetPoint_guarantee_result =
      compute_setPoint_currentTempGTSetPoint_guarantee(
        setPointApi, currentTempApi, fanCmdApi,
        latestTemp, latestTempIn, currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    // Traceability: compute currentTempInRange
    val compute_setPoint_currentTempInRange_guarantee_result =
      compute_setPoint_currentTempInRange_guarantee(
        setPointApi, currentTempApi, fanCmdApi,
        latestTemp, latestTempIn, currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    // Traceability: compute newFanState
    val compute_setPoint_newFanState_guarantee_result =
      compute_setPoint_currentTempInRange_guarantee(
        setPointApi, currentTempApi, fanCmdApi,
        latestTemp, latestTempIn, currentSetPoint, currentSetPointIn, currentFanState, currentFanStateIn)
    return (compute_setPoint_currentSetPoint_guarantee_result &
      compute_setPoint_currentTempLTSetPoint_guarantee_result &
      compute_setPoint_currentTempGTSetPoint_guarantee_result &
      compute_setPoint_currentTempInRange_guarantee_result &
      compute_setPoint_newFanState_guarantee_result)
  }

  //=====================================================================
  //  D a t a    I n v a r i a n t s
  //=====================================================================
  //---------------------------------------------------------------------
  //  Temperature_i  E x e c u t a b l e    I n v a r i a n t
  //
  //   This would probably be generated in the Temperature_i data type
  //---------------------------------------------------------------------
  def temperature_i_invx (temperature_i: Temperature_i): B = {
    // Slang Invariant: Invariant(degrees >= -459.67F)
    temperature_i.degrees >= -459.67f
  }

  //---------------------------------------------------------------------
  //  SetPoint_i  E x e c u t a b l e    I n v a r i a n t
  //
  //   This would probably be generated in the SetPoint_i data type
  //---------------------------------------------------------------------
  def setPoint_i_invx (setPoint_i: SetPoint_i): B = {
    // Slang Invariant: Invariant(
    //  low.degrees >= 50.0f &
    //    high.degrees <= 110.0f &
    //    low.degrees <= high.degrees
    // )
    setPoint_i.low.degrees >= 50.0f &
    setPoint_i.high.degrees <= 110.0f &
    setPoint_i.low.degrees <= setPoint_i.high.degrees
    // ToDo: should this check the invariant for subcomponents?
    //  or will the methodology naturally lead to that already be checked elsewhere?
  }

  //=====================================================================
  //  I n t e g r a t i o n     C o n s t r a i n t s
  //=====================================================================
  //---------------------------------------------------------------------
  //  currentTemp  E x e c u t a b l e    I n t e g r a t i o n     C o n s t r a i n t
  //
  //   This would probably be generated TempControl_i_Api file.
  //---------------------------------------------------------------------
  //   // --- i n p u t s ---
  @strictpure def currentTemp_PAPred(x: Temperature_i): B = {
   // AADL contract: currentTemp.degrees >= -70.0F & currentTemp.degrees <= 180.0F;
    x.degrees >= -70.0f & x.degrees <= 180.0f
  }

  //---------------------------------------------------------------------
  //  setPoint E x e c u t a b l e    I n t e g r a t i o n     C o n s t r a i n t
  //
  //   This would probably be generated TempControl_i_Api file.
  //---------------------------------------------------------------------
  //   // --- i n p u t s ---
  @strictpure def setPoint_PAPred(x: SetPoint_i): B = {
    // no integration constraint is given for setPoint, so contract is trivially true
    true
  }

  //---------------------------------------------------------------------
  //  fanAck E x e c u t a b l e    I n t e g r a t i o n     C o n s t r a i n t
  //
  //   This would probably be generated TempControl_i_Api file.
  //---------------------------------------------------------------------
  //   // --- i n p u t s ---
  @strictpure def fanAck_PAPred(x: FanAck.Type): B = {
    // no integration constraint is given for fanAck, so contract is trivially true
    true
  }

  //---------------------------------------------------------------------
  //  fanCmd E x e c u t a b l e    I n t e g r a t i o n     C o n s t r a i n t
  //
  //   This would probably be generated TempControl_i_Api file.
  //---------------------------------------------------------------------
  //   // --- i n p u t s ---
  @strictpure def fanCmd_PAPred(x: FanCmd.Type): B = {
    // no integration constraint is given for fanCmd, so contract is trivially true
    true
  }
}
