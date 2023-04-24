// #Sireum

package tc.TempSensor

import org.sireum._
import tc._

// This file was auto-generated.  Do not edit
object TempSensor_s_tcproc_tempSensor_GumboX {
  /** I-Guar: Integration constraint on tempSensor's outgoing data port currentTemp
    *
    * guarantee Sensor_Temperature_Range
    */
  @strictpure def I_Guar_currentTemp(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -50.0f && currentTemp.degrees <= 150.0f && currentTemp.degrees >= TempSensor_s_tcproc_tempSensor.minTempDegrees() && currentTemp.degrees >= TempSensor.GUMBO__Library.gminTempDegrees() && currentTemp.degrees >= TempSensor.GUMBO__Library.gminTempDegrees() && GUMBO_Definitions.GUMBO__Library.inRange(currentTemp)

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
    api_currentTemp.degrees == 72.0f && api_currentTemp.degrees == TempSensor_s_tcproc_tempSensor.defaultTempDegrees() && api_currentTemp == TempSensor.Temperature.i(TempSensor_s_tcproc_tempSensor.defaultTempDegrees()) && api_currentTemp == TempSensor.Temperature.i(TempSensor_s_tcproc_tempSensor.defaultTempDegrees())

  /** Initialize Entrypoint Contract
    *
    * guarantees g1
    *   Testing MustSend with event port, initializes so no event expected
    * @param api_tempChanged port variable
    */
  @strictpure def initialize_g1 (
      api_tempChanged: Option[art.Empty]): B =
    !(api_tempChanged.nonEmpty)

  /** Initialize Entrypoint Contract
    *
    * guarantees g2
    *   Testing NoSend with event port, initializes so no event expected
    * @param api_tempChanged port variable
    */
  @strictpure def initialize_g2 (
      api_tempChanged: Option[art.Empty]): B =
    api_tempChanged.isEmpty

  /** IEP-Guar: Initialize Entrypoint Contracts for tempSensor
    *
    * @param api_currentTemp port variable
    * @param api_tempChanged port variable
    */
  @strictpure def initialize_IEP_Guar (
      api_currentTemp: TempSensor.Temperature_i,
      api_tempChanged: Option[art.Empty]): B =
    initialize_initializes(api_currentTemp) &
    initialize_g1(api_tempChanged) &
    initialize_g2(api_tempChanged)

  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param api_currentTemp port variable
    * @param api_tempChanged port variable
    * @param currentTemp_IEP_Guar port variable
    */
  @strictpure def inititialize_IEP_Post (
      api_currentTemp: TempSensor.Temperature_i,
      api_tempChanged: Option[art.Empty],
      currentTemp_IEP_Guar: Option[TempSensor.Temperature_i]): B =
    (// I-Guar-Guard: Integration constraints for tempSensor's outgoing ports
     I_Guar_Guard_currentTemp(currentTemp_IEP_Guar) &

     // D-Inv-Guard: Datatype invariants for the types associated with tempSensor outgoing ports
     TempSensor.Temperature_i_GumboX.D_Inv_Guard_Temperature_i(currentTemp_IEP_Guar) &

     // IEP-Guar: Initialize Entrypoint contract for tempSensor
     initialize_IEP_Guar(api_currentTemp, api_tempChanged))
}
