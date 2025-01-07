#include "building_control_cpp_pkg/base_headers/enum_converter.hpp"

const char* enumToString(building_control_cpp_pkg_interfaces::msg::TempUnit* value) {
    switch (value->temp_unit) {
        case building_control_cpp_pkg_interfaces::msg::TempUnit::TEMP_UNIT_FAHRENHEIT:
            return "TempUnit Fahrenheit";
        case building_control_cpp_pkg_interfaces::msg::TempUnit::TEMP_UNIT_CELSIUS:
            return "TempUnit Celsius";
        case building_control_cpp_pkg_interfaces::msg::TempUnit::TEMP_UNIT_KELVIN:
            return "TempUnit Kelvin";
        default:
            return "Unknown value for TempUnit";
    }
}

const char* enumToString(building_control_cpp_pkg_interfaces::msg::FanAck* value) {
    switch (value->fan_ack) {
        case building_control_cpp_pkg_interfaces::msg::FanAck::FAN_ACK_OK:
            return "FanAck Ok";
        case building_control_cpp_pkg_interfaces::msg::FanAck::FAN_ACK_ERROR:
            return "FanAck Error";
        default:
            return "Unknown value for FanAck";
    }
}

const char* enumToString(building_control_cpp_pkg_interfaces::msg::FanCmd* value) {
    switch (value->fan_cmd) {
        case building_control_cpp_pkg_interfaces::msg::FanCmd::FAN_CMD_ON:
            return "FanCmd On";
        case building_control_cpp_pkg_interfaces::msg::FanCmd::FAN_CMD_OFF:
            return "FanCmd Off";
        default:
            return "Unknown value for FanCmd";
    }
}

