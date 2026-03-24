// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from usv_interfaces:msg/OperationMode.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "usv_interfaces/msg/detail/operation_mode__struct.hpp"
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

void OperationMode_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) usv_interfaces::msg::OperationMode(_init);
}

void OperationMode_fini_function(void * message_memory)
{
  auto typed_message = static_cast<usv_interfaces::msg::OperationMode *>(message_memory);
  typed_message->~OperationMode();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember OperationMode_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces::msg::OperationMode, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(usv_interfaces::msg::OperationMode, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers OperationMode_message_members = {
  "usv_interfaces::msg",  // message namespace
  "OperationMode",  // message name
  2,  // number of fields
  sizeof(usv_interfaces::msg::OperationMode),
  OperationMode_message_member_array,  // message members
  OperationMode_init_function,  // function to initialize message memory (memory has to be allocated)
  OperationMode_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t OperationMode_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &OperationMode_message_members,
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
get_message_type_support_handle<usv_interfaces::msg::OperationMode>()
{
  return &::usv_interfaces::msg::rosidl_typesupport_introspection_cpp::OperationMode_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, usv_interfaces, msg, OperationMode)() {
  return &::usv_interfaces::msg::rosidl_typesupport_introspection_cpp::OperationMode_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
