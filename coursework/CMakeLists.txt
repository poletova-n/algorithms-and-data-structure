cmake_minimum_required(VERSION 3.16)
project(coursework)

set(CMAKE_CXX_STANDARD 20)

add_executable(coursework main.cpp avltree.hpp avltree.cpp tests.hpp)