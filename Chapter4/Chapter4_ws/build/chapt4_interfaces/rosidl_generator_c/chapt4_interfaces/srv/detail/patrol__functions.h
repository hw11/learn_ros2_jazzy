// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from chapt4_interfaces:srv/Patrol.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "chapt4_interfaces/srv/patrol.h"


#ifndef CHAPT4_INTERFACES__SRV__DETAIL__PATROL__FUNCTIONS_H_
#define CHAPT4_INTERFACES__SRV__DETAIL__PATROL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "chapt4_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "chapt4_interfaces/srv/detail/patrol__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/Patrol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * chapt4_interfaces__srv__Patrol_Request
 * )) before or use
 * chapt4_interfaces__srv__Patrol_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__init(chapt4_interfaces__srv__Patrol_Request * msg);

/// Finalize srv/Patrol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Request__fini(chapt4_interfaces__srv__Patrol_Request * msg);

/// Create srv/Patrol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * chapt4_interfaces__srv__Patrol_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Request *
chapt4_interfaces__srv__Patrol_Request__create(void);

/// Destroy srv/Patrol message.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Request__destroy(chapt4_interfaces__srv__Patrol_Request * msg);

/// Check for srv/Patrol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__are_equal(const chapt4_interfaces__srv__Patrol_Request * lhs, const chapt4_interfaces__srv__Patrol_Request * rhs);

/// Copy a srv/Patrol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__copy(
  const chapt4_interfaces__srv__Patrol_Request * input,
  chapt4_interfaces__srv__Patrol_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/Patrol messages.
/**
 * It allocates the memory for the number of elements and calls
 * chapt4_interfaces__srv__Patrol_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__Sequence__init(chapt4_interfaces__srv__Patrol_Request__Sequence * array, size_t size);

/// Finalize array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Request__Sequence__fini(chapt4_interfaces__srv__Patrol_Request__Sequence * array);

/// Create array of srv/Patrol messages.
/**
 * It allocates the memory for the array and calls
 * chapt4_interfaces__srv__Patrol_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Request__Sequence *
chapt4_interfaces__srv__Patrol_Request__Sequence__create(size_t size);

/// Destroy array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Request__Sequence__destroy(chapt4_interfaces__srv__Patrol_Request__Sequence * array);

/// Check for srv/Patrol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__Sequence__are_equal(const chapt4_interfaces__srv__Patrol_Request__Sequence * lhs, const chapt4_interfaces__srv__Patrol_Request__Sequence * rhs);

/// Copy an array of srv/Patrol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Request__Sequence__copy(
  const chapt4_interfaces__srv__Patrol_Request__Sequence * input,
  chapt4_interfaces__srv__Patrol_Request__Sequence * output);

/// Initialize srv/Patrol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * chapt4_interfaces__srv__Patrol_Response
 * )) before or use
 * chapt4_interfaces__srv__Patrol_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__init(chapt4_interfaces__srv__Patrol_Response * msg);

/// Finalize srv/Patrol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Response__fini(chapt4_interfaces__srv__Patrol_Response * msg);

/// Create srv/Patrol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * chapt4_interfaces__srv__Patrol_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Response *
chapt4_interfaces__srv__Patrol_Response__create(void);

/// Destroy srv/Patrol message.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Response__destroy(chapt4_interfaces__srv__Patrol_Response * msg);

/// Check for srv/Patrol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__are_equal(const chapt4_interfaces__srv__Patrol_Response * lhs, const chapt4_interfaces__srv__Patrol_Response * rhs);

/// Copy a srv/Patrol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__copy(
  const chapt4_interfaces__srv__Patrol_Response * input,
  chapt4_interfaces__srv__Patrol_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/Patrol messages.
/**
 * It allocates the memory for the number of elements and calls
 * chapt4_interfaces__srv__Patrol_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__Sequence__init(chapt4_interfaces__srv__Patrol_Response__Sequence * array, size_t size);

/// Finalize array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Response__Sequence__fini(chapt4_interfaces__srv__Patrol_Response__Sequence * array);

/// Create array of srv/Patrol messages.
/**
 * It allocates the memory for the array and calls
 * chapt4_interfaces__srv__Patrol_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Response__Sequence *
chapt4_interfaces__srv__Patrol_Response__Sequence__create(size_t size);

/// Destroy array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Response__Sequence__destroy(chapt4_interfaces__srv__Patrol_Response__Sequence * array);

/// Check for srv/Patrol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__Sequence__are_equal(const chapt4_interfaces__srv__Patrol_Response__Sequence * lhs, const chapt4_interfaces__srv__Patrol_Response__Sequence * rhs);

/// Copy an array of srv/Patrol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Response__Sequence__copy(
  const chapt4_interfaces__srv__Patrol_Response__Sequence * input,
  chapt4_interfaces__srv__Patrol_Response__Sequence * output);

/// Initialize srv/Patrol message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * chapt4_interfaces__srv__Patrol_Event
 * )) before or use
 * chapt4_interfaces__srv__Patrol_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__init(chapt4_interfaces__srv__Patrol_Event * msg);

/// Finalize srv/Patrol message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Event__fini(chapt4_interfaces__srv__Patrol_Event * msg);

/// Create srv/Patrol message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * chapt4_interfaces__srv__Patrol_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Event *
chapt4_interfaces__srv__Patrol_Event__create(void);

/// Destroy srv/Patrol message.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Event__destroy(chapt4_interfaces__srv__Patrol_Event * msg);

/// Check for srv/Patrol message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__are_equal(const chapt4_interfaces__srv__Patrol_Event * lhs, const chapt4_interfaces__srv__Patrol_Event * rhs);

/// Copy a srv/Patrol message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__copy(
  const chapt4_interfaces__srv__Patrol_Event * input,
  chapt4_interfaces__srv__Patrol_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_type_hash_t *
chapt4_interfaces__srv__Patrol_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
chapt4_interfaces__srv__Patrol_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource *
chapt4_interfaces__srv__Patrol_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
chapt4_interfaces__srv__Patrol_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/Patrol messages.
/**
 * It allocates the memory for the number of elements and calls
 * chapt4_interfaces__srv__Patrol_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__Sequence__init(chapt4_interfaces__srv__Patrol_Event__Sequence * array, size_t size);

/// Finalize array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Event__Sequence__fini(chapt4_interfaces__srv__Patrol_Event__Sequence * array);

/// Create array of srv/Patrol messages.
/**
 * It allocates the memory for the array and calls
 * chapt4_interfaces__srv__Patrol_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
chapt4_interfaces__srv__Patrol_Event__Sequence *
chapt4_interfaces__srv__Patrol_Event__Sequence__create(size_t size);

/// Destroy array of srv/Patrol messages.
/**
 * It calls
 * chapt4_interfaces__srv__Patrol_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
void
chapt4_interfaces__srv__Patrol_Event__Sequence__destroy(chapt4_interfaces__srv__Patrol_Event__Sequence * array);

/// Check for srv/Patrol message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__Sequence__are_equal(const chapt4_interfaces__srv__Patrol_Event__Sequence * lhs, const chapt4_interfaces__srv__Patrol_Event__Sequence * rhs);

/// Copy an array of srv/Patrol messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_chapt4_interfaces
bool
chapt4_interfaces__srv__Patrol_Event__Sequence__copy(
  const chapt4_interfaces__srv__Patrol_Event__Sequence * input,
  chapt4_interfaces__srv__Patrol_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // CHAPT4_INTERFACES__SRV__DETAIL__PATROL__FUNCTIONS_H_
