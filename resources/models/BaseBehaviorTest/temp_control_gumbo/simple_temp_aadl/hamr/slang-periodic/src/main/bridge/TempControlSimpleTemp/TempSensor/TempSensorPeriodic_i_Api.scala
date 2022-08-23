// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import art._
import TempControlSimpleTemp._

object TempSensorPeriodic_i_Api {
  @strictpure def Sensor_Temperature_Range(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -50.0f && currentTemp.degrees <= 150.0f
}

import TempSensorPeriodic_i_Api._

@sig trait TempSensorPeriodic_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId

  @spec var currentTemp: TempSensor.Temperature_i = $ // Logika spec var representing port state
  @spec def currentTemp_Inv = Invariant(
    Sensor_Temperature_Range(currentTemp)
  )


  def put_currentTemp(value : TempSensor.Temperature_i) : Unit = {
    Contract(
      Requires(Sensor_Temperature_Range(value)),
      Modifies(currentTemp),
      Ensures(currentTemp == value)
    )
    Spec {
      currentTemp = value
    }

    Art.putValue(currentTemp_Id, TempSensor.Temperature_i_Payload(value))
  }

  def logInfo(msg: String): Unit = {
    Art.logInfo(id, msg)
  }

  def logDebug(msg: String): Unit = {
    Art.logDebug(id, msg)
  }

  def logError(msg: String): Unit = {
    Art.logError(id, msg)
  }
}

@datatype class TempSensorPeriodic_i_Initialization_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId) extends TempSensorPeriodic_i_Api

@datatype class TempSensorPeriodic_i_Operational_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId) extends TempSensorPeriodic_i_Api {

}
