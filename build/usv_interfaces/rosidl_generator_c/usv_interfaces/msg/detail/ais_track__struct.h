// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ship_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/AISTrack in the package usv_interfaces.
typedef struct usv_interfaces__msg__AISTrack
{
  /// 船舶唯一识别码（Maritime Mobile Service Identity）
  uint32_t mmsi;
  /// 船名
  rosidl_runtime_c__String ship_name;
  /// 解算后的相对本船 X 坐标（米）
  double relative_x;
  /// 解算后的相对本船 Y 坐标（米）
  double relative_y;
  /// 相对速度矢量 X（米/秒）
  double relative_v_x;
  /// 相对速度矢量 Y（米/秒）
  double relative_v_y;
  /// 真实艏向角（弧度）
  double true_heading;
} usv_interfaces__msg__AISTrack;

// Struct for a sequence of usv_interfaces__msg__AISTrack.
typedef struct usv_interfaces__msg__AISTrack__Sequence
{
  usv_interfaces__msg__AISTrack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__AISTrack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_H_
