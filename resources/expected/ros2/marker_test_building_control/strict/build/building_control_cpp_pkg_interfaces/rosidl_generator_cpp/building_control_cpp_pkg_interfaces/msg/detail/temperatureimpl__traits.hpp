// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__TRAITS_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'degrees'
#include "building_control_cpp_pkg_interfaces/msg/detail/float32__traits.hpp"
// Member 'unit'
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__traits.hpp"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Temperatureimpl & msg,
  std::ostream & out)
{
  out << "{";
  // member: degrees
  {
    out << "degrees: ";
    to_flow_style_yaml(msg.degrees, out);
    out << ", ";
  }

  // member: unit
  {
    out << "unit: ";
    to_flow_style_yaml(msg.unit, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Temperatureimpl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: degrees
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "degrees:\n";
    to_block_style_yaml(msg.degrees, out, indentation + 2);
  }

  // member: unit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "unit:\n";
    to_block_style_yaml(msg.unit, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Temperatureimpl & msg, bool use_flow_style = false)
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
  const building_control_cpp_pkg_interfaces::msg::Temperatureimpl & msg,
  std::ostream & out, size_t indentation = 0)
{
  building_control_cpp_pkg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const building_control_cpp_pkg_interfaces::msg::Temperatureimpl & msg)
{
  return building_control_cpp_pkg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>()
{
  return "building_control_cpp_pkg_interfaces::msg::Temperatureimpl";
}

template<>
inline const char * name<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>()
{
  return "building_control_cpp_pkg_interfaces/msg/Temperatureimpl";
}

template<>
struct has_fixed_size<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>
  : std::integral_constant<bool, has_fixed_size<building_control_cpp_pkg_interfaces::msg::Float32>::value && has_fixed_size<building_control_cpp_pkg_interfaces::msg::TempUnit>::value> {};

template<>
struct has_bounded_size<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>
  : std::integral_constant<bool, has_bounded_size<building_control_cpp_pkg_interfaces::msg::Float32>::value && has_bounded_size<building_control_cpp_pkg_interfaces::msg::TempUnit>::value> {};

template<>
struct is_message<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__TRAITS_HPP_
