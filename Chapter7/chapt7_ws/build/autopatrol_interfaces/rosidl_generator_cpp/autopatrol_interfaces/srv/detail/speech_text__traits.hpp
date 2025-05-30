// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autopatrol_interfaces:srv/SpeechText.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "autopatrol_interfaces/srv/speech_text.hpp"


#ifndef AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__TRAITS_HPP_
#define AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autopatrol_interfaces/srv/detail/speech_text__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autopatrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SpeechText_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: text
  {
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpeechText_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "text: ";
    rosidl_generator_traits::value_to_yaml(msg.text, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpeechText_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace autopatrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use autopatrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopatrol_interfaces::srv::SpeechText_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopatrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopatrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const autopatrol_interfaces::srv::SpeechText_Request & msg)
{
  return autopatrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<autopatrol_interfaces::srv::SpeechText_Request>()
{
  return "autopatrol_interfaces::srv::SpeechText_Request";
}

template<>
inline const char * name<autopatrol_interfaces::srv::SpeechText_Request>()
{
  return "autopatrol_interfaces/srv/SpeechText_Request";
}

template<>
struct has_fixed_size<autopatrol_interfaces::srv::SpeechText_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<autopatrol_interfaces::srv::SpeechText_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<autopatrol_interfaces::srv::SpeechText_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace autopatrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SpeechText_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpeechText_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpeechText_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace autopatrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use autopatrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopatrol_interfaces::srv::SpeechText_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopatrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopatrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const autopatrol_interfaces::srv::SpeechText_Response & msg)
{
  return autopatrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<autopatrol_interfaces::srv::SpeechText_Response>()
{
  return "autopatrol_interfaces::srv::SpeechText_Response";
}

template<>
inline const char * name<autopatrol_interfaces::srv::SpeechText_Response>()
{
  return "autopatrol_interfaces/srv/SpeechText_Response";
}

template<>
struct has_fixed_size<autopatrol_interfaces::srv::SpeechText_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autopatrol_interfaces::srv::SpeechText_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autopatrol_interfaces::srv::SpeechText_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace autopatrol_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SpeechText_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpeechText_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpeechText_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace autopatrol_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use autopatrol_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopatrol_interfaces::srv::SpeechText_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopatrol_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopatrol_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const autopatrol_interfaces::srv::SpeechText_Event & msg)
{
  return autopatrol_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<autopatrol_interfaces::srv::SpeechText_Event>()
{
  return "autopatrol_interfaces::srv::SpeechText_Event";
}

template<>
inline const char * name<autopatrol_interfaces::srv::SpeechText_Event>()
{
  return "autopatrol_interfaces/srv/SpeechText_Event";
}

template<>
struct has_fixed_size<autopatrol_interfaces::srv::SpeechText_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<autopatrol_interfaces::srv::SpeechText_Event>
  : std::integral_constant<bool, has_bounded_size<autopatrol_interfaces::srv::SpeechText_Request>::value && has_bounded_size<autopatrol_interfaces::srv::SpeechText_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<autopatrol_interfaces::srv::SpeechText_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<autopatrol_interfaces::srv::SpeechText>()
{
  return "autopatrol_interfaces::srv::SpeechText";
}

template<>
inline const char * name<autopatrol_interfaces::srv::SpeechText>()
{
  return "autopatrol_interfaces/srv/SpeechText";
}

template<>
struct has_fixed_size<autopatrol_interfaces::srv::SpeechText>
  : std::integral_constant<
    bool,
    has_fixed_size<autopatrol_interfaces::srv::SpeechText_Request>::value &&
    has_fixed_size<autopatrol_interfaces::srv::SpeechText_Response>::value
  >
{
};

template<>
struct has_bounded_size<autopatrol_interfaces::srv::SpeechText>
  : std::integral_constant<
    bool,
    has_bounded_size<autopatrol_interfaces::srv::SpeechText_Request>::value &&
    has_bounded_size<autopatrol_interfaces::srv::SpeechText_Response>::value
  >
{
};

template<>
struct is_service<autopatrol_interfaces::srv::SpeechText>
  : std::true_type
{
};

template<>
struct is_service_request<autopatrol_interfaces::srv::SpeechText_Request>
  : std::true_type
{
};

template<>
struct is_service_response<autopatrol_interfaces::srv::SpeechText_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__TRAITS_HPP_
