// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Empty.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__BUILDER_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "building_control_cpp_pkg_interfaces/msg/detail/empty__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{


}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::building_control_cpp_pkg_interfaces::msg::Empty>()
{
  return ::building_control_cpp_pkg_interfaces::msg::Empty(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__BUILDER_HPP_
