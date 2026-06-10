// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from usv_interfaces:msg/FusedTrackSample.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "usv_interfaces/msg/detail/fused_track_sample__rosidl_typesupport_introspection_c.h"
#include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "usv_interfaces/msg/detail/fused_track_sample__functions.h"
#include "usv_interfaces/msg/detail/fused_track_sample__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__msg__FusedTrackSample__init(message_memory);
}

void usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_fini_function(void * message_memory)
{
  usv_interfaces__msg__FusedTrackSample__fini(message_memory);
}

size_t usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__size_function__FusedTrackSample__covariance(
  const void * untyped_member)
{
  (void)untyped_member;
  return 16;
}

const void * usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_const_function__FusedTrackSample__covariance(
  const void * untyped_member, size_t index)
{
  const double * member =
    (const double *)(untyped_member);
  return &member[index];
}

void * usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_function__FusedTrackSample__covariance(
  void * untyped_member, size_t index)
{
  double * member =
    (double *)(untyped_member);
  return &member[index];
}

void usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__fetch_function__FusedTrackSample__covariance(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_const_function__FusedTrackSample__covariance(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__assign_function__FusedTrackSample__covariance(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_function__FusedTrackSample__covariance(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_member_array[7] = {
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "t_sec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, t_sec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, v_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, v_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "covariance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    16,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__FusedTrackSample, covariance),  // bytes offset in struct
    NULL,  // default value
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__size_function__FusedTrackSample__covariance,  // size() function pointer
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_const_function__FusedTrackSample__covariance,  // get_const(index) function pointer
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__get_function__FusedTrackSample__covariance,  // get(index) function pointer
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__fetch_function__FusedTrackSample__covariance,  // fetch(index, &value) function pointer
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__assign_function__FusedTrackSample__covariance,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_members = {
  "usv_interfaces__msg",  // message namespace
  "FusedTrackSample",  // message name
  7,  // number of fields
  sizeof(usv_interfaces__msg__FusedTrackSample),
  usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_member_array,  // message members
  usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_type_support_handle = {
  0,
  &usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, FusedTrackSample)() {
  usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__msg__FusedTrackSample__rosidl_typesupport_introspection_c__FusedTrackSample_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
