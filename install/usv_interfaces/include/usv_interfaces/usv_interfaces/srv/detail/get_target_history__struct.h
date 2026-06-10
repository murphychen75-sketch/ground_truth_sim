// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_H_
#define USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 't_start'
// Member 't_end'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in srv/GetTargetHistory in the package usv_interfaces.
typedef struct usv_interfaces__srv__GetTargetHistory_Request
{
  unique_identifier_msgs__msg__UUID target_id;
  /// inclusive; sec and nanosec both zero => from file start
  builtin_interfaces__msg__Time t_start;
  /// inclusive; both zero => until file end
  builtin_interfaces__msg__Time t_end;
  /// 0 => no limit (use with care)
  uint32_t max_samples;
} usv_interfaces__srv__GetTargetHistory_Request;

// Struct for a sequence of usv_interfaces__srv__GetTargetHistory_Request.
typedef struct usv_interfaces__srv__GetTargetHistory_Request__Sequence
{
  usv_interfaces__srv__GetTargetHistory_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__srv__GetTargetHistory_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'samples'
#include "usv_interfaces/msg/detail/fused_track_sample__struct.h"

/// Struct defined in srv/GetTargetHistory in the package usv_interfaces.
typedef struct usv_interfaces__srv__GetTargetHistory_Response
{
  /// 0 = OK, 1 = unknown target / no file, 2 = read error
  int32_t status;
  usv_interfaces__msg__FusedTrackSample__Sequence samples;
} usv_interfaces__srv__GetTargetHistory_Response;

// Struct for a sequence of usv_interfaces__srv__GetTargetHistory_Response.
typedef struct usv_interfaces__srv__GetTargetHistory_Response__Sequence
{
  usv_interfaces__srv__GetTargetHistory_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} usv_interfaces__srv__GetTargetHistory_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_H_
