#ifndef ENUM_CONVERTER_HPP
#define ENUM_CONVERTER_HPP

#include <string>
#include "building_control_cpp_pkg_interfaces/msg/temp_unit.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_ack.hpp"
#include "building_control_cpp_pkg_interfaces/msg/fan_cmd.hpp"

std::string enumToString(building_control_cpp_pkg_interfaces::msg::TempUnit value);
std::string enumToString(building_control_cpp_pkg_interfaces::msg::FanAck value);
std::string enumToString(building_control_cpp_pkg_interfaces::msg::FanCmd value);

#endif
