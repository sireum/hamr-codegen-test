// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/Empty.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Empty in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__Empty
{
  uint8_t structure_needs_at_least_one_member;
} building_control_cpp_pkg_interfaces__msg__Empty;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__Empty.
typedef struct building_control_cpp_pkg_interfaces__msg__Empty__Sequence
{
  building_control_cpp_pkg_interfaces__msg__Empty * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__Empty__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__EMPTY__STRUCT_H_
