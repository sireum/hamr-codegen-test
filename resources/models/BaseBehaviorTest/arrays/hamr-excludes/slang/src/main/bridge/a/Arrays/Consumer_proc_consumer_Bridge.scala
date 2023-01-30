// #Sireum

package a.Arrays

import org.sireum._
import art._
import a._
import a.Arrays.{Consumer_proc_consumer => component}

// This file was auto-generated.  Do not edit

@datatype class Consumer_proc_consumer_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[IS[Art.PortId, Art.PortId]],

  coordinates: Port[Arrays.Array_of_Coordinates],
  vector_of_coordinates: Port[Arrays.Vector_of_Coordinates],
  integers: Port[Arrays.Array_of_Integers]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    all = IS[Art.PortId, art.UPort](coordinates,
                                    vector_of_coordinates,
                                    integers),

    dataIns = IS[Art.PortId, art.UPort](),

    dataOuts = IS[Art.PortId, art.UPort](),

    eventIns = IS[Art.PortId, art.UPort](coordinates,
                                         vector_of_coordinates,
                                         integers),

    eventOuts = IS[Art.PortId, art.UPort]()
  )

  val initialization_api : Consumer_Initialization_Api = {
    val api = Consumer_Initialization_Api(
      id,
      coordinates.id,
      vector_of_coordinates.id,
      integers.id
    )
    Consumer_proc_consumer_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Consumer_Operational_Api = {
    val api = Consumer_Operational_Api(
      id,
      coordinates.id,
      vector_of_coordinates.id,
      integers.id
    )
    Consumer_proc_consumer_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Consumer_proc_consumer_Bridge.EntryPoints(
      id,

      coordinates.id,
      vector_of_coordinates.id,
      integers.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Consumer_proc_consumer_Bridge {

  var c_initialization_api: Option[Consumer_Initialization_Api] = None()
  var c_operational_api: Option[Consumer_Operational_Api] = None()

  @datatype class EntryPoints(
    Consumer_proc_consumer_BridgeId : Art.BridgeId,
    coordinates_Id : Art.PortId,
    vector_of_coordinates_Id : Art.PortId,
    integers_Id : Art.PortId,
    dispatchTriggers : Option[IS[Art.PortId, Art.PortId]],
    initialization_api: Consumer_Initialization_Api,
    operational_api: Consumer_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: IS[Art.PortId, Art.PortId] = IS()

    val eventInPortIds: IS[Art.PortId, Art.PortId] = IS(coordinates_Id,
                                                        vector_of_coordinates_Id,
                                                        integers_Id)

    val dataOutPortIds: IS[Art.PortId, Art.PortId] = IS()

    val eventOutPortIds: IS[Art.PortId, Art.PortId] = IS()

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Consumer_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def compute(): Unit = {
      // transpiler friendly filter
      def filter(receivedEvents: IS[Art.PortId, Art.PortId], triggers: IS[Art.PortId, Art.PortId]): IS[Art.PortId, Art.PortId] = {
        var r = IS[Art.PortId, Art.PortId]()
        val opsTriggers = art.ops.ISPOps(triggers)
        for(e <- receivedEvents) {
          if(opsTriggers.contains(e)) {
            r = r :+ e
          }
        }
        return r
      }

      // fetch received events ordered by highest urgency then earliest arrival-time
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Consumer_proc_consumer_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: IS[Art.PortId, Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == coordinates_Id){
          val Some(Arrays.Array_of_Coordinates_Payload(value)) = Art.getValue(coordinates_Id)

          // implement the following in 'component':  def handle_coordinates(api: Consumer_Operational_Api, value: Arrays.Array_of_Coordinates): Unit = {}
          component.handle_coordinates(operational_api, value)
        }
        else if(portId == vector_of_coordinates_Id){
          val Some(Arrays.Vector_of_Coordinates_Payload(value)) = Art.getValue(vector_of_coordinates_Id)

          // implement the following in 'component':  def handle_vector_of_coordinates(api: Consumer_Operational_Api, value: Arrays.Vector_of_Coordinates): Unit = {}
          component.handle_vector_of_coordinates(operational_api, value)
        }
        else if(portId == integers_Id){
          val Some(Arrays.Array_of_Integers_Payload(value)) = Art.getValue(integers_Id)

          // implement the following in 'component':  def handle_integers(api: Consumer_Operational_Api, value: Arrays.Array_of_Integers): Unit = {}
          component.handle_integers(operational_api, value)
        }
      }

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def activate(): Unit = {
      // implement the following method in 'component':  def activate(api: Consumer_Operational_Api): Unit = {}
      component.activate(operational_api)
    }

    def deactivate(): Unit = {
      // implement the following method in 'component':  def deactivate(api: Consumer_Operational_Api): Unit = {}
      component.deactivate(operational_api)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: Consumer_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    def recover(): Unit = {
      // implement the following method in 'component':  def recover(api: Consumer_Operational_Api): Unit = {}
      component.recover(operational_api)
    }

    override
    def testInitialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Consumer_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }

    override
    def testCompute(): Unit = {
      // transpiler friendly filter
      def filter(receivedEvents: IS[Art.PortId, Art.PortId], triggers: IS[Art.PortId, Art.PortId]): IS[Art.PortId, Art.PortId] = {
        var r = IS[Art.PortId, Art.PortId]()
        val opsTriggers = art.ops.ISPOps(triggers)
        for(e <- receivedEvents) {
          if(opsTriggers.contains(e)) {
            r = r :+ e
          }
        }
        return r
      }

      // fetch received events ordered by highest urgency then earliest arrival-time
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Consumer_proc_consumer_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: IS[Art.PortId, Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == coordinates_Id){
          val Some(Arrays.Array_of_Coordinates_Payload(value)) = Art.getValue(coordinates_Id)

          // implement the following in 'component':  def handle_coordinates(api: Consumer_Operational_Api, value: Arrays.Array_of_Coordinates): Unit = {}
          component.handle_coordinates(operational_api, value)
        }
        else if(portId == vector_of_coordinates_Id){
          val Some(Arrays.Vector_of_Coordinates_Payload(value)) = Art.getValue(vector_of_coordinates_Id)

          // implement the following in 'component':  def handle_vector_of_coordinates(api: Consumer_Operational_Api, value: Arrays.Vector_of_Coordinates): Unit = {}
          component.handle_vector_of_coordinates(operational_api, value)
        }
        else if(portId == integers_Id){
          val Some(Arrays.Array_of_Integers_Payload(value)) = Art.getValue(integers_Id)

          // implement the following in 'component':  def handle_integers(api: Consumer_Operational_Api, value: Arrays.Array_of_Integers): Unit = {}
          component.handle_integers(operational_api, value)
        }
      }

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}