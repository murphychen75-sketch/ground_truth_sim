// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/fused_target_snapshot__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "usv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.h"
#include "usv_interfaces/msg/detail/fused_target_snapshot__functions.h"
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

#include "unique_identifier_msgs/msg/detail/uuid__functions.h"  // target_id
#include "usv_interfaces/msg/detail/fused_track_sample__functions.h"  // state

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_usv_interfaces
size_t get_serialized_size_unique_identifier_msgs__msg__UUID(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_usv_interfaces
size_t max_serialized_size_unique_identifier_msgs__msg__UUID(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_usv_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID)();
size_t get_serialized_size_usv_interfaces__msg__FusedTrackSample(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_usv_interfaces__msg__FusedTrackSample(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, usv_interfaces, msg, FusedTrackSample)();


using _FusedTargetSnapshot__ros_msg_type = usv_interfaces__msg__FusedTargetSnapshot;

static bool _FusedTargetSnapshot__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _FusedTargetSnapshot__ros_msg_type * ros_message = static_cast<const _FusedTargetSnapshot__ros_msg_type *>(untyped_ros_message);
  // Field name: target_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->target_id, cdr))
    {
      return false;
    }
  }

  // Field name: state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, usv_interfaces, msg, FusedTrackSample
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->state, cdr))
    {
      return false;
    }
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

static bool _FusedTargetSnapshot__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _FusedTargetSnapshot__ros_msg_type * ros_message = static_cast<_FusedTargetSnapshot__ros_msg_type *>(untyped_ros_message);
  // Field name: target_id
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, unique_identifier_msgs, msg, UUID
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->target_id))
    {
      return false;
    }
  }

  // Field name: state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, usv_interfaces, msg, FusedTrackSample
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->state))
    {
      return false;
    }
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
size_t get_serialized_size_usv_interfaces__msg__FusedTargetSnapshot(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _FusedTargetSnapshot__ros_msg_type * ros_message = static_cast<const _FusedTargetSnapshot__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name target_id

  current_alignment += get_serialized_size_unique_identifier_msgs__msg__UUID(
    &(ros_message->target_id), current_alignment);
  // field.name state

  current_alignment += get_serialized_size_usv_interfaces__msg__FusedTrackSample(
    &(ros_message->state), current_alignment);
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

static uint32_t _FusedTargetSnapshot__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_usv_interfaces__msg__FusedTargetSnapshot(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t max_serialized_size_usv_interfaces__msg__FusedTargetSnapshot(
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

  // member: target_id
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_unique_identifier_msgs__msg__UUID(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: state
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_usv_interfaces__msg__FusedTrackSample(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
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
    using DataType = usv_interfaces__msg__FusedTargetSnapshot;
    is_plain =
      (
      offsetof(DataType, matched_mmsi) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _FusedTargetSnapshot__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_usv_interfaces__msg__FusedTargetSnapshot(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_FusedTargetSnapshot = {
  "usv_interfaces::msg",
  "FusedTargetSnapshot",
  _FusedTargetSnapshot__cdr_serialize,
  _FusedTargetSnapshot__cdr_deserialize,
  _FusedTargetSnapshot__get_serialized_size,
  _FusedTargetSnapshot__max_serialized_size
};

static rosidl_message_type_support_t _FusedTargetSnapshot__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_FusedTargetSnapshot,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, usv_interfaces, msg, FusedTargetSnapshot)() {
  return &_FusedTargetSnapshot__type_support;
}

#if defined(__cplusplus)
}
#endif
