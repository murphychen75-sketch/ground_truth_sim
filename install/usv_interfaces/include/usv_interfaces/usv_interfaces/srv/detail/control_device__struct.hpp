// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:srv/ControlDevice.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_HPP_
#define USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__srv__ControlDevice_Request __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__srv__ControlDevice_Request __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ControlDevice_Request_
{
  using Type = ControlDevice_Request_<ContainerAllocator>;

  explicit ControlDevice_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->command = "";
      this->value = 0.0f;
    }
  }

  explicit ControlDevice_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : device_id(_alloc),
    command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->device_id = "";
      this->command = "";
      this->value = 0.0f;
    }
  }

  // field types and members
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _value_type =
    float;
  _value_type value;

  // setters for named parameter idiom
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__value(
    const float & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__srv__ControlDevice_Request
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__srv__ControlDevice_Request
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlDevice_Request_ & other) const
  {
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->command != other.command) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlDevice_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlDevice_Request_

// alias to use template instance with default allocator
using ControlDevice_Request =
  usv_interfaces::srv::ControlDevice_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace usv_interfaces


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__srv__ControlDevice_Response __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__srv__ControlDevice_Response __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ControlDevice_Response_
{
  using Type = ControlDevice_Response_<ContainerAllocator>;

  explicit ControlDevice_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit ControlDevice_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__srv__ControlDevice_Response
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__srv__ControlDevice_Response
    std::shared_ptr<usv_interfaces::srv::ControlDevice_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ControlDevice_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const ControlDevice_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ControlDevice_Response_

// alias to use template instance with default allocator
using ControlDevice_Response =
  usv_interfaces::srv::ControlDevice_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace usv_interfaces

namespace usv_interfaces
{

namespace srv
{

struct ControlDevice
{
  using Request = usv_interfaces::srv::ControlDevice_Request;
  using Response = usv_interfaces::srv::ControlDevice_Response;
};

}  // namespace srv

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__SRV__DETAIL__CONTROL_DEVICE__STRUCT_HPP_
