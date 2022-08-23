package TempControlSimpleTemp.TempControlSoftwareSystem

import org.scalatest.funsuite.AnyFunSuite
import org.scalacheck.{Prop, Test}
import org.scalacheck.Test.Parameters
import org.sireum.println
import TempControlSimpleTemp.TempSensor.Temperature_i

class SetPoint_i_Gen_Test extends AnyFunSuite {

  test("SetPoint_i_Gen default") {
    val prop =
      Prop.forAll(SetPoint_i_Gen.default){setPoint_i: SetPoint_i =>
        // Note: printing should show that all temp values satisfy SetPoint_i data invariant, i.e.,
        //   low <= high
        // ...and because some components are of type Temperature_i, they should satisfy the Temperature_i invariant, i.e.,
        //    all greater than or equal to obsolute zero
        println(setPoint_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    // val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose.withMaxDiscardRatio(1000),prop)
    assert(scalaCheckResult.passed)
  }


  test("SetPoint_i_Gen bounded") {
    val prop =
      Prop.forAll(SetPoint_i_Gen.bounded(Temperature_i(50.0f), Temperature_i(110.0f))){setPoint_i: SetPoint_i =>
        // Note: printing should show that all temp values satisfy SetPoint_i data invariant, i.e.,
        //   low <= high
        // ...and because some components are of type Temperature_i, they should satisfy the Temperature_i invariant, i.e.,
        //    all greater than or equal to obsolute zero
        println(setPoint_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }
}
