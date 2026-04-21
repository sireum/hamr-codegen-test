<!-- This file will not be overwritten if HAMR codegen is rerun -->

# building_control — ROS2 Workspace

## Table of Contents

- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package | Dispatch |
|---|---|---|
| `tcp_tempSensor_exe` | `building_control_cpp_pkg` | Periodic |
| `tcp_tempControl_exe` | `building_control_cpp_pkg` | Sporadic |
| `tcp_fan_exe` | `building_control_cpp_pkg` | Sporadic |

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
# tcp_tempSensor
ros2 run building_control_cpp_pkg tcp_tempSensor_exe

# tcp_tempControl
ros2 run building_control_cpp_pkg tcp_tempControl_exe

# tcp_fan
ros2 run building_control_cpp_pkg tcp_fan_exe
```
