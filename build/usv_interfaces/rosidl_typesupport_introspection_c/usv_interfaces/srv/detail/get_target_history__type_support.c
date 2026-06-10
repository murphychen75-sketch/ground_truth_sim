// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "usv_interfaces/srv/detail/get_target_history__rosidl_typesupport_introspection_c.h"
#include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "usv_interfaces/srv/detail/get_target_history__functions.h"
#include "usv_interfaces/srv/detail/get_target_history__struct.h"


// Include directives for member types
// Member `target_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `target_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `t_start`
// Member `t_end`
#include "builtin_interfaces/msg/time.h"
// Member `t_start`
// Member `t_end`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__srv__GetTargetHistory_Request__init(message_memory);
}

void usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_fini_function(void * message_memory)
{
  usv_interfaces__srv__GetTargetHistory_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_member_array[4] = {
  {
    "target_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Request, target_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "t_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Request, t_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "t_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Request, t_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_samples",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Request, max_samples),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_members = {
  "usv_interfaces__srv",  // message namespace
  "GetTargetHistory_Request",  // message name
  4,  // number of fields
  sizeof(usv_interfaces__srv__GetTargetHistory_Request),
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_member_array,  // message members
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_type_support_handle = {
  0,
  &usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Request)() {
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__srv__GetTargetHistory_Request__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "usv_interfaces/srv/detail/get_target_history__rosidl_typesupport_introspection_c.h"
// already included above
// #include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "usv_interfaces/srv/detail/get_target_history__functions.h"
// already included above
// #include "usv_interfaces/srv/detail/get_target_history__struct.h"


// Include directives for member types
// Member `samples`
#include "usv_interfaces/msg/fused_track_sample.h"
// Member `samples`
#include "usv_interfaces/msg/detail/fused_track_sample__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__srv__GetTargetHistory_Response__init(message_memory);
}

void usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_fini_function(void * message_memory)
{
  usv_interfaces__srv__GetTargetHistory_Response__fini(message_memory);
}

size_t usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__size_function__GetTargetHistory_Response__samples(
  const void * untyped_member)
{
  const usv_interfaces__msg__FusedTrackSample__Sequence * member =
    (const usv_interfaces__msg__FusedTrackSample__Sequence *)(untyped_member);
  return member->size;
}

const void * usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_const_function__GetTargetHistory_Response__samples(
  const void * untyped_member, size_t index)
{
  const usv_interfaces__msg__FusedTrackSample__Sequence * member =
    (const usv_interfaces__msg__FusedTrackSample__Sequence *)(untyped_member);
  return &member->data[index];
}

void * usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_function__GetTargetHistory_Response__samples(
  void * untyped_member, size_t index)
{
  usv_interfaces__msg__FusedTrackSample__Sequence * member =
    (usv_interfaces__msg__FusedTrackSample__Sequence *)(untyped_member);
  return &member->data[index];
}

void usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__fetch_function__GetTargetHistory_Response__samples(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const usv_interfaces__msg__FusedTrackSample * item =
    ((const usv_interfaces__msg__FusedTrackSample *)
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_const_function__GetTargetHistory_Response__samples(untyped_member, index));
  usv_interfaces__msg__FusedTrackSample * value =
    (usv_interfaces__msg__FusedTrackSample *)(untyped_value);
  *value = *item;
}

void usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__assign_function__GetTargetHistory_Response__samples(
  void * untyped_member, size_t index, const void * untyped_value)
{
  usv_interfaces__msg__FusedTrackSample * item =
    ((usv_interfaces__msg__FusedTrackSample *)
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_function__GetTargetHistory_Response__samples(untyped_member, index));
  const usv_interfaces__msg__FusedTrackSample * value =
    (const usv_interfaces__msg__FusedTrackSample *)(untyped_value);
  *item = *value;
}

bool usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__resize_function__GetTargetHistory_Response__samples(
  void * untyped_member, size_t size)
{
  usv_interfaces__msg__FusedTrackSample__Sequence * member =
    (usv_interfaces__msg__FusedTrackSample__Sequence *)(untyped_member);
  usv_interfaces__msg__FusedTrackSample__Sequence__fini(member);
  return usv_interfaces__msg__FusedTrackSample__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "samples",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__srv__GetTargetHistory_Response, samples),  // bytes offset in struct
    NULL,  // default value
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__size_function__GetTargetHistory_Response__samples,  // size() function pointer
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_const_function__GetTargetHistory_Response__samples,  // get_const(index) function pointer
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__get_function__GetTargetHistory_Response__samples,  // get(index) function pointer
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__fetch_function__GetTargetHistory_Response__samples,  // fetch(index, &value) function pointer
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__assign_function__GetTargetHistory_Response__samples,  // assign(index, value) function pointer
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__resize_function__GetTargetHistory_Response__samples  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_members = {
  "usv_interfaces__srv",  // message namespace
  "GetTargetHistory_Response",  // message name
  2,  // number of fields
  sizeof(usv_interfaces__srv__GetTargetHistory_Response),
  usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_member_array,  // message members
  usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_type_support_handle = {
  0,
  &usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Response)() {
  usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, FusedTrackSample)();
  if (!usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__srv__GetTargetHistory_Response__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "usv_interfaces/srv/detail/get_target_history__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_members = {
  "usv_interfaces__srv",  // service namespace
  "GetTargetHistory",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_Request_message_type_support_handle,
  NULL  // response message
  // usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_Response_message_type_support_handle
};

static rosidl_service_type_support_t usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_type_support_handle = {
  0,
  &usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory)() {
  if (!usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_type_support_handle.typesupport_identifier) {
    usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, srv, GetTargetHistory_Response)()->data;
  }

  return &usv_interfaces__srv__detail__get_target_history__rosidl_typesupport_introspection_c__GetTargetHistory_service_type_support_handle;
}
