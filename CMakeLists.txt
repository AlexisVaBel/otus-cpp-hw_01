cmake_minimum_required(VERSION 3.7)

project(final)
include_directories ("version")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lpthread ")
set(SRC_LIST main.cpp)
add_executable(final ${SRC_LIST})


