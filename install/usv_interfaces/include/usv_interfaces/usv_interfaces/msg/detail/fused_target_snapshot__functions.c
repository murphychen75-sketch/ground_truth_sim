// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/fused_target_snapshot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `state`
#include "usv_interfaces/msg/detail/fused_track_sample__functions.h"

bool
usv_interfaces__msg__FusedTargetSnapshot__init(usv_interfaces__msg__FusedTargetSnapshot * msg)
{
  if (!msg) {
    return false;
  }
  // target_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->target_id)) {
    usv_interfaces__msg__FusedTargetSnapshot__fini(msg);
    return false;
  }
  // state
  if (!usv_interfaces__msg__FusedTrackSample__init(&msg->state)) {
    usv_interfaces__msg__FusedTargetSnapshot__fini(msg);
    return false;
  }
  // size_w
  // size_l
  // size_h
  // is_dark_target
  // is_ais_matched
  // matched_mmsi
  return true;
}

void
usv_interfaces__msg__FusedTargetSnapshot__fini(usv_interfaces__msg__FusedTargetSnapshot * msg)
{
  if (!msg) {
    return;
  }
  // target_id
  unique_identifier_msgs__msg__UUID__fini(&msg->target_id);
  // state
  usv_interfaces__msg__FusedTrackSample__fini(&msg->state);
  // size_w
  // size_l
  // size_h
  // is_dark_target
  // is_ais_matched
  // matched_mmsi
}

bool
usv_interfaces__msg__FusedTargetSnapshot__are_equal(const usv_interfaces__msg__FusedTargetSnapshot * lhs, const usv_interfaces__msg__FusedTargetSnapshot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->target_id), &(rhs->target_id)))
  {
    return false;
  }
  // state
  if (!usv_interfaces__msg__FusedTrackSample__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // size_w
  if (lhs->size_w != rhs->size_w) {
    return false;
  }
  // size_l
  if (lhs->size_l != rhs->size_l) {
    return false;
  }
  // size_h
  if (lhs->size_h != rhs->size_h) {
    return false;
  }
  // is_dark_target
  if (lhs->is_dark_target != rhs->is_dark_target) {
    return false;
  }
  // is_ais_matched
  if (lhs->is_ais_matched != rhs->is_ais_matched) {
    return false;
  }
  // matched_mmsi
  if (lhs->matched_mmsi != rhs->matched_mmsi) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__FusedTargetSnapshot__copy(
  const usv_interfaces__msg__FusedTargetSnapshot * input,
  usv_interfaces__msg__FusedTargetSnapshot * output)
{
  if (!input || !output) {
    return false;
  }
  // target_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->target_id), &(output->target_id)))
  {
    return false;
  }
  // state
  if (!usv_interfaces__msg__FusedTrackSample__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // size_w
  output->size_w = input->size_w;
  // size_l
  output->size_l = input->size_l;
  // size_h
  output->size_h = input->size_h;
  // is_dark_target
  output->is_dark_target = input->is_dark_target;
  // is_ais_matched
  output->is_ais_matched = input->is_ais_matched;
  // matched_mmsi
  output->matched_mmsi = input->matched_mmsi;
  return true;
}

usv_interfaces__msg__FusedTargetSnapshot *
usv_interfaces__msg__FusedTargetSnapshot__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetSnapshot * msg = (usv_interfaces__msg__FusedTargetSnapshot *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTargetSnapshot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__FusedTargetSnapshot));
  bool success = usv_interfaces__msg__FusedTargetSnapshot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__FusedTargetSnapshot__destroy(usv_interfaces__msg__FusedTargetSnapshot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__FusedTargetSnapshot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__FusedTargetSnapshot__Sequence__init(usv_interfaces__msg__FusedTargetSnapshot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetSnapshot * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__FusedTargetSnapshot *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__FusedTargetSnapshot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__FusedTargetSnapshot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__FusedTargetSnapshot__fini(&data[i - 1]);
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
usv_interfaces__msg__FusedTargetSnapshot__Sequence__fini(usv_interfaces__msg__FusedTargetSnapshot__Sequence * array)
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
      usv_interfaces__msg__FusedTargetSnapshot__fini(&array->data[i]);
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

usv_interfaces__msg__FusedTargetSnapshot__Sequence *
usv_interfaces__msg__FusedTargetSnapshot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetSnapshot__Sequence * array = (usv_interfaces__msg__FusedTargetSnapshot__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTargetSnapshot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__FusedTargetSnapshot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__FusedTargetSnapshot__Sequence__destroy(usv_interfaces__msg__FusedTargetSnapshot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__FusedTargetSnapshot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__FusedTargetSnapshot__Sequence__are_equal(const usv_interfaces__msg__FusedTargetSnapshot__Sequence * lhs, const usv_interfaces__msg__FusedTargetSnapshot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__FusedTargetSnapshot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__FusedTargetSnapshot__Sequence__copy(
  const usv_interfaces__msg__FusedTargetSnapshot__Sequence * input,
  usv_interfaces__msg__FusedTargetSnapshot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__FusedTargetSnapshot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__FusedTargetSnapshot * data =
      (usv_interfaces__msg__FusedTargetSnapshot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__FusedTargetSnapshot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__FusedTargetSnapshot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__FusedTargetSnapshot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
