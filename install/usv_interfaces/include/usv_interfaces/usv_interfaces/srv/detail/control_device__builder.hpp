// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:srv/ControlDevice.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__BUILDER_HPP_
#define USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/srv/detail/control_device__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControlDevice_Request_value
{
public:
  explicit Init_ControlDevice_Request_value(::usv_interfaces::srv::ControlDevice_Request & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::srv::ControlDevice_Request value(::usv_interfaces::srv::ControlDevice_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::srv::ControlDevice_Request msg_;
};

class Init_ControlDevice_Request_command
{
public:
  explicit Init_ControlDevice_Request_command(::usv_interfaces::srv::ControlDevice_Request & msg)
  : msg_(msg)
  {}
  Init_ControlDevice_Request_value command(::usv_interfaces::srv::ControlDevice_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_ControlDevice_Request_value(msg_);
  }

private:
  ::usv_interfaces::srv::ControlDevice_Request msg_;
};

class Init_ControlDevice_Request_device_id
{
public:
  Init_ControlDevice_Request_device_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlDevice_Request_command device_id(::usv_interfaces::srv::ControlDevice_Request::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_ControlDevice_Request_command(msg_);
  }

private:
  ::usv_interfaces::srv::ControlDevice_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::srv::ControlDevice_Request>()
{
  return usv_interfaces::srv::builder::Init_ControlDevice_Request_device_id();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace srv
{

namespace builder
{

class Init_ControlDevice_Response_message
{
public:
  explicit Init_ControlDevice_Response_message(::usv_interfaces::srv::ControlDevice_Response & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::srv::ControlDevice_Response message(::usv_interfaces::srv::ControlDevice_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::srv::ControlDevice_Response msg_;
};

class Init_ControlDevice_Response_success
{
public:
  Init_ControlDevice_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlDevice_Response_message success(::usv_interfaces::srv::ControlDevice_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ControlDevice_Response_message(msg_);
  }

private:
  ::usv_interfaces::srv::ControlDevice_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::srv::ControlDevice_Response>()
{
  return usv_interfaces::srv::builder::Init_ControlDevice_Response_success();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__BUILDER_HPP_
