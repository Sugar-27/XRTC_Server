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
CMAKE_SOURCE_DIR = /home/sugar/project/abseil-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sugar/project/abseil-cpp/out

# Include any dependencies generated for this target.
include absl/log/CMakeFiles/log_sink.dir/depend.make

# Include the progress variables for this target.
include absl/log/CMakeFiles/log_sink.dir/progress.make

# Include the compile flags for this target's objects.
include absl/log/CMakeFiles/log_sink.dir/flags.make

absl/log/CMakeFiles/log_sink.dir/log_sink.cc.o: absl/log/CMakeFiles/log_sink.dir/flags.make
absl/log/CMakeFiles/log_sink.dir/log_sink.cc.o: ../absl/log/log_sink.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/log/CMakeFiles/log_sink.dir/log_sink.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/log && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/log_sink.dir/log_sink.cc.o -c /home/sugar/project/abseil-cpp/absl/log/log_sink.cc

absl/log/CMakeFiles/log_sink.dir/log_sink.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/log_sink.dir/log_sink.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/log/log_sink.cc > CMakeFiles/log_sink.dir/log_sink.cc.i

absl/log/CMakeFiles/log_sink.dir/log_sink.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/log_sink.dir/log_sink.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/log/log_sink.cc -o CMakeFiles/log_sink.dir/log_sink.cc.s

# Object files for target log_sink
log_sink_OBJECTS = \
"CMakeFiles/log_sink.dir/log_sink.cc.o"

# External object files for target log_sink
log_sink_EXTERNAL_OBJECTS =

absl/log/libabsl_log_sink.a: absl/log/CMakeFiles/log_sink.dir/log_sink.cc.o
absl/log/libabsl_log_sink.a: absl/log/CMakeFiles/log_sink.dir/build.make
absl/log/libabsl_log_sink.a: absl/log/CMakeFiles/log_sink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_log_sink.a"
	cd /home/sugar/project/abseil-cpp/out/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/log_sink.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/log_sink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/log/CMakeFiles/log_sink.dir/build: absl/log/libabsl_log_sink.a

.PHONY : absl/log/CMakeFiles/log_sink.dir/build

absl/log/CMakeFiles/log_sink.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/log_sink.dir/cmake_clean.cmake
.PHONY : absl/log/CMakeFiles/log_sink.dir/clean

absl/log/CMakeFiles/log_sink.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/log /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/log /home/sugar/project/abseil-cpp/out/absl/log/CMakeFiles/log_sink.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/log/CMakeFiles/log_sink.dir/depend
