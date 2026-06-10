// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/ControlDeviation in the package usv_interfaces.
typedef struct usv_interfaces__msg__ControlDeviation
{
  std_msgs__msg__Header header;
  /// 循迹误差 (偏航距离 m, 左正右负)
  float cross_track_error;
  /// 艏向误差 (rad)
  float heading_error;
  /// 距离当前局部目标点的距离 (m)
  float distance_to_goal;
  /// 期望航速 (m/s)
  float target_speed;
  /// 实际航速 (m/s)
  float current_speed;
} usv_interfaces__msg__ControlDeviation;

// Struct for a sequence of usv_interfaces__msg__ControlDeviation.
typedef struct usv_interfaces__msg__ControlDeviation__Sequence
{
  usv_interfaces__msg__ControlDeviation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__ControlDeviation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_H_
