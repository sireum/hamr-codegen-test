// #Sireum

package TempControlSimpleTemp.CoolingFan

import org.sireum._
import art._
import TempControlSimpleTemp._
import TempControlSimpleTemp.CoolingFan.{Fan_i_tcproc_fan => component}

// This file was auto-generated.  Do not edit

@datatype class Fan_i_tcproc_fan_Bridge(
  val id: Art.BridgeId,
  val name: String,
  val dispatchProtocol: DispatchPropertyProtocol,
  val dispatchTriggers: Option[IS[Art.PortId, Art.PortId]],

  fanCmd: Port[CoolingFan.FanCmd.Type],
  fanAck: Port[CoolingFan.FanAck.Type]
  ) extends Bridge {

  val ports : Bridge.Ports = Bridge.Ports(
    all = IS[Art.PortId, art.UPort](fanCmd,
                                    fanAck),

    dataIns = IS[Art.PortId, art.UPort](),

    dataOuts = IS[Art.PortId, art.UPort](),

    eventIns = IS[Art.PortId, art.UPort](fanCmd),

    eventOuts = IS[Art.PortId, art.UPort](fanAck)
  )

  val initialization_api : Fan_i_Initialization_Api = {
    val api = Fan_i_Initialization_Api(
      id,
      fanCmd.id,
      fanAck.id
    )
    Fan_i_tcproc_fan_Bridge.c_initialization_api = Some(api)
    api
  }

  val operational_api : Fan_i_Operational_Api = {
    val api = Fan_i_Operational_Api(
      id,
      fanCmd.id,
      fanAck.id
    )
    Fan_i_tcproc_fan_Bridge.c_operational_api = Some(api)
    api
  }

  val entryPoints : Bridge.EntryPoints =
    Fan_i_tcproc_fan_Bridge.EntryPoints(
      id,

      fanCmd.id,
      fanAck.id,

      dispatchTriggers,

      initialization_api,
      operational_api)
}

object Fan_i_tcproc_fan_Bridge {

  var c_initialization_api: Option[Fan_i_Initialization_Api] = None()
  var c_operational_api: Option[Fan_i_Operational_Api] = None()

  @datatype class EntryPoints(
    Fan_i_tcproc_fan_BridgeId : Art.BridgeId,
    fanCmd_Id : Art.PortId,
    fanAck_Id : Art.PortId,
    dispatchTriggers : Option[IS[Art.PortId, Art.PortId]],
    initialization_api: Fan_i_Initialization_Api,
    operational_api: Fan_i_Operational_Api) extends Bridge.EntryPoints {

    val dataInPortIds: IS[Art.PortId, Art.PortId] = IS()

    val eventInPortIds: IS[Art.PortId, Art.PortId] = IS(fanCmd_Id)

    val dataOutPortIds: IS[Art.PortId, Art.PortId] = IS()

    val eventOutPortIds: IS[Art.PortId, Art.PortId] = IS(fanAck_Id)

    def initialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Fan_i_Initialization_Api): Unit = {}
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
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Fan_i_tcproc_fan_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: IS[Art.PortId, Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == fanCmd_Id){
          val Some(CoolingFan.FanCmd_Payload(value)) = Art.getValue(fanCmd_Id)

          // implement the following in 'component':  def handle_fanCmd(api: Fan_i_Operational_Api, value: CoolingFan.FanCmd.Type): Unit = {}
          component.handle_fanCmd(operational_api, value)
        }
      }

      Art.sendOutput(eventOutPortIds, dataOutPortIds)
    }

    def activate(): Unit = {
      // implement the following method in 'component':  def activate(api: Fan_i_Operational_Api): Unit = {}
      component.activate(operational_api)
    }

    def deactivate(): Unit = {
      // implement the following method in 'component':  def deactivate(api: Fan_i_Operational_Api): Unit = {}
      component.deactivate(operational_api)
    }

    def finalise(): Unit = {
      // implement the following method in 'component':  def finalise(api: Fan_i_Operational_Api): Unit = {}
      component.finalise(operational_api)
    }

    def recover(): Unit = {
      // implement the following method in 'component':  def recover(api: Fan_i_Operational_Api): Unit = {}
      component.recover(operational_api)
    }

    override
    def testInitialise(): Unit = {
      // implement the following method in 'component':  def initialise(api: Fan_i_Initialization_Api): Unit = {}
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
      val EventTriggered(receivedEvents) = Art.dispatchStatus(Fan_i_tcproc_fan_BridgeId)

      // remove non-dispatching event ports
      val dispatchableEventPorts: IS[Art.PortId, Art.PortId] =
        if(dispatchTriggers.isEmpty) receivedEvents
        else filter(receivedEvents, dispatchTriggers.get)

      Art.receiveInput(eventInPortIds, dataInPortIds)

      for(portId <- dispatchableEventPorts) {
        if(portId == fanCmd_Id){
          val Some(CoolingFan.FanCmd_Payload(value)) = Art.getValue(fanCmd_Id)

          // implement the following in 'component':  def handle_fanCmd(api: Fan_i_Operational_Api, value: CoolingFan.FanCmd.Type): Unit = {}
          component.handle_fanCmd(operational_api, value)
        }
      }

      Art.releaseOutput(eventOutPortIds, dataOutPortIds)
    }
  }
}