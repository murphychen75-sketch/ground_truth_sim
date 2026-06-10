# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:msg/ControlDeviation.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ControlDeviation(type):
    """Metaclass of message 'ControlDeviation'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('usv_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'usv_interfaces.msg.ControlDeviation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__control_deviation
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__control_deviation
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__control_deviation
            cls._TYPE_SUPPORT = module.type_support_msg__msg__control_deviation
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__control_deviation

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ControlDeviation(metaclass=Metaclass_ControlDeviation):
    """Message class 'ControlDeviation'."""

    __slots__ = [
        '_header',
        '_cross_track_error',
        '_heading_error',
        '_distance_to_goal',
        '_target_speed',
        '_current_speed',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'cross_track_error': 'float',
        'heading_error': 'float',
        'distance_to_goal': 'float',
        'target_speed': 'float',
        'current_speed': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.cross_track_error = kwargs.get('cross_track_error', float())
        self.heading_error = kwargs.get('heading_error', float())
        self.distance_to_goal = kwargs.get('distance_to_goal', float())
        self.target_speed = kwargs.get('target_speed', float())
        self.current_speed = kwargs.get('current_speed', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.cross_track_error != other.cross_track_error:
            return False
        if self.heading_error != other.heading_error:
            return False
        if self.distance_to_goal != other.distance_to_goal:
            return False
        if self.target_speed != other.target_speed:
            return False
        if self.current_speed != other.current_speed:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def cross_track_error(self):
        """Message field 'cross_track_error'."""
        return self._cross_track_error

    @cross_track_error.setter
    def cross_track_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cross_track_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'cross_track_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._cross_track_error = value

    @builtins.property
    def heading_error(self):
        """Message field 'heading_error'."""
        return self._heading_error

    @heading_error.setter
    def heading_error(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'heading_error' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'heading_error' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._heading_error = value

    @builtins.property
    def distance_to_goal(self):
        """Message field 'distance_to_goal'."""
        return self._distance_to_goal

    @distance_to_goal.setter
    def distance_to_goal(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_to_goal' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'distance_to_goal' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._distance_to_goal = value

    @builtins.property
    def target_speed(self):
        """Message field 'target_speed'."""
        return self._target_speed

    @target_speed.setter
    def target_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'target_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'target_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._target_speed = value

    @builtins.property
    def current_speed(self):
        """Message field 'current_speed'."""
        return self._current_speed

    @current_speed.setter
    def current_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current_speed = value
