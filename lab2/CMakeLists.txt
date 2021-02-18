cmake_minimum_required(VERSION 3.17)
project(lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES ../main.cpp)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_HEADERS
        stackarray.hpp
        stacklist.hpp
        exceptions.hpp
        stack.hpp
        )
set(PROJECT_SOURCES
        main.cpp
        )

add_executable(lab_2 ${PROJECT_SOURCES} ${PROJECT_HEADERS})