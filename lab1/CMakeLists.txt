cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES ../main.cpp)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        DoubleLinkedList.h
        )
set(PROJECT_SOURCES
        DoubleLinkedList.cpp
        main.cpp
        )

add_executable(lab_1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})