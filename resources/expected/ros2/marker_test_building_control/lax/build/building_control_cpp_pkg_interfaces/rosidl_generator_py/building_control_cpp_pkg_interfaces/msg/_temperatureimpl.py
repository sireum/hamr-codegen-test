# generated from rosidl_generator_py/resource/_idl.py.em
# with input from building_control_cpp_pkg_interfaces:msg/Temperatureimpl.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Temperatureimpl(type):
    """Metaclass of message 'Temperatureimpl'."""

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
            module = import_type_support('building_control_cpp_pkg_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'building_control_cpp_pkg_interfaces.msg.Temperatureimpl')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__temperatureimpl
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__temperatureimpl
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__temperatureimpl
            cls._TYPE_SUPPORT = module.type_support_msg__msg__temperatureimpl
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__temperatureimpl

            from building_control_cpp_pkg_interfaces.msg import Float32
            if Float32.__class__._TYPE_SUPPORT is None:
                Float32.__class__.__import_type_support__()

            from building_control_cpp_pkg_interfaces.msg import TempUnit
            if TempUnit.__class__._TYPE_SUPPORT is None:
                TempUnit.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Temperatureimpl(metaclass=Metaclass_Temperatureimpl):
    """Message class 'Temperatureimpl'."""

    __slots__ = [
        '_degrees',
        '_unit',
    ]

    _fields_and_field_types = {
        'degrees': 'building_control_cpp_pkg_interfaces/Float32',
        'unit': 'building_control_cpp_pkg_interfaces/TempUnit',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['building_control_cpp_pkg_interfaces', 'msg'], 'Float32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['building_control_cpp_pkg_interfaces', 'msg'], 'TempUnit'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from building_control_cpp_pkg_interfaces.msg import Float32
        self.degrees = kwargs.get('degrees', Float32())
        from building_control_cpp_pkg_interfaces.msg import TempUnit
        self.unit = kwargs.get('unit', TempUnit())

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
        if self.degrees != other.degrees:
            return False
        if self.unit != other.unit:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def degrees(self):
        """Message field 'degrees'."""
        return self._degrees

    @degrees.setter
    def degrees(self, value):
        if __debug__:
            from building_control_cpp_pkg_interfaces.msg import Float32
            assert \
                isinstance(value, Float32), \
                "The 'degrees' field must be a sub message of type 'Float32'"
        self._degrees = value

    @builtins.property
    def unit(self):
        """Message field 'unit'."""
        return self._unit

    @unit.setter
    def unit(self, value):
        if __debug__:
            from building_control_cpp_pkg_interfaces.msg import TempUnit
            assert \
                isinstance(value, TempUnit), \
                "The 'unit' field must be a sub message of type 'TempUnit'"
        self._unit = value
