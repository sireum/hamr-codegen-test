<!-- This file will not be overwritten if HAMR codegen is rerun -->

# fan_in_fan_out_system — ROS2 Workspace

## Table of Contents

- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package |
|---|---|
| `fanIn_producer1_exe` | `fan_in_fan_out_system_cpp_pkg` |
| `fanIn_producer2_exe` | `fan_in_fan_out_system_cpp_pkg` |
| `fanIn_consumer_exe` | `fan_in_fan_out_system_cpp_pkg` |
| `fanOut_producer_exe` | `fan_in_fan_out_system_cpp_pkg` |
| `fanOut_consumer1_exe` | `fan_in_fan_out_system_cpp_pkg` |
| `fanOut_consumer2_exe` | `fan_in_fan_out_system_cpp_pkg` |

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
# fanIn_producer1
ros2 run fan_in_fan_out_system_cpp_pkg fanIn_producer1_exe

# fanIn_producer2
ros2 run fan_in_fan_out_system_cpp_pkg fanIn_producer2_exe

# fanIn_consumer
ros2 run fan_in_fan_out_system_cpp_pkg fanIn_consumer_exe

# fanOut_producer
ros2 run fan_in_fan_out_system_cpp_pkg fanOut_producer_exe

# fanOut_consumer1
ros2 run fan_in_fan_out_system_cpp_pkg fanOut_consumer1_exe

# fanOut_consumer2
ros2 run fan_in_fan_out_system_cpp_pkg fanOut_consumer2_exe
```
