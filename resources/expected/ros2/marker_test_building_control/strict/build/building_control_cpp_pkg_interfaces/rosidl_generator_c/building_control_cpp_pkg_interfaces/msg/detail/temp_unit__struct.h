// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TEMP_UNIT_FAHRENHEIT'.
enum
{
  building_control_cpp_pkg_interfaces__msg__TempUnit__TEMP_UNIT_FAHRENHEIT = 0
};

/// Constant 'TEMP_UNIT_CELSIUS'.
enum
{
  building_control_cpp_pkg_interfaces__msg__TempUnit__TEMP_UNIT_CELSIUS = 1
};

/// Constant 'TEMP_UNIT_KELVIN'.
enum
{
  building_control_cpp_pkg_interfaces__msg__TempUnit__TEMP_UNIT_KELVIN = 2
};

/// Struct defined in msg/TempUnit in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__TempUnit
{
  uint8_t temp_unit;
} building_control_cpp_pkg_interfaces__msg__TempUnit;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__TempUnit.
typedef struct building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence
{
  building_control_cpp_pkg_interfaces__msg__TempUnit * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__STRUCT_H_
