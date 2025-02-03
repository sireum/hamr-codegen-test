// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'low'
// Member 'high'
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.h"

/// Struct defined in msg/SetPointimpl in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__SetPointimpl
{
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl low;
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl high;
} building_control_cpp_pkg_interfaces__msg__SetPointimpl;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__SetPointimpl.
typedef struct building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence
{
  building_control_cpp_pkg_interfaces__msg__SetPointimpl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__SET_POINTIMPL__STRUCT_H_
