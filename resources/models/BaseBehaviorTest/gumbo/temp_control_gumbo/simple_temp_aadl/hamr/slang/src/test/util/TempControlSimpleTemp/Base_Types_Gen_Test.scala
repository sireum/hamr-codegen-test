package TempControlSimpleTemp

import org.scalatest.funsuite.AnyFunSuite
import org.scalacheck.{Prop, Test}
import org.scalacheck.Test.Parameters
import org.sireum.println
import org.sireum.F32

class Base_Types_Gen_Test extends AnyFunSuite {

  // auto-generated to illustrate the use of Base Type Generators
  test("F32 sampling") {

    // use ScalaCheck "sample" on a generator object to get random values from the generator
    val myF32Gen = Base_Types_Gen.F32.default
    println(s"F32 Sample 1: ${myF32Gen.sample}")
    println(s"F32 Sample 2: ${myF32Gen.sample}")
    println(s"F32 Sample 3: ${myF32Gen.sample}")

    assert(true)
  }

  test("F32 default") {
    val prop =
      Prop.forAll(Base_Types_Gen.F32.default){f32: F32 =>
        // replace code below with call to method, etc. to check with
        // argument f32 here.  Result should be Boolean indicating
        // success or fail
        println(f32)
        true
      }

    // ScalaCheck parameters such as # times to test property, etc. can be tweaked
    // via the parameters below
    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }

  test("F32 bounded [-20,20]") {
    val prop =
      Prop.forAll(Base_Types_Gen.F32.bounded(-20.0f,20.0f)){f32: F32 =>
        // replace code below with call to method, etc. to check with
        // argument f32 here.  Result should be Boolean indicating
        // success or fail
        println(f32)
        true
      }

    // ScalaCheck parameters such as # times to test property, etc. can be tweaked
    // via the parameters below
    val scalaCheckResult: Test.Result = Test.check(Parameters.defaultVerbose,prop)
    assert(scalaCheckResult.passed)
  }
}
