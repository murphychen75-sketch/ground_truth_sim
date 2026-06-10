// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/ais_track__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const AISTrack & msg,
  std::ostream & out)
{
  out << "{";
  // member: mmsi
  {
    out << "mmsi: ";
    rosidl_generator_traits::value_to_yaml(msg.mmsi, out);
    out << ", ";
  }

  // member: ship_name
  {
    out << "ship_name: ";
    rosidl_generator_traits::value_to_yaml(msg.ship_name, out);
    out << ", ";
  }

  // member: relative_x
  {
    out << "relative_x: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_x, out);
    out << ", ";
  }

  // member: relative_y
  {
    out << "relative_y: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_y, out);
    out << ", ";
  }

  // member: relative_v_x
  {
    out << "relative_v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_v_x, out);
    out << ", ";
  }

  // member: relative_v_y
  {
    out << "relative_v_y: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_v_y, out);
    out << ", ";
  }

  // member: true_heading
  {
    out << "true_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.true_heading, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AISTrack & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mmsi
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mmsi: ";
    rosidl_generator_traits::value_to_yaml(msg.mmsi, out);
    out << "\n";
  }

  // member: ship_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ship_name: ";
    rosidl_generator_traits::value_to_yaml(msg.ship_name, out);
    out << "\n";
  }

  // member: relative_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_x: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_x, out);
    out << "\n";
  }

  // member: relative_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_y: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_y, out);
    out << "\n";
  }

  // member: relative_v_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_v_x: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_v_x, out);
    out << "\n";
  }

  // member: relative_v_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "relative_v_y: ";
    rosidl_generator_traits::value_to_yaml(msg.relative_v_y, out);
    out << "\n";
  }

  // member: true_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "true_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.true_heading, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AISTrack & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::AISTrack & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::AISTrack & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::AISTrack>()
{
  return "usv_interfaces::msg::AISTrack";
}

template<>
inline const char * name<usv_interfaces::msg::AISTrack>()
{
  return "usv_interfaces/msg/AISTrack";
}

template<>
struct has_fixed_size<usv_interfaces::msg::AISTrack>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::msg::AISTrack>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::msg::AISTrack>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK__TRAITS_HPP_
