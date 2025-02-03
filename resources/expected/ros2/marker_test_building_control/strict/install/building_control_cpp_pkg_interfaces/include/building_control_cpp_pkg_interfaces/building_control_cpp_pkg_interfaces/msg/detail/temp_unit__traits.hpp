// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__TRAITS_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TempUnit & msg,
  std::ostream & out)
{
  out << "{";
  // member: temp_unit
  {
    out << "temp_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_unit, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TempUnit & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: temp_unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp_unit: ";
    rosidl_generator_traits::value_to_yaml(msg.temp_unit, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TempUnit & msg, bool use_flow_style = false)
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
  const building_control_cpp_pkg_interfaces::msg::TempUnit & msg,
  std::ostream & out, size_t indentation = 0)
{
  building_control_cpp_pkg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const building_control_cpp_pkg_interfaces::msg::TempUnit & msg)
{
  return building_control_cpp_pkg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<building_control_cpp_pkg_interfaces::msg::TempUnit>()
{
  return "building_control_cpp_pkg_interfaces::msg::TempUnit";
}

template<>
inline const char * name<building_control_cpp_pkg_interfaces::msg::TempUnit>()
{
  return "building_control_cpp_pkg_interfaces/msg/TempUnit";
}

template<>
struct has_fixed_size<building_control_cpp_pkg_interfaces::msg::TempUnit>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<building_control_cpp_pkg_interfaces::msg::TempUnit>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<building_control_cpp_pkg_interfaces::msg::TempUnit>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__TRAITS_HPP_
