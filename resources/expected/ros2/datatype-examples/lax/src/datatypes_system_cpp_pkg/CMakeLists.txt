cmake_minimum_required(VERSION 3.8)
project(datatypes_system_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(datatypes_system_cpp_pkg_interfaces REQUIRED)

include_directories(include)

add_executable(producer_producer_exe src/base_code/producer_producer_runner.cpp src/user_code/producer_producer_src.cpp src/base_code/producer_producer_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(producer_producer_exe rclcpp datatypes_system_cpp_pkg_interfaces)

add_executable(consumer_consumer_exe src/base_code/consumer_consumer_runner.cpp src/user_code/consumer_consumer_src.cpp src/base_code/consumer_consumer_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(consumer_consumer_exe rclcpp datatypes_system_cpp_pkg_interfaces)

install(TARGETS
    producer_producer_exe
    consumer_consumer_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
