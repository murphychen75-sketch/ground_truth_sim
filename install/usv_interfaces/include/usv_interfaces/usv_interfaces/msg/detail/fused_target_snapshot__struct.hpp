// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'state'
#include "usv_interfaces/msg/detail/fused_track_sample__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__FusedTargetSnapshot __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__FusedTargetSnapshot __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FusedTargetSnapshot_
{
  using Type = FusedTargetSnapshot_<ContainerAllocator>;

  explicit FusedTargetSnapshot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_init),
    state(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  explicit FusedTargetSnapshot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_alloc, _init),
    state(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  // field types and members
  using _target_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _target_id_type target_id;
  using _state_type =
    usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>;
  _state_type state;
  using _size_w_type =
    double;
  _size_w_type size_w;
  using _size_l_type =
    double;
  _size_l_type size_l;
  using _size_h_type =
    double;
  _size_h_type size_h;
  using _is_dark_target_type =
    bool;
  _is_dark_target_type is_dark_target;
  using _is_ais_matched_type =
    bool;
  _is_ais_matched_type is_ais_matched;
  using _matched_mmsi_type =
    uint32_t;
  _matched_mmsi_type matched_mmsi;

  // setters for named parameter idiom
  Type & set__target_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__state(
    const usv_interfaces::msg::FusedTrackSample_<ContainerAllocator> & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__size_w(
    const double & _arg)
  {
    this->size_w = _arg;
    return *this;
  }
  Type & set__size_l(
    const double & _arg)
  {
    this->size_l = _arg;
    return *this;
  }
  Type & set__size_h(
    const double & _arg)
  {
    this->size_h = _arg;
    return *this;
  }
  Type & set__is_dark_target(
    const bool & _arg)
  {
    this->is_dark_target = _arg;
    return *this;
  }
  Type & set__is_ais_matched(
    const bool & _arg)
  {
    this->is_ais_matched = _arg;
    return *this;
  }
  Type & set__matched_mmsi(
    const uint32_t & _arg)
  {
    this->matched_mmsi = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__FusedTargetSnapshot
    std::shared_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__FusedTargetSnapshot
    std::shared_ptr<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FusedTargetSnapshot_ & other) const
  {
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->size_w != other.size_w) {
      return false;
    }
    if (this->size_l != other.size_l) {
      return false;
    }
    if (this->size_h != other.size_h) {
      return false;
    }
    if (this->is_dark_target != other.is_dark_target) {
      return false;
    }
    if (this->is_ais_matched != other.is_ais_matched) {
      return false;
    }
    if (this->matched_mmsi != other.matched_mmsi) {
      return false;
    }
    return true;
  }
  bool operator!=(const FusedTargetSnapshot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FusedTargetSnapshot_

// alias to use template instance with default allocator
using FusedTargetSnapshot =
  usv_interfaces::msg::FusedTargetSnapshot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_SNAPSHOT__STRUCT_HPP_
