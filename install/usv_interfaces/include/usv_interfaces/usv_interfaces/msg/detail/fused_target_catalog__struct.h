// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/FusedTargetCatalog.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__STRUCT_H_

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
// Member 'profiles'
#include "usv_interfaces/msg/detail/fused_target_profile__struct.h"

/// Struct defined in msg/FusedTargetCatalog in the package usv_interfaces.
typedef struct usv_interfaces__msg__FusedTargetCatalog
{
  std_msgs__msg__Header header;
  usv_interfaces__msg__FusedTargetProfile__Sequence profiles;
} usv_interfaces__msg__FusedTargetCatalog;

// Struct for a sequence of usv_interfaces__msg__FusedTargetCatalog.
typedef struct usv_interfaces__msg__FusedTargetCatalog__Sequence
{
  usv_interfaces__msg__FusedTargetCatalog * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__FusedTargetCatalog__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__STRUCT_H_
