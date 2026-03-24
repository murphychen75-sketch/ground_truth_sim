// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/NavRadarTarget.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/nav_radar_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
usv_interfaces__msg__NavRadarTarget__init(usv_interfaces__msg__NavRadarTarget * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // v_x
  // v_y
  // area
  return true;
}

void
usv_interfaces__msg__NavRadarTarget__fini(usv_interfaces__msg__NavRadarTarget * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // v_x
  // v_y
  // area
}

bool
usv_interfaces__msg__NavRadarTarget__are_equal(const usv_interfaces__msg__NavRadarTarget * lhs, const usv_interfaces__msg__NavRadarTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // v_x
  if (lhs->v_x != rhs->v_x) {
    return false;
  }
  // v_y
  if (lhs->v_y != rhs->v_y) {
    return false;
  }
  // area
  if (lhs->area != rhs->area) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__NavRadarTarget__copy(
  const usv_interfaces__msg__NavRadarTarget * input,
  usv_interfaces__msg__NavRadarTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // v_x
  output->v_x = input->v_x;
  // v_y
  output->v_y = input->v_y;
  // area
  output->area = input->area;
  return true;
}

usv_interfaces__msg__NavRadarTarget *
usv_interfaces__msg__NavRadarTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__NavRadarTarget * msg = (usv_interfaces__msg__NavRadarTarget *)allocator.allocate(sizeof(usv_interfaces__msg__NavRadarTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__NavRadarTarget));
  bool success = usv_interfaces__msg__NavRadarTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__NavRadarTarget__destroy(usv_interfaces__msg__NavRadarTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__NavRadarTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__NavRadarTarget__Sequence__init(usv_interfaces__msg__NavRadarTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__NavRadarTarget * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__NavRadarTarget *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__NavRadarTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__NavRadarTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__NavRadarTarget__fini(&data[i - 1]);
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
usv_interfaces__msg__NavRadarTarget__Sequence__fini(usv_interfaces__msg__NavRadarTarget__Sequence * array)
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
      usv_interfaces__msg__NavRadarTarget__fini(&array->data[i]);
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

usv_interfaces__msg__NavRadarTarget__Sequence *
usv_interfaces__msg__NavRadarTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__NavRadarTarget__Sequence * array = (usv_interfaces__msg__NavRadarTarget__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__NavRadarTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__NavRadarTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__NavRadarTarget__Sequence__destroy(usv_interfaces__msg__NavRadarTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__NavRadarTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__NavRadarTarget__Sequence__are_equal(const usv_interfaces__msg__NavRadarTarget__Sequence * lhs, const usv_interfaces__msg__NavRadarTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__NavRadarTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__NavRadarTarget__Sequence__copy(
  const usv_interfaces__msg__NavRadarTarget__Sequence * input,
  usv_interfaces__msg__NavRadarTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__NavRadarTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__NavRadarTarget * data =
      (usv_interfaces__msg__NavRadarTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__NavRadarTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__NavRadarTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__NavRadarTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
