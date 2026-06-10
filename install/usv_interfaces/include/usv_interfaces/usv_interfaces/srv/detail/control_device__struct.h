// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:srv/ControlDevice.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_H_
#define USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'device_id'
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ControlDevice in the package usv_interfaces.
typedef struct usv_interfaces__srv__ControlDevice_Request
{
  /// 设备ID (例如: "nav_light_left", "sampler_pump")
  rosidl_runtime_c__String device_id;
  /// 指令 (例如: "ON", "OFF", "SET_LEVEL")
  rosidl_runtime_c__String command;
  /// 数值 (例如: 亮度 0-100)
  float value;
} usv_interfaces__srv__ControlDevice_Request;

// Struct for a sequence of usv_interfaces__srv__ControlDevice_Request.
typedef struct usv_interfaces__srv__ControlDevice_Request__Sequence
{
  usv_interfaces__srv__ControlDevice_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__srv__ControlDevice_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ControlDevice in the package usv_interfaces.
typedef struct usv_interfaces__srv__ControlDevice_Response
{
  /// 执行是否成功
  bool success;
  /// 错误信息或执行结果描述
  rosidl_runtime_c__String message;
} usv_interfaces__srv__ControlDevice_Response;

// Struct for a sequence of usv_interfaces__srv__ControlDevice_Response.
typedef struct usv_interfaces__srv__ControlDevice_Response__Sequence
{
  usv_interfaces__srv__ControlDevice_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__srv__ControlDevice_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_H_
