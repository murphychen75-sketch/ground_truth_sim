// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GlobalTrack in the package usv_interfaces.
typedef struct usv_interfaces__msg__GlobalTrack
{
  /// 融合中心分配的全局唯一 ID
  uint32_t track_id;
  /// 融合后的平滑相对坐标 X（米）
  double x;
  /// 融合后的平滑相对坐标 Y（米）
  double y;
  /// 融合后的平滑速度 X（米/秒）
  double v_x;
  /// 融合后的平滑速度 Y（米/秒）
  double v_y;
  /// 综合估算的 3D 尺寸——宽（米）
  double size_w;
  /// 综合估算的 3D 尺寸——长（米）
  double size_l;
  /// 综合估算的 3D 尺寸——高（米）
  double size_h;
  /// 4x4 协方差矩阵（按 x, y, v_x, v_y 顺序）
  double covariance[16];
  /// 是否为未匹配 AIS 的暗目标/可疑船只
  bool is_dark_target;
  /// 是否已经绑定 AIS 轨迹
  bool is_ais_matched;
  /// 若绑定成功，对应的 AIS MMSI
  uint32_t matched_mmsi;
} usv_interfaces__msg__GlobalTrack;

// Struct for a sequence of usv_interfaces__msg__GlobalTrack.
typedef struct usv_interfaces__msg__GlobalTrack__Sequence
{
  usv_interfaces__msg__GlobalTrack * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__GlobalTrack__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_H_
