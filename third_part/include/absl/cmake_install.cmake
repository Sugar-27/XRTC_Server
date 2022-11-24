# Install script for directory: /home/sugar/project/abseil-cpp/absl

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/sugar/project/abseil-cpp/out/absl/base/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/algorithm/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/cleanup/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/container/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/crc/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/debugging/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/flags/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/functional/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/hash/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/log/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/memory/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/meta/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/numeric/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/profiling/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/random/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/status/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/strings/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/synchronization/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/time/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/types/cmake_install.cmake")
  include("/home/sugar/project/abseil-cpp/out/absl/utility/cmake_install.cmake")

endif()

