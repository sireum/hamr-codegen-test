#!/usr/bin/env python3
from datatypes_system_py_pkg_interfaces.msg import MyEnum

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

def enumToString(value):
    typedValue = Heat()
    typedValue.data = value
    match (typedValue.heat):
        case Heat.HEAT_DUMMY_HEAD_ENUM:
            return "Heat Dummy_Head_Enum"
        case default:
            return "Unknown value for Heat"

def enumToString(value):
    typedValue = InterfaceInteraction()
    typedValue.data = value
    match (typedValue.interface_interaction):
        case InterfaceInteraction.INTERFACE_INTERACTION_DUMMY_INTERFACE_INTERACTION_ENUM:
            return "InterfaceInteraction Dummy_Interface_Interaction_Enum"
        case default:
            return "Unknown value for InterfaceInteraction"

def enumToString(value):
    typedValue = ValueStatus()
    typedValue.data = value
    match (typedValue.value_status):
        case ValueStatus.VALUE_STATUS_VALID:
            return "ValueStatus Valid"
        case ValueStatus.VALUE_STATUS_INVALID:
            return "ValueStatus Invalid"
        case default:
            return "Unknown value for ValueStatus"

def enumToString(value):
    typedValue = OnOff()
    typedValue.data = value
    match (typedValue.on_off):
        case OnOff.ON_OFF_ONN:
            return "OnOff Onn"
        case OnOff.ON_OFF_OFF:
            return "OnOff Off"
        case default:
            return "Unknown value for OnOff"

def enumToString(value):
    typedValue = Status()
    typedValue.data = value
    match (typedValue.status):
        case Status.STATUS_INIT_STATUS:
            return "Status Init_Status"
        case Status.STATUS_ON_STATUS:
            return "Status On_Status"
        case Status.STATUS_FAILED_STATUS:
            return "Status Failed_Status"
        case default:
            return "Unknown value for Status"

def enumToString(value):
    typedValue = RegulatorMode()
    typedValue.data = value
    match (typedValue.regulator_mode):
        case RegulatorMode.REGULATOR_MODE_INIT_REGULATOR_MODE:
            return "RegulatorMode Init_Regulator_Mode"
        case RegulatorMode.REGULATOR_MODE_NORMAL_REGULATOR_MODE:
            return "RegulatorMode Normal_Regulator_Mode"
        case RegulatorMode.REGULATOR_MODE_FAILED_REGULATOR_MODE:
            return "RegulatorMode Failed_Regulator_Mode"
        case default:
            return "Unknown value for RegulatorMode"

def enumToString(value):
    typedValue = MonitorMode()
    typedValue.data = value
    match (typedValue.monitor_mode):
        case MonitorMode.MONITOR_MODE_INIT_MONITOR_MODE:
            return "MonitorMode Init_Monitor_Mode"
        case MonitorMode.MONITOR_MODE_NORMAL_MONITOR_MODE:
            return "MonitorMode Normal_Monitor_Mode"
        case MonitorMode.MONITOR_MODE_FAILED_MONITOR_MODE:
            return "MonitorMode Failed_Monitor_Mode"
        case default:
            return "Unknown value for MonitorMode"

