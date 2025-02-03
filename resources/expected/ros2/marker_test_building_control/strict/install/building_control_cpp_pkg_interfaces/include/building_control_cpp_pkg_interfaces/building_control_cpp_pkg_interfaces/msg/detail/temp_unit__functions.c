// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from building_control_cpp_pkg_interfaces:msg/TempUnit.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/temp_unit__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
building_control_cpp_pkg_interfaces__msg__TempUnit__init(building_control_cpp_pkg_interfaces__msg__TempUnit * msg)
{
  if (!msg) {
    return false;
  }
  // temp_unit
  return true;
}

void
building_control_cpp_pkg_interfaces__msg__TempUnit__fini(building_control_cpp_pkg_interfaces__msg__TempUnit * msg)
{
  if (!msg) {
    return;
  }
  // temp_unit
}

bool
building_control_cpp_pkg_interfaces__msg__TempUnit__are_equal(const building_control_cpp_pkg_interfaces__msg__TempUnit * lhs, const building_control_cpp_pkg_interfaces__msg__TempUnit * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // temp_unit
  if (lhs->temp_unit != rhs->temp_unit) {
    return false;
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__TempUnit__copy(
  const building_control_cpp_pkg_interfaces__msg__TempUnit * input,
  building_control_cpp_pkg_interfaces__msg__TempUnit * output)
{
  if (!input || !output) {
    return false;
  }
  // temp_unit
  output->temp_unit = input->temp_unit;
  return true;
}

building_control_cpp_pkg_interfaces__msg__TempUnit *
building_control_cpp_pkg_interfaces__msg__TempUnit__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__TempUnit * msg = (building_control_cpp_pkg_interfaces__msg__TempUnit *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit));
  bool success = building_control_cpp_pkg_interfaces__msg__TempUnit__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
building_control_cpp_pkg_interfaces__msg__TempUnit__destroy(building_control_cpp_pkg_interfaces__msg__TempUnit * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    building_control_cpp_pkg_interfaces__msg__TempUnit__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__init(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__TempUnit * data = NULL;

  if (size) {
    data = (building_control_cpp_pkg_interfaces__msg__TempUnit *)allocator.zero_allocate(size, sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = building_control_cpp_pkg_interfaces__msg__TempUnit__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        building_control_cpp_pkg_interfaces__msg__TempUnit__fini(&data[i - 1]);
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
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__fini(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array)
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
      building_control_cpp_pkg_interfaces__msg__TempUnit__fini(&array->data[i]);
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

building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence *
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array = (building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__destroy(building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__are_equal(const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * lhs, const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__TempUnit__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence__copy(
  const building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * input,
  building_control_cpp_pkg_interfaces__msg__TempUnit__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(building_control_cpp_pkg_interfaces__msg__TempUnit);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    building_control_cpp_pkg_interfaces__msg__TempUnit * data =
      (building_control_cpp_pkg_interfaces__msg__TempUnit *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!building_control_cpp_pkg_interfaces__msg__TempUnit__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          building_control_cpp_pkg_interfaces__msg__TempUnit__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__TempUnit__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
