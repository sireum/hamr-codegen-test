#include "datatypes_system_cpp_pkg/user_headers/producer_producer_src.hpp"
#include "datatypes_system_cpp_pkg/base_headers/enum_converter.hpp"

//===========================================================
// This file will not be overwritten when re-running Codegen
//===========================================================

//=================================================
//  I n i t i a l i z e    E n t r y    P o i n t
//=================================================
void producer_producer::initialize()
{
    PRINT_INFO("Initialize Entry Point invoked");

    // Initialize the node
}

//=================================================
//  C o m p u t e    E n t r y    P o i n t
//=================================================
void producer_producer::timeTriggered()
{
    // Handle communication

    // Example publishing messages
    datatypes_system_cpp_pkg_interfaces::msg::Boolean myBoolean = datatypes_system_cpp_pkg_interfaces::msg::Boolean();
    put_myBoolean(myBoolean);
    datatypes_system_cpp_pkg_interfaces::msg::Integer64 myInteger = datatypes_system_cpp_pkg_interfaces::msg::Integer64();
    put_myInteger(myInteger);
    datatypes_system_cpp_pkg_interfaces::msg::Float64 myFloat = datatypes_system_cpp_pkg_interfaces::msg::Float64();
    put_myFloat(myFloat);
    datatypes_system_cpp_pkg_interfaces::msg::Character myCharacter = datatypes_system_cpp_pkg_interfaces::msg::Character();
    put_myCharacter(myCharacter);
    datatypes_system_cpp_pkg_interfaces::msg::String myString = datatypes_system_cpp_pkg_interfaces::msg::String();
    put_myString(myString);
    datatypes_system_cpp_pkg_interfaces::msg::Integer8 myInt8 = datatypes_system_cpp_pkg_interfaces::msg::Integer8();
    put_myInt8(myInt8);
    datatypes_system_cpp_pkg_interfaces::msg::Integer16 myInt16 = datatypes_system_cpp_pkg_interfaces::msg::Integer16();
    put_myInt16(myInt16);
    datatypes_system_cpp_pkg_interfaces::msg::Integer32 myInt32 = datatypes_system_cpp_pkg_interfaces::msg::Integer32();
    put_myInt32(myInt32);
    datatypes_system_cpp_pkg_interfaces::msg::Integer64 myInt64 = datatypes_system_cpp_pkg_interfaces::msg::Integer64();
    put_myInt64(myInt64);
    datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 myUInt8 = datatypes_system_cpp_pkg_interfaces::msg::Unsigned8();
    put_myUInt8(myUInt8);
    datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 myUInt16 = datatypes_system_cpp_pkg_interfaces::msg::Unsigned16();
    put_myUInt16(myUInt16);
    datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 myUInt32 = datatypes_system_cpp_pkg_interfaces::msg::Unsigned32();
    put_myUInt32(myUInt32);
    datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 myUInt64 = datatypes_system_cpp_pkg_interfaces::msg::Unsigned64();
    put_myUInt64(myUInt64);
    datatypes_system_cpp_pkg_interfaces::msg::Float32 myFloat32 = datatypes_system_cpp_pkg_interfaces::msg::Float32();
    put_myFloat32(myFloat32);
    datatypes_system_cpp_pkg_interfaces::msg::Float64 myFloat64 = datatypes_system_cpp_pkg_interfaces::msg::Float64();
    put_myFloat64(myFloat64);
    datatypes_system_cpp_pkg_interfaces::msg::MyEnum myEnum = datatypes_system_cpp_pkg_interfaces::msg::MyEnum();
    put_myEnum(myEnum);
    datatypes_system_cpp_pkg_interfaces::msg::MyStructi myStruct = datatypes_system_cpp_pkg_interfaces::msg::MyStructi();
    put_myStruct(myStruct);
    datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim myArray1 = datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim();
    put_myArray1(myArray1);
    datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded myArray2 = datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded();
    put_myArray2(myArray2);
    datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim myArray3 = datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim();
    put_myArray3(myArray3);
}

