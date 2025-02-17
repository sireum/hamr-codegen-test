# Install script for directory: /home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/src/building_control_cpp_pkg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/install/building_control_cpp_pkg")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg" TYPE EXECUTABLE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/tcp_tempSensor_exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe"
         OLD_RPATH "/opt/ros/humble/lib:/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/install/building_control_cpp_pkg_interfaces/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempSensor_exe")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg" TYPE EXECUTABLE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/tcp_tempControl_exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe"
         OLD_RPATH "/opt/ros/humble/lib:/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/install/building_control_cpp_pkg_interfaces/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_tempControl_exe")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg" TYPE EXECUTABLE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/tcp_fan_exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe"
         OLD_RPATH "/opt/ros/humble/lib:/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/install/building_control_cpp_pkg_interfaces/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/building_control_cpp_pkg/tcp_fan_exe")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/building_control_cpp_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/building_control_cpp_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg/environment" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg/environment" TYPE FILE FILES "/opt/ros/humble/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg/environment" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_index/share/ament_index/resource_index/packages/building_control_cpp_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg/cmake" TYPE FILE FILES
    "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_core/building_control_cpp_pkgConfig.cmake"
    "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/ament_cmake_core/building_control_cpp_pkgConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/building_control_cpp_pkg" TYPE FILE FILES "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/src/building_control_cpp_pkg/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/clint/Applications/Sireum/hamr/codegen/jvm/src/test/results/ros2/marker_test_building_control/results/strict/build/building_control_cpp_pkg/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
