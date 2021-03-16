cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(lab3
        main.cpp
        stack.hpp
        stackArray.hpp
        operator.cpp operator.hpp)