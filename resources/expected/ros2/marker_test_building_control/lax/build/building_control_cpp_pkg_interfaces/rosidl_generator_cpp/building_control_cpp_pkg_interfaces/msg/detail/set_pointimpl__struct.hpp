// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'low'
// Member 'high'
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__SetPointimpl __attribute__((deprecated))
#else
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__SetPointimpl __declspec(deprecated)
#endif

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SetPointimpl_
{
  using Type = SetPointimpl_<ContainerAllocator>;

  explicit SetPointimpl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : low(_init),
    high(_init)
  {
    (void)_init;
  }

  explicit SetPointimpl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : low(_alloc, _init),
    high(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _low_type =
    building_control_cpp_pkg_interfaces::msg::Temperatureimpl_<ContainerAllocator>;
  _low_type low;
  using _high_type =
    building_control_cpp_pkg_interfaces::msg::Temperatureimpl_<ContainerAllocator>;
  _high_type high;

  // setters for named parameter idiom
  Type & set__low(
    const building_control_cpp_pkg_interfaces::msg::Temperatureimpl_<ContainerAllocator> & _arg)
  {
    this->low = _arg;
    return *this;
  }
  Type & set__high(
    const building_control_cpp_pkg_interfaces::msg::Temperatureimpl_<ContainerAllocator> & _arg)
  {
    this->high = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> *;
  using ConstRawPtr =
    const building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__SetPointimpl
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__SetPointimpl
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::SetPointimpl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetPointimpl_ & other) const
  {
    if (this->low != other.low) {
      return false;
    }
    if (this->high != other.high) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetPointimpl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetPointimpl_

// alias to use template instance with default allocator
using SetPointimpl =
  building_control_cpp_pkg_interfaces::msg::SetPointimpl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_HPP_
