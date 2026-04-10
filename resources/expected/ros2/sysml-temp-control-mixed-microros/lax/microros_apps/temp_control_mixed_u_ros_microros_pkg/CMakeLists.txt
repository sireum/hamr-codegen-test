cmake_minimum_required(VERSION 3.8)
project(temp_control_mixed_u_ros_microros_pkg)

# Content between markers will be preserved if codegen is rerun

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(temp_control_mixed_u_ros_cpp_pkg_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(tcp_tempSensor_exe src/base_code/tcp_tempSensor_runner.c src/user_code/tcp_tempSensor_src.c src/base_code/tcp_tempSensor_base_src.c src/base_code/enum_converter.c)
ament_target_dependencies(tcp_tempSensor_exe rclc temp_control_mixed_u_ros_cpp_pkg_interfaces)

add_executable(tcp_tempControl_exe src/base_code/tcp_tempControl_runner.c src/user_code/tcp_tempControl_src.c src/base_code/tcp_tempControl_base_src.c src/base_code/enum_converter.c)
ament_target_dependencies(tcp_tempControl_exe rclc temp_control_mixed_u_ros_cpp_pkg_interfaces)

install(TARGETS
    tcp_tempSensor_exe
    tcp_tempControl_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
