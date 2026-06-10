// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/FusedTrackSample.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/fused_track_sample__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_FusedTrackSample_covariance
{
public:
  explicit Init_FusedTrackSample_covariance(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::FusedTrackSample covariance(::usv_interfaces::msg::FusedTrackSample::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_v_y
{
public:
  explicit Init_FusedTrackSample_v_y(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  Init_FusedTrackSample_covariance v_y(::usv_interfaces::msg::FusedTrackSample::_v_y_type arg)
  {
    msg_.v_y = std::move(arg);
    return Init_FusedTrackSample_covariance(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_v_x
{
public:
  explicit Init_FusedTrackSample_v_x(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  Init_FusedTrackSample_v_y v_x(::usv_interfaces::msg::FusedTrackSample::_v_x_type arg)
  {
    msg_.v_x = std::move(arg);
    return Init_FusedTrackSample_v_y(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_y
{
public:
  explicit Init_FusedTrackSample_y(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  Init_FusedTrackSample_v_x y(::usv_interfaces::msg::FusedTrackSample::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_FusedTrackSample_v_x(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_x
{
public:
  explicit Init_FusedTrackSample_x(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  Init_FusedTrackSample_y x(::usv_interfaces::msg::FusedTrackSample::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_FusedTrackSample_y(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_t_sec
{
public:
  explicit Init_FusedTrackSample_t_sec(::usv_interfaces::msg::FusedTrackSample & msg)
  : msg_(msg)
  {}
  Init_FusedTrackSample_x t_sec(::usv_interfaces::msg::FusedTrackSample::_t_sec_type arg)
  {
    msg_.t_sec = std::move(arg);
    return Init_FusedTrackSample_x(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

class Init_FusedTrackSample_stamp
{
public:
  Init_FusedTrackSample_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedTrackSample_t_sec stamp(::usv_interfaces::msg::FusedTrackSample::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_FusedTrackSample_t_sec(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTrackSample msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::FusedTrackSample>()
{
  return usv_interfaces::msg::builder::Init_FusedTrackSample_stamp();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__BUILDER_HPP_
