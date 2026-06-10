// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/mmwave_target__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "usv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "usv_interfaces/msg/detail/mmwave_target__struct.h"
#include "usv_interfaces/msg/detail/mmwave_target__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // radar_id
#include "rosidl_runtime_c/string_functions.h"  // radar_id

// forward declare type support functions


using _MmwaveTarget__ros_msg_type = usv_interfaces__msg__MmwaveTarget;

static bool _MmwaveTarget__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MmwaveTarget__ros_msg_type * ros_message = static_cast<const _MmwaveTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: radar_id
  {
    const rosidl_runtime_c__String * str = &ros_message->radar_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: x
  {
    cdr << ros_message->x;
  }

  // Field name: y
  {
    cdr << ros_message->y;
  }

  // Field name: v_x
  {
    cdr << ros_message->v_x;
  }

  // Field name: v_y
  {
    cdr << ros_message->v_y;
  }

  // Field name: size_w
  {
    cdr << ros_message->size_w;
  }

  // Field name: size_l
  {
    cdr << ros_message->size_l;
  }

  // Field name: size_h
  {
    cdr << ros_message->size_h;
  }

  // Field name: objmotion_status
  {
    cdr << ros_message->objmotion_status;
  }

  // Field name: track_id
  {
    cdr << ros_message->track_id;
  }

  return true;
}

static bool _MmwaveTarget__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MmwaveTarget__ros_msg_type * ros_message = static_cast<_MmwaveTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: radar_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->radar_id.data) {
      rosidl_runtime_c__String__init(&ros_message->radar_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->radar_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'radar_id'\n");
      return false;
    }
  }

  // Field name: x
  {
    cdr >> ros_message->x;
  }

  // Field name: y
  {
    cdr >> ros_message->y;
  }

  // Field name: v_x
  {
    cdr >> ros_message->v_x;
  }

  // Field name: v_y
  {
    cdr >> ros_message->v_y;
  }

  // Field name: size_w
  {
    cdr >> ros_message->size_w;
  }

  // Field name: size_l
  {
    cdr >> ros_message->size_l;
  }

  // Field name: size_h
  {
    cdr >> ros_message->size_h;
  }

  // Field name: objmotion_status
  {
    cdr >> ros_message->objmotion_status;
  }

  // Field name: track_id
  {
    cdr >> ros_message->track_id;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t get_serialized_size_usv_interfaces__msg__MmwaveTarget(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MmwaveTarget__ros_msg_type * ros_message = static_cast<const _MmwaveTarget__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name radar_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->radar_id.size + 1);
  // field.name x
  {
    size_t item_size = sizeof(ros_message->x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y
  {
    size_t item_size = sizeof(ros_message->y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_x
  {
    size_t item_size = sizeof(ros_message->v_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_y
  {
    size_t item_size = sizeof(ros_message->v_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name size_w
  {
    size_t item_size = sizeof(ros_message->size_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name size_l
  {
    size_t item_size = sizeof(ros_message->size_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name size_h
  {
    size_t item_size = sizeof(ros_message->size_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name objmotion_status
  {
    size_t item_size = sizeof(ros_message->objmotion_status);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name track_id
  {
    size_t item_size = sizeof(ros_message->track_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MmwaveTarget__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_usv_interfaces__msg__MmwaveTarget(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t max_serialized_size_usv_interfaces__msg__MmwaveTarget(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: radar_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: size_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: size_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: size_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: objmotion_status
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: track_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = usv_interfaces__msg__MmwaveTarget;
    is_plain =
      (
      offsetof(DataType, track_id) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _MmwaveTarget__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_usv_interfaces__msg__MmwaveTarget(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MmwaveTarget = {
  "usv_interfaces::msg",
  "MmwaveTarget",
  _MmwaveTarget__cdr_serialize,
  _MmwaveTarget__cdr_deserialize,
  _MmwaveTarget__get_serialized_size,
  _MmwaveTarget__max_serialized_size
};

static rosidl_message_type_support_t _MmwaveTarget__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MmwaveTarget,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, usv_interfaces, msg, MmwaveTarget)() {
  return &_MmwaveTarget__type_support;
}

#if defined(__cplusplus)
}
#endif
