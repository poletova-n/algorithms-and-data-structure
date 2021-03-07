cmake_minimum_required(VERSION 3.16)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3 Stack.cpp Stack.h StackArray.h StackOverflow.h StackUnderflow.h WrongStackSize.h)