// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from chapt4_interfaces:srv/Patrol.idl
// generated code does not contain a copyright notice

#include "chapt4_interfaces/srv/detail/patrol__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x74, 0x23, 0x98, 0x7b, 0xee, 0x9e, 0xd1, 0xed,
      0x58, 0xda, 0xab, 0xc8, 0x8b, 0x15, 0xce, 0xf8,
      0xff, 0x22, 0x58, 0x08, 0xaa, 0x80, 0x54, 0x57,
      0x85, 0x2a, 0x43, 0x57, 0x24, 0xf6, 0xb8, 0xf6,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x64, 0xf1, 0xf4, 0xa6, 0x5a, 0xa9, 0x6f, 0xf9,
      0x99, 0xcd, 0x53, 0xcf, 0x94, 0xa7, 0x50, 0x2e,
      0x45, 0xcf, 0x87, 0xcd, 0x43, 0xa2, 0x70, 0x70,
      0xf8, 0x01, 0x81, 0x39, 0xd5, 0x62, 0x98, 0x40,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe1, 0xa1, 0x50, 0x38, 0xcc, 0x97, 0x72, 0x88,
      0x3b, 0x2c, 0x87, 0x7c, 0xaf, 0x4f, 0x8d, 0x4f,
      0x0e, 0x96, 0x6b, 0x17, 0x72, 0x0a, 0xe7, 0x72,
      0x99, 0x0c, 0x69, 0x6d, 0x28, 0xae, 0x0a, 0x3b,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x3f, 0x33, 0xfa, 0xdb, 0xc3, 0x74, 0x24, 0xda,
      0xe0, 0xc9, 0x7b, 0xfe, 0x2c, 0x9c, 0xa0, 0xdc,
      0x56, 0xd3, 0xfb, 0x28, 0x72, 0x48, 0x9b, 0x31,
      0x15, 0xfc, 0x7b, 0xeb, 0x68, 0xbf, 0xd5, 0x83,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char chapt4_interfaces__srv__Patrol__TYPE_NAME[] = "chapt4_interfaces/srv/Patrol";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char chapt4_interfaces__srv__Patrol_Event__TYPE_NAME[] = "chapt4_interfaces/srv/Patrol_Event";
static char chapt4_interfaces__srv__Patrol_Request__TYPE_NAME[] = "chapt4_interfaces/srv/Patrol_Request";
static char chapt4_interfaces__srv__Patrol_Response__TYPE_NAME[] = "chapt4_interfaces/srv/Patrol_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char chapt4_interfaces__srv__Patrol__FIELD_NAME__request_message[] = "request_message";
static char chapt4_interfaces__srv__Patrol__FIELD_NAME__response_message[] = "response_message";
static char chapt4_interfaces__srv__Patrol__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field chapt4_interfaces__srv__Patrol__FIELDS[] = {
  {
    {chapt4_interfaces__srv__Patrol__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {chapt4_interfaces__srv__Patrol_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription chapt4_interfaces__srv__Patrol__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {chapt4_interfaces__srv__Patrol__TYPE_NAME, 28, 28},
      {chapt4_interfaces__srv__Patrol__FIELDS, 3, 3},
    },
    {chapt4_interfaces__srv__Patrol__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = chapt4_interfaces__srv__Patrol_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = chapt4_interfaces__srv__Patrol_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = chapt4_interfaces__srv__Patrol_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char chapt4_interfaces__srv__Patrol_Request__FIELD_NAME__target_x[] = "target_x";
static char chapt4_interfaces__srv__Patrol_Request__FIELD_NAME__target_y[] = "target_y";

static rosidl_runtime_c__type_description__Field chapt4_interfaces__srv__Patrol_Request__FIELDS[] = {
  {
    {chapt4_interfaces__srv__Patrol_Request__FIELD_NAME__target_x, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Request__FIELD_NAME__target_y, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
      {chapt4_interfaces__srv__Patrol_Request__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char chapt4_interfaces__srv__Patrol_Response__FIELD_NAME__result[] = "result";

static rosidl_runtime_c__type_description__Field chapt4_interfaces__srv__Patrol_Response__FIELDS[] = {
  {
    {chapt4_interfaces__srv__Patrol_Response__FIELD_NAME__result, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
      {chapt4_interfaces__srv__Patrol_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__info[] = "info";
static char chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__request[] = "request";
static char chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field chapt4_interfaces__srv__Patrol_Event__FIELDS[] = {
  {
    {chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription chapt4_interfaces__srv__Patrol_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {chapt4_interfaces__srv__Patrol_Event__TYPE_NAME, 34, 34},
      {chapt4_interfaces__srv__Patrol_Event__FIELDS, 3, 3},
    },
    {chapt4_interfaces__srv__Patrol_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = chapt4_interfaces__srv__Patrol_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = chapt4_interfaces__srv__Patrol_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 target_x\n"
  "float32 target_y\n"
  "---\n"
  "int8 SUCCESS=1\n"
  "int8 FAIL=0\n"
  "int8 result  #SUCCESS/FAIL";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {chapt4_interfaces__srv__Patrol__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 91, 91},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {chapt4_interfaces__srv__Patrol_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {chapt4_interfaces__srv__Patrol_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {chapt4_interfaces__srv__Patrol_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *chapt4_interfaces__srv__Patrol__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *chapt4_interfaces__srv__Patrol_Event__get_individual_type_description_source(NULL);
    sources[3] = *chapt4_interfaces__srv__Patrol_Request__get_individual_type_description_source(NULL);
    sources[4] = *chapt4_interfaces__srv__Patrol_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *chapt4_interfaces__srv__Patrol_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *chapt4_interfaces__srv__Patrol_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *chapt4_interfaces__srv__Patrol_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *chapt4_interfaces__srv__Patrol_Request__get_individual_type_description_source(NULL);
    sources[3] = *chapt4_interfaces__srv__Patrol_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
