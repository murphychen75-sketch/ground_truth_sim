// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/FusedTrackSample.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__FusedTrackSample __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__FusedTrackSample __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FusedTrackSample_
{
  using Type = FusedTrackSample_<ContainerAllocator>;

  explicit FusedTrackSample_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t_sec = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      std::fill<typename std::array<double, 16>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  explicit FusedTrackSample_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init),
    covariance(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->t_sec = 0.0;
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      std::fill<typename std::array<double, 16>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _t_sec_type =
    double;
  _t_sec_type t_sec;
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _v_x_type =
    double;
  _v_x_type v_x;
  using _v_y_type =
    double;
  _v_y_type v_y;
  using _covariance_type =
    std::array<double, 16>;
  _covariance_type covariance;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__t_sec(
    const double & _arg)
  {
    this->t_sec = _arg;
    return *this;
  }
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__v_x(
    const double & _arg)
  {
    this->v_x = _arg;
    return *this;
  }
  Type & set__v_y(
    const double & _arg)
  {
    this->v_y = _arg;
    return *this;
  }
  Type & set__covariance(
    const std::array<double, 16> & _arg)
  {
    this->covariance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__FusedTrackSample
    std::shared_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__FusedTrackSample
    std::shared_ptr<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FusedTrackSample_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->t_sec != other.t_sec) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->v_x != other.v_x) {
      return false;
    }
    if (this->v_y != other.v_y) {
      return false;
    }
    if (this->covariance != other.covariance) {
      return false;
    }
    return true;
  }
  bool operator!=(const FusedTrackSample_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FusedTrackSample_

// alias to use template instance with default allocator
using FusedTrackSample =
  usv_interfaces::msg::FusedTrackSample_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TRACK_SAMPLE__STRUCT_HPP_
