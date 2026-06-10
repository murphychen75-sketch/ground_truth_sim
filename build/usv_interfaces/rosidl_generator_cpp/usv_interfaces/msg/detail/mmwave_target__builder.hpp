// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/mmwave_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_MmwaveTarget_track_id
{
public:
  explicit Init_MmwaveTarget_track_id(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::MmwaveTarget track_id(::usv_interfaces::msg::MmwaveTarget::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_objmotion_status
{
public:
  explicit Init_MmwaveTarget_objmotion_status(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_track_id objmotion_status(::usv_interfaces::msg::MmwaveTarget::_objmotion_status_type arg)
  {
    msg_.objmotion_status = std::move(arg);
    return Init_MmwaveTarget_track_id(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_size_h
{
public:
  explicit Init_MmwaveTarget_size_h(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_objmotion_status size_h(::usv_interfaces::msg::MmwaveTarget::_size_h_type arg)
  {
    msg_.size_h = std::move(arg);
    return Init_MmwaveTarget_objmotion_status(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_size_l
{
public:
  explicit Init_MmwaveTarget_size_l(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_size_h size_l(::usv_interfaces::msg::MmwaveTarget::_size_l_type arg)
  {
    msg_.size_l = std::move(arg);
    return Init_MmwaveTarget_size_h(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_size_w
{
public:
  explicit Init_MmwaveTarget_size_w(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_size_l size_w(::usv_interfaces::msg::MmwaveTarget::_size_w_type arg)
  {
    msg_.size_w = std::move(arg);
    return Init_MmwaveTarget_size_l(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_v_y
{
public:
  explicit Init_MmwaveTarget_v_y(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_size_w v_y(::usv_interfaces::msg::MmwaveTarget::_v_y_type arg)
  {
    msg_.v_y = std::move(arg);
    return Init_MmwaveTarget_size_w(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_v_x
{
public:
  explicit Init_MmwaveTarget_v_x(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_v_y v_x(::usv_interfaces::msg::MmwaveTarget::_v_x_type arg)
  {
    msg_.v_x = std::move(arg);
    return Init_MmwaveTarget_v_y(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_y
{
public:
  explicit Init_MmwaveTarget_y(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_v_x y(::usv_interfaces::msg::MmwaveTarget::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_MmwaveTarget_v_x(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_x
{
public:
  explicit Init_MmwaveTarget_x(::usv_interfaces::msg::MmwaveTarget & msg)
  : msg_(msg)
  {}
  Init_MmwaveTarget_y x(::usv_interfaces::msg::MmwaveTarget::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_MmwaveTarget_y(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

class Init_MmwaveTarget_radar_id
{
public:
  Init_MmwaveTarget_radar_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MmwaveTarget_x radar_id(::usv_interfaces::msg::MmwaveTarget::_radar_id_type arg)
  {
    msg_.radar_id = std::move(arg);
    return Init_MmwaveTarget_x(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::MmwaveTarget>()
{
  return usv_interfaces::msg::builder::Init_MmwaveTarget_radar_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__BUILDER_HPP_
