#include "datatypes_system_cpp_pkg/base_headers/enum_converter.hpp"

std::string enumToString(datatypes_system_cpp_pkg_interfaces::msg::MyEnum* value) {
    switch (value->my_enum) {
        case building_control_cpp_pkg_interfaces::msg::MyEnum::MY_ENUM_ON:
            return "MyEnum On";
        case building_control_cpp_pkg_interfaces::msg::MyEnum::MY_ENUM_OFF:
            return "MyEnum Off";
        default:
            return "Unknown value for MyEnum";
    }
}

