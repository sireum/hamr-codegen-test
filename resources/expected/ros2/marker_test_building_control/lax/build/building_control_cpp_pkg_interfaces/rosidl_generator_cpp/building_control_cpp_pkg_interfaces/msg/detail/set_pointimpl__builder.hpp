// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/set_pointimpl__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace builder
{

class Init_SetPointimpl_high
{
public:
  explicit Init_SetPointimpl_high(::building_control_cpp_pkg_interfaces::msg::SetPointimpl & msg)
  : msg_(msg)
  {}
  ::building_control_cpp_pkg_interfaces::msg::SetPointimpl high(::building_control_cpp_pkg_interfaces::msg::SetPointimpl::_high_type arg)
  {
    msg_.high = std::move(arg);
    return std::move(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::SetPointimpl msg_;
};

class Init_SetPointimpl_low
{
public:
  Init_SetPointimpl_low()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetPointimpl_high low(::building_control_cpp_pkg_interfaces::msg::SetPointimpl::_low_type arg)
  {
    msg_.low = std::move(arg);
    return Init_SetPointimpl_high(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::SetPointimpl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::SetPointimpl>()
{
  return building_control_cpp_pkg_interfaces::msg::builder::Init_SetPointimpl_low();
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__BUILDER_HPP_
