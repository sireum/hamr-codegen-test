//============================================================
//  TempControl_i_tcproc_tempControl_Gen.scala
//
//     Generators for input ports and spec local state
//     of TempControl component
//============================================================

package TempControlSimpleTemp.TempControlSoftwareSystem

import TempControlSimpleTemp.TempControlSoftwareSystem.TempControl_i_tcproc_tempControl_XContracts.setPoint_PAPred
import TempControlSimpleTemp.TempSensor.Temperature_i
import org.scalacheck.Gen
import org.scalacheck.Gen._

object TempControl_i_tcproc_tempControl_Gen {

  //====== Generators for ports ========

  import TempControlSimpleTemp.Base_Types_Gen
  import TempControlSimpleTemp.TempControlSoftwareSystem.TempControl_i_tcproc_tempControl_XContracts.currentTemp_PAPred
  import org.scalacheck.Gen

  // -- Generators for currentTemp port
  object currentTemp_port {

    // auto-generated
    //  Generator for the current temp port built from port type (data component) that satisfies
    //  the invariant for the port data type as well as the port assertion
    val simple: Gen[Temperature_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      temperature_i <- TempControlSimpleTemp.TempSensor.Temperature_i_Gen.default
      // apply the integration constraint for the port to filter out output values
      if currentTemp_PAPred(temperature_i)
    } yield temperature_i

    // auto-generated (conjecture)
    //  for ports with simple data types, we should be able to auto-generate a bounded version
    //  of the generator
    def bounded(low_currentTemp: Temperature_i, high_currentTemp: Temperature_i): Gen[Temperature_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      temperature_i <- TempControlSimpleTemp.TempSensor.Temperature_i_Gen.bounded(low_currentTemp, high_currentTemp)
      // apply the integration constraint for the port to filter out output values
      if currentTemp_PAPred(temperature_i)
    } yield temperature_i

    // Auto-generated
    //  DEMO: Uncomment the generator definition below to illustrate the inability of the
    //  framework to generate enough values to satisfy the constraints from the datatype and port assertion
    // val default: Gen[Temperature_i] = simple

    // Hand-customized for efficiency
    //   Align generator bounds with range constraints in port assertion
    //   x.degrees >= -70.0f & x.degrees <= 180.0f
    val default: Gen[Temperature_i] = bounded(Temperature_i(-70.0f), Temperature_i(180.0f))

    //================================================================
    //   Fault model illustration
    //================================================================

    // Hand-built by component developer to give fault model semantics for "belowRange" AADL error type
    //  on this port.   Could be automated to some extent if data range is explict in the contract.
    val belowRange: Gen[Temperature_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      temperature_i <- TempControlSimpleTemp.TempSensor.Temperature_i_Gen.default
      // apply the integration constraint for the port to filter out output values
      //   x.degrees >= -70.0f & x.degrees <= 180.0f
      if temperature_i.degrees < -70.0f
    } yield temperature_i

    // Hand-built by component developer to give fault model semantics for "belowRange" AADL error type
    //  on this port.   Could be automated to some extent if data range is explict in the contract.
    val aboveRange: Gen[Temperature_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      temperature_i <- TempControlSimpleTemp.TempSensor.Temperature_i_Gen.default
      // apply the integration constraint for the port to filter out output values
      //   x.degrees >= -70.0f & x.degrees <= 180.0f
      if temperature_i.degrees > 180.0f
    } yield temperature_i

    // Temperature values with belowRange and aboveRange faults (distribution currently hard-coded)
    val faultModel: Gen[Temperature_i] = for {
      // 5% below
      // 5% above
      // 90% in range

      faultModelGen <- Gen.frequency(
        (1, belowRange),
        (1, aboveRange),
        (20, default)
      )
    } yield faultModelGen
  }

  // -- Generators for setPoint_port port
  object setPoint_port {

    // auto-generated
    //  Generator for the current temp port built from port type (data component) that satisfies
    //  the invariant for the port data type as well as the port assertion
    val simple: Gen[SetPoint_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      setPoint_i <- TempControlSimpleTemp.TempControlSoftwareSystem.SetPoint_i_Gen.default
      // apply the integration constraint for the port to filter out output values
      if setPoint_PAPred(setPoint_i)
    } yield setPoint_i

    // manually written -- it would be hard to see how to generate a bounded version of this
    //  ToDo:
    //   Consider a low value and a high value for each field.
    //   In what is written below, we have "hand optimized" taking advantage of the fact that the
    //   low field is always less than the high field.
    def bounded(low_temp: Temperature_i, high_temp: Temperature_i): Gen[SetPoint_i] = for {
      // pattern: use the default generator for the data type of the port to generate values for the port
      setPoint_i <- TempControlSimpleTemp.TempControlSoftwareSystem.SetPoint_i_Gen.bounded(low_temp, high_temp)
      // apply the integration constraint for the port to filter out output values
      if setPoint_PAPred(setPoint_i)
    } yield setPoint_i

    // Auto-generated
    //  DEMO: Uncomment the generator definition below to illustrate the inability of the
    //  framework to generate enough values to satisfy the constraints from the datatype and port assertion
    // val default: Gen[Temperature_i] = simple

    // Hand-customized for efficiency
    //   Align generator bounds with range constraints in port assertion
    //   x.degrees >= -70.0f & x.degrees <= 180.0f
    val default: Gen[SetPoint_i] = bounded(Temperature_i(-70.0f), Temperature_i(180.0f))
  }

  object tempChanged_port {

    // ToDo

  }



  // ToDo:
  //  Next up -
  //    generator for tempChanged event port
  //    generators for SetPoint and FanAck in event data ports
  //    generators for exposed local state values
}
