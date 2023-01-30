// #Sireum

package a

import org.sireum._
import art._
import art.PortMode._
import art.DispatchPropertyProtocol._
import art.Art.BridgeId._
import art.Art.PortId._

// This file was auto-generated.  Do not edit

object Arch {
  val PC_Sys_Impl_Instance_proc_producer : a.Arrays.Producer_proc_producer_Bridge = {
    val coordinates = Port[Arrays.Array_of_Coordinates] (id = portId"0", name = "PC_Sys_Impl_Instance_proc_producer_coordinates", mode = EventOut)
    val vector_of_coordinates = Port[Arrays.Vector_of_Coordinates] (id = portId"1", name = "PC_Sys_Impl_Instance_proc_producer_vector_of_coordinates", mode = EventOut)
    val integers = Port[Arrays.Array_of_Integers] (id = portId"2", name = "PC_Sys_Impl_Instance_proc_producer_integers", mode = EventOut)

    a.Arrays.Producer_proc_producer_Bridge(
      id = bridgeId"0",
      name = "PC_Sys_Impl_Instance_proc_producer",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      coordinates = coordinates,
      vector_of_coordinates = vector_of_coordinates,
      integers = integers
    )
  }
  val PC_Sys_Impl_Instance_proc_consumer : a.Arrays.Consumer_proc_consumer_Bridge = {
    val coordinates = Port[Arrays.Array_of_Coordinates] (id = portId"3", name = "PC_Sys_Impl_Instance_proc_consumer_coordinates", mode = EventIn)
    val vector_of_coordinates = Port[Arrays.Vector_of_Coordinates] (id = portId"4", name = "PC_Sys_Impl_Instance_proc_consumer_vector_of_coordinates", mode = EventIn)
    val integers = Port[Arrays.Array_of_Integers] (id = portId"5", name = "PC_Sys_Impl_Instance_proc_consumer_integers", mode = EventIn)

    a.Arrays.Consumer_proc_consumer_Bridge(
      id = bridgeId"1",
      name = "PC_Sys_Impl_Instance_proc_consumer",
      dispatchProtocol = Sporadic(min = 1),
      dispatchTriggers = None(),

      coordinates = coordinates,
      vector_of_coordinates = vector_of_coordinates,
      integers = integers
    )
  }

  val ad : ArchitectureDescription = {
    TranspilerUtil.touch()

    ArchitectureDescription(
      components = IS[Art.BridgeId, Bridge] (PC_Sys_Impl_Instance_proc_producer, PC_Sys_Impl_Instance_proc_consumer),

      connections = IS[Art.ConnectionId, UConnection] (Connection(from = PC_Sys_Impl_Instance_proc_producer.coordinates, to = PC_Sys_Impl_Instance_proc_consumer.coordinates),
                                                       Connection(from = PC_Sys_Impl_Instance_proc_producer.vector_of_coordinates, to = PC_Sys_Impl_Instance_proc_consumer.vector_of_coordinates),
                                                       Connection(from = PC_Sys_Impl_Instance_proc_producer.integers, to = PC_Sys_Impl_Instance_proc_consumer.integers))
    )
  }
}

object TranspilerUtil {
  def touch(): Unit = {
    if(F) {
      TranspilerToucher.touch()

      // add types used in Platform.receive and Platform.receiveAsync
      val mbox2Boolean_Payload: MBox2[Art.PortId, DataContent] = MBox2(portId"0", Base_Types.Boolean_Payload(T))
      val mbox2OptionDataContent: MBox2[Art.PortId, Option[DataContent]] = MBox2(portId"0", None())

      // touch process/thread timing properties
      println(Schedulers.PC_Sys_Impl_Instance_proc_producer_timingProperties)
      println(Schedulers.PC_Sys_Impl_Instance_proc_consumer_timingProperties)

      // touch each payload/type in case some are only used as a field in a record
      def printDataContent(a: art.DataContent): Unit = { println(s"${a}") }

      printDataContent(Base_Types.Integer_32_Payload(Base_Types.Integer_32_example()))
      printDataContent(Arrays.Coordinate_Impl_Payload(Arrays.Coordinate_Impl.example()))
      printDataContent(Arrays.Array_of_Coordinates_Payload(Arrays.Array_of_Coordinates.example()))
      printDataContent(Base_Types.Integer_Payload(Base_Types.Integer_example()))
      printDataContent(Arrays.Vector_of_Coordinates_Payload(Arrays.Vector_of_Coordinates.example()))
      printDataContent(Arrays.Array_of_Integers_Payload(Arrays.Array_of_Integers.example()))
      printDataContent(art.Empty())

      {
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.logInfo("")
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.logDebug("")
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.logError("")
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.logInfo("")
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.logDebug("")
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.logError("")
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.put_coordinates(Arrays.Array_of_Coordinates.example())
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.put_coordinates(Arrays.Array_of_Coordinates.example())
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.put_vector_of_coordinates(Arrays.Vector_of_Coordinates.example())
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.put_vector_of_coordinates(Arrays.Vector_of_Coordinates.example())
        a.Arrays.Producer_proc_producer_Bridge.c_initialization_api.get.put_integers(Arrays.Array_of_Integers.example())
        a.Arrays.Producer_proc_producer_Bridge.c_operational_api.get.put_integers(Arrays.Array_of_Integers.example())
      }
      {
        a.Arrays.Consumer_proc_consumer_Bridge.c_initialization_api.get.logInfo("")
        a.Arrays.Consumer_proc_consumer_Bridge.c_initialization_api.get.logDebug("")
        a.Arrays.Consumer_proc_consumer_Bridge.c_initialization_api.get.logError("")
        a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.logInfo("")
        a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.logDebug("")
        a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.logError("")
        val apiUsage_coordinates: Option[Arrays.Array_of_Coordinates] = a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.get_coordinates()
        val apiUsage_vector_of_coordinates: Option[Arrays.Vector_of_Coordinates] = a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.get_vector_of_coordinates()
        val apiUsage_integers: Option[Arrays.Array_of_Integers] = a.Arrays.Consumer_proc_consumer_Bridge.c_operational_api.get.get_integers()
      }
    }
  }
}

