// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from usv_interfaces:msg/FusedTargetSnapshot.idl
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
#include "usv_interfaces/msg/detail/fused_target_snapshot__struct.h"
#include "usv_interfaces/msg/detail/fused_target_snapshot__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool unique_identifier_msgs__msg__uuid__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * unique_identifier_msgs__msg__uuid__convert_to_py(void * raw_ros_message);
bool usv_interfaces__msg__fused_track_sample__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * usv_interfaces__msg__fused_track_sample__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool usv_interfaces__msg__fused_target_snapshot__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[62];
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
    assert(strncmp("usv_interfaces.msg._fused_target_snapshot.FusedTargetSnapshot", full_classname_dest, 61) == 0);
  }
  usv_interfaces__msg__FusedTargetSnapshot * ros_message = _ros_message;
  {  // target_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_id");
    if (!field) {
      return false;
    }
    if (!unique_identifier_msgs__msg__uuid__convert_from_py(field, &ros_message->target_id)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    if (!usv_interfaces__msg__fused_track_sample__convert_from_py(field, &ros_message->state)) {
      Py_DECREF(field);
      return false;
    }
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
  {  // is_dark_target
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_dark_target");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_dark_target = (Py_True == field);
    Py_DECREF(field);
  }
  {  // is_ais_matched
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_ais_matched");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_ais_matched = (Py_True == field);
    Py_DECREF(field);
  }
  {  // matched_mmsi
    PyObject * field = PyObject_GetAttrString(_pymsg, "matched_mmsi");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->matched_mmsi = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * usv_interfaces__msg__fused_target_snapshot__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FusedTargetSnapshot */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("usv_interfaces.msg._fused_target_snapshot");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FusedTargetSnapshot");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  usv_interfaces__msg__FusedTargetSnapshot * ros_message = (usv_interfaces__msg__FusedTargetSnapshot *)raw_ros_message;
  {  // target_id
    PyObject * field = NULL;
    field = unique_identifier_msgs__msg__uuid__convert_to_py(&ros_message->target_id);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state
    PyObject * field = NULL;
    field = usv_interfaces__msg__fused_track_sample__convert_to_py(&ros_message->state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
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
  {  // is_dark_target
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_dark_target ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_dark_target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_ais_matched
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_ais_matched ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_ais_matched", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // matched_mmsi
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->matched_mmsi);
    {
      int rc = PyObject_SetAttrString(_pymessage, "matched_mmsi", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
