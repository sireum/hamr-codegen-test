package TempControlSimpleTemp.TempSensor

import org.scalatest.funsuite.AnyFunSuite
import org.scalacheck.{Prop, Test}
import org.scalacheck.Test.Parameters
import org.sireum.println
import org.scalacheck.Gen
import org.scalacheck.rng.Seed

class Temperature_i_Gen_Test extends AnyFunSuite {

  test("Temperature_i sampling") {
    // use ScalaCheck "sample" on a generator object to get random values from the generator
    val myGen = Temperature_i_Gen.default
    println(s"Temperature_i Sample 1: ${myGen.sample}")
    // println(s"Temperature_i Sample 1: ${myGen.doPureApply(Gen.Parameters.default,Seed.random(),1000).retrieve}")
    println(s"Temperature_i Sample 2: ${myGen.sample}")
    // println(s"Temperature_i Sample 2: ${myGen.doPureApply(Gen.Parameters.default,Seed.random(),1000).retrieve}")
    println(s"Temperature_i Sample 3: ${myGen.sample}")
    // println(s"Temperature_i Sample 2: ${myGen.doPureApply(Gen.Parameters.default,Seed.random(),1000).retrieve}")
    assert(true)
  }

  test("Temperature_i_Gen default") {
    val tempProp =
      Prop.forAll(Temperature_i_Gen.default){temperature_i: Temperature_i =>
        // Note: printing should show that all temp values satisfy Temperature_i data invariant, i.e.,
        //   all temperature values are above absolute zero (>= -459.67)
        println(temperature_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,tempProp)
    assert(scalaCheckResult.passed)
  }

  test("Temperature_i_Gen bounded") {
    val tempProp =
      Prop.forAll(Temperature_i_Gen.bounded(Temperature_i(-50.0f),Temperature_i(90.0f))){temperature_i: Temperature_i =>
        // Note: printing should show that all temp values satisfy Temperature_i data invariant, i.e.,
        //   all temperature values are above absolute zero (>= -459.67)
        println(temperature_i)
        true
      }

    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,tempProp)
    assert(scalaCheckResult.passed)
  }
}
