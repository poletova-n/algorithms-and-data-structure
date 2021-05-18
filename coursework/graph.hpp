#ifndef GRAPH_HPP
#define GRAPH_HPP

template<class T>
class Graph
{
public:
  virtual ~Graph() = default;

  virtual void BFS() = 0;

  virtual bool isEmptyGraph() const = 0;
  virtual bool isVertexIncluded(const size_t& vertex) = 0;
  virtual bool isEdgeIncluded(const T& vertex1, const T& vertex2) = 0;

  virtual void addVertex(const T& newData) = 0;
  virtual void addWeightEdge(int number1, int number2, int weight = 0) = 0;

  virtual void deleteVertex(T data) = 0;
  virtual int deleteWeightEdge(const int& number1, const int& number2) = 0;
};

#endif
