#ifndef COURSEWORK_UNDIRECTEDGRAPH_HPP
#define COURSEWORK_UNDIRECTEDGRAPH_HPP

#include <vector>
#include "graph.hpp"
#include "doubleLinkedList.hpp"
#include "exceptions.hpp"
#include "stackArray.hpp"

template<class T>
class UndirectedGraph : public Graph<T>
{
public:
  UndirectedGraph() :
    head_(nullptr), size_(0)
  {}

  void insertNode(T value) override;

  void insertEdge(T node1, T node2) override;

  void deleteNode(T value) override;

  void deleteEdge(T node1, T node2) override;

  void print() override;

  bool includeNode(T value) override;

  bool includeEdge(T node1, T node2) override;

  void DFS() override;

  bool isEmpty() override;

private:
  struct Node
  {
    T value_;
    Node *next_;
    size_t number_;
    DoubleLinkedList edges_;

    Node() :
      value_(0),
      next_(nullptr)
    {}

    Node(T value, Node *next, size_t number) :
      value_(value), next_(next), number_(number)
    {}
  };

  Node *head_;
  size_t size_;
  std::vector<DoubleLinkedList> allEdges_;

  Node *searchNodeByValue(T value);
  Node *searchNodeByIndex(int index);
  void subDFS (bool *used, UndirectedGraph::Node *node);
};

template<class T>
void UndirectedGraph<T>::insertNode(T value)
{
  if (isEmpty())
  {
    head_ = new Node(value, nullptr, size_);
  }
  else
  {
    Node *current = head_;
    Node *temp = new Node(value, nullptr, size_);
    while (current->next_ != nullptr)
    {
      if (current->value_ == value)
      {
        throw std::invalid_argument("Current number already exists in the graph");
      }
      current = current->next_;
    }
    current->next_ = temp;
  }
  DoubleLinkedList newList;
  allEdges_.push_back(newList);
  size_++;
}

template<class T>
void UndirectedGraph<T>::insertEdge(T node1, T node2)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  Node *temp1 = searchNodeByValue(node1);
  Node *temp2 = searchNodeByValue(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  allEdges_[node1Number].insertTail(node2Number);
  allEdges_[node2Number].insertTail(node1Number);
}

template<class T>
void UndirectedGraph<T>::deleteNode(T value)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  Node *current = head_;
  Node *prev = head_;
  while (current && current->value_ != value)
  {
    prev = current;
    current = current->next_;
  }
  if (current)
  {
    prev->next_ = current->next_;
    Node *temp = head_;
    allEdges_.erase(allEdges_.begin() + current->number_);
    while (temp)
    {
      if (allEdges_[temp->number_].searchItem(current->number_))
      {
        allEdges_[temp->number_].deleteItem(current->number_);
      }
      if (temp->number_ > current->number_)
      {
        temp->number_--;
      }
      temp = temp->next_;
    }
    size_--;
    delete current;
  }
}

template<class T>
void UndirectedGraph<T>::deleteEdge(T node1, T node2)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (!includeEdge(node1, node2))
  {
    throw std::invalid_argument("Current number already exists in the graph");
  }
  Node *temp1 = searchNodeByValue(node1);
  Node *temp2 = searchNodeByValue(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  allEdges_[node1Number].deleteItem(node2Number);
}

template<class T>
void UndirectedGraph<T>::print()
{
  if (isEmpty())
  {
    std::cout << "Graph is empty.";
  }
  else
  {
    std::cout << "Nodes: " << '\n';
    int number = 0;
    while (number != size_)
    {
      Node *temp = searchNodeByIndex(number);
      std::cout << "number: " << temp->number_ << " item: " << temp->value_ << "\n";
      number++;
    }
    std::cout << "All edges: " << '\n';
    for (int i = 0; i < allEdges_.size(); i++)
    {
      if (!(allEdges_[i].isEmpty()))
      {
        std::cout << "Node with index " << i << " connected with nodes: " << allEdges_[i];;
      }
      else
      {
        std::cout << "Node with index " << i << " connected with no nodes.\n";
      }
    }
    std::cout << "\n";
  }
}

template<class T>
void UndirectedGraph<T>::DFS()
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  bool *used = new bool[size_];
  for (int i = 0; i < size_; i++)
  {
    used[i] = false;
  }
  subDFS(used, head_);
  for (int i = 0; i < size_; i++)
  {
    if (!used[i])
    {
      throw GraphDFCError();
    }
  }
  std::cout << "\nDFC complete\n";
}

template<class T>
void UndirectedGraph<T>::subDFS(bool *used, UndirectedGraph::Node *node)
{
  std::cout << node->value_ << " ";
  used[node->number_] = true;
  DoubleLinkedList nodeWays = allEdges_[node->number_];
  for (int i = 0; i < size_; i++)
  {
    if (nodeWays.searchItem(i) && !used[i])
    {
      subDFS(used, searchNodeByIndex(i));
    }
  }
}

template<class T>
typename UndirectedGraph<T>::Node *UndirectedGraph<T>::searchNodeByValue(T value)
{
  Node *temp = head_;
  while (temp != nullptr && temp->value_ != value)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
typename UndirectedGraph<T>::Node *UndirectedGraph<T>::searchNodeByIndex(int index)
{
  Node *temp = head_;
  while (temp != nullptr && temp->number_ != index)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
bool UndirectedGraph<T>::includeNode(T value)
{
  Node *current = head_;
  while (current->next_ != nullptr)
  {
    if (current->value_ == value)
    {
      return true;
    }
  }
  return false;
}

template<class T>
bool UndirectedGraph<T>::includeEdge(T node1, T node2)
{
  return allEdges_[node1].searchItem(node2) || allEdges_[node2].searchItem(node1);
}

template<class T>
bool UndirectedGraph<T>::isEmpty()
{
  return size_ == 0;
}

#endif
