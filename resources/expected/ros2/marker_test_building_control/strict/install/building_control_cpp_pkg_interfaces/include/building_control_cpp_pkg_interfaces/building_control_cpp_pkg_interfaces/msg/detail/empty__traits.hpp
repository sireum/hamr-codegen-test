// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Empty.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__TRAITS_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "building_control_cpp_pkg_interfaces/msg/detail/empty__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Empty & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Empty & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Empty & msg, bool use_flow_style = false)
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
  const building_control_cpp_pkg_interfaces::msg::Empty & msg,
  std::ostream & out, size_t indentation = 0)
{
  building_control_cpp_pkg_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use building_control_cpp_pkg_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const building_control_cpp_pkg_interfaces::msg::Empty & msg)
{
  return building_control_cpp_pkg_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<building_control_cpp_pkg_interfaces::msg::Empty>()
{
  return "building_control_cpp_pkg_interfaces::msg::Empty";
}

template<>
inline const char * name<building_control_cpp_pkg_interfaces::msg::Empty>()
{
  return "building_control_cpp_pkg_interfaces/msg/Empty";
}

template<>
struct has_fixed_size<building_control_cpp_pkg_interfaces::msg::Empty>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<building_control_cpp_pkg_interfaces::msg::Empty>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<building_control_cpp_pkg_interfaces::msg::Empty>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__TRAITS_HPP_
