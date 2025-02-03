// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'degrees'
#include "building_control_cpp_pkg_interfaces/msg/detail/float32__struct.h"
// Member 'unit'
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__struct.h"

/// Struct defined in msg/Temperatureimpl in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__Temperatureimpl
{
  building_control_cpp_pkg_interfaces__msg__Float32 degrees;
  building_control_cpp_pkg_interfaces__msg__TempUnit unit;
} building_control_cpp_pkg_interfaces__msg__Temperatureimpl;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__Temperatureimpl.
typedef struct building_control_cpp_pkg_interfaces__msg__Temperatureimpl__Sequence
{
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__Temperatureimpl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMPERATUREIMPL__STRUCT_H_
