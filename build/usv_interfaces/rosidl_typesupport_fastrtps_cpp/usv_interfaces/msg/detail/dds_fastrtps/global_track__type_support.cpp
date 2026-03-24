// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice
#include "usv_interfaces/msg/detail/global_track__rosidl_typesupport_fastrtps_cpp.hpp"
#include "usv_interfaces/msg/detail/global_track__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace usv_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_usv_interfaces
cdr_serialize(
  const usv_interfaces::msg::GlobalTrack & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: track_id
  cdr << ros_message.track_id;
  // Member: x
  cdr << ros_message.x;
  // Member: y
  cdr << ros_message.y;
  // Member: v_x
  cdr << ros_message.v_x;
  // Member: v_y
  cdr << ros_message.v_y;
  // Member: size_w
  cdr << ros_message.size_w;
  // Member: size_l
  cdr << ros_message.size_l;
  // Member: size_h
  cdr << ros_message.size_h;
  // Member: covariance
  {
    cdr << ros_message.covariance;
  }
  // Member: is_dark_target
  cdr << (ros_message.is_dark_target ? true : false);
  // Member: is_ais_matched
  cdr << (ros_message.is_ais_matched ? true : false);
  // Member: matched_mmsi
  cdr << ros_message.matched_mmsi;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_usv_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  usv_interfaces::msg::GlobalTrack & ros_message)
{
  // Member: track_id
  cdr >> ros_message.track_id;

  // Member: x
  cdr >> ros_message.x;

  // Member: y
  cdr >> ros_message.y;

  // Member: v_x
  cdr >> ros_message.v_x;

  // Member: v_y
  cdr >> ros_message.v_y;

  // Member: size_w
  cdr >> ros_message.size_w;

  // Member: size_l
  cdr >> ros_message.size_l;

  // Member: size_h
  cdr >> ros_message.size_h;

  // Member: covariance
  {
    cdr >> ros_message.covariance;
  }

  // Member: is_dark_target
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_dark_target = tmp ? true : false;
  }

  // Member: is_ais_matched
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.is_ais_matched = tmp ? true : false;
  }

  // Member: matched_mmsi
  cdr >> ros_message.matched_mmsi;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_usv_interfaces
get_serialized_size(
  const usv_interfaces::msg::GlobalTrack & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: track_id
  {
    size_t item_size = sizeof(ros_message.track_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: x
  {
    size_t item_size = sizeof(ros_message.x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y
  {
    size_t item_size = sizeof(ros_message.y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_x
  {
    size_t item_size = sizeof(ros_message.v_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_y
  {
    size_t item_size = sizeof(ros_message.v_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: size_w
  {
    size_t item_size = sizeof(ros_message.size_w);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: size_l
  {
    size_t item_size = sizeof(ros_message.size_l);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: size_h
  {
    size_t item_size = sizeof(ros_message.size_h);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: covariance
  {
    size_t array_size = 16;
    size_t item_size = sizeof(ros_message.covariance[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_dark_target
  {
    size_t item_size = sizeof(ros_message.is_dark_target);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_ais_matched
  {
    size_t item_size = sizeof(ros_message.is_ais_matched);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: matched_mmsi
  {
    size_t item_size = sizeof(ros_message.matched_mmsi);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_usv_interfaces
max_serialized_size_GlobalTrack(
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


  // Member: track_id
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: size_w
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: size_l
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: size_h
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: covariance
  {
    size_t array_size = 16;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: is_dark_target
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_ais_matched
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: matched_mmsi
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
    using DataType = usv_interfaces::msg::GlobalTrack;
    is_plain =
      (
      offsetof(DataType, matched_mmsi) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _GlobalTrack__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const usv_interfaces::msg::GlobalTrack *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _GlobalTrack__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<usv_interfaces::msg::GlobalTrack *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _GlobalTrack__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const usv_interfaces::msg::GlobalTrack *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _GlobalTrack__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_GlobalTrack(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _GlobalTrack__callbacks = {
  "usv_interfaces::msg",
  "GlobalTrack",
  _GlobalTrack__cdr_serialize,
  _GlobalTrack__cdr_deserialize,
  _GlobalTrack__get_serialized_size,
  _GlobalTrack__max_serialized_size
};

static rosidl_message_type_support_t _GlobalTrack__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_GlobalTrack__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace usv_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_usv_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<usv_interfaces::msg::GlobalTrack>()
{
  return &usv_interfaces::msg::typesupport_fastrtps_cpp::_GlobalTrack__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, usv_interfaces, msg, GlobalTrack)() {
  return &usv_interfaces::msg::typesupport_fastrtps_cpp::_GlobalTrack__handle;
}

#ifdef __cplusplus
}
#endif
