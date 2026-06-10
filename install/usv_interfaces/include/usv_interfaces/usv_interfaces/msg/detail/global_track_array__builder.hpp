// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/GlobalTrackArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/global_track_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_GlobalTrackArray_tracks
{
public:
  explicit Init_GlobalTrackArray_tracks(::usv_interfaces::msg::GlobalTrackArray & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::GlobalTrackArray tracks(::usv_interfaces::msg::GlobalTrackArray::_tracks_type arg)
  {
    msg_.tracks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrackArray msg_;
};

class Init_GlobalTrackArray_header
{
public:
  Init_GlobalTrackArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GlobalTrackArray_tracks header(::usv_interfaces::msg::GlobalTrackArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_GlobalTrackArray_tracks(msg_);
  }

private:
  ::usv_interfaces::msg::GlobalTrackArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::GlobalTrackArray>()
{
  return usv_interfaces::msg::builder::Init_GlobalTrackArray_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK_ARRAY__BUILDER_HPP_
