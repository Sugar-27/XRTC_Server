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
include absl/flags/CMakeFiles/flags_marshalling.dir/depend.make

# Include the progress variables for this target.
include absl/flags/CMakeFiles/flags_marshalling.dir/progress.make

# Include the compile flags for this target's objects.
include absl/flags/CMakeFiles/flags_marshalling.dir/flags.make

absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.o: absl/flags/CMakeFiles/flags_marshalling.dir/flags.make
absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.o: ../absl/flags/marshalling.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flags_marshalling.dir/marshalling.cc.o -c /home/sugar/project/abseil-cpp/absl/flags/marshalling.cc

absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flags_marshalling.dir/marshalling.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/flags/marshalling.cc > CMakeFiles/flags_marshalling.dir/marshalling.cc.i

absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flags_marshalling.dir/marshalling.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/flags/marshalling.cc -o CMakeFiles/flags_marshalling.dir/marshalling.cc.s

# Object files for target flags_marshalling
flags_marshalling_OBJECTS = \
"CMakeFiles/flags_marshalling.dir/marshalling.cc.o"

# External object files for target flags_marshalling
flags_marshalling_EXTERNAL_OBJECTS =

absl/flags/libabsl_flags_marshalling.a: absl/flags/CMakeFiles/flags_marshalling.dir/marshalling.cc.o
absl/flags/libabsl_flags_marshalling.a: absl/flags/CMakeFiles/flags_marshalling.dir/build.make
absl/flags/libabsl_flags_marshalling.a: absl/flags/CMakeFiles/flags_marshalling.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_flags_marshalling.a"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_marshalling.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flags_marshalling.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/flags/CMakeFiles/flags_marshalling.dir/build: absl/flags/libabsl_flags_marshalling.a

.PHONY : absl/flags/CMakeFiles/flags_marshalling.dir/build

absl/flags/CMakeFiles/flags_marshalling.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_marshalling.dir/cmake_clean.cmake
.PHONY : absl/flags/CMakeFiles/flags_marshalling.dir/clean

absl/flags/CMakeFiles/flags_marshalling.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/flags /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/flags /home/sugar/project/abseil-cpp/out/absl/flags/CMakeFiles/flags_marshalling.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/flags/CMakeFiles/flags_marshalling.dir/depend

