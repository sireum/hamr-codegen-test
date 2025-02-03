// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__TRAITS_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "building_control_cpp_pkg_interfaces/msg/detail/set_pointimpl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'low'
// Member 'high'
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__traits.hpp"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SetPointimpl & msg,
  std::ostream & out)
{
  out << "{";
  // member: low
  {
    out << "low: ";
    to_flow_style_yaml(msg.low, out);
    out << ", ";
  }

  // member: high
  {
    out << "high: ";
    to_flow_style_yaml(msg.high, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPointimpl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: low
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "low:\n";
    to_block_style_yaml(msg.low, out, indentation + 2);
  }

  // member: high
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "high:\n";
    to_block_style_yaml(msg.high, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPointimpl & msg, bool use_flow_style = false)
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
  const building_control_cpp_pkg_interfaces::msg::SetPointimpl & msg,
  std::ostream & out, size_t indentation = 0)
{
  building_control_cpp_pkg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const building_control_cpp_pkg_interfaces::msg::SetPointimpl & msg)
{
  return building_control_cpp_pkg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<building_control_cpp_pkg_interfaces::msg::SetPointimpl>()
{
  return "building_control_cpp_pkg_interfaces::msg::SetPointimpl";
}

template<>
inline const char * name<building_control_cpp_pkg_interfaces::msg::SetPointimpl>()
{
  return "building_control_cpp_pkg_interfaces/msg/SetPointimpl";
}

template<>
struct has_fixed_size<building_control_cpp_pkg_interfaces::msg::SetPointimpl>
  : std::integral_constant<bool, has_fixed_size<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>::value> {};

template<>
struct has_bounded_size<building_control_cpp_pkg_interfaces::msg::SetPointimpl>
  : std::integral_constant<bool, has_bounded_size<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>::value> {};

template<>
struct is_message<building_control_cpp_pkg_interfaces::msg::SetPointimpl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__TRAITS_HPP_
