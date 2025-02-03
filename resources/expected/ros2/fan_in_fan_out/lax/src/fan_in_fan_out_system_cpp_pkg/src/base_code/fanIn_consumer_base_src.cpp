#include "fan_in_fan_out_system_cpp_pkg/base_headers/fanIn_consumer_base_src.hpp"

//========================================================
// Re-running Codegen will overwrite changes to this file
//========================================================

fanIn_consumer_base::fanIn_consumer_base() : Node("fanIn_consumer")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    fanIn_consumer_myInteger_subscription_ = this->create_subscription<fan_in_fan_out_system_cpp_pkg_interfaces::msg::Integer64>(
        "fanIn_consumer_myInteger",
        1,
        std::bind(&fanIn_consumer_base::handle_myInteger, this, std::placeholders::_1), subscription_options_);

}
