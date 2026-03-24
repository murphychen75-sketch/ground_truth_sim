// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/NavRadarTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__NavRadarTarget __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__NavRadarTarget __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NavRadarTarget_
{
  using Type = NavRadarTarget_<ContainerAllocator>;

  explicit NavRadarTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->area = 0.0;
    }
  }

  explicit NavRadarTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->area = 0.0;
    }
  }

  // field types and members
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
  using _area_type =
    double;
  _area_type area;

  // setters for named parameter idiom
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
  Type & set__area(
    const double & _arg)
  {
    this->area = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__NavRadarTarget
    std::shared_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__NavRadarTarget
    std::shared_ptr<usv_interfaces::msg::NavRadarTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NavRadarTarget_ & other) const
  {
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
    if (this->area != other.area) {
      return false;
    }
    return true;
  }
  bool operator!=(const NavRadarTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NavRadarTarget_

// alias to use template instance with default allocator
using NavRadarTarget =
  usv_interfaces::msg::NavRadarTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__NAV_RADAR_TARGET__STRUCT_HPP_
