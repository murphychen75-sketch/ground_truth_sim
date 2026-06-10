// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/global_track__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_GlobalTrack_source_model_name
{
public:
  explicit Init_GlobalTrack_source_model_name(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::GlobalTrack source_model_name(::usv_interfaces::msg::GlobalTrack::_source_model_name_type arg)
  {
    msg_.source_model_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_matched_mmsi
{
public:
  explicit Init_GlobalTrack_matched_mmsi(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_source_model_name matched_mmsi(::usv_interfaces::msg::GlobalTrack::_matched_mmsi_type arg)
  {
    msg_.matched_mmsi = std::move(arg);
    return Init_GlobalTrack_source_model_name(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_is_ais_matched
{
public:
  explicit Init_GlobalTrack_is_ais_matched(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_matched_mmsi is_ais_matched(::usv_interfaces::msg::GlobalTrack::_is_ais_matched_type arg)
  {
    msg_.is_ais_matched = std::move(arg);
    return Init_GlobalTrack_matched_mmsi(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_is_dark_target
{
public:
  explicit Init_GlobalTrack_is_dark_target(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_is_ais_matched is_dark_target(::usv_interfaces::msg::GlobalTrack::_is_dark_target_type arg)
  {
    msg_.is_dark_target = std::move(arg);
    return Init_GlobalTrack_is_ais_matched(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_covariance
{
public:
  explicit Init_GlobalTrack_covariance(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_is_dark_target covariance(::usv_interfaces::msg::GlobalTrack::_covariance_type arg)
  {
    msg_.covariance = std::move(arg);
    return Init_GlobalTrack_is_dark_target(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_size_h
{
public:
  explicit Init_GlobalTrack_size_h(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_covariance size_h(::usv_interfaces::msg::GlobalTrack::_size_h_type arg)
  {
    msg_.size_h = std::move(arg);
    return Init_GlobalTrack_covariance(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_size_l
{
public:
  explicit Init_GlobalTrack_size_l(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_size_h size_l(::usv_interfaces::msg::GlobalTrack::_size_l_type arg)
  {
    msg_.size_l = std::move(arg);
    return Init_GlobalTrack_size_h(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_size_w
{
public:
  explicit Init_GlobalTrack_size_w(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_size_l size_w(::usv_interfaces::msg::GlobalTrack::_size_w_type arg)
  {
    msg_.size_w = std::move(arg);
    return Init_GlobalTrack_size_l(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_v_y
{
public:
  explicit Init_GlobalTrack_v_y(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_size_w v_y(::usv_interfaces::msg::GlobalTrack::_v_y_type arg)
  {
    msg_.v_y = std::move(arg);
    return Init_GlobalTrack_size_w(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_v_x
{
public:
  explicit Init_GlobalTrack_v_x(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_v_y v_x(::usv_interfaces::msg::GlobalTrack::_v_x_type arg)
  {
    msg_.v_x = std::move(arg);
    return Init_GlobalTrack_v_y(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_y
{
public:
  explicit Init_GlobalTrack_y(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_v_x y(::usv_interfaces::msg::GlobalTrack::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GlobalTrack_v_x(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_x
{
public:
  explicit Init_GlobalTrack_x(::usv_interfaces::msg::GlobalTrack & msg)
  : msg_(msg)
  {}
  Init_GlobalTrack_y x(::usv_interfaces::msg::GlobalTrack::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GlobalTrack_y(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

class Init_GlobalTrack_track_id
{
public:
  Init_GlobalTrack_track_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GlobalTrack_x track_id(::usv_interfaces::msg::GlobalTrack::_track_id_type arg)
  {
    msg_.track_id = std::move(arg);
    return Init_GlobalTrack_x(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::GlobalTrack>()
{
  return usv_interfaces::msg::builder::Init_GlobalTrack_track_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__BUILDER_HPP_
