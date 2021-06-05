cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursework main.cpp graph.hpp undirectedGraph.hpp doubleLinkedList.cpp doubleLinkedList.hpp stack.hpp stackArray.hpp exceptions.hpp directedGraph.hpp test-graph.hpp)