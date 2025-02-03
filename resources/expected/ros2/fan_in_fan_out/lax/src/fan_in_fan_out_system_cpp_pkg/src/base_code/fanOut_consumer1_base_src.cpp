#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanOut_consumer1_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanOut_consumer1_base::fanOut_consumer1_base() : Node("fanOut_consumer1")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    fanOut_consumer1_myInteger_subscription_ = this->create_subscription<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanOut_consumer1_myInteger",
        1,
        std::bind(&fanOut_consumer1_base::handle_myInteger, this, std::placeholders::_1), subscription_options_);

}
