cmake_minimum_required(VERSION 3.16)
project(bst)

set(CMAKE_CXX_STANDARD 14)

add_executable(bst main.cpp BinarySearchTree.h Stack.h StackArray.h)