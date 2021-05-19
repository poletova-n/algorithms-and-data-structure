cmake_minimum_required(VERSION 3.17)
project(coursework)

set(CMAKE_CXX_STANDARD 14)

add_executable(coursework main.cpp
        utility.cpp utility.hpp
        encryption.cpp encryption.hpp
        BinaryTree.hpp BinaryTree.cpp
        List.hpp)