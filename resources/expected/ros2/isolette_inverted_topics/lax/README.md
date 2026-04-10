<!-- This file will not be overwritten if HAMR codegen is rerun -->

# isolette — ROS2 Workspace

## Table of Contents

- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package |
|---|---|
| `thermostat_regulate_temperature_manage_regulator_interface_mrit_exe` | `isolette_cpp_pkg` |
| `thermostat_regulate_temperature_manage_heat_source_mhst_exe` | `isolette_cpp_pkg` |
| `thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe` | `isolette_cpp_pkg` |
| `thermostat_monitor_temperature_manage_alarm_mat_exe` | `isolette_cpp_pkg` |
| `thermostat_monitor_temperature_manage_monitor_interface_mmit_exe` | `isolette_cpp_pkg` |
| `thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe` | `isolette_cpp_pkg` |
| `operator_interface_oip_oit_exe` | `isolette_cpp_pkg` |
| `temperature_sensor_cpi_thermostat_exe` | `isolette_cpp_pkg` |
| `heat_source_cpi_heat_controller_exe` | `isolette_cpp_pkg` |

## Quick Start

| Target | Description |
|---|---|
| `make` | Build and launch all nodes in separate terminals |
| `make run` | Same as `make` |
| `make stop` | Kill all running nodes |
| `make clean` | Remove build artifacts |

## Manual Steps

The Makefile targets automate the following steps.

### Build

```bash
source /opt/ros/$ROS_DISTRO/setup.bash
colcon build
source install/setup.bash
```

### Run

Each terminal requires:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash && source install/setup.bash
```

```bash
# thermostat_regulate_temperature_manage_regulator_interface_mrit
ros2 run isolette_cpp_pkg thermostat_regulate_temperature_manage_regulator_interface_mrit_exe

# thermostat_regulate_temperature_manage_heat_source_mhst
ros2 run isolette_cpp_pkg thermostat_regulate_temperature_manage_heat_source_mhst_exe

# thermostat_regulate_temperature_manage_regulator_mode_mrmt
ros2 run isolette_cpp_pkg thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe

# thermostat_monitor_temperature_manage_alarm_mat
ros2 run isolette_cpp_pkg thermostat_monitor_temperature_manage_alarm_mat_exe

# thermostat_monitor_temperature_manage_monitor_interface_mmit
ros2 run isolette_cpp_pkg thermostat_monitor_temperature_manage_monitor_interface_mmit_exe

# thermostat_monitor_temperature_manage_monitor_mode_mmmt
ros2 run isolette_cpp_pkg thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe

# operator_interface_oip_oit
ros2 run isolette_cpp_pkg operator_interface_oip_oit_exe

# temperature_sensor_cpi_thermostat
ros2 run isolette_cpp_pkg temperature_sensor_cpi_thermostat_exe

# heat_source_cpi_heat_controller
ros2 run isolette_cpp_pkg heat_source_cpi_heat_controller_exe
```
