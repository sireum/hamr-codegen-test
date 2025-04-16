from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    thermostat_regulate_temperature_manage_regulator_interface_mrit_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_regulator_interface_mrit_exe"
       )

    thermostat_regulate_temperature_manage_heat_source_mhst_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_heat_source_mhst_exe"
       )

    thermostat_regulate_temperature_manage_regulator_mode_mrmt_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe"
       )

    thermostat_monitor_temperature_manage_alarm_mat_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_monitor_temperature_manage_alarm_mat_exe"
       )

    thermostat_monitor_temperature_manage_monitor_interface_mmit_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_monitor_temperature_manage_monitor_interface_mmit_exe"
       )

    thermostat_monitor_temperature_manage_monitor_mode_mmmt_node = Node(
        package = "isolette_py_pkg",
        executable = "thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe"
       )

    operator_interface_oip_oit_node = Node(
        package = "isolette_py_pkg",
        executable = "operator_interface_oip_oit_exe"
       )

    temperature_sensor_cpi_thermostat_node = Node(
        package = "isolette_py_pkg",
        executable = "temperature_sensor_cpi_thermostat_exe"
       )

    heat_source_cpi_heat_controller_node = Node(
        package = "isolette_py_pkg",
        executable = "heat_source_cpi_heat_controller_exe"
       )

    ld.add_action(thermostat_regulate_temperature_manage_regulator_interface_mrit_node)
    ld.add_action(thermostat_regulate_temperature_manage_heat_source_mhst_node)
    ld.add_action(thermostat_regulate_temperature_manage_regulator_mode_mrmt_node)
    ld.add_action(thermostat_monitor_temperature_manage_alarm_mat_node)
    ld.add_action(thermostat_monitor_temperature_manage_monitor_interface_mmit_node)
    ld.add_action(thermostat_monitor_temperature_manage_monitor_mode_mmmt_node)
    ld.add_action(operator_interface_oip_oit_node)
    ld.add_action(temperature_sensor_cpi_thermostat_node)
    ld.add_action(heat_source_cpi_heat_controller_node)

    return ld
