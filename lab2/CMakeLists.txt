cmake_minimum_required(VERSION 3.16)
project(working)

set(CMAKE_CXX_STANDARD 14)

add_executable(working
        main.cpp stackoverflow.hpp stackunderflow.hpp stack.hpp wrongstacksize.hpp stackarray.hpp stacklist.hpp)