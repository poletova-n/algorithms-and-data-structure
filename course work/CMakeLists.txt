cmake_minimum_required(VERSION 3.17)
project(coursach)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursach main.cpp list.hpp list.cpp binarySearchTree.hpp BinarySearchTree.cpp tests.hpp tests.cpp)