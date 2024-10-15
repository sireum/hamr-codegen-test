cmake_minimum_required(VERSION 3.8)
project(pca_system_cpp_pkg_interfaces)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  msg/AlarmSignal.msg
  msg/AlarmType.msg
  msg/WarningType.msg
  msg/Boolean.msg
  msg/StatusType.msg
  msg/Unsigned16.msg
  msg/Minuteimp.msg
  msg/String.msg
  msg/DrugCodeimp.msg
  msg/DoseRateUnitimp.msg
  msg/InfusionUnitimp.msg
  msg/Integer16.msg
  msg/DrugWeightimp.msg
  msg/Float32.msg
  msg/Float64.msg
  msg/DrugConcentrationimp.msg
  msg/DrugVolumeimp.msg
  msg/FlowRateimp.msg
  msg/DrugRecordimp.msg
  msg/DrugLibrary.msg
  msg/Integer64.msg
  msg/FaultRecordimp.msg
  msg/FaultLog.msg
  msg/FluidFlowimp.msg
  msg/Sound.msg
  msg/Voltageimp.msg
  msg/Currentimp.msg
  msg/Prescriptionimp.msg
  msg/Message.msg
  msg/FluidVolumeimp.msg
  msg/Empty.msg
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
