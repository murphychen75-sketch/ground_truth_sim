// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/MmwaveTargetArray.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/mmwave_target_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `targets`
#include "usv_interfaces/msg/detail/mmwave_target__functions.h"

bool
usv_interfaces__msg__MmwaveTargetArray__init(usv_interfaces__msg__MmwaveTargetArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    usv_interfaces__msg__MmwaveTargetArray__fini(msg);
    return false;
  }
  // targets
  if (!usv_interfaces__msg__MmwaveTarget__Sequence__init(&msg->targets, 0)) {
    usv_interfaces__msg__MmwaveTargetArray__fini(msg);
    return false;
  }
  return true;
}

void
usv_interfaces__msg__MmwaveTargetArray__fini(usv_interfaces__msg__MmwaveTargetArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // targets
  usv_interfaces__msg__MmwaveTarget__Sequence__fini(&msg->targets);
}

bool
usv_interfaces__msg__MmwaveTargetArray__are_equal(const usv_interfaces__msg__MmwaveTargetArray * lhs, const usv_interfaces__msg__MmwaveTargetArray * rhs)
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
  // targets
  if (!usv_interfaces__msg__MmwaveTarget__Sequence__are_equal(
      &(lhs->targets), &(rhs->targets)))
  {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__MmwaveTargetArray__copy(
  const usv_interfaces__msg__MmwaveTargetArray * input,
  usv_interfaces__msg__MmwaveTargetArray * output)
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
  // targets
  if (!usv_interfaces__msg__MmwaveTarget__Sequence__copy(
      &(input->targets), &(output->targets)))
  {
    return false;
  }
  return true;
}

usv_interfaces__msg__MmwaveTargetArray *
usv_interfaces__msg__MmwaveTargetArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__MmwaveTargetArray * msg = (usv_interfaces__msg__MmwaveTargetArray *)allocator.allocate(sizeof(usv_interfaces__msg__MmwaveTargetArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__MmwaveTargetArray));
  bool success = usv_interfaces__msg__MmwaveTargetArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__MmwaveTargetArray__destroy(usv_interfaces__msg__MmwaveTargetArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__MmwaveTargetArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__MmwaveTargetArray__Sequence__init(usv_interfaces__msg__MmwaveTargetArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__MmwaveTargetArray * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__MmwaveTargetArray *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__MmwaveTargetArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__MmwaveTargetArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__MmwaveTargetArray__fini(&data[i - 1]);
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
usv_interfaces__msg__MmwaveTargetArray__Sequence__fini(usv_interfaces__msg__MmwaveTargetArray__Sequence * array)
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
      usv_interfaces__msg__MmwaveTargetArray__fini(&array->data[i]);
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

usv_interfaces__msg__MmwaveTargetArray__Sequence *
usv_interfaces__msg__MmwaveTargetArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__MmwaveTargetArray__Sequence * array = (usv_interfaces__msg__MmwaveTargetArray__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__MmwaveTargetArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__MmwaveTargetArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__MmwaveTargetArray__Sequence__destroy(usv_interfaces__msg__MmwaveTargetArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__MmwaveTargetArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__MmwaveTargetArray__Sequence__are_equal(const usv_interfaces__msg__MmwaveTargetArray__Sequence * lhs, const usv_interfaces__msg__MmwaveTargetArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__MmwaveTargetArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__MmwaveTargetArray__Sequence__copy(
  const usv_interfaces__msg__MmwaveTargetArray__Sequence * input,
  usv_interfaces__msg__MmwaveTargetArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__MmwaveTargetArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__MmwaveTargetArray * data =
      (usv_interfaces__msg__MmwaveTargetArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__MmwaveTargetArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__MmwaveTargetArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__MmwaveTargetArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
