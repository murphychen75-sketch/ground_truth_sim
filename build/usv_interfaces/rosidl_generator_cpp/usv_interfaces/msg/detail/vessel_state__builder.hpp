// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:msg/VesselState.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__BUILDER_HPP_
#define USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/msg/detail/vessel_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace msg
{

namespace builder
{

class Init_VesselState_cpu_temperature
{
public:
  explicit Init_VesselState_cpu_temperature(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::msg::VesselState cpu_temperature(::usv_interfaces::msg::VesselState::_cpu_temperature_type arg)
  {
    msg_.cpu_temperature = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_leak_detected
{
public:
  explicit Init_VesselState_leak_detected(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_cpu_temperature leak_detected(::usv_interfaces::msg::VesselState::_leak_detected_type arg)
  {
    msg_.leak_detected = std::move(arg);
    return Init_VesselState_cpu_temperature(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_battery_percentage
{
public:
  explicit Init_VesselState_battery_percentage(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_leak_detected battery_percentage(::usv_interfaces::msg::VesselState::_battery_percentage_type arg)
  {
    msg_.battery_percentage = std::move(arg);
    return Init_VesselState_leak_detected(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_battery_voltage
{
public:
  explicit Init_VesselState_battery_voltage(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_battery_percentage battery_voltage(::usv_interfaces::msg::VesselState::_battery_voltage_type arg)
  {
    msg_.battery_voltage = std::move(arg);
    return Init_VesselState_battery_percentage(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_yaw
{
public:
  explicit Init_VesselState_yaw(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_battery_voltage yaw(::usv_interfaces::msg::VesselState::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_VesselState_battery_voltage(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_pitch
{
public:
  explicit Init_VesselState_pitch(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_yaw pitch(::usv_interfaces::msg::VesselState::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_VesselState_yaw(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_roll
{
public:
  explicit Init_VesselState_roll(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_pitch roll(::usv_interfaces::msg::VesselState::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_VesselState_pitch(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_velocity
{
public:
  explicit Init_VesselState_velocity(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_roll velocity(::usv_interfaces::msg::VesselState::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_VesselState_roll(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_pose
{
public:
  explicit Init_VesselState_pose(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_velocity pose(::usv_interfaces::msg::VesselState::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_VesselState_velocity(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_altitude
{
public:
  explicit Init_VesselState_altitude(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_pose altitude(::usv_interfaces::msg::VesselState::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_VesselState_pose(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_longitude
{
public:
  explicit Init_VesselState_longitude(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_altitude longitude(::usv_interfaces::msg::VesselState::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_VesselState_altitude(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_latitude
{
public:
  explicit Init_VesselState_latitude(::usv_interfaces::msg::VesselState & msg)
  : msg_(msg)
  {}
  Init_VesselState_longitude latitude(::usv_interfaces::msg::VesselState::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_VesselState_longitude(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

class Init_VesselState_header
{
public:
  Init_VesselState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VesselState_latitude header(::usv_interfaces::msg::VesselState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VesselState_latitude(msg_);
  }

private:
  ::usv_interfaces::msg::VesselState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::msg::VesselState>()
{
  return usv_interfaces::msg::builder::Init_VesselState_header();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__MSG__DETAIL__VESSEL_STATE__BUILDER_HPP_
