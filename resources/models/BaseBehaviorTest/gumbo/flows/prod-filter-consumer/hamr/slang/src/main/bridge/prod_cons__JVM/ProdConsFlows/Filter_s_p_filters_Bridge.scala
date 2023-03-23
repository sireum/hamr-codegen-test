// #Sireum

package prod_cons__JVM.ProdConsFlows

import org.sireum._
import art._
import prod_cons__JVM._
import prod_cons__JVM.ProdConsFlows.{Filter_s_p_filters => component}

// This file was auto-generated.  Do not edit

@datatype class Filter_s_p_filters_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[ISZ[Art.PortId]],

  a_in: Port[Base_Types.Float_32],
  b_in: Port[Base_Types.Float_32],
  a_out: Port[Base_Types.Float_32],
  b_out: Port[Base_Types.Float_32]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    dataIns = ISZ[art.UPort](),

    dataOuts = ISZ[art.UPort](),

    eventIns = ISZ[art.UPort](a_in,
                              b_in),

    eventOuts = ISZ[art.UPort](a_out,
                               b_out)
  )

  val initialization_api : Filter_s_Initialization_Api = {
    val api = Filter_s_Initialization_Api(
      id,
      a_in.id,
      b_in.id,
      a_out.id,
      b_out.id
    )
    Filter_s_p_filters_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Filter_s_Operational_Api = {
    val api = Filter_s_Operational_Api(
      id,
      a_in.id,
      b_in.id,
      a_out.id,
      b_out.id
    )
    Filter_s_p_filters_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Filter_s_p_filters_Bridge.EntryPoints(
      id,

      a_in.id,
      b_in.id,
      a_out.id,
      b_out.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Filter_s_p_filters_Bridge {

  var c_initialization_api: Option[Filter_s_Initialization_Api] = None()
  var c_operational_api: Option[Filter_s_Operational_Api] = None()

  @datatype class EntryPoints(
    Filter_s_p_filters_BridgeId : Art.BridgeId,
    a_in_Id : Art.PortId,
    b_in_Id : Art.PortId,
    a_out_Id : Art.PortId,
    b_out_Id : Art.PortId,
    dispatchTriggers : Option[ISZ[Art.PortId]],
    initialization_api: Filter_s_Initialization_Api,
    operational_api: Filter_s_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: ISZ[Art.PortId] = IS()

    val eventInPortIds: ISZ[Art.PortId] = IS(a_in_Id,
                                             b_in_Id)

    val dataOutPortIds: ISZ[Art.PortId] = IS()

    val eventOutPortIds: ISZ[Art.PortId] = IS(a_out_Id,
                                              b_out_Id)

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Filter_s_Initialization_Api): Unit = {}
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
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Filter_s_p_filters_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: ISZ[Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == a_in_Id){
          val Some(Base_Types.Float_32_Payload(value)) = Art.getValue(a_in_Id)

          // implement the following in 'component':  def handle_a_in(api: Filter_s_Operational_Api, value: Base_Types.Float_32): Unit = {}
          component.handle_a_in(operational_api, value)
        }
        else if(portId == b_in_Id){
          val Some(Base_Types.Float_32_Payload(value)) = Art.getValue(b_in_Id)

          // implement the following in 'component':  def handle_b_in(api: Filter_s_Operational_Api, value: Base_Types.Float_32): Unit = {}
          component.handle_b_in(operational_api, value)
        }
      }

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def activate(): Unit = {
      // implement the following method in 'component':  def activate(api: Filter_s_Operational_Api): Unit = {}
      component.activate(operational_api)
    }

    def deactivate(): Unit = {
      // implement the following method in 'component':  def deactivate(api: Filter_s_Operational_Api): Unit = {}
      component.deactivate(operational_api)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: Filter_s_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    def recover(): Unit = {
      // implement the following method in 'component':  def recover(api: Filter_s_Operational_Api): Unit = {}
      component.recover(operational_api)
    }

    override
    def testInitialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Filter_s_Initialization_Api): Unit = {}
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
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Filter_s_p_filters_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: ISZ[Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == a_in_Id){
          val Some(Base_Types.Float_32_Payload(value)) = Art.getValue(a_in_Id)

          // implement the following in 'component':  def handle_a_in(api: Filter_s_Operational_Api, value: Base_Types.Float_32): Unit = {}
          component.handle_a_in(operational_api, value)
        }
        else if(portId == b_in_Id){
          val Some(Base_Types.Float_32_Payload(value)) = Art.getValue(b_in_Id)

          // implement the following in 'component':  def handle_b_in(api: Filter_s_Operational_Api, value: Base_Types.Float_32): Unit = {}
          component.handle_b_in(operational_api, value)
        }
      }

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}