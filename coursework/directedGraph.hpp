#ifndef DIRECTEDGRAPH_HPP
#define DIRECTEDGRAPH_HPP

#include "graph.hpp"
#include "singlyLinkedOrderedList.hpp"
#include "queueArray.hpp"
#include "array.hpp"
#include "stackArray.hpp"
#include <cstdlib>
#include "exceptionGraph.hpp"

template<class T>
class DirectedGraph
  : public Graph<T>
{
  private:

  template<typename T1>
  struct Node
  {
    Node *next_;
    T1 item_;
    size_t number_{};
    SinglyLinkedOrderedList<int> ways_;

    Node()
    {
      item_ = 0;
      next_ = nullptr;
    };
  };

  public:
  explicit DirectedGraph();

  ~DirectedGraph() = default;

  void addNode(const T &newItem) override;
  void addLine(const int &node1, const int &node2) override;

  void deleteLine(const int &node1, const int &node2) override;

  void deleteNode(const T &item) override;
  bool isEmpty() const override;
  bool isIncludeLine(const int &node1, const int &node2) override;
  bool isIncludeNode(const T &node) override;
  void print();
  void BFC() override;

  void topologicalSort();

  private:
  Node<T> *first_;
  Array<SinglyLinkedOrderedList<int>> lines_;
  size_t size_;

  Node<T> *searchNode(const int &item);
  Node<T> *searchNodeNumber(const int &index);

  Node<T> *searchNodeNoIncomingEdges();

  void topologicalSortUtil(int v, bool *visited, StackArray<Node<T> *> &stack);

  void DFC(Node<T> *node, Array<char> &color);

  bool isCycle();

  bool freeNode();
};

template<class T>
DirectedGraph<T>::DirectedGraph()
{
  size_ = 0;
  first_ = nullptr;
}

template<class T>
void DirectedGraph<T>::addNode(const T &newItem)
{
  if (isIncludeNode(newItem))
  {
    throw GraphWrongNode();
  }
  auto *node = new Node<T>();
  node->item_ = newItem;
  if (isEmpty())
  {
    node->number_ = 0;
    first_ = node;
    SinglyLinkedOrderedList<T> newList;
    lines_.pushBack(newList);
    size_++;
  } else
  {
    Node<T> *temp = first_;
    while (temp->next_ != nullptr)
    {
      temp = temp->next_;
    }
    node->number_ = size_;
    temp->next_ = node;
    SinglyLinkedOrderedList<T> newList;
    lines_.pushBack(newList);
    size_++;
  }
}

template<class T>
bool DirectedGraph<T>::isEmpty() const
{
  return (size_ == 0);
}

template<class T>
void DirectedGraph<T>::deleteLine(const int &node1, const int &node2)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (!isIncludeLine(node1, node2))
  {
    throw GraphWrongLine();
  }
  Node<T> *temp1 = searchNode(node1);
  Node<T> *temp2 = searchNode(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  lines_[node1Number].deleteItem(node2Number);
  temp1->ways_ = lines_[node1Number];
}

template<class T>
void DirectedGraph<T>::deleteNode(const T &item)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (!isIncludeNode(item))
  {
    throw GraphWrongNode();
  } else
  {
    Node<T> *temp = searchNode(item);
    int deleteNodeNumber = temp->number_;
    for (int i = 0; i < size_; i++)
    {
      if (lines_[i].searchItem(temp->number_))
      {
        lines_[i].deleteItem(temp->number_);
        Node<T> *deleteNodeWays = searchNodeNumber(i);
        deleteNodeWays->ways_ = lines_[i];
      }
    }
    size_--;
    lines_.deleteItem(temp->number_);

    if (temp == this->first_)
    {
      first_ = temp->next_;
      temp = temp->next_;
      while (temp != nullptr)
      {
        temp->number_--;
        int numberTemp = temp->number_;
        for (int i = 0; i < size_; i++)
        {
          if (lines_[numberTemp].searchItem(i))
          {
            lines_[numberTemp].deleteItem(i);
            lines_[numberTemp].insertItem(i - 1);
          }
          temp->ways_ = lines_[numberTemp];
        }
        temp = temp->next_;
      }
    } else
    {
      Node<T> *temp2 = first_;
      while (temp2 != nullptr && temp != temp2->next_)
      {
        temp2 = temp2->next_;
      }
      temp2->next_ = temp->next_;
      temp2 = temp2->next_;
      while (temp2 != nullptr)
      {
        temp2->number_--;
        int numberTemp = temp->number_;
        for (int i = deleteNodeNumber; i < size_; i++)
        {
          if (lines_[numberTemp].searchItem(i))
          {
            lines_[numberTemp].deleteItem(i);
            lines_[numberTemp].insertItem(i - 1);
          }
          temp2->ways_ = lines_[numberTemp];
        }
        temp2 = temp2->next_;
      }

    }
    delete temp;
  }

}

