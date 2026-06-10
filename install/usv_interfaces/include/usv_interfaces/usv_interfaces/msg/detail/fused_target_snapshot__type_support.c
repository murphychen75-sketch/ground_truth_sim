// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "usv_interfaces/msg/detail/fused_target_snapshot__rosidl_typesupport_introspection_c.h"
#include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "usv_interfaces/msg/detail/fused_target_snapshot__functions.h"
#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.h"


// Include directives for member types
// Member `target_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `target_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `state`
#include "usv_interfaces/msg/fused_track_sample.h"
// Member `state`
#include "usv_interfaces/msg/detail/fused_track_sample__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__msg__FusedTargetSnapshot__init(message_memory);
}

void usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_fini_function(void * message_memory)
{
  usv_interfaces__msg__FusedTargetSnapshot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_member_array[8] = {
  {
    "target_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, target_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size_w",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, size_w),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size_l",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, size_l),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size_h",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, size_h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_dark_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, is_dark_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "is_ais_matched",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, is_ais_matched),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "matched_mmsi",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTargetSnapshot, matched_mmsi),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_members = {
  "usv_interfaces__msg",  // message namespace
  "FusedTargetSnapshot",  // message name
  8,  // number of fields
  sizeof(usv_interfaces__msg__FusedTargetSnapshot),
  usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_member_array,  // message members
  usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_type_support_handle = {
  0,
  &usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, FusedTargetSnapshot)() {
  usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, FusedTrackSample)();
  if (!usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__msg__FusedTargetSnapshot__rosidl_typesupport_introspection_c__FusedTargetSnapshot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
