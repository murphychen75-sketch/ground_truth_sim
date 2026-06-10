// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from usv_interfaces:msg/FusedSceneSnapshot.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "usv_interfaces/msg/detail/fused_scene_snapshot__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace usv_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void FusedSceneSnapshot_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) usv_interfaces::msg::FusedSceneSnapshot(_init);
}

void FusedSceneSnapshot_fini_function(void * message_memory)
{
  auto typed_message = static_cast<usv_interfaces::msg::FusedSceneSnapshot *>(message_memory);
  typed_message->~FusedSceneSnapshot();
}

size_t size_function__FusedSceneSnapshot__targets(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<usv_interfaces::msg::FusedTargetSnapshot> *>(untyped_member);
  return member->size();
}

const void * get_const_function__FusedSceneSnapshot__targets(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<usv_interfaces::msg::FusedTargetSnapshot> *>(untyped_member);
  return &member[index];
}

void * get_function__FusedSceneSnapshot__targets(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<usv_interfaces::msg::FusedTargetSnapshot> *>(untyped_member);
  return &member[index];
}

void fetch_function__FusedSceneSnapshot__targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const usv_interfaces::msg::FusedTargetSnapshot *>(
    get_const_function__FusedSceneSnapshot__targets(untyped_member, index));
  auto & value = *reinterpret_cast<usv_interfaces::msg::FusedTargetSnapshot *>(untyped_value);
  value = item;
}

void assign_function__FusedSceneSnapshot__targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<usv_interfaces::msg::FusedTargetSnapshot *>(
    get_function__FusedSceneSnapshot__targets(untyped_member, index));
  const auto & value = *reinterpret_cast<const usv_interfaces::msg::FusedTargetSnapshot *>(untyped_value);
  item = value;
}

void resize_function__FusedSceneSnapshot__targets(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<usv_interfaces::msg::FusedTargetSnapshot> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember FusedSceneSnapshot_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces::msg::FusedSceneSnapshot, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "targets",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<usv_interfaces::msg::FusedTargetSnapshot>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces::msg::FusedSceneSnapshot, targets),  // bytes offset in struct
    nullptr,  // default value
    size_function__FusedSceneSnapshot__targets,  // size() function pointer
    get_const_function__FusedSceneSnapshot__targets,  // get_const(index) function pointer
    get_function__FusedSceneSnapshot__targets,  // get(index) function pointer
    fetch_function__FusedSceneSnapshot__targets,  // fetch(index, &value) function pointer
    assign_function__FusedSceneSnapshot__targets,  // assign(index, value) function pointer
    resize_function__FusedSceneSnapshot__targets  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers FusedSceneSnapshot_message_members = {
  "usv_interfaces::msg",  // message namespace
  "FusedSceneSnapshot",  // message name
  2,  // number of fields
  sizeof(usv_interfaces::msg::FusedSceneSnapshot),
  FusedSceneSnapshot_message_member_array,  // message members
  FusedSceneSnapshot_init_function,  // function to initialize message memory (memory has to be allocated)
  FusedSceneSnapshot_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t FusedSceneSnapshot_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &FusedSceneSnapshot_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace usv_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<usv_interfaces::msg::FusedSceneSnapshot>()
{
  return &::usv_interfaces::msg::rosidl_typesupport_introspection_cpp::FusedSceneSnapshot_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, usv_interfaces, msg, FusedSceneSnapshot)() {
  return &::usv_interfaces::msg::rosidl_typesupport_introspection_cpp::FusedSceneSnapshot_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
