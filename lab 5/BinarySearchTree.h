#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>

#include "QueueArray.hpp"

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree();

  BinarySearchTree(const BinarySearchTree<T> &scr) = delete;

  BinarySearchTree(BinarySearchTree<T> &&scr) noexcept;

  BinarySearchTree<T> &operator=(const BinarySearchTree<T> &src) = delete;

  BinarySearchTree<T> &operator=(BinarySearchTree<T> &&src) noexcept;

  virtual ~BinarySearchTree();

  bool iterativeSearch(const T &key) const;

  bool insert(const T &key);

  bool deleteKey(const T &key);

  void print(std::ostream &out) const;

  int getCount() const;

  int getHeight() const;

  void inorderWalk() const;

  T* iterativeInorderWalk() const;

  void breadthFirstWalk() const;

  bool isSimilarTree(const BinarySearchTree<T> &src);

  bool operator==(const BinarySearchTree<T> &src);

private:
  struct Node
  {
    T key_;
    Node *left_;
    Node *right_;

    explicit Node(T key, Node *left = nullptr, Node *right = nullptr) :
      key_(key), left_(left), right_(right)
    {}
  };

  Node *root_;

  void swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right);

  void deleteSubtree(Node *node);

  void insert(Node *node);

  Node *iterativeSearchNode(const T &key) const;

  void printNode(std::ostream &out, Node *root) const;

  int getCountSubTree(const Node *node) const;

  int getHeightSubTree(Node *node) const;

  void inorderWalk(Node *node) const;
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr)
{}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &&scr) noexcept
{
  swap(this, scr);
  delete scr;
}

template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree<T> &&src) noexcept
{
  swap(this, src);
  delete src;
  return *this;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(Node *node)
{
  if (node != nullptr)
  {
    if (node->right_ != nullptr)
    {
      deleteSubtree(node->right_);
    }
    if (node->left_ != nullptr)
    {
      deleteSubtree(node->left_);
    }
    delete node;
  }
}

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T> &left, BinarySearchTree<T> &right)
{
  Node time = left.root_;
  left.root_ = right.root_;
  right.root_ = time;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  if (root_ == nullptr)
    return root_;
  else
  {
    Node *temp = root_;
    while (true)
    {
      if (key == temp->key_)
      {
        return temp;
      }
      if (key > temp->key_)
      {
        temp = temp->right_;
      }
      else if (key < temp->key_)
      {
        temp = temp->left_;
      }
      if (temp == nullptr)
      {
        return nullptr;
      }
    }
  }
}

template<class T>
bool BinarySearchTree<T>::insert(const T &key)
{
  if (iterativeSearch(key))
  {
    std::cout << "Element with key " << key << " is already present in the tree\n";
    return false;
  }
  auto *tempNode = new Node(key);
  Node *temp = root_;
  if (root_ == nullptr)
  {
    root_ = tempNode;
    return true;
  }
  while (temp != nullptr)
  {
    if (tempNode->key_ > temp->key_)
    {
      if (temp->right_ == nullptr)
      {
        temp->right_ = tempNode;
        return true;
      }
      temp = temp->right_;
    }
    else if (tempNode->key_ < temp->key_)
    {
      if (temp->left_ == nullptr)
      {
        temp->left_ = tempNode;
        return true;
      }
      temp = temp->left_;
    }
  }
}

template<class T>
bool BinarySearchTree<T>::deleteKey(const T &key)
{
  if (!iterativeSearch(key))
  {
    std::cout << "Element with key " << key << " not found in tree\n";
    return false;
  }
  Node *toDelete;
  Node *temp = root_;
  Node *previousTemp = root_;
  if (root_->key_ == key)
  {
    toDelete = root_;
    temp = root_->left_;
    root_ = root_->right_;
    this->insert(temp);
    delete toDelete;
    return true;
  }
  while (true)
  {
    if (temp->key_ == key)
    {
      if ((temp->right_ == nullptr) && (temp->left_ == nullptr))
      {
        if ((previousTemp->left_ != nullptr) && (previousTemp->left_->key_ == temp->key_))
        {
          previousTemp->left_ = nullptr;
          delete temp;
          return true;
        }
        else
        {
          previousTemp->right_ = nullptr;
          delete temp;
          return true;
        }
      }
      else if (temp->right_ == nullptr)
      {
        if (previousTemp->left_->key_ == temp->key_)
        {
          previousTemp->left_ = temp->right_;
          return true;
        }
        else
        {
          previousTemp->right_ = temp->left_;
          return true;
        }
      }
      else if (temp->left_ == nullptr)
      {
        if ((temp->key_ == previousTemp->right_->key_) && (nullptr != previousTemp->right_))
        {
          previousTemp->left_ = temp->right_;
          previousTemp->right_ = nullptr;
          return true;
        }
        else
        {
          previousTemp->right_ = temp->left_;
          previousTemp->left_ = nullptr;
          return true;
        }
      }
      else
      {
        if ((previousTemp->left_ != nullptr) && (previousTemp->left_->key_ == key))
        {
          previousTemp->left_ = temp->right_;
          this->insert(temp->left_);
          return true;
        }
        else if ((previousTemp->right_ != nullptr) && (previousTemp->right_->key_ == key))
        {
          previousTemp->right_ = temp->right_;
          this->insert(temp->left_);
          return true;
        }
      }
    }
    else if (key > temp->key_)
    {
      previousTemp = temp;
      temp = temp->right_;
    }
    else if (key < temp->key_)
    {
      previousTemp = temp;
      temp = temp->left_;
    }
  }
}

