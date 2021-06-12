#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
public:
  Graph();
  ~Graph();
  bool isEmpty() const;
  bool hasNode(int a) const;
  bool hasEdge(int a, int b) const;
  void insertNode(int a);
  void insertEdge(int a, int b, int weight);
  void deleteNode(int a);
  void deleteEdge(int a, int b);
  void print() const;
  void primAlgorithm() const;
  void kruskalAlgorithm() const;
private:
  int** matrix_;
  int size_;
};

#endif
