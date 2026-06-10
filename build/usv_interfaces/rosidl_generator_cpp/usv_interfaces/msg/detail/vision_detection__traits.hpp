// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/VisionDetection.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/vision_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisionDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: camera_id
  {
    out << "camera_id: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_id, out);
    out << ", ";
  }

  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: distance_predict
  {
    out << "distance_predict: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_predict, out);
    out << ", ";
  }

  // member: size_w
  {
    out << "size_w: ";
    rosidl_generator_traits::value_to_yaml(msg.size_w, out);
    out << ", ";
  }

  // member: size_h
  {
    out << "size_h: ";
    rosidl_generator_traits::value_to_yaml(msg.size_h, out);
    out << ", ";
  }

  // member: pixel_width
  {
    out << "pixel_width: ";
    rosidl_generator_traits::value_to_yaml(msg.pixel_width, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: camera_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "camera_id: ";
    rosidl_generator_traits::value_to_yaml(msg.camera_id, out);
    out << "\n";
  }

  // member: class_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << "\n";
  }

  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << "\n";
  }

  // member: distance_predict
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_predict: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_predict, out);
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

  // member: size_h
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size_h: ";
    rosidl_generator_traits::value_to_yaml(msg.size_h, out);
    out << "\n";
  }

  // member: pixel_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pixel_width: ";
    rosidl_generator_traits::value_to_yaml(msg.pixel_width, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionDetection & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::VisionDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::VisionDetection & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::VisionDetection>()
{
  return "usv_interfaces::msg::VisionDetection";
}

template<>
inline const char * name<usv_interfaces::msg::VisionDetection>()
{
  return "usv_interfaces/msg/VisionDetection";
}

template<>
struct has_fixed_size<usv_interfaces::msg::VisionDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::msg::VisionDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::msg::VisionDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__TRAITS_HPP_
