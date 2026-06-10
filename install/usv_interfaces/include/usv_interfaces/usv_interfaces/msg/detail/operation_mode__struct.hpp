// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/OperationMode.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_HPP_

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
# define DEPRECATED__usv_interfaces__msg__OperationMode __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__OperationMode __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OperationMode_
{
  using Type = OperationMode_<ContainerAllocator>;

  explicit OperationMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit OperationMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mode_type =
    uint8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t MODE_MANUAL =
    0u;
  static constexpr uint8_t MODE_AUTO_HEADING =
    1u;
  static constexpr uint8_t MODE_SMART_PATH =
    2u;
  static constexpr uint8_t MODE_AUTO_NAV =
    3u;

  // pointer types
  using RawPtr =
    usv_interfaces::msg::OperationMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::OperationMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::OperationMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::OperationMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__OperationMode
    std::shared_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__OperationMode
    std::shared_ptr<usv_interfaces::msg::OperationMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OperationMode_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const OperationMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OperationMode_

// alias to use template instance with default allocator
using OperationMode =
  usv_interfaces::msg::OperationMode_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OperationMode_<ContainerAllocator>::MODE_MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OperationMode_<ContainerAllocator>::MODE_AUTO_HEADING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OperationMode_<ContainerAllocator>::MODE_SMART_PATH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OperationMode_<ContainerAllocator>::MODE_AUTO_NAV;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__OPERATION_MODE__STRUCT_HPP_
