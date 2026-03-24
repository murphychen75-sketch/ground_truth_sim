// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from usv_interfaces:msg/VesselState.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/vessel_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `velocity`
#include "geometry_msgs/msg/detail/twist__functions.h"

bool
usv_interfaces__msg__VesselState__init(usv_interfaces__msg__VesselState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    usv_interfaces__msg__VesselState__fini(msg);
    return false;
  }
  // latitude
  // longitude
  // altitude
  // pose
  if (!geometry_msgs__msg__Pose__init(&msg->pose)) {
    usv_interfaces__msg__VesselState__fini(msg);
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__init(&msg->velocity)) {
    usv_interfaces__msg__VesselState__fini(msg);
    return false;
  }
  // roll
  // pitch
  // yaw
  // battery_voltage
  // battery_percentage
  // leak_detected
  // cpu_temperature
  return true;
}

void
usv_interfaces__msg__VesselState__fini(usv_interfaces__msg__VesselState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // latitude
  // longitude
  // altitude
  // pose
  geometry_msgs__msg__Pose__fini(&msg->pose);
  // velocity
  geometry_msgs__msg__Twist__fini(&msg->velocity);
  // roll
  // pitch
  // yaw
  // battery_voltage
  // battery_percentage
  // leak_detected
  // cpu_temperature
}

bool
usv_interfaces__msg__VesselState__are_equal(const usv_interfaces__msg__VesselState * lhs, const usv_interfaces__msg__VesselState * rhs)
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
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  // pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose), &(rhs->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__are_equal(
      &(lhs->velocity), &(rhs->velocity)))
  {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // battery_percentage
  if (lhs->battery_percentage != rhs->battery_percentage) {
    return false;
  }
  // leak_detected
  if (lhs->leak_detected != rhs->leak_detected) {
    return false;
  }
  // cpu_temperature
  if (lhs->cpu_temperature != rhs->cpu_temperature) {
    return false;
  }
  return true;
}

bool
usv_interfaces__msg__VesselState__copy(
  const usv_interfaces__msg__VesselState * input,
  usv_interfaces__msg__VesselState * output)
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
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // altitude
  output->altitude = input->altitude;
  // pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose), &(output->pose)))
  {
    return false;
  }
  // velocity
  if (!geometry_msgs__msg__Twist__copy(
      &(input->velocity), &(output->velocity)))
  {
    return false;
  }
  // roll
  output->roll = input->roll;
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // battery_percentage
  output->battery_percentage = input->battery_percentage;
  // leak_detected
  output->leak_detected = input->leak_detected;
  // cpu_temperature
  output->cpu_temperature = input->cpu_temperature;
  return true;
}

usv_interfaces__msg__VesselState *
usv_interfaces__msg__VesselState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VesselState * msg = (usv_interfaces__msg__VesselState *)allocator.allocate(sizeof(usv_interfaces__msg__VesselState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(usv_interfaces__msg__VesselState));
  bool success = usv_interfaces__msg__VesselState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
usv_interfaces__msg__VesselState__destroy(usv_interfaces__msg__VesselState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    usv_interfaces__msg__VesselState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
usv_interfaces__msg__VesselState__Sequence__init(usv_interfaces__msg__VesselState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VesselState * data = NULL;

  if (size) {
    data = (usv_interfaces__msg__VesselState *)allocator.zero_allocate(size, sizeof(usv_interfaces__msg__VesselState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = usv_interfaces__msg__VesselState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        usv_interfaces__msg__VesselState__fini(&data[i - 1]);
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
usv_interfaces__msg__VesselState__Sequence__fini(usv_interfaces__msg__VesselState__Sequence * array)
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
      usv_interfaces__msg__VesselState__fini(&array->data[i]);
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

usv_interfaces__msg__VesselState__Sequence *
usv_interfaces__msg__VesselState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  usv_interfaces__msg__VesselState__Sequence * array = (usv_interfaces__msg__VesselState__Sequence *)allocator.allocate(sizeof(usv_interfaces__msg__VesselState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = usv_interfaces__msg__VesselState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
usv_interfaces__msg__VesselState__Sequence__destroy(usv_interfaces__msg__VesselState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    usv_interfaces__msg__VesselState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
usv_interfaces__msg__VesselState__Sequence__are_equal(const usv_interfaces__msg__VesselState__Sequence * lhs, const usv_interfaces__msg__VesselState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!usv_interfaces__msg__VesselState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
usv_interfaces__msg__VesselState__Sequence__copy(
  const usv_interfaces__msg__VesselState__Sequence * input,
  usv_interfaces__msg__VesselState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(usv_interfaces__msg__VesselState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    usv_interfaces__msg__VesselState * data =
      (usv_interfaces__msg__VesselState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!usv_interfaces__msg__VesselState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          usv_interfaces__msg__VesselState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!usv_interfaces__msg__VesselState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
