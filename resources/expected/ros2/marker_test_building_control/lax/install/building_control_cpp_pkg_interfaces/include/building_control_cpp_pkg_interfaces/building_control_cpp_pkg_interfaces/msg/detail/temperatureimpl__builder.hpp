// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace builder
{

class Init_Temperatureimpl_unit
{
public:
  explicit Init_Temperatureimpl_unit(::building_control_cpp_pkg_interfaces::msg::Temperatureimpl & msg)
  : msg_(msg)
  {}
  ::building_control_cpp_pkg_interfaces::msg::Temperatureimpl unit(::building_control_cpp_pkg_interfaces::msg::Temperatureimpl::_unit_type arg)
  {
    msg_.unit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg_;
};

class Init_Temperatureimpl_degrees
{
public:
  Init_Temperatureimpl_degrees()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Temperatureimpl_unit degrees(::building_control_cpp_pkg_interfaces::msg::Temperatureimpl::_degrees_type arg)
  {
    msg_.degrees = std::move(arg);
    return Init_Temperatureimpl_unit(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::Temperatureimpl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::Temperatureimpl>()
{
  return building_control_cpp_pkg_interfaces::msg::builder::Init_Temperatureimpl_degrees();
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__BUILDER_HPP_