template<class T>
void BinarySearchTree<T>::print(std::ostream &out) const
{
  printNode(out, root_);
  out << std::endl;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream &out, Node *root) const
{
  out << '(';
  if (root != nullptr)
  {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}

template<class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(const Node *node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(Node *node) const
{
  int countRight = 0;
  int countLeft = 0;
  if (node != nullptr)
  {
    if (node->right_ != nullptr)
      countRight = getHeightSubTree(node->right_) + 1;
    else
      countRight = 1;
    if (node->left_ != nullptr)
      countLeft = getHeightSubTree(node->left_) + 1;
    else
      countLeft = 1;
  }
  int max = std::max(countLeft, countRight);
  return max;
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
  inorderWalk(root_);
}

template<class T>
void BinarySearchTree<T>::inorderWalk(Node *node) const
{
  if (node != nullptr)
  {
    inorderWalk(node->left_);
    std::cout << node->key_ << " ";
    inorderWalk(node->right_);
  }
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T> &src)
{
  std::stack<Node *> tempStack;
  std::stack<Node *> Stack;
  std::stack<Node *> srcStack;
  Node *thisNode = root_;
  while (true)
  {
    if (thisNode != nullptr)
    {
      tempStack.push(thisNode);
      Stack.push(thisNode);
      thisNode = thisNode->left_;
    }
    else
    {
      if (tempStack.size() == 0)
      {
        break;
      }
      else
      {
        thisNode = tempStack.top();
        tempStack.pop();
        thisNode = thisNode->right_;
      }
    }
  }
  Node *srcNode = src.root_;
  while (true)
  {
    if (srcNode != nullptr)
    {
      tempStack.push(srcNode);
      srcStack.push(srcNode);
      srcNode = srcNode->left_;
    }
    else
    {
      if (tempStack.size() == 0)
      {
        break;
      }
      else
      {
        srcNode = tempStack.top();
        tempStack.pop();
        srcNode = srcNode->right_;
      }
    }
  }
  if (Stack.size() != srcStack.size())
  {
    return false;
  }
  while ((Stack.size()) != 0 && (srcStack.size() != 0))
  {
    Node *Top = Stack.top();
    Node *srcTop = srcStack.top();
    if (Top->key_ != srcTop->key_)
    {
      return false;
    }
    Stack.pop();
    srcStack.pop();
  }
  return true;
}

template<class T>
void BinarySearchTree<T>::insert(BinarySearchTree::Node *node)
{
  int flag = 0;
  Node *temp = root_;
  if (root_ == nullptr)
  {
    root_ = node;
  }
  while ((temp != nullptr) && (flag != 1))
  {
    if (node->key_ > temp->key_)
    {
      if (temp->right_ == nullptr)
      {
        temp->right_ = node;
        flag = 1;
      }
      temp = temp->right_;
    }
    else if (node->key_ < temp->key_)
    {
      if (temp->left_ == nullptr)
      {
        temp->left_ = node;
        flag = 1;
      }
      temp = temp->left_;
    }
  }
}

template<class T>
T* BinarySearchTree<T>::iterativeInorderWalk() const
{
  std::stack<Node *> tempStack;
  T* tempArray = new T[getCount()];
  int i = 0;
  Node *tempItem = root_;
  if (root_ == nullptr)
  {
    std::cout << "Tree is empty\n";
  }
  else
  {
    tempStack.push(tempItem);
    while (!tempStack.empty())
    {
      tempItem = tempStack.top();
      tempStack.pop();
      while (tempItem != nullptr)
      {
        tempStack.push(tempItem);
        tempItem = tempItem->left_;
      }
      if (!tempStack.empty())
      {
        tempItem = tempStack.top();
        tempStack.pop();
        tempArray[i] = tempItem->key_;
        i++;
        std::cout << tempItem->key_ << " ";
        tempStack.push(tempItem->right_);
      }
    }
    std::cout << "\n";
    return tempArray;
  }
}

template<class T>
void BinarySearchTree<T>::breadthFirstWalk() const
{
  QueueArray<Node *> tempQueue(getCount());
  Node *temp = root_;
  if (root_ == nullptr)
  {
    std::cout << "Tree is empty\n";
  }
  else
  {
    tempQueue.enQueue(temp);
    while (!tempQueue.isEmpty())
    {
      temp = tempQueue.deQueue();
      std::cout << temp->key_ << " ";
      if (temp->left_!= nullptr)
      {
        tempQueue.enQueue(temp->left_);
      }
      if (temp->right_!= nullptr)
      {
        tempQueue.enQueue(temp->right_);
      }
    }
    std::cout << "\n";
  }
}

template<class T>
bool BinarySearchTree<T>::isSimilarTree(const BinarySearchTree<T> &src)
{
  if (getCount()!=src.getCount())
  {
    return false;
  }
  T* firstTree = iterativeInorderWalk();
  T* secondTree = src.iterativeInorderWalk();
  for (int i=0; i<getCount(); i++)
  {
    if (firstTree[i]!=secondTree[i])
    {
      return false;
    }
  }
  return true;
}
#endif
