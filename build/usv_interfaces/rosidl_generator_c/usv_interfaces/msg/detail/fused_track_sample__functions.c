// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/FusedTrackSample.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/fused_track_sample__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
usv_interfaces__msg__FusedTrackSample__init(usv_interfaces__msg__FusedTrackSample * msg)
{
  if (!msg) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    usv_interfaces__msg__FusedTrackSample__fini(msg);
    return false;
  }
  // t_sec
  // x
  // y
  // v_x
  // v_y
  // covariance
  return true;
}

void
usv_interfaces__msg__FusedTrackSample__fini(usv_interfaces__msg__FusedTrackSample * msg)
{
  if (!msg) {
    return;
  }
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
  // t_sec
  // x
  // y
  // v_x
  // v_y
  // covariance
}

bool
usv_interfaces__msg__FusedTrackSample__are_equal(const usv_interfaces__msg__FusedTrackSample * lhs, const usv_interfaces__msg__FusedTrackSample * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  // t_sec
  if (lhs->t_sec != rhs->t_sec) {
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
  // covariance
  for (size_t i = 0; i < 16; ++i) {
    if (lhs->covariance[i] != rhs->covariance[i]) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__FusedTrackSample__copy(
  const usv_interfaces__msg__FusedTrackSample * input,
  usv_interfaces__msg__FusedTrackSample * output)
{
  if (!input || !output) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  // t_sec
  output->t_sec = input->t_sec;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // v_x
  output->v_x = input->v_x;
  // v_y
  output->v_y = input->v_y;
  // covariance
  for (size_t i = 0; i < 16; ++i) {
    output->covariance[i] = input->covariance[i];
  }
  return true;
}

usv_interfaces__msg__FusedTrackSample *
usv_interfaces__msg__FusedTrackSample__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTrackSample * msg = (usv_interfaces__msg__FusedTrackSample *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTrackSample), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__FusedTrackSample));
  bool success = usv_interfaces__msg__FusedTrackSample__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__FusedTrackSample__destroy(usv_interfaces__msg__FusedTrackSample * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__FusedTrackSample__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__FusedTrackSample__Sequence__init(usv_interfaces__msg__FusedTrackSample__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTrackSample * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__FusedTrackSample *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__FusedTrackSample), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__FusedTrackSample__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__FusedTrackSample__fini(&data[i - 1]);
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
usv_interfaces__msg__FusedTrackSample__Sequence__fini(usv_interfaces__msg__FusedTrackSample__Sequence * array)
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
      usv_interfaces__msg__FusedTrackSample__fini(&array->data[i]);
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

usv_interfaces__msg__FusedTrackSample__Sequence *
usv_interfaces__msg__FusedTrackSample__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTrackSample__Sequence * array = (usv_interfaces__msg__FusedTrackSample__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTrackSample__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__FusedTrackSample__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__FusedTrackSample__Sequence__destroy(usv_interfaces__msg__FusedTrackSample__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__FusedTrackSample__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__FusedTrackSample__Sequence__are_equal(const usv_interfaces__msg__FusedTrackSample__Sequence * lhs, const usv_interfaces__msg__FusedTrackSample__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__FusedTrackSample__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__FusedTrackSample__Sequence__copy(
  const usv_interfaces__msg__FusedTrackSample__Sequence * input,
  usv_interfaces__msg__FusedTrackSample__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__FusedTrackSample);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__FusedTrackSample * data =
      (usv_interfaces__msg__FusedTrackSample *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__FusedTrackSample__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__FusedTrackSample__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__FusedTrackSample__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
