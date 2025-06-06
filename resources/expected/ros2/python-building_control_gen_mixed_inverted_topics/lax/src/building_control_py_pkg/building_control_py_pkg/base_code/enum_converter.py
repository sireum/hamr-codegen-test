#!/usr/bin/env python3
from building_control_py_pkg_interfaces.msg import TempUnit
from building_control_py_pkg_interfaces.msg import FanAck
from building_control_py_pkg_interfaces.msg import FanCmd

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

def enumToString(value):
    typedValue = TempUnit()
    typedValue.data = value
    match (typedValue.temp_unit):
        case TempUnit.TEMP_UNIT_FAHRENHEIT:
            return "TempUnit Fahrenheit"
        case TempUnit.TEMP_UNIT_CELSIUS:
            return "TempUnit Celsius"
        case TempUnit.TEMP_UNIT_KELVIN:
            return "TempUnit Kelvin"
        case default:
            return "Unknown value for TempUnit"

def enumToString(value):
    typedValue = FanAck()
    typedValue.data = value
    match (typedValue.fan_ack):
        case FanAck.FAN_ACK_OK:
            return "FanAck Ok"
        case FanAck.FAN_ACK_ERROR:
            return "FanAck Error"
        case default:
            return "Unknown value for FanAck"

def enumToString(value):
    typedValue = FanCmd()
    typedValue.data = value
    match (typedValue.fan_cmd):
        case FanCmd.FAN_CMD_ON:
            return "FanCmd On"
        case FanCmd.FAN_CMD_OFF:
            return "FanCmd Off"
        case default:
            return "Unknown value for FanCmd"

