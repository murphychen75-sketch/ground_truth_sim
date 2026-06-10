// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/VisionDetection.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/vision_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_VisionDetection_confidence
{
public:
  explicit Init_VisionDetection_confidence(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::VisionDetection confidence(::usv_interfaces::msg::VisionDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_pixel_width
{
public:
  explicit Init_VisionDetection_pixel_width(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_confidence pixel_width(::usv_interfaces::msg::VisionDetection::_pixel_width_type arg)
  {
    msg_.pixel_width = std::move(arg);
    return Init_VisionDetection_confidence(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_size_h
{
public:
  explicit Init_VisionDetection_size_h(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_pixel_width size_h(::usv_interfaces::msg::VisionDetection::_size_h_type arg)
  {
    msg_.size_h = std::move(arg);
    return Init_VisionDetection_pixel_width(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_size_w
{
public:
  explicit Init_VisionDetection_size_w(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_size_h size_w(::usv_interfaces::msg::VisionDetection::_size_w_type arg)
  {
    msg_.size_w = std::move(arg);
    return Init_VisionDetection_size_h(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_distance_predict
{
public:
  explicit Init_VisionDetection_distance_predict(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_size_w distance_predict(::usv_interfaces::msg::VisionDetection::_distance_predict_type arg)
  {
    msg_.distance_predict = std::move(arg);
    return Init_VisionDetection_size_w(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_azimuth
{
public:
  explicit Init_VisionDetection_azimuth(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_distance_predict azimuth(::usv_interfaces::msg::VisionDetection::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_VisionDetection_distance_predict(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_class_id
{
public:
  explicit Init_VisionDetection_class_id(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_azimuth class_id(::usv_interfaces::msg::VisionDetection::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_VisionDetection_azimuth(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_class_name
{
public:
  explicit Init_VisionDetection_class_name(::usv_interfaces::msg::VisionDetection & msg)
  : msg_(msg)
  {}
  Init_VisionDetection_class_id class_name(::usv_interfaces::msg::VisionDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_VisionDetection_class_id(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

class Init_VisionDetection_camera_id
{
public:
  Init_VisionDetection_camera_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionDetection_class_name camera_id(::usv_interfaces::msg::VisionDetection::_camera_id_type arg)
  {
    msg_.camera_id = std::move(arg);
    return Init_VisionDetection_class_name(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::VisionDetection>()
{
  return usv_interfaces::msg::builder::Init_VisionDetection_camera_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__BUILDER_HPP_
