#include "rclcpp/rclcpp.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/boolean.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/integer64.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/float64.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/character.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/string.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/integer8.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/integer16.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/integer32.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/unsigned8.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/unsigned16.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/unsigned32.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/unsigned64.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/float32.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/my_enum.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/my_structi.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/my_array_one_dim.hpp"
#include "datatypes_system_cpp_pkg_interfaces/msg/my_array_unbounded.hpp"
#include <queue>
#include <vector>
#include <variant>
#include <mutex>

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class producer_producer_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<datatypes_system_cpp_pkg_interfaces::msg::Boolean, datatypes_system_cpp_pkg_interfaces::msg::Integer64, datatypes_system_cpp_pkg_interfaces::msg::Float64, datatypes_system_cpp_pkg_interfaces::msg::Character, datatypes_system_cpp_pkg_interfaces::msg::String, datatypes_system_cpp_pkg_interfaces::msg::Integer8, datatypes_system_cpp_pkg_interfaces::msg::Integer16, datatypes_system_cpp_pkg_interfaces::msg::Integer32, datatypes_system_cpp_pkg_interfaces::msg::Unsigned8, datatypes_system_cpp_pkg_interfaces::msg::Unsigned16, datatypes_system_cpp_pkg_interfaces::msg::Unsigned32, datatypes_system_cpp_pkg_interfaces::msg::Unsigned64, datatypes_system_cpp_pkg_interfaces::msg::Float32, datatypes_system_cpp_pkg_interfaces::msg::MyEnum, datatypes_system_cpp_pkg_interfaces::msg::MyStructi, datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim, datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>;

    producer_producer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)

    void put_myBoolean(datatypes_system_cpp_pkg_interfaces::msg::Boolean msg);
    void put_myInteger(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void put_myFloat(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void put_myCharacter(datatypes_system_cpp_pkg_interfaces::msg::Character msg);
    void put_myString(datatypes_system_cpp_pkg_interfaces::msg::String msg);
    void put_myInt8(datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg);
    void put_myInt16(datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg);
    void put_myInt32(datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg);
    void put_myInt64(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void put_myUInt8(datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg);
    void put_myUInt16(datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg);
    void put_myUInt32(datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg);
    void put_myUInt64(datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg);
    void put_myFloat32(datatypes_system_cpp_pkg_interfaces::msg::Float32 msg);
    void put_myFloat64(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void put_myEnum(datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg);
    void put_myStruct(datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg);
    void put_myArray1(datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg);
    void put_myArray2(datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // Methods for working with port queues
    void receiveInputs();

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    std::queue<MsgType> infrastructureOut_myBoolean;
    std::queue<MsgType> applicationOut_myBoolean;
    std::queue<MsgType> infrastructureOut_myInteger;
    std::queue<MsgType> applicationOut_myInteger;
    std::queue<MsgType> infrastructureOut_myFloat;
    std::queue<MsgType> applicationOut_myFloat;
    std::queue<MsgType> infrastructureOut_myCharacter;
    std::queue<MsgType> applicationOut_myCharacter;
    std::queue<MsgType> infrastructureOut_myString;
    std::queue<MsgType> applicationOut_myString;
    std::queue<MsgType> infrastructureOut_myInt8;
    std::queue<MsgType> applicationOut_myInt8;
    std::queue<MsgType> infrastructureOut_myInt16;
    std::queue<MsgType> applicationOut_myInt16;
    std::queue<MsgType> infrastructureOut_myInt32;
    std::queue<MsgType> applicationOut_myInt32;
    std::queue<MsgType> infrastructureOut_myInt64;
    std::queue<MsgType> applicationOut_myInt64;
    std::queue<MsgType> infrastructureOut_myUInt8;
    std::queue<MsgType> applicationOut_myUInt8;
    std::queue<MsgType> infrastructureOut_myUInt16;
    std::queue<MsgType> applicationOut_myUInt16;
    std::queue<MsgType> infrastructureOut_myUInt32;
    std::queue<MsgType> applicationOut_myUInt32;
    std::queue<MsgType> infrastructureOut_myUInt64;
    std::queue<MsgType> applicationOut_myUInt64;
    std::queue<MsgType> infrastructureOut_myFloat32;
    std::queue<MsgType> applicationOut_myFloat32;
    std::queue<MsgType> infrastructureOut_myFloat64;
    std::queue<MsgType> applicationOut_myFloat64;
    std::queue<MsgType> infrastructureOut_myEnum;
    std::queue<MsgType> applicationOut_myEnum;
    std::queue<MsgType> infrastructureOut_myStruct;
    std::queue<MsgType> applicationOut_myStruct;
    std::queue<MsgType> infrastructureOut_myArray1;
    std::queue<MsgType> applicationOut_myArray1;
    std::queue<MsgType> infrastructureOut_myArray2;
    std::queue<MsgType> applicationOut_myArray2;

    void sendOut_myBoolean(MsgType msg);
    void sendOut_myInteger(MsgType msg);
    void sendOut_myFloat(MsgType msg);
    void sendOut_myCharacter(MsgType msg);
    void sendOut_myString(MsgType msg);
    void sendOut_myInt8(MsgType msg);
    void sendOut_myInt16(MsgType msg);
    void sendOut_myInt32(MsgType msg);
    void sendOut_myInt64(MsgType msg);
    void sendOut_myUInt8(MsgType msg);
    void sendOut_myUInt16(MsgType msg);
    void sendOut_myUInt32(MsgType msg);
    void sendOut_myUInt64(MsgType msg);
    void sendOut_myFloat32(MsgType msg);
    void sendOut_myFloat64(MsgType msg);
    void sendOut_myEnum(MsgType msg);
    void sendOut_myStruct(MsgType msg);
    void sendOut_myArray1(MsgType msg);
    void sendOut_myArray2(MsgType msg);

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr Sys_i_Instance_producer_producer_myBoolean_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr Sys_i_Instance_producer_producer_myInteger_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr Sys_i_Instance_producer_producer_myFloat_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Character>::SharedPtr Sys_i_Instance_producer_producer_myCharacter_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::String>::SharedPtr Sys_i_Instance_producer_producer_myString_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer8>::SharedPtr Sys_i_Instance_producer_producer_myInt8_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer16>::SharedPtr Sys_i_Instance_producer_producer_myInt16_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer32>::SharedPtr Sys_i_Instance_producer_producer_myInt32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr Sys_i_Instance_producer_producer_myInt64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>::SharedPtr Sys_i_Instance_producer_producer_myUInt8_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>::SharedPtr Sys_i_Instance_producer_producer_myUInt16_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>::SharedPtr Sys_i_Instance_producer_producer_myUInt32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>::SharedPtr Sys_i_Instance_producer_producer_myUInt64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float32>::SharedPtr Sys_i_Instance_producer_producer_myFloat32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr Sys_i_Instance_producer_producer_myFloat64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>::SharedPtr Sys_i_Instance_producer_producer_myEnum_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>::SharedPtr Sys_i_Instance_producer_producer_myStruct_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>::SharedPtr Sys_i_Instance_producer_producer_myArray1_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>::SharedPtr Sys_i_Instance_producer_producer_myArray2_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

    void timeTriggeredCaller();

    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inEventPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (producer_producer_base::*)(MsgType)>> outPortTupleVector;
};
