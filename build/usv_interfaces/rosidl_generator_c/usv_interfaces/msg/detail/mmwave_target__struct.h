// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'radar_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MmwaveTarget in the package usv_interfaces.
typedef struct usv_interfaces__msg__MmwaveTarget
{
  /// 雷达实例标识（如 front/right/port），区分不同 mmWave 设备
  rosidl_runtime_c__String radar_id;
  /// 纵向位置 (m, VCS)
  double x;
  /// 横向位置 (m, VCS)
  double y;
  /// 纵向速度 (m/s)
  double v_x;
  /// 横向速度 (m/s)
  double v_y;
  /// 包围盒宽度/横向尺寸 (m)
  double size_w;
  /// 包围盒长度/纵向尺寸 (m)
  double size_l;
  /// 包围盒高度 (m)
  double size_h;
  /// 动静状态: 0 静止, 1 运动
  uint8_t objmotion_status;
  /// 航迹 ID
  uint32_t track_id;
} usv_interfaces__msg__MmwaveTarget;

// Struct for a sequence of usv_interfaces__msg__MmwaveTarget.
typedef struct usv_interfaces__msg__MmwaveTarget__Sequence
{
  usv_interfaces__msg__MmwaveTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__MmwaveTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_H_
