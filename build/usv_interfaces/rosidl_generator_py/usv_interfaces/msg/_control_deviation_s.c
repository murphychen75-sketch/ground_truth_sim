// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from usv_interfaces:msg/ControlDeviation.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "usv_interfaces/msg/detail/control_deviation__struct.h"
#include "usv_interfaces/msg/detail/control_deviation__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool usv_interfaces__msg__control_deviation__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[55];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("usv_interfaces.msg._control_deviation.ControlDeviation", full_classname_dest, 54) == 0);
  }
  usv_interfaces__msg__ControlDeviation * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // cross_track_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "cross_track_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cross_track_error = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // heading_error
    PyObject * field = PyObject_GetAttrString(_pymsg, "heading_error");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->heading_error = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_to_goal
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_to_goal");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_to_goal = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->target_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "current_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * usv_interfaces__msg__control_deviation__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ControlDeviation */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("usv_interfaces.msg._control_deviation");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ControlDeviation");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  usv_interfaces__msg__ControlDeviation * ros_message = (usv_interfaces__msg__ControlDeviation *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cross_track_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cross_track_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cross_track_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // heading_error
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->heading_error);
    {
      int rc = PyObject_SetAttrString(_pymessage, "heading_error", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_to_goal
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_to_goal);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_to_goal", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->target_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
