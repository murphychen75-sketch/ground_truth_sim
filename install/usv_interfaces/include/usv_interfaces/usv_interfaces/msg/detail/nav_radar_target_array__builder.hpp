// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/NavRadarTargetArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/nav_radar_target_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_NavRadarTargetArray_targets
{
public:
  explicit Init_NavRadarTargetArray_targets(::usv_interfaces::msg::NavRadarTargetArray & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::NavRadarTargetArray targets(::usv_interfaces::msg::NavRadarTargetArray::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTargetArray msg_;
};

class Init_NavRadarTargetArray_header
{
public:
  Init_NavRadarTargetArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavRadarTargetArray_targets header(::usv_interfaces::msg::NavRadarTargetArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NavRadarTargetArray_targets(msg_);
  }

private:
  ::usv_interfaces::msg::NavRadarTargetArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::NavRadarTargetArray>()
{
  return usv_interfaces::msg::builder::Init_NavRadarTargetArray_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET_ARRAY__BUILDER_HPP_
