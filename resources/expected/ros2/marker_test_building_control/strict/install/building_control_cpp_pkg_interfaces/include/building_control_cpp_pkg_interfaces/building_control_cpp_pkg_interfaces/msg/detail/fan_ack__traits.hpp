// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/FanAck.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__TRAITS_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "building_control_cpp_pkg_interfaces/msg/detail/fan_ack__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FanAck & msg,
  std::ostream & out)
{
  out << "{";
  // member: fan_ack
  {
    out << "fan_ack: ";
    rosidl_generator_traits::value_to_yaml(msg.fan_ack, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FanAck & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fan_ack
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fan_ack: ";
    rosidl_generator_traits::value_to_yaml(msg.fan_ack, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FanAck & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const building_control_cpp_pkg_interfaces::msg::FanAck & msg,
  std::ostream & out, size_t indentation = 0)
{
  building_control_cpp_pkg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const building_control_cpp_pkg_interfaces::msg::FanAck & msg)
{
  return building_control_cpp_pkg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<building_control_cpp_pkg_interfaces::msg::FanAck>()
{
  return "building_control_cpp_pkg_interfaces::msg::FanAck";
}

template<>
inline const char * name<building_control_cpp_pkg_interfaces::msg::FanAck>()
{
  return "building_control_cpp_pkg_interfaces/msg/FanAck";
}

template<>
struct has_fixed_size<building_control_cpp_pkg_interfaces::msg::FanAck>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<building_control_cpp_pkg_interfaces::msg::FanAck>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<building_control_cpp_pkg_interfaces::msg::FanAck>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__TRAITS_HPP_
