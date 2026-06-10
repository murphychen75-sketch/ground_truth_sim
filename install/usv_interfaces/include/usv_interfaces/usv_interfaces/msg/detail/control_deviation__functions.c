// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/control_deviation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
usv_interfaces__msg__ControlDeviation__init(usv_interfaces__msg__ControlDeviation * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    usv_interfaces__msg__ControlDeviation__fini(msg);
    return false;
  }
  // cross_track_error
  // heading_error
  // distance_to_goal
  // target_speed
  // current_speed
  return true;
}

void
usv_interfaces__msg__ControlDeviation__fini(usv_interfaces__msg__ControlDeviation * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // cross_track_error
  // heading_error
  // distance_to_goal
  // target_speed
  // current_speed
}

bool
usv_interfaces__msg__ControlDeviation__are_equal(const usv_interfaces__msg__ControlDeviation * lhs, const usv_interfaces__msg__ControlDeviation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // cross_track_error
  if (lhs->cross_track_error != rhs->cross_track_error) {
    return false;
  }
  // heading_error
  if (lhs->heading_error != rhs->heading_error) {
    return false;
  }
  // distance_to_goal
  if (lhs->distance_to_goal != rhs->distance_to_goal) {
    return false;
  }
  // target_speed
  if (lhs->target_speed != rhs->target_speed) {
    return false;
  }
  // current_speed
  if (lhs->current_speed != rhs->current_speed) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__ControlDeviation__copy(
  const usv_interfaces__msg__ControlDeviation * input,
  usv_interfaces__msg__ControlDeviation * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // cross_track_error
  output->cross_track_error = input->cross_track_error;
  // heading_error
  output->heading_error = input->heading_error;
  // distance_to_goal
  output->distance_to_goal = input->distance_to_goal;
  // target_speed
  output->target_speed = input->target_speed;
  // current_speed
  output->current_speed = input->current_speed;
  return true;
}

usv_interfaces__msg__ControlDeviation *
usv_interfaces__msg__ControlDeviation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__ControlDeviation * msg = (usv_interfaces__msg__ControlDeviation *)allocator.allocate(sizeof(usv_interfaces__msg__ControlDeviation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__ControlDeviation));
  bool success = usv_interfaces__msg__ControlDeviation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__ControlDeviation__destroy(usv_interfaces__msg__ControlDeviation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__ControlDeviation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__ControlDeviation__Sequence__init(usv_interfaces__msg__ControlDeviation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__ControlDeviation * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__ControlDeviation *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__ControlDeviation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__ControlDeviation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__ControlDeviation__fini(&data[i - 1]);
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
usv_interfaces__msg__ControlDeviation__Sequence__fini(usv_interfaces__msg__ControlDeviation__Sequence * array)
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
      usv_interfaces__msg__ControlDeviation__fini(&array->data[i]);
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

usv_interfaces__msg__ControlDeviation__Sequence *
usv_interfaces__msg__ControlDeviation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__ControlDeviation__Sequence * array = (usv_interfaces__msg__ControlDeviation__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__ControlDeviation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__ControlDeviation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__ControlDeviation__Sequence__destroy(usv_interfaces__msg__ControlDeviation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__ControlDeviation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__ControlDeviation__Sequence__are_equal(const usv_interfaces__msg__ControlDeviation__Sequence * lhs, const usv_interfaces__msg__ControlDeviation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__ControlDeviation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__ControlDeviation__Sequence__copy(
  const usv_interfaces__msg__ControlDeviation__Sequence * input,
  usv_interfaces__msg__ControlDeviation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__ControlDeviation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__ControlDeviation * data =
      (usv_interfaces__msg__ControlDeviation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__ControlDeviation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__ControlDeviation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__ControlDeviation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
