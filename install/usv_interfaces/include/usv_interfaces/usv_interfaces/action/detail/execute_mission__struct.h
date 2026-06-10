// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
#define USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission_file_name'
// Member 'forbidden_zone_file'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_Goal
{
  /// 任务航点文件路径/名称
  rosidl_runtime_c__String mission_file_name;
  /// 禁航区描述文件路径/名称
  rosidl_runtime_c__String forbidden_zone_file;
  /// 是否循环执行
  bool loop_execution;
} usv_interfaces__action__ExecuteMission_Goal;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_Goal.
typedef struct usv_interfaces__action__ExecuteMission_Goal__Sequence
{
  usv_interfaces__action__ExecuteMission_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_Result
{
  bool success;
  /// 比如 "Mission Complete"
  rosidl_runtime_c__String message;
} usv_interfaces__action__ExecuteMission_Result;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_Result.
typedef struct usv_interfaces__action__ExecuteMission_Result__Sequence
{
  usv_interfaces__action__ExecuteMission_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'current_task_name'
// Member 'status_text'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_Feedback
{
  /// 当前阶段名称
  rosidl_runtime_c__String current_task_name;
  /// 当前目标索引
  uint32_t current_waypoint_index;
  /// 总进度 %
  float mission_progress;
  /// 状态机描述
  rosidl_runtime_c__String status_text;
} usv_interfaces__action__ExecuteMission_Feedback;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_Feedback.
typedef struct usv_interfaces__action__ExecuteMission_Feedback__Sequence
{
  usv_interfaces__action__ExecuteMission_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "usv_interfaces/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  usv_interfaces__action__ExecuteMission_Goal goal;
} usv_interfaces__action__ExecuteMission_SendGoal_Request;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_SendGoal_Request.
typedef struct usv_interfaces__action__ExecuteMission_SendGoal_Request__Sequence
{
  usv_interfaces__action__ExecuteMission_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} usv_interfaces__action__ExecuteMission_SendGoal_Response;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_SendGoal_Response.
typedef struct usv_interfaces__action__ExecuteMission_SendGoal_Response__Sequence
{
  usv_interfaces__action__ExecuteMission_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} usv_interfaces__action__ExecuteMission_GetResult_Request;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_GetResult_Request.
typedef struct usv_interfaces__action__ExecuteMission_GetResult_Request__Sequence
{
  usv_interfaces__action__ExecuteMission_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "usv_interfaces/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_GetResult_Response
{
  int8_t status;
  usv_interfaces__action__ExecuteMission_Result result;
} usv_interfaces__action__ExecuteMission_GetResult_Response;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_GetResult_Response.
typedef struct usv_interfaces__action__ExecuteMission_GetResult_Response__Sequence
{
  usv_interfaces__action__ExecuteMission_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "usv_interfaces/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package usv_interfaces.
typedef struct usv_interfaces__action__ExecuteMission_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  usv_interfaces__action__ExecuteMission_Feedback feedback;
} usv_interfaces__action__ExecuteMission_FeedbackMessage;

// Struct for a sequence of usv_interfaces__action__ExecuteMission_FeedbackMessage.
typedef struct usv_interfaces__action__ExecuteMission_FeedbackMessage__Sequence
{
  usv_interfaces__action__ExecuteMission_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__action__ExecuteMission_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
