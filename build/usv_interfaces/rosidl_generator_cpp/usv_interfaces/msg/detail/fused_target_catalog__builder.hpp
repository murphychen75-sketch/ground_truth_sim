// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/FusedTargetCatalog.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/fused_target_catalog__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_FusedTargetCatalog_profiles
{
public:
  explicit Init_FusedTargetCatalog_profiles(::usv_interfaces::msg::FusedTargetCatalog & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::FusedTargetCatalog profiles(::usv_interfaces::msg::FusedTargetCatalog::_profiles_type arg)
  {
    msg_.profiles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetCatalog msg_;
};

class Init_FusedTargetCatalog_header
{
public:
  Init_FusedTargetCatalog_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedTargetCatalog_profiles header(::usv_interfaces::msg::FusedTargetCatalog::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FusedTargetCatalog_profiles(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetCatalog msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::FusedTargetCatalog>()
{
  return usv_interfaces::msg::builder::Init_FusedTargetCatalog_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_CATALOG__BUILDER_HPP_
