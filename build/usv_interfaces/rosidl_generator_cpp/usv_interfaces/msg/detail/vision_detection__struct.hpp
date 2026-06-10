// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from usv_interfaces:msg/VisionDetection.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_HPP_
#define USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__usv_interfaces__msg__VisionDetection __attribute__((deprecated))
#else
# define DEPRECATED__usv_interfaces__msg__VisionDetection __declspec(deprecated)
#endif

namespace usv_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisionDetection_
{
  using Type = VisionDetection_<ContainerAllocator>;

  explicit VisionDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->camera_id = "";
      this->class_name = "";
      this->class_id = 0l;
      this->azimuth = 0.0;
      this->distance_predict = 0.0;
      this->size_w = 0.0;
      this->size_h = 0.0;
      this->pixel_width = 0.0;
      this->confidence = 0.0;
    }
  }

  explicit VisionDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : camera_id(_alloc),
    class_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->camera_id = "";
      this->class_name = "";
      this->class_id = 0l;
      this->azimuth = 0.0;
      this->distance_predict = 0.0;
      this->size_w = 0.0;
      this->size_h = 0.0;
      this->pixel_width = 0.0;
      this->confidence = 0.0;
    }
  }

  // field types and members
  using _camera_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _camera_id_type camera_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _class_id_type =
    int32_t;
  _class_id_type class_id;
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _distance_predict_type =
    double;
  _distance_predict_type distance_predict;
  using _size_w_type =
    double;
  _size_w_type size_w;
  using _size_h_type =
    double;
  _size_h_type size_h;
  using _pixel_width_type =
    double;
  _pixel_width_type pixel_width;
  using _confidence_type =
    double;
  _confidence_type confidence;

  // setters for named parameter idiom
  Type & set__camera_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->camera_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__class_id(
    const int32_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__distance_predict(
    const double & _arg)
  {
    this->distance_predict = _arg;
    return *this;
  }
  Type & set__size_w(
    const double & _arg)
  {
    this->size_w = _arg;
    return *this;
  }
  Type & set__size_h(
    const double & _arg)
  {
    this->size_h = _arg;
    return *this;
  }
  Type & set__pixel_width(
    const double & _arg)
  {
    this->pixel_width = _arg;
    return *this;
  }
  Type & set__confidence(
    const double & _arg)
  {
    this->confidence = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    usv_interfaces::msg::VisionDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const usv_interfaces::msg::VisionDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::VisionDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      usv_interfaces::msg::VisionDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__usv_interfaces__msg__VisionDetection
    std::shared_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__usv_interfaces__msg__VisionDetection
    std::shared_ptr<usv_interfaces::msg::VisionDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionDetection_ & other) const
  {
    if (this->camera_id != other.camera_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->distance_predict != other.distance_predict) {
      return false;
    }
    if (this->size_w != other.size_w) {
      return false;
    }
    if (this->size_h != other.size_h) {
      return false;
    }
    if (this->pixel_width != other.pixel_width) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionDetection_

// alias to use template instance with default allocator
using VisionDetection =
  usv_interfaces::msg::VisionDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__VISION_DETECTION__STRUCT_HPP_
