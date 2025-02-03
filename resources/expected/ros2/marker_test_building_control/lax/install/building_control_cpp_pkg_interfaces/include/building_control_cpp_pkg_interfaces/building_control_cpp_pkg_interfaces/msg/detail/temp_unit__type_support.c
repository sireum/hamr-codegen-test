// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__rosidl_typesupport_introspection_c.h"
#include "building_control_cpp_pkg_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__functions.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  building_control_cpp_pkg_interfaces__msg__TempUnit__init(message_memory);
}

void building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_fini_function(void * message_memory)
{
  building_control_cpp_pkg_interfaces__msg__TempUnit__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_member_array[1] = {
  {
    "temp_unit",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(building_control_cpp_pkg_interfaces__msg__TempUnit, temp_unit),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_members = {
  "building_control_cpp_pkg_interfaces__msg",  // message namespace
  "TempUnit",  // message name
  1,  // number of fields
  sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit),
  building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_member_array,  // message members
  building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_init_function,  // function to initialize message memory (memory has to be allocated)
  building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_type_support_handle = {
  0,
  &building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_building_control_cpp_pkg_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, building_control_cpp_pkg_interfaces, msg, TempUnit)() {
  if (!building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_type_support_handle.typesupport_identifier) {
    building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &building_control_cpp_pkg_interfaces__msg__TempUnit__rosidl_typesupport_introspection_c__TempUnit_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
