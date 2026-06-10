// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/OperationMode.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/operation_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_OperationMode_mode
{
public:
  explicit Init_OperationMode_mode(::usv_interfaces::msg::OperationMode & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::OperationMode mode(::usv_interfaces::msg::OperationMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::OperationMode msg_;
};

class Init_OperationMode_header
{
public:
  Init_OperationMode_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OperationMode_mode header(::usv_interfaces::msg::OperationMode::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_OperationMode_mode(msg_);
  }

private:
  ::usv_interfaces::msg::OperationMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::OperationMode>()
{
  return usv_interfaces::msg::builder::Init_OperationMode_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__BUILDER_HPP_
