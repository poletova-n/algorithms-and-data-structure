cmake_minimum_required(VERSION 3.19)
project(kursovaya)

set(CMAKE_CXX_STANDARD 14)

add_executable(kursovaya main.cpp hash.hpp hash.cpp table.hpp)