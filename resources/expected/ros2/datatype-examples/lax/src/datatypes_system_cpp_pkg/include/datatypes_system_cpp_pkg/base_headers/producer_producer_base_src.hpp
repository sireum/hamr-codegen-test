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
#include "datatypes_system_cpp_pkg_interfaces/msg/my_array_two_dim.hpp"
#include <queue>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class producer_producer_base : public rclcpp::Node
{
protected:
    producer_producer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) datatypes_system_cpp_pkg_interfaces::msg::to_yaml(*message).c_str()
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
    void put_myArray3(datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim msg);

private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr producer_producer_myBoolean_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr producer_producer_myInteger_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr producer_producer_myFloat_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Character>::SharedPtr producer_producer_myCharacter_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::String>::SharedPtr producer_producer_myString_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer8>::SharedPtr producer_producer_myInt8_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer16>::SharedPtr producer_producer_myInt16_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer32>::SharedPtr producer_producer_myInt32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr producer_producer_myInt64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>::SharedPtr producer_producer_myUInt8_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>::SharedPtr producer_producer_myUInt16_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>::SharedPtr producer_producer_myUInt32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>::SharedPtr producer_producer_myUInt64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float32>::SharedPtr producer_producer_myFloat32_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr producer_producer_myFloat64_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>::SharedPtr producer_producer_myEnum_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>::SharedPtr producer_producer_myStruct_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>::SharedPtr producer_producer_myArray1_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>::SharedPtr producer_producer_myArray2_publisher_;
    rclcpp::Publisher<datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim>::SharedPtr producer_producer_myArray3_publisher_;

    //=================================================
    //  C a l l b a c k   a n d   T i m e r
    //=================================================
    virtual void timeTriggered() = 0;

    rclcpp::TimerBase::SharedPtr periodTimer_;

};
