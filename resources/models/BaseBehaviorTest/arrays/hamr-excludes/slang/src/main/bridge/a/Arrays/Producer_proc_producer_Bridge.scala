// #Sireum

package a.Arrays

import org.sireum._
import art._
import a._
import a.Arrays.{Producer_proc_producer => component}

// This file was auto-generated.  Do not edit

@datatype class Producer_proc_producer_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[ISZ[Art.PortId]],

  coordinates: Port[Arrays.Array_of_Coordinates],
  vector_of_coordinates: Port[Arrays.Vector_of_Coordinates],
  integers: Port[Arrays.Array_of_Integers]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    dataIns = ISZ[art.UPort](),

    dataOuts = ISZ[art.UPort](),

    eventIns = ISZ[art.UPort](),

    eventOuts = ISZ[art.UPort](coordinates,
                               vector_of_coordinates,
                               integers)
  )

  val initialization_api : Producer_Initialization_Api = {
    val api = Producer_Initialization_Api(
      id,
      coordinates.id,
      vector_of_coordinates.id,
      integers.id
    )
    Producer_proc_producer_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Producer_Operational_Api = {
    val api = Producer_Operational_Api(
      id,
      coordinates.id,
      vector_of_coordinates.id,
      integers.id
    )
    Producer_proc_producer_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Producer_proc_producer_Bridge.EntryPoints(
      id,

      coordinates.id,
      vector_of_coordinates.id,
      integers.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Producer_proc_producer_Bridge {

  var c_initialization_api: Option[Producer_Initialization_Api] = None()
  var c_operational_api: Option[Producer_Operational_Api] = None()

  @datatype class EntryPoints(
    Producer_proc_producer_BridgeId : Art.BridgeId,
    coordinates_Id : Art.PortId,
    vector_of_coordinates_Id : Art.PortId,
    integers_Id : Art.PortId,
    dispatchTriggers : Option[ISZ[Art.PortId]],
    initialization_api: Producer_Initialization_Api,
    operational_api: Producer_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: ISZ[Art.PortId] = IS()

    val eventInPortIds: ISZ[Art.PortId] = IS()

    val dataOutPortIds: ISZ[Art.PortId] = IS()

    val eventOutPortIds: ISZ[Art.PortId] = IS(coordinates_Id,
                                              vector_of_coordinates_Id,
                                              integers_Id)

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Producer_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def compute(): Unit = {
      Art.receiveInput(eventInPortIds, dataInPortIds)

      // implement the following in 'component':  def timeTriggered(api: Producer_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def activate(): Unit = {
      // implement the following method in 'component':  def activate(api: Producer_Operational_Api): Unit = {}
      component.activate(operational_api)
    }

    def deactivate(): Unit = {
      // implement the following method in 'component':  def deactivate(api: Producer_Operational_Api): Unit = {}
      component.deactivate(operational_api)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: Producer_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    def recover(): Unit = {
      // implement the following method in 'component':  def recover(api: Producer_Operational_Api): Unit = {}
      component.recover(operational_api)
    }

    override
    def testInitialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Producer_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }

    override
    def testCompute(): Unit = {
      Art.receiveInput(eventInPortIds, dataInPortIds)

      // implement the following in 'component':  def timeTriggered(api: Producer_Operational_Api): Unit = {}
      component.timeTriggered(operational_api)

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}