#ifndef GRAPH_HPP
#define GRAPH_HPP

template<class T>
class Graph
{
  public:
  virtual ~Graph()
  {}

  virtual void addNode(const T &newItem) = 0;

  virtual void addLine(const int &node1, const int &node2) = 0;

  virtual void deleteLine(const int &node1, const int &node2) = 0;

  virtual void deleteNode(const T &index_g) = 0;

  virtual bool isEmpty() const = 0;

  virtual bool isIncludeLine(const int &node1, const int &node2) = 0;

  virtual bool isIncludeNode(const T &node) = 0;

  virtual void DFC() = 0;
};

#endif
