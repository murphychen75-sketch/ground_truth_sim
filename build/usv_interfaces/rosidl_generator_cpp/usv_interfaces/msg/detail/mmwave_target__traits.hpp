// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/mmwave_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MmwaveTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: radar_id
  {
    out << "radar_id: ";
    rosidl_generator_traits::value_to_yaml(msg.radar_id, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: v_x
  {
    out << "v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_x, out);
    out << ", ";
  }

  // member: v_y
  {
    out << "v_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_y, out);
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

  // member: snr
  {
    out << "snr: ";
    rosidl_generator_traits::value_to_yaml(msg.snr, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MmwaveTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: radar_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radar_id: ";
    rosidl_generator_traits::value_to_yaml(msg.radar_id, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: v_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_x, out);
    out << "\n";
  }

  // member: v_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_y, out);
    out << "\n";
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

  // member: snr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "snr: ";
    rosidl_generator_traits::value_to_yaml(msg.snr, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MmwaveTarget & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::MmwaveTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::MmwaveTarget & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::MmwaveTarget>()
{
  return "usv_interfaces::msg::MmwaveTarget";
}

template<>
inline const char * name<usv_interfaces::msg::MmwaveTarget>()
{
  return "usv_interfaces/msg/MmwaveTarget";
}

template<>
struct has_fixed_size<usv_interfaces::msg::MmwaveTarget>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::msg::MmwaveTarget>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::msg::MmwaveTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__TRAITS_HPP_
