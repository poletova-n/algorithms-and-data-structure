#ifndef UNDIRECTEDGRAPH_HPP
#define UNDIRECTEDGRAPH_HPP

#define _CRT_SECURE_NO_WARNINGS
//#define SIZE 6
//#include <stdio.h>
//#include <stdlib.h>

#include <iostream>
#include <vector>
#include "graph.hpp"
#include "list.hpp"
#include "queueArray.hpp"
#include "exceptionsGraph.hpp"

template<class T>
class UndirectedGraph : public Graph<T>
{
public:
  UndirectedGraph();
  UndirectedGraph(const UndirectedGraph& src) = delete;
  UndirectedGraph(UndirectedGraph&& src) = delete;
  ~UndirectedGraph() = default;
  UndirectedGraph& operator=(const UndirectedGraph<T>& src) = delete;
  UndirectedGraph& operator=(UndirectedGraph<T>&& src) = delete;

  void BFS() override;

  bool isEmptyGraph() const override;
  bool isVertexIncluded(const size_t& vertex) override;
  bool isEdgeIncluded(const T& vertex1, const T& vertex2) override;

  void addVertex(const T& newData) override;
  void addWeightEdge(int number1, int number2, int weight = 0) override;

  void deleteVertex(T data) override;
  int deleteWeightEdge(const int& number1, const int& number2) override;

  void print();

private:
  struct Vertex
  {
    Vertex* next_;
    int numberOfThisVertex_;
    T key_;
    DoubleLinkedList<int> contacts;

    Vertex(Vertex* next, size_t numberOfThisVertex, T key) :
      next_(next), numberOfThisVertex_(numberOfThisVertex), key_(key)
    {}
  };

  int size_;
  Vertex* first_;
  std::vector<DoubleLinkedList<int>> vertices;
  Vertex* searchVertexByNumber(const T& vertex);
};

template<class T>
UndirectedGraph<T>::UndirectedGraph()
{
  size_ = 0;
  first_ = nullptr;
}

template<class T>
void UndirectedGraph<T>::BFS()
{
  if (isEmptyGraph()) {
    throw EmptyGraph();
  }
  std::vector<bool> isUsed(size_);
  QueueArray<Vertex*> queue(size_);
  DoubleLinkedList<int> tempList;
  queue.enQueue(first_);
  while (!queue.isEmpty()) {
    Vertex* tempNode = queue.deQueue();
    isUsed[tempNode->numberOfThisVertex_] = true;
    tempList.insertItem(tempNode->key_);
    DoubleLinkedList<int> tempWays = tempNode->contacts;
    for (int j = 0; j < size_; j++) {
      if (tempWays.searchItem(j) && !isUsed[j]) {
        queue.enQueue(searchVertexByNumber(j));
      }
    }
  }
  for (int i = 0; i < size_; i++) {
    if (!isUsed[i]) {
      throw GraphBFSError();
    }
  }
  std::cout << "Right BFS - ";
  tempList.outAll();
}

template<class T>
bool UndirectedGraph<T>::isEmptyGraph() const
{
  return (size_ == 0);
}

template<class T>
bool UndirectedGraph<T>::isVertexIncluded(const size_t& vertex)
{
  if ((isEmptyGraph()) || (searchVertexByNumber(vertex) == nullptr))
  {
    return false;
  }
  return true;
}

template<class T>
bool UndirectedGraph<T>::isEdgeIncluded(const T& vertex1, const T& vertex2)
{
  if ((isEmptyGraph()) || (searchVertexByNumber(vertex1) == nullptr || searchVertexByNumber(vertex2) == nullptr))
  {
    return false;
  }
  size_t numberOfVertex1 = searchVertexByNumber(vertex1)->numberOfThisVertex_;
  size_t numberOfVertex2 = searchVertexByNumber(vertex2)->numberOfThisVertex_;
  return ((vertices[numberOfVertex1].searchItem(numberOfVertex2)) || (vertices[numberOfVertex2].searchItem(numberOfVertex1)));
}

template<class T>
void UndirectedGraph<T>::addVertex(const T& newData)
{
  if (isEmptyGraph())
  {
    first_ = new Vertex(nullptr, 0, newData);
    vertices.push_back(first_->contacts);
  }
  else
  {
    Vertex* current = first_;
    Vertex* temp = new Vertex(nullptr, size_, newData);
    while (current->next_ != nullptr)
    {
      current = current->next_;
    }
    current->next_ = temp;
    vertices.push_back(current->contacts);
  }
  size_++;
}

template<class T>
void UndirectedGraph<T>::addWeightEdge(int number1, int number2, int weight)
{
  if (isEmptyGraph())
  {
    throw EmptyGraph();
  }
  Vertex* temp = first_;
  Vertex* one = nullptr;
  Vertex* two = nullptr;
  while (temp != nullptr)
  {
    if (temp->numberOfThisVertex_ == number1)
    {
      one = temp;
    }
    if (temp->numberOfThisVertex_ == number2)
    {
      two = temp;
    }
    temp = temp->next_;
  }

  if ((one != nullptr) && (two != nullptr))
  {
    one->contacts.insertTail(two->numberOfThisVertex_, weight);
    two->contacts.insertTail(one->numberOfThisVertex_, weight);
    while (!vertices[number1].isEmpty()) {
      vertices[number1].deleteTail();
    }
    while (!vertices[number2].isEmpty()) {
      vertices[number2].deleteTail();
    }
    vertices[number1] = one->contacts;
    vertices[number2] = two->contacts;
  }
  else
  {
    throw WrongVertexGraph();
  }
}

template<class T>
void UndirectedGraph<T>::deleteVertex(T data)
{
  if (isEmptyGraph())
  {
    throw EmptyGraph();
  }
  if (!isVertexIncluded(data))
  {
    throw WrongVertexGraph();
  }
  else
  {
    Vertex* current = first_;
    Vertex* prev = current;
    while (current != nullptr)
    {
      if (current->key_ == data)
      {
        break;
      }
      prev = current;
      current = current->next_;
    }
    if (current == nullptr)
    {
      return;
    }
    else
    {
      int deletingVertexNumber = current->numberOfThisVertex_;
      for (int i = 0; i < size_; i++) {
        if (vertices[i].searchItem(current->numberOfThisVertex_))
        {
          vertices[i].deleteItem(current->numberOfThisVertex_);
          Vertex* renewFreedVertex = searchVertexByNumber(i);
          while (!renewFreedVertex->contacts.isEmpty())
          {
            renewFreedVertex->contacts.deleteTail();
          }
          renewFreedVertex->contacts = vertices[i];
        }
      }
      size_--;
      vertices.erase(vertices.begin() + current->numberOfThisVertex_);
      if (current == first_)
      {
        first_ = current->next_;
        current = current->next_;
        while (current != nullptr)
        {
          current->numberOfThisVertex_--;
          current = current->next_;
        }
        for (int i = 0; i < size_; ++i)
        {
          auto temp = vertices[i].head();
          while (temp != nullptr)
          {
            if (temp->item_ > deletingVertexNumber)
            {
              temp->item_--;
            }
            temp = temp->next_;
          }
        }
      }
      else
      {
        Vertex* temp2 = first_;
        while (temp2 != nullptr && current != temp2->next_) {
          temp2 = temp2->next_;
        }
        temp2->next_ = current->next_;
        temp2 = temp2->next_;
        while (temp2 != nullptr) {
          temp2->numberOfThisVertex_--;
          temp2 = temp2->next_;
        }
        for (int i = 0; i < size_; ++i)
        {
          auto temp = vertices[i].head();
          while (temp != nullptr) {
            if (temp->item_ > deletingVertexNumber) {
              temp->item_--;
            }
            temp = temp->next_;
          }
        }
      }
      delete current;
    }
  }
}

template<class T>
int UndirectedGraph<T>::deleteWeightEdge(const int& number1, const int& number2)
{
  if (isEmptyGraph())
  {
    throw EmptyGraph();
  }

  Vertex* temp = first_;
  Vertex* one = nullptr;
  Vertex* two = nullptr;
  while (temp != nullptr)
  {
    if (temp->numberOfThisVertex_ == number1)
    {
      one = temp;
    }
    if (temp->numberOfThisVertex_ == number2)
    {
      two = temp;
    }
    temp = temp->next_;
  }
  if ((one != nullptr) && (two != nullptr) && (one->contacts.searchItem(number2)) && (two->contacts.searchItem(number1)))
  {
    int weight = one->contacts.searchNode(number2)->weight_;

    vertices[one->numberOfThisVertex_].deleteItem(number2);
    while (!one->contacts.isEmpty()) {
      one->contacts.deleteTail();
    }
    one->contacts = vertices[one->numberOfThisVertex_];

    vertices[two->numberOfThisVertex_].deleteItem(number1);
    while (!two->contacts.isEmpty()) {
      two->contacts.deleteTail();
    }
    two->contacts = vertices[two->numberOfThisVertex_];

    std::cout << "Returned weight of this path - ";
    return weight;
  }
  else {
    throw WrongEdgeGraph();
  }
}

template<class T>
void UndirectedGraph<T>::print()
{
  if (isEmptyGraph())
  {
    std::cerr << "Graph is empty";
  }
  else
  {
    std::cout << "Vertexes: \n";
    for (int number = 0; number != size_; ++number)
    {
      Vertex* temp = searchVertexByNumber(number);
      std::cout << "Number: " << temp->numberOfThisVertex_ << ", included data: " << temp->key_ << "\n";
    }
    std::cout << "Edges: \n";
    for (int i = 0; i != vertices.size(); ++i)
    {
      if (!vertices[i].isEmpty())
      {
        std::cout << "Vertex with number " << i << " connected with Vertexes number: ";
        vertices[i].outAll();
      }
      else
      {
        std::cout << "Node with number " << i << " connected with no Vertexes\n";
      }
    }
  }
}

template<class T>
typename UndirectedGraph<T>::Vertex* UndirectedGraph<T>::searchVertexByNumber(const T& vertex)
{
  Vertex* current = first_;
  while (current != nullptr)
  {
    if (current->numberOfThisVertex_ == vertex)
    {
      return current;
    }
    current = current->next_;
  }
  return nullptr;
}

#endif
