// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__MmwaveTarget __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__MmwaveTarget __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MmwaveTarget_
{
  using Type = MmwaveTarget_<ContainerAllocator>;

  explicit MmwaveTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radar_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->objmotion_status = 0;
      this->track_id = 0ul;
    }
  }

  explicit MmwaveTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : radar_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radar_id = "";
      this->x = 0.0;
      this->y = 0.0;
      this->v_x = 0.0;
      this->v_y = 0.0;
      this->size_w = 0.0;
      this->size_l = 0.0;
      this->size_h = 0.0;
      this->objmotion_status = 0;
      this->track_id = 0ul;
    }
  }

  // field types and members
  using _radar_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _radar_id_type radar_id;
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
  using _objmotion_status_type =
    uint8_t;
  _objmotion_status_type objmotion_status;
  using _track_id_type =
    uint32_t;
  _track_id_type track_id;

  // setters for named parameter idiom
  Type & set__radar_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->radar_id = _arg;
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
  Type & set__objmotion_status(
    const uint8_t & _arg)
  {
    this->objmotion_status = _arg;
    return *this;
  }
  Type & set__track_id(
    const uint32_t & _arg)
  {
    this->track_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__MmwaveTarget
    std::shared_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__MmwaveTarget
    std::shared_ptr<usv_interfaces::msg::MmwaveTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MmwaveTarget_ & other) const
  {
    if (this->radar_id != other.radar_id) {
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
    if (this->objmotion_status != other.objmotion_status) {
      return false;
    }
    if (this->track_id != other.track_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const MmwaveTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MmwaveTarget_

// alias to use template instance with default allocator
using MmwaveTarget =
  usv_interfaces::msg::MmwaveTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__MMWAVE_TARGET__STRUCT_HPP_
