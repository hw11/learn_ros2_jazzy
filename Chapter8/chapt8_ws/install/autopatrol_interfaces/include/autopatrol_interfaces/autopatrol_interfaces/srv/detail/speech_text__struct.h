// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from autopatrol_interfaces:srv/SpeechText.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "autopatrol_interfaces/srv/speech_text.h"


#ifndef AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__STRUCT_H_
#define AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'text'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SpeechText in the package autopatrol_interfaces.
typedef struct autopatrol_interfaces__srv__SpeechText_Request
{
  rosidl_runtime_c__String text;
} autopatrol_interfaces__srv__SpeechText_Request;

// Struct for a sequence of autopatrol_interfaces__srv__SpeechText_Request.
typedef struct autopatrol_interfaces__srv__SpeechText_Request__Sequence
{
  autopatrol_interfaces__srv__SpeechText_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopatrol_interfaces__srv__SpeechText_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/SpeechText in the package autopatrol_interfaces.
typedef struct autopatrol_interfaces__srv__SpeechText_Response
{
  bool result;
} autopatrol_interfaces__srv__SpeechText_Response;

// Struct for a sequence of autopatrol_interfaces__srv__SpeechText_Response.
typedef struct autopatrol_interfaces__srv__SpeechText_Response__Sequence
{
  autopatrol_interfaces__srv__SpeechText_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopatrol_interfaces__srv__SpeechText_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  autopatrol_interfaces__srv__SpeechText_Event__request__MAX_SIZE = 1
};
// response
enum
{
  autopatrol_interfaces__srv__SpeechText_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SpeechText in the package autopatrol_interfaces.
typedef struct autopatrol_interfaces__srv__SpeechText_Event
{
  service_msgs__msg__ServiceEventInfo info;
  autopatrol_interfaces__srv__SpeechText_Request__Sequence request;
  autopatrol_interfaces__srv__SpeechText_Response__Sequence response;
} autopatrol_interfaces__srv__SpeechText_Event;

// Struct for a sequence of autopatrol_interfaces__srv__SpeechText_Event.
typedef struct autopatrol_interfaces__srv__SpeechText_Event__Sequence
{
  autopatrol_interfaces__srv__SpeechText_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} autopatrol_interfaces__srv__SpeechText_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUTOPATROL_INTERFACES__SRV__DETAIL__SPEECH_TEXT__STRUCT_H_
