// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__TRAITS_HPP_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/msg/detail/global_track__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'track_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace usv_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const GlobalTrack & msg,
  std::ostream & out)
{
  out << "{";
  // member: track_id
  {
    out << "track_id: ";
    to_flow_style_yaml(msg.track_id, out);
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

  // member: covariance
  {
    if (msg.covariance.size() == 0) {
      out << "covariance: []";
    } else {
      out << "covariance: [";
      size_t pending_items = msg.covariance.size();
      for (auto item : msg.covariance) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
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
    out << ", ";
  }

  // member: source_model_name
  {
    out << "source_model_name: ";
    rosidl_generator_traits::value_to_yaml(msg.source_model_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GlobalTrack & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: track_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "track_id:\n";
    to_block_style_yaml(msg.track_id, out, indentation + 2);
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

  // member: covariance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.covariance.size() == 0) {
      out << "covariance: []\n";
    } else {
      out << "covariance:\n";
      for (auto item : msg.covariance) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
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

  // member: source_model_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "source_model_name: ";
    rosidl_generator_traits::value_to_yaml(msg.source_model_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GlobalTrack & msg, bool use_flow_style = false)
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
  const usv_interfaces::msg::GlobalTrack & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::msg::GlobalTrack & msg)
{
  return usv_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::msg::GlobalTrack>()
{
  return "usv_interfaces::msg::GlobalTrack";
}

template<>
inline const char * name<usv_interfaces::msg::GlobalTrack>()
{
  return "usv_interfaces/msg/GlobalTrack";
}

template<>
struct has_fixed_size<usv_interfaces::msg::GlobalTrack>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::msg::GlobalTrack>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::msg::GlobalTrack>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__TRAITS_HPP_
