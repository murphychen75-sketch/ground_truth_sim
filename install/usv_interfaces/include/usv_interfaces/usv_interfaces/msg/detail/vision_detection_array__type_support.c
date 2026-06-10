// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from usv_interfaces:msg/VisionDetectionArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "usv_interfaces/msg/detail/vision_detection_array__rosidl_typesupport_introspection_c.h"
#include "usv_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "usv_interfaces/msg/detail/vision_detection_array__functions.h"
#include "usv_interfaces/msg/detail/vision_detection_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `output_stamp`
#include "builtin_interfaces/msg/time.h"
// Member `output_stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `detections`
#include "usv_interfaces/msg/vision_detection.h"
// Member `detections`
#include "usv_interfaces/msg/detail/vision_detection__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  usv_interfaces__msg__VisionDetectionArray__init(message_memory);
}

void usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_fini_function(void * message_memory)
{
  usv_interfaces__msg__VisionDetectionArray__fini(message_memory);
}

size_t usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__size_function__VisionDetectionArray__detections(
  const void * untyped_member)
{
  const usv_interfaces__msg__VisionDetection__Sequence * member =
    (const usv_interfaces__msg__VisionDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_const_function__VisionDetectionArray__detections(
  const void * untyped_member, size_t index)
{
  const usv_interfaces__msg__VisionDetection__Sequence * member =
    (const usv_interfaces__msg__VisionDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_function__VisionDetectionArray__detections(
  void * untyped_member, size_t index)
{
  usv_interfaces__msg__VisionDetection__Sequence * member =
    (usv_interfaces__msg__VisionDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__fetch_function__VisionDetectionArray__detections(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const usv_interfaces__msg__VisionDetection * item =
    ((const usv_interfaces__msg__VisionDetection *)
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_const_function__VisionDetectionArray__detections(untyped_member, index));
  usv_interfaces__msg__VisionDetection * value =
    (usv_interfaces__msg__VisionDetection *)(untyped_value);
  *value = *item;
}

void usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__assign_function__VisionDetectionArray__detections(
  void * untyped_member, size_t index, const void * untyped_value)
{
  usv_interfaces__msg__VisionDetection * item =
    ((usv_interfaces__msg__VisionDetection *)
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_function__VisionDetectionArray__detections(untyped_member, index));
  const usv_interfaces__msg__VisionDetection * value =
    (const usv_interfaces__msg__VisionDetection *)(untyped_value);
  *item = *value;
}

bool usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__resize_function__VisionDetectionArray__detections(
  void * untyped_member, size_t size)
{
  usv_interfaces__msg__VisionDetection__Sequence * member =
    (usv_interfaces__msg__VisionDetection__Sequence *)(untyped_member);
  usv_interfaces__msg__VisionDetection__Sequence__fini(member);
  return usv_interfaces__msg__VisionDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__VisionDetectionArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "output_stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__VisionDetectionArray, output_stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detections",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces__msg__VisionDetectionArray, detections),  // bytes offset in struct
    NULL,  // default value
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__size_function__VisionDetectionArray__detections,  // size() function pointer
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_const_function__VisionDetectionArray__detections,  // get_const(index) function pointer
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__get_function__VisionDetectionArray__detections,  // get(index) function pointer
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__fetch_function__VisionDetectionArray__detections,  // fetch(index, &value) function pointer
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__assign_function__VisionDetectionArray__detections,  // assign(index, value) function pointer
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__resize_function__VisionDetectionArray__detections  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_members = {
  "usv_interfaces__msg",  // message namespace
  "VisionDetectionArray",  // message name
  3,  // number of fields
  sizeof(usv_interfaces__msg__VisionDetectionArray),
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_member_array,  // message members
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_type_support_handle = {
  0,
  &usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, VisionDetectionArray)() {
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, usv_interfaces, msg, VisionDetection)();
  if (!usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_type_support_handle.typesupport_identifier) {
    usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &usv_interfaces__msg__VisionDetectionArray__rosidl_typesupport_introspection_c__VisionDetectionArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
