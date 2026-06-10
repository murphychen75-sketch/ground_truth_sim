// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/FusedTargetProfile.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_HPP_

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
// Member 'first_seen'
// Member 'last_profile_update'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__FusedTargetProfile __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__FusedTargetProfile __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FusedTargetProfile_
{
  using Type = FusedTargetProfile_<ContainerAllocator>;

  explicit FusedTargetProfile_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_init),
    first_seen(_init),
    last_profile_update(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->class_id = 0l;
      this->class_name = "";
      this->class_confidence = 0.0;
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  explicit FusedTargetProfile_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_alloc, _init),
    class_name(_alloc),
    first_seen(_alloc, _init),
    last_profile_update(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->class_id = 0l;
      this->class_name = "";
      this->class_confidence = 0.0;
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  // field types and members
  using _target_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _target_id_type target_id;
  using _size_w_type =
    double;
  _size_w_type size_w;
  using _size_l_type =
    double;
  _size_l_type size_l;
  using _size_h_type =
    double;
  _size_h_type size_h;
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _class_confidence_type =
    double;
  _class_confidence_type class_confidence;
  using _is_dark_target_type =
    bool;
  _is_dark_target_type is_dark_target;
  using _is_ais_matched_type =
    bool;
  _is_ais_matched_type is_ais_matched;
  using _matched_mmsi_type =
    uint32_t;
  _matched_mmsi_type matched_mmsi;
  using _first_seen_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _first_seen_type first_seen;
  using _last_profile_update_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _last_profile_update_type last_profile_update;

  // setters for named parameter idiom
  Type & set__target_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->target_id = _arg;
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
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__class_confidence(
    const double & _arg)
  {
    this->class_confidence = _arg;
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
  Type & set__first_seen(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->first_seen = _arg;
    return *this;
  }
  Type & set__last_profile_update(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->last_profile_update = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__FusedTargetProfile
    std::shared_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__FusedTargetProfile
    std::shared_ptr<usv_interfaces::msg::FusedTargetProfile_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FusedTargetProfile_ & other) const
  {
    if (this->target_id != other.target_id) {
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
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->class_confidence != other.class_confidence) {
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
    if (this->first_seen != other.first_seen) {
      return false;
    }
    if (this->last_profile_update != other.last_profile_update) {
      return false;
    }
    return true;
  }
  bool operator!=(const FusedTargetProfile_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FusedTargetProfile_

// alias to use template instance with default allocator
using FusedTargetProfile =
  usv_interfaces::msg::FusedTargetProfile_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_TARGET_PROFILE__STRUCT_HPP_
