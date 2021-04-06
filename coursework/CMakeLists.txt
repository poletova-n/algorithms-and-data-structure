cmake_minimum_required(VERSION 3.17)
project(cur)

set(CMAKE_CXX_STANDARD 14)

add_executable(cur main.cpp queue.hpp array.hpp queueArray.hpp singlyLinkedOrderedList.hpp graph.hpp directedGraph.hpp undirectedGraph.hpp stack.hpp stackArray.hpp exceptionQueue.hpp exceptionStack.hpp exceptionGraph.hpp testUndirectedraph.hpp testDirectedGraph.hpp exceptionList.hpp exceptionArray.hpp)