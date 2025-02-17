# generated from rosidl_generator_py/resource/_idl.py.em
# with input from building_control_cpp_pkg_interfaces:msg/FanCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FanCmd(type):
    """Metaclass of message 'FanCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FAN_CMD_ON': 0,
        'FAN_CMD_OFF': 1,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('building_control_cpp_pkg_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'building_control_cpp_pkg_interfaces.msg.FanCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__fan_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__fan_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__fan_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__fan_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__fan_cmd

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FAN_CMD_ON': cls.__constants['FAN_CMD_ON'],
            'FAN_CMD_OFF': cls.__constants['FAN_CMD_OFF'],
        }

    @property
    def FAN_CMD_ON(self):
        """Message constant 'FAN_CMD_ON'."""
        return Metaclass_FanCmd.__constants['FAN_CMD_ON']

    @property
    def FAN_CMD_OFF(self):
        """Message constant 'FAN_CMD_OFF'."""
        return Metaclass_FanCmd.__constants['FAN_CMD_OFF']


class FanCmd(metaclass=Metaclass_FanCmd):
    """
    Message class 'FanCmd'.

    Constants:
      FAN_CMD_ON
      FAN_CMD_OFF
    """

    __slots__ = [
        '_fan_cmd',
    ]

    _fields_and_field_types = {
        'fan_cmd': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.fan_cmd = kwargs.get('fan_cmd', int())

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
        if self.fan_cmd != other.fan_cmd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def fan_cmd(self):
        """Message field 'fan_cmd'."""
        return self._fan_cmd

    @fan_cmd.setter
    def fan_cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fan_cmd' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fan_cmd' field must be an unsigned integer in [0, 255]"
        self._fan_cmd = value
