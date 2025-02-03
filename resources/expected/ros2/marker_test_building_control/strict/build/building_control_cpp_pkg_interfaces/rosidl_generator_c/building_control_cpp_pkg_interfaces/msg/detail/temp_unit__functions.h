// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#ifndef BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__FUNCTIONS_H_
#define BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "building_control_cpp_pkg_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__struct.h"

/// Initialize msg/TempUnit message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * building_control_cpp_pkg_interfaces__msg__TempUnit
 * )) before or use
 * building_control_cpp_pkg_interfaces__msg__TempUnit__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__TempUnit__init(building_control_cpp_pkg_interfaces__msg__TempUnit * msg);

/// Finalize msg/TempUnit message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__TempUnit__fini(building_control_cpp_pkg_interfaces__msg__TempUnit * msg);

/// Create msg/TempUnit message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
building_control_cpp_pkg_interfaces__msg__TempUnit *
building_control_cpp_pkg_interfaces__msg__TempUnit__create();

/// Destroy msg/TempUnit message.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__TempUnit__destroy(building_control_cpp_pkg_interfaces__msg__TempUnit * msg);

/// Check for msg/TempUnit message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__TempUnit__are_equal(const building_control_cpp_pkg_interfaces__msg__TempUnit * lhs, const building_control_cpp_pkg_interfaces__msg__TempUnit * rhs);

/// Copy a msg/TempUnit message.
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
building_control_cpp_pkg_interfaces__msg__TempUnit__copy(
  const building_control_cpp_pkg_interfaces__msg__TempUnit * input,
  building_control_cpp_pkg_interfaces__msg__TempUnit * output);

/// Initialize array of msg/TempUnit messages.
/**
 * It allocates the memory for the number of elements and calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__init(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array, size_t size);

/// Finalize array of msg/TempUnit messages.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__fini(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array);

/// Create array of msg/TempUnit messages.
/**
 * It allocates the memory for the array and calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence *
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__create(size_t size);

/// Destroy array of msg/TempUnit messages.
/**
 * It calls
 * building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
void
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__destroy(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array);

/// Check for msg/TempUnit message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_building_control_cpp_pkg_interfaces
bool
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__are_equal(const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * lhs, const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * rhs);

/// Copy an array of msg/TempUnit messages.
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
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__copy(
  const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * input,
  building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BUILDING_CONTROL_CPP_PKG_INTERFACES__MSG__DETAIL__TEMP_UNIT__FUNCTIONS_H_
