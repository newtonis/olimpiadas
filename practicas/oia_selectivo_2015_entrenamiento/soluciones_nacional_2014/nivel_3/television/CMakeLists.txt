cmake_minimum_required(VERSION 3.1)
project(television)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES television.cpp televisionGrader.cpp)
add_executable(television ${SOURCE_FILES})