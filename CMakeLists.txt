cmake_minimum_required(VERSION 3.16)

project (xrtcserver)

add_definitions("-g -pipe -W -Wall -fPIC -std=gnu++14 -DWEBRTC_POSIX -DWEBRTC_LINUX")

file(GLOB all_src
    "./src/*cpp"
)

add_executable(xrtcserver ${all_src})