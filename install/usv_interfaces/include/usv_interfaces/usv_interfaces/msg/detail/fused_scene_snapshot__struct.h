// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/FusedSceneSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_H_

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
// Member 'targets'
#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.h"

/// Struct defined in msg/FusedSceneSnapshot in the package usv_interfaces.
typedef struct usv_interfaces__msg__FusedSceneSnapshot
{
  std_msgs__msg__Header header;
  usv_interfaces__msg__FusedTargetSnapshot__Sequence targets;
} usv_interfaces__msg__FusedSceneSnapshot;

// Struct for a sequence of usv_interfaces__msg__FusedSceneSnapshot.
typedef struct usv_interfaces__msg__FusedSceneSnapshot__Sequence
{
  usv_interfaces__msg__FusedSceneSnapshot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__FusedSceneSnapshot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_H_
