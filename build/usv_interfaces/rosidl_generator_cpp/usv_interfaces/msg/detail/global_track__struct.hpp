// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/GlobalTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__GlobalTrack __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__GlobalTrack __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct GlobalTrack_
{
  using Type = GlobalTrack_<ContainerAllocator>;

  explicit GlobalTrack_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->track_id = 0ul;
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      std::fill<typename std::array<double, 16>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  explicit GlobalTrack_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : covariance(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->track_id = 0ul;
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      std::fill<typename std::array<double, 16>::iterator, double>(this->covariance.begin(), this->covariance.end(), 0.0);
      this->is_dark_target = false;
      this->is_ais_matched = false;
      this->matched_mmsi = 0ul;
    }
  }

  // field types and members
  using _track_id_type =
    uint32_t;
  _track_id_type track_id;
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
  using _size_w_type =
    double;
  _size_w_type size_w;
  using _size_l_type =
    double;
  _size_l_type size_l;
  using _size_h_type =
    double;
  _size_h_type size_h;
  using _covariance_type =
    std::array<double, 16>;
  _covariance_type covariance;
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
  Type & set__track_id(
    const uint32_t & _arg)
  {
    this->track_id = _arg;
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
  Type & set__covariance(
    const std::array<double, 16> & _arg)
  {
    this->covariance = _arg;
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
    usv_interfaces::msg::GlobalTrack_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::GlobalTrack_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::GlobalTrack_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::GlobalTrack_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__GlobalTrack
    std::shared_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__GlobalTrack
    std::shared_ptr<usv_interfaces::msg::GlobalTrack_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GlobalTrack_ & other) const
  {
    if (this->track_id != other.track_id) {
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
    if (this->size_w != other.size_w) {
      return false;
    }
    if (this->size_l != other.size_l) {
      return false;
    }
    if (this->size_h != other.size_h) {
      return false;
    }
    if (this->covariance != other.covariance) {
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
  bool operator!=(const GlobalTrack_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GlobalTrack_

// alias to use template instance with default allocator
using GlobalTrack =
  usv_interfaces::msg::GlobalTrack_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__GLOBAL_TRACK__STRUCT_HPP_
