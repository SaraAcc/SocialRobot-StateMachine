# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/catkin_ws/build

# Utility rule file for _qt_nuitrack_app_generate_messages_check_deps_Gestures.

# Include the progress variables for this target.
include headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/progress.make

headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures:
	cd /home/student/catkin_ws/build/headers/qt_nuitrack_app && ../../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/genmsg/cmake/../../../lib/genmsg/genmsg_check_deps.py qt_nuitrack_app /home/student/catkin_ws/src/headers/qt_nuitrack_app/msg/Gestures.msg qt_nuitrack_app/GestureInfo

_qt_nuitrack_app_generate_messages_check_deps_Gestures: headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures
_qt_nuitrack_app_generate_messages_check_deps_Gestures: headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/build.make

.PHONY : _qt_nuitrack_app_generate_messages_check_deps_Gestures

# Rule to build all files generated by this target.
headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/build: _qt_nuitrack_app_generate_messages_check_deps_Gestures

.PHONY : headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/build

headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/clean:
	cd /home/student/catkin_ws/build/headers/qt_nuitrack_app && $(CMAKE_COMMAND) -P CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/cmake_clean.cmake
.PHONY : headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/clean

headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/depend:
	cd /home/student/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/catkin_ws/src /home/student/catkin_ws/src/headers/qt_nuitrack_app /home/student/catkin_ws/build /home/student/catkin_ws/build/headers/qt_nuitrack_app /home/student/catkin_ws/build/headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : headers/qt_nuitrack_app/CMakeFiles/_qt_nuitrack_app_generate_messages_check_deps_Gestures.dir/depend

