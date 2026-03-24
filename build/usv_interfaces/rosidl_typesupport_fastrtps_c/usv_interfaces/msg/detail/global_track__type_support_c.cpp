// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/global_track__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "usv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "usv_interfaces/msg/detail/global_track__struct.h"
#include "usv_interfaces/msg/detail/global_track__functions.h"
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


// forward declare type support functions


using _GlobalTrack__ros_msg_type = usv_interfaces__msg__GlobalTrack;

static bool _GlobalTrack__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _GlobalTrack__ros_msg_type * ros_message = static_cast<const _GlobalTrack__ros_msg_type *>(untyped_ros_message);
  // Field name: track_id
  {
    cdr << ros_message->track_id;
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

  // Field name: covariance
  {
    size_t size = 16;
    auto array_ptr = ros_message->covariance;
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: is_dark_target
  {
    cdr << (ros_message->is_dark_target ? true : false);
  }

  // Field name: is_ais_matched
  {
    cdr << (ros_message->is_ais_matched ? true : false);
  }

  // Field name: matched_mmsi
  {
    cdr << ros_message->matched_mmsi;
  }

  return true;
}

static bool _GlobalTrack__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _GlobalTrack__ros_msg_type * ros_message = static_cast<_GlobalTrack__ros_msg_type *>(untyped_ros_message);
  // Field name: track_id
  {
    cdr >> ros_message->track_id;
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

  // Field name: covariance
  {
    size_t size = 16;
    auto array_ptr = ros_message->covariance;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: is_dark_target
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_dark_target = tmp ? true : false;
  }

  // Field name: is_ais_matched
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_ais_matched = tmp ? true : false;
  }

  // Field name: matched_mmsi
  {
    cdr >> ros_message->matched_mmsi;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t get_serialized_size_usv_interfaces__msg__GlobalTrack(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _GlobalTrack__ros_msg_type * ros_message = static_cast<const _GlobalTrack__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name track_id
  {
    size_t item_size = sizeof(ros_message->track_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
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
  // field.name covariance
  {
    size_t array_size = 16;
    auto array_ptr = ros_message->covariance;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_dark_target
  {
    size_t item_size = sizeof(ros_message->is_dark_target);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_ais_matched
  {
    size_t item_size = sizeof(ros_message->is_ais_matched);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name matched_mmsi
  {
    size_t item_size = sizeof(ros_message->matched_mmsi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GlobalTrack__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_usv_interfaces__msg__GlobalTrack(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t max_serialized_size_usv_interfaces__msg__GlobalTrack(
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

  // member: track_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
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
  // member: covariance
  {
    size_t array_size = 16;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: is_dark_target
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: is_ais_matched
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: matched_mmsi
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
    using DataType = usv_interfaces__msg__GlobalTrack;
    is_plain =
      (
      offsetof(DataType, matched_mmsi) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _GlobalTrack__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_usv_interfaces__msg__GlobalTrack(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_GlobalTrack = {
  "usv_interfaces::msg",
  "GlobalTrack",
  _GlobalTrack__cdr_serialize,
  _GlobalTrack__cdr_deserialize,
  _GlobalTrack__get_serialized_size,
  _GlobalTrack__max_serialized_size
};

static rosidl_message_type_support_t _GlobalTrack__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_GlobalTrack,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, usv_interfaces, msg, GlobalTrack)() {
  return &_GlobalTrack__type_support;
}

#if defined(__cplusplus)
}
#endif
