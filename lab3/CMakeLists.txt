cmake_minimum_required(VERSION 3.16)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 main.cpp stack.h stackArray.h stackOverflow.h stackUnderflow.h wrongStackSize.h)