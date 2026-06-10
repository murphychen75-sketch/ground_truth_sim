// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/FusedTargetProfile.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_H_

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
// Member 'class_name'
#include "rosidl_runtime_c/string.h"
// Member 'first_seen'
// Member 'last_profile_update'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FusedTargetProfile in the package usv_interfaces.
/**
  * Slow-changing target attributes (catalog / archive).
 */
typedef struct usv_interfaces__msg__FusedTargetProfile
{
  unique_identifier_msgs__msg__UUID target_id;
  double size_w;
  double size_l;
  double size_h;
  int32_t class_id;
  rosidl_runtime_c__String class_name;
  /// 近 N 帧类别投票占比 [0,1]
  double class_confidence;
  bool is_dark_target;
  bool is_ais_matched;
  uint32_t matched_mmsi;
  builtin_interfaces__msg__Time first_seen;
  builtin_interfaces__msg__Time last_profile_update;
} usv_interfaces__msg__FusedTargetProfile;

// Struct for a sequence of usv_interfaces__msg__FusedTargetProfile.
typedef struct usv_interfaces__msg__FusedTargetProfile__Sequence
{
  usv_interfaces__msg__FusedTargetProfile * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__FusedTargetProfile__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_H_
