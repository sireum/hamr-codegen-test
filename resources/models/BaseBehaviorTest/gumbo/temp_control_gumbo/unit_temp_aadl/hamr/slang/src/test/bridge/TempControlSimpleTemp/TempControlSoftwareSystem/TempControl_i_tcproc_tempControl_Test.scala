package TempControlSimpleTemp.TempControlSoftwareSystem

import TempControlSimpleTemp.CoolingFan.{FanAck, FanCmd, FanCmd_Gen}
import org.sireum._
import TempControlSimpleTemp.TempControlSoftwareSystem.TempControl_i_tcproc_tempControl_XContracts._
import TempControlSimpleTemp.TempSensor.{Temperature_i, Temperature_i_Gen}
import org.scalacheck.Test.Parameters
import org.scalacheck.Prop
import org.scalacheck.util.ConsoleReporter
import org.scalacheck.Test


// This file will not be overwritten so is safe to edit
class TempControl_i_tcproc_tempControl_Test extends TempControl_i_tcproc_tempControl_TestApi {

  def setPointandCurrentTempInteractions(low: Float, high: Float, current: Float): Unit = {
    //-----------------
    // Interaction 1: cause a set point to be stored in TempControl component's local state
    //-----------------

    // create set point structure
    val low_setPoint = Temperature_i(low)
    val high_setPoint = Temperature_i(high)
    val setPoint = SetPoint_i(low_setPoint,high_setPoint)
    // put setPoint value on input event data port
    put_setPoint(setPoint)
    // execute compute entry point to process updated setPoint
    // ..this will cause the setPoint values to be stored in the
    //   component local state
    executeTest()

    //-----------------
    // Interaction 2: send a temperature value
    //-----------------

    // create current temp value
    val currentTemp = Temperature_i(current)
    // put setPoint value on input data port
    put_currentTemp(currentTemp)
    // put notification of new temp value on input event port
    put_tempChanged()
    // execute compute entry point to process updated setPoint
    // ..this will cause the setPoint values to be stored in the
    //   component local state
    executeTest()
  }

  // CHUT = Convential HAMR Unit Test
  test("CHUT: High after set point; Interaction-based; using helper") {
    // Test outputs of TempControl when temperature received lies
    // above the bounds of the set point region:
    //  ...in such a case, an "On" command should be sent to the Fan
    //  ** This relies on the fact that the default currentFanState is OFF**
    //   (if the default currentFanState was ON, the command would not be sent
    //    because the desired state of the fan already matches the current state of the fan).
    //
    // This scenario is realized using two interactions with the TempControl component.
    //  1. process the set point  (no output to observe)
    //  2. process a current temperature value
    //      (check the output to see that an on command is sent to the fan)
    //

    setPointandCurrentTempInteractions(60.0F, 75.0F, 80.0F)

    //-----------------
    // Check Results
    //-----------------
    val optFanCmd = get_fanCmd()
    // first assert that the fanCmd is not empty (i.e., a command was sent)
    assert(!get_fanCmd().isEmpty)
    // get the command
    val fanCmd = optFanCmd.get
    // assert that then fan cmd is to turn on
    assert(fanCmd == FanCmd.On)
  }

  test("CHUT: Low Temp; explict config of local state") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //   currentTemp = 50.0f
    //   tempChanged event
    //-----------------

    // ------------ s e t    i n p u t s ------------
    // input: set point structure
    val low_setPoint = Temperature_i(60.0F)
    val high_setPoint = Temperature_i(75.0F)
    val setPoint = SetPoint_i(low_setPoint,high_setPoint)
    TempControl_i_tcproc_tempControl.currentSetPoint = setPoint

    // input: force fan to be on, because we we want this interaction to
    //  turn the fan off (a new command is sent to the fan only if the "desired fan state"
    //  changes as a result of the current dispatch
    TempControl_i_tcproc_tempControl.currentFanState = FanCmd.On

    // input: current temp value
    val currentTempApi = Temperature_i(50.0F)
    put_currentTemp(currentTempApi)

    // input: temp changed event
    put_tempChanged()

    // ------------ e x e c u t e     c o m p o n e n t  ------------
    executeTest()

    // ------------ c h e c k   e x p e c t e d   o u t p u t  ------------
    // get output state
    val optFanCmd: Option[FanCmd.Type] = get_fanCmd()

