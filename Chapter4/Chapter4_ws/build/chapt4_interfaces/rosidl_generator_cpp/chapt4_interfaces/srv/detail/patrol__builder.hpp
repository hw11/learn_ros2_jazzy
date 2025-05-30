// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from chapt4_interfaces:srv/Patrol.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "chapt4_interfaces/srv/patrol.hpp"


#ifndef CHAPT4_INTERFACES__SRV__DETAIL__PATROL__BUILDER_HPP_
#define CHAPT4_INTERFACES__SRV__DETAIL__PATROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "chapt4_interfaces/srv/detail/patrol__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace chapt4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Patrol_Request_target_y
{
public:
  explicit Init_Patrol_Request_target_y(::chapt4_interfaces::srv::Patrol_Request & msg)
  : msg_(msg)
  {}
  ::chapt4_interfaces::srv::Patrol_Request target_y(::chapt4_interfaces::srv::Patrol_Request::_target_y_type arg)
  {
    msg_.target_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Request msg_;
};

class Init_Patrol_Request_target_x
{
public:
  Init_Patrol_Request_target_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_Request_target_y target_x(::chapt4_interfaces::srv::Patrol_Request::_target_x_type arg)
  {
    msg_.target_x = std::move(arg);
    return Init_Patrol_Request_target_y(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::chapt4_interfaces::srv::Patrol_Request>()
{
  return chapt4_interfaces::srv::builder::Init_Patrol_Request_target_x();
}

}  // namespace chapt4_interfaces


namespace chapt4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Patrol_Response_result
{
public:
  Init_Patrol_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::chapt4_interfaces::srv::Patrol_Response result(::chapt4_interfaces::srv::Patrol_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::chapt4_interfaces::srv::Patrol_Response>()
{
  return chapt4_interfaces::srv::builder::Init_Patrol_Response_result();
}

}  // namespace chapt4_interfaces


namespace chapt4_interfaces
{

namespace srv
{

namespace builder
{

class Init_Patrol_Event_response
{
public:
  explicit Init_Patrol_Event_response(::chapt4_interfaces::srv::Patrol_Event & msg)
  : msg_(msg)
  {}
  ::chapt4_interfaces::srv::Patrol_Event response(::chapt4_interfaces::srv::Patrol_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Event msg_;
};

class Init_Patrol_Event_request
{
public:
  explicit Init_Patrol_Event_request(::chapt4_interfaces::srv::Patrol_Event & msg)
  : msg_(msg)
  {}
  Init_Patrol_Event_response request(::chapt4_interfaces::srv::Patrol_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_Patrol_Event_response(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Event msg_;
};

class Init_Patrol_Event_info
{
public:
  Init_Patrol_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Patrol_Event_request info(::chapt4_interfaces::srv::Patrol_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_Patrol_Event_request(msg_);
  }

private:
  ::chapt4_interfaces::srv::Patrol_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::chapt4_interfaces::srv::Patrol_Event>()
{
  return chapt4_interfaces::srv::builder::Init_Patrol_Event_info();
}

}  // namespace chapt4_interfaces

#endif  // CHAPT4_INTERFACES__SRV__DETAIL__PATROL__BUILDER_HPP_
