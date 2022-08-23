package TempControlSimpleTemp.TempSensor

import TempControlSimpleTemp.Base_Types_Gen
import TempControlSimpleTemp.TempControlSoftwareSystem.TempControl_i_tcproc_tempControl_XContracts.temperature_i_invx
import org.scalacheck.Gen

object Temperature_i_Gen {

  // auto-generated
  val simple: Gen[Temperature_i] = for {
    degrees <- Base_Types_Gen.F32.default // generate values for degrees field
    temperature_i = Temperature_i(degrees)
    // only generate values that satisfy executable version
    // of Temperature_i data invariant
    if temperature_i_invx(temperature_i)
  } yield temperature_i

  // auto-generated - bounded generators for Base Types or AADL structs with one field
  //   can easily be auto-generated
  def bounded(low_degrees:Temperature_i, high_degrees:Temperature_i): Gen[Temperature_i] = for {
    n <- Base_Types_Gen.F32.bounded(low_degrees.degrees,high_degrees.degrees)
    temperature_i = Temperature_i(n)
    if temperature_i_invx(temperature_i)
  } yield temperature_i

  // ToDo: Refactor this to be set up from a defined testing profile
  var default = simple
  // val default: Gen[Temperature_i] = bounded(Temperature_i(-459.67f), Temperature_i(1000.0f))
}
