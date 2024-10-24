// #Sireum

package TempControlSimpleTemp.TempControlSoftwareSystem

import org.sireum._
import art._
import TempControlSimpleTemp._
import TempControlSimpleTemp.TempControlSoftwareSystem.{OperatorInterface_i_tcproc_operatorInterface => component}

// This file was auto-generated.  Do not edit

@datatype class OperatorInterface_i_tcproc_operatorInterface_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[ISZ[Art.PortId]],

  currentTemp: Port[TempSensor.Temperature_i],
  setPoint: Port[TempControlSoftwareSystem.SetPoint_i],
  tempChanged: Port[art.Empty]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    all = ISZ(currentTemp,
              setPoint,
              tempChanged),

    dataIns = ISZ(currentTemp),

    dataOuts = ISZ(),

    eventIns = ISZ(tempChanged),

    eventOuts = ISZ(setPoint)
  )

  val initialization_api : OperatorInterface_i_Initialization_Api = {
    val api = OperatorInterface_i_Initialization_Api(
      id,
      currentTemp.id,
      setPoint.id,
      tempChanged.id
    )
    OperatorInterface_i_tcproc_operatorInterface_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : OperatorInterface_i_Operational_Api = {
    val api = OperatorInterface_i_Operational_Api(
      id,
      currentTemp.id,
      setPoint.id,
      tempChanged.id
    )
    OperatorInterface_i_tcproc_operatorInterface_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    OperatorInterface_i_tcproc_operatorInterface_Bridge.EntryPoints(
      id,

      currentTemp.id,
      setPoint.id,
      tempChanged.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object OperatorInterface_i_tcproc_operatorInterface_Bridge {

  var c_initialization_api: Option[OperatorInterface_i_Initialization_Api] = None()
  var c_operational_api: Option[OperatorInterface_i_Operational_Api] = None()

  @datatype class EntryPoints(
    OperatorInterface_i_tcproc_operatorInterface_BridgeId : Art.BridgeId,

    currentTemp_Id : Art.PortId,
    setPoint_Id : Art.PortId,
    tempChanged_Id : Art.PortId,

    dispatchTriggers : Option[ISZ[Art.PortId]],

    initialization_api: OperatorInterface_i_Initialization_Api,
    operational_api: OperatorInterface_i_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: ISZ[Art.PortId] = ISZ(currentTemp_Id)

    val eventInPortIds: ISZ[Art.PortId] = ISZ(tempChanged_Id)

    val dataOutPortIds: ISZ[Art.PortId] = ISZ()

    val eventOutPortIds: ISZ[Art.PortId] = ISZ(setPoint_Id)

    def compute(): Unit = {
      Art.receiveInput(eventInPortIds, dataInPortIds)

      // implement the following in 'component':  def timeTriggered(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    override
    def testCompute(): Unit = {
      Art.receiveInput(eventInPortIds, dataInPortIds)

      // implement the following in 'component':  def timeTriggered(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }

    def activate(): Unit = {
      // implement the following method in 'component':  def activate(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.activate(operational_api)
    }

    def deactivate(): Unit = {
      // implement the following method in 'component':  def deactivate(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.deactivate(operational_api)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: OperatorInterface_i_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def recover(): Unit = {
      // implement the following method in 'component':  def recover(api: OperatorInterface_i_Operational_Api): Unit = {}
      component.recover(operational_api)
    }
  }
}