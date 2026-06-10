// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/NavRadarTargetArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__STRUCT_H_

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
#include "usv_interfaces/msg/detail/nav_radar_target__struct.h"

/// Struct defined in msg/NavRadarTargetArray in the package usv_interfaces.
typedef struct usv_interfaces__msg__NavRadarTargetArray
{
  /// 导航雷达坐标系与时间戳
  std_msgs__msg__Header header;
  /// 扫描周期内的雷达目标数组
  usv_interfaces__msg__NavRadarTarget__Sequence targets;
} usv_interfaces__msg__NavRadarTargetArray;

// Struct for a sequence of usv_interfaces__msg__NavRadarTargetArray.
typedef struct usv_interfaces__msg__NavRadarTargetArray__Sequence
{
  usv_interfaces__msg__NavRadarTargetArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__NavRadarTargetArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__STRUCT_H_
