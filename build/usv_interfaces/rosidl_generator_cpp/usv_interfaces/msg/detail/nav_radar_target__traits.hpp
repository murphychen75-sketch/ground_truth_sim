// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/NavRadarTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/nav_radar_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const NavRadarTarget & msg,
  std::ostream & out)
{
  out << "{";
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

  // member: area
  {
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NavRadarTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
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

  // member: area
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "area: ";
    rosidl_generator_traits::value_to_yaml(msg.area, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NavRadarTarget & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::NavRadarTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::NavRadarTarget & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::NavRadarTarget>()
{
  return "usv_interfaces::msg::NavRadarTarget";
}

template<>
inline const char * name<usv_interfaces::msg::NavRadarTarget>()
{
  return "usv_interfaces/msg/NavRadarTarget";
}

template<>
struct has_fixed_size<usv_interfaces::msg::NavRadarTarget>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<usv_interfaces::msg::NavRadarTarget>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<usv_interfaces::msg::NavRadarTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__TRAITS_HPP_
