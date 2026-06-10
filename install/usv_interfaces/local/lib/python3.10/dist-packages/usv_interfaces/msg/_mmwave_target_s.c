// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from usv_interfaces:msg/MmwaveTarget.idl
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
#include "usv_interfaces/msg/detail/mmwave_target__struct.h"
#include "usv_interfaces/msg/detail/mmwave_target__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool usv_interfaces__msg__mmwave_target__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[47];
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
    assert(strncmp("usv_interfaces.msg._mmwave_target.MmwaveTarget", full_classname_dest, 46) == 0);
  }
  usv_interfaces__msg__MmwaveTarget * ros_message = _ros_message;
  {  // radar_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "radar_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->radar_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // size_w
    PyObject * field = PyObject_GetAttrString(_pymsg, "size_w");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->size_w = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // size_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "size_l");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->size_l = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // size_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "size_h");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->size_h = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // objmotion_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "objmotion_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->objmotion_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // track_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "track_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->track_id = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * usv_interfaces__msg__mmwave_target__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MmwaveTarget */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("usv_interfaces.msg._mmwave_target");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MmwaveTarget");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  usv_interfaces__msg__MmwaveTarget * ros_message = (usv_interfaces__msg__MmwaveTarget *)raw_ros_message;
  {  // radar_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->radar_id.data,
      strlen(ros_message->radar_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "radar_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // size_w
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->size_w);
    {
      int rc = PyObject_SetAttrString(_pymessage, "size_w", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // size_l
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->size_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "size_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // size_h
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->size_h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "size_h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // objmotion_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->objmotion_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "objmotion_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // track_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->track_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "track_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
