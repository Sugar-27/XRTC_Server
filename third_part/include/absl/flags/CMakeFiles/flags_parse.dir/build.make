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
include absl/flags/CMakeFiles/flags_parse.dir/depend.make

# Include the progress variables for this target.
include absl/flags/CMakeFiles/flags_parse.dir/progress.make

# Include the compile flags for this target's objects.
include absl/flags/CMakeFiles/flags_parse.dir/flags.make

absl/flags/CMakeFiles/flags_parse.dir/parse.cc.o: absl/flags/CMakeFiles/flags_parse.dir/flags.make
absl/flags/CMakeFiles/flags_parse.dir/parse.cc.o: ../absl/flags/parse.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/flags/CMakeFiles/flags_parse.dir/parse.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/flags_parse.dir/parse.cc.o -c /home/sugar/project/abseil-cpp/absl/flags/parse.cc

absl/flags/CMakeFiles/flags_parse.dir/parse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/flags_parse.dir/parse.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/flags/parse.cc > CMakeFiles/flags_parse.dir/parse.cc.i

absl/flags/CMakeFiles/flags_parse.dir/parse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/flags_parse.dir/parse.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/flags/parse.cc -o CMakeFiles/flags_parse.dir/parse.cc.s

# Object files for target flags_parse
flags_parse_OBJECTS = \
"CMakeFiles/flags_parse.dir/parse.cc.o"

# External object files for target flags_parse
flags_parse_EXTERNAL_OBJECTS =

absl/flags/libabsl_flags_parse.a: absl/flags/CMakeFiles/flags_parse.dir/parse.cc.o
absl/flags/libabsl_flags_parse.a: absl/flags/CMakeFiles/flags_parse.dir/build.make
absl/flags/libabsl_flags_parse.a: absl/flags/CMakeFiles/flags_parse.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_flags_parse.a"
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_parse.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/flags_parse.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/flags/CMakeFiles/flags_parse.dir/build: absl/flags/libabsl_flags_parse.a

.PHONY : absl/flags/CMakeFiles/flags_parse.dir/build

absl/flags/CMakeFiles/flags_parse.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/flags && $(CMAKE_COMMAND) -P CMakeFiles/flags_parse.dir/cmake_clean.cmake
.PHONY : absl/flags/CMakeFiles/flags_parse.dir/clean

absl/flags/CMakeFiles/flags_parse.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/flags /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/flags /home/sugar/project/abseil-cpp/out/absl/flags/CMakeFiles/flags_parse.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/flags/CMakeFiles/flags_parse.dir/depend
