// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from usv_interfaces:srv/ControlDevice.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__TRAITS_HPP_
#define USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "usv_interfaces/srv/detail/control_device__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace usv_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ControlDevice_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: device_id
  {
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << ", ";
  }

  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlDevice_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << "\n";
  }

  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlDevice_Request & msg, bool use_flow_style = false)
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
  const usv_interfaces::srv::ControlDevice_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::srv::ControlDevice_Request & msg)
{
  return usv_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::srv::ControlDevice_Request>()
{
  return "usv_interfaces::srv::ControlDevice_Request";
}

template<>
inline const char * name<usv_interfaces::srv::ControlDevice_Request>()
{
  return "usv_interfaces/srv/ControlDevice_Request";
}

template<>
struct has_fixed_size<usv_interfaces::srv::ControlDevice_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::srv::ControlDevice_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::srv::ControlDevice_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace usv_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ControlDevice_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ControlDevice_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ControlDevice_Response & msg, bool use_flow_style = false)
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
  const usv_interfaces::srv::ControlDevice_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  usv_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use usv_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const usv_interfaces::srv::ControlDevice_Response & msg)
{
  return usv_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<usv_interfaces::srv::ControlDevice_Response>()
{
  return "usv_interfaces::srv::ControlDevice_Response";
}

template<>
inline const char * name<usv_interfaces::srv::ControlDevice_Response>()
{
  return "usv_interfaces/srv/ControlDevice_Response";
}

template<>
struct has_fixed_size<usv_interfaces::srv::ControlDevice_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<usv_interfaces::srv::ControlDevice_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<usv_interfaces::srv::ControlDevice_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<usv_interfaces::srv::ControlDevice>()
{
  return "usv_interfaces::srv::ControlDevice";
}

template<>
inline const char * name<usv_interfaces::srv::ControlDevice>()
{
  return "usv_interfaces/srv/ControlDevice";
}

template<>
struct has_fixed_size<usv_interfaces::srv::ControlDevice>
  : std::integral_constant<
    bool,
    has_fixed_size<usv_interfaces::srv::ControlDevice_Request>::value &&
    has_fixed_size<usv_interfaces::srv::ControlDevice_Response>::value
  >
{
};

template<>
struct has_bounded_size<usv_interfaces::srv::ControlDevice>
  : std::integral_constant<
    bool,
    has_bounded_size<usv_interfaces::srv::ControlDevice_Request>::value &&
    has_bounded_size<usv_interfaces::srv::ControlDevice_Response>::value
  >
{
};

template<>
struct is_service<usv_interfaces::srv::ControlDevice>
  : std::true_type
{
};

template<>
struct is_service_request<usv_interfaces::srv::ControlDevice_Request>
  : std::true_type
{
};

template<>
struct is_service_response<usv_interfaces::srv::ControlDevice_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__TRAITS_HPP_
