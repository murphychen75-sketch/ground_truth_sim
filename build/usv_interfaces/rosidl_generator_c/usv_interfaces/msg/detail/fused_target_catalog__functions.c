// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/FusedTargetCatalog.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/fused_target_catalog__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `profiles`
#include "usv_interfaces/msg/detail/fused_target_profile__functions.h"

bool
usv_interfaces__msg__FusedTargetCatalog__init(usv_interfaces__msg__FusedTargetCatalog * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    usv_interfaces__msg__FusedTargetCatalog__fini(msg);
    return false;
  }
  // profiles
  if (!usv_interfaces__msg__FusedTargetProfile__Sequence__init(&msg->profiles, 0)) {
    usv_interfaces__msg__FusedTargetCatalog__fini(msg);
    return false;
  }
  return true;
}

void
usv_interfaces__msg__FusedTargetCatalog__fini(usv_interfaces__msg__FusedTargetCatalog * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // profiles
  usv_interfaces__msg__FusedTargetProfile__Sequence__fini(&msg->profiles);
}

bool
usv_interfaces__msg__FusedTargetCatalog__are_equal(const usv_interfaces__msg__FusedTargetCatalog * lhs, const usv_interfaces__msg__FusedTargetCatalog * rhs)
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
  // profiles
  if (!usv_interfaces__msg__FusedTargetProfile__Sequence__are_equal(
      &(lhs->profiles), &(rhs->profiles)))
  {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__FusedTargetCatalog__copy(
  const usv_interfaces__msg__FusedTargetCatalog * input,
  usv_interfaces__msg__FusedTargetCatalog * output)
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
  // profiles
  if (!usv_interfaces__msg__FusedTargetProfile__Sequence__copy(
      &(input->profiles), &(output->profiles)))
  {
    return false;
  }
  return true;
}

usv_interfaces__msg__FusedTargetCatalog *
usv_interfaces__msg__FusedTargetCatalog__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetCatalog * msg = (usv_interfaces__msg__FusedTargetCatalog *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTargetCatalog), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__FusedTargetCatalog));
  bool success = usv_interfaces__msg__FusedTargetCatalog__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__FusedTargetCatalog__destroy(usv_interfaces__msg__FusedTargetCatalog * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__FusedTargetCatalog__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__FusedTargetCatalog__Sequence__init(usv_interfaces__msg__FusedTargetCatalog__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetCatalog * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__FusedTargetCatalog *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__FusedTargetCatalog), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__FusedTargetCatalog__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__FusedTargetCatalog__fini(&data[i - 1]);
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
usv_interfaces__msg__FusedTargetCatalog__Sequence__fini(usv_interfaces__msg__FusedTargetCatalog__Sequence * array)
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
      usv_interfaces__msg__FusedTargetCatalog__fini(&array->data[i]);
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

usv_interfaces__msg__FusedTargetCatalog__Sequence *
usv_interfaces__msg__FusedTargetCatalog__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__FusedTargetCatalog__Sequence * array = (usv_interfaces__msg__FusedTargetCatalog__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__FusedTargetCatalog__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__FusedTargetCatalog__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__FusedTargetCatalog__Sequence__destroy(usv_interfaces__msg__FusedTargetCatalog__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__FusedTargetCatalog__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__FusedTargetCatalog__Sequence__are_equal(const usv_interfaces__msg__FusedTargetCatalog__Sequence * lhs, const usv_interfaces__msg__FusedTargetCatalog__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__FusedTargetCatalog__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__FusedTargetCatalog__Sequence__copy(
  const usv_interfaces__msg__FusedTargetCatalog__Sequence * input,
  usv_interfaces__msg__FusedTargetCatalog__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__FusedTargetCatalog);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__FusedTargetCatalog * data =
      (usv_interfaces__msg__FusedTargetCatalog *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__FusedTargetCatalog__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__FusedTargetCatalog__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__FusedTargetCatalog__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
