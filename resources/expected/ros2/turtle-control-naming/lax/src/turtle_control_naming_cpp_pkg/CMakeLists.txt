cmake_minimum_required(VERSION 3.8)
project(turtle_control_naming_cpp_pkg)

# Content between markers will be preserved if codegen is rerun

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(turtle_control_naming_cpp_pkg_interfaces REQUIRED)
find_package(turtlesim REQUIRED)
find_package(geometry_msgs REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(proc_pilot_exe src/base_code/proc_pilot_runner.cpp src/user_code/proc_pilot_src.cpp src/base_code/proc_pilot_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(proc_pilot_exe rclcpp turtle_control_naming_cpp_pkg_interfaces turtlesim geometry_msgs)

install(TARGETS
    proc_pilot_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
