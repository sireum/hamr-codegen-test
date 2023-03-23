package TempControlSimpleTemp.CoolingFan

import org.scalatest.funsuite.AnyFunSuite
import org.scalacheck.{Prop, Test}
import org.scalacheck.Test.Parameters
import org.sireum.println

class FanCmd_Gen_Test extends AnyFunSuite {
  test("FanCmd_Gen default") {
    val prop =
      Prop.forAll(FanCmd_Gen.default){fanCmd: FanCmd.Type =>
        println(fanCmd)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }
}
