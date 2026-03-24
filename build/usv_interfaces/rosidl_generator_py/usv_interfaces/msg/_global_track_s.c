// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from usv_interfaces:msg/GlobalTrack.idl
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
#include "usv_interfaces/msg/detail/global_track__struct.h"
#include "usv_interfaces/msg/detail/global_track__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool usv_interfaces__msg__global_track__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("usv_interfaces.msg._global_track.GlobalTrack", full_classname_dest, 44) == 0);
  }
  usv_interfaces__msg__GlobalTrack * ros_message = _ros_message;
  {  // track_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "track_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->track_id = PyLong_AsUnsignedLong(field);
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
  {  // covariance
    PyObject * field = PyObject_GetAttrString(_pymsg, "covariance");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
      Py_ssize_t size = 16;
      double * dest = ros_message->covariance;
      for (Py_ssize_t i = 0; i < size; ++i) {
        double tmp = *(npy_float64 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(double));
      }
      Py_DECREF(seq_field);
    }
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
PyObject * usv_interfaces__msg__global_track__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GlobalTrack */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("usv_interfaces.msg._global_track");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GlobalTrack");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  usv_interfaces__msg__GlobalTrack * ros_message = (usv_interfaces__msg__GlobalTrack *)raw_ros_message;
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
  {  // covariance
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "covariance");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_FLOAT64);
    assert(sizeof(npy_float64) == sizeof(double));
    npy_float64 * dst = (npy_float64 *)PyArray_GETPTR1(seq_field, 0);
    double * src = &(ros_message->covariance[0]);
    memcpy(dst, src, 16 * sizeof(double));
    Py_DECREF(field);
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
