#include "pca_system_cpp_pkg/user_headers/wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_src.hpp"

//=================================================
//  D O   N O T   E D I T   T H I S   F I L E
//=================================================

wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher::wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher() : wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher_base()
{
    // Invoke initialize entry point
    initialize();

    PRINT_INFO("wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher infrastructure set up");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto executor = rclcpp::executors::MultiThreadedExecutor();
    auto node = std::make_shared<wrap_pca_imp_Instance_pump_operation_operation_process_operation_threads_max_drug_watcher>();
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
