<!-- This file will not be overwritten if HAMR codegen is rerun -->

# datatypes_system — ROS2 Workspace

## Table of Contents

- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package |
|---|---|
| `producer_producer_exe` | `datatypes_system_cpp_pkg` |
| `consumer_consumer_exe` | `datatypes_system_cpp_pkg` |

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
# producer_producer
ros2 run datatypes_system_cpp_pkg producer_producer_exe

# consumer_consumer
ros2 run datatypes_system_cpp_pkg consumer_consumer_exe
```
