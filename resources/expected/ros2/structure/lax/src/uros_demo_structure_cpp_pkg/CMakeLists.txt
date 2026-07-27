cmake_minimum_required(VERSION 3.8)
project(uros_demo_structure_cpp_pkg)

# Content between markers will be preserved if codegen is rerun

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(uros_demo_structure_cpp_pkg_interfaces REQUIRED)
find_package(rcl_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(proc_logger_exe src/base_code/proc_logger_runner.cpp src/user_code/proc_logger_src.cpp src/base_code/proc_logger_base_src.cpp)
ament_target_dependencies(proc_logger_exe rclcpp uros_demo_structure_cpp_pkg_interfaces rcl_interfaces)

install(TARGETS
    proc_logger_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
