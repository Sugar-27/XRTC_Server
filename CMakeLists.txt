cmake_minimum_required(VERSION 3.16)

project (xrtcserver)

add_definitions("-g -pipe -W -Wall -fPIC -std=gnu++14 -DWEBRTC_POSIX -DWEBRTC_LINUX")

include_directories(
    "./src"
    "./third_part/include"
)

link_directories(
    "./third_part/lib"
)

file(GLOB all_src
    "./src/*cpp"
    "./src/base/*.cpp"
)

add_executable(xrtcserver ${all_src})

target_link_libraries(xrtcserver libyaml-cpp.a)