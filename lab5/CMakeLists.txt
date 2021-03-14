cmake_minimum_required(VERSION 3.16)
project(lab5)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab5 main.cpp queueOverflow.hpp wrongQueueSize.hpp queueUnderflow.hpp queue.hpp queueArray.hpp binarySearchTree.hpp stack.hpp stackArray.hpp stackOverflow.hpp stackUnderflow.hpp wrongStackSize.hpp)