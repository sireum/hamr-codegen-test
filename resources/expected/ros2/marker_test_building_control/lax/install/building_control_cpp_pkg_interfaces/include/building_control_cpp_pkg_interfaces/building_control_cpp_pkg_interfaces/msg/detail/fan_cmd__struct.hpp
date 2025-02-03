// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/FanCmd.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanCmd __attribute__((deprecated))
#else
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanCmd __declspec(deprecated)
#endif

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FanCmd_
{
  using Type = FanCmd_<ContainerAllocator>;

  explicit FanCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fan_cmd = 0;
    }
  }

  explicit FanCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fan_cmd = 0;
    }
  }

  // field types and members
  using _fan_cmd_type =
    uint8_t;
  _fan_cmd_type fan_cmd;

  // setters for named parameter idiom
  Type & set__fan_cmd(
    const uint8_t & _arg)
  {
    this->fan_cmd = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t FAN_CMD_ON =
    0u;
  static constexpr uint8_t FAN_CMD_OFF =
    1u;

  // pointer types
  using RawPtr =
    building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanCmd
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanCmd
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FanCmd_ & other) const
  {
    if (this->fan_cmd != other.fan_cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const FanCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FanCmd_

// alias to use template instance with default allocator
using FanCmd =
  building_control_cpp_pkg_interfaces::msg::FanCmd_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FanCmd_<ContainerAllocator>::FAN_CMD_ON;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FanCmd_<ContainerAllocator>::FAN_CMD_OFF;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_HPP_
