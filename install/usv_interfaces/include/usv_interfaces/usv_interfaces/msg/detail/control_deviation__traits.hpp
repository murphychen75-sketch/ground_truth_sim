// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/control_deviation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ControlDeviation & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: cross_track_error
  {
    out << "cross_track_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cross_track_error, out);
    out << ", ";
  }

  // member: heading_error
  {
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
    out << ", ";
  }

  // member: distance_to_goal
  {
    out << "distance_to_goal: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_goal, out);
    out << ", ";
  }

  // member: target_speed
  {
    out << "target_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.target_speed, out);
    out << ", ";
  }

  // member: current_speed
  {
    out << "current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.current_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlDeviation & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: cross_track_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cross_track_error: ";
    rosidl_generator_traits::value_to_yaml(msg.cross_track_error, out);
    out << "\n";
  }

  // member: heading_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "heading_error: ";
    rosidl_generator_traits::value_to_yaml(msg.heading_error, out);
    out << "\n";
  }

  // member: distance_to_goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_to_goal: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_to_goal, out);
    out << "\n";
  }

  // member: target_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.target_speed, out);
    out << "\n";
  }

  // member: current_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.current_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlDeviation & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::ControlDeviation & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::ControlDeviation & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::ControlDeviation>()
{
  return "usv_interfaces::msg::ControlDeviation";
}

template<>
inline const char * name<usv_interfaces::msg::ControlDeviation>()
{
  return "usv_interfaces/msg/ControlDeviation";
}

template<>
struct has_fixed_size<usv_interfaces::msg::ControlDeviation>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<usv_interfaces::msg::ControlDeviation>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<usv_interfaces::msg::ControlDeviation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__TRAITS_HPP_
