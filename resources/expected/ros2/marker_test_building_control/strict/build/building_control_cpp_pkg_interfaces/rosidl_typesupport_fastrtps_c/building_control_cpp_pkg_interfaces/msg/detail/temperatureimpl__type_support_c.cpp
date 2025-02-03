// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "building_control_cpp_pkg_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "building_control_cpp_pkg_interfaces/msg/detail/float32__functions.h"  // degrees
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__functions.h"  // unit

// forward declare type support functions
size_t get_serialized_size_building_control_cpp_pkg_interfaces__msg__Float32(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_building_control_cpp_pkg_interfaces__msg__Float32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, Float32)();
size_t get_serialized_size_building_control_cpp_pkg_interfaces__msg__TempUnit(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_building_control_cpp_pkg_interfaces__msg__TempUnit(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, TempUnit)();


using _Temperatureimpl__ros_msg_type = building_control_cpp_pkg_interfaces__msg__Temperatureimpl;

static bool _Temperatureimpl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Temperatureimpl__ros_msg_type * ros_message = static_cast<const _Temperatureimpl__ros_msg_type *>(untyped_ros_message);
  // Field name: degrees
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, Float32
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->degrees, cdr))
    {
      return false;
    }
  }

  // Field name: unit
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, TempUnit
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->unit, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _Temperatureimpl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Temperatureimpl__ros_msg_type * ros_message = static_cast<_Temperatureimpl__ros_msg_type *>(untyped_ros_message);
  // Field name: degrees
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, Float32
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->degrees))
    {
      return false;
    }
  }

  // Field name: unit
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, TempUnit
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->unit))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_building_control_cpp_pkg_interfaces
size_t get_serialized_size_building_control_cpp_pkg_interfaces__msg__Temperatureimpl(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Temperatureimpl__ros_msg_type * ros_message = static_cast<const _Temperatureimpl__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name degrees

  current_alignment += get_serialized_size_building_control_cpp_pkg_interfaces__msg__Float32(
    &(ros_message->degrees), current_alignment);
  // field.name unit

  current_alignment += get_serialized_size_building_control_cpp_pkg_interfaces__msg__TempUnit(
    &(ros_message->unit), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _Temperatureimpl__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_building_control_cpp_pkg_interfaces__msg__Temperatureimpl(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_building_control_cpp_pkg_interfaces
size_t max_serialized_size_building_control_cpp_pkg_interfaces__msg__Temperatureimpl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: degrees
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_building_control_cpp_pkg_interfaces__msg__Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: unit
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_building_control_cpp_pkg_interfaces__msg__TempUnit(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = building_control_cpp_pkg_interfaces__msg__Temperatureimpl;
    is_plain =
      (
      offsetof(DataType, unit) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Temperatureimpl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_building_control_cpp_pkg_interfaces__msg__Temperatureimpl(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Temperatureimpl = {
  "building_control_cpp_pkg_interfaces::msg",
  "Temperatureimpl",
  _Temperatureimpl__cdr_serialize,
  _Temperatureimpl__cdr_deserialize,
  _Temperatureimpl__get_serialized_size,
  _Temperatureimpl__max_serialized_size
};

static rosidl_message_type_support_t _Temperatureimpl__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Temperatureimpl,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, building_control_cpp_pkg_interfaces, msg, Temperatureimpl)() {
  return &_Temperatureimpl__type_support;
}

#if defined(__cplusplus)
}
#endif
