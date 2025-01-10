#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Heat value) {
    switch (value.heat) {
        case isolette_cpp_pkg_interfaces::msg::Heat::HEAT_DUMMY_HEAD_ENUM:
            return "Heat Dummy_Head_Enum";
        default:
            return "Unknown value for Heat";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::InterfaceInteraction value) {
    switch (value.interface_interaction) {
        case isolette_cpp_pkg_interfaces::msg::InterfaceInteraction::INTERFACE_INTERACTION_DUMMY_INTERFACE_INTERACTION_ENUM:
            return "InterfaceInteraction Dummy_Interface_Interaction_Enum";
        default:
            return "Unknown value for InterfaceInteraction";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::ValueStatus value) {
    switch (value.value_status) {
        case isolette_cpp_pkg_interfaces::msg::ValueStatus::VALUE_STATUS_VALID:
            return "ValueStatus Valid";
        case isolette_cpp_pkg_interfaces::msg::ValueStatus::VALUE_STATUS_INVALID:
            return "ValueStatus Invalid";
        default:
            return "Unknown value for ValueStatus";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::OnOff value) {
    switch (value.on_off) {
        case isolette_cpp_pkg_interfaces::msg::OnOff::ON_OFF_ONN:
            return "OnOff Onn";
        case isolette_cpp_pkg_interfaces::msg::OnOff::ON_OFF_OFF:
            return "OnOff Off";
        default:
            return "Unknown value for OnOff";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Status value) {
    switch (value.status) {
        case isolette_cpp_pkg_interfaces::msg::Status::STATUS_INIT_STATUS:
            return "Status Init_Status";
        case isolette_cpp_pkg_interfaces::msg::Status::STATUS_ON_STATUS:
            return "Status On_Status";
        case isolette_cpp_pkg_interfaces::msg::Status::STATUS_FAILED_STATUS:
            return "Status Failed_Status";
        default:
            return "Unknown value for Status";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::RegulatorMode value) {
    switch (value.regulator_mode) {
        case isolette_cpp_pkg_interfaces::msg::RegulatorMode::REGULATOR_MODE_INIT_REGULATOR_MODE:
            return "RegulatorMode Init_Regulator_Mode";
        case isolette_cpp_pkg_interfaces::msg::RegulatorMode::REGULATOR_MODE_NORMAL_REGULATOR_MODE:
            return "RegulatorMode Normal_Regulator_Mode";
        case isolette_cpp_pkg_interfaces::msg::RegulatorMode::REGULATOR_MODE_FAILED_REGULATOR_MODE:
            return "RegulatorMode Failed_Regulator_Mode";
        default:
            return "Unknown value for RegulatorMode";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::MonitorMode value) {
    switch (value.monitor_mode) {
        case isolette_cpp_pkg_interfaces::msg::MonitorMode::MONITOR_MODE_INIT_MONITOR_MODE:
            return "MonitorMode Init_Monitor_Mode";
        case isolette_cpp_pkg_interfaces::msg::MonitorMode::MONITOR_MODE_NORMAL_MONITOR_MODE:
            return "MonitorMode Normal_Monitor_Mode";
        case isolette_cpp_pkg_interfaces::msg::MonitorMode::MONITOR_MODE_FAILED_MONITOR_MODE:
            return "MonitorMode Failed_Monitor_Mode";
        default:
            return "Unknown value for MonitorMode";
    }
}

