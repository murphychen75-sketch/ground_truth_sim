// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/FusedSceneSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/fused_scene_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_FusedSceneSnapshot_targets
{
public:
  explicit Init_FusedSceneSnapshot_targets(::usv_interfaces::msg::FusedSceneSnapshot & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::FusedSceneSnapshot targets(::usv_interfaces::msg::FusedSceneSnapshot::_targets_type arg)
  {
    msg_.targets = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::FusedSceneSnapshot msg_;
};

class Init_FusedSceneSnapshot_header
{
public:
  Init_FusedSceneSnapshot_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedSceneSnapshot_targets header(::usv_interfaces::msg::FusedSceneSnapshot::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FusedSceneSnapshot_targets(msg_);
  }

private:
  ::usv_interfaces::msg::FusedSceneSnapshot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::FusedSceneSnapshot>()
{
  return usv_interfaces::msg::builder::Init_FusedSceneSnapshot_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__BUILDER_HPP_
