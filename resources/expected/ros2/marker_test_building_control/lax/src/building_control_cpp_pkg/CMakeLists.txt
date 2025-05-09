cmake_minimum_required(VERSION 3.8)
project(building_control_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(building_control_cpp_pkg_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen
# Test comment
# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(tcp_tempSensor_exe src/base_code/tcp_tempSensor_runner.cpp src/user_code/tcp_tempSensor_src.cpp src/base_code/tcp_tempSensor_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(tcp_tempSensor_exe rclcpp building_control_cpp_pkg_interfaces)

add_executable(tcp_tempControl_exe src/base_code/tcp_tempControl_runner.cpp src/user_code/tcp_tempControl_src.cpp src/base_code/tcp_tempControl_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(tcp_tempControl_exe rclcpp building_control_cpp_pkg_interfaces)

add_executable(tcp_fan_exe src/base_code/tcp_fan_runner.cpp src/user_code/tcp_fan_src.cpp src/base_code/tcp_fan_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(tcp_fan_exe rclcpp building_control_cpp_pkg_interfaces)

install(TARGETS
    tcp_tempSensor_exe
    tcp_tempControl_exe
    tcp_fan_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
