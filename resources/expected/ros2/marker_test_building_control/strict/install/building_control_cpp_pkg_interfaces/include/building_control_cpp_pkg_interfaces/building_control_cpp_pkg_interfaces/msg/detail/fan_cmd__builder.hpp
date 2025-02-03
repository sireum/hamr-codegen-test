// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/FanCmd.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/fan_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace builder
{

class Init_FanCmd_fan_cmd
{
public:
  Init_FanCmd_fan_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::building_control_cpp_pkg_interfaces::msg::FanCmd fan_cmd(::building_control_cpp_pkg_interfaces::msg::FanCmd::_fan_cmd_type arg)
  {
    msg_.fan_cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::FanCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::FanCmd>()
{
  return building_control_cpp_pkg_interfaces::msg::builder::Init_FanCmd_fan_cmd();
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__BUILDER_HPP_
