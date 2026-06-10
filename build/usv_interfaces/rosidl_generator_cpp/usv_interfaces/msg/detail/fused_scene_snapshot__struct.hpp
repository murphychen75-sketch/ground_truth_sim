// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/FusedSceneSnapshot.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_HPP_

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
// Member 'targets'
#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__FusedSceneSnapshot __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__FusedSceneSnapshot __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FusedSceneSnapshot_
{
  using Type = FusedSceneSnapshot_<ContainerAllocator>;

  explicit FusedSceneSnapshot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit FusedSceneSnapshot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _targets_type =
    std::vector<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>>;
  _targets_type targets;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__targets(
    const std::vector<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<usv_interfaces::msg::FusedTargetSnapshot_<ContainerAllocator>>> & _arg)
  {
    this->targets = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__FusedSceneSnapshot
    std::shared_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__FusedSceneSnapshot
    std::shared_ptr<usv_interfaces::msg::FusedSceneSnapshot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FusedSceneSnapshot_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->targets != other.targets) {
      return false;
    }
    return true;
  }
  bool operator!=(const FusedSceneSnapshot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FusedSceneSnapshot_

// alias to use template instance with default allocator
using FusedSceneSnapshot =
  usv_interfaces::msg::FusedSceneSnapshot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__FUSED_SCENE_SNAPSHOT__STRUCT_HPP_
