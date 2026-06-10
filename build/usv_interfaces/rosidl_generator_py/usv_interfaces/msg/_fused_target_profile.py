# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:msg/FusedTargetProfile.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FusedTargetProfile(type):
    """Metaclass of message 'FusedTargetProfile'."""

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
                'usv_interfaces.msg.FusedTargetProfile')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fused_target_profile
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fused_target_profile
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fused_target_profile
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fused_target_profile
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fused_target_profile

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FusedTargetProfile(metaclass=Metaclass_FusedTargetProfile):
    """Message class 'FusedTargetProfile'."""

    __slots__ = [
        '_target_id',
        '_size_w',
        '_size_l',
        '_size_h',
        '_class_id',
        '_class_name',
        '_class_confidence',
        '_is_dark_target',
        '_is_ais_matched',
        '_matched_mmsi',
        '_first_seen',
        '_last_profile_update',
    ]

    _fields_and_field_types = {
        'target_id': 'unique_identifier_msgs/UUID',
        'size_w': 'double',
        'size_l': 'double',
        'size_h': 'double',
        'class_id': 'int32',
        'class_name': 'string',
        'class_confidence': 'double',
        'is_dark_target': 'boolean',
        'is_ais_matched': 'boolean',
        'matched_mmsi': 'uint32',
        'first_seen': 'builtin_interfaces/Time',
        'last_profile_update': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.target_id = kwargs.get('target_id', UUID())
        self.size_w = kwargs.get('size_w', float())
        self.size_l = kwargs.get('size_l', float())
        self.size_h = kwargs.get('size_h', float())
        self.class_id = kwargs.get('class_id', int())
        self.class_name = kwargs.get('class_name', str())
        self.class_confidence = kwargs.get('class_confidence', float())
        self.is_dark_target = kwargs.get('is_dark_target', bool())
        self.is_ais_matched = kwargs.get('is_ais_matched', bool())
        self.matched_mmsi = kwargs.get('matched_mmsi', int())
        from builtin_interfaces.msg import Time
        self.first_seen = kwargs.get('first_seen', Time())
        from builtin_interfaces.msg import Time
        self.last_profile_update = kwargs.get('last_profile_update', Time())

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
        if self.target_id != other.target_id:
            return False
        if self.size_w != other.size_w:
            return False
        if self.size_l != other.size_l:
            return False
        if self.size_h != other.size_h:
            return False
        if self.class_id != other.class_id:
            return False
        if self.class_name != other.class_name:
            return False
        if self.class_confidence != other.class_confidence:
            return False
        if self.is_dark_target != other.is_dark_target:
            return False
        if self.is_ais_matched != other.is_ais_matched:
            return False
        if self.matched_mmsi != other.matched_mmsi:
            return False
        if self.first_seen != other.first_seen:
            return False
        if self.last_profile_update != other.last_profile_update:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_id(self):
        """Message field 'target_id'."""
        return self._target_id

    @target_id.setter
    def target_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'target_id' field must be a sub message of type 'UUID'"
        self._target_id = value

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
    def class_confidence(self):
        """Message field 'class_confidence'."""
        return self._class_confidence

    @class_confidence.setter
    def class_confidence(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'class_confidence' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'class_confidence' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._class_confidence = value

    @builtins.property
    def is_dark_target(self):
        """Message field 'is_dark_target'."""
        return self._is_dark_target

    @is_dark_target.setter
    def is_dark_target(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_dark_target' field must be of type 'bool'"
        self._is_dark_target = value

    @builtins.property
    def is_ais_matched(self):
        """Message field 'is_ais_matched'."""
        return self._is_ais_matched

    @is_ais_matched.setter
    def is_ais_matched(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_ais_matched' field must be of type 'bool'"
        self._is_ais_matched = value

    @builtins.property
    def matched_mmsi(self):
        """Message field 'matched_mmsi'."""
        return self._matched_mmsi

    @matched_mmsi.setter
    def matched_mmsi(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'matched_mmsi' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'matched_mmsi' field must be an unsigned integer in [0, 4294967295]"
        self._matched_mmsi = value

    @builtins.property
    def first_seen(self):
        """Message field 'first_seen'."""
        return self._first_seen

    @first_seen.setter
    def first_seen(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'first_seen' field must be a sub message of type 'Time'"
        self._first_seen = value

    @builtins.property
    def last_profile_update(self):
        """Message field 'last_profile_update'."""
        return self._last_profile_update

    @last_profile_update.setter
    def last_profile_update(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'last_profile_update' field must be a sub message of type 'Time'"
        self._last_profile_update = value
