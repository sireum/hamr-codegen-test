#ifndef ENUM_CONVERTER_HPP
#define ENUM_CONVERTER_HPP

#include <string>
#include "isolette_cpp_pkg_interfaces/msg/heat.hpp"
#include "isolette_cpp_pkg_interfaces/msg/interface_interaction.hpp"
#include "isolette_cpp_pkg_interfaces/msg/value_status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/on_off.hpp"
#include "isolette_cpp_pkg_interfaces/msg/status.hpp"
#include "isolette_cpp_pkg_interfaces/msg/regulator_mode.hpp"
#include "isolette_cpp_pkg_interfaces/msg/monitor_mode.hpp"

const char* enumToString(isolette_cpp_pkg_interfaces::msg::Heat* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::InterfaceInteraction* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::ValueStatus* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::OnOff* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::Status* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::RegulatorMode* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::MonitorMode* value);

#endif
