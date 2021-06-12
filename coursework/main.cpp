#include <iostream>

#include "Graph.hpp"

int main()
{
  Graph graph;
  std::cout << std::boolalpha;
  std::cout << "Graph is empty: " << graph.isEmpty() << '\n';
  for (int i = 0; i < 7; i++)
  {
    graph.insertNode(i);
  }
  graph.insertEdge(0, 1, 7);//A0 B1 C2 D3 E4 F5 G6
  graph.insertEdge(0, 3, 5);
  graph.insertEdge(1, 2, 8);
  graph.insertEdge(1, 3, 9);
  graph.insertEdge(1, 4, 7);
  graph.insertEdge(2, 4, 5);
  graph.insertEdge(3, 4, 15);
  graph.insertEdge(3, 5, 6);
  graph.insertEdge(4, 5, 8);
  graph.insertEdge(4, 6, 9);
  graph.insertEdge(5, 6, 11);
  std::cout << std::endl;
  std::cout << "Test hasNode: " << graph.hasNode(6)  << '\n';
  std::cout << "Test hasEdge: " << graph.hasEdge(8, 5)  << '\n';
  graph.print();
  std::cout << std::endl;
  graph.kruskalAlgorithm();
  graph.primAlgorithm();
  std::cout << "Test deleteNode 1: " << '\n';
  graph.deleteNode(1);
  graph.print();
  std::cout << "Test deleteEdge 4-6: " << '\n';
  graph.deleteEdge(4, 6);
  graph.print();
  return 0;
}
