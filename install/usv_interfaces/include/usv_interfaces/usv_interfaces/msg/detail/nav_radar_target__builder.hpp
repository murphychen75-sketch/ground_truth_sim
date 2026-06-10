// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/NavRadarTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/nav_radar_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavRadarTarget_area
{
public:
  explicit Init_NavRadarTarget_area(::usv_interfaces::msg::NavRadarTarget & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::NavRadarTarget area(::usv_interfaces::msg::NavRadarTarget::_area_type arg)
  {
    msg_.area = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTarget msg_;
};

class Init_NavRadarTarget_v_y
{
public:
  explicit Init_NavRadarTarget_v_y(::usv_interfaces::msg::NavRadarTarget & msg)
  : msg_(msg)
  {}
  Init_NavRadarTarget_area v_y(::usv_interfaces::msg::NavRadarTarget::_v_y_type arg)
  {
    msg_.v_y = std::move(arg);
    return Init_NavRadarTarget_area(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTarget msg_;
};

class Init_NavRadarTarget_v_x
{
public:
  explicit Init_NavRadarTarget_v_x(::usv_interfaces::msg::NavRadarTarget & msg)
  : msg_(msg)
  {}
  Init_NavRadarTarget_v_y v_x(::usv_interfaces::msg::NavRadarTarget::_v_x_type arg)
  {
    msg_.v_x = std::move(arg);
    return Init_NavRadarTarget_v_y(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTarget msg_;
};

class Init_NavRadarTarget_y
{
public:
  explicit Init_NavRadarTarget_y(::usv_interfaces::msg::NavRadarTarget & msg)
  : msg_(msg)
  {}
  Init_NavRadarTarget_v_x y(::usv_interfaces::msg::NavRadarTarget::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_NavRadarTarget_v_x(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTarget msg_;
};

class Init_NavRadarTarget_x
{
public:
  Init_NavRadarTarget_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavRadarTarget_y x(::usv_interfaces::msg::NavRadarTarget::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_NavRadarTarget_y(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::NavRadarTarget>()
{
  return usv_interfaces::msg::builder::Init_NavRadarTarget_x();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__BUILDER_HPP_
