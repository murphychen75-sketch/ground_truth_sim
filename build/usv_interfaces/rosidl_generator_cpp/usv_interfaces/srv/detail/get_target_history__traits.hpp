// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__TRAITS_HPP_
#define USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/srv/detail/get_target_history__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'target_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 't_start'
// Member 't_end'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace usv_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetTargetHistory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target_id
  {
    out << "target_id: ";
    to_flow_style_yaml(msg.target_id, out);
    out << ", ";
  }

  // member: t_start
  {
    out << "t_start: ";
    to_flow_style_yaml(msg.t_start, out);
    out << ", ";
  }

  // member: t_end
  {
    out << "t_end: ";
    to_flow_style_yaml(msg.t_end, out);
    out << ", ";
  }

  // member: max_samples
  {
    out << "max_samples: ";
    rosidl_generator_traits::value_to_yaml(msg.max_samples, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetTargetHistory_Request & msg,
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

  // member: t_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_start:\n";
    to_block_style_yaml(msg.t_start, out, indentation + 2);
  }

  // member: t_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t_end:\n";
    to_block_style_yaml(msg.t_end, out, indentation + 2);
  }

  // member: max_samples
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_samples: ";
    rosidl_generator_traits::value_to_yaml(msg.max_samples, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetTargetHistory_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace usv_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use usv_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const usv_interfaces::srv::GetTargetHistory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::srv::GetTargetHistory_Request & msg)
{
  return usv_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::srv::GetTargetHistory_Request>()
{
  return "usv_interfaces::srv::GetTargetHistory_Request";
}

template<>
inline const char * name<usv_interfaces::srv::GetTargetHistory_Request>()
{
  return "usv_interfaces/srv/GetTargetHistory_Request";
}

template<>
struct has_fixed_size<usv_interfaces::srv::GetTargetHistory_Request>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<usv_interfaces::srv::GetTargetHistory_Request>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<usv_interfaces::srv::GetTargetHistory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'samples'
#include "usv_interfaces/msg/detail/fused_track_sample__traits.hpp"

namespace usv_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetTargetHistory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: samples
  {
    if (msg.samples.size() == 0) {
      out << "samples: []";
    } else {
      out << "samples: [";
      size_t pending_items = msg.samples.size();
      for (auto item : msg.samples) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetTargetHistory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: samples
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.samples.size() == 0) {
      out << "samples: []\n";
    } else {
      out << "samples:\n";
      for (auto item : msg.samples) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetTargetHistory_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace usv_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use usv_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const usv_interfaces::srv::GetTargetHistory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::srv::GetTargetHistory_Response & msg)
{
  return usv_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::srv::GetTargetHistory_Response>()
{
  return "usv_interfaces::srv::GetTargetHistory_Response";
}

template<>
inline const char * name<usv_interfaces::srv::GetTargetHistory_Response>()
{
  return "usv_interfaces/srv/GetTargetHistory_Response";
}

template<>
struct has_fixed_size<usv_interfaces::srv::GetTargetHistory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::srv::GetTargetHistory_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::srv::GetTargetHistory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<usv_interfaces::srv::GetTargetHistory>()
{
  return "usv_interfaces::srv::GetTargetHistory";
}

template<>
inline const char * name<usv_interfaces::srv::GetTargetHistory>()
{
  return "usv_interfaces/srv/GetTargetHistory";
}

template<>
struct has_fixed_size<usv_interfaces::srv::GetTargetHistory>
  : std::integral_constant<
    bool,
    has_fixed_size<usv_interfaces::srv::GetTargetHistory_Request>::value &&
    has_fixed_size<usv_interfaces::srv::GetTargetHistory_Response>::value
  >
{
};

template<>
struct has_bounded_size<usv_interfaces::srv::GetTargetHistory>
  : std::integral_constant<
    bool,
    has_bounded_size<usv_interfaces::srv::GetTargetHistory_Request>::value &&
    has_bounded_size<usv_interfaces::srv::GetTargetHistory_Response>::value
  >
{
};

template<>
struct is_service<usv_interfaces::srv::GetTargetHistory>
  : std::true_type
{
};

template<>
struct is_service_request<usv_interfaces::srv::GetTargetHistory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<usv_interfaces::srv::GetTargetHistory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__TRAITS_HPP_
