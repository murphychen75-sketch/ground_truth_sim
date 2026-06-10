// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__BUILDER_HPP_
#define USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/srv/detail/get_target_history__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTargetHistory_Request_max_samples
{
public:
  explicit Init_GetTargetHistory_Request_max_samples(::usv_interfaces::srv::GetTargetHistory_Request & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::srv::GetTargetHistory_Request max_samples(::usv_interfaces::srv::GetTargetHistory_Request::_max_samples_type arg)
  {
    msg_.max_samples = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Request msg_;
};

class Init_GetTargetHistory_Request_t_end
{
public:
  explicit Init_GetTargetHistory_Request_t_end(::usv_interfaces::srv::GetTargetHistory_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetHistory_Request_max_samples t_end(::usv_interfaces::srv::GetTargetHistory_Request::_t_end_type arg)
  {
    msg_.t_end = std::move(arg);
    return Init_GetTargetHistory_Request_max_samples(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Request msg_;
};

class Init_GetTargetHistory_Request_t_start
{
public:
  explicit Init_GetTargetHistory_Request_t_start(::usv_interfaces::srv::GetTargetHistory_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetHistory_Request_t_end t_start(::usv_interfaces::srv::GetTargetHistory_Request::_t_start_type arg)
  {
    msg_.t_start = std::move(arg);
    return Init_GetTargetHistory_Request_t_end(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Request msg_;
};

class Init_GetTargetHistory_Request_target_id
{
public:
  Init_GetTargetHistory_Request_target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTargetHistory_Request_t_start target_id(::usv_interfaces::srv::GetTargetHistory_Request::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_GetTargetHistory_Request_t_start(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::srv::GetTargetHistory_Request>()
{
  return usv_interfaces::srv::builder::Init_GetTargetHistory_Request_target_id();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetTargetHistory_Response_samples
{
public:
  explicit Init_GetTargetHistory_Response_samples(::usv_interfaces::srv::GetTargetHistory_Response & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::srv::GetTargetHistory_Response samples(::usv_interfaces::srv::GetTargetHistory_Response::_samples_type arg)
  {
    msg_.samples = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Response msg_;
};

class Init_GetTargetHistory_Response_status
{
public:
  Init_GetTargetHistory_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTargetHistory_Response_samples status(::usv_interfaces::srv::GetTargetHistory_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GetTargetHistory_Response_samples(msg_);
  }

private:
  ::usv_interfaces::srv::GetTargetHistory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::srv::GetTargetHistory_Response>()
{
  return usv_interfaces::srv::builder::Init_GetTargetHistory_Response_status();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__BUILDER_HPP_
