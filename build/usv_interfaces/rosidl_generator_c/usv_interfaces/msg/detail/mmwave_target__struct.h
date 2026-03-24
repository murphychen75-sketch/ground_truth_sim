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
  /// 聚类中心相对坐标 X（米）
  double x;
  /// 聚类中心相对坐标 Y（米）
  double y;
  /// 目标速度矢量 X（米/秒），可为绝对或相对速度
  double v_x;
  /// 目标速度矢量 Y（米/秒）
  double v_y;
  /// 点云聚类估算宽度（米）
  double size_w;
  /// 点云聚类估算长度（米）
  double size_l;
  /// 点云聚类估算高度（米，仅用于高度分类，不参与 EKF 追踪）
  double size_h;
  /// 信噪比，融合节点依此调节尺寸置信度
  double snr;
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
