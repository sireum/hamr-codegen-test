cmake_minimum_required(VERSION 3.8)
project(fan_in_fan_out_system_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(fan_in_fan_out_system_cpp_pkg_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(fanIn_producer1_exe src/base_code/fanIn_producer1_runner.cpp src/user_code/fanIn_producer1_src.cpp src/base_code/fanIn_producer1_base_src.cpp)
ament_target_dependencies(fanIn_producer1_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

add_executable(fanIn_producer2_exe src/base_code/fanIn_producer2_runner.cpp src/user_code/fanIn_producer2_src.cpp src/base_code/fanIn_producer2_base_src.cpp)
ament_target_dependencies(fanIn_producer2_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

add_executable(fanIn_consumer_exe src/base_code/fanIn_consumer_runner.cpp src/user_code/fanIn_consumer_src.cpp src/base_code/fanIn_consumer_base_src.cpp)
ament_target_dependencies(fanIn_consumer_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

add_executable(fanOut_producer_exe src/base_code/fanOut_producer_runner.cpp src/user_code/fanOut_producer_src.cpp src/base_code/fanOut_producer_base_src.cpp)
ament_target_dependencies(fanOut_producer_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

add_executable(fanOut_consumer1_exe src/base_code/fanOut_consumer1_runner.cpp src/user_code/fanOut_consumer1_src.cpp src/base_code/fanOut_consumer1_base_src.cpp)
ament_target_dependencies(fanOut_consumer1_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

add_executable(fanOut_consumer2_exe src/base_code/fanOut_consumer2_runner.cpp src/user_code/fanOut_consumer2_src.cpp src/base_code/fanOut_consumer2_base_src.cpp)
ament_target_dependencies(fanOut_consumer2_exe rclcpp fan_in_fan_out_system_cpp_pkg_interfaces)

install(TARGETS
    fanIn_producer1_exe
    fanIn_producer2_exe
    fanIn_consumer_exe
    fanOut_producer_exe
    fanOut_consumer1_exe
    fanOut_consumer2_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
