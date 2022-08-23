//============================================================
//  TempControl_i_tcproc_tempControl_Gen_Test.scala
//
//     Simple unit tests to illustrate behavior of auto-generators
//     for TempControl component
//============================================================

package TempControlSimpleTemp.TempControlSoftwareSystem

import TempControlSimpleTemp.TempSensor.Temperature_i
import TempControlSimpleTemp.CoolingFan.{FanAck, FanCmd, FanCmd_Gen}
import org.scalatest.funsuite.AnyFunSuite
import org.scalacheck.{Prop, Test}
import org.scalacheck.Test.Parameters
import org.sireum.println

class TempControl_i_tcproc_tempControl_Gen_Test extends AnyFunSuite {

  // auto-generated
  // Illustrate generator for currentTemp input data port
  test("currentTemp Gen default") {
    val prop =
      Prop.forAll(TempControl_i_tcproc_tempControl_Gen.currentTemp_port.default){temperature_i: Temperature_i =>
        // Note: printing should show that all temp values satisfy currentTemp integration invariant
        println(temperature_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }

  // auto-generated
  // Illustrate generator for setPoint input event data port payload/value
  test("setPoint Gen default") {
    val prop =
      Prop.forAll(TempControl_i_tcproc_tempControl_Gen.setPoint_port.default){setPoint_i: SetPoint_i =>
        println(setPoint_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }

  // auto-generated
  test("tempChanged dispatch") {
    val prop =
      Prop.forAll(// null input for tempChange (no data on event port)
                  // generator for in data port (generated values should satisfy data invariant and port invariant)
                  TempControl_i_tcproc_tempControl_Gen.currentTemp_port.default,
                  // ToDo: This could/should be replaced by a generator for a tuple of local state variables
                  //   that satisfies the component invariants.
                  // generator for in component variable currentSetPoint
                  SetPoint_i_Gen.default,
                  // generator for in component variable currentFanState
                  FanCmd_Gen.default
      ){(temperature_i: Temperature_i, currentSetPoint: SetPoint_i, currentFanState: FanCmd.Type)  =>
        // println(temperature_i, currentSetPoint, currentFanState)

        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }
}
