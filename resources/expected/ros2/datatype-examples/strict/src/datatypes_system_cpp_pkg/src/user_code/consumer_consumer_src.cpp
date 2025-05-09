#include "datatypes_system_cpp_pkg/user_headers/consumer_consumer_src.hpp"
#include "datatypes_system_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void consumer_consumer::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void consumer_consumer::handle_myBoolean(const datatypes_system_cpp_pkg_interfaces::msg::Boolean msg)
{
    // Handle myBoolean msg
    PRINT_INFO("Received myBoolean: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myInteger(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    // Handle myInteger msg
    PRINT_INFO("Received myInteger: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myFloat(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    // Handle myFloat msg
    PRINT_INFO("Received myFloat: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myCharacter(const datatypes_system_cpp_pkg_interfaces::msg::Character msg)
{
    // Handle myCharacter msg
    PRINT_INFO("Received myCharacter: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myString(const datatypes_system_cpp_pkg_interfaces::msg::String msg)
{
    // Handle myString msg
    PRINT_INFO("Received myString: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myInt8(const datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg)
{
    // Handle myInt8 msg
    PRINT_INFO("Received myInt8: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myInt16(const datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg)
{
    // Handle myInt16 msg
    PRINT_INFO("Received myInt16: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myInt32(const datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg)
{
    // Handle myInt32 msg
    PRINT_INFO("Received myInt32: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myInt64(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    // Handle myInt64 msg
    PRINT_INFO("Received myInt64: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myUInt8(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg)
{
    // Handle myUInt8 msg
    PRINT_INFO("Received myUInt8: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myUInt16(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg)
{
    // Handle myUInt16 msg
    PRINT_INFO("Received myUInt16: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myUInt32(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg)
{
    // Handle myUInt32 msg
    PRINT_INFO("Received myUInt32: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myUInt64(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg)
{
    // Handle myUInt64 msg
    PRINT_INFO("Received myUInt64: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myFloat32(const datatypes_system_cpp_pkg_interfaces::msg::Float32 msg)
{
    // Handle myFloat32 msg
    PRINT_INFO("Received myFloat32: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myFloat64(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    // Handle myFloat64 msg
    PRINT_INFO("Received myFloat64: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myEnum(const datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg)
{
    // Handle myEnum msg
    PRINT_INFO("Received myEnum: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myStruct(const datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg)
{
    // Handle myStruct msg
    PRINT_INFO("Received myStruct: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myArray1(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg)
{
    // Handle myArray1 msg
    PRINT_INFO("Received myArray1: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myArray2(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg)
{
    // Handle myArray2 msg
    PRINT_INFO("Received myArray2: %s", MESSAGE_TO_STRING(msg));
}

void consumer_consumer::handle_myArray3(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim msg)
{
    // Handle myArray3 msg
    PRINT_INFO("Received myArray3: %s", MESSAGE_TO_STRING(msg));
}

