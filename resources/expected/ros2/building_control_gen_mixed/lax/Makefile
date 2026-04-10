# This file will not be overwritten if HAMR codegen is rerun

ROS2_PKG     := building_control_cpp_pkg
SOURCE_ROS   := source /opt/ros/$${ROS_DISTRO}/setup.bash
SOURCE_LOCAL := source $(CURDIR)/install/setup.bash

.PHONY: all build run stop clean check-ros2

all: run

check-ros2:
	@test -n "$${ROS_DISTRO}" || { echo "ERROR: ROS_DISTRO is not set. Source a ROS2 installation first (e.g., source /opt/ros/jazzy/setup.bash)."; exit 1; }
	@test -f "/opt/ros/$${ROS_DISTRO}/setup.bash" || { echo "ERROR: /opt/ros/$${ROS_DISTRO}/setup.bash not found."; exit 1; }

build: check-ros2
	bash -c "$(SOURCE_ROS); colcon build; $(SOURCE_LOCAL)"

run: build
	gnome-terminal --title="[ROS2] tcp_tempSensor_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_tempSensor_exe; exec bash"
	gnome-terminal --title="[ROS2] tcp_tempControl_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_tempControl_exe; exec bash"
	gnome-terminal --title="[ROS2] tcp_fan_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) tcp_fan_exe; exec bash"
	@echo "Nodes launched. Run 'make stop' to kill them."

stop:
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_tempSensor_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_tempControl_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_fan_exe' 2>/dev/null || true

clean:
	rm -rf build install log
