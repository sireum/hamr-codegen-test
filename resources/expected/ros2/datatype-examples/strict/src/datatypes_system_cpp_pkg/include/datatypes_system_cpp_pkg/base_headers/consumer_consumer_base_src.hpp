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
#include <vector>
#include <variant>
#include <mutex>

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

class consumer_consumer_base : public rclcpp::Node
{
protected:
    using MsgType = std::variant<datatypes_system_cpp_pkg_interfaces::msg::Boolean, datatypes_system_cpp_pkg_interfaces::msg::Integer64, datatypes_system_cpp_pkg_interfaces::msg::Float64, datatypes_system_cpp_pkg_interfaces::msg::Character, datatypes_system_cpp_pkg_interfaces::msg::String, datatypes_system_cpp_pkg_interfaces::msg::Integer8, datatypes_system_cpp_pkg_interfaces::msg::Integer16, datatypes_system_cpp_pkg_interfaces::msg::Integer32, datatypes_system_cpp_pkg_interfaces::msg::Unsigned8, datatypes_system_cpp_pkg_interfaces::msg::Unsigned16, datatypes_system_cpp_pkg_interfaces::msg::Unsigned32, datatypes_system_cpp_pkg_interfaces::msg::Unsigned64, datatypes_system_cpp_pkg_interfaces::msg::Float32, datatypes_system_cpp_pkg_interfaces::msg::MyEnum, datatypes_system_cpp_pkg_interfaces::msg::MyStructi, datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim, datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded, datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim>;

    consumer_consumer_base();

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================

    #define MESSAGE_TO_STRING(message) datatypes_system_cpp_pkg_interfaces::msg::to_yaml(message).c_str()
    #define PRINT_INFO(...) RCLCPP_INFO(this->get_logger(), __VA_ARGS__)
    #define PRINT_WARN(...) RCLCPP_WARN(this->get_logger(), __VA_ARGS__)
    #define PRINT_ERROR(...) RCLCPP_ERROR(this->get_logger(), __VA_ARGS__)


private:
    rclcpp::CallbackGroup::SharedPtr cb_group_;

    void accept_myBoolean(datatypes_system_cpp_pkg_interfaces::msg::Boolean msg);
    void accept_myInteger(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void accept_myFloat(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void accept_myCharacter(datatypes_system_cpp_pkg_interfaces::msg::Character msg);
    void accept_myString(datatypes_system_cpp_pkg_interfaces::msg::String msg);
    void accept_myInt8(datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg);
    void accept_myInt16(datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg);
    void accept_myInt32(datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg);
    void accept_myInt64(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg);
    void accept_myUInt8(datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg);
    void accept_myUInt16(datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg);
    void accept_myUInt32(datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg);
    void accept_myUInt64(datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg);
    void accept_myFloat32(datatypes_system_cpp_pkg_interfaces::msg::Float32 msg);
    void accept_myFloat64(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg);
    void accept_myEnum(datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg);
    void accept_myStruct(datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg);
    void accept_myArray1(datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg);
    void accept_myArray2(datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg);
    void accept_myArray3(datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim msg);

    // Methods for working with port queues
    void receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue);

    void sendOutputs();

    void enqueue(std::queue<MsgType>& queue, MsgType val);

    // SubscriptionOptions for assigning subscriptions to the callback group
    rclcpp::SubscriptionOptions subscription_options_;

    void dataSubscriptionHandler(MsgType msg, std::queue<MsgType>& queue);

    void eventSubscriptionHandler(MsgType msg, std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue, void (consumer_consumer_base::*handleMsg)(MsgType));


    //=================================================
    //  C o m p u t e    E n t r y    P o i n t
    //=================================================
    virtual void handle_myBoolean(const datatypes_system_cpp_pkg_interfaces::msg::Boolean msg) = 0;
    void handle_myBoolean_base(MsgType msg);
    virtual void handle_myInteger(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg) = 0;
    void handle_myInteger_base(MsgType msg);
    virtual void handle_myFloat(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg) = 0;
    void handle_myFloat_base(MsgType msg);
    virtual void handle_myCharacter(const datatypes_system_cpp_pkg_interfaces::msg::Character msg) = 0;
    void handle_myCharacter_base(MsgType msg);
    virtual void handle_myString(const datatypes_system_cpp_pkg_interfaces::msg::String msg) = 0;
    void handle_myString_base(MsgType msg);
    virtual void handle_myInt8(const datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg) = 0;
    void handle_myInt8_base(MsgType msg);
    virtual void handle_myInt16(const datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg) = 0;
    void handle_myInt16_base(MsgType msg);
    virtual void handle_myInt32(const datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg) = 0;
    void handle_myInt32_base(MsgType msg);
    virtual void handle_myInt64(const datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg) = 0;
    void handle_myInt64_base(MsgType msg);
    virtual void handle_myUInt8(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg) = 0;
    void handle_myUInt8_base(MsgType msg);
    virtual void handle_myUInt16(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg) = 0;
    void handle_myUInt16_base(MsgType msg);
    virtual void handle_myUInt32(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg) = 0;
    void handle_myUInt32_base(MsgType msg);
    virtual void handle_myUInt64(const datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg) = 0;
    void handle_myUInt64_base(MsgType msg);
    virtual void handle_myFloat32(const datatypes_system_cpp_pkg_interfaces::msg::Float32 msg) = 0;
    void handle_myFloat32_base(MsgType msg);
    virtual void handle_myFloat64(const datatypes_system_cpp_pkg_interfaces::msg::Float64 msg) = 0;
    void handle_myFloat64_base(MsgType msg);
    virtual void handle_myEnum(const datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg) = 0;
    void handle_myEnum_base(MsgType msg);
    virtual void handle_myStruct(const datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg) = 0;
    void handle_myStruct_base(MsgType msg);
    virtual void handle_myArray1(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg) = 0;
    void handle_myArray1_base(MsgType msg);
    virtual void handle_myArray2(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg) = 0;
    void handle_myArray2_base(MsgType msg);
    virtual void handle_myArray3(const datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim msg) = 0;
    void handle_myArray3_base(MsgType msg);

    std::queue<MsgType> infrastructureIn_myBoolean;
    std::queue<MsgType> applicationIn_myBoolean;
    std::queue<MsgType> infrastructureIn_myInteger;
    std::queue<MsgType> applicationIn_myInteger;
    std::queue<MsgType> infrastructureIn_myFloat;
    std::queue<MsgType> applicationIn_myFloat;
    std::queue<MsgType> infrastructureIn_myCharacter;
    std::queue<MsgType> applicationIn_myCharacter;
    std::queue<MsgType> infrastructureIn_myString;
    std::queue<MsgType> applicationIn_myString;
    std::queue<MsgType> infrastructureIn_myInt8;
    std::queue<MsgType> applicationIn_myInt8;
    std::queue<MsgType> infrastructureIn_myInt16;
    std::queue<MsgType> applicationIn_myInt16;
    std::queue<MsgType> infrastructureIn_myInt32;
    std::queue<MsgType> applicationIn_myInt32;
    std::queue<MsgType> infrastructureIn_myInt64;
    std::queue<MsgType> applicationIn_myInt64;
    std::queue<MsgType> infrastructureIn_myUInt8;
    std::queue<MsgType> applicationIn_myUInt8;
    std::queue<MsgType> infrastructureIn_myUInt16;
    std::queue<MsgType> applicationIn_myUInt16;
    std::queue<MsgType> infrastructureIn_myUInt32;
    std::queue<MsgType> applicationIn_myUInt32;
    std::queue<MsgType> infrastructureIn_myUInt64;
    std::queue<MsgType> applicationIn_myUInt64;
    std::queue<MsgType> infrastructureIn_myFloat32;
    std::queue<MsgType> applicationIn_myFloat32;
    std::queue<MsgType> infrastructureIn_myFloat64;
    std::queue<MsgType> applicationIn_myFloat64;
    std::queue<MsgType> infrastructureIn_myEnum;
    std::queue<MsgType> applicationIn_myEnum;
    std::queue<MsgType> infrastructureIn_myStruct;
    std::queue<MsgType> applicationIn_myStruct;
    std::queue<MsgType> infrastructureIn_myArray1;
    std::queue<MsgType> applicationIn_myArray1;
    std::queue<MsgType> infrastructureIn_myArray2;
    std::queue<MsgType> applicationIn_myArray2;
    std::queue<MsgType> infrastructureIn_myArray3;
    std::queue<MsgType> applicationIn_myArray3;

    //=================================================
    //  C o m m u n i c a t i o n
    //=================================================
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Boolean>::SharedPtr consumer_consumer_myBoolean_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr consumer_consumer_myInteger_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr consumer_consumer_myFloat_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Character>::SharedPtr consumer_consumer_myCharacter_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::String>::SharedPtr consumer_consumer_myString_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer8>::SharedPtr consumer_consumer_myInt8_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer16>::SharedPtr consumer_consumer_myInt16_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer32>::SharedPtr consumer_consumer_myInt32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>::SharedPtr consumer_consumer_myInt64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>::SharedPtr consumer_consumer_myUInt8_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>::SharedPtr consumer_consumer_myUInt16_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>::SharedPtr consumer_consumer_myUInt32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>::SharedPtr consumer_consumer_myUInt64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float32>::SharedPtr consumer_consumer_myFloat32_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>::SharedPtr consumer_consumer_myFloat64_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>::SharedPtr consumer_consumer_myEnum_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>::SharedPtr consumer_consumer_myStruct_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>::SharedPtr consumer_consumer_myArray1_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>::SharedPtr consumer_consumer_myArray2_subscription_;
    rclcpp::Subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayTwoDim>::SharedPtr consumer_consumer_myArray3_subscription_;


    // Used for thread locking
    std::mutex mutex_;

    // Used by receiveInputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*>> inDataPortTupleVector;
    // Used by sendOutputs
    std::vector<std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (consumer_consumer_base::*)(MsgType)>> outPortTupleVector;
};
