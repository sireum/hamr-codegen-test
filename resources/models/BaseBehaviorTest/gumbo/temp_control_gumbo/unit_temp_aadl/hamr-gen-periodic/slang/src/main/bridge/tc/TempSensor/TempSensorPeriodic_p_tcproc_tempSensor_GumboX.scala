// #Sireum

package tc.TempSensor

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object TempSensorPeriodic_p_tcproc_tempSensor_GumboX {
  /** I-Guar: Integration constraint on tempSensor's outgoing data port currentTemp
    *
    * guarantee Sensor_Temperature_Range
    */
  @strictpure def I_Guar_currentTemp(currentTemp: TempSensor.Temperature_i): B =
    GUMBO_Definitions.GUMBO__Library.isFahrenheit(currentTemp) && currentTemp.degrees >= -50.0f && currentTemp.degrees <= 150.0f

  // I_Guar-Guard: Integration constraint on tempSensor's outgoing data port currentTemp
  @strictpure def I_Guar_Guard_currentTemp(currentTemp: Option[TempSensor.Temperature_i]): B =
    currentTemp.nonEmpty -->: I_Guar_currentTemp(currentTemp.get)

  /** Initialize Entrypoint Contract
    *
    * guarantees initializes
    * @param api_currentTemp port variable
    */
  @strictpure def initialize_initializes (
      api_currentTemp: TempSensor.Temperature_i): B =
    GUMBO_Definitions.GUMBO__Library.isFahrenheit(api_currentTemp) && api_currentTemp.degrees == 72.0f

  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param api_currentTemp port variable
    * @param currentTemp_IEP_Guar port variable
    */
  @strictpure def inititialize_IEP_Post (
      api_currentTemp: TempSensor.Temperature_i,
      currentTemp_IEP_Guar: Option[TempSensor.Temperature_i]): B =
    (// I-Guar-Guard: Integration constraints for tempSensor's outgoing ports
     I_Guar_Guard_currentTemp(currentTemp_IEP_Guar) &

     // D-Inv-Guard: Datatype invariants for the types associated with tempSensor outgoing ports
     TempSensor.Temperature_i_GumboX.D_Inv_Guard_Temperature_i(currentTemp_IEP_Guar) &

     // IEP-Guar: Initialize Entrypoint contract for tempSensor
     initialize_initializes(api_currentTemp))
}
