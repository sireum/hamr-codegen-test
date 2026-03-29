cmake_minimum_required(VERSION 3.8)
project(isolette_py_pkg_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  msg/Heat.msg
  msg/InterfaceInteraction.msg
  msg/Float32.msg
  msg/PhysicalTempimpl.msg
  msg/ValueStatus.msg
  msg/TempWstatusimpl.msg
  msg/OnOff.msg
  msg/Status.msg
  msg/Tempimpl.msg
  msg/RegulatorMode.msg
  msg/Boolean.msg
  msg/FailureFlagimpl.msg
  msg/MonitorMode.msg
  msg/Empty.msg
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
