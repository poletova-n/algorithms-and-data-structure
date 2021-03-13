cmake_minimum_required(VERSION 3.17)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue main.cpp exception.hpp queue.hpp queueArray.hpp binarySearchTree.hpp stack.hpp stackArray.hpp test-queue.hpp test-binarySearchTree.hpp)