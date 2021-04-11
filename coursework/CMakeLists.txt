cmake_minimum_required(VERSION 3.17)
project(CourseWork)

set(CMAKE_CXX_STANDARD 14)

add_executable(CourseWork main.cpp List.hpp List.cpp AVLTree.cpp AVLTree.hpp Exceptions.hpp test.hpp)