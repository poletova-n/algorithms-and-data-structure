cmake_minimum_required(VERSION 3.16)
project(bst)

set(CMAKE_CXX_STANDARD 14)

add_executable(bst main.cpp stackOverflow.h stackUnderflow.h wrongStackSize.h Stack.h StackArray.h)