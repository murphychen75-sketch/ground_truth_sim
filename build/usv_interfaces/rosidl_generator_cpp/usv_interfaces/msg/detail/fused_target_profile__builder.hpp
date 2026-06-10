// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/FusedTargetProfile.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/fused_target_profile__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_FusedTargetProfile_last_profile_update
{
public:
  explicit Init_FusedTargetProfile_last_profile_update(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::FusedTargetProfile last_profile_update(::usv_interfaces::msg::FusedTargetProfile::_last_profile_update_type arg)
  {
    msg_.last_profile_update = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_first_seen
{
public:
  explicit Init_FusedTargetProfile_first_seen(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_last_profile_update first_seen(::usv_interfaces::msg::FusedTargetProfile::_first_seen_type arg)
  {
    msg_.first_seen = std::move(arg);
    return Init_FusedTargetProfile_last_profile_update(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_matched_mmsi
{
public:
  explicit Init_FusedTargetProfile_matched_mmsi(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_first_seen matched_mmsi(::usv_interfaces::msg::FusedTargetProfile::_matched_mmsi_type arg)
  {
    msg_.matched_mmsi = std::move(arg);
    return Init_FusedTargetProfile_first_seen(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_is_ais_matched
{
public:
  explicit Init_FusedTargetProfile_is_ais_matched(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_matched_mmsi is_ais_matched(::usv_interfaces::msg::FusedTargetProfile::_is_ais_matched_type arg)
  {
    msg_.is_ais_matched = std::move(arg);
    return Init_FusedTargetProfile_matched_mmsi(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_is_dark_target
{
public:
  explicit Init_FusedTargetProfile_is_dark_target(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_is_ais_matched is_dark_target(::usv_interfaces::msg::FusedTargetProfile::_is_dark_target_type arg)
  {
    msg_.is_dark_target = std::move(arg);
    return Init_FusedTargetProfile_is_ais_matched(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_class_confidence
{
public:
  explicit Init_FusedTargetProfile_class_confidence(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_is_dark_target class_confidence(::usv_interfaces::msg::FusedTargetProfile::_class_confidence_type arg)
  {
    msg_.class_confidence = std::move(arg);
    return Init_FusedTargetProfile_is_dark_target(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_class_name
{
public:
  explicit Init_FusedTargetProfile_class_name(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_class_confidence class_name(::usv_interfaces::msg::FusedTargetProfile::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_FusedTargetProfile_class_confidence(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_class_id
{
public:
  explicit Init_FusedTargetProfile_class_id(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_class_name class_id(::usv_interfaces::msg::FusedTargetProfile::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_FusedTargetProfile_class_name(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_size_h
{
public:
  explicit Init_FusedTargetProfile_size_h(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_class_id size_h(::usv_interfaces::msg::FusedTargetProfile::_size_h_type arg)
  {
    msg_.size_h = std::move(arg);
    return Init_FusedTargetProfile_class_id(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_size_l
{
public:
  explicit Init_FusedTargetProfile_size_l(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_size_h size_l(::usv_interfaces::msg::FusedTargetProfile::_size_l_type arg)
  {
    msg_.size_l = std::move(arg);
    return Init_FusedTargetProfile_size_h(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_size_w
{
public:
  explicit Init_FusedTargetProfile_size_w(::usv_interfaces::msg::FusedTargetProfile & msg)
  : msg_(msg)
  {}
  Init_FusedTargetProfile_size_l size_w(::usv_interfaces::msg::FusedTargetProfile::_size_w_type arg)
  {
    msg_.size_w = std::move(arg);
    return Init_FusedTargetProfile_size_l(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

class Init_FusedTargetProfile_target_id
{
public:
  Init_FusedTargetProfile_target_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FusedTargetProfile_size_w target_id(::usv_interfaces::msg::FusedTargetProfile::_target_id_type arg)
  {
    msg_.target_id = std::move(arg);
    return Init_FusedTargetProfile_size_w(msg_);
  }

private:
  ::usv_interfaces::msg::FusedTargetProfile msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::FusedTargetProfile>()
{
  return usv_interfaces::msg::builder::Init_FusedTargetProfile_target_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__BUILDER_HPP_
