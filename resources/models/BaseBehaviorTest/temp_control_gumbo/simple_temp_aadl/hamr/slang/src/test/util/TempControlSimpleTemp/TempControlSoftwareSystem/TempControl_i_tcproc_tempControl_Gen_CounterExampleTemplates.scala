package TempControlSimpleTemp.TempControlSoftwareSystem

import TempControlSimpleTemp.CoolingFan.{FanAck, FanCmd}
import TempControlSimpleTemp.TempSensor.{Temperature_i}
import TempControlSimpleTemp.TempControlSoftwareSystem.SetPoint_i

object TempControl_i_tcproc_tempControl_Gen_CounterExampleTemplates {

  def tempChangedDispatch(currentTempApi: Temperature_i,
                          currentSetPoint_in: SetPoint_i,
                          currentFanState_in: FanCmd.Type): String = {
    s"""// GUMBOCheck test for counter-example
       |test("Failing Case: XXX") {
       | assert(tempChanged_harness_setlocals(${currentTempApi}, // currentTemp (in port)
       |                                      ${currentSetPoint_in}, // local state
       |                                      FanCmd.${currentFanState_in} // local state
       |                                      ))
       |}
       |""".stripMargin
  }
}
