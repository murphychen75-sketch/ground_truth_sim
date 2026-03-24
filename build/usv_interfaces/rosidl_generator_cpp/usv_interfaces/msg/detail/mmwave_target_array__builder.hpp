// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/MmwaveTargetArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/mmwave_target_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_MmwaveTargetArray_targets
{
public:
  explicit Init_MmwaveTargetArray_targets(::usv_interfaces::msg::MmwaveTargetArray & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::MmwaveTargetArray targets(::usv_interfaces::msg::MmwaveTargetArray::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTargetArray msg_;
};

class Init_MmwaveTargetArray_header
{
public:
  Init_MmwaveTargetArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MmwaveTargetArray_targets header(::usv_interfaces::msg::MmwaveTargetArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MmwaveTargetArray_targets(msg_);
  }

private:
  ::usv_interfaces::msg::MmwaveTargetArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::MmwaveTargetArray>()
{
  return usv_interfaces::msg::builder::Init_MmwaveTargetArray_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET_ARRAY__BUILDER_HPP_
