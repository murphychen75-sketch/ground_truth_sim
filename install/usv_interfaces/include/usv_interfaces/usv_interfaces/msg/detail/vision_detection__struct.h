// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/VisionDetection.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'camera_id'
// Member 'class_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/VisionDetection in the package usv_interfaces.
typedef struct usv_interfaces__msg__VisionDetection
{
  /// 摄像头标识（如 "front"/"left"/"right"），单个摄像头覆盖 90° 视场
  rosidl_runtime_c__String camera_id;
  /// 目标类别名称
  rosidl_runtime_c__String class_name;
  /// 目标类别 ID（与 class_name 对应的数值标签）
  int32_t class_id;
  /// 目标相对该摄像头光心的水平方位角（弧度）
  double azimuth;
  /// 单目预测的相对直线距离（米）
  double distance_predict;
  /// 预测的可见横向宽度（米，沿相机水平视场方向）
  double size_w;
  /// 预测的可见高度（米）
  double size_h;
  /// 检测框水平像素宽度（px），融合匹配用
  double pixel_width;
  /// 检测置信度（0~1），融合节点按距离动态调节协方差
  double confidence;
} usv_interfaces__msg__VisionDetection;

// Struct for a sequence of usv_interfaces__msg__VisionDetection.
typedef struct usv_interfaces__msg__VisionDetection__Sequence
{
  usv_interfaces__msg__VisionDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__VisionDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_H_
