cmake_minimum_required(VERSION 3.14)
project(kursach)

set(CMAKE_CXX_STANDARD 20)

add_executable(kursach main.cpp SinglyLinkedOrderedList.h SinglyLinkedOrderedList.cpp RBTree.cpp RBTree.hpp tests.hpp tests.cpp)