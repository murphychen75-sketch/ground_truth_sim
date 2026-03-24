// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/control_deviation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_ControlDeviation_current_speed
{
public:
  explicit Init_ControlDeviation_current_speed(::usv_interfaces::msg::ControlDeviation & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::ControlDeviation current_speed(::usv_interfaces::msg::ControlDeviation::_current_speed_type arg)
  {
    msg_.current_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

class Init_ControlDeviation_target_speed
{
public:
  explicit Init_ControlDeviation_target_speed(::usv_interfaces::msg::ControlDeviation & msg)
  : msg_(msg)
  {}
  Init_ControlDeviation_current_speed target_speed(::usv_interfaces::msg::ControlDeviation::_target_speed_type arg)
  {
    msg_.target_speed = std::move(arg);
    return Init_ControlDeviation_current_speed(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

class Init_ControlDeviation_distance_to_goal
{
public:
  explicit Init_ControlDeviation_distance_to_goal(::usv_interfaces::msg::ControlDeviation & msg)
  : msg_(msg)
  {}
  Init_ControlDeviation_target_speed distance_to_goal(::usv_interfaces::msg::ControlDeviation::_distance_to_goal_type arg)
  {
    msg_.distance_to_goal = std::move(arg);
    return Init_ControlDeviation_target_speed(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

class Init_ControlDeviation_heading_error
{
public:
  explicit Init_ControlDeviation_heading_error(::usv_interfaces::msg::ControlDeviation & msg)
  : msg_(msg)
  {}
  Init_ControlDeviation_distance_to_goal heading_error(::usv_interfaces::msg::ControlDeviation::_heading_error_type arg)
  {
    msg_.heading_error = std::move(arg);
    return Init_ControlDeviation_distance_to_goal(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

class Init_ControlDeviation_cross_track_error
{
public:
  explicit Init_ControlDeviation_cross_track_error(::usv_interfaces::msg::ControlDeviation & msg)
  : msg_(msg)
  {}
  Init_ControlDeviation_heading_error cross_track_error(::usv_interfaces::msg::ControlDeviation::_cross_track_error_type arg)
  {
    msg_.cross_track_error = std::move(arg);
    return Init_ControlDeviation_heading_error(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

class Init_ControlDeviation_header
{
public:
  Init_ControlDeviation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ControlDeviation_cross_track_error header(::usv_interfaces::msg::ControlDeviation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ControlDeviation_cross_track_error(msg_);
  }

private:
  ::usv_interfaces::msg::ControlDeviation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::ControlDeviation>()
{
  return usv_interfaces::msg::builder::Init_ControlDeviation_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__BUILDER_HPP_
