cmake_minimum_required(VERSION 3.13)
project(numerical_algorithms)

set(CMAKE_CXX_STANDARD 14)

file(COPY resources DESTINATION ${CMAKE_BINARY_DIR})

include_directories(.)

add_executable(numerical_algorithms main.cpp dependency.h lib/cli/menu/menu.h lib/cli/menu/menu.cpp paths.h lib/utility.h lib/utility.cpp)