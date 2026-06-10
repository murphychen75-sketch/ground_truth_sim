// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/srv/detail/get_target_history__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `target_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `t_start`
// Member `t_end`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
usv_interfaces__srv__GetTargetHistory_Request__init(usv_interfaces__srv__GetTargetHistory_Request * msg)
{
  if (!msg) {
    return false;
  }
  // target_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->target_id)) {
    usv_interfaces__srv__GetTargetHistory_Request__fini(msg);
    return false;
  }
  // t_start
  if (!builtin_interfaces__msg__Time__init(&msg->t_start)) {
    usv_interfaces__srv__GetTargetHistory_Request__fini(msg);
    return false;
  }
  // t_end
  if (!builtin_interfaces__msg__Time__init(&msg->t_end)) {
    usv_interfaces__srv__GetTargetHistory_Request__fini(msg);
    return false;
  }
  // max_samples
  return true;
}

void
usv_interfaces__srv__GetTargetHistory_Request__fini(usv_interfaces__srv__GetTargetHistory_Request * msg)
{
  if (!msg) {
    return;
  }
  // target_id
  unique_identifier_msgs__msg__UUID__fini(&msg->target_id);
  // t_start
  builtin_interfaces__msg__Time__fini(&msg->t_start);
  // t_end
  builtin_interfaces__msg__Time__fini(&msg->t_end);
  // max_samples
}

bool
usv_interfaces__srv__GetTargetHistory_Request__are_equal(const usv_interfaces__srv__GetTargetHistory_Request * lhs, const usv_interfaces__srv__GetTargetHistory_Request * rhs)
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
  // t_start
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->t_start), &(rhs->t_start)))
  {
    return false;
  }
  // t_end
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->t_end), &(rhs->t_end)))
  {
    return false;
  }
  // max_samples
  if (lhs->max_samples != rhs->max_samples) {
    return false;
  }
  return true;
}

bool
usv_interfaces__srv__GetTargetHistory_Request__copy(
  const usv_interfaces__srv__GetTargetHistory_Request * input,
  usv_interfaces__srv__GetTargetHistory_Request * output)
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
  // t_start
  if (!builtin_interfaces__msg__Time__copy(
      &(input->t_start), &(output->t_start)))
  {
    return false;
  }
  // t_end
  if (!builtin_interfaces__msg__Time__copy(
      &(input->t_end), &(output->t_end)))
  {
    return false;
  }
  // max_samples
  output->max_samples = input->max_samples;
  return true;
}

usv_interfaces__srv__GetTargetHistory_Request *
usv_interfaces__srv__GetTargetHistory_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Request * msg = (usv_interfaces__srv__GetTargetHistory_Request *)allocator.allocate(sizeof(usv_interfaces__srv__GetTargetHistory_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__srv__GetTargetHistory_Request));
  bool success = usv_interfaces__srv__GetTargetHistory_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__srv__GetTargetHistory_Request__destroy(usv_interfaces__srv__GetTargetHistory_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__srv__GetTargetHistory_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__srv__GetTargetHistory_Request__Sequence__init(usv_interfaces__srv__GetTargetHistory_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Request * data = NULL;

  if (size) {
    data = (usv_interfaces__srv__GetTargetHistory_Request *)allocator.zero_allocate(size, sizeof(usv_interfaces__srv__GetTargetHistory_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__srv__GetTargetHistory_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__srv__GetTargetHistory_Request__fini(&data[i - 1]);
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
usv_interfaces__srv__GetTargetHistory_Request__Sequence__fini(usv_interfaces__srv__GetTargetHistory_Request__Sequence * array)
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
      usv_interfaces__srv__GetTargetHistory_Request__fini(&array->data[i]);
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

usv_interfaces__srv__GetTargetHistory_Request__Sequence *
usv_interfaces__srv__GetTargetHistory_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Request__Sequence * array = (usv_interfaces__srv__GetTargetHistory_Request__Sequence *)allocator.allocate(sizeof(usv_interfaces__srv__GetTargetHistory_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__srv__GetTargetHistory_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__srv__GetTargetHistory_Request__Sequence__destroy(usv_interfaces__srv__GetTargetHistory_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__srv__GetTargetHistory_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__srv__GetTargetHistory_Request__Sequence__are_equal(const usv_interfaces__srv__GetTargetHistory_Request__Sequence * lhs, const usv_interfaces__srv__GetTargetHistory_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__srv__GetTargetHistory_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__srv__GetTargetHistory_Request__Sequence__copy(
  const usv_interfaces__srv__GetTargetHistory_Request__Sequence * input,
  usv_interfaces__srv__GetTargetHistory_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__srv__GetTargetHistory_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__srv__GetTargetHistory_Request * data =
      (usv_interfaces__srv__GetTargetHistory_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__srv__GetTargetHistory_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__srv__GetTargetHistory_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__srv__GetTargetHistory_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `samples`
#include "usv_interfaces/msg/detail/fused_track_sample__functions.h"

bool
usv_interfaces__srv__GetTargetHistory_Response__init(usv_interfaces__srv__GetTargetHistory_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // samples
  if (!usv_interfaces__msg__FusedTrackSample__Sequence__init(&msg->samples, 0)) {
    usv_interfaces__srv__GetTargetHistory_Response__fini(msg);
    return false;
  }
  return true;
}

void
usv_interfaces__srv__GetTargetHistory_Response__fini(usv_interfaces__srv__GetTargetHistory_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // samples
  usv_interfaces__msg__FusedTrackSample__Sequence__fini(&msg->samples);
}

bool
usv_interfaces__srv__GetTargetHistory_Response__are_equal(const usv_interfaces__srv__GetTargetHistory_Response * lhs, const usv_interfaces__srv__GetTargetHistory_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // samples
  if (!usv_interfaces__msg__FusedTrackSample__Sequence__are_equal(
      &(lhs->samples), &(rhs->samples)))
  {
    return false;
  }
  return true;
}

bool
usv_interfaces__srv__GetTargetHistory_Response__copy(
  const usv_interfaces__srv__GetTargetHistory_Response * input,
  usv_interfaces__srv__GetTargetHistory_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // samples
  if (!usv_interfaces__msg__FusedTrackSample__Sequence__copy(
      &(input->samples), &(output->samples)))
  {
    return false;
  }
  return true;
}

usv_interfaces__srv__GetTargetHistory_Response *
usv_interfaces__srv__GetTargetHistory_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Response * msg = (usv_interfaces__srv__GetTargetHistory_Response *)allocator.allocate(sizeof(usv_interfaces__srv__GetTargetHistory_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__srv__GetTargetHistory_Response));
  bool success = usv_interfaces__srv__GetTargetHistory_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__srv__GetTargetHistory_Response__destroy(usv_interfaces__srv__GetTargetHistory_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__srv__GetTargetHistory_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__srv__GetTargetHistory_Response__Sequence__init(usv_interfaces__srv__GetTargetHistory_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Response * data = NULL;

  if (size) {
    data = (usv_interfaces__srv__GetTargetHistory_Response *)allocator.zero_allocate(size, sizeof(usv_interfaces__srv__GetTargetHistory_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__srv__GetTargetHistory_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__srv__GetTargetHistory_Response__fini(&data[i - 1]);
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
usv_interfaces__srv__GetTargetHistory_Response__Sequence__fini(usv_interfaces__srv__GetTargetHistory_Response__Sequence * array)
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
      usv_interfaces__srv__GetTargetHistory_Response__fini(&array->data[i]);
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

usv_interfaces__srv__GetTargetHistory_Response__Sequence *
usv_interfaces__srv__GetTargetHistory_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__GetTargetHistory_Response__Sequence * array = (usv_interfaces__srv__GetTargetHistory_Response__Sequence *)allocator.allocate(sizeof(usv_interfaces__srv__GetTargetHistory_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__srv__GetTargetHistory_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__srv__GetTargetHistory_Response__Sequence__destroy(usv_interfaces__srv__GetTargetHistory_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__srv__GetTargetHistory_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__srv__GetTargetHistory_Response__Sequence__are_equal(const usv_interfaces__srv__GetTargetHistory_Response__Sequence * lhs, const usv_interfaces__srv__GetTargetHistory_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__srv__GetTargetHistory_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__srv__GetTargetHistory_Response__Sequence__copy(
  const usv_interfaces__srv__GetTargetHistory_Response__Sequence * input,
  usv_interfaces__srv__GetTargetHistory_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__srv__GetTargetHistory_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__srv__GetTargetHistory_Response * data =
      (usv_interfaces__srv__GetTargetHistory_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__srv__GetTargetHistory_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__srv__GetTargetHistory_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__srv__GetTargetHistory_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