    // check output -- was FanOn command sent?
    // first assert that the fanCmd is not empty (i.e., a command was sent)
    assert(!optFanCmd.isEmpty)
    // get the command
    val fanCmd = optFanCmd.get
    // assert that then fan cmd is to turn off
    assert(fanCmd == FanCmd.Off) // =========== w a s  a n   O F F   c o m m a n d   s e n t ?
  }

  test("XContract: Low Temp; explict config of local state") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //   currentTemp = 50.0f
    //   tempChanged event
    //-----------------

    // ------------ s e t    i n p u t s (local state) ------------
    TempControl_i_tcproc_tempControl.currentSetPoint =
      SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))

    // note: no need to explicitly set currentFanState because testing oracle will
    //  access the initial fan state and condition the contract based on it.
    //  We could have two different tests illustrating starting with the currentFanState
    //  being on or off.

    // ------------ s e t    i n p u t s (conceptual test input and dispatch) ------------
    // input: current temp value
    val currentTempApi = Temperature_i(50.0F)
    put_currentTemp(currentTempApi)

    // input: temp changed event
    put_tempChanged()

    // ------------ e x e c u t e  component and o r a c l e ------------
    assert(currentTemp_execute_and_invoke_oracle(currentTempApi))
  }

  test("XContract: High Temp; explict config of local state") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //   currentTemp = 80.0f
    //   tempChanged event
    //-----------------

    // ------------ s e t    i n p u t s ------------
    TempControl_i_tcproc_tempControl.currentSetPoint =
      SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))

    // input: current temp value
    val currentTempApi = Temperature_i(80.0F)
    put_currentTemp(currentTempApi)

    // input: temp changed event
    put_tempChanged()

    // ------------ e x e c u t e  component and o r a c l e ------------
    assert(currentTemp_execute_and_invoke_oracle(currentTempApi))
  }

  test("XCheck failing test") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //   currentTemp = 50.0f
    //   tempChanged event
    //-----------------

    // ------------ s e t    i n p u t s (local state) ------------
    TempControl_i_tcproc_tempControl.currentSetPoint =
      SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))

    // note: no need to explicitly set currentFanState because testing oracle will
    //  access the initial fan state and condition the contract based on it.
    //  We could have two different tests illustrating starting with the currentFanState
    //  being on or off.

    // ------------ s e t    i n p u t s (conceptual test input and dispatch) ------------
    // input: current temp value
    val currentTempApi = Temperature_i(74.96812f)
    put_currentTemp(currentTempApi)

    // input: temp changed event
    put_tempChanged()

    // ------------ e x e c u t e  component and o r a c l e ------------
    val result = currentTemp_execute_and_invoke_oracle(currentTempApi)
    assert(result)
  }

  test("XContract / ScalaCheck - fixed setPoint") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //-----------------

    val validProperty =
      Prop.forAll(Temperature_i_Gen.default){ temp: Temperature_i =>
        put_currentTemp(temp)
        put_tempChanged()
        currentTemp_execute_and_invoke_oracle(temp)
      }

    // ------------ s e t    i n p u t s ------------
    TempControl_i_tcproc_tempControl.currentSetPoint =
      SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,validProperty)
    assert(scalaCheckResult.passed)
    // TBD:  Fill in what I should do here to define and invoke a Scala Check property verification
//    // input: current temp value
//    val currentTempApi = Temperature_i(80.0F)
//    put_currentTemp(currentTempApi)
//
//    // input: temp changed event
//    put_tempChanged()
//
//    // ------------ e x e c u t e  component and o r a c l e ------------
//    temp_testing_execute_and_invoke_oracle(currentTempApi)
  }



  // Custom invocation of oracle
  def currentTemp_execute_and_invoke_oracle(
                                currentTempApi:Temperature_i,
                                ): Boolean = {
    // get input state of local variables
    val currentSetPointIn: SetPoint_i = TempControl_i_tcproc_tempControl.currentSetPoint
    val currentFanStateIn: FanCmd.Type = TempControl_i_tcproc_tempControl.currentFanState

    // ------------ e x e c u t e    c o m p o n e n t ------------
    executeTest()

    // ------------- i n v o k e     o r a c l e -----------------
    // get output state
    val fanCmdApi: Option[FanCmd.Type] = get_fanCmd()
    val currentSetPoint: SetPoint_i = TempControl_i_tcproc_tempControl.currentSetPoint
    val currentFanState: FanCmd.Type = TempControl_i_tcproc_tempControl.currentFanState

    // call oracle
    tempChanged_oracle(currentTempApi,fanCmdApi,
      currentSetPoint,currentSetPointIn,currentFanState,currentFanStateIn)
  }


  test("XContract - High Temp (Long)") {
    //-----------------
    // Inputs:
    //   set point low = 60.0f and high = 75.0f
    //   currentTemp = 80.0f
    //   tempChanged event
    //-----------------

    // ------------ s e t    i n p u t s ------------
    // input: set point structure
    //    val low_setPoint = Temperature_i(60.0F)
    //    val high_setPoint = Temperature_i(75.0F)
    //    val setPoint = SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))
    TempControl_i_tcproc_tempControl.currentSetPoint = SetPoint_i(Temperature_i(60.0F), Temperature_i(75.0F))

    // input: current temp value
    val currentTempApi = Temperature_i(80.0F)
    put_currentTemp(currentTempApi)

    // input: temp changed event
    put_tempChanged()

    // get input state of local variables
    val currentSetPointIn: SetPoint_i = TempControl_i_tcproc_tempControl.currentSetPoint
    val currentFanStateIn: FanCmd.Type = TempControl_i_tcproc_tempControl.currentFanState

    // ------------ e x e c u t e    c o m p o n e n t ------------
    executeTest()

    // ------------- i n v o k e     o r a c l e -----------------
    // get output state
    val fanCmdApi: Option[FanCmd.Type] = get_fanCmd()
    val currentSetPoint: SetPoint_i = TempControl_i_tcproc_tempControl.currentSetPoint
    val currentFanState: FanCmd.Type = TempControl_i_tcproc_tempControl.currentFanState

    // call oracle
    assert(tempChanged_oracle(currentTempApi,fanCmdApi,
      currentSetPoint,currentSetPointIn,currentFanState,currentFanStateIn))
  }


}
