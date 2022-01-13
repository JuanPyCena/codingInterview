cmake_minimum_required(VERSION 3.21)
project(interview)

set(CMAKE_CXX_STANDARD 14)

add_executable(interview main.cpp helperfunctions.h)
add_executable(test test_main.cpp helperfunctions.h)
