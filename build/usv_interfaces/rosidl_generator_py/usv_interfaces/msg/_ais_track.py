# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:msg/AISTrack.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_AISTrack(type):
    """Metaclass of message 'AISTrack'."""

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
                'usv_interfaces.msg.AISTrack')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ais_track
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ais_track
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ais_track
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ais_track
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ais_track

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class AISTrack(metaclass=Metaclass_AISTrack):
    """Message class 'AISTrack'."""

    __slots__ = [
        '_mmsi',
        '_ship_name',
        '_relative_x',
        '_relative_y',
        '_relative_v_x',
        '_relative_v_y',
        '_true_heading',
    ]

    _fields_and_field_types = {
        'mmsi': 'uint32',
        'ship_name': 'string',
        'relative_x': 'double',
        'relative_y': 'double',
        'relative_v_x': 'double',
        'relative_v_y': 'double',
        'true_heading': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mmsi = kwargs.get('mmsi', int())
        self.ship_name = kwargs.get('ship_name', str())
        self.relative_x = kwargs.get('relative_x', float())
        self.relative_y = kwargs.get('relative_y', float())
        self.relative_v_x = kwargs.get('relative_v_x', float())
        self.relative_v_y = kwargs.get('relative_v_y', float())
        self.true_heading = kwargs.get('true_heading', float())

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
        if self.mmsi != other.mmsi:
            return False
        if self.ship_name != other.ship_name:
            return False
        if self.relative_x != other.relative_x:
            return False
        if self.relative_y != other.relative_y:
            return False
        if self.relative_v_x != other.relative_v_x:
            return False
        if self.relative_v_y != other.relative_v_y:
            return False
        if self.true_heading != other.true_heading:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mmsi(self):
        """Message field 'mmsi'."""
        return self._mmsi

    @mmsi.setter
    def mmsi(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mmsi' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'mmsi' field must be an unsigned integer in [0, 4294967295]"
        self._mmsi = value

    @builtins.property
    def ship_name(self):
        """Message field 'ship_name'."""
        return self._ship_name

    @ship_name.setter
    def ship_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ship_name' field must be of type 'str'"
        self._ship_name = value

    @builtins.property
    def relative_x(self):
        """Message field 'relative_x'."""
        return self._relative_x

    @relative_x.setter
    def relative_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'relative_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'relative_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._relative_x = value

    @builtins.property
    def relative_y(self):
        """Message field 'relative_y'."""
        return self._relative_y

    @relative_y.setter
    def relative_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'relative_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'relative_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._relative_y = value

    @builtins.property
    def relative_v_x(self):
        """Message field 'relative_v_x'."""
        return self._relative_v_x

    @relative_v_x.setter
    def relative_v_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'relative_v_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'relative_v_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._relative_v_x = value

    @builtins.property
    def relative_v_y(self):
        """Message field 'relative_v_y'."""
        return self._relative_v_y

    @relative_v_y.setter
    def relative_v_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'relative_v_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'relative_v_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._relative_v_y = value

    @builtins.property
    def true_heading(self):
        """Message field 'true_heading'."""
        return self._true_heading

    @true_heading.setter
    def true_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'true_heading' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'true_heading' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._true_heading = value
