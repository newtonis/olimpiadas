cmake_minimum_required(VERSION 3.1)
project(red)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES red.cpp redGrader.cpp)
add_executable(red ${SOURCE_FILES})