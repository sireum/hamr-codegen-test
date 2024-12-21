#include "datatypes_system_cpp_pkg/base_headers/producer_producer_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

producer_producer_base::producer_producer_base() : Node("producer_producer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    // Setting up connections
    producer_producer_myBoolean_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(
        "consumer_consumer_myBoolean",
        1);

    producer_producer_myInteger_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "consumer_consumer_myInteger",
        1);

    producer_producer_myFloat_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "consumer_consumer_myFloat",
        1);

    producer_producer_myCharacter_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Character>(
        "consumer_consumer_myCharacter",
        1);

    producer_producer_myString_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::String>(
        "consumer_consumer_myString",
        1);

    producer_producer_myInt8_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(
        "consumer_consumer_myInt8",
        1);

    producer_producer_myInt16_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(
        "consumer_consumer_myInt16",
        1);

    producer_producer_myInt32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(
        "consumer_consumer_myInt32",
        1);

    producer_producer_myInt64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "consumer_consumer_myInt64",
        1);

    producer_producer_myUInt8_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(
        "consumer_consumer_myUInt8",
        1);

    producer_producer_myUInt16_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(
        "consumer_consumer_myUInt16",
        1);

    producer_producer_myUInt32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(
        "consumer_consumer_myUInt32",
        1);

    producer_producer_myUInt64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(
        "consumer_consumer_myUInt64",
        1);

    producer_producer_myFloat32_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float32>(
        "consumer_consumer_myFloat32",
        1);

    producer_producer_myFloat64_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "consumer_consumer_myFloat64",
        1);

    producer_producer_myEnum_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(
        "consumer_consumer_myEnum",
        1);

    producer_producer_myStruct_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(
        "consumer_consumer_myStruct",
        1);

    producer_producer_myArray1_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(
        "consumer_consumer_myArray1",
        1);

    producer_producer_myArray2_publisher_ = this->create_publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(
        "consumer_consumer_myArray2",
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
    producer_producer_myBoolean_publisher_->publish(msg);
}

void producer_producer_base::put_myInteger(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    producer_producer_myInteger_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    producer_producer_myFloat_publisher_->publish(msg);
}

void producer_producer_base::put_myCharacter(datatypes_system_cpp_pkg_interfaces::msg::Character msg)
{
    producer_producer_myCharacter_publisher_->publish(msg);
}

void producer_producer_base::put_myString(datatypes_system_cpp_pkg_interfaces::msg::String msg)
{
    producer_producer_myString_publisher_->publish(msg);
}

void producer_producer_base::put_myInt8(datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg)
{
    producer_producer_myInt8_publisher_->publish(msg);
}

void producer_producer_base::put_myInt16(datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg)
{
    producer_producer_myInt16_publisher_->publish(msg);
}

void producer_producer_base::put_myInt32(datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg)
{
    producer_producer_myInt32_publisher_->publish(msg);
}

void producer_producer_base::put_myInt64(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    producer_producer_myInt64_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt8(datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg)
{
    producer_producer_myUInt8_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt16(datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg)
{
    producer_producer_myUInt16_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt32(datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg)
{
    producer_producer_myUInt32_publisher_->publish(msg);
}

void producer_producer_base::put_myUInt64(datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg)
{
    producer_producer_myUInt64_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat32(datatypes_system_cpp_pkg_interfaces::msg::Float32 msg)
{
    producer_producer_myFloat32_publisher_->publish(msg);
}

void producer_producer_base::put_myFloat64(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    producer_producer_myFloat64_publisher_->publish(msg);
}

void producer_producer_base::put_myEnum(datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg)
{
    producer_producer_myEnum_publisher_->publish(msg);
}

void producer_producer_base::put_myStruct(datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg)
{
    producer_producer_myStruct_publisher_->publish(msg);
}

void producer_producer_base::put_myArray1(datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg)
{
    producer_producer_myArray1_publisher_->publish(msg);
}

void producer_producer_base::put_myArray2(datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg)
{
    producer_producer_myArray2_publisher_->publish(msg);
}

