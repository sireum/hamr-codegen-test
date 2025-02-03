// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__struct.h"
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__functions.h"

bool building_control_cpp_pkg_interfaces__msg__float32__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * building_control_cpp_pkg_interfaces__msg__float32__convert_to_py(void * raw_ros_message);
bool building_control_cpp_pkg_interfaces__msg__temp_unit__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * building_control_cpp_pkg_interfaces__msg__temp_unit__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool building_control_cpp_pkg_interfaces__msg__temperatureimpl__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[73];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("building_control_cpp_pkg_interfaces.msg._temperatureimpl.Temperatureimpl", full_classname_dest, 72) == 0);
  }
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl * ros_message = _ros_message;
  {  // degrees
    PyObject * field = PyObject_GetAttrString(_pymsg, "degrees");
    if (!field) {
      return false;
    }
    if (!building_control_cpp_pkg_interfaces__msg__float32__convert_from_py(field, &ros_message->degrees)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // unit
    PyObject * field = PyObject_GetAttrString(_pymsg, "unit");
    if (!field) {
      return false;
    }
    if (!building_control_cpp_pkg_interfaces__msg__temp_unit__convert_from_py(field, &ros_message->unit)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * building_control_cpp_pkg_interfaces__msg__temperatureimpl__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Temperatureimpl */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("building_control_cpp_pkg_interfaces.msg._temperatureimpl");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Temperatureimpl");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl * ros_message = (building_control_cpp_pkg_interfaces__msg__Temperatureimpl *)raw_ros_message;
  {  // degrees
    PyObject * field = NULL;
    field = building_control_cpp_pkg_interfaces__msg__float32__convert_to_py(&ros_message->degrees);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "degrees", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // unit
    PyObject * field = NULL;
    field = building_control_cpp_pkg_interfaces__msg__temp_unit__convert_to_py(&ros_message->unit);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "unit", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
