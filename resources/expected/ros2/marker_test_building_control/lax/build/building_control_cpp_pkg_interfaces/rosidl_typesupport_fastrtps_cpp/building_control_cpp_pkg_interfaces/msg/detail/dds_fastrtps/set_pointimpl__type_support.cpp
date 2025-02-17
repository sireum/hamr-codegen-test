// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/set_pointimpl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/detail/set_pointimpl__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace building_control_cpp_pkg_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const building_control_cpp_pkg_interfaces::msg::Temperatureimpl &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  building_control_cpp_pkg_interfaces::msg::Temperatureimpl &);
size_t get_serialized_size(
  const building_control_cpp_pkg_interfaces::msg::Temperatureimpl &,
  size_t current_alignment);
size_t
max_serialized_size_Temperatureimpl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace building_control_cpp_pkg_interfaces

// functions for building_control_cpp_pkg_interfaces::msg::Temperatureimpl already declared above


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
cdr_serialize(
  const building_control_cpp_pkg_interfaces::msg::SetPointimpl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: low
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.low,
    cdr);
  // Member: high
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.high,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  building_control_cpp_pkg_interfaces::msg::SetPointimpl & ros_message)
{
  // Member: low
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.low);

  // Member: high
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.high);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
get_serialized_size(
  const building_control_cpp_pkg_interfaces::msg::SetPointimpl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: low

  current_alignment +=
    building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.low, current_alignment);
  // Member: high

  current_alignment +=
    building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.high, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
max_serialized_size_SetPointimpl(
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


  // Member: low
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Temperatureimpl(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: high
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Temperatureimpl(
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
    using DataType = building_control_cpp_pkg_interfaces::msg::SetPointimpl;
    is_plain =
      (
      offsetof(DataType, high) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SetPointimpl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const building_control_cpp_pkg_interfaces::msg::SetPointimpl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SetPointimpl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<building_control_cpp_pkg_interfaces::msg::SetPointimpl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SetPointimpl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const building_control_cpp_pkg_interfaces::msg::SetPointimpl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SetPointimpl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SetPointimpl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SetPointimpl__callbacks = {
  "building_control_cpp_pkg_interfaces::msg",
  "SetPointimpl",
  _SetPointimpl__cdr_serialize,
  _SetPointimpl__cdr_deserialize,
  _SetPointimpl__get_serialized_size,
  _SetPointimpl__max_serialized_size
};

static rosidl_message_type_support_t _SetPointimpl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SetPointimpl__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_building_control_cpp_pkg_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<building_control_cpp_pkg_interfaces::msg::SetPointimpl>()
{
  return &building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::_SetPointimpl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, building_control_cpp_pkg_interfaces, msg, SetPointimpl)() {
  return &building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::_SetPointimpl__handle;
}

#ifdef __cplusplus
}
#endif
