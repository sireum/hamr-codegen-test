#include "datatypes_system_cpp_pkg/base_headers/Sys_i_Instance_consumer_consumer_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

Sys_i_Instance_consumer_consumer_base::Sys_i_Instance_consumer_consumer_base() : Node("Sys_i_Instance_consumer_consumer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    Sys_i_Instance_consumer_consumer_myBoolean_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(
        "Sys_i_Instance_consumer_consumer_myBoolean",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Boolean msg) {
            enqueue(infrastructureIn_myBoolean, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myBoolean, applicationIn_myBoolean);
                if (applicationIn_myBoolean.empty()) return;
                handle_myBoolean_base(applicationIn_myBoolean.front());
                applicationIn_myBoolean.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myInteger_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInteger",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg) {
            enqueue(infrastructureIn_myInteger, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myInteger, applicationIn_myInteger);
                if (applicationIn_myInteger.empty()) return;
                handle_myInteger_base(applicationIn_myInteger.front());
                applicationIn_myInteger.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Float64 msg) {
            enqueue(infrastructureIn_myFloat, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myFloat, applicationIn_myFloat);
                if (applicationIn_myFloat.empty()) return;
                handle_myFloat_base(applicationIn_myFloat.front());
                applicationIn_myFloat.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myCharacter_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Character>(
        "Sys_i_Instance_consumer_consumer_myCharacter",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Character msg) {
            enqueue(infrastructureIn_myCharacter, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myCharacter, applicationIn_myCharacter);
                if (applicationIn_myCharacter.empty()) return;
                handle_myCharacter_base(applicationIn_myCharacter.front());
                applicationIn_myCharacter.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myString_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::String>(
        "Sys_i_Instance_consumer_consumer_myString",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::String msg) {
            enqueue(infrastructureIn_myString, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myString, applicationIn_myString);
                if (applicationIn_myString.empty()) return;
                handle_myString_base(applicationIn_myString.front());
                applicationIn_myString.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt8_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(
        "Sys_i_Instance_consumer_consumer_myInt8",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Integer8 msg) {
            enqueue(infrastructureIn_myInt8, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myInt8, applicationIn_myInt8);
                if (applicationIn_myInt8.empty()) return;
                handle_myInt8_base(applicationIn_myInt8.front());
                applicationIn_myInt8.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt16_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(
        "Sys_i_Instance_consumer_consumer_myInt16",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Integer16 msg) {
            enqueue(infrastructureIn_myInt16, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myInt16, applicationIn_myInt16);
                if (applicationIn_myInt16.empty()) return;
                handle_myInt16_base(applicationIn_myInt16.front());
                applicationIn_myInt16.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(
        "Sys_i_Instance_consumer_consumer_myInt32",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Integer32 msg) {
            enqueue(infrastructureIn_myInt32, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myInt32, applicationIn_myInt32);
                if (applicationIn_myInt32.empty()) return;
                handle_myInt32_base(applicationIn_myInt32.front());
                applicationIn_myInt32.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myInt64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(
        "Sys_i_Instance_consumer_consumer_myInt64",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Integer64 msg) {
            enqueue(infrastructureIn_myInt64, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myInt64, applicationIn_myInt64);
                if (applicationIn_myInt64.empty()) return;
                handle_myInt64_base(applicationIn_myInt64.front());
                applicationIn_myInt64.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt8_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(
        "Sys_i_Instance_consumer_consumer_myUInt8",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Unsigned8 msg) {
            enqueue(infrastructureIn_myUInt8, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myUInt8, applicationIn_myUInt8);
                if (applicationIn_myUInt8.empty()) return;
                handle_myUInt8_base(applicationIn_myUInt8.front());
                applicationIn_myUInt8.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt16_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(
        "Sys_i_Instance_consumer_consumer_myUInt16",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Unsigned16 msg) {
            enqueue(infrastructureIn_myUInt16, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myUInt16, applicationIn_myUInt16);
                if (applicationIn_myUInt16.empty()) return;
                handle_myUInt16_base(applicationIn_myUInt16.front());
                applicationIn_myUInt16.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(
        "Sys_i_Instance_consumer_consumer_myUInt32",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Unsigned32 msg) {
            enqueue(infrastructureIn_myUInt32, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myUInt32, applicationIn_myUInt32);
                if (applicationIn_myUInt32.empty()) return;
                handle_myUInt32_base(applicationIn_myUInt32.front());
                applicationIn_myUInt32.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myUInt64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(
        "Sys_i_Instance_consumer_consumer_myUInt64",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Unsigned64 msg) {
            enqueue(infrastructureIn_myUInt64, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myUInt64, applicationIn_myUInt64);
                if (applicationIn_myUInt64.empty()) return;
                handle_myUInt64_base(applicationIn_myUInt64.front());
                applicationIn_myUInt64.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat32_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float32>(
        "Sys_i_Instance_consumer_consumer_myFloat32",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Float32 msg) {
            enqueue(infrastructureIn_myFloat32, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myFloat32, applicationIn_myFloat32);
                if (applicationIn_myFloat32.empty()) return;
                handle_myFloat32_base(applicationIn_myFloat32.front());
                applicationIn_myFloat32.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myFloat64_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::Float64>(
        "Sys_i_Instance_consumer_consumer_myFloat64",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::Float64 msg) {
            enqueue(infrastructureIn_myFloat64, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myFloat64, applicationIn_myFloat64);
                if (applicationIn_myFloat64.empty()) return;
                handle_myFloat64_base(applicationIn_myFloat64.front());
                applicationIn_myFloat64.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myEnum_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(
        "Sys_i_Instance_consumer_consumer_myEnum",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::MyEnum msg) {
            enqueue(infrastructureIn_myEnum, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myEnum, applicationIn_myEnum);
                if (applicationIn_myEnum.empty()) return;
                handle_myEnum_base(applicationIn_myEnum.front());
                applicationIn_myEnum.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myStruct_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(
        "Sys_i_Instance_consumer_consumer_myStruct",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::MyStructi msg) {
            enqueue(infrastructureIn_myStruct, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myStruct, applicationIn_myStruct);
                if (applicationIn_myStruct.empty()) return;
                handle_myStruct_base(applicationIn_myStruct.front());
                applicationIn_myStruct.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myArray1_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(
        "Sys_i_Instance_consumer_consumer_myArray1",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim msg) {
            enqueue(infrastructureIn_myArray1, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myArray1, applicationIn_myArray1);
                if (applicationIn_myArray1.empty()) return;
                handle_myArray1_base(applicationIn_myArray1.front());
                applicationIn_myArray1.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    Sys_i_Instance_consumer_consumer_myArray2_subscription_ = this->create_subscription<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(
        "Sys_i_Instance_consumer_consumer_myArray2",
        1,
        [this](datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded msg) {
            enqueue(infrastructureIn_myArray2, msg);
            std::thread([this]() {
                std::lock_guard<std::mutex> lock(mutex_);
                receiveInputs(infrastructureIn_myArray2, applicationIn_myArray2);
                if (applicationIn_myArray2.empty()) return;
                handle_myArray2_base(applicationIn_myArray2.front());
                applicationIn_myArray2.pop();
                sendOutputs();
            }).detach();
        },
        subscription_options_);

    // Used by receiveInputs
    inDataPortTupleVector = {
    };

    // Used by sendOutputs
    outPortTupleVector = {
    };

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void Sys_i_Instance_consumer_consumer_base::handle_myBoolean_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Boolean>(&msg)) {
        handle_myBoolean(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myBoolean.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myInteger_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        handle_myInteger(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInteger.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myFloat_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float64>(&msg)) {
        handle_myFloat(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myCharacter_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Character>(&msg)) {
        handle_myCharacter(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myCharacter.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myString_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::String>(&msg)) {
        handle_myString(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myString.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myInt8_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer8>(&msg)) {
        handle_myInt8(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myInt16_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer16>(&msg)) {
        handle_myInt16(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myInt32_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer32>(&msg)) {
        handle_myInt32(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myInt64_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Integer64>(&msg)) {
        handle_myInt64(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myUInt8_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned8>(&msg)) {
        handle_myUInt8(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt8.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myUInt16_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned16>(&msg)) {
        handle_myUInt16(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt16.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myUInt32_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned32>(&msg)) {
        handle_myUInt32(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myUInt64_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Unsigned64>(&msg)) {
        handle_myUInt64(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myUInt64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myFloat32_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float32>(&msg)) {
        handle_myFloat32(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat32.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myFloat64_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::Float64>(&msg)) {
        handle_myFloat64(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myFloat64.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myEnum_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyEnum>(&msg)) {
        handle_myEnum(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myEnum.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myStruct_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyStructi>(&msg)) {
        handle_myStruct(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myStruct.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myArray1_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyArrayOneDim>(&msg)) {
        handle_myArray1(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myArray1.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::handle_myArray2_base(MsgType msg)
{
    if (auto typedMsg = std::get_if<datatypes_system_cpp_pkg_interfaces::msg::MyArrayUnbounded>(&msg)) {
        handle_myArray2(*typedMsg);
    } else {
        PRINT_ERROR("Sending out wrong type of variable on port myArray2.\nThis shouldn't be possible.  If you are seeing this message, please notify this tool's current maintainer.");
    }
}

void Sys_i_Instance_consumer_consumer_base::receiveInputs(std::queue<MsgType>& infrastructureQueue, std::queue<MsgType>& applicationQueue) {
    if (!infrastructureQueue.empty()) {
        MsgType eventMsg = infrastructureQueue.front();
        infrastructureQueue.pop();
        enqueue(applicationQueue, eventMsg);
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*> port : inDataPortTupleVector) {
        auto infrastructureQueue = std::get<0>(port);
        if (!infrastructureQueue->empty()) {
            auto msg = infrastructureQueue->front();
            enqueue(*std::get<1>(port), msg);
        }
    }
}

void Sys_i_Instance_consumer_consumer_base::enqueue(std::queue<MsgType>& queue, MsgType val) {
    if (queue.size() >= 1) {
        queue.pop();
    }
    queue.push(val);
}

void Sys_i_Instance_consumer_consumer_base::sendOutputs() {
    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (Sys_i_Instance_consumer_consumer_base::*)(MsgType)> port : outPortTupleVector) {
        auto applicationQueue = std::get<0>(port);
        if (applicationQueue->size() != 0) {
            auto msg = applicationQueue->front();
            applicationQueue->pop();
            enqueue(*std::get<1>(port), msg);
        }
    }

    for (std::tuple<std::queue<MsgType>*, std::queue<MsgType>*, void (Sys_i_Instance_consumer_consumer_base::*)(MsgType)> port : outPortTupleVector) {
        auto infrastructureQueue = std::get<1>(port);
        if (infrastructureQueue->size() != 0) {
            auto msg = infrastructureQueue->front();
            infrastructureQueue->pop();
            (this->*std::get<2>(port))(msg);
        }
    }
}
