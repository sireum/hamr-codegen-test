cmake_minimum_required(VERSION 3.8)
project(isolette_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(isolette_cpp_pkg_interfaces REQUIRED)

# Additions within these tags will be preserved when re-running Codegen

# Additions within these tags will be preserved when re-running Codegen

include_directories(include)

add_executable(thermostat_regulate_temperature_manage_regulator_interface_mrit_exe src/base_code/thermostat_regulate_temperature_manage_regulator_interface_mrit_runner.cpp src/user_code/thermostat_regulate_temperature_manage_regulator_interface_mrit_src.cpp src/base_code/thermostat_regulate_temperature_manage_regulator_interface_mrit_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_regulate_temperature_manage_regulator_interface_mrit_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(thermostat_regulate_temperature_manage_heat_source_mhst_exe src/base_code/thermostat_regulate_temperature_manage_heat_source_mhst_runner.cpp src/user_code/thermostat_regulate_temperature_manage_heat_source_mhst_src.cpp src/base_code/thermostat_regulate_temperature_manage_heat_source_mhst_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_regulate_temperature_manage_heat_source_mhst_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe src/base_code/thermostat_regulate_temperature_manage_regulator_mode_mrmt_runner.cpp src/user_code/thermostat_regulate_temperature_manage_regulator_mode_mrmt_src.cpp src/base_code/thermostat_regulate_temperature_manage_regulator_mode_mrmt_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(thermostat_monitor_temperature_manage_alarm_mat_exe src/base_code/thermostat_monitor_temperature_manage_alarm_mat_runner.cpp src/user_code/thermostat_monitor_temperature_manage_alarm_mat_src.cpp src/base_code/thermostat_monitor_temperature_manage_alarm_mat_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_monitor_temperature_manage_alarm_mat_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(thermostat_monitor_temperature_manage_monitor_interface_mmit_exe src/base_code/thermostat_monitor_temperature_manage_monitor_interface_mmit_runner.cpp src/user_code/thermostat_monitor_temperature_manage_monitor_interface_mmit_src.cpp src/base_code/thermostat_monitor_temperature_manage_monitor_interface_mmit_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_monitor_temperature_manage_monitor_interface_mmit_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe src/base_code/thermostat_monitor_temperature_manage_monitor_mode_mmmt_runner.cpp src/user_code/thermostat_monitor_temperature_manage_monitor_mode_mmmt_src.cpp src/base_code/thermostat_monitor_temperature_manage_monitor_mode_mmmt_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(operator_interface_oip_oit_exe src/base_code/operator_interface_oip_oit_runner.cpp src/user_code/operator_interface_oip_oit_src.cpp src/base_code/operator_interface_oip_oit_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(operator_interface_oip_oit_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(temperature_sensor_cpi_thermostat_exe src/base_code/temperature_sensor_cpi_thermostat_runner.cpp src/user_code/temperature_sensor_cpi_thermostat_src.cpp src/base_code/temperature_sensor_cpi_thermostat_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(temperature_sensor_cpi_thermostat_exe rclcpp isolette_cpp_pkg_interfaces)

add_executable(heat_source_cpi_heat_controller_exe src/base_code/heat_source_cpi_heat_controller_runner.cpp src/user_code/heat_source_cpi_heat_controller_src.cpp src/base_code/heat_source_cpi_heat_controller_base_src.cpp src/base_code/enum_converter.cpp)
ament_target_dependencies(heat_source_cpi_heat_controller_exe rclcpp isolette_cpp_pkg_interfaces)

install(TARGETS
    thermostat_regulate_temperature_manage_regulator_interface_mrit_exe
    thermostat_regulate_temperature_manage_heat_source_mhst_exe
    thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe
    thermostat_monitor_temperature_manage_alarm_mat_exe
    thermostat_monitor_temperature_manage_monitor_interface_mmit_exe
    thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe
    operator_interface_oip_oit_exe
    temperature_sensor_cpi_thermostat_exe
    heat_source_cpi_heat_controller_exe
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
