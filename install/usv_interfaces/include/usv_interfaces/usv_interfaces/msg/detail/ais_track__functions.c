// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/ais_track__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `ship_name`
#include "rosidl_runtime_c/string_functions.h"

bool
usv_interfaces__msg__AISTrack__init(usv_interfaces__msg__AISTrack * msg)
{
  if (!msg) {
    return false;
  }
  // mmsi
  // ship_name
  if (!rosidl_runtime_c__String__init(&msg->ship_name)) {
    usv_interfaces__msg__AISTrack__fini(msg);
    return false;
  }
  // relative_x
  // relative_y
  // relative_v_x
  // relative_v_y
  // true_heading
  return true;
}

void
usv_interfaces__msg__AISTrack__fini(usv_interfaces__msg__AISTrack * msg)
{
  if (!msg) {
    return;
  }
  // mmsi
  // ship_name
  rosidl_runtime_c__String__fini(&msg->ship_name);
  // relative_x
  // relative_y
  // relative_v_x
  // relative_v_y
  // true_heading
}

bool
usv_interfaces__msg__AISTrack__are_equal(const usv_interfaces__msg__AISTrack * lhs, const usv_interfaces__msg__AISTrack * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mmsi
  if (lhs->mmsi != rhs->mmsi) {
    return false;
  }
  // ship_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ship_name), &(rhs->ship_name)))
  {
    return false;
  }
  // relative_x
  if (lhs->relative_x != rhs->relative_x) {
    return false;
  }
  // relative_y
  if (lhs->relative_y != rhs->relative_y) {
    return false;
  }
  // relative_v_x
  if (lhs->relative_v_x != rhs->relative_v_x) {
    return false;
  }
  // relative_v_y
  if (lhs->relative_v_y != rhs->relative_v_y) {
    return false;
  }
  // true_heading
  if (lhs->true_heading != rhs->true_heading) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__AISTrack__copy(
  const usv_interfaces__msg__AISTrack * input,
  usv_interfaces__msg__AISTrack * output)
{
  if (!input || !output) {
    return false;
  }
  // mmsi
  output->mmsi = input->mmsi;
  // ship_name
  if (!rosidl_runtime_c__String__copy(
      &(input->ship_name), &(output->ship_name)))
  {
    return false;
  }
  // relative_x
  output->relative_x = input->relative_x;
  // relative_y
  output->relative_y = input->relative_y;
  // relative_v_x
  output->relative_v_x = input->relative_v_x;
  // relative_v_y
  output->relative_v_y = input->relative_v_y;
  // true_heading
  output->true_heading = input->true_heading;
  return true;
}

usv_interfaces__msg__AISTrack *
usv_interfaces__msg__AISTrack__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__AISTrack * msg = (usv_interfaces__msg__AISTrack *)allocator.allocate(sizeof(usv_interfaces__msg__AISTrack), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__AISTrack));
  bool success = usv_interfaces__msg__AISTrack__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__AISTrack__destroy(usv_interfaces__msg__AISTrack * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__AISTrack__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__AISTrack__Sequence__init(usv_interfaces__msg__AISTrack__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__AISTrack * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__AISTrack *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__AISTrack), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__AISTrack__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__AISTrack__fini(&data[i - 1]);
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
usv_interfaces__msg__AISTrack__Sequence__fini(usv_interfaces__msg__AISTrack__Sequence * array)
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
      usv_interfaces__msg__AISTrack__fini(&array->data[i]);
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

usv_interfaces__msg__AISTrack__Sequence *
usv_interfaces__msg__AISTrack__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__AISTrack__Sequence * array = (usv_interfaces__msg__AISTrack__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__AISTrack__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__AISTrack__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__AISTrack__Sequence__destroy(usv_interfaces__msg__AISTrack__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__AISTrack__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__AISTrack__Sequence__are_equal(const usv_interfaces__msg__AISTrack__Sequence * lhs, const usv_interfaces__msg__AISTrack__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__AISTrack__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__AISTrack__Sequence__copy(
  const usv_interfaces__msg__AISTrack__Sequence * input,
  usv_interfaces__msg__AISTrack__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__AISTrack);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__AISTrack * data =
      (usv_interfaces__msg__AISTrack *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__AISTrack__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__AISTrack__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__AISTrack__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
