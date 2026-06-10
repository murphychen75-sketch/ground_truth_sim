// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:msg/OperationMode.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_H_
#define USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'MODE_MANUAL'.
/**
  * 手动遥控
 */
enum
{
  usv_interfaces__msg__OperationMode__MODE_MANUAL = 0
};

/// Constant 'MODE_AUTO_HEADING'.
/**
  * 自动航向/巡线
 */
enum
{
  usv_interfaces__msg__OperationMode__MODE_AUTO_HEADING = 1
};

/// Constant 'MODE_SMART_PATH'.
/**
  * 智能避障巡线
 */
enum
{
  usv_interfaces__msg__OperationMode__MODE_SMART_PATH = 2
};

/// Constant 'MODE_AUTO_NAV'.
/**
  * 自主点对点导航
 */
enum
{
  usv_interfaces__msg__OperationMode__MODE_AUTO_NAV = 3
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/OperationMode in the package usv_interfaces.
typedef struct usv_interfaces__msg__OperationMode
{
  std_msgs__msg__Header header;
  /// 当前模式
  uint8_t mode;
} usv_interfaces__msg__OperationMode;

// Struct for a sequence of usv_interfaces__msg__OperationMode.
typedef struct usv_interfaces__msg__OperationMode__Sequence
{
  usv_interfaces__msg__OperationMode * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__msg__OperationMode__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_H_
