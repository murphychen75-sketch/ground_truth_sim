// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/AISTrackArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/ais_track_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_AISTrackArray_tracks
{
public:
  explicit Init_AISTrackArray_tracks(::usv_interfaces::msg::AISTrackArray & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::AISTrackArray tracks(::usv_interfaces::msg::AISTrackArray::_tracks_type arg)
  {
    msg_.tracks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrackArray msg_;
};

class Init_AISTrackArray_header
{
public:
  Init_AISTrackArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AISTrackArray_tracks header(::usv_interfaces::msg::AISTrackArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_AISTrackArray_tracks(msg_);
  }

private:
  ::usv_interfaces::msg::AISTrackArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::AISTrackArray>()
{
  return usv_interfaces::msg::builder::Init_AISTrackArray_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__BUILDER_HPP_
