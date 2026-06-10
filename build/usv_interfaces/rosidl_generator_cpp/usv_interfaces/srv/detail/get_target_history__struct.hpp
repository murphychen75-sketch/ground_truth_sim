// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:srv/GetTargetHistory.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_HPP_
#define USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_HPP_

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
// Member 't_start'
// Member 't_end'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__srv__GetTargetHistory_Request __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__srv__GetTargetHistory_Request __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTargetHistory_Request_
{
  using Type = GetTargetHistory_Request_<ContainerAllocator>;

  explicit GetTargetHistory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_init),
    t_start(_init),
    t_end(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_samples = 0ul;
    }
  }

  explicit GetTargetHistory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_id(_alloc, _init),
    t_start(_alloc, _init),
    t_end(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max_samples = 0ul;
    }
  }

  // field types and members
  using _target_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _target_id_type target_id;
  using _t_start_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _t_start_type t_start;
  using _t_end_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _t_end_type t_end;
  using _max_samples_type =
    uint32_t;
  _max_samples_type max_samples;

  // setters for named parameter idiom
  Type & set__target_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->target_id = _arg;
    return *this;
  }
  Type & set__t_start(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->t_start = _arg;
    return *this;
  }
  Type & set__t_end(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->t_end = _arg;
    return *this;
  }
  Type & set__max_samples(
    const uint32_t & _arg)
  {
    this->max_samples = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__srv__GetTargetHistory_Request
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__srv__GetTargetHistory_Request
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTargetHistory_Request_ & other) const
  {
    if (this->target_id != other.target_id) {
      return false;
    }
    if (this->t_start != other.t_start) {
      return false;
    }
    if (this->t_end != other.t_end) {
      return false;
    }
    if (this->max_samples != other.max_samples) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTargetHistory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTargetHistory_Request_

// alias to use template instance with default allocator
using GetTargetHistory_Request =
  usv_interfaces::srv::GetTargetHistory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace usv_interfaces


// Include directives for member types
// Member 'samples'
#include "usv_interfaces/msg/detail/fused_track_sample__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__usv_interfaces__srv__GetTargetHistory_Response __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__srv__GetTargetHistory_Response __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTargetHistory_Response_
{
  using Type = GetTargetHistory_Response_<ContainerAllocator>;

  explicit GetTargetHistory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
    }
  }

  explicit GetTargetHistory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
    }
  }

  // field types and members
  using _status_type =
    int32_t;
  _status_type status;
  using _samples_type =
    std::vector<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>>;
  _samples_type samples;

  // setters for named parameter idiom
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__samples(
    const std::vector<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<usv_interfaces::msg::FusedTrackSample_<ContainerAllocator>>> & _arg)
  {
    this->samples = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__srv__GetTargetHistory_Response
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__srv__GetTargetHistory_Response
    std::shared_ptr<usv_interfaces::srv::GetTargetHistory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTargetHistory_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->samples != other.samples) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTargetHistory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTargetHistory_Response_

// alias to use template instance with default allocator
using GetTargetHistory_Response =
  usv_interfaces::srv::GetTargetHistory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace usv_interfaces

namespace usv_interfaces
{

namespace srv
{

struct GetTargetHistory
{
  using Request = usv_interfaces::srv::GetTargetHistory_Request;
  using Response = usv_interfaces::srv::GetTargetHistory_Response;
};

}  // namespace srv

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__SRV__DETAIL__GET_TARGET_HISTORY__STRUCT_HPP_
