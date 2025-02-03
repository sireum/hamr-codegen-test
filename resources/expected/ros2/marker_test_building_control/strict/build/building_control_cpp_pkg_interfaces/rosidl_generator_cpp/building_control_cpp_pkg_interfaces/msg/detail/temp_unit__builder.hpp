// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace builder
{

class Init_TempUnit_temp_unit
{
public:
  Init_TempUnit_temp_unit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::building_control_cpp_pkg_interfaces::msg::TempUnit temp_unit(::building_control_cpp_pkg_interfaces::msg::TempUnit::_temp_unit_type arg)
  {
    msg_.temp_unit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::TempUnit msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::TempUnit>()
{
  return building_control_cpp_pkg_interfaces::msg::builder::Init_TempUnit_temp_unit();
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__BUILDER_HPP_
