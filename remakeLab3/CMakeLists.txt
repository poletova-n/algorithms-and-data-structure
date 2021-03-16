cmake_minimum_required(VERSION 3.17)
project(remakeLab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(remakeLab3 main.cpp Stack.hpp StackArray.hpp exception.hpp operator.cpp operator.hpp)