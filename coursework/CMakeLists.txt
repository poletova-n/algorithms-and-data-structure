cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")
set(SOURCE_FILES main.cpp rb-tree.cpp rb-tree.h)

add_executable(coursework main.cpp ${SOURCE_FILES})
