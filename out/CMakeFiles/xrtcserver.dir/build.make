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
CMAKE_SOURCE_DIR = /home/sugar/project/cpp/xrtcserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sugar/project/cpp/xrtcserver/out

# Include any dependencies generated for this target.
include CMakeFiles/xrtcserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xrtcserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xrtcserver.dir/flags.make

CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o: ../src/base/conf.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/base/conf.cpp

CMakeFiles/xrtcserver.dir/src/base/conf.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/base/conf.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/base/conf.cpp > CMakeFiles/xrtcserver.dir/src/base/conf.cpp.i

CMakeFiles/xrtcserver.dir/src/base/conf.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/base/conf.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/base/conf.cpp -o CMakeFiles/xrtcserver.dir/src/base/conf.cpp.s

CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o: ../src/base/event_loop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/base/event_loop.cpp

CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/base/event_loop.cpp > CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.i

CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/base/event_loop.cpp -o CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.s

CMakeFiles/xrtcserver.dir/src/base/log.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/base/log.cpp.o: ../src/base/log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/xrtcserver.dir/src/base/log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/base/log.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/base/log.cpp

CMakeFiles/xrtcserver.dir/src/base/log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/base/log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/base/log.cpp > CMakeFiles/xrtcserver.dir/src/base/log.cpp.i

CMakeFiles/xrtcserver.dir/src/base/log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/base/log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/base/log.cpp -o CMakeFiles/xrtcserver.dir/src/base/log.cpp.s

CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o: ../src/base/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/base/socket.cpp

CMakeFiles/xrtcserver.dir/src/base/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/base/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/base/socket.cpp > CMakeFiles/xrtcserver.dir/src/base/socket.cpp.i

CMakeFiles/xrtcserver.dir/src/base/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/base/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/base/socket.cpp -o CMakeFiles/xrtcserver.dir/src/base/socket.cpp.s

CMakeFiles/xrtcserver.dir/src/main.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/xrtcserver.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/main.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/main.cpp

CMakeFiles/xrtcserver.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/main.cpp > CMakeFiles/xrtcserver.dir/src/main.cpp.i

CMakeFiles/xrtcserver.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/main.cpp -o CMakeFiles/xrtcserver.dir/src/main.cpp.s

CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o: ../src/server/rtc_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/server/rtc_server.cpp

CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/server/rtc_server.cpp > CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.i

CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/server/rtc_server.cpp -o CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.s

CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o: ../src/server/signaling_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/server/signaling_server.cpp

CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/server/signaling_server.cpp > CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.i

CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/server/signaling_server.cpp -o CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.s

CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o: ../src/server/signaling_worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/server/signaling_worker.cpp

CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/server/signaling_worker.cpp > CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.i

CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/server/signaling_worker.cpp -o CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.s

CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o: CMakeFiles/xrtcserver.dir/flags.make
CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o: ../src/server/tcp_connection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o -c /home/sugar/project/cpp/xrtcserver/src/server/tcp_connection.cpp

CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sugar/project/cpp/xrtcserver/src/server/tcp_connection.cpp > CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.i

CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sugar/project/cpp/xrtcserver/src/server/tcp_connection.cpp -o CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.s

# Object files for target xrtcserver
xrtcserver_OBJECTS = \
"CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/base/log.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/main.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o" \
"CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o"

# External object files for target xrtcserver
xrtcserver_EXTERNAL_OBJECTS =

xrtcserver: CMakeFiles/xrtcserver.dir/src/base/conf.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/base/event_loop.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/base/log.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/base/socket.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/main.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/server/rtc_server.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/server/signaling_server.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/server/signaling_worker.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/src/server/tcp_connection.cpp.o
xrtcserver: CMakeFiles/xrtcserver.dir/build.make
xrtcserver: CMakeFiles/xrtcserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sugar/project/cpp/xrtcserver/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable xrtcserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xrtcserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xrtcserver.dir/build: xrtcserver

.PHONY : CMakeFiles/xrtcserver.dir/build

CMakeFiles/xrtcserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xrtcserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xrtcserver.dir/clean

CMakeFiles/xrtcserver.dir/depend:
	cd /home/sugar/project/cpp/xrtcserver/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sugar/project/cpp/xrtcserver /home/sugar/project/cpp/xrtcserver /home/sugar/project/cpp/xrtcserver/out /home/sugar/project/cpp/xrtcserver/out /home/sugar/project/cpp/xrtcserver/out/CMakeFiles/xrtcserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xrtcserver.dir/depend

