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

# Utility rule file for qt_vosk_app_generate_messages_py.

# Include the progress variables for this target.
include headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/progress.make

headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py: /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/_speech_recognize.py
headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py: /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/__init__.py


/home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/_speech_recognize.py: /opt/ros/noetic/lib/genpy/gensrv_py.py
/home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/_speech_recognize.py: /home/student/catkin_ws/src/headers/qt_vosk_app/srv/speech_recognize.srv
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/student/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating Python code from SRV qt_vosk_app/speech_recognize"
	cd /home/student/catkin_ws/build/headers/qt_vosk_app && ../../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/genpy/cmake/../../../lib/genpy/gensrv_py.py /home/student/catkin_ws/src/headers/qt_vosk_app/srv/speech_recognize.srv -Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg -p qt_vosk_app -o /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv

/home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/__init__.py: /opt/ros/noetic/lib/genpy/genmsg_py.py
/home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/__init__.py: /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/_speech_recognize.py
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/student/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating Python srv __init__.py for qt_vosk_app"
	cd /home/student/catkin_ws/build/headers/qt_vosk_app && ../../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/genpy/cmake/../../../lib/genpy/genmsg_py.py -o /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv --initpy

qt_vosk_app_generate_messages_py: headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py
qt_vosk_app_generate_messages_py: /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/_speech_recognize.py
qt_vosk_app_generate_messages_py: /home/student/catkin_ws/devel/lib/python3/dist-packages/qt_vosk_app/srv/__init__.py
qt_vosk_app_generate_messages_py: headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/build.make

.PHONY : qt_vosk_app_generate_messages_py

# Rule to build all files generated by this target.
headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/build: qt_vosk_app_generate_messages_py

.PHONY : headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/build

headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/clean:
	cd /home/student/catkin_ws/build/headers/qt_vosk_app && $(CMAKE_COMMAND) -P CMakeFiles/qt_vosk_app_generate_messages_py.dir/cmake_clean.cmake
.PHONY : headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/clean

headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/depend:
	cd /home/student/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/catkin_ws/src /home/student/catkin_ws/src/headers/qt_vosk_app /home/student/catkin_ws/build /home/student/catkin_ws/build/headers/qt_vosk_app /home/student/catkin_ws/build/headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : headers/qt_vosk_app/CMakeFiles/qt_vosk_app_generate_messages_py.dir/depend

