cmake_minimum_required(VERSION 3.8)
project(datatypes_system_cpp_pkg_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  msg/Boolean.msg
  msg/Integer64.msg
  msg/Float64.msg
  msg/Character.msg
  msg/String.msg
  msg/Integer8.msg
  msg/Integer16.msg
  msg/Integer32.msg
  msg/Unsigned8.msg
  msg/Unsigned16.msg
  msg/Unsigned32.msg
  msg/Unsigned64.msg
  msg/Float32.msg
  msg/MyEnum.msg
  msg/MyStruct2i.msg
  msg/MyArrayOneDim.msg
  msg/MyArrayUnbounded.msg
  msg/MyStructi.msg
  msg/Empty.msg
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
