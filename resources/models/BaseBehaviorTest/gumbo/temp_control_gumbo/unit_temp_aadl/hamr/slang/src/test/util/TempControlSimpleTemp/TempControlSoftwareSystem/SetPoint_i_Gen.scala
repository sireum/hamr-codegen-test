package TempControlSimpleTemp.TempControlSoftwareSystem

import TempControlSimpleTemp.TempControlSoftwareSystem.TempControl_i_tcproc_tempControl_XContracts.setPoint_i_invx
import TempControlSimpleTemp.TempSensor.Temperature_i_Gen
import TempControlSimpleTemp.TempSensor.Temperature_i
import org.scalacheck.Gen

object SetPoint_i_Gen {

  // Automatically generated
  val simple: Gen[SetPoint_i] = for {
    low <- Temperature_i_Gen.default
    high <- Temperature_i_Gen.default
    setPoint_i = SetPoint_i(low,high)
    if setPoint_i_invx(setPoint_i)
  } yield setPoint_i

  // Manually written
  //   It would be difficult to imagine how this would be automatically generated in general.
  //   If there were bounds for each field individually, that could be auto-generated
  def bounded(lowbound:Temperature_i, highbound:Temperature_i): Gen[SetPoint_i] = for {
    low <- Temperature_i_Gen.bounded(lowbound, highbound)
    high <- Temperature_i_Gen.bounded(lowbound, highbound)
    setPoint_i = SetPoint_i(low, high)
    if setPoint_i_invx(setPoint_i)
  } yield setPoint_i

  // ToDo: Refactor this to be set up from a defined testing profile
  // var default: Gen[SetPoint_i] = simple
  var default = bounded(Temperature_i(50.0f),Temperature_i(110.0f))
}
