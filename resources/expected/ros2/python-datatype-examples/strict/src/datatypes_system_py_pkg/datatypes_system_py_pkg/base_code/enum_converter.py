#!/usr/bin/env python3
from datatypes_system_py_pkg_interfaces.msg import MyEnum

#========================================================
# Re-running Codegen will overwrite changes to this file
#========================================================

def enumToString(value):
    typedValue = MyEnum()
    typedValue.data = value
    match (typedValue.my_enum):
        case MyEnum.MY_ENUM_ON:
            return "MyEnum On"
        case MyEnum.MY_ENUM_OFF:
            return "MyEnum Off"
        case default:
            return "Unknown value for MyEnum"

