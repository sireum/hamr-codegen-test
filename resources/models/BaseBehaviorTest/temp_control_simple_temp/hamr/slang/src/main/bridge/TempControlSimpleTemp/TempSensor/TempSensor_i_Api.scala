// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import art._
import TempControlSimpleTemp._

object TempSensor_i_Api {
  @strictpure def SensorTemperatureRange(currentTemp: TempSensor.Temperature_i): B =
    currentTemp.degrees >= -50.0f && currentTemp.degrees <= 150.0f
}

import TempSensor_i_Api._

@sig trait TempSensor_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId
  def tempChanged_Id : Art.PortId

  // Logika spec var representing port state for outgoing data port
  @spec var currentTemp: TempSensor.Temperature_i = $
  @spec def currentTemp_Inv = Invariant(
    SensorTemperatureRange(currentTemp)
  )

  def put_currentTemp(value : TempSensor.Temperature_i) : Unit = {
    Contract(
      Requires(SensorTemperatureRange(value)),
      Modifies(currentTemp),
      Ensures(currentTemp == value)
    )
    Spec {
      currentTemp = value
    }

    Art.putValue(currentTemp_Id, TempSensor.Temperature_i_Payload(value))
  }

  // Logika spec var representing port state for outgoing event port
  @spec var tempChanged: Option[art.Empty] = $

  def put_tempChanged() : Unit = {
    Contract(
      Modifies(tempChanged),
      Ensures(tempChanged == Some(Empty()))
    )
    Spec {
      tempChanged = Some(Empty())
    }

    Art.putValue(tempChanged_Id, art.Empty())
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

@datatype class TempSensor_i_Initialization_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val tempChanged_Id : Art.PortId) extends TempSensor_i_Api

@datatype class TempSensor_i_Operational_Api (
  val id: Art.BridgeId,
  val currentTemp_Id : Art.PortId,
  val tempChanged_Id : Art.PortId) extends TempSensor_i_Api {

}
