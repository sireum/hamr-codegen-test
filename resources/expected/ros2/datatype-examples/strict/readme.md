<!-- This file will not be overwritten if HAMR codegen is rerun -->

# datatypes_system — ROS2 Workspace

## Table of Contents

- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package | Dispatch |
|---|---|---|
| `producer_producer_exe` | `datatypes_system_cpp_pkg` | Periodic |
| `consumer_consumer_exe` | `datatypes_system_cpp_pkg` | Sporadic |

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
# producer_producer
ros2 run datatypes_system_cpp_pkg producer_producer_exe

# consumer_consumer
ros2 run datatypes_system_cpp_pkg consumer_consumer_exe
```
