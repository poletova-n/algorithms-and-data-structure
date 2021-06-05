#ifndef COURSEWORK_TEST_GRAPH_HPP
#define COURSEWORK_TEST_GRAPH_HPP

#include <iostream>
#include "undirectedGraph.hpp"
#include "directedGraph.hpp"

void drawLine(int size)
{
  for (int i = 0 ; i < size; i++)
  {
    std::cout << "_";
  }
  std::cout << '\n';
}

void testUndirectedGraph()
{
  std::cout << "Undirected Graph Tests:\n\n";
  UndirectedGraph<int> undirGr;
  drawLine(40);
  std::cout << "Try to delete node from empty graph:\n";
  try
  {
    undirGr.deleteNode(1);
  }
  catch (GraphEmpty &error)
  {
    std::cout << error.what() << "\n";
  }
  drawLine(40);
  std::cout << "Add nodes 2, 3, 8, 4, 17, 13, 1:\n";
  undirGr.insertNode(2);
  undirGr.insertNode(3);
  undirGr.insertNode(8);
  undirGr.insertNode(4);
  undirGr.insertNode(17);
  undirGr.insertNode(13);
  undirGr.insertNode(1);
  drawLine(40);
  std::cout << "Delete 17\n";
  undirGr.deleteNode(17);
  drawLine(40);
  std::cout << "Add edges 2-3, 3-8, 2-4, 8-13, 8-4:\n";
  undirGr.insertEdge(2, 3);
  undirGr.insertEdge(3, 8);
  undirGr.insertEdge(2, 4);
  undirGr.insertEdge(8, 13);
  undirGr.insertEdge(8, 4);
  drawLine(40);
  std::cout << "Get DFS error because 1 is isolated:\n";
  try
  {
    undirGr.DFS();
  }
  catch (GraphDFCError &error)
  {
    std::cout << "\n" << error.what() << "\n";
  }
  drawLine(40);
  std::cout << "Connect 1 to graph:\n";
  undirGr.insertEdge(2, 1);
  drawLine(40);
  std::cout << "DFS:\n";
  undirGr.DFS();
  drawLine(40);
  std::cout << "Graph:\n";
  undirGr.print();
}

void testDirectedGraph()
{
  std::cout << "\nDirected Graph Tests:\n\n";
  DirectedGraph<int> dirGr;
  drawLine(40);
  std::cout << "Try to delete node from empty graph:\n";
  try
  {
    dirGr.deleteNode(1);
  }
  catch (GraphEmpty &error)
  {
    std::cout << error.what() << "\n";
  }
  drawLine(40);
  std::cout << "Add nodes 2, 3, 8, 4, 17, 13, 1:\n";
  dirGr.insertNode(2);
  dirGr.insertNode(3);
  dirGr.insertNode(8);
  dirGr.insertNode(4);
  dirGr.insertNode(17);
  dirGr.insertNode(13);
  dirGr.insertNode(1);
  drawLine(40);
  std::cout << "Delete 17\n";
  dirGr.deleteNode(17);
  drawLine(40);
  std::cout << "Add edges 2->3, 3->8, 8->2, 2->4, 8->13, 8->4:\n";
  dirGr.insertEdge(2, 3);
  dirGr.insertEdge(3, 8);
  dirGr.insertEdge(8, 2);
  dirGr.insertEdge(2, 4);
  dirGr.insertEdge(8, 13);
  dirGr.insertEdge(8, 4);
  drawLine(40);
  std::cout << "Get DFS error because 1 is isolated:\n";
  try
  {
    dirGr.DFS();
  }
  catch (GraphDFCError &error)
  {
    std::cout << "\n" << error.what() << "\n";
  }
  drawLine(40);
  std::cout << "Connect 1 to graph:\n";
  dirGr.insertEdge(2, 1);
  drawLine(40);
  std::cout << "DFS:\n";
  dirGr.DFS();
  drawLine(40);
  std::cout << "Strongly connected components:\n";
  dirGr.SCC();
  drawLine(40);
  std::cout << "Graph:\n";
  dirGr.print();
  drawLine(40);
  std::cout << "Transposed graph:\n";
  DirectedGraph<int> transDirGr = dirGr.getTranspose();
  transDirGr.print();
}

#endif
