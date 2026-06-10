// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/ais_track__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_AISTrack_true_heading
{
public:
  explicit Init_AISTrack_true_heading(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::AISTrack true_heading(::usv_interfaces::msg::AISTrack::_true_heading_type arg)
  {
    msg_.true_heading = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_relative_v_y
{
public:
  explicit Init_AISTrack_relative_v_y(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  Init_AISTrack_true_heading relative_v_y(::usv_interfaces::msg::AISTrack::_relative_v_y_type arg)
  {
    msg_.relative_v_y = std::move(arg);
    return Init_AISTrack_true_heading(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_relative_v_x
{
public:
  explicit Init_AISTrack_relative_v_x(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  Init_AISTrack_relative_v_y relative_v_x(::usv_interfaces::msg::AISTrack::_relative_v_x_type arg)
  {
    msg_.relative_v_x = std::move(arg);
    return Init_AISTrack_relative_v_y(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_relative_y
{
public:
  explicit Init_AISTrack_relative_y(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  Init_AISTrack_relative_v_x relative_y(::usv_interfaces::msg::AISTrack::_relative_y_type arg)
  {
    msg_.relative_y = std::move(arg);
    return Init_AISTrack_relative_v_x(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_relative_x
{
public:
  explicit Init_AISTrack_relative_x(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  Init_AISTrack_relative_y relative_x(::usv_interfaces::msg::AISTrack::_relative_x_type arg)
  {
    msg_.relative_x = std::move(arg);
    return Init_AISTrack_relative_y(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_ship_name
{
public:
  explicit Init_AISTrack_ship_name(::usv_interfaces::msg::AISTrack & msg)
  : msg_(msg)
  {}
  Init_AISTrack_relative_x ship_name(::usv_interfaces::msg::AISTrack::_ship_name_type arg)
  {
    msg_.ship_name = std::move(arg);
    return Init_AISTrack_relative_x(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

class Init_AISTrack_mmsi
{
public:
  Init_AISTrack_mmsi()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AISTrack_ship_name mmsi(::usv_interfaces::msg::AISTrack::_mmsi_type arg)
  {
    msg_.mmsi = std::move(arg);
    return Init_AISTrack_ship_name(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrack msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::AISTrack>()
{
  return usv_interfaces::msg::builder::Init_AISTrack_mmsi();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK__BUILDER_HPP_
