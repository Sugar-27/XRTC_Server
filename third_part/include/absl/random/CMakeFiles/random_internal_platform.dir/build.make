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
include absl/random/CMakeFiles/random_internal_platform.dir/depend.make

# Include the progress variables for this target.
include absl/random/CMakeFiles/random_internal_platform.dir/progress.make

# Include the compile flags for this target's objects.
include absl/random/CMakeFiles/random_internal_platform.dir/flags.make

absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o: absl/random/CMakeFiles/random_internal_platform.dir/flags.make
absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o: ../absl/random/internal/randen_round_keys.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/random && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o -c /home/sugar/project/abseil-cpp/absl/random/internal/randen_round_keys.cc

absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/random && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/random/internal/randen_round_keys.cc > CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.i

absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/random && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/random/internal/randen_round_keys.cc -o CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.s

# Object files for target random_internal_platform
random_internal_platform_OBJECTS = \
"CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o"

# External object files for target random_internal_platform
random_internal_platform_EXTERNAL_OBJECTS =

absl/random/libabsl_random_internal_platform.a: absl/random/CMakeFiles/random_internal_platform.dir/internal/randen_round_keys.cc.o
absl/random/libabsl_random_internal_platform.a: absl/random/CMakeFiles/random_internal_platform.dir/build.make
absl/random/libabsl_random_internal_platform.a: absl/random/CMakeFiles/random_internal_platform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_random_internal_platform.a"
	cd /home/sugar/project/abseil-cpp/out/absl/random && $(CMAKE_COMMAND) -P CMakeFiles/random_internal_platform.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/random && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/random_internal_platform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/random/CMakeFiles/random_internal_platform.dir/build: absl/random/libabsl_random_internal_platform.a

.PHONY : absl/random/CMakeFiles/random_internal_platform.dir/build

absl/random/CMakeFiles/random_internal_platform.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/random && $(CMAKE_COMMAND) -P CMakeFiles/random_internal_platform.dir/cmake_clean.cmake
.PHONY : absl/random/CMakeFiles/random_internal_platform.dir/clean

absl/random/CMakeFiles/random_internal_platform.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/random /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/random /home/sugar/project/abseil-cpp/out/absl/random/CMakeFiles/random_internal_platform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/random/CMakeFiles/random_internal_platform.dir/depend

