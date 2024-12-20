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

    // timeTriggeredCaller callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&producer_producer_base::timeTriggeredCaller, this), cb_group_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by receiveInputs
    inEventPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
        {&applicationOut_myBoolean, &infrastructureOut_myBoolean, &producer_producer_base::sendOut_myBoolean},
        {&applicationOut_myInteger, &infrastructureOut_myInteger, &producer_producer_base::sendOut_myInteger},
        {&applicationOut_myFloat, &infrastructureOut_myFloat, &producer_producer_base::sendOut_myFloat},
        {&applicationOut_myCharacter, &infrastructureOut_myCharacter, &producer_producer_base::sendOut_myCharacter},
        {&applicationOut_myString, &infrastructureOut_myString, &producer_producer_base::sendOut_myString},
        {&applicationOut_myInt8, &infrastructureOut_myInt8, &producer_producer_base::sendOut_myInt8},
        {&applicationOut_myInt16, &infrastructureOut_myInt16, &producer_producer_base::sendOut_myInt16},
        {&applicationOut_myInt32, &infrastructureOut_myInt32, &producer_producer_base::sendOut_myInt32},
        {&applicationOut_myInt64, &infrastructureOut_myInt64, &producer_producer_base::sendOut_myInt64},
        {&applicationOut_myUInt8, &infrastructureOut_myUInt8, &producer_producer_base::sendOut_myUInt8},
        {&applicationOut_myUInt16, &infrastructureOut_myUInt16, &producer_producer_base::sendOut_myUInt16},
        {&applicationOut_myUInt32, &infrastructureOut_myUInt32, &producer_producer_base::sendOut_myUInt32},
        {&applicationOut_myUInt64, &infrastructureOut_myUInt64, &producer_producer_base::sendOut_myUInt64},
        {&applicationOut_myFloat32, &infrastructureOut_myFloat32, &producer_producer_base::sendOut_myFloat32},
        {&applicationOut_myFloat64, &infrastructureOut_myFloat64, &producer_producer_base::sendOut_myFloat64},
        {&applicationOut_myEnum, &infrastructureOut_myEnum, &producer_producer_base::sendOut_myEnum},
        {&applicationOut_myStruct, &infrastructureOut_myStruct, &producer_producer_base::sendOut_myStruct},
        {&applicationOut_myArray1, &infrastructureOut_myArray1, &producer_producer_base::sendOut_myArray1},
        {&applicationOut_myArray2, &infrastructureOut_myArray2, &producer_producer_base::sendOut_myArray2}
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void producer_producer_base::sendOut_myBoolean(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(&msg)) {
        Sys_i_Instance_producer_producer_myBoolean_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myInteger(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        Sys_i_Instance_producer_producer_myInteger_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myFloat(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float64>(&msg)) {
        Sys_i_Instance_producer_producer_myFloat_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myCharacter(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Character>(&msg)) {
        Sys_i_Instance_producer_producer_myCharacter_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myString(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::String>(&msg)) {
        Sys_i_Instance_producer_producer_myString_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myInt8(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(&msg)) {
        Sys_i_Instance_producer_producer_myInt8_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myInt16(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(&msg)) {
        Sys_i_Instance_producer_producer_myInt16_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myInt32(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(&msg)) {
        Sys_i_Instance_producer_producer_myInt32_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myInt64(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        Sys_i_Instance_producer_producer_myInt64_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myUInt8(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(&msg)) {
        Sys_i_Instance_producer_producer_myUInt8_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myUInt16(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(&msg)) {
        Sys_i_Instance_producer_producer_myUInt16_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myUInt32(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(&msg)) {
        Sys_i_Instance_producer_producer_myUInt32_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myUInt64(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(&msg)) {
        Sys_i_Instance_producer_producer_myUInt64_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myFloat32(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float32>(&msg)) {
        Sys_i_Instance_producer_producer_myFloat32_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myFloat64(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float64>(&msg)) {
        Sys_i_Instance_producer_producer_myFloat64_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myEnum(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(&msg)) {
        Sys_i_Instance_producer_producer_myEnum_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myStruct(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(&msg)) {
        Sys_i_Instance_producer_producer_myStruct_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myArray1(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(&msg)) {
        Sys_i_Instance_producer_producer_myArray1_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::sendOut_myArray2(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(&msg)) {
        Sys_i_Instance_producer_producer_myArray2_publisher_->publish(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void producer_producer_base::put_myBoolean(datatypes_system_cpp_pkg_interfaces::msg::Boolean msg)
{
    enqueue(applicationOut_myBoolean, msg);
}

void producer_producer_base::put_myInteger(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    enqueue(applicationOut_myInteger, msg);
}

void producer_producer_base::put_myFloat(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    enqueue(applicationOut_myFloat, msg);
}

void producer_producer_base::put_myCharacter(datatypes_system_cpp_pkg_interfaces::msg::Character msg)
{
    enqueue(applicationOut_myCharacter, msg);
}

void producer_producer_base::put_myString(datatypes_system_cpp_pkg_interfaces::msg::String msg)
{
    enqueue(applicationOut_myString, msg);
}

void producer_producer_base::put_myInt8(datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg)
{
    enqueue(applicationOut_myInt8, msg);
}

void producer_producer_base::put_myInt16(datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg)
{
    enqueue(applicationOut_myInt16, msg);
}

void producer_producer_base::put_myInt32(datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg)
{
    enqueue(applicationOut_myInt32, msg);
}

void producer_producer_base::put_myInt64(datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg)
{
    enqueue(applicationOut_myInt64, msg);
}

void producer_producer_base::put_myUInt8(datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg)
{
    enqueue(applicationOut_myUInt8, msg);
}

void producer_producer_base::put_myUInt16(datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg)
{
    enqueue(applicationOut_myUInt16, msg);
}

void producer_producer_base::put_myUInt32(datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg)
{
    enqueue(applicationOut_myUInt32, msg);
}

void producer_producer_base::put_myUInt64(datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg)
{
    enqueue(applicationOut_myUInt64, msg);
}

void producer_producer_base::put_myFloat32(datatypes_system_cpp_pkg_interfaces::msg::Float32 msg)
{
    enqueue(applicationOut_myFloat32, msg);
}

void producer_producer_base::put_myFloat64(datatypes_system_cpp_pkg_interfaces::msg::Float64 msg)
{
    enqueue(applicationOut_myFloat64, msg);
}

void producer_producer_base::put_myEnum(datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg)
{
    enqueue(applicationOut_myEnum, msg);
}

void producer_producer_base::put_myStruct(datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg)
{
    enqueue(applicationOut_myStruct, msg);
}

void producer_producer_base::put_myArray1(datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg)
{
    enqueue(applicationOut_myArray1, msg);
}

void producer_producer_base::put_myArray2(datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg)
{
    enqueue(applicationOut_myArray2, msg);
}

void producer_producer_base::timeTriggeredCaller() {
    receiveInputs();
    timeTriggered();
    sendOutputs();
}

void producer_producer_base::receiveInputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inDataPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            enqueue(*std::get<1>(port), msg);
        }
    }
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inEventPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }
}

void producer_producer_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void producer_producer_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (producer_producer_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (producer_producer_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
