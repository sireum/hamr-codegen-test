// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from building_control_cpp_pkg_interfaces:msg/SetPointimpl.idl
// generated code does not contain a copyright notice
#include "building_control_cpp_pkg_interfaces/msg/detail/set_pointimpl__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `low`
// Member `high`
#include "building_control_cpp_pkg_interfaces/msg/detail/temperatureimpl__functions.h"

bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__init(building_control_cpp_pkg_interfaces__msg__SetPointimpl * msg)
{
  if (!msg) {
    return false;
  }
  // low
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__init(&msg->low)) {
    building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(msg);
    return false;
  }
  // high
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__init(&msg->high)) {
    building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(msg);
    return false;
  }
  return true;
}

void
building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(building_control_cpp_pkg_interfaces__msg__SetPointimpl * msg)
{
  if (!msg) {
    return;
  }
  // low
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl__fini(&msg->low);
  // high
  building_control_cpp_pkg_interfaces__msg__Temperatureimpl__fini(&msg->high);
}

bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__are_equal(const building_control_cpp_pkg_interfaces__msg__SetPointimpl * lhs, const building_control_cpp_pkg_interfaces__msg__SetPointimpl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // low
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__are_equal(
      &(lhs->low), &(rhs->low)))
  {
    return false;
  }
  // high
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__are_equal(
      &(lhs->high), &(rhs->high)))
  {
    return false;
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__copy(
  const building_control_cpp_pkg_interfaces__msg__SetPointimpl * input,
  building_control_cpp_pkg_interfaces__msg__SetPointimpl * output)
{
  if (!input || !output) {
    return false;
  }
  // low
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__copy(
      &(input->low), &(output->low)))
  {
    return false;
  }
  // high
  if (!building_control_cpp_pkg_interfaces__msg__Temperatureimpl__copy(
      &(input->high), &(output->high)))
  {
    return false;
  }
  return true;
}

building_control_cpp_pkg_interfaces__msg__SetPointimpl *
building_control_cpp_pkg_interfaces__msg__SetPointimpl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__SetPointimpl * msg = (building_control_cpp_pkg_interfaces__msg__SetPointimpl *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__SetPointimpl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(building_control_cpp_pkg_interfaces__msg__SetPointimpl));
  bool success = building_control_cpp_pkg_interfaces__msg__SetPointimpl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
building_control_cpp_pkg_interfaces__msg__SetPointimpl__destroy(building_control_cpp_pkg_interfaces__msg__SetPointimpl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__init(building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__SetPointimpl * data = NULL;

  if (size) {
    data = (building_control_cpp_pkg_interfaces__msg__SetPointimpl *)allocator.zero_allocate(size, sizeof(building_control_cpp_pkg_interfaces__msg__SetPointimpl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = building_control_cpp_pkg_interfaces__msg__SetPointimpl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(&data[i - 1]);
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
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__fini(building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * array)
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
      building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(&array->data[i]);
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

building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence *
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * array = (building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence *)allocator.allocate(sizeof(building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__destroy(building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__are_equal(const building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * lhs, const building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__SetPointimpl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence__copy(
  const building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * input,
  building_control_cpp_pkg_interfaces__msg__SetPointimpl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(building_control_cpp_pkg_interfaces__msg__SetPointimpl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    building_control_cpp_pkg_interfaces__msg__SetPointimpl * data =
      (building_control_cpp_pkg_interfaces__msg__SetPointimpl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!building_control_cpp_pkg_interfaces__msg__SetPointimpl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          building_control_cpp_pkg_interfaces__msg__SetPointimpl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!building_control_cpp_pkg_interfaces__msg__SetPointimpl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
