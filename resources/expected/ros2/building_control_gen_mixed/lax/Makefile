# This file will not be overwritten if HAMR codegen is rerun

ROS2_PKG     := building_control_cpp_pkg
SOURCE_ROS   := source /opt/ros/$${ROS_DISTRO}/setup.bash
SOURCE_LOCAL := source $(CURDIR)/install/setup.bash

# Extra rcl arguments appended to every `ros2 run` below, e.g.
#   make run ROS_ARGS="--ros-args -p log_file_name:=uros-demo.txt"
# Node parameters must be declared by the node before a value here takes effect.
ROS_ARGS ?=

.PHONY: all build run launch launch-py launch-xml stop clean check-ros2

all: run

check-ros2:
	@test -n "$${ROS_DISTRO}" || { echo "ERROR: ROS_DISTRO is not set. Source a ROS2 installation first (e.g., source /opt/ros/jazzy/setup.bash)."; exit 1; }
	@test -f "/opt/ros/$${ROS_DISTRO}/setup.bash" || { echo "ERROR: /opt/ros/$${ROS_DISTRO}/setup.bash not found."; exit 1; }

build: check-ros2
	bash -c "$(SOURCE_ROS); colcon build; $(SOURCE_LOCAL)"

run: build
	gnome-terminal --title="[ROS2] tcp_tempSensor_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_tempSensor_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] tcp_tempControl_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_tempControl_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] tcp_fan_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_fan_exe $(ROS_ARGS); exec bash"
	@echo "Nodes launched. Run 'make stop' to kill them."

# Arguments passed to `ros2 launch`, e.g.
#   make launch LAUNCH_ARGS="log_file:=run1.txt joystick_dev:=/dev/input/js0"
# `ros2 launch --show-args $(BRINGUP_PKG) $(LAUNCH_FILE).launch.py` lists what the file
# accepts.  Unlike ROS_ARGS above these are launch arguments, not rcl arguments: they are
# declared by the launch file and reach a node through its parameters.
LAUNCH_ARGS ?=

# Which launch file to run.  BuildingControlDemo_i_Instance brings up the whole system on this host;
# BuildingControlDemo_i_Instance_ros2 brings up only the ROS2 half, for when the micro-ROS nodes run on
# hardware and the agent is reachable elsewhere.
LAUNCH_FILE ?= BuildingControlDemo_i_Instance

BRINGUP_PKG := $(ROS2_PKG)_bringup

# Both formats are generated from the same model and launch the same system; pick
# whichever you prefer to hand-edit.
launch: launch-py

launch-py: build
	bash -c "$(SOURCE_ROS); $(SOURCE_LOCAL); ros2 launch $(BRINGUP_PKG) $(LAUNCH_FILE).launch.py $(LAUNCH_ARGS)"

launch-xml: build
	bash -c "$(SOURCE_ROS); $(SOURCE_LOCAL); ros2 launch $(BRINGUP_PKG) $(LAUNCH_FILE).launch.xml $(LAUNCH_ARGS)"

stop:
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_tempSensor_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_tempControl_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_fan_exe' 2>/dev/null || true

clean:
	rm -rf build install log
