// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__ControlDeviation __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__ControlDeviation __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ControlDeviation_
{
  using Type = ControlDeviation_<ContainerAllocator>;

  explicit ControlDeviation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cross_track_error = 0.0f;
      this->heading_error = 0.0f;
      this->distance_to_goal = 0.0f;
      this->target_speed = 0.0f;
      this->current_speed = 0.0f;
    }
  }

  explicit ControlDeviation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cross_track_error = 0.0f;
      this->heading_error = 0.0f;
      this->distance_to_goal = 0.0f;
      this->target_speed = 0.0f;
      this->current_speed = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _cross_track_error_type =
    float;
  _cross_track_error_type cross_track_error;
  using _heading_error_type =
    float;
  _heading_error_type heading_error;
  using _distance_to_goal_type =
    float;
  _distance_to_goal_type distance_to_goal;
  using _target_speed_type =
    float;
  _target_speed_type target_speed;
  using _current_speed_type =
    float;
  _current_speed_type current_speed;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__cross_track_error(
    const float & _arg)
  {
    this->cross_track_error = _arg;
    return *this;
  }
  Type & set__heading_error(
    const float & _arg)
  {
    this->heading_error = _arg;
    return *this;
  }
  Type & set__distance_to_goal(
    const float & _arg)
  {
    this->distance_to_goal = _arg;
    return *this;
  }
  Type & set__target_speed(
    const float & _arg)
  {
    this->target_speed = _arg;
    return *this;
  }
  Type & set__current_speed(
    const float & _arg)
  {
    this->current_speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::ControlDeviation_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::ControlDeviation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::ControlDeviation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::ControlDeviation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__ControlDeviation
    std::shared_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__ControlDeviation
    std::shared_ptr<usv_interfaces::msg::ControlDeviation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlDeviation_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->cross_track_error != other.cross_track_error) {
      return false;
    }
    if (this->heading_error != other.heading_error) {
      return false;
    }
    if (this->distance_to_goal != other.distance_to_goal) {
      return false;
    }
    if (this->target_speed != other.target_speed) {
      return false;
    }
    if (this->current_speed != other.current_speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlDeviation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlDeviation_

// alias to use template instance with default allocator
using ControlDeviation =
  usv_interfaces::msg::ControlDeviation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__CONTROL_DEVIATION__STRUCT_HPP_
