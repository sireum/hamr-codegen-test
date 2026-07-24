cmake_minimum_required(VERSION 3.8)
project(uros_demo_gumbo_microros_pkg)

# Content between markers will be preserved if codegen is rerun

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(rcutils REQUIRED)
find_package(uros_demo_gumbo_cpp_pkg_interfaces REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(proc_ttj_exe src/base_code/proc_ttj_runner.c src/user_code/proc_ttj_src.c src/base_code/proc_ttj_base_src.c)
ament_target_dependencies(proc_ttj_exe rclc rcutils uros_demo_gumbo_cpp_pkg_interfaces sensor_msgs geometry_msgs)

install(TARGETS
    proc_ttj_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
