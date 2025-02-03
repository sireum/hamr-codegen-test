// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/Float32.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Float32 in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__Float32
{
  float data;
} building_control_cpp_pkg_interfaces__msg__Float32;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__Float32.
typedef struct building_control_cpp_pkg_interfaces__msg__Float32__Sequence
{
  building_control_cpp_pkg_interfaces__msg__Float32 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__Float32__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FLOAT32__STRUCT_H_
