// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/GlobalTrackArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__STRUCT_H_

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
// Member 'tracks'
#include "usv_interfaces/msg/detail/global_track__struct.h"

/// Struct defined in msg/GlobalTrackArray in the package usv_interfaces.
typedef struct usv_interfaces__msg__GlobalTrackArray
{
  /// 融合输出时间戳（base_link 坐标系）
  std_msgs__msg__Header header;
  /// 同一时间内的全局轨迹列表
  usv_interfaces__msg__GlobalTrack__Sequence tracks;
} usv_interfaces__msg__GlobalTrackArray;

// Struct for a sequence of usv_interfaces__msg__GlobalTrackArray.
typedef struct usv_interfaces__msg__GlobalTrackArray__Sequence
{
  usv_interfaces__msg__GlobalTrackArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__GlobalTrackArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__STRUCT_H_
