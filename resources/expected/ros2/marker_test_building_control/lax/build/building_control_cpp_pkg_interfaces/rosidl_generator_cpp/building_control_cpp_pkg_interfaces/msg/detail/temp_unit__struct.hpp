// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_HPP_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__TempUnit __attribute__((deprecated))
#else
# define DEPRECATED__building_control_cpp_pkg_interfaces__msg__TempUnit __declspec(deprecated)
#endif

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TempUnit_
{
  using Type = TempUnit_<ContainerAllocator>;

  explicit TempUnit_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp_unit = 0;
    }
  }

  explicit TempUnit_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->temp_unit = 0;
    }
  }

  // field types and members
  using _temp_unit_type =
    uint8_t;
  _temp_unit_type temp_unit;

  // setters for named parameter idiom
  Type & set__temp_unit(
    const uint8_t & _arg)
  {
    this->temp_unit = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t TEMP_UNIT_FAHRENHEIT =
    0u;
  static constexpr uint8_t TEMP_UNIT_CELSIUS =
    1u;
  static constexpr uint8_t TEMP_UNIT_KELVIN =
    2u;

  // pointer types
  using RawPtr =
    building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> *;
  using ConstRawPtr =
    const building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__TempUnit
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__building_control_cpp_pkg_interfaces__msg__TempUnit
    std::shared_ptr<building_control_cpp_pkg_interfaces::msg::TempUnit_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TempUnit_ & other) const
  {
    if (this->temp_unit != other.temp_unit) {
      return false;
    }
    return true;
  }
  bool operator!=(const TempUnit_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TempUnit_

// alias to use template instance with default allocator
using TempUnit =
  building_control_cpp_pkg_interfaces::msg::TempUnit_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TempUnit_<ContainerAllocator>::TEMP_UNIT_FAHRENHEIT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TempUnit_<ContainerAllocator>::TEMP_UNIT_CELSIUS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t TempUnit_<ContainerAllocator>::TEMP_UNIT_KELVIN;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_HPP_
