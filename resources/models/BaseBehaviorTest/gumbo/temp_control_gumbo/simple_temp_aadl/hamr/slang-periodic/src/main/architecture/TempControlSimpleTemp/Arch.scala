// #Sireum

package TempControlSimpleTemp

import org.sireum._
import art._
import art.PortMode._
import art.DispatchPropertyProtocol._

// This file was auto-generated.  Do not edit

object Arch {
  val TempControlSoftwareSystem_p_Instance_tcproc_tempSensor : TempControlSimpleTemp.TempSensor.TempSensorPeriodic_i_tcproc_tempSensor_Bridge = {
    val currentTemp = Port[TempSensor.Temperature_i] (id = 0, name = "TempControlSoftwareSystem_p_Instance_tcproc_tempSensor_currentTemp", mode = DataOut)

    TempControlSimpleTemp.TempSensor.TempSensorPeriodic_i_tcproc_tempSensor_Bridge(
      id = 0,
      name = "TempControlSoftwareSystem_p_Instance_tcproc_tempSensor",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      currentTemp = currentTemp
    )
  }
  val TempControlSoftwareSystem_p_Instance_tcproc_fan : TempControlSimpleTemp.CoolingFan.FanPeriodic_i_tcproc_fan_Bridge = {
    val fanCmd = Port[CoolingFan.FanCmd.Type] (id = 1, name = "TempControlSoftwareSystem_p_Instance_tcproc_fan_fanCmd", mode = DataIn)
    val fanAck = Port[CoolingFan.FanAck.Type] (id = 2, name = "TempControlSoftwareSystem_p_Instance_tcproc_fan_fanAck", mode = DataOut)

    TempControlSimpleTemp.CoolingFan.FanPeriodic_i_tcproc_fan_Bridge(
      id = 1,
      name = "TempControlSoftwareSystem_p_Instance_tcproc_fan",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      fanCmd = fanCmd,
      fanAck = fanAck
    )
  }
  val TempControlSoftwareSystem_p_Instance_tcproc_tempControl : TempControlSimpleTemp.TempControlSoftwareSystem.TempControlPeriodic_i_tcproc_tempControl_Bridge = {
    val currentTemp = Port[TempSensor.Temperature_i] (id = 3, name = "TempControlSoftwareSystem_p_Instance_tcproc_tempControl_currentTemp", mode = DataIn)
    val fanAck = Port[CoolingFan.FanAck.Type] (id = 4, name = "TempControlSoftwareSystem_p_Instance_tcproc_tempControl_fanAck", mode = DataIn)
    val setPoint = Port[TempControlSoftwareSystem.SetPoint_i] (id = 5, name = "TempControlSoftwareSystem_p_Instance_tcproc_tempControl_setPoint", mode = DataIn)
    val fanCmd = Port[CoolingFan.FanCmd.Type] (id = 6, name = "TempControlSoftwareSystem_p_Instance_tcproc_tempControl_fanCmd", mode = DataOut)

    TempControlSimpleTemp.TempControlSoftwareSystem.TempControlPeriodic_i_tcproc_tempControl_Bridge(
      id = 2,
      name = "TempControlSoftwareSystem_p_Instance_tcproc_tempControl",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      currentTemp = currentTemp,
      fanAck = fanAck,
      setPoint = setPoint,
      fanCmd = fanCmd
    )
  }
  val TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface : TempControlSimpleTemp.TempControlSoftwareSystem.OperatorInterfacePeriodic_i_tcproc_operatorInterface_Bridge = {
    val currentTemp = Port[TempSensor.Temperature_i] (id = 7, name = "TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface_currentTemp", mode = DataIn)
    val setPoint = Port[TempControlSoftwareSystem.SetPoint_i] (id = 8, name = "TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface_setPoint", mode = DataOut)

    TempControlSimpleTemp.TempControlSoftwareSystem.OperatorInterfacePeriodic_i_tcproc_operatorInterface_Bridge(
      id = 3,
      name = "TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface",
      dispatchProtocol = Periodic(period = 1000),
      dispatchTriggers = None(),

      currentTemp = currentTemp,
      setPoint = setPoint
    )
  }

  val ad : ArchitectureDescription = {

    ArchitectureDescription(
      components = ISZ (TempControlSoftwareSystem_p_Instance_tcproc_tempSensor, TempControlSoftwareSystem_p_Instance_tcproc_fan, TempControlSoftwareSystem_p_Instance_tcproc_tempControl, TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface),

      connections = ISZ (Connection(from = TempControlSoftwareSystem_p_Instance_tcproc_tempSensor.currentTemp, to = TempControlSoftwareSystem_p_Instance_tcproc_tempControl.currentTemp),
                         Connection(from = TempControlSoftwareSystem_p_Instance_tcproc_tempSensor.currentTemp, to = TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface.currentTemp),
                         Connection(from = TempControlSoftwareSystem_p_Instance_tcproc_fan.fanAck, to = TempControlSoftwareSystem_p_Instance_tcproc_tempControl.fanAck),
                         Connection(from = TempControlSoftwareSystem_p_Instance_tcproc_tempControl.fanCmd, to = TempControlSoftwareSystem_p_Instance_tcproc_fan.fanCmd),
                         Connection(from = TempControlSoftwareSystem_p_Instance_tcproc_operatorInterface.setPoint, to = TempControlSoftwareSystem_p_Instance_tcproc_tempControl.setPoint))
    )
  }
}
