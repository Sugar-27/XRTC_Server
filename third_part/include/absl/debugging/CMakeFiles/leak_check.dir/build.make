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
include absl/debugging/CMakeFiles/leak_check.dir/depend.make

# Include the progress variables for this target.
include absl/debugging/CMakeFiles/leak_check.dir/progress.make

# Include the compile flags for this target's objects.
include absl/debugging/CMakeFiles/leak_check.dir/flags.make

absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.o: absl/debugging/CMakeFiles/leak_check.dir/flags.make
absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.o: ../absl/debugging/leak_check.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leak_check.dir/leak_check.cc.o -c /home/sugar/project/abseil-cpp/absl/debugging/leak_check.cc

absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leak_check.dir/leak_check.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/debugging/leak_check.cc > CMakeFiles/leak_check.dir/leak_check.cc.i

absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leak_check.dir/leak_check.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/debugging/leak_check.cc -o CMakeFiles/leak_check.dir/leak_check.cc.s

# Object files for target leak_check
leak_check_OBJECTS = \
"CMakeFiles/leak_check.dir/leak_check.cc.o"

# External object files for target leak_check
leak_check_EXTERNAL_OBJECTS =

absl/debugging/libabsl_leak_check.a: absl/debugging/CMakeFiles/leak_check.dir/leak_check.cc.o
absl/debugging/libabsl_leak_check.a: absl/debugging/CMakeFiles/leak_check.dir/build.make
absl/debugging/libabsl_leak_check.a: absl/debugging/CMakeFiles/leak_check.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_leak_check.a"
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && $(CMAKE_COMMAND) -P CMakeFiles/leak_check.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leak_check.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/debugging/CMakeFiles/leak_check.dir/build: absl/debugging/libabsl_leak_check.a

.PHONY : absl/debugging/CMakeFiles/leak_check.dir/build

absl/debugging/CMakeFiles/leak_check.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/debugging && $(CMAKE_COMMAND) -P CMakeFiles/leak_check.dir/cmake_clean.cmake
.PHONY : absl/debugging/CMakeFiles/leak_check.dir/clean

absl/debugging/CMakeFiles/leak_check.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/debugging /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/debugging /home/sugar/project/abseil-cpp/out/absl/debugging/CMakeFiles/leak_check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/debugging/CMakeFiles/leak_check.dir/depend

