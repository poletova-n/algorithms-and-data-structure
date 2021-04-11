#ifndef UNDIRECTEDGRAPH_HPP
#define UNDIRECTEDGRAPH_HPP

#include "graph.hpp"
#include "list.hpp"
#include "array.hpp"
#include "exceptionGraph.hpp"

template<class T>
class UndirectedGraph
  : public Graph<T>
{
  private:
  template<typename T1>
  struct Node
  {
    Node *next_;
    T1 item_;
    size_t number_{};
    List<int> ways_;

    Node()
    {
      item_ = 0;
      next_ == nullptr;
    };
  };

  public:
  explicit UndirectedGraph();

  ~UndirectedGraph() = default;
  UndirectedGraph(const UndirectedGraph &src) = delete;

  UndirectedGraph &operator=(const UndirectedGraph<T> &src) = delete;

  UndirectedGraph(UndirectedGraph &&src) = delete;

  UndirectedGraph &operator=(UndirectedGraph<T> &&src) = delete;

  void addNode(const T &newItem) override;
  void addLine(const int &node1, const int &node2) override;

  void deleteLine(const int &node1, const int &node2) override;

  void deleteNode(const T &item) override;
  bool isEmpty() const override;
  bool isIncludeLine(const int &node1, const int &node2) override;

  bool isIncludeNode(const T &node) override;
  void print();
  void DFC() override;

  private:
  Node<T> *first_;
  Array<List<int>> lines_;
  size_t size_;

  Node<T> *searchNode(const int &item);
  Node<T> *searchNodeNumber(const int &index);

  bool freeNode();

};

template<class T>
UndirectedGraph<T>::UndirectedGraph()
{
  size_ = 0;
  first_ = nullptr;
}

template<class T>
void UndirectedGraph<T>::addNode(const T &newItem)
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
    first_->next_ = nullptr;
    List<T> newList;
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
    node->next_ = nullptr;
    List<T> newList;
    lines_.pushBack(newList);
    size_++;
  }
}

template<class T>
bool UndirectedGraph<T>::isEmpty() const
{
  return (size_ == 0);
}

template<class T>
void UndirectedGraph<T>::addLine(const int &node1, const int &node2)
{
  if (isIncludeLine(node1, node2))
  {
    throw GraphWrongLine();
  }
  Node<T> *temp1 = searchNode(node1);
  Node<T> *temp2 = searchNode(node2);
  size_t node1Number = temp1->number_;
  size_t node2Number = temp2->number_;
  lines_[node1Number].insertItem(node2Number);
  lines_[node2Number].insertItem(node1Number);
  temp1->ways_ = lines_[node1Number];
  temp2->ways_ = lines_[node2Number];
}

template<class T>
void UndirectedGraph<T>::deleteLine(const int &node1, const int &node2)
{
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (!isIncludeLine(node1, node2))
  {
    throw GraphWrongLine();
  }
  {
    Node<T> *temp1 = searchNode(node1);
    Node<T> *temp2 = searchNode(node2);
    size_t node1Number = temp1->number_;
    size_t node2Number = temp2->number_;
    lines_[node1Number].deleteItem(node2Number);
    lines_[node2Number].deleteItem(node1Number);
    temp1->ways_ = lines_[node1Number];
    temp2->ways_ = lines_[node2Number];
  }
}

template<class T>
void UndirectedGraph<T>::deleteNode(const T &item)
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
bool UndirectedGraph<T>::isIncludeLine(const int &node1, const int &node2)
{
  if (isEmpty())
  {
    throw GraphEmpty();
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
bool UndirectedGraph<T>::isIncludeNode(const T &node)
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
void UndirectedGraph<T>::print()
{
  if (isEmpty())
  {
    std::cout << "Graph is Empty.";
  } else
  {
    std::cout << "nodes: " << '\n';
    int number = 0;
    while (number != size_)
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
typename UndirectedGraph<T>::template Node<T> *UndirectedGraph<T>::searchNode(const int &item)
{
  Node<T> *temp = first_;
  while (temp != nullptr && temp->item_ != item)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
typename UndirectedGraph<T>::template Node<T> *UndirectedGraph<T>::searchNodeNumber(const int &index)
{
  Node<T> *temp = first_;

  while (temp != nullptr && temp->number_ != index)
  {
    temp = temp->next_;
  }
  return temp;
}

template<class T>
bool UndirectedGraph<T>::freeNode()
{
  for (int i = 0; i < size_; i++)
  {
    if (lines_[i].getSize() == 0)
      return true;
  }
  return false;
}
template<class T>
void UndirectedGraph<T>::DFC()
{
  bool isVisited[size_];
  List<int> tempList;
  if (isEmpty())
  {
    throw GraphEmpty();
  }
  if (freeNode())
  {
    throw GraphFreeNode();
  }
  StackArray<Node<T> *> stack(size_);
  stack.push(first_);
  while (!stack.isEmpty())
  {
    Node<T> *tempNode = stack.pop();
    isVisited[tempNode->number_] = true;
    tempList.insertItem(tempNode->item_);
    List<int> tempWays = tempNode->ways_;
    for (int j = 0; j < size_; j++)
    {
      if (tempWays.searchItem(j) && !isVisited[j])
      {
        stack.push(searchNodeNumber(j));
      }

    }
  }
  for (int i = 0; i < size_; i++)
  {
    if (!isVisited[i])
    {
      throw GraphDFCError();
    }
  }
  tempList.print();
}

#endif
