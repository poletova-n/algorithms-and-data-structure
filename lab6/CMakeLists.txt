cmake_minimum_required(VERSION 3.17)
project(lab6)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab6 main.cpp
        binarytree.hpp
        exceptionS.hpp
        stack.hpp
        stacklist.hpp
        exceptionQ.hpp
        queue.hpp
        queueList.hpp)