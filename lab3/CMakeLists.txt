cmake_minimum_required(VERSION 3.17)
project(lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab3 main.cpp Stack.hpp StackArray.hpp exception.hpp operator.hpp operator.cpp)