// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/FanCmd.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FAN_CMD_ON'.
enum
{
  building_control_cpp_pkg_interfaces__msg__FanCmd__FAN_CMD_ON = 0
};

/// Constant 'FAN_CMD_OFF'.
enum
{
  building_control_cpp_pkg_interfaces__msg__FanCmd__FAN_CMD_OFF = 1
};

/// Struct defined in msg/FanCmd in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__FanCmd
{
  uint8_t fan_cmd;
} building_control_cpp_pkg_interfaces__msg__FanCmd;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__FanCmd.
typedef struct building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence
{
  building_control_cpp_pkg_interfaces__msg__FanCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_CMD__STRUCT_H_
