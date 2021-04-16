cmake_minimum_required(VERSION 3.16)
project(coursework)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursework RedBlackTree.cpp RedBlackTree.hpp DoubleLinkedList.cpp DoubleLinkedList.hpp main.cpp)