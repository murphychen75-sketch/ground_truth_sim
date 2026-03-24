// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/ais_track__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "usv_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "usv_interfaces/msg/detail/ais_track__struct.h"
#include "usv_interfaces/msg/detail/ais_track__functions.h"
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

#include "rosidl_runtime_c/string.h"  // ship_name
#include "rosidl_runtime_c/string_functions.h"  // ship_name

// forward declare type support functions


using _AISTrack__ros_msg_type = usv_interfaces__msg__AISTrack;

static bool _AISTrack__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _AISTrack__ros_msg_type * ros_message = static_cast<const _AISTrack__ros_msg_type *>(untyped_ros_message);
  // Field name: mmsi
  {
    cdr << ros_message->mmsi;
  }

  // Field name: ship_name
  {
    const rosidl_runtime_c__String * str = &ros_message->ship_name;
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

  // Field name: relative_x
  {
    cdr << ros_message->relative_x;
  }

  // Field name: relative_y
  {
    cdr << ros_message->relative_y;
  }

  // Field name: relative_v_x
  {
    cdr << ros_message->relative_v_x;
  }

  // Field name: relative_v_y
  {
    cdr << ros_message->relative_v_y;
  }

  // Field name: true_heading
  {
    cdr << ros_message->true_heading;
  }

  return true;
}

static bool _AISTrack__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _AISTrack__ros_msg_type * ros_message = static_cast<_AISTrack__ros_msg_type *>(untyped_ros_message);
  // Field name: mmsi
  {
    cdr >> ros_message->mmsi;
  }

  // Field name: ship_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ship_name.data) {
      rosidl_runtime_c__String__init(&ros_message->ship_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ship_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ship_name'\n");
      return false;
    }
  }

  // Field name: relative_x
  {
    cdr >> ros_message->relative_x;
  }

  // Field name: relative_y
  {
    cdr >> ros_message->relative_y;
  }

  // Field name: relative_v_x
  {
    cdr >> ros_message->relative_v_x;
  }

  // Field name: relative_v_y
  {
    cdr >> ros_message->relative_v_y;
  }

  // Field name: true_heading
  {
    cdr >> ros_message->true_heading;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t get_serialized_size_usv_interfaces__msg__AISTrack(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _AISTrack__ros_msg_type * ros_message = static_cast<const _AISTrack__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name mmsi
  {
    size_t item_size = sizeof(ros_message->mmsi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name ship_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ship_name.size + 1);
  // field.name relative_x
  {
    size_t item_size = sizeof(ros_message->relative_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name relative_y
  {
    size_t item_size = sizeof(ros_message->relative_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name relative_v_x
  {
    size_t item_size = sizeof(ros_message->relative_v_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name relative_v_y
  {
    size_t item_size = sizeof(ros_message->relative_v_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name true_heading
  {
    size_t item_size = sizeof(ros_message->true_heading);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _AISTrack__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_usv_interfaces__msg__AISTrack(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_usv_interfaces
size_t max_serialized_size_usv_interfaces__msg__AISTrack(
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

  // member: mmsi
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: ship_name
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
  // member: relative_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: relative_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: relative_v_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: relative_v_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: true_heading
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = usv_interfaces__msg__AISTrack;
    is_plain =
      (
      offsetof(DataType, true_heading) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _AISTrack__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_usv_interfaces__msg__AISTrack(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_AISTrack = {
  "usv_interfaces::msg",
  "AISTrack",
  _AISTrack__cdr_serialize,
  _AISTrack__cdr_deserialize,
  _AISTrack__get_serialized_size,
  _AISTrack__max_serialized_size
};

static rosidl_message_type_support_t _AISTrack__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_AISTrack,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, usv_interfaces, msg, AISTrack)() {
  return &_AISTrack__type_support;
}

#if defined(__cplusplus)
}
#endif
