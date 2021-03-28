cmake_minimum_required(VERSION 3.16)
project(sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(sorts main.cpp sort-algorithms.hpp sort-algorithms.cpp)