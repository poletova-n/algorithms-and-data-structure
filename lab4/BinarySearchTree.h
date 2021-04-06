#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include<stdexcept>

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void addIterative(T data);
  void addRecursive(T data);
  int getheight();
  void printInfo(int number, std::ostream& output);
  int countNodes();
  void deleteNode(T data);
private:
  struct Node
  {
    Node(T data, int number, Node* p = nullptr, Node* left = nullptr, Node* right = nullptr) :
      key_(data),
      left_(left),
      right_(right),
      number_(number),
      p_(p)
    {}
    T key_;
    Node* left_;
    Node* right_;
    Node* p_;
    int number_;
  };
  Node* root_;
  int currentNumber;
  void addRecursive(T data, Node* ptr);
  void deleteTree(Node* ptr);
  void search(T data, Node*& ptr);
  void countNodes(int& count, Node* ptr);
  void searchNext(T data, Node*& ptr);
  int getHeight(Node*& ptr);
  void fixNumbers(Node* ptr);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() :
  root_(nullptr),
  currentNumber(0)
{}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  if (root_ != nullptr)
  {
    deleteTree(root_);
    root_ = nullptr;
    currentNumber = 0;
  }
}

template<class T>
void BinarySearchTree<T>::addIterative(T data)
{
  currentNumber += 1;
  if (root_ == nullptr)
  {
    root_ = new Node(data, currentNumber);
  }
  else
  {
    Node* temp = root_;
    while ((temp->left_ != nullptr && temp->key_ > data) || (temp->right_ != nullptr && temp->key_ <= data))
    {
      if (temp->left_ != nullptr && temp->key_ > data)
      {
        temp = temp->left_;
      }
      else if (temp->right_ != nullptr && temp->key_ <= data)
      {
        temp = temp->right_;
      }
    }
    if (temp->key_ > data)
    {
      temp->left_ = new Node(data, currentNumber, temp);
    }
    else
    {
      temp->right_ = new Node(data, currentNumber, temp);
    }
  }
}

template<class T>
void BinarySearchTree<T>::addRecursive(T data)
{
  currentNumber += 1;
  if (root_ == nullptr)
  {
    root_ = new Node(data, currentNumber);
  }
  else
  {
    addRecursive(data, root_);
  }
}

template<class T>
void BinarySearchTree<T>::addRecursive(T data, Node* ptr)
{
  if (ptr->left_ != nullptr && ptr->key_ > data)
  {
    addRecursive(data, ptr->left_);
  }
  else if (ptr->right_ != nullptr && ptr->key_ <= data)
  {
    addRecursive(data, ptr->right_);
  }
  if (ptr->left_ == nullptr && ptr->key_ > data)
  {
    ptr->left_ = new Node(data, currentNumber, ptr);
  }
  else if (ptr->right_ == nullptr && ptr->key_ <= data)
  {
    ptr->right_ = new Node(data, currentNumber, ptr);
  }
}

template<class T>
int BinarySearchTree<T>::getheight()
{
  if (root_ == nullptr)
  {
    throw std::logic_error("getHeight: tree is empty");
  }
  return getHeight(root_);
}

template<class T>
int BinarySearchTree<T>::getHeight(Node*& ptr)
{
  int countLeft = 0;
  int countRight = 0;
  if (ptr->left_ != nullptr)
  {
    countLeft = getHeight(ptr->left_);
  }
  if (ptr->right_ != nullptr)
  {
    countRight = getHeight(ptr->right_);
  }

  if (countLeft > countRight)
  {
    return countLeft + 1;
  }
  else
  {
    return countRight + 1;
  }
}

template<class T>
void BinarySearchTree<T>::printInfo(int number, std::ostream& output)
{
  if (root_ == nullptr)
  {
    throw std::logic_error("printInfo: tree is empty");
  }
  if (number <= 0)
  {
    throw std::invalid_argument("printInfo: number less than 0");
  }
  if (number > currentNumber)
  {
    throw std::logic_error("printInfo: number out of range");
  }
  Node* temp = root_;
  while (temp->left_ != nullptr)
  {
    temp = temp->left_;
  }
  while (number != temp->number_)
  {
    searchNext(temp->key_, temp);
  }
  output << "Number: " << temp->number_ << ", key: " << temp->key_;
}

template<class T>
int BinarySearchTree<T>::countNodes()
{
  if (root_ == nullptr)
  {
    throw std::logic_error("countNodes: tree is empty");
  }
  int count = 0;
  countNodes(count, root_);
  return count;
}

template<class T>
void BinarySearchTree<T>::countNodes(int& count, Node* ptr)
{
  count += 1;
  if (ptr->left_ != nullptr)
  {
    countNodes(count, ptr->left_);
  }
  if (ptr->right_ != nullptr)
  {
    countNodes(count, ptr->right_);
  }
}

template<class T>
void BinarySearchTree<T>::deleteNode(T data)
{
  Node* temp = nullptr;
  search(data, temp);
  currentNumber -= 1;
  if (temp->left_ == nullptr && temp->right_ == nullptr)
  {
    if (temp == root_)
    {
      delete root_;
      root_ = nullptr;
    }
    else
    {
      if (temp->p_->left_ == temp)
      {
        temp->p_->left_ = nullptr;
        fixNumbers(temp);
        delete temp;
      }
      else if (temp->p_->right_ == temp)
      {
        temp->p_->right_ = nullptr;
        fixNumbers(temp);
        delete temp;
      }
    }
  }
  else if (temp->left_ != nullptr && temp->right_ == nullptr)
  {
    if (temp == root_)
    {
      root_ = temp->left_;
      temp->left_->p_ = nullptr;
      fixNumbers(temp);
      delete temp;
    }
    else if (temp->p_->left_ == temp)
    {
      temp->p_->left_ = temp->left_;
      temp->left_->p_ = temp->p_;
      fixNumbers(temp);
      delete temp;
    }
    else if (temp->p_->right_ == temp)
    {
      temp->p_->right_ = temp->left_;
      temp->left_->p_ = temp->p_;
      fixNumbers(temp);
      delete temp;
    }
  }
  else if (temp->left_ == nullptr && temp->right_ != nullptr)
  {
    if (temp == root_)
    {
      root_ = temp->right_;
      temp->right_->p_ = nullptr;
      fixNumbers(temp);
      delete temp;
    }
    else if (temp->p_->left_ == temp)
    {
      temp->p_->left_ = temp->right_;
      temp->right_->p_ = temp->p_;
      fixNumbers(temp);
      delete temp;
    }
    else if (temp->p_->right_ == temp)
    {
      temp->p_->right_ = temp->right_;
      temp->right_->p_ = temp->p_;
      fixNumbers(temp);
      delete temp;
    }
  }
  else if (temp->left_ != nullptr && temp->right_ != nullptr)
  {
    Node* current = temp;
    temp = temp->left_;
    while (temp->right_ != nullptr)
    {
      temp = temp->right_;
    }
    current->key_ = temp->key_;
    if (temp->p_->left_ == temp)
    {
      if (temp->left_ != nullptr)
      {
        temp->p_->left_ = temp->left_;
        temp->left_->p_ = current;
      }
      else
      {
        temp->p_->left_ = nullptr;
      }
      fixNumbers(temp);
      delete temp;
    }
    else if (temp->p_->right_ == temp)
    {
      temp->p_->right_ = nullptr;
      fixNumbers(temp);
      delete temp;
    }
  }
}

template<class T>
void BinarySearchTree<T>::deleteTree(Node* ptr)
{
  if (ptr->left_ != nullptr)
  {
    deleteTree(ptr->left_);
  }
  if (ptr->right_ != nullptr)
  {
    deleteTree(ptr->right_);
  }
  delete ptr;
}

template<class T>
void BinarySearchTree<T>::search(T data, Node*& ptr)
{
  if (root_ == nullptr)
  {
    throw std::logic_error("search: Tree is empty");
  }
  Node* temp = root_;
  while (true)
  {
    if (temp->key_ == data)
    {
      ptr = temp;
      return;
    }
    if (data <= temp->key_ && temp->left_ != nullptr)
    {
      temp = temp->left_;
    }
    else if (data >= temp->key_ && temp->right_ != nullptr)
    {
      temp = temp->right_;
    }
    else
    {
      throw std::logic_error("search: element not found");
    }
  }
}

template<class T>
void BinarySearchTree<T>::searchNext(T data, Node*& ptr)
{
  Node* temp = nullptr;
  search(data, temp);
  if (temp->p_ == nullptr)  //if element is root
  {
    if (temp->right_ != nullptr)
    {
      temp = temp->right_;
      while (temp->left_ != nullptr)
      {
        temp = temp->left_;
      }
      ptr = temp;
    }
    else
    {
      ptr = temp;
    }
  }
  else  //if element not root
  {
    if (temp->p_->left_ != nullptr && temp->p_->left_ == temp)  //if element is left
    {
      if (temp->right_ != nullptr)
      {
        temp = temp->right_;
        while (temp->left_ != nullptr)
        {
          temp = temp->left_;
        }
        ptr = temp;
      }
      else
      {
        ptr = temp->p_;
      }
    }
    else if (temp->p_->right_ != nullptr && temp->p_->right_ == temp)  //if element is right
    {
      if (temp->right_ != nullptr)
      {
        temp = temp->right_;
        while (temp->left_ != nullptr)
        {
          temp = temp->left_;
        }
        ptr = temp;
      }
      else
      {
        ptr = temp;
        while (true)
        {
          temp = temp->p_;
          if (ptr->key_ < temp->key_)
          {
            ptr = temp;
            return;
          }
          if (temp->p_ == nullptr)
          {
            return;
          }
        }
      }
    }
  }
}

template<class T>
void BinarySearchTree<T>::fixNumbers(Node* ptr)
{
  for (int i = ptr->number_ + 1; i <= currentNumber + 1; i++)
  {
    Node* temp = root_;
    while (temp->left_ != nullptr)
    {
      temp = temp->left_;
    }
    while (i != temp->number_)
    {
      searchNext(temp->key_, temp);
    }
    temp->number_ -= 1;
  }
}

#endif