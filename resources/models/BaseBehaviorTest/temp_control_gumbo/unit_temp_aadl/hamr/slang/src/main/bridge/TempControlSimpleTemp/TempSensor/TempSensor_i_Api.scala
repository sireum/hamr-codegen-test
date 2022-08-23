// #Sireum

package TempControlSimpleTemp.TempSensor

import org.sireum._
import TempControlSimpleTemp.TempSensor.TempSensor_i_Api.currentTemp_PAPred // ToDo: Robby: why do I need this import.  I would think values in the companion object would be visible.
import art._
import TempControlSimpleTemp._

object TempSensor_i_Api {
  // =====================================================
  //   S p e c    H e l p e r s
  //
  //      - Port Invariant Predicates
  //
  //   Ideally, these should be held in separate files (e.g., one per component)
  //   where they can be referenced by both verification contracts and run-time monitoring.
  //   e.g., ComponentName.Specs.PIName
  // =====================================================

  // representation of port invariant constraints
  //    -- an predicate that should always hold for data flowing across a particular port

  // From Robby: These definitions could also go in the companion object
  //   object C1_Api { ...  }
  //
  //  The c.o. could be imported or referenced directly.

  // predicates for output ports
  @strictpure def currentTemp_PAPred(x: TempSensor.Temperature_i): B = {
    return Defs.TempSensorRange(x)
    // return x.degrees >= -50.0f & x.degrees <= 150.0f
  }

  // predicates for output ports
  @strictpure def currentTemp_PAPredINCOMPSPEC(x: TempSensor.Temperature_i): B = {
    return x.degrees >= -100.0f & x.degrees <= 150.0f
  }
}

@sig trait TempSensor_i_Api {
  def id: Art.BridgeId
  def currentTemp_Id : Art.PortId
  def tempChanged_Id : Art.PortId

  // =====================================================
  //   S p e c i f i c a t i o n    V a r i a b l e s
  //   R e p r e s e n t i n g    P o r t   V a r i a b l e s
  //
  //    with associated invariants
  // =====================================================

  // --- o u t p u t s ---
  @spec var currentTemp: TempSensor.Temperature_i = $
  @spec def currentTemp_Inv = Invariant(
    currentTemp_PAPred(currentTemp)
  )

  // =====================================================
  //   O u t p u t    P o r t    Api
  // =====================================================

  def put_currentTemp(value : TempSensor.Temperature_i) : Unit = {
    Contract(
      // Requires(currentTemp_PAPred(value)),
      Requires(value.degrees >= -50.0f & value.degrees <= 150.0f),
      Modifies(currentTemp),
      // output port variable is set to the value of the parameter
      Ensures(currentTemp == value)
    )
    Spec {
      currentTemp = value
    }
    Art.putValue(currentTemp_Id, TempSensor.Temperature_i_Payload(value))
  }

  def put_tempChanged() : Unit = {
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
