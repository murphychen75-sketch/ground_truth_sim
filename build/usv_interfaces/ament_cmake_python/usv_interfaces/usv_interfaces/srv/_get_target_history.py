# generated from rosidl_generator_py/resource/_idl.py.em
# with input from usv_interfaces:srv/GetTargetHistory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetTargetHistory_Request(type):
    """Metaclass of message 'GetTargetHistory_Request'."""

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
                'usv_interfaces.srv.GetTargetHistory_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_target_history__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_target_history__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_target_history__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_target_history__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_target_history__request

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


class GetTargetHistory_Request(metaclass=Metaclass_GetTargetHistory_Request):
    """Message class 'GetTargetHistory_Request'."""

    __slots__ = [
        '_target_id',
        '_t_start',
        '_t_end',
        '_max_samples',
    ]

    _fields_and_field_types = {
        'target_id': 'unique_identifier_msgs/UUID',
        't_start': 'builtin_interfaces/Time',
        't_end': 'builtin_interfaces/Time',
        'max_samples': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.target_id = kwargs.get('target_id', UUID())
        from builtin_interfaces.msg import Time
        self.t_start = kwargs.get('t_start', Time())
        from builtin_interfaces.msg import Time
        self.t_end = kwargs.get('t_end', Time())
        self.max_samples = kwargs.get('max_samples', int())

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
        if self.t_start != other.t_start:
            return False
        if self.t_end != other.t_end:
            return False
        if self.max_samples != other.max_samples:
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
    def t_start(self):
        """Message field 't_start'."""
        return self._t_start

    @t_start.setter
    def t_start(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 't_start' field must be a sub message of type 'Time'"
        self._t_start = value

    @builtins.property
    def t_end(self):
        """Message field 't_end'."""
        return self._t_end

    @t_end.setter
    def t_end(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 't_end' field must be a sub message of type 'Time'"
        self._t_end = value

    @builtins.property
    def max_samples(self):
        """Message field 'max_samples'."""
        return self._max_samples

    @max_samples.setter
    def max_samples(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_samples' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'max_samples' field must be an unsigned integer in [0, 4294967295]"
        self._max_samples = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetTargetHistory_Response(type):
    """Metaclass of message 'GetTargetHistory_Response'."""

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
                'usv_interfaces.srv.GetTargetHistory_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_target_history__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_target_history__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_target_history__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_target_history__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_target_history__response

            from usv_interfaces.msg import FusedTrackSample
            if FusedTrackSample.__class__._TYPE_SUPPORT is None:
                FusedTrackSample.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetTargetHistory_Response(metaclass=Metaclass_GetTargetHistory_Response):
    """Message class 'GetTargetHistory_Response'."""

    __slots__ = [
        '_status',
        '_samples',
    ]

    _fields_and_field_types = {
        'status': 'int32',
        'samples': 'sequence<usv_interfaces/FusedTrackSample>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['usv_interfaces', 'msg'], 'FusedTrackSample')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        self.samples = kwargs.get('samples', [])

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
        if self.status != other.status:
            return False
        if self.samples != other.samples:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'status' field must be an integer in [-2147483648, 2147483647]"
        self._status = value

    @builtins.property
    def samples(self):
        """Message field 'samples'."""
        return self._samples

    @samples.setter
    def samples(self, value):
        if __debug__:
            from usv_interfaces.msg import FusedTrackSample
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, FusedTrackSample) for v in value) and
                 True), \
                "The 'samples' field must be a set or sequence and each value of type 'FusedTrackSample'"
        self._samples = value


class Metaclass_GetTargetHistory(type):
    """Metaclass of service 'GetTargetHistory'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('usv_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'usv_interfaces.srv.GetTargetHistory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_target_history

            from usv_interfaces.srv import _get_target_history
            if _get_target_history.Metaclass_GetTargetHistory_Request._TYPE_SUPPORT is None:
                _get_target_history.Metaclass_GetTargetHistory_Request.__import_type_support__()
            if _get_target_history.Metaclass_GetTargetHistory_Response._TYPE_SUPPORT is None:
                _get_target_history.Metaclass_GetTargetHistory_Response.__import_type_support__()


class GetTargetHistory(metaclass=Metaclass_GetTargetHistory):
    from usv_interfaces.srv._get_target_history import GetTargetHistory_Request as Request
    from usv_interfaces.srv._get_target_history import GetTargetHistory_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
