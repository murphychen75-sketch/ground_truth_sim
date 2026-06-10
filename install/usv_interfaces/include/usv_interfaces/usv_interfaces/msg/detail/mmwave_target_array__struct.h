// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/MmwaveTargetArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__STRUCT_H_

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
#include "usv_interfaces/msg/detail/mmwave_target__struct.h"

/// Struct defined in msg/MmwaveTargetArray in the package usv_interfaces.
typedef struct usv_interfaces__msg__MmwaveTargetArray
{
  /// 毫米波雷达的时间戳与坐标系
  std_msgs__msg__Header header;
  /// 同步输出的所有 4D 雷达目标
  usv_interfaces__msg__MmwaveTarget__Sequence targets;
} usv_interfaces__msg__MmwaveTargetArray;

// Struct for a sequence of usv_interfaces__msg__MmwaveTargetArray.
typedef struct usv_interfaces__msg__MmwaveTargetArray__Sequence
{
  usv_interfaces__msg__MmwaveTargetArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__MmwaveTargetArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__STRUCT_H_
