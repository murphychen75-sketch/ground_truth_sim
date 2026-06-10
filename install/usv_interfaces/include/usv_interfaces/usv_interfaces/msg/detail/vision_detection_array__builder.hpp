// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/VisionDetectionArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/vision_detection_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_VisionDetectionArray_detections
{
public:
  explicit Init_VisionDetectionArray_detections(::usv_interfaces::msg::VisionDetectionArray & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::VisionDetectionArray detections(::usv_interfaces::msg::VisionDetectionArray::_detections_type arg)
  {
    msg_.detections = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetectionArray msg_;
};

class Init_VisionDetectionArray_output_stamp
{
public:
  explicit Init_VisionDetectionArray_output_stamp(::usv_interfaces::msg::VisionDetectionArray & msg)
  : msg_(msg)
  {}
  Init_VisionDetectionArray_detections output_stamp(::usv_interfaces::msg::VisionDetectionArray::_output_stamp_type arg)
  {
    msg_.output_stamp = std::move(arg);
    return Init_VisionDetectionArray_detections(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetectionArray msg_;
};

class Init_VisionDetectionArray_header
{
public:
  Init_VisionDetectionArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionDetectionArray_output_stamp header(::usv_interfaces::msg::VisionDetectionArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VisionDetectionArray_output_stamp(msg_);
  }

private:
  ::usv_interfaces::msg::VisionDetectionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::VisionDetectionArray>()
{
  return usv_interfaces::msg::builder::Init_VisionDetectionArray_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION_ARRAY__BUILDER_HPP_
