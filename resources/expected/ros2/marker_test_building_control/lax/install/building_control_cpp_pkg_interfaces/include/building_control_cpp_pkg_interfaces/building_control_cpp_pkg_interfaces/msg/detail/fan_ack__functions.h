// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from building_control_cpp_pkg_interfaces:msg/FanAck.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__FUNCTIONS_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "building_control_cpp_pkg_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "building_control_cpp_pkg_interfaces/msg/detail/fan_ack__struct.h"

/// Initialize msg/FanAck message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * building_control_cpp_pkg_interfaces__msg__FanAck
 * )) before or use
 * building_control_cpp_pkg_interfaces__msg__FanAck__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__init(building_control_cpp_pkg_interfaces__msg__FanAck * msg);

/// Finalize msg/FanAck message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__FanAck__fini(building_control_cpp_pkg_interfaces__msg__FanAck * msg);

/// Create msg/FanAck message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
building_control_cpp_pkg_interfaces__msg__FanAck *
building_control_cpp_pkg_interfaces__msg__FanAck__create();

/// Destroy msg/FanAck message.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__FanAck__destroy(building_control_cpp_pkg_interfaces__msg__FanAck * msg);

/// Check for msg/FanAck message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__are_equal(const building_control_cpp_pkg_interfaces__msg__FanAck * lhs, const building_control_cpp_pkg_interfaces__msg__FanAck * rhs);

/// Copy a msg/FanAck message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__copy(
  const building_control_cpp_pkg_interfaces__msg__FanAck * input,
  building_control_cpp_pkg_interfaces__msg__FanAck * output);

/// Initialize array of msg/FanAck messages.
/**
 * It allocates the memory for the number of elements and calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__init(building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * array, size_t size);

/// Finalize array of msg/FanAck messages.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__fini(building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * array);

/// Create array of msg/FanAck messages.
/**
 * It allocates the memory for the array and calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence *
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__create(size_t size);

/// Destroy array of msg/FanAck messages.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__destroy(building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * array);

/// Check for msg/FanAck message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__are_equal(const building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * lhs, const building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * rhs);

/// Copy an array of msg/FanAck messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__FanAck__Sequence__copy(
  const building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * input,
  building_control_cpp_pkg_interfaces__msg__FanAck__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__FAN_ACK__FUNCTIONS_H_
