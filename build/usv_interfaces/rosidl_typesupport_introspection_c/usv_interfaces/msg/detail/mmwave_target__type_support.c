// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "usv_interfaces/msg/detail/mmwave_target__rosidl_typesupport_introspection_c.h"
#include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "usv_interfaces/msg/detail/mmwave_target__functions.h"
#include "usv_interfaces/msg/detail/mmwave_target__struct.h"


// Include directives for member types
// Member `radar_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__msg__MmwaveTarget__init(message_memory);
}

void usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_fini_function(void * message_memory)
{
  usv_interfaces__msg__MmwaveTarget__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_member_array[9] = {
  {
    "radar_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__MmwaveTarget, radar_id),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, x),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, y),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, v_x),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, v_y),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, size_w),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, size_l),  // bytes offset in struct
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
    offsetof(usv_interfaces__msg__MmwaveTarget, size_h),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "snr",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__MmwaveTarget, snr),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_members = {
  "usv_interfaces__msg",  // message namespace
  "MmwaveTarget",  // message name
  9,  // number of fields
  sizeof(usv_interfaces__msg__MmwaveTarget),
  usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_member_array,  // message members
  usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_type_support_handle = {
  0,
  &usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, MmwaveTarget)() {
  if (!usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__msg__MmwaveTarget__rosidl_typesupport_introspection_c__MmwaveTarget_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
