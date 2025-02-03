// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace building_control_cpp_pkg_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Temperatureimpl_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) building_control_cpp_pkg_interfaces::msg::Temperatureimpl(_init);
}

void Temperatureimpl_fini_function(void * message_memory)
{
  auto typed_message = static_cast<building_control_cpp_pkg_interfaces::msg::Temperatureimpl *>(message_memory);
  typed_message->~Temperatureimpl();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Temperatureimpl_message_member_array[2] = {
  {
    "degrees",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<building_control_cpp_pkg_interfaces::msg::Float32>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(building_control_cpp_pkg_interfaces::msg::Temperatureimpl, degrees),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "unit",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<building_control_cpp_pkg_interfaces::msg::TempUnit>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(building_control_cpp_pkg_interfaces::msg::Temperatureimpl, unit),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Temperatureimpl_message_members = {
  "building_control_cpp_pkg_interfaces::msg",  // message namespace
  "Temperatureimpl",  // message name
  2,  // number of fields
  sizeof(building_control_cpp_pkg_interfaces::msg::Temperatureimpl),
  Temperatureimpl_message_member_array,  // message members
  Temperatureimpl_init_function,  // function to initialize message memory (memory has to be allocated)
  Temperatureimpl_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Temperatureimpl_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Temperatureimpl_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace building_control_cpp_pkg_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<building_control_cpp_pkg_interfaces::msg::Temperatureimpl>()
{
  return &::building_control_cpp_pkg_interfaces::msg::rosidl_typesupport_introspection_cpp::Temperatureimpl_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, building_control_cpp_pkg_interfaces, msg, Temperatureimpl)() {
  return &::building_control_cpp_pkg_interfaces::msg::rosidl_typesupport_introspection_cpp::Temperatureimpl_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
