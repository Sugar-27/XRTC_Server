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
include absl/strings/CMakeFiles/cord.dir/depend.make

# Include the progress variables for this target.
include absl/strings/CMakeFiles/cord.dir/progress.make

# Include the compile flags for this target's objects.
include absl/strings/CMakeFiles/cord.dir/flags.make

absl/strings/CMakeFiles/cord.dir/cord.cc.o: absl/strings/CMakeFiles/cord.dir/flags.make
absl/strings/CMakeFiles/cord.dir/cord.cc.o: ../absl/strings/cord.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object absl/strings/CMakeFiles/cord.dir/cord.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cord.dir/cord.cc.o -c /home/sugar/project/abseil-cpp/absl/strings/cord.cc

absl/strings/CMakeFiles/cord.dir/cord.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cord.dir/cord.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/strings/cord.cc > CMakeFiles/cord.dir/cord.cc.i

absl/strings/CMakeFiles/cord.dir/cord.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cord.dir/cord.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/strings/cord.cc -o CMakeFiles/cord.dir/cord.cc.s

absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.o: absl/strings/CMakeFiles/cord.dir/flags.make
absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.o: ../absl/strings/cord_analysis.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cord.dir/cord_analysis.cc.o -c /home/sugar/project/abseil-cpp/absl/strings/cord_analysis.cc

absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cord.dir/cord_analysis.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/strings/cord_analysis.cc > CMakeFiles/cord.dir/cord_analysis.cc.i

absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cord.dir/cord_analysis.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/strings/cord_analysis.cc -o CMakeFiles/cord.dir/cord_analysis.cc.s

absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.o: absl/strings/CMakeFiles/cord.dir/flags.make
absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.o: ../absl/strings/cord_buffer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.o"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cord.dir/cord_buffer.cc.o -c /home/sugar/project/abseil-cpp/absl/strings/cord_buffer.cc

absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cord.dir/cord_buffer.cc.i"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/abseil-cpp/absl/strings/cord_buffer.cc > CMakeFiles/cord.dir/cord_buffer.cc.i

absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cord.dir/cord_buffer.cc.s"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/abseil-cpp/absl/strings/cord_buffer.cc -o CMakeFiles/cord.dir/cord_buffer.cc.s

# Object files for target cord
cord_OBJECTS = \
"CMakeFiles/cord.dir/cord.cc.o" \
"CMakeFiles/cord.dir/cord_analysis.cc.o" \
"CMakeFiles/cord.dir/cord_buffer.cc.o"

# External object files for target cord
cord_EXTERNAL_OBJECTS =

absl/strings/libabsl_cord.a: absl/strings/CMakeFiles/cord.dir/cord.cc.o
absl/strings/libabsl_cord.a: absl/strings/CMakeFiles/cord.dir/cord_analysis.cc.o
absl/strings/libabsl_cord.a: absl/strings/CMakeFiles/cord.dir/cord_buffer.cc.o
absl/strings/libabsl_cord.a: absl/strings/CMakeFiles/cord.dir/build.make
absl/strings/libabsl_cord.a: absl/strings/CMakeFiles/cord.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/abseil-cpp/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libabsl_cord.a"
	cd /home/sugar/project/abseil-cpp/out/absl/strings && $(CMAKE_COMMAND) -P CMakeFiles/cord.dir/cmake_clean_target.cmake
	cd /home/sugar/project/abseil-cpp/out/absl/strings && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cord.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
absl/strings/CMakeFiles/cord.dir/build: absl/strings/libabsl_cord.a

.PHONY : absl/strings/CMakeFiles/cord.dir/build

absl/strings/CMakeFiles/cord.dir/clean:
	cd /home/sugar/project/abseil-cpp/out/absl/strings && $(CMAKE_COMMAND) -P CMakeFiles/cord.dir/cmake_clean.cmake
.PHONY : absl/strings/CMakeFiles/cord.dir/clean

absl/strings/CMakeFiles/cord.dir/depend:
	cd /home/sugar/project/abseil-cpp/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/abseil-cpp /home/sugar/project/abseil-cpp/absl/strings /home/sugar/project/abseil-cpp/out /home/sugar/project/abseil-cpp/out/absl/strings /home/sugar/project/abseil-cpp/out/absl/strings/CMakeFiles/cord.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : absl/strings/CMakeFiles/cord.dir/depend
