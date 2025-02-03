// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/FanAck.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanAck __attribute__((deprecated))
#else
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanAck __declspec(deprecated)
#endif

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FanAck_
{
  using Type = FanAck_<ContainerAllocator>;

  explicit FanAck_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fan_ack = 0;
    }
  }

  explicit FanAck_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->fan_ack = 0;
    }
  }

  // field types and members
  using _fan_ack_type =
    uint8_t;
  _fan_ack_type fan_ack;

  // setters for named parameter idiom
  Type & set__fan_ack(
    const uint8_t & _arg)
  {
    this->fan_ack = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t FAN_ACK_OK =
    0u;
  static constexpr uint8_t FAN_ACK_ERROR =
    1u;

  // pointer types
  using RawPtr =
    building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> *;
  using ConstRawPtr =
    const building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanAck
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__FanAck
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::FanAck_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FanAck_ & other) const
  {
    if (this->fan_ack != other.fan_ack) {
      return false;
    }
    return true;
  }
  bool operator!=(const FanAck_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FanAck_

// alias to use template instance with default allocator
using FanAck =
  building_control_cpp_pkg_interfaces::msg::FanAck_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FanAck_<ContainerAllocator>::FAN_ACK_OK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t FanAck_<ContainerAllocator>::FAN_ACK_ERROR;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_HPP_
