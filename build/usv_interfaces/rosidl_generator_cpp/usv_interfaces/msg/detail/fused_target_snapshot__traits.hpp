// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'state'
#include "usv_interfaces/msg/detail/fused_track_sample__traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const FusedTargetSnapshot & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_id
  {
    out << "target_id: ";
    to_flow_style_yaml(msg.target_id, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    to_flow_style_yaml(msg.state, out);
    out << ", ";
  }

  // member: size_w
  {
    out << "size_w: ";
    rosidl_generator_traits::value_to_yaml(msg.size_w, out);
    out << ", ";
  }

  // member: size_l
  {
    out << "size_l: ";
    rosidl_generator_traits::value_to_yaml(msg.size_l, out);
    out << ", ";
  }

  // member: size_h
  {
    out << "size_h: ";
    rosidl_generator_traits::value_to_yaml(msg.size_h, out);
    out << ", ";
  }

  // member: is_dark_target
  {
    out << "is_dark_target: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dark_target, out);
    out << ", ";
  }

  // member: is_ais_matched
  {
    out << "is_ais_matched: ";
    rosidl_generator_traits::value_to_yaml(msg.is_ais_matched, out);
    out << ", ";
  }

  // member: matched_mmsi
  {
    out << "matched_mmsi: ";
    rosidl_generator_traits::value_to_yaml(msg.matched_mmsi, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FusedTargetSnapshot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_id:\n";
    to_block_style_yaml(msg.target_id, out, indentation + 2);
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state:\n";
    to_block_style_yaml(msg.state, out, indentation + 2);
  }

  // member: size_w
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size_w: ";
    rosidl_generator_traits::value_to_yaml(msg.size_w, out);
    out << "\n";
  }

  // member: size_l
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size_l: ";
    rosidl_generator_traits::value_to_yaml(msg.size_l, out);
    out << "\n";
  }

  // member: size_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size_h: ";
    rosidl_generator_traits::value_to_yaml(msg.size_h, out);
    out << "\n";
  }

  // member: is_dark_target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_dark_target: ";
    rosidl_generator_traits::value_to_yaml(msg.is_dark_target, out);
    out << "\n";
  }

  // member: is_ais_matched
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_ais_matched: ";
    rosidl_generator_traits::value_to_yaml(msg.is_ais_matched, out);
    out << "\n";
  }

  // member: matched_mmsi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "matched_mmsi: ";
    rosidl_generator_traits::value_to_yaml(msg.matched_mmsi, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FusedTargetSnapshot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace usv_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use usv_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const usv_interfaces::msg::FusedTargetSnapshot & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::FusedTargetSnapshot & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::FusedTargetSnapshot>()
{
  return "usv_interfaces::msg::FusedTargetSnapshot";
}

template<>
inline const char * name<usv_interfaces::msg::FusedTargetSnapshot>()
{
  return "usv_interfaces/msg/FusedTargetSnapshot";
}

template<>
struct has_fixed_size<usv_interfaces::msg::FusedTargetSnapshot>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value && has_fixed_size<usv_interfaces::msg::FusedTrackSample>::value> {};

template<>
struct has_bounded_size<usv_interfaces::msg::FusedTargetSnapshot>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value && has_bounded_size<usv_interfaces::msg::FusedTrackSample>::value> {};

template<>
struct is_message<usv_interfaces::msg::FusedTargetSnapshot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__TRAITS_HPP_
