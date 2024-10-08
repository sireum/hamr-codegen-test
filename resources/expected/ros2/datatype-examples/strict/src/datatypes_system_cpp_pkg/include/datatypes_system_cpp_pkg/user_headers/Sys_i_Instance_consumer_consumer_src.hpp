#include "datatypes_system_cpp_pkg/base_headers/Sys_i_Instance_consumer_consumer_base_src.hpp"

class Sys_i_Instance_consumer_consumer : public Sys_i_Instance_consumer_consumer_base
{
public:
    Sys_i_Instance_consumer_consumer();

private:
    //=================================================
    //  I n i t i a l i z e    E n t r y    P o i n t
    //=================================================
    void initialize();

    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    void handle_myBoolean(const datatypes_system_cpp_pkg_interfaces::msg::Boolean msg);
    void handle_myInteger(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void handle_myFloat(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void handle_myCharacter(const datatypes_system_cpp_pkg_interfaces::msg::Character msg);
    void handle_myString(const datatypes_system_cpp_pkg_interfaces::msg::String msg);
    void handle_myInt8(const datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg);
    void handle_myInt16(const datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg);
    void handle_myInt32(const datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg);
    void handle_myInt64(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void handle_myUInt8(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg);
    void handle_myUInt16(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg);
    void handle_myUInt32(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg);
    void handle_myUInt64(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg);
    void handle_myFloat32(const datatypes_system_cpp_pkg_interfaces::msg::Float32 msg);
    void handle_myFloat64(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void handle_myEnum(const datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg);
    void handle_myStruct(const datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg);
    void handle_myArray1(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg);
    void handle_myArray2(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg);

    //=================================================
    //  Include any additional declarations here
    //=================================================

};
