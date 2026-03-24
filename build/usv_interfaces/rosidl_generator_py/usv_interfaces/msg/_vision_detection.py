# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:msg/VisionDetection.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_VisionDetection(type):
    """Metaclass of message 'VisionDetection'."""

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
                'usv_interfaces.msg.VisionDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vision_detection
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vision_detection
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vision_detection
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vision_detection
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vision_detection

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class VisionDetection(metaclass=Metaclass_VisionDetection):
    """Message class 'VisionDetection'."""

    __slots__ = [
        '_camera_id',
        '_class_name',
        '_class_id',
        '_azimuth',
        '_distance_predict',
        '_size_w',
        '_size_h',
        '_confidence',
    ]

    _fields_and_field_types = {
        'camera_id': 'string',
        'class_name': 'string',
        'class_id': 'int32',
        'azimuth': 'double',
        'distance_predict': 'double',
        'size_w': 'double',
        'size_h': 'double',
        'confidence': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        self.camera_id = kwargs.get('camera_id', str())
        self.class_name = kwargs.get('class_name', str())
        self.class_id = kwargs.get('class_id', int())
        self.azimuth = kwargs.get('azimuth', float())
        self.distance_predict = kwargs.get('distance_predict', float())
        self.size_w = kwargs.get('size_w', float())
        self.size_h = kwargs.get('size_h', float())
        self.confidence = kwargs.get('confidence', float())

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
        if self.camera_id != other.camera_id:
            return False
        if self.class_name != other.class_name:
            return False
        if self.class_id != other.class_id:
            return False
        if self.azimuth != other.azimuth:
            return False
        if self.distance_predict != other.distance_predict:
            return False
        if self.size_w != other.size_w:
            return False
        if self.size_h != other.size_h:
            return False
        if self.confidence != other.confidence:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def camera_id(self):
        """Message field 'camera_id'."""
        return self._camera_id

    @camera_id.setter
    def camera_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'camera_id' field must be of type 'str'"
        self._camera_id = value

    @builtins.property
    def class_name(self):
        """Message field 'class_name'."""
        return self._class_name

    @class_name.setter
    def class_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'class_name' field must be of type 'str'"
        self._class_name = value

    @builtins.property
    def class_id(self):
        """Message field 'class_id'."""
        return self._class_id

    @class_id.setter
    def class_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'class_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'class_id' field must be an integer in [-2147483648, 2147483647]"
        self._class_id = value

    @builtins.property
    def azimuth(self):
        """Message field 'azimuth'."""
        return self._azimuth

    @azimuth.setter
    def azimuth(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'azimuth' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'azimuth' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._azimuth = value

    @builtins.property
    def distance_predict(self):
        """Message field 'distance_predict'."""
        return self._distance_predict

    @distance_predict.setter
    def distance_predict(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_predict' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance_predict' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance_predict = value

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
    def confidence(self):
        """Message field 'confidence'."""
        return self._confidence

    @confidence.setter
    def confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._confidence = value
