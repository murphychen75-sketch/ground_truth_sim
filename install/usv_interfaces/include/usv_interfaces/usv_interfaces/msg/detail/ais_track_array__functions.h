// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from usv_interfaces:msg/AISTrackArray.idl
// generated code does not contain a copyright notice

#ifndef USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__FUNCTIONS_H_
#define USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "usv_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "usv_interfaces/msg/detail/ais_track_array__struct.h"

/// Initialize msg/AISTrackArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * usv_interfaces__msg__AISTrackArray
 * )) before or use
 * usv_interfaces__msg__AISTrackArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__init(usv_interfaces__msg__AISTrackArray * msg);

/// Finalize msg/AISTrackArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
void
usv_interfaces__msg__AISTrackArray__fini(usv_interfaces__msg__AISTrackArray * msg);

/// Create msg/AISTrackArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * usv_interfaces__msg__AISTrackArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
usv_interfaces__msg__AISTrackArray *
usv_interfaces__msg__AISTrackArray__create();

/// Destroy msg/AISTrackArray message.
/**
 * It calls
 * usv_interfaces__msg__AISTrackArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
void
usv_interfaces__msg__AISTrackArray__destroy(usv_interfaces__msg__AISTrackArray * msg);

/// Check for msg/AISTrackArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__are_equal(const usv_interfaces__msg__AISTrackArray * lhs, const usv_interfaces__msg__AISTrackArray * rhs);

/// Copy a msg/AISTrackArray message.
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
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__copy(
  const usv_interfaces__msg__AISTrackArray * input,
  usv_interfaces__msg__AISTrackArray * output);

/// Initialize array of msg/AISTrackArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * usv_interfaces__msg__AISTrackArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__Sequence__init(usv_interfaces__msg__AISTrackArray__Sequence * array, size_t size);

/// Finalize array of msg/AISTrackArray messages.
/**
 * It calls
 * usv_interfaces__msg__AISTrackArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
void
usv_interfaces__msg__AISTrackArray__Sequence__fini(usv_interfaces__msg__AISTrackArray__Sequence * array);

/// Create array of msg/AISTrackArray messages.
/**
 * It allocates the memory for the array and calls
 * usv_interfaces__msg__AISTrackArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
usv_interfaces__msg__AISTrackArray__Sequence *
usv_interfaces__msg__AISTrackArray__Sequence__create(size_t size);

/// Destroy array of msg/AISTrackArray messages.
/**
 * It calls
 * usv_interfaces__msg__AISTrackArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
void
usv_interfaces__msg__AISTrackArray__Sequence__destroy(usv_interfaces__msg__AISTrackArray__Sequence * array);

/// Check for msg/AISTrackArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__Sequence__are_equal(const usv_interfaces__msg__AISTrackArray__Sequence * lhs, const usv_interfaces__msg__AISTrackArray__Sequence * rhs);

/// Copy an array of msg/AISTrackArray messages.
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
ROSIDL_GENERATOR_C_PUBLIC_usv_interfaces
bool
usv_interfaces__msg__AISTrackArray__Sequence__copy(
  const usv_interfaces__msg__AISTrackArray__Sequence * input,
  usv_interfaces__msg__AISTrackArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // USV_INTERFACES__MSG__DETAIL__AIS_TRACK_ARRAY__FUNCTIONS_H_
