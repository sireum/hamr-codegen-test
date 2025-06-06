// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp._

// Do not edit this file as it will be overwritten if HAMR codegen is rerun
object TempSensor_i_tcproc_tempSensor_GumboX {
  /** I-Guar: Integration constraint on tempSensor's outgoing data port currentTemp
    *
    * guarantee SensorTemperatureRange
    *   Sensor Temperature Range
    */
  @strictpure def I_Guar_currentTemp(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -50.0f &&
      currentTemp.degrees <= 150.0f

  // I_Guar-Guard: Integration constraint on tempSensor's outgoing data port currentTemp
  @strictpure def I_Guar_Guard_currentTemp(currentTemp: Option[TempSensor.Temperature_i]): B =
    currentTemp.nonEmpty ___>: I_Guar_currentTemp(currentTemp.get)

  /** Initialize Entrypoint Contract
    *
    * guarantee initializes
    * @param api_currentTemp outgoing data port
    */
  @strictpure def initialize_initializes (
      api_currentTemp: TempSensor.Temperature_i): B =
    api_currentTemp.degrees == 72.0f

  /** IEP-Guar: Initialize Entrypoint Contracts for tempSensor
    *
    * @param api_tempChanged outgoing event port
    * @param api_currentTemp outgoing data port
    */
  @strictpure def initialize_IEP_Guar (
      api_tempChanged: Option[art.Empty],
      api_currentTemp: TempSensor.Temperature_i): B =
    initialize_initializes(api_currentTemp)

  /** IEP-Post: Initialize Entrypoint Post-Condition
    *
    * @param api_tempChanged outgoing event port
    * @param api_currentTemp outgoing data port
    */
  @strictpure def inititialize_IEP_Post (
      api_tempChanged: Option[art.Empty],
      api_currentTemp: TempSensor.Temperature_i): B =
    (// D-Inv-Guard: Datatype invariants for the types associated with tempSensor's state variables and outgoing ports
     TempSensor.Temperature_i.D_Inv_Temperature_i(api_currentTemp) & 

     // I-Guar-Guard: Integration constraints for tempSensor's outgoing ports"
     I_Guar_currentTemp(api_currentTemp) & 

     // IEP-Guar: Initialize Entrypoint contract for tempSensor
     initialize_IEP_Guar(api_tempChanged, api_currentTemp))

  /** IEP-Post: Initialize Entrypoint Post-Condition via container
    *
    * @param post Container holding the value of incoming ports and the pre-state values of state variables
    */
  @strictpure def inititialize_IEP_Post_Container (post: TempSensor_i_tcproc_tempSensor_PostState_Container_PS): B =
    inititialize_IEP_Post (
      api_tempChanged = post.api_tempChanged,
      api_currentTemp = post.api_currentTemp)

  /** CEP-Post: Compute Entrypoint Post-Condition for tempSensor
    *
    * @param api_tempChanged outgoing event port
    * @param api_currentTemp outgoing data port
    */
  @strictpure def compute_CEP_Post (
      api_tempChanged: Option[art.Empty],
      api_currentTemp: TempSensor.Temperature_i): B =
    (// D-Inv-Guard: Datatype invariants for the types associated with tempSensor's state variables and outgoing ports
     TempSensor.Temperature_i.D_Inv_Temperature_i(api_currentTemp) & 

     // I-Guar-Guard: Integration constraints for tempSensor's outgoing ports
     I_Guar_currentTemp(api_currentTemp))

  /** CEP-Post: Compute Entrypoint Post-Condition for tempSensor via containers
    *
    * @param pre Container holding the values of incoming ports and the pre-state values of state variables
    * @param post Container holding the values of outgoing ports and the post-state values of state variables
    */
  @strictpure def compute_CEP_Post_Container(
      pre: TempSensor_i_tcproc_tempSensor_PreState_Container_PS,
      post: TempSensor_i_tcproc_tempSensor_PostState_Container_PS): B =
    compute_CEP_Post(
      api_tempChanged = post.api_tempChanged,
      api_currentTemp = post.api_currentTemp)
}
