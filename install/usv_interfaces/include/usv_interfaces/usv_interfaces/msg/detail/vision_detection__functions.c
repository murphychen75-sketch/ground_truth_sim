// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/VisionDetection.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/vision_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `camera_id`
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"

bool
usv_interfaces__msg__VisionDetection__init(usv_interfaces__msg__VisionDetection * msg)
{
  if (!msg) {
    return false;
  }
  // camera_id
  if (!rosidl_runtime_c__String__init(&msg->camera_id)) {
    usv_interfaces__msg__VisionDetection__fini(msg);
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    usv_interfaces__msg__VisionDetection__fini(msg);
    return false;
  }
  // class_id
  // azimuth
  // distance_predict
  // size_w
  // size_h
  // pixel_width
  // confidence
  return true;
}

void
usv_interfaces__msg__VisionDetection__fini(usv_interfaces__msg__VisionDetection * msg)
{
  if (!msg) {
    return;
  }
  // camera_id
  rosidl_runtime_c__String__fini(&msg->camera_id);
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // class_id
  // azimuth
  // distance_predict
  // size_w
  // size_h
  // pixel_width
  // confidence
}

bool
usv_interfaces__msg__VisionDetection__are_equal(const usv_interfaces__msg__VisionDetection * lhs, const usv_interfaces__msg__VisionDetection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // camera_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->camera_id), &(rhs->camera_id)))
  {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // class_id
  if (lhs->class_id != rhs->class_id) {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // distance_predict
  if (lhs->distance_predict != rhs->distance_predict) {
    return false;
  }
  // size_w
  if (lhs->size_w != rhs->size_w) {
    return false;
  }
  // size_h
  if (lhs->size_h != rhs->size_h) {
    return false;
  }
  // pixel_width
  if (lhs->pixel_width != rhs->pixel_width) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__VisionDetection__copy(
  const usv_interfaces__msg__VisionDetection * input,
  usv_interfaces__msg__VisionDetection * output)
{
  if (!input || !output) {
    return false;
  }
  // camera_id
  if (!rosidl_runtime_c__String__copy(
      &(input->camera_id), &(output->camera_id)))
  {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // class_id
  output->class_id = input->class_id;
  // azimuth
  output->azimuth = input->azimuth;
  // distance_predict
  output->distance_predict = input->distance_predict;
  // size_w
  output->size_w = input->size_w;
  // size_h
  output->size_h = input->size_h;
  // pixel_width
  output->pixel_width = input->pixel_width;
  // confidence
  output->confidence = input->confidence;
  return true;
}

usv_interfaces__msg__VisionDetection *
usv_interfaces__msg__VisionDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VisionDetection * msg = (usv_interfaces__msg__VisionDetection *)allocator.allocate(sizeof(usv_interfaces__msg__VisionDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__VisionDetection));
  bool success = usv_interfaces__msg__VisionDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__VisionDetection__destroy(usv_interfaces__msg__VisionDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__VisionDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__VisionDetection__Sequence__init(usv_interfaces__msg__VisionDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VisionDetection * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__VisionDetection *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__VisionDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__VisionDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__VisionDetection__fini(&data[i - 1]);
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
usv_interfaces__msg__VisionDetection__Sequence__fini(usv_interfaces__msg__VisionDetection__Sequence * array)
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
      usv_interfaces__msg__VisionDetection__fini(&array->data[i]);
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

usv_interfaces__msg__VisionDetection__Sequence *
usv_interfaces__msg__VisionDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VisionDetection__Sequence * array = (usv_interfaces__msg__VisionDetection__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__VisionDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__VisionDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__VisionDetection__Sequence__destroy(usv_interfaces__msg__VisionDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__VisionDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__VisionDetection__Sequence__are_equal(const usv_interfaces__msg__VisionDetection__Sequence * lhs, const usv_interfaces__msg__VisionDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__VisionDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__VisionDetection__Sequence__copy(
  const usv_interfaces__msg__VisionDetection__Sequence * input,
  usv_interfaces__msg__VisionDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__VisionDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__VisionDetection * data =
      (usv_interfaces__msg__VisionDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__VisionDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__VisionDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__VisionDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
