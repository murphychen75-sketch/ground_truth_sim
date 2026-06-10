// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/VisionDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__STRUCT_H_

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
// Member 'output_stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'detections'
#include "usv_interfaces/msg/detail/vision_detection__struct.h"

/// Struct defined in msg/VisionDetectionArray in the package usv_interfaces.
/**
  * 双时间戳（语义区分）：
  * - header.stamp：与该帧对应的图像采集时刻（仿真中与输入真值 stamp 对齐）
  * - output_stamp：识别结果输出时刻（采集时刻 + 算法/流水线延迟；percision_sim 内可用随机延迟建模）
 */
typedef struct usv_interfaces__msg__VisionDetectionArray
{
  std_msgs__msg__Header header;
  builtin_interfaces__msg__Time output_stamp;
  /// 当前帧的检测列表
  usv_interfaces__msg__VisionDetection__Sequence detections;
} usv_interfaces__msg__VisionDetectionArray;

// Struct for a sequence of usv_interfaces__msg__VisionDetectionArray.
typedef struct usv_interfaces__msg__VisionDetectionArray__Sequence
{
  usv_interfaces__msg__VisionDetectionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__VisionDetectionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__STRUCT_H_
