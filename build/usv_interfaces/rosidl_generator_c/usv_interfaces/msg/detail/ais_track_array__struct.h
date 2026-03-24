// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/AISTrackArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__STRUCT_H_

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
#include "usv_interfaces/msg/detail/ais_track__struct.h"

/// Struct defined in msg/AISTrackArray in the package usv_interfaces.
typedef struct usv_interfaces__msg__AISTrackArray
{
  /// AIS 报文时间戳与坐标系
  std_msgs__msg__Header header;
  /// 当前批次的 AIS 跟踪集合
  usv_interfaces__msg__AISTrack__Sequence tracks;
} usv_interfaces__msg__AISTrackArray;

// Struct for a sequence of usv_interfaces__msg__AISTrackArray.
typedef struct usv_interfaces__msg__AISTrackArray__Sequence
{
  usv_interfaces__msg__AISTrackArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__AISTrackArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__STRUCT_H_