template<class T>
bool DirectedGraph<T>::isIncludeNode(const T &node)
{
  if (isEmpty())
  {
    return false;
  } else
  {
    Node<T> *temp = first_;
    while (temp != nullptr)
    {
      if (temp->item_ == node)
        return true;
      temp = temp->next_;
    }
  }
  return false;
}

template<class T>
void DirectedGraph<T>::print()
{
  if (isEmpty())
  {
    std::cout << "Graph is Empty.";
  } else
  {
    std::cout << "nodes: " << '\n';
    int number = 0;
    while (searchNodeNumber(number) != nullptr)
    {
      Node<T> *temp = searchNodeNumber(number);
      std::cout << "number: " << temp->number_ << " item: " << temp->item_ << "\n";
      number++;
    }
    std::cout << "lines: " << '\n';
    lines_.print();
  }

}

template<class T>
typename DirectedGraph<T>::template Node<T> *DirectedGraph<T>::searchNode(const int &item)
{
  Node<T> *temp = first_;
  while (temp != nullptr && temp->item_ != item)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
void DirectedGraph<T>::BFC()
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (freeNode())
  {
    throw GraphFreeNode();
  }
  QueueArray<Node<T> *> tempQueue(size_);
  if (isCycle() || searchNodeNoIncomingEdges() == nullptr)
  {
    tempQueue.enQueue(first_);
  } else
  {
    tempQueue.enQueue(searchNodeNoIncomingEdges());
  }
  Array<bool> isVisit;
  for (int i = 0; i < size_; i++)
  {
    isVisit.pushBack(false);
  }
  isVisit[first_->number_] = true;
  Array<int> nodes;
  while (!tempQueue.isEmpty())
  {
    Node<T> *temp = tempQueue.deQueue();
    nodes.pushBack(temp->item_);
    for (int i = 0; i < lines_[temp->number_].getSize(); i++)
    {
      for (int j = 0; j < size_; j++)
      {
        if (lines_[temp->number_].searchItem(j) && !isVisit[j])
        {
          tempQueue.enQueue(searchNodeNumber(j));
          isVisit[j] = true;
        }
      }
    }
  }
  for(int i=0;i<size_;i++)
  {
    if(!isVisit[i])
    {
      throw GraphBFCError();
    }
  }
  std::cout << "\nBFC\n";
  for(int i=0;i<size_;i++)
  {
    std::cout<<nodes[i]<<" ";
  }
}

template<class T>
typename DirectedGraph<T>::template Node<T> *DirectedGraph<T>::searchNodeNumber(const int &index)
{
  Node<T> *temp = first_;

  while (temp != nullptr && temp->number_ != index)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
void DirectedGraph<T>::topologicalSortUtil(int v, bool *visited, StackArray<Node<T> *> &stack)
{
  visited[v] = true;
  Node<T> *addNode = searchNodeNumber(v);
  if (lines_[v].isEmpty())
  {
    stack.push(addNode);
  } else
  {
    for (int i = 0; i < size_; i++)
    {
      if (!visited[i] && lines_[v].searchItem(i))
      {
        topologicalSortUtil(i, visited, stack);
      }
    }
    stack.push(addNode);
  }
}

template<class T>
void DirectedGraph<T>::topologicalSort()
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (freeNode())
    throw GraphFreeNode();
  StackArray<Node<T> *> stack(size_);
  if (isCycle())
  {
    throw GraphCycle();
  }
  bool visited[size_];
  for (int i = 0; i < size_; i++)
  {
    visited[i] = false;
  }
  Node<T> *firstTopologyNode = searchNodeNoIncomingEdges();
  topologicalSortUtil(firstTopologyNode->number_, visited, stack);

  size_t newNumber = 0;
  std::cout << "\nTopology sort\n";
  while (!stack.isEmpty())
  {
    Node<T> *tempNode = stack.pop();
    tempNode->number_ = newNumber;
    std::cout << tempNode->item_ << " ";
    newNumber++;
  }
  for (int i = 0; i < size_; i++)
  {
    Node<T> *tempNode2 = searchNodeNumber(i);
    lines_[i] = tempNode2->ways_;
  }
  Node<T> *newFirst_ = first_;
  size_t number = 0;
  while (true)
  {
    Node<T> *tempNodeNewNumberingSystem = searchNodeNumber(number);
    if (tempNodeNewNumberingSystem == nullptr)
    {
      break;
    }
    newFirst_ = tempNodeNewNumberingSystem;
    number++;
  }
}

