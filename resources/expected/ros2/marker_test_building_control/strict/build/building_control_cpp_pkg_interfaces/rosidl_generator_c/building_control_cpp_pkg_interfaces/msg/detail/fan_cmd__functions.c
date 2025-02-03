// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from building_control_cpp_pkg_interfaces:msg/FanCmd.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/fan_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
building_control_cpp_pkg_interfaces__msg__FanCmd__init(building_control_cpp_pkg_interfaces__msg__FanCmd * msg)
{
  if (!msg) {
    return false;
  }
  // fan_cmd
  return true;
}

void
building_control_cpp_pkg_interfaces__msg__FanCmd__fini(building_control_cpp_pkg_interfaces__msg__FanCmd * msg)
{
  if (!msg) {
    return;
  }
  // fan_cmd
}

bool
building_control_cpp_pkg_interfaces__msg__FanCmd__are_equal(const building_control_cpp_pkg_interfaces__msg__FanCmd * lhs, const building_control_cpp_pkg_interfaces__msg__FanCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // fan_cmd
  if (lhs->fan_cmd != rhs->fan_cmd) {
    return false;
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__FanCmd__copy(
  const building_control_cpp_pkg_interfaces__msg__FanCmd * input,
  building_control_cpp_pkg_interfaces__msg__FanCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // fan_cmd
  output->fan_cmd = input->fan_cmd;
  return true;
}

building_control_cpp_pkg_interfaces__msg__FanCmd *
building_control_cpp_pkg_interfaces__msg__FanCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__FanCmd * msg = (building_control_cpp_pkg_interfaces__msg__FanCmd *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__FanCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(building_control_cpp_pkg_interfaces__msg__FanCmd));
  bool success = building_control_cpp_pkg_interfaces__msg__FanCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
building_control_cpp_pkg_interfaces__msg__FanCmd__destroy(building_control_cpp_pkg_interfaces__msg__FanCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    building_control_cpp_pkg_interfaces__msg__FanCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__init(building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__FanCmd * data = NULL;

  if (size) {
    data = (building_control_cpp_pkg_interfaces__msg__FanCmd *)allocator.zero_allocate(size, sizeof(building_control_cpp_pkg_interfaces__msg__FanCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = building_control_cpp_pkg_interfaces__msg__FanCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        building_control_cpp_pkg_interfaces__msg__FanCmd__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__fini(building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      building_control_cpp_pkg_interfaces__msg__FanCmd__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence *
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * array = (building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__destroy(building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__are_equal(const building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * lhs, const building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__FanCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence__copy(
  const building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * input,
  building_control_cpp_pkg_interfaces__msg__FanCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(building_control_cpp_pkg_interfaces__msg__FanCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    building_control_cpp_pkg_interfaces__msg__FanCmd * data =
      (building_control_cpp_pkg_interfaces__msg__FanCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!building_control_cpp_pkg_interfaces__msg__FanCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          building_control_cpp_pkg_interfaces__msg__FanCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__FanCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
