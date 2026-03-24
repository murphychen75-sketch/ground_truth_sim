// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/NavRadarTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/NavRadarTarget in the package usv_interfaces.
typedef struct usv_interfaces__msg__NavRadarTarget
{
  /// 相对平面坐标 X（米）
  double x;
  /// 相对平面坐标 Y（米）
  double y;
  /// 2D 速度矢量 X（米/秒）
  double v_x;
  /// 2D 速度矢量 Y（米/秒）
  double v_y;
  /// 目标 2D 投影面积估算（平方米）
  double area;
} usv_interfaces__msg__NavRadarTarget;

// Struct for a sequence of usv_interfaces__msg__NavRadarTarget.
typedef struct usv_interfaces__msg__NavRadarTarget__Sequence
{
  usv_interfaces__msg__NavRadarTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__NavRadarTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_H_