template<class T>
bool DirectedGraph<T>::isIncludeLine(const int &node1, const int &node2)
{
  if (isEmpty())
  {
    return false;
  }

  if (searchNode(node1) == nullptr || searchNode(node2) == nullptr)
  {
    throw GraphWrongLine();
  }
  Node<T> *temp1 = searchNode(node1);
  Node<T> *temp2 = searchNode(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  return (lines_[node1Number].searchItem(node2Number));
}

template<class T>
void DirectedGraph<T>::addLine(const int &node1, const int &node2)
{
  if (isIncludeLine(node1, node2) || isIncludeLine(node2, node1))
  {
    throw GraphWrongLine();
  }
  Node<T> *temp1 = searchNode(node1);
  Node<T> *temp2 = searchNode(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  lines_[node1Number].insertItem(node2Number);
  temp1->ways_ = lines_[node1Number];
}

template<class T>
typename DirectedGraph<T>::template Node<T> *DirectedGraph<T>::searchNodeNoIncomingEdges()
{
  int visits[size_];
  for (int i = 0; i < size_; i++)
  {
    visits[i] = false;
  }
  for (int i = 0; i < size_; i++)
  {
    for (int j = 0; j < size_; j++)
    {
      if (lines_[i].searchItem(j))
      {
        visits[j] = true;
      }
    }
  }
  for (int i = 0; i < size_; i++)
  {
    if (!visits[i])
    {
      return searchNodeNumber(i);
    }
  }
  return nullptr;
}

template<class T>
bool DirectedGraph<T>::freeNode()
{
  StackArray<Node<T> *> stack(size_);
  SinglyLinkedOrderedList<int> list;
  Node<T> *nodeTemp = first_;
  while (nodeTemp != nullptr)
  {
    SinglyLinkedOrderedList<int> tempWays = nodeTemp->ways_;
    bool isLink = false;
    for (int i = 0; i < size_; i++)
    {
      if (tempWays.searchItem(i))
      {
        list.insertItem(i);
        isLink = true;
      }
    }
    if (isLink)
      list.insertItem(nodeTemp->number_);
    nodeTemp = nodeTemp->next_;
  }
  for (int i = 0; i < size_; i++)
  {
    if (!list.searchItem(i))
      return true;

  }
  return false;
}

template<class T>
void DirectedGraph<T>::DFC(DirectedGraph::Node<T> *node, Array<char> &color)
{
  color[node->number_] = 'g';
  SinglyLinkedOrderedList<int> tempWays = node->ways_;
  for (int i = 0; i < size_; i++)
  {
    if (tempWays.searchItem(i))
    {
      if (color[i] == 'g')
      {
        return;
      } else
      {
        DFC(searchNodeNumber(i), color);
      }
    }
  }
  color[node->number_] = 'b';
}

template<class T>
bool DirectedGraph<T>::isCycle()
{
  Array<char> colour;

  for (int i = 0; i < size_; i++)
  {
    colour.pushBack('w');
  }
  Node<T> *tempNode = searchNodeNoIncomingEdges();
  if (tempNode == nullptr)
    return true;
  DFC(tempNode, colour);
  for (int i = 0; i < size_; i++)
  {
    if (colour[i] != 'b')
      return true;
  }
  return false;
}

#endif
