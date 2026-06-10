// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/VesselState.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__STRUCT_H_

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
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'velocity'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in msg/VesselState in the package usv_interfaces.
typedef struct usv_interfaces__msg__VesselState
{
  std_msgs__msg__Header header;
  /// === 1. 地理位置 (来源: GPS/GNSS) ===
  /// 纬度
  double latitude;
  /// 经度
  double longitude;
  /// 海拔
  float altitude;
  /// === 2. 局部运动状态 (来源: 里程计/IMU融合) ===
  /// 包含位置(x,y,z) 和 姿态(x,y,z,w 四元数)
  geometry_msgs__msg__Pose pose;
  /// 包含线速度(vx, vy, vz) 和 角速度(wx, wy, wz)
  geometry_msgs__msg__Twist velocity;
  /// === 3. 欧拉角 (方便调试与UI显示) ===
  /// 横滚 (rad)
  float roll;
  /// 俯仰 (rad)
  float pitch;
  /// 航向 (rad)
  float yaw;
  /// === 4. 设备健康状态 ===
  /// 电池电压 (V)
  float battery_voltage;
  /// 电量 (%)
  float battery_percentage;
  /// 漏水报警 (True=漏水)
  bool leak_detected;
  /// 核心温度 (C)
  float cpu_temperature;
} usv_interfaces__msg__VesselState;

// Struct for a sequence of usv_interfaces__msg__VesselState.
typedef struct usv_interfaces__msg__VesselState__Sequence
{
  usv_interfaces__msg__VesselState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__VesselState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__STRUCT_H_
