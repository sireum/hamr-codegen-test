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
| `make build` | Build the ROS2 packages |
| `make launch` | Build, then bring the system up with `ros2 launch` (Python launch file) |
| `make launch-py` | Same as `make launch` |
| `make launch-xml` | Build, then bring the system up using the XML launch file instead |
| `make` | Build and launch all nodes in separate terminals |
| `make run` | Same as `make` |
| `make stop` | Kill all running nodes |
| `make clean` | Remove build artifacts |

`make launch` and `make run` are alternatives: the launch targets start everything from
one launch file in the foreground, `run` opens a terminal per node.  Set launch
arguments with `LAUNCH_ARGS`:

```bash
make launch LAUNCH_ARGS="log_file:=run1.txt"
```

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
