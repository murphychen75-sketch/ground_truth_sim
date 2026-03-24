// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from usv_interfaces:msg/VisionDetection.idl
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
#include "usv_interfaces/msg/detail/vision_detection__struct.h"
#include "usv_interfaces/msg/detail/vision_detection__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool usv_interfaces__msg__vision_detection__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[53];
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
    assert(strncmp("usv_interfaces.msg._vision_detection.VisionDetection", full_classname_dest, 52) == 0);
  }
  usv_interfaces__msg__VisionDetection * ros_message = _ros_message;
  {  // camera_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "camera_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->camera_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // class_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "class_name");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->class_name, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // class_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "class_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->class_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // azimuth
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_predict
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_predict");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_predict = PyFloat_AS_DOUBLE(field);
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
  {  // size_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "size_h");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->size_h = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // confidence
    PyObject * field = PyObject_GetAttrString(_pymsg, "confidence");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->confidence = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * usv_interfaces__msg__vision_detection__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of VisionDetection */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("usv_interfaces.msg._vision_detection");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "VisionDetection");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  usv_interfaces__msg__VisionDetection * ros_message = (usv_interfaces__msg__VisionDetection *)raw_ros_message;
  {  // camera_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->camera_id.data,
      strlen(ros_message->camera_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "camera_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // class_name
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->class_name.data,
      strlen(ros_message->class_name.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "class_name", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // class_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->class_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "class_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azimuth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_predict
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_predict);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_predict", field);
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
  {  // confidence
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->confidence);
    {
      int rc = PyObject_SetAttrString(_pymessage, "confidence", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
