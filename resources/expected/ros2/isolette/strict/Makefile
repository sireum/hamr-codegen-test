# This file will not be overwritten if HAMR codegen is rerun

ROS2_PKG     := isolette_cpp_pkg
SOURCE_ROS   := source /opt/ros/$${ROS_DISTRO}/setup.bash
SOURCE_LOCAL := source $(CURDIR)/install/setup.bash

# Extra rcl arguments appended to every `ros2 run` below, e.g.
#   make run ROS_ARGS="--ros-args -p log_file_name:=uros-demo.txt"
# Node parameters must be declared by the node before a value here takes effect.
ROS_ARGS ?=

.PHONY: all build run stop clean check-ros2

all: run

check-ros2:
	@test -n "$${ROS_DISTRO}" || { echo "ERROR: ROS_DISTRO is not set. Source a ROS2 installation first (e.g., source /opt/ros/jazzy/setup.bash)."; exit 1; }
	@test -f "/opt/ros/$${ROS_DISTRO}/setup.bash" || { echo "ERROR: /opt/ros/$${ROS_DISTRO}/setup.bash not found."; exit 1; }

build: check-ros2
	bash -c "$(SOURCE_ROS); colcon build; $(SOURCE_LOCAL)"

run: build
	gnome-terminal --title="[ROS2] thermostat_regulate_temperature_manage_regulator_interface_mrit_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_regulator_interface_mrit_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] thermostat_regulate_temperature_manage_heat_source_mhst_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_heat_source_mhst_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] thermostat_monitor_temperature_manage_alarm_mat_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_alarm_mat_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] thermostat_monitor_temperature_manage_monitor_interface_mmit_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_monitor_interface_mmit_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] operator_interface_oip_oit_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) operator_interface_oip_oit_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] temperature_sensor_cpi_thermostat_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) temperature_sensor_cpi_thermostat_exe $(ROS_ARGS); exec bash"
	gnome-terminal --title="[ROS2] heat_source_cpi_heat_controller_exe" -- bash -c "source /opt/ros/$${ROS_DISTRO}/setup.bash && source $(CURDIR)/install/setup.bash && ros2 run $(ROS2_PKG) heat_source_cpi_heat_controller_exe $(ROS_ARGS); exec bash"
	@echo "Nodes launched. Run 'make stop' to kill them."

stop:
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_regulator_interface_mrit_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_heat_source_mhst_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_regulate_temperature_manage_regulator_mode_mrmt_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_alarm_mat_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_monitor_interface_mmit_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) thermostat_monitor_temperature_manage_monitor_mode_mmmt_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) operator_interface_oip_oit_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) temperature_sensor_cpi_thermostat_exe' 2>/dev/null || true
	-pkill -f 'ros2 run $(ROS2_PKG) heat_source_cpi_heat_controller_exe' 2>/dev/null || true

clean:
	rm -rf build install log
