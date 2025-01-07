#include "isolette_cpp_pkg/base_headers/enum_converter.hpp"

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Heat* value) {
    switch (value->heat) {
        case isolette_cpp_pkg_interfaces::msg::Heat::HEAT_DUMMY_HEAD_ENUM:
            return "Heat Dummy_Head_Enum";
        default:
            return "Unknown value for Heat";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Interface_Interaction* value) {
    switch (value->interface_interaction) {
        case isolette_cpp_pkg_interfaces::msg::Interface_Interaction::INTERFACE_INTERACTION_DUMMY_INTERFACE_INTERACTION_ENUM:
            return "Interface_Interaction Dummy_Interface_Interaction_Enum";
        default:
            return "Unknown value for Interface_Interaction";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::ValueStatus* value) {
    switch (value->value_status) {
        case isolette_cpp_pkg_interfaces::msg::ValueStatus::VALUE_STATUS_VALID:
            return "ValueStatus Valid";
        case isolette_cpp_pkg_interfaces::msg::ValueStatus::VALUE_STATUS_INVALID:
            return "ValueStatus Invalid";
        default:
            return "Unknown value for ValueStatus";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::On_Off* value) {
    switch (value->on_off) {
        case isolette_cpp_pkg_interfaces::msg::On_Off::ON_OFF_ONN:
            return "On_Off Onn";
        case isolette_cpp_pkg_interfaces::msg::On_Off::ON_OFF_OFF:
            return "On_Off Off";
        default:
            return "Unknown value for On_Off";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Status* value) {
    switch (value->status) {
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

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Regulator_Mode* value) {
    switch (value->regulator_mode) {
        case isolette_cpp_pkg_interfaces::msg::Regulator_Mode::REGULATOR_MODE_INIT_REGULATOR_MODE:
            return "Regulator_Mode Init_Regulator_Mode";
        case isolette_cpp_pkg_interfaces::msg::Regulator_Mode::REGULATOR_MODE_NORMAL_REGULATOR_MODE:
            return "Regulator_Mode Normal_Regulator_Mode";
        case isolette_cpp_pkg_interfaces::msg::Regulator_Mode::REGULATOR_MODE_FAILED_REGULATOR_MODE:
            return "Regulator_Mode Failed_Regulator_Mode";
        default:
            return "Unknown value for Regulator_Mode";
    }
}

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Monitor_Mode* value) {
    switch (value->monitor_mode) {
        case isolette_cpp_pkg_interfaces::msg::Monitor_Mode::MONITOR_MODE_INIT_MONITOR_MODE:
            return "Monitor_Mode Init_Monitor_Mode";
        case isolette_cpp_pkg_interfaces::msg::Monitor_Mode::MONITOR_MODE_NORMAL_MONITOR_MODE:
            return "Monitor_Mode Normal_Monitor_Mode";
        case isolette_cpp_pkg_interfaces::msg::Monitor_Mode::MONITOR_MODE_FAILED_MONITOR_MODE:
            return "Monitor_Mode Failed_Monitor_Mode";
        default:
            return "Unknown value for Monitor_Mode";
    }
}

