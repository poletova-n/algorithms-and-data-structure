cmake_minimum_required(VERSION 3.17)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5
        exceptions.h
        main.cpp
        queue.h
        queuearray.h
        queuelist.h)
