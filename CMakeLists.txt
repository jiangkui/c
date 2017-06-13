cmake_minimum_required(VERSION 3.5)
project(c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES five/5-2.c)
add_executable(c ${SOURCE_FILES})