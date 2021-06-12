#include "Graph.hpp"

#include <iostream>

Graph::Graph():
  matrix_(nullptr),
  size_(0)
{}

Graph::~Graph()
{
  if (matrix_ == nullptr)
  {
    return;
  }
  for (int i = 0; i < size_; i++)
  {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

bool Graph::isEmpty() const
{
  return size_ == 0;
}

bool Graph::hasNode(int a) const
{
  if (a < size_)
  {
    for (int i = 0; i < size_; i++)
    {
      if (matrix_[a][i] != INT32_MAX)
      {
        return true;
      }
    }
  }
  return false;
}

bool Graph::hasEdge(int a, int b) const
{
  return matrix_ != nullptr && a < size_ && b < size_ && matrix_[a][b] != INT32_MAX;
}

void Graph::insertNode(int a)
{
  if (matrix_ == nullptr)
  {
    size_ = a + 1;
    matrix_ = new int*[size_];
    for (int i = 0; i < size_; i++)
    {
      matrix_[i] = new int[size_];
      for (int j = 0; j < size_; j++)
      {
        matrix_[i][j] = INT32_MAX;
      }
    }
  }
  else if (a >= size_)
  {
    int tempSize = a + 1;
    int** tempMatrix = new int*[tempSize];
    for (int i = 0; i < tempSize; i++)
    {
      tempMatrix[i] = new int[tempSize];
    }
    for (int i = 0; i < size_; i++)
    {
      for (int j = 0; j < size_; j++)
      {
        tempMatrix[i][j] = matrix_[i][j];
      }
    }
    std::swap(matrix_, tempMatrix);
    for (int i = 0; i < size_; i++)
    {
      delete[] tempMatrix[i];
    }
    delete[] tempMatrix;
    for (int i = 0; i < tempSize; i++)
    {
      for (int j = size_; j < tempSize; j++)
      {
        matrix_[i][j] = INT32_MAX;
        matrix_[j][i] = INT32_MAX;
      }
    }
    size_ = tempSize;
  }
}

void Graph::insertEdge(int a, int b, int weight)
{
  if (a >= size_ || b >= size_)
  {
    throw std::logic_error("Node is not inserted");
  }
  matrix_[a][b] = weight;
  matrix_[b][a] = weight;
}

void Graph::deleteNode(int a)
{
  for (int i = 0; i < size_; i++)
  {
    matrix_[i][a] = INT32_MAX;
    matrix_[a][i] = INT32_MAX;
  }
}

void Graph::deleteEdge(int a, int b)
{
  matrix_[a][b] = INT32_MAX;
  matrix_[b][a] = INT32_MAX;
}

void Graph::print() const
{
  for (int i = 0; i < size_; i++)
  {
    for (int j = i + 1; j < size_; j++)
    {
      if (matrix_[i][j] != INT32_MAX)
      {
        std::cout << "Edge " << i << "-" << j << " cost:" << matrix_[i][j] << '\n';
      }
    }
  }
}

int find(int i, int* parent)
{
  while (parent[i] != i)
  {
    i = parent[i];
  }
  return i;
}

void unite(int i, int j, int* parent)
{
  int a = find(i, parent);
  int b = find(j, parent);
  parent[a] = b;
}

void Graph::kruskalAlgorithm() const
{
  int* parent = new int[size_];
  for (int i = 0; i < size_; i++)
  {
    parent[i] = i;
  }
  int edge_count = 0;
  int mincost = 0;
  while (edge_count < size_ - 1) {
    int min = INT32_MAX, a = -1, b = -1;
    for (int i = 0; i < size_; i++) {
      for (int j = 0; j < size_; j++) {
        if (find(i, parent) != find(j, parent) && matrix_[i][j] < min) {
          min = matrix_[i][j];
          a = i;
          b = j;
        }
      }
    }
    unite(a, b, parent);
    std::cout << "Edge " << edge_count++ << ": (" << a << ", " << b << ") cost: " << min << '\n';
    mincost += min;
  }
  delete[] parent;
  std::cout << "Minimum cost: " << mincost << '\n';
}

int minKey(int key[], bool mstSet[], int size)
{
  int min = INT32_MAX, min_index;

  for (int i = 0; i < size; i++)
  {
    if (!mstSet[i] && key[i] < min)
    {
      min = key[i], min_index = i;
    }
  }
  return min_index;
}

void Graph::primAlgorithm() const
{
  int parent[size_];
  int key[size_];
  bool mstSet[size_];
  for (int i = 0; i < size_; i++)
  {
    key[i] = INT32_MAX, mstSet[i] = false;
  }
  key[0] = 0;
  parent[0] = -1;
  for (int k = 0; k < size_ - 1; k++)
  {
    int j = minKey(key, mstSet, size_);
    mstSet[j] = true;
    for (int i = 0; i < size_; i++)
    {
      if (!mstSet[i] && matrix_[j][i] < key[i])
      {
        parent[i] = j;
        key[i] = matrix_[j][i];
      }
    }
  }
  int mincost = 0;
  for (int i = 1; i < size_; i++)
  {
    std::cout << "Edge " << i << ": (" << parent[i] << ", " << i << ") cost: " << matrix_[i][parent[i]] << '\n';
    mincost += matrix_[i][parent[i]];
  }
  std::cout << "Minimum cost: " << mincost << '\n';
}
