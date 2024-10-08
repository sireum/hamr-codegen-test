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

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

class Sys_i_Instance_consumer_consumer_base : public rclcpp::Node
{
protected:
    Sys_i_Instance_consumer_consumer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)


private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_myBoolean(const datatypes_system_cpp_pkg_interfaces::msg::Boolean::SharedPtr msg) = 0;
    virtual void handle_myInteger(const datatypes_system_cpp_pkg_interfaces::msg::Integer64::SharedPtr msg) = 0;
    virtual void handle_myFloat(const datatypes_system_cpp_pkg_interfaces::msg::Float64::SharedPtr msg) = 0;
    virtual void handle_myCharacter(const datatypes_system_cpp_pkg_interfaces::msg::Character::SharedPtr msg) = 0;
    virtual void handle_myString(const datatypes_system_cpp_pkg_interfaces::msg::String::SharedPtr msg) = 0;
    virtual void handle_myInt8(const datatypes_system_cpp_pkg_interfaces::msg::Integer8::SharedPtr msg) = 0;
    virtual void handle_myInt16(const datatypes_system_cpp_pkg_interfaces::msg::Integer16::SharedPtr msg) = 0;
    virtual void handle_myInt32(const datatypes_system_cpp_pkg_interfaces::msg::Integer32::SharedPtr msg) = 0;
    virtual void handle_myInt64(const datatypes_system_cpp_pkg_interfaces::msg::Integer64::SharedPtr msg) = 0;
    virtual void handle_myUInt8(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned8::SharedPtr msg) = 0;
    virtual void handle_myUInt16(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned16::SharedPtr msg) = 0;
    virtual void handle_myUInt32(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned32::SharedPtr msg) = 0;
    virtual void handle_myUInt64(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned64::SharedPtr msg) = 0;
    virtual void handle_myFloat32(const datatypes_system_cpp_pkg_interfaces::msg::Float32::SharedPtr msg) = 0;
    virtual void handle_myFloat64(const datatypes_system_cpp_pkg_interfaces::msg::Float64::SharedPtr msg) = 0;
    virtual void handle_myEnum(const datatypes_system_cpp_pkg_interfaces::msg::MyEnum::SharedPtr msg) = 0;
    virtual void handle_myStruct(const datatypes_system_cpp_pkg_interfaces::msg::MyStructi::SharedPtr msg) = 0;
    virtual void handle_myArray1(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim::SharedPtr msg) = 0;
    virtual void handle_myArray2(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded::SharedPtr msg) = 0;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr Sys_i_Instance_consumer_consumer_myBoolean_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr Sys_i_Instance_consumer_consumer_myInteger_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr Sys_i_Instance_consumer_consumer_myFloat_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Character>::SharedPtr Sys_i_Instance_consumer_consumer_myCharacter_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::String>::SharedPtr Sys_i_Instance_consumer_consumer_myString_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer8>::SharedPtr Sys_i_Instance_consumer_consumer_myInt8_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer16>::SharedPtr Sys_i_Instance_consumer_consumer_myInt16_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer32>::SharedPtr Sys_i_Instance_consumer_consumer_myInt32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr Sys_i_Instance_consumer_consumer_myInt64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>::SharedPtr Sys_i_Instance_consumer_consumer_myUInt8_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>::SharedPtr Sys_i_Instance_consumer_consumer_myUInt16_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>::SharedPtr Sys_i_Instance_consumer_consumer_myUInt32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>::SharedPtr Sys_i_Instance_consumer_consumer_myUInt64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float32>::SharedPtr Sys_i_Instance_consumer_consumer_myFloat32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr Sys_i_Instance_consumer_consumer_myFloat64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>::SharedPtr Sys_i_Instance_consumer_consumer_myEnum_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>::SharedPtr Sys_i_Instance_consumer_consumer_myStruct_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>::SharedPtr Sys_i_Instance_consumer_consumer_myArray1_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>::SharedPtr Sys_i_Instance_consumer_consumer_myArray2_subscription_;


};
