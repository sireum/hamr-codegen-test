cmake_minimum_required(VERSION 3.8)
project(temp_control_mixed_u_ros_cpp_pkg)

# Content between markers will be preserved if codegen is rerun

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(temp_control_mixed_u_ros_cpp_pkg_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(tcp_fan_exe src/base_code/tcp_fan_runner.cpp src/user_code/tcp_fan_src.cpp src/base_code/tcp_fan_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(tcp_fan_exe rclcpp temp_control_mixed_u_ros_cpp_pkg_interfaces)

add_executable(tcp_opInterface_exe src/base_code/tcp_opInterface_runner.cpp src/user_code/tcp_opInterface_src.cpp src/base_code/tcp_opInterface_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(tcp_opInterface_exe rclcpp temp_control_mixed_u_ros_cpp_pkg_interfaces)

install(TARGETS
    tcp_fan_exe
    tcp_opInterface_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
