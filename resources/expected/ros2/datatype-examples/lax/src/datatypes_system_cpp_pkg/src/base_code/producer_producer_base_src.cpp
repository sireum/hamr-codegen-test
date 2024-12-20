#include "datatypes_system_cpp_pkg/base_headers/producer_producer_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

producer_producer_base::producer_producer_base() : Node("producer_producer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    Sys_i_Instance_producer_producer_myBoolean_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(
        "Sys_i_Instance_consumer_consumer_myBoolean",
        1);

    Sys_i_Instance_producer_producer_myInteger_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInteger",
        1);

    Sys_i_Instance_producer_producer_myFloat_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat",
        1);

    Sys_i_Instance_producer_producer_myCharacter_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Character>(
        "Sys_i_Instance_consumer_consumer_myCharacter",
        1);

    Sys_i_Instance_producer_producer_myString_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::String>(
        "Sys_i_Instance_consumer_consumer_myString",
        1);

    Sys_i_Instance_producer_producer_myInt8_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(
        "Sys_i_Instance_consumer_consumer_myInt8",
        1);

    Sys_i_Instance_producer_producer_myInt16_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(
        "Sys_i_Instance_consumer_consumer_myInt16",
        1);

    Sys_i_Instance_producer_producer_myInt32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(
        "Sys_i_Instance_consumer_consumer_myInt32",
        1);

    Sys_i_Instance_producer_producer_myInt64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInt64",
        1);

    Sys_i_Instance_producer_producer_myUInt8_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(
        "Sys_i_Instance_consumer_consumer_myUInt8",
        1);

    Sys_i_Instance_producer_producer_myUInt16_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(
        "Sys_i_Instance_consumer_consumer_myUInt16",
        1);

    Sys_i_Instance_producer_producer_myUInt32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(
        "Sys_i_Instance_consumer_consumer_myUInt32",
        1);

    Sys_i_Instance_producer_producer_myUInt64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(
        "Sys_i_Instance_consumer_consumer_myUInt64",
        1);

    Sys_i_Instance_producer_producer_myFloat32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float32>(
        "Sys_i_Instance_consumer_consumer_myFloat32",
        1);

    Sys_i_Instance_producer_producer_myFloat64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat64",
        1);

    Sys_i_Instance_producer_producer_myEnum_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(
        "Sys_i_Instance_consumer_consumer_myEnum",
        1);

    Sys_i_Instance_producer_producer_myStruct_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(
        "Sys_i_Instance_consumer_consumer_myStruct",
        1);

    Sys_i_Instance_producer_producer_myArray1_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(
        "Sys_i_Instance_consumer_consumer_myArray1",
        1);

    Sys_i_Instance_producer_producer_myArray2_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(
        "Sys_i_Instance_consumer_consumer_myArray2",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&producer_producer_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void producer_producer_base::put_myBoolean(datatypes_system_cpp_pkg_interfaces::msg::Boolean msg)
{
    Sys_i_Instance_producer_producer_myBoolean_publisher_->publish(msg);
}

void producer_producer_base::put_myInteger(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    Sys_i_Instance_producer_producer_myInteger_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    Sys_i_Instance_producer_producer_myFloat_publisher_->publish(msg);
}

void producer_producer_base::put_myCharacter(datatypes_system_cpp_pkg_interfaces::msg::Character msg)
{
    Sys_i_Instance_producer_producer_myCharacter_publisher_->publish(msg);
}

void producer_producer_base::put_myString(datatypes_system_cpp_pkg_interfaces::msg::String msg)
{
    Sys_i_Instance_producer_producer_myString_publisher_->publish(msg);
}

void producer_producer_base::put_myInt8(datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg)
{
    Sys_i_Instance_producer_producer_myInt8_publisher_->publish(msg);
}

void producer_producer_base::put_myInt16(datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg)
{
    Sys_i_Instance_producer_producer_myInt16_publisher_->publish(msg);
}

void producer_producer_base::put_myInt32(datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg)
{
    Sys_i_Instance_producer_producer_myInt32_publisher_->publish(msg);
}

void producer_producer_base::put_myInt64(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    Sys_i_Instance_producer_producer_myInt64_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt8(datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg)
{
    Sys_i_Instance_producer_producer_myUInt8_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt16(datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg)
{
    Sys_i_Instance_producer_producer_myUInt16_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt32(datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg)
{
    Sys_i_Instance_producer_producer_myUInt32_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt64(datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg)
{
    Sys_i_Instance_producer_producer_myUInt64_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat32(datatypes_system_cpp_pkg_interfaces::msg::Float32 msg)
{
    Sys_i_Instance_producer_producer_myFloat32_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat64(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    Sys_i_Instance_producer_producer_myFloat64_publisher_->publish(msg);
}

void producer_producer_base::put_myEnum(datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg)
{
    Sys_i_Instance_producer_producer_myEnum_publisher_->publish(msg);
}

void producer_producer_base::put_myStruct(datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg)
{
    Sys_i_Instance_producer_producer_myStruct_publisher_->publish(msg);
}

void producer_producer_base::put_myArray1(datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg)
{
    Sys_i_Instance_producer_producer_myArray1_publisher_->publish(msg);
}

void producer_producer_base::put_myArray2(datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg)
{
    Sys_i_Instance_producer_producer_myArray2_publisher_->publish(msg);
}

