# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:msg/MmwaveTarget.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MmwaveTarget(type):
    """Metaclass of message 'MmwaveTarget'."""

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
                'usv_interfaces.msg.MmwaveTarget')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mmwave_target
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mmwave_target
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mmwave_target
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mmwave_target
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mmwave_target

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MmwaveTarget(metaclass=Metaclass_MmwaveTarget):
    """Message class 'MmwaveTarget'."""

    __slots__ = [
        '_radar_id',
        '_x',
        '_y',
        '_v_x',
        '_v_y',
        '_size_w',
        '_size_l',
        '_size_h',
        '_objmotion_status',
        '_track_id',
    ]

    _fields_and_field_types = {
        'radar_id': 'string',
        'x': 'double',
        'y': 'double',
        'v_x': 'double',
        'v_y': 'double',
        'size_w': 'double',
        'size_l': 'double',
        'size_h': 'double',
        'objmotion_status': 'uint8',
        'track_id': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.radar_id = kwargs.get('radar_id', str())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.v_x = kwargs.get('v_x', float())
        self.v_y = kwargs.get('v_y', float())
        self.size_w = kwargs.get('size_w', float())
        self.size_l = kwargs.get('size_l', float())
        self.size_h = kwargs.get('size_h', float())
        self.objmotion_status = kwargs.get('objmotion_status', int())
        self.track_id = kwargs.get('track_id', int())

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
        if self.radar_id != other.radar_id:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.v_x != other.v_x:
            return False
        if self.v_y != other.v_y:
            return False
        if self.size_w != other.size_w:
            return False
        if self.size_l != other.size_l:
            return False
        if self.size_h != other.size_h:
            return False
        if self.objmotion_status != other.objmotion_status:
            return False
        if self.track_id != other.track_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def radar_id(self):
        """Message field 'radar_id'."""
        return self._radar_id

    @radar_id.setter
    def radar_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'radar_id' field must be of type 'str'"
        self._radar_id = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def v_x(self):
        """Message field 'v_x'."""
        return self._v_x

    @v_x.setter
    def v_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_x = value

    @builtins.property
    def v_y(self):
        """Message field 'v_y'."""
        return self._v_y

    @v_y.setter
    def v_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_y = value

    @builtins.property
    def size_w(self):
        """Message field 'size_w'."""
        return self._size_w

    @size_w.setter
    def size_w(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'size_w' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'size_w' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._size_w = value

    @builtins.property
    def size_l(self):
        """Message field 'size_l'."""
        return self._size_l

    @size_l.setter
    def size_l(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'size_l' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'size_l' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._size_l = value

    @builtins.property
    def size_h(self):
        """Message field 'size_h'."""
        return self._size_h

    @size_h.setter
    def size_h(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'size_h' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'size_h' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._size_h = value

    @builtins.property
    def objmotion_status(self):
        """Message field 'objmotion_status'."""
        return self._objmotion_status

    @objmotion_status.setter
    def objmotion_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'objmotion_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'objmotion_status' field must be an unsigned integer in [0, 255]"
        self._objmotion_status = value

    @builtins.property
    def track_id(self):
        """Message field 'track_id'."""
        return self._track_id

    @track_id.setter
    def track_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'track_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'track_id' field must be an unsigned integer in [0, 4294967295]"
        self._track_id = value
