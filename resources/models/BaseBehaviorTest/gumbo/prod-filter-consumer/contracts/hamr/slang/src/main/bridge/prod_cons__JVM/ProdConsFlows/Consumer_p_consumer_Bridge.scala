// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._
import prod_cons__JVM.ProdConsFlows.{Consumer_p_consumer => component}

// Do not edit this file as it will be overwritten if HAMR codegen is rerun

@datatype class Consumer_p_consumer_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[ISZ[Art.PortId]],

  e_data_in: Port[ProdConsFlows.Container_i],
  f_event_data_in: Port[ProdConsFlows.Container_i],
  g_event_data_in: Port[ProdConsFlows.Container_i],
  h_event_in: Port[art.Empty]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    dataIns = ISZ[art.UPort](e_data_in),

    dataOuts = ISZ[art.UPort](),

    eventIns = ISZ[art.UPort](f_event_data_in,
                              g_event_data_in,
                              h_event_in),

    eventOuts = ISZ[art.UPort]()
  )

  val initialization_api : Consumer_Initialization_Api = {
    val api = Consumer_Initialization_Api(
      id,
      e_data_in.id,
      f_event_data_in.id,
      g_event_data_in.id,
      h_event_in.id
    )
    Consumer_p_consumer_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Consumer_Operational_Api = {
    val api = Consumer_Operational_Api(
      id,
      e_data_in.id,
      f_event_data_in.id,
      g_event_data_in.id,
      h_event_in.id
    )
    Consumer_p_consumer_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Consumer_p_consumer_Bridge.EntryPoints(
      id,

      e_data_in.id,
      f_event_data_in.id,
      g_event_data_in.id,
      h_event_in.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Consumer_p_consumer_Bridge {

  var c_initialization_api: Option[Consumer_Initialization_Api] = None()
  var c_operational_api: Option[Consumer_Operational_Api] = None()

  @datatype class EntryPoints(
    Consumer_p_consumer_BridgeId : Art.BridgeId,
    e_data_in_Id : Art.PortId,
    f_event_data_in_Id : Art.PortId,
    g_event_data_in_Id : Art.PortId,
    h_event_in_Id : Art.PortId,
    dispatchTriggers : Option[ISZ[Art.PortId]],
    initialization_api: Consumer_Initialization_Api,
    operational_api: Consumer_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: ISZ[Art.PortId] = IS(e_data_in_Id)

    val eventInPortIds: ISZ[Art.PortId] = IS(f_event_data_in_Id,
                                             g_event_data_in_Id,
                                             h_event_in_Id)

    val dataOutPortIds: ISZ[Art.PortId] = IS()

    val eventOutPortIds: ISZ[Art.PortId] = IS()

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Consumer_Initialization_Api): Unit = {}
      component.initialise(initialization_api)
      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def compute(): Unit = {
      // transpiler friendly filter
      def filter(receivedEvents: ISZ[Art.PortId], triggers: ISZ[Art.PortId]): ISZ[Art.PortId] = {
        var r = ISZ[Art.PortId]()
        val opsTriggers = ops.ISZOps(triggers)
        for(e <- receivedEvents) {
          if(opsTriggers.contains(e)) {
            r = r :+ e
          }
        }
        return r
      }

      // fetch received events ordered by highest urgency then earliest arrival-time
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Consumer_p_consumer_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: ISZ[Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == f_event_data_in_Id){
          val Some(ProdConsFlows.Container_i_Payload(value)) = Art.getValue(f_event_data_in_Id)

          // implement the following in 'component':  def handle_f_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {}
          component.handle_f_event_data_in(operational_api, value)
        }
        else if(portId == g_event_data_in_Id){
          val Some(ProdConsFlows.Container_i_Payload(value)) = Art.getValue(g_event_data_in_Id)

          // implement the following in 'component':  def handle_g_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {}
          component.handle_g_event_data_in(operational_api, value)
        }
        else if(portId == h_event_in_Id) {
          // implement the following in 'component':  def handle_h_event_in(api: Consumer_Operational_Api): Unit = {}
          component.handle_h_event_in(operational_api)
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
      def filter(receivedEvents: ISZ[Art.PortId], triggers: ISZ[Art.PortId]): ISZ[Art.PortId] = {
        var r = ISZ[Art.PortId]()
        val opsTriggers = ops.ISZOps(triggers)
        for(e <- receivedEvents) {
          if(opsTriggers.contains(e)) {
            r = r :+ e
          }
        }
        return r
      }

      // fetch received events ordered by highest urgency then earliest arrival-time
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Consumer_p_consumer_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: ISZ[Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == f_event_data_in_Id){
          val Some(ProdConsFlows.Container_i_Payload(value)) = Art.getValue(f_event_data_in_Id)

          // implement the following in 'component':  def handle_f_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {}
          component.handle_f_event_data_in(operational_api, value)
        }
        else if(portId == g_event_data_in_Id){
          val Some(ProdConsFlows.Container_i_Payload(value)) = Art.getValue(g_event_data_in_Id)

          // implement the following in 'component':  def handle_g_event_data_in(api: Consumer_Operational_Api, value: ProdConsFlows.Container_i): Unit = {}
          component.handle_g_event_data_in(operational_api, value)
        }
        else if(portId == h_event_in_Id) {
          // implement the following in 'component':  def handle_h_event_in(api: Consumer_Operational_Api): Unit = {}
          component.handle_h_event_in(operational_api)
        }
      }

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}