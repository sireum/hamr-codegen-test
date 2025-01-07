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
const char* enumToString(isolette_cpp_pkg_interfaces::msg::Interface_Interaction* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::ValueStatus* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::On_Off* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::Status* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::Regulator_Mode* value);
const char* enumToString(isolette_cpp_pkg_interfaces::msg::Monitor_Mode* value);

#endif
