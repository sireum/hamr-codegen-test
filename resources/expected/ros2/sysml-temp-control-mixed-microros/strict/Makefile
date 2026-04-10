# This file will not be overwritten if HAMR codegen is rerun

MICROROS_WS ?= $(error MICROROS_WS is not set. Export it to the path of your micro-ROS firmware workspace.)
ROS2_PKG       := temp_control_mixed_u_ros_cpp_pkg
INTERFACES_PKG := temp_control_mixed_u_ros_cpp_pkg_interfaces
MICROROS_PKG   := temp_control_mixed_u_ros_microros_pkg

SOURCE_BASE  := source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(MICROROS_WS)/install/setup.bash
SOURCE_LOCAL := source $(CURDIR)/install/setup.bash

.PHONY: all build build-microros build-ros2 run stop clean check-ros2

all: run

build: check-ros2 build-microros build-ros2

check-ros2:
	@test -n "$${ROS_DISTRO}" || { echo "ERROR: ROS_DISTRO is not set. Source a ROS2 installation first (e.g., source /opt/ros/jazzy/setup.bash)."; exit 1; }
	@test -f "/opt/ros/$${ROS_DISTRO}/setup.bash" || { echo "ERROR: /opt/ros/$${ROS_DISTRO}/setup.bash not found."; exit 1; }

build-microros:
	cp -r src/$(INTERFACES_PKG) $(MICROROS_WS)/src/
	cp -r microros_apps/$(MICROROS_PKG) $(MICROROS_WS)/src/
	cd $(MICROROS_WS) && bash -c "$(SOURCE_BASE); colcon build --packages-select $(INTERFACES_PKG) $(MICROROS_PKG)"

build-ros2:
	bash -c "$(SOURCE_BASE); colcon build; $(SOURCE_LOCAL)"

run: build
	gnome-terminal --title="[agent] micro-XRCE-DDS" -- bash -c "$(SOURCE_BASE); ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888; exec bash"
	sleep 2
	gnome-terminal --title="[microROS] tcp_tempSensor_exe" -- bash -c "$(SOURCE_BASE); RMW_IMPLEMENTATION=rmw_microxrcedds ros2 run $(MICROROS_PKG) tcp_tempSensor_exe; exec bash"
	gnome-terminal --title="[microROS] tcp_tempControl_exe" -- bash -c "$(SOURCE_BASE); RMW_IMPLEMENTATION=rmw_microxrcedds ros2 run $(MICROROS_PKG) tcp_tempControl_exe; exec bash"
	gnome-terminal --title="[ROS2] tcp_fan_exe" -- bash -c "$(SOURCE_BASE); $(SOURCE_LOCAL); ros2 run $(ROS2_PKG) tcp_fan_exe; exec bash"
	gnome-terminal --title="[ROS2] tcp_opInterface_exe" -- bash -c "$(SOURCE_BASE); $(SOURCE_LOCAL); ros2 run $(ROS2_PKG) tcp_opInterface_exe; exec bash"
	@echo "Nodes launched. Run 'make stop' to kill them."

stop:
	-pkill -f 'micro_ros_agent udp4' 2>/dev/null || true
	-pkill -f 'ros2 run $(MICROROS_PKG) tcp_tempSensor_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(MICROROS_PKG) tcp_tempControl_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_fan_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) tcp_opInterface_exe' 2>/dev/null || true

clean:
	rm -rf build install log
	rm -rf $(MICROROS_WS)/src/$(INTERFACES_PKG) $(MICROROS_WS)/src/$(MICROROS_PKG)
	rm -rf $(MICROROS_WS)/build/$(INTERFACES_PKG) $(MICROROS_WS)/build/$(MICROROS_PKG)
	rm -rf $(MICROROS_WS)/install/$(INTERFACES_PKG) $(MICROROS_WS)/install/$(MICROROS_PKG)
