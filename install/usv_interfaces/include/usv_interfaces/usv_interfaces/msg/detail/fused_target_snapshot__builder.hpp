// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_FusedTargetSnapshot_matched_mmsi
{
public:
  explicit Init_FusedTargetSnapshot_matched_mmsi(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::FusedTargetSnapshot matched_mmsi(::usv_interfaces::msg::FusedTargetSnapshot::_matched_mmsi_type arg)
  {
    msg_.matched_mmsi = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_is_ais_matched
{
public:
  explicit Init_FusedTargetSnapshot_is_ais_matched(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_matched_mmsi is_ais_matched(::usv_interfaces::msg::FusedTargetSnapshot::_is_ais_matched_type arg)
  {
    msg_.is_ais_matched = std::move(arg);
    return Init_FusedTargetSnapshot_matched_mmsi(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_is_dark_target
{
public:
  explicit Init_FusedTargetSnapshot_is_dark_target(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_is_ais_matched is_dark_target(::usv_interfaces::msg::FusedTargetSnapshot::_is_dark_target_type arg)
  {
    msg_.is_dark_target = std::move(arg);
    return Init_FusedTargetSnapshot_is_ais_matched(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_size_h
{
public:
  explicit Init_FusedTargetSnapshot_size_h(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_is_dark_target size_h(::usv_interfaces::msg::FusedTargetSnapshot::_size_h_type arg)
  {
    msg_.size_h = std::move(arg);
    return Init_FusedTargetSnapshot_is_dark_target(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_size_l
{
public:
  explicit Init_FusedTargetSnapshot_size_l(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_size_h size_l(::usv_interfaces::msg::FusedTargetSnapshot::_size_l_type arg)
  {
    msg_.size_l = std::move(arg);
    return Init_FusedTargetSnapshot_size_h(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_size_w
{
public:
  explicit Init_FusedTargetSnapshot_size_w(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_size_l size_w(::usv_interfaces::msg::FusedTargetSnapshot::_size_w_type arg)
  {
    msg_.size_w = std::move(arg);
    return Init_FusedTargetSnapshot_size_l(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_state
{
public:
  explicit Init_FusedTargetSnapshot_state(::usv_interfaces::msg::FusedTargetSnapshot & msg)
  : msg_(msg)
  {}
  Init_FusedTargetSnapshot_size_w state(::usv_interfaces::msg::FusedTargetSnapshot::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_FusedTargetSnapshot_size_w(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

class Init_FusedTargetSnapshot_target_id
{
public:
  Init_FusedTargetSnapshot_target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedTargetSnapshot_state target_id(::usv_interfaces::msg::FusedTargetSnapshot::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_FusedTargetSnapshot_state(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetSnapshot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::FusedTargetSnapshot>()
{
  return usv_interfaces::msg::builder::Init_FusedTargetSnapshot_target_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__BUILDER_HPP_
