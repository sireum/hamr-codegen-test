#include "pca_system_cpp_pkg/base_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base() : Node("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher")
{
    cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    subscription_options_.callback_group = cb_group_;

    // Setting up connections
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::FlowRateimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Infusion_Flow_Rate",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::handle_Infusion_Flow_Rate, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour_subscription_ = this->create_subscription<pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Max_Drug_Per_Hour",
        1,
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::handle_Max_Drug_Per_Hour, this, std::placeholders::_1), subscription_options_);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Near_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Near_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_safety_alarm_process_alarm_thr_Max_Dose_Warning",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_rate_controller_Over_Max_Drug_Per_Hour",
        1);

    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3 = this->create_publisher<pca_system_cpp_pkg_interfaces::msg::Empty>(
        "wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_ice_thread_Over_Max_Drug_Per_Hour",
        1);

    // timeTriggered callback timer
    periodTimer_ = this->create_wall_timer(std::chrono::milliseconds(1000),
        std::bind(&wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::timeTriggered, this), cb_group_);

}

//=================================================
//  C o m m u n i c a t i o n
//=================================================

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::handle_Infusion_Flow_Rate(const pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr msg)
{
    Infusion_Flow_Rate_msg_holder = msg;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::handle_Max_Drug_Per_Hour(const pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr msg)
{
    Max_Drug_Per_Hour_msg_holder = msg;
}

pca_system_cpp_pkg_interfaces::msg::FlowRateimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::get_Infusion_Flow_Rate() {
    return Infusion_Flow_Rate_msg_holder;
}

pca_system_cpp_pkg_interfaces::msg::DrugVolumeimp::SharedPtr wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::get_Max_Drug_Per_Hour() {
    return Max_Drug_Per_Hour_msg_holder;
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::put_Near_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Near_Max_Drug_Per_Hour_publisher_2->publish(msg);
}

void wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base::put_Over_Max_Drug_Per_Hour(pca_system_cpp_pkg_interfaces::msg::Empty msg)
{
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_1->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_2->publish(msg);
    wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_Over_Max_Drug_Per_Hour_publisher_3->publish(msg);
}

