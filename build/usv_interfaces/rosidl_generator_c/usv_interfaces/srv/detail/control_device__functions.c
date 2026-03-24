// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:srv/ControlDevice.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/srv/detail/control_device__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `device_id`
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
usv_interfaces__srv__ControlDevice_Request__init(usv_interfaces__srv__ControlDevice_Request * msg)
{
  if (!msg) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    usv_interfaces__srv__ControlDevice_Request__fini(msg);
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    usv_interfaces__srv__ControlDevice_Request__fini(msg);
    return false;
  }
  // value
  return true;
}

void
usv_interfaces__srv__ControlDevice_Request__fini(usv_interfaces__srv__ControlDevice_Request * msg)
{
  if (!msg) {
    return;
  }
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // value
}

bool
usv_interfaces__srv__ControlDevice_Request__are_equal(const usv_interfaces__srv__ControlDevice_Request * lhs, const usv_interfaces__srv__ControlDevice_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // value
  if (lhs->value != rhs->value) {
    return false;
  }
  return true;
}

bool
usv_interfaces__srv__ControlDevice_Request__copy(
  const usv_interfaces__srv__ControlDevice_Request * input,
  usv_interfaces__srv__ControlDevice_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // value
  output->value = input->value;
  return true;
}

usv_interfaces__srv__ControlDevice_Request *
usv_interfaces__srv__ControlDevice_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Request * msg = (usv_interfaces__srv__ControlDevice_Request *)allocator.allocate(sizeof(usv_interfaces__srv__ControlDevice_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__srv__ControlDevice_Request));
  bool success = usv_interfaces__srv__ControlDevice_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__srv__ControlDevice_Request__destroy(usv_interfaces__srv__ControlDevice_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__srv__ControlDevice_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__srv__ControlDevice_Request__Sequence__init(usv_interfaces__srv__ControlDevice_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Request * data = NULL;

  if (size) {
    data = (usv_interfaces__srv__ControlDevice_Request *)allocator.zero_allocate(size, sizeof(usv_interfaces__srv__ControlDevice_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__srv__ControlDevice_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__srv__ControlDevice_Request__fini(&data[i - 1]);
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
usv_interfaces__srv__ControlDevice_Request__Sequence__fini(usv_interfaces__srv__ControlDevice_Request__Sequence * array)
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
      usv_interfaces__srv__ControlDevice_Request__fini(&array->data[i]);
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

usv_interfaces__srv__ControlDevice_Request__Sequence *
usv_interfaces__srv__ControlDevice_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Request__Sequence * array = (usv_interfaces__srv__ControlDevice_Request__Sequence *)allocator.allocate(sizeof(usv_interfaces__srv__ControlDevice_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__srv__ControlDevice_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__srv__ControlDevice_Request__Sequence__destroy(usv_interfaces__srv__ControlDevice_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__srv__ControlDevice_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__srv__ControlDevice_Request__Sequence__are_equal(const usv_interfaces__srv__ControlDevice_Request__Sequence * lhs, const usv_interfaces__srv__ControlDevice_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__srv__ControlDevice_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__srv__ControlDevice_Request__Sequence__copy(
  const usv_interfaces__srv__ControlDevice_Request__Sequence * input,
  usv_interfaces__srv__ControlDevice_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__srv__ControlDevice_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__srv__ControlDevice_Request * data =
      (usv_interfaces__srv__ControlDevice_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__srv__ControlDevice_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__srv__ControlDevice_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__srv__ControlDevice_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
usv_interfaces__srv__ControlDevice_Response__init(usv_interfaces__srv__ControlDevice_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    usv_interfaces__srv__ControlDevice_Response__fini(msg);
    return false;
  }
  return true;
}

void
usv_interfaces__srv__ControlDevice_Response__fini(usv_interfaces__srv__ControlDevice_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
usv_interfaces__srv__ControlDevice_Response__are_equal(const usv_interfaces__srv__ControlDevice_Response * lhs, const usv_interfaces__srv__ControlDevice_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
usv_interfaces__srv__ControlDevice_Response__copy(
  const usv_interfaces__srv__ControlDevice_Response * input,
  usv_interfaces__srv__ControlDevice_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

usv_interfaces__srv__ControlDevice_Response *
usv_interfaces__srv__ControlDevice_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Response * msg = (usv_interfaces__srv__ControlDevice_Response *)allocator.allocate(sizeof(usv_interfaces__srv__ControlDevice_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__srv__ControlDevice_Response));
  bool success = usv_interfaces__srv__ControlDevice_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__srv__ControlDevice_Response__destroy(usv_interfaces__srv__ControlDevice_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__srv__ControlDevice_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__srv__ControlDevice_Response__Sequence__init(usv_interfaces__srv__ControlDevice_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Response * data = NULL;

  if (size) {
    data = (usv_interfaces__srv__ControlDevice_Response *)allocator.zero_allocate(size, sizeof(usv_interfaces__srv__ControlDevice_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__srv__ControlDevice_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__srv__ControlDevice_Response__fini(&data[i - 1]);
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
usv_interfaces__srv__ControlDevice_Response__Sequence__fini(usv_interfaces__srv__ControlDevice_Response__Sequence * array)
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
      usv_interfaces__srv__ControlDevice_Response__fini(&array->data[i]);
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

usv_interfaces__srv__ControlDevice_Response__Sequence *
usv_interfaces__srv__ControlDevice_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__srv__ControlDevice_Response__Sequence * array = (usv_interfaces__srv__ControlDevice_Response__Sequence *)allocator.allocate(sizeof(usv_interfaces__srv__ControlDevice_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__srv__ControlDevice_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__srv__ControlDevice_Response__Sequence__destroy(usv_interfaces__srv__ControlDevice_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__srv__ControlDevice_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__srv__ControlDevice_Response__Sequence__are_equal(const usv_interfaces__srv__ControlDevice_Response__Sequence * lhs, const usv_interfaces__srv__ControlDevice_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__srv__ControlDevice_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__srv__ControlDevice_Response__Sequence__copy(
  const usv_interfaces__srv__ControlDevice_Response__Sequence * input,
  usv_interfaces__srv__ControlDevice_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__srv__ControlDevice_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__srv__ControlDevice_Response * data =
      (usv_interfaces__srv__ControlDevice_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__srv__ControlDevice_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__srv__ControlDevice_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__srv__ControlDevice_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
