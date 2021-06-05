#ifndef COURSEWORK_GRAPH_HPP
#define COURSEWORK_GRAPH_HPP

template<class T>
class Graph
{
public:
  virtual ~Graph() = default;

  virtual void insertNode(T value) = 0;

  virtual void insertEdge(T node1, T node2) = 0;

  virtual void deleteNode(T value) = 0;

  virtual void deleteEdge(T node1, T node2) = 0;

  virtual void print() = 0;

  virtual bool includeNode(T value) = 0;

  virtual bool includeEdge(T node1, T node2) = 0;

  virtual void DFS() = 0;

  virtual bool isEmpty() = 0;
};

#endif
