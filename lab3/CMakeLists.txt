cmake_minimum_required(VERSION 3.17)
project(stacks)

set(CMAKE_CXX_STANDARD 14)

add_executable(stacks main.cpp stack.h stackArray.h exception.h main.cpp operator.h)