// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Float32.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/float32__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace builder
{

class Init_Float32_data
{
public:
  Init_Float32_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::building_control_cpp_pkg_interfaces::msg::Float32 data(::building_control_cpp_pkg_interfaces::msg::Float32::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::building_control_cpp_pkg_interfaces::msg::Float32 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::Float32>()
{
  return building_control_cpp_pkg_interfaces::msg::builder::Init_Float32_data();
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__BUILDER_HPP_
