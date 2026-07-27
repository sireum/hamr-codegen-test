<!-- This file will not be overwritten if HAMR codegen is rerun -->

# uros_demo_structure — Mixed ROS2 / microROS Workspace

- [Prerequisites](#prerequisites)
- [Quick Start](#quick-start)
- [Manual Steps](#manual-steps)
  - [Build](#build)
  - [Run](#run)

| Node | Package | Type | Dispatch |
|---|---|---|---|
| `proc_logger_exe` | `uros_demo_structure_cpp_pkg` | ROS2 (rclcpp) | Sporadic |
| `proc_ttj_exe` | `uros_demo_structure_microros_pkg` | microROS (rclc + rmw_microxrcedds) | Sporadic |

The microROS node(s) communicate via a micro-XRCE-DDS agent that bridges them to the ROS2 DDS bus.

## Prerequisites

- [ROS2 Humble](https://docs.ros.org/en/humble/Installation.html)
- micro-ROS Firmware Workspace (one-time setup)

  microROS nodes require a firmware workspace containing the micro-ROS client stack and agent.
  This workspace is built once and shared across all your microROS projects — set `MICROROS_WS`
  to a stable location outside any individual project and reuse it everywhere.

  **Step 1 — choose a location** (edit this, then add it to your shell profile):

  ```bash
  export MICROROS_WS=/path/to/microros_ws
  ```

  **Step 2 — build the firmware workspace** (copy-paste as-is once `MICROROS_WS` is set):

  ```bash
  mkdir -p $MICROROS_WS && cd $MICROROS_WS
  source /opt/ros/$ROS_DISTRO/setup.bash

  # 1. Add micro_ros_setup and build it
  git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup
  colcon build --packages-select micro_ros_setup
  source install/setup.bash

  # 2. Download the micro-ROS client stack
  ros2 run micro_ros_setup create_firmware_ws.sh host

  # 3. Ignore packages with known build failures that are not needed
  touch src/ros2/example_interfaces/COLCON_IGNORE
  touch src/uros/micro-ROS-demos/COLCON_IGNORE

  # 4. Build the full micro-ROS stack (takes a while, but only done once)
  ros2 run micro_ros_setup build_firmware.sh
  source install/setup.bash

  # 5. Build the micro-XRCE-DDS agent
  ros2 run micro_ros_setup create_agent_ws.sh
  ros2 run micro_ros_setup build_agent.sh
  source install/setup.bash
  ```

## Quick Start

Run from this directory with `MICROROS_WS` set.

| Target | Description |
|---|---|
| `make` | Build everything and launch all nodes in separate terminals |
| `make run` | Same as `make` |
| `make stop` | Kill all running nodes |
| `make clean` | Remove local build artifacts and copied packages from `MICROROS_WS` |
| `make microros-config` | Apply `microros_apps/colcon.meta` to `MICROROS_WS` and rebuild the micro-ROS stack (see below) |

## Firmware Configuration

`microros_apps/colcon.meta` holds the build configuration the generated nodes need
from the micro-ROS middleware.  It is **not** consumed from where it sits: it
configures packages such as `rcl` and `rmw_microxrcedds`, which live in the firmware
workspace and are built by step 4 above -- not by `make build`, which builds only the
application packages.  Applying it is therefore a separate step:

```bash
make microros-config
```

Run it once after generating, and again whenever `colcon.meta` changes.  Two of its
settings matter in ways that fail quietly if it is never applied:

- `RCL_COMMAND_LINE_ENABLED=ON` -- the micro-ROS fork of `rcl` strips its
  argument-parsing machinery by default.  Without this flag, the rcl arguments in each
  node's `node_options` block (topic remap rules in particular) are parsed by nothing.
- `RMW_UXRCE_MAX_PUBLISHERS` / `RMW_UXRCE_MAX_SUBSCRIPTIONS` -- these are derived from
  the model's port counts and regenerated on every codegen run.  If the firmware's
  pools are smaller than the nodes need, entity creation fails without a diagnostic,
  so re-apply after adding ports.

Entries outside the marked blocks in `colcon.meta` are derived from the model and are
overwritten on each run; the marked blocks (build profile, transport and tuning) are
preserved.  To override a derived value, restate its `-D` flag inside a marked block --
colcon passes `cmake-args` through in order and CMake takes the last occurrence.

Because `MICROROS_WS` is shared across projects, `make microros-config` backs up any
`colcon.meta` already there to `colcon.meta.bak`.  If you maintain your own firmware
configuration, merge the two rather than letting one replace the other.

### On a host workspace this step is effectively a no-op

A firmware workspace created for the **host** platform
(`create_firmware_ws.sh host generic`) does not check out `rcl` at all -- on host,
micro-ROS is `rmw_microxrcedds` and `rclc` layered over the ROS 2 distribution's own
`rcl`, so there is no micro-ROS `rcl` to configure.  `make microros-config` will copy
`colcon.meta` into place and rebuild successfully, but the `rcl` entry matches no
package and is silently inert; `find_package(rcl)` keeps resolving to
`/opt/ros/$ROS_DISTRO`.

This is usually invisible, because the distribution's `rcl` is built with both
argument parsing and logging enabled -- the very things the flags above turn on.  So
remap rules and `/rosout` routing work on host whether or not this step is ever run.
They stop working the moment the same model is deployed to an embedded target, where
the micro-ROS `rcl` fork is used and ships with both features off.  Applying the
configuration matters there, and an embedded workspace
(`create_firmware_ws.sh <rtos> <board>`) does check `rcl` out, under
`firmware/mcu_ws`.

One setting to revisit when moving off host: `RCL_LOGGING_IMPLEMENTATION` is emitted
as `rcl_logging_spdlog`, which suits a host build.  Embedded targets generally want
`rcl_logging_noop`.

## Manual Steps

The Makefile targets automate the following steps.

### Build

Run from this directory. Requires `MICROROS_WS` to be set to the firmware workspace above.

```bash
source /opt/ros/$ROS_DISTRO/setup.bash && source $MICROROS_WS/install/setup.bash

# Copy the interfaces and microROS app into the firmware workspace and build them
cp -r src/uros_demo_structure_cpp_pkg_interfaces $MICROROS_WS/src/
cp -r microros_apps/uros_demo_structure_microros_pkg $MICROROS_WS/src/
cd $MICROROS_WS && colcon build --packages-select uros_demo_structure_cpp_pkg_interfaces uros_demo_structure_microros_pkg

# Build the ROS2 packages from this workspace
cd - && colcon build
source install/setup.bash
```

### Run

Each terminal requires:

```bash
source /opt/ros/$ROS_DISTRO/setup.bash && source $MICROROS_WS/install/setup.bash
```

Terminals running ROS2 nodes also need:

```bash
source <path-to-this-workspace>/install/setup.bash
```

Start the agent before the microROS node(s).

```bash
# Terminal 1 — micro-XRCE-DDS agent (must start first)
ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888

# proc_ttj — microROS node
RMW_IMPLEMENTATION=rmw_microxrcedds ros2 run uros_demo_structure_microros_pkg proc_ttj_exe

# proc_logger — ROS2 node
ros2 run uros_demo_structure_cpp_pkg proc_logger_exe
```
