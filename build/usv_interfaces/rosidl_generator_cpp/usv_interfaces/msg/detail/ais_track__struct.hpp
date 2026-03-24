// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/AISTrack.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__AISTrack __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__AISTrack __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AISTrack_
{
  using Type = AISTrack_<ContainerAllocator>;

  explicit AISTrack_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mmsi = 0ul;
      this->ship_name = "";
      this->relative_x = 0.0;
      this->relative_y = 0.0;
      this->relative_v_x = 0.0;
      this->relative_v_y = 0.0;
      this->true_heading = 0.0;
    }
  }

  explicit AISTrack_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : ship_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mmsi = 0ul;
      this->ship_name = "";
      this->relative_x = 0.0;
      this->relative_y = 0.0;
      this->relative_v_x = 0.0;
      this->relative_v_y = 0.0;
      this->true_heading = 0.0;
    }
  }

  // field types and members
  using _mmsi_type =
    uint32_t;
  _mmsi_type mmsi;
  using _ship_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ship_name_type ship_name;
  using _relative_x_type =
    double;
  _relative_x_type relative_x;
  using _relative_y_type =
    double;
  _relative_y_type relative_y;
  using _relative_v_x_type =
    double;
  _relative_v_x_type relative_v_x;
  using _relative_v_y_type =
    double;
  _relative_v_y_type relative_v_y;
  using _true_heading_type =
    double;
  _true_heading_type true_heading;

  // setters for named parameter idiom
  Type & set__mmsi(
    const uint32_t & _arg)
  {
    this->mmsi = _arg;
    return *this;
  }
  Type & set__ship_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ship_name = _arg;
    return *this;
  }
  Type & set__relative_x(
    const double & _arg)
  {
    this->relative_x = _arg;
    return *this;
  }
  Type & set__relative_y(
    const double & _arg)
  {
    this->relative_y = _arg;
    return *this;
  }
  Type & set__relative_v_x(
    const double & _arg)
  {
    this->relative_v_x = _arg;
    return *this;
  }
  Type & set__relative_v_y(
    const double & _arg)
  {
    this->relative_v_y = _arg;
    return *this;
  }
  Type & set__true_heading(
    const double & _arg)
  {
    this->true_heading = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::AISTrack_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::AISTrack_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::AISTrack_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::AISTrack_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__AISTrack
    std::shared_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__AISTrack
    std::shared_ptr<usv_interfaces::msg::AISTrack_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AISTrack_ & other) const
  {
    if (this->mmsi != other.mmsi) {
      return false;
    }
    if (this->ship_name != other.ship_name) {
      return false;
    }
    if (this->relative_x != other.relative_x) {
      return false;
    }
    if (this->relative_y != other.relative_y) {
      return false;
    }
    if (this->relative_v_x != other.relative_v_x) {
      return false;
    }
    if (this->relative_v_y != other.relative_v_y) {
      return false;
    }
    if (this->true_heading != other.true_heading) {
      return false;
    }
    return true;
  }
  bool operator!=(const AISTrack_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AISTrack_

// alias to use template instance with default allocator
using AISTrack =
  usv_interfaces::msg::AISTrack_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK__STRUCT_HPP_
