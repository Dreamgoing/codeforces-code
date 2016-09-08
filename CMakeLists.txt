cmake_minimum_required(VERSION 3.3)
project(cf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 365d.cpp)
add_executable(365d ${SOURCE_FILES})