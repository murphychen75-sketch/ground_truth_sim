// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'state'
#include "usv_interfaces/msg/detail/fused_track_sample__struct.h"

/// Struct defined in msg/FusedTargetSnapshot in the package usv_interfaces.
/**
  * One fused target at the current fusion cycle (high-rate snapshot row).
 */
typedef struct usv_interfaces__msg__FusedTargetSnapshot
{
  unique_identifier_msgs__msg__UUID target_id;
  usv_interfaces__msg__FusedTrackSample state;
  double size_w;
  double size_l;
  double size_h;
  bool is_dark_target;
  bool is_ais_matched;
  uint32_t matched_mmsi;
} usv_interfaces__msg__FusedTargetSnapshot;

// Struct for a sequence of usv_interfaces__msg__FusedTargetSnapshot.
typedef struct usv_interfaces__msg__FusedTargetSnapshot__Sequence
{
  usv_interfaces__msg__FusedTargetSnapshot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__FusedTargetSnapshot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_H_
