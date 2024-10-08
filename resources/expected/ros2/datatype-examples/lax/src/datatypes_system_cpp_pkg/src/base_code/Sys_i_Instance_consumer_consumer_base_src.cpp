#include "datatypes_system_cpp_pkg/base_headers/Sys_i_Instance_consumer_consumer_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

Sys_i_Instance_consumer_consumer_base::Sys_i_Instance_consumer_consumer_base() : Node("Sys_i_Instance_consumer_consumer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    Sys_i_Instance_consumer_consumer_myBoolean_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(
        "Sys_i_Instance_consumer_consumer_myBoolean",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myBoolean, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myInteger_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInteger",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myInteger, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myFloat, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myCharacter_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Character>(
        "Sys_i_Instance_consumer_consumer_myCharacter",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myCharacter, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myString_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::String>(
        "Sys_i_Instance_consumer_consumer_myString",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myString, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt8_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(
        "Sys_i_Instance_consumer_consumer_myInt8",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myInt8, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt16_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(
        "Sys_i_Instance_consumer_consumer_myInt16",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myInt16, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(
        "Sys_i_Instance_consumer_consumer_myInt32",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myInt32, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInt64",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myInt64, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt8_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(
        "Sys_i_Instance_consumer_consumer_myUInt8",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myUInt8, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt16_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(
        "Sys_i_Instance_consumer_consumer_myUInt16",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myUInt16, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(
        "Sys_i_Instance_consumer_consumer_myUInt32",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myUInt32, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(
        "Sys_i_Instance_consumer_consumer_myUInt64",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myUInt64, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float32>(
        "Sys_i_Instance_consumer_consumer_myFloat32",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myFloat32, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat64",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myFloat64, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myEnum_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(
        "Sys_i_Instance_consumer_consumer_myEnum",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myEnum, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myStruct_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(
        "Sys_i_Instance_consumer_consumer_myStruct",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myStruct, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myArray1_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(
        "Sys_i_Instance_consumer_consumer_myArray1",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myArray1, this, std::placeholders::_1), subscription_options_);

    Sys_i_Instance_consumer_consumer_myArray2_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(
        "Sys_i_Instance_consumer_consumer_myArray2",
        1,
        std::bind(&Sys_i_Instance_consumer_consumer_base::handle_myArray2, this, std::placeholders::_1), subscription_options_);

}
