// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/FusedTrackSample.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FusedTrackSample in the package usv_interfaces.
/**
  * Single kinematic sample (trajectory point, service response, or jsonl row).
 */
typedef struct usv_interfaces__msg__FusedTrackSample
{
  builtin_interfaces__msg__Time stamp;
  /// wall-time seconds (same instant as stamp); useful for offline tools
  double t_sec;
  double x;
  double y;
  double v_x;
  double v_y;
  /// 4x4 row-major for x, y, v_x, v_y; use zeros if unknown
  double covariance[16];
} usv_interfaces__msg__FusedTrackSample;

// Struct for a sequence of usv_interfaces__msg__FusedTrackSample.
typedef struct usv_interfaces__msg__FusedTrackSample__Sequence
{
  usv_interfaces__msg__FusedTrackSample * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__FusedTrackSample__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_H_
