#ifndef TEST_UNDIRECTEDGRAPH_HPP
#define TEST_UNDIRECTEDGRAPH_HPP

#include <iostream>
#include "undirectedGraph.hpp"

void testEmptyGraphError()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Empty Undirected Graph Error\n";
  UndirectedGraph<int> undirectedGraph;
  std::cout << "isEmptyGraph: " << (undirectedGraph.isEmptyGraph() ? "Yes" : "No") << "\n";
  std::cout << "Try to delete vertex: ";
  try {
    undirectedGraph.deleteVertex(5);
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }
}

void testNewGraph()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: New Undirected Graph\n";
  UndirectedGraph<int> undirectedGraph;
  undirectedGraph.addVertex(0);
  undirectedGraph.addVertex(1);
  undirectedGraph.addVertex(2);
  undirectedGraph.addVertex(3);
  undirectedGraph.addVertex(4);
  undirectedGraph.addVertex(5);
  try {
    undirectedGraph.addWeightEdge(0, 1, 40);
    undirectedGraph.addWeightEdge(0, 4, 18);
    undirectedGraph.addWeightEdge(1, 4, 15);
    undirectedGraph.addWeightEdge(1, 3, 6);
    undirectedGraph.addWeightEdge(1, 2, 22);
    undirectedGraph.addWeightEdge(3, 4, 20);
    undirectedGraph.addWeightEdge(2, 3, 14);
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  undirectedGraph.print();
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Including Components\n";
  std::cout << "is Vertex include?\n";
  std::cout << (undirectedGraph.isVertexIncluded(0) ? "Yes, we have vertex 0\n" : "No we haven't this vertex 0\n");
  std::cout << (undirectedGraph.isVertexIncluded(2) ? "Yes, we have vertex 2\n" : "No we haven't this vertex 2\n");
  std::cout << (undirectedGraph.isVertexIncluded(7) ? "Yes, we have vertex 7\n" : "No we haven't this vertex 7\n");
  std::cout << "is Edge include?\n";
  std::cout << (undirectedGraph.isEdgeIncluded(0, 4) ? "Yes, we have edge between vertex 0 and vertex 4\n" : "No, we haven't edge between vertex 0 and vertex 4\n");
  std::cout << (undirectedGraph.isEdgeIncluded(2, 1) ? "Yes, we have edge between vertex 2 and vertex 1\n" : "No, we haven't edge between vertex 2 and vertex 1\n");
  std::cout << (undirectedGraph.isEdgeIncluded(0, 3) ? "Yes, we have edge between vertex 0 and vertex 3\n" : "No, we haven't edge between vertex 0 and vertex 3\n");
}

void testDeleteVertexes()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Before Deleting Vertexes\n";
  UndirectedGraph<int> undirectedGraph;
  undirectedGraph.addVertex(0);
  undirectedGraph.addVertex(1);
  undirectedGraph.addVertex(2);
  undirectedGraph.addVertex(3);
  undirectedGraph.addVertex(4);
  undirectedGraph.addVertex(5);
  try {
    undirectedGraph.addWeightEdge(0, 1, 40);
    undirectedGraph.addWeightEdge(0, 4, 18);
    undirectedGraph.addWeightEdge(1, 4, 15);
    undirectedGraph.addWeightEdge(1, 3, 6);
    undirectedGraph.addWeightEdge(1, 2, 22);
    undirectedGraph.addWeightEdge(3, 4, 20);
    undirectedGraph.addWeightEdge(2, 3, 14);
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  std::cout << "Before deleting\n";
  undirectedGraph.print();

  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Deleting Vertexes\n";
  std::cout << "Try to delete 2 (must be correct):\n";
  try {
    undirectedGraph.deleteVertex(2);
    undirectedGraph.print();
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  std::cout << "Try to delete 9 (must be incorrect):\n";
  try {
    undirectedGraph.deleteVertex(9);
    undirectedGraph.print();
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  std::cout << "Try to delete 0 (must be correct):\n";
  try {
    undirectedGraph.deleteVertex(0);
    undirectedGraph.print();
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }
}

void testDeleteEdges()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Before Deleting Edges\n";
  UndirectedGraph<int> undirectedGraph;
  undirectedGraph.addVertex(0);
  undirectedGraph.addVertex(1);
  undirectedGraph.addVertex(2);
  undirectedGraph.addVertex(3);
  undirectedGraph.addVertex(4);
  undirectedGraph.addVertex(5);
  try {
    undirectedGraph.addWeightEdge(0, 1, 40);
    undirectedGraph.addWeightEdge(0, 4, 18);
    undirectedGraph.addWeightEdge(1, 4, 15);
    undirectedGraph.addWeightEdge(1, 3, 6);
    undirectedGraph.addWeightEdge(1, 2, 22);
    undirectedGraph.addWeightEdge(3, 4, 20);
    undirectedGraph.addWeightEdge(2, 3, 14);
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  std::cout << "Before deleting\n";
  undirectedGraph.print();

  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: Deleting Edges\n";
  std::cout << "Try to delete edge between 1 and 3 (must be correct):\n";
  try {
    std::cout << undirectedGraph.deleteWeightEdge(1, 3) << std::endl;
    undirectedGraph.print();
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongEdgeGraph& error) {
    std::cerr << error.getError() << "\n";
  }

  std::cout << "Try to delete edge between 3 and 5 (must be incorrect):\n";
  try {
    std::cout << undirectedGraph.deleteWeightEdge(3, 5) << std::endl;
    undirectedGraph.print();
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongEdgeGraph& error) {
    std::cerr << error.getError() << "\n";
  }
}

void testBFS()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: BFS\n";
  UndirectedGraph<int> undirectedGraph;
  undirectedGraph.addVertex(0);
  undirectedGraph.addVertex(3);
  undirectedGraph.addVertex(5);
  undirectedGraph.addVertex(4);
  undirectedGraph.addVertex(1);
  undirectedGraph.addVertex(6);
  undirectedGraph.addVertex(7);
  try {
    undirectedGraph.addWeightEdge(0, 1, 40);
    undirectedGraph.addWeightEdge(0, 2, 18);
    undirectedGraph.addWeightEdge(1, 3, 15);
    undirectedGraph.addWeightEdge(1, 4, 6);
    undirectedGraph.addWeightEdge(3, 5, 20);
    undirectedGraph.addWeightEdge(2, 6, 10);
  }
  catch (EmptyGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  catch (WrongVertexGraph& error) {
    std::cerr << error.getError() << "\n";
  }
  undirectedGraph.print();

  try {
    undirectedGraph.BFS();
    std::cout << std::endl;
  }
  catch (GraphBFSError& error) {
    std::cerr << error.getError() << "\n";
  }
}

void testUndirectedGraph()
{
  testEmptyGraphError();
  testNewGraph();
  testDeleteVertexes();
  testDeleteEdges();
  testBFS();
}

#endif
