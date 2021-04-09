cmake_minimum_required(VERSION 3.17)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp
        Tree.h
        Queue.h
        QueueException.h QueueArray.h stack.h stackArray.h stackOverflow.h
        stackUnderflow.h
        wrongStackSize.h)