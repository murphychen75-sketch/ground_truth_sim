// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from usv_interfaces:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
#define USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "usv_interfaces/action/detail/execute_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Goal_loop_execution
{
public:
  explicit Init_ExecuteMission_Goal_loop_execution(::usv_interfaces::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_Goal loop_execution(::usv_interfaces::action::ExecuteMission_Goal::_loop_execution_type arg)
  {
    msg_.loop_execution = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_forbidden_zone_file
{
public:
  explicit Init_ExecuteMission_Goal_forbidden_zone_file(::usv_interfaces::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_loop_execution forbidden_zone_file(::usv_interfaces::action::ExecuteMission_Goal::_forbidden_zone_file_type arg)
  {
    msg_.forbidden_zone_file = std::move(arg);
    return Init_ExecuteMission_Goal_loop_execution(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_mission_file_name
{
public:
  Init_ExecuteMission_Goal_mission_file_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Goal_forbidden_zone_file mission_file_name(::usv_interfaces::action::ExecuteMission_Goal::_mission_file_name_type arg)
  {
    msg_.mission_file_name = std::move(arg);
    return Init_ExecuteMission_Goal_forbidden_zone_file(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_Goal>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_Goal_mission_file_name();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Result_message
{
public:
  explicit Init_ExecuteMission_Result_message(::usv_interfaces::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_Result message(::usv_interfaces::action::ExecuteMission_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_success
{
public:
  Init_ExecuteMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Result_message success(::usv_interfaces::action::ExecuteMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteMission_Result_message(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_Result>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_Result_success();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Feedback_status_text
{
public:
  explicit Init_ExecuteMission_Feedback_status_text(::usv_interfaces::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_Feedback status_text(::usv_interfaces::action::ExecuteMission_Feedback::_status_text_type arg)
  {
    msg_.status_text = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_mission_progress
{
public:
  explicit Init_ExecuteMission_Feedback_mission_progress(::usv_interfaces::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_status_text mission_progress(::usv_interfaces::action::ExecuteMission_Feedback::_mission_progress_type arg)
  {
    msg_.mission_progress = std::move(arg);
    return Init_ExecuteMission_Feedback_status_text(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_waypoint_index
{
public:
  explicit Init_ExecuteMission_Feedback_current_waypoint_index(::usv_interfaces::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_mission_progress current_waypoint_index(::usv_interfaces::action::ExecuteMission_Feedback::_current_waypoint_index_type arg)
  {
    msg_.current_waypoint_index = std::move(arg);
    return Init_ExecuteMission_Feedback_mission_progress(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_task_name
{
public:
  Init_ExecuteMission_Feedback_current_task_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Feedback_current_waypoint_index current_task_name(::usv_interfaces::action::ExecuteMission_Feedback::_current_task_name_type arg)
  {
    msg_.current_task_name = std::move(arg);
    return Init_ExecuteMission_Feedback_current_waypoint_index(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_Feedback>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_Feedback_current_task_name();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteMission_SendGoal_Request_goal(::usv_interfaces::action::ExecuteMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_SendGoal_Request goal(::usv_interfaces::action::ExecuteMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_SendGoal_Request msg_;
};

class Init_ExecuteMission_SendGoal_Request_goal_id
{
public:
  Init_ExecuteMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Request_goal goal_id(::usv_interfaces::action::ExecuteMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_SendGoal_Request_goal(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_SendGoal_Request>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_SendGoal_Request_goal_id();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteMission_SendGoal_Response_stamp(::usv_interfaces::action::ExecuteMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_SendGoal_Response stamp(::usv_interfaces::action::ExecuteMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_SendGoal_Response msg_;
};

class Init_ExecuteMission_SendGoal_Response_accepted
{
public:
  Init_ExecuteMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Response_stamp accepted(::usv_interfaces::action::ExecuteMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_SendGoal_Response>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_SendGoal_Response_accepted();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Request_goal_id
{
public:
  Init_ExecuteMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::usv_interfaces::action::ExecuteMission_GetResult_Request goal_id(::usv_interfaces::action::ExecuteMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_GetResult_Request>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_GetResult_Request_goal_id();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Response_result
{
public:
  explicit Init_ExecuteMission_GetResult_Response_result(::usv_interfaces::action::ExecuteMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_GetResult_Response result(::usv_interfaces::action::ExecuteMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_GetResult_Response msg_;
};

class Init_ExecuteMission_GetResult_Response_status
{
public:
  Init_ExecuteMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Response_result status(::usv_interfaces::action::ExecuteMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteMission_GetResult_Response_result(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_GetResult_Response>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_GetResult_Response_status();
}

}  // namespace usv_interfaces


namespace usv_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteMission_FeedbackMessage_feedback(::usv_interfaces::action::ExecuteMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::usv_interfaces::action::ExecuteMission_FeedbackMessage feedback(::usv_interfaces::action::ExecuteMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_FeedbackMessage msg_;
};

class Init_ExecuteMission_FeedbackMessage_goal_id
{
public:
  Init_ExecuteMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_FeedbackMessage_feedback goal_id(::usv_interfaces::action::ExecuteMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::usv_interfaces::action::ExecuteMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::usv_interfaces::action::ExecuteMission_FeedbackMessage>()
{
  return usv_interfaces::action::builder::Init_ExecuteMission_FeedbackMessage_goal_id();
}

}  // namespace usv_interfaces

#endif  // USV_INTERFACES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
