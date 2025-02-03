// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from building_control_cpp_pkg_interfaces:msg/FanAck.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'FAN_ACK_OK'.
enum
{
  building_control_cpp_pkg_interfaces__msg__FanAck__FAN_ACK_OK = 0
};

/// Constant 'FAN_ACK_ERROR'.
enum
{
  building_control_cpp_pkg_interfaces__msg__FanAck__FAN_ACK_ERROR = 1
};

/// Struct defined in msg/FanAck in the package building_control_cpp_pkg_interfaces.
typedef struct building_control_cpp_pkg_interfaces__msg__FanAck
{
  uint8_t fan_ack;
} building_control_cpp_pkg_interfaces__msg__FanAck;

// Struct for a sequence of building_control_cpp_pkg_interfaces__msg__FanAck.
typedef struct building_control_cpp_pkg_interfaces__msg__FanAck__Sequence
{
  building_control_cpp_pkg_interfaces__msg__FanAck * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} building_control_cpp_pkg_interfaces__msg__FanAck__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__STRUCT_H_
