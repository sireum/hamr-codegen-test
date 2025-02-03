// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.hpp"

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
  const building_control_cpp_pkg_interfaces::msg::Float32 &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  building_control_cpp_pkg_interfaces::msg::Float32 &);
size_t get_serialized_size(
  const building_control_cpp_pkg_interfaces::msg::Float32 &,
  size_t current_alignment);
size_t
max_serialized_size_Float32(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace building_control_cpp_pkg_interfaces

namespace building_control_cpp_pkg_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const building_control_cpp_pkg_interfaces::msg::TempUnit &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  building_control_cpp_pkg_interfaces::msg::TempUnit &);
size_t get_serialized_size(
  const building_control_cpp_pkg_interfaces::msg::TempUnit &,
  size_t current_alignment);
size_t
max_serialized_size_TempUnit(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace building_control_cpp_pkg_interfaces


namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
cdr_serialize(
  const building_control_cpp_pkg_interfaces::msg::Temperatureimpl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: degrees
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.degrees,
    cdr);
  // Member: unit
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.unit,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  building_control_cpp_pkg_interfaces::msg::Temperatureimpl & ros_message)
{
  // Member: degrees
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.degrees);

  // Member: unit
  building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.unit);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
get_serialized_size(
  const building_control_cpp_pkg_interfaces::msg::Temperatureimpl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: degrees

  current_alignment +=
    building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.degrees, current_alignment);
  // Member: unit

  current_alignment +=
    building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.unit, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_building_control_cpp_pkg_interfaces
max_serialized_size_Temperatureimpl(
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


  // Member: degrees
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Float32(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: unit
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_TempUnit(
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
    using DataType = building_control_cpp_pkg_interfaces::msg::Temperatureimpl;
    is_plain =
      (
      offsetof(DataType, unit) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Temperatureimpl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const building_control_cpp_pkg_interfaces::msg::Temperatureimpl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Temperatureimpl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<building_control_cpp_pkg_interfaces::msg::Temperatureimpl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Temperatureimpl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const building_control_cpp_pkg_interfaces::msg::Temperatureimpl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Temperatureimpl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Temperatureimpl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Temperatureimpl__callbacks = {
  "building_control_cpp_pkg_interfaces::msg",
  "Temperatureimpl",
  _Temperatureimpl__cdr_serialize,
  _Temperatureimpl__cdr_deserialize,
  _Temperatureimpl__get_serialized_size,
  _Temperatureimpl__max_serialized_size
};

static rosidl_message_type_support_t _Temperatureimpl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Temperatureimpl__callbacks,
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
get_message_type_support_handle<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>()
{
  return &building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::_Temperatureimpl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, building_control_cpp_pkg_interfaces, msg, Temperatureimpl)() {
  return &building_control_cpp_pkg_interfaces::msg::typesupport_fastrtps_cpp::_Temperatureimpl__handle;
}

#ifdef __cplusplus
}
#endif
