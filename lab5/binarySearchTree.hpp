#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

#include "stackArray.hpp"
#include "queueArray.hpp"

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree<T>& src) = delete;
  BinarySearchTree(BinarySearchTree<T>&& src);
  BinarySearchTree<T>& operator= (const BinarySearchTree<T>& src) = delete;
  BinarySearchTree<T>& operator= (BinarySearchTree<T>&& src);

  ~BinarySearchTree();

  bool deleteKey(const T& key);
  bool iterativeSearch(const T& key) const;
  void print(std::ostream& out) const;
  size_t getCount() const;
  int getHeight() const;
  void iterativeInfixWalkByStack() const;
  void iterativeWidthWalkByQueue() const;
  void inorderWalk() const;
  bool insert(const T& key);
  bool isSimilar(const BinarySearchTree<T>& other);

private:
  template<class T>
  struct Node
  {
    T key_;
    Node<T>* left_;
    Node<T>* right_;
    Node<T>* par_;

    Node(T key, Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr) :
      key_(key),
      left_(l),
      right_(r),
      par_(p)
    {}
  };

  Node<T>* root_;

  void swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right);
  void deleteSubtree(Node<T>* node);
  Node<T>* iterativeSearchNode(const T& key) const;
  void printNode(std::ostream& out, Node<T>* root) const;
  size_t getCountSubTree(const Node<T>* root) const;
  int getHeightSubTree(Node<T>* node) const;
  void recursiveInorderWalk(Node<T>* node) const;
  bool equalNode(const Node<T>* node1, const Node<T>* node2);
};


template<class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) : root_(src.root_)
{
  src.root_ = nullptr;

  std::cout << "Move Constructor\n";
}

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree<T>&& src)
{
  if (src == *this)
    return *this;

  root_ = src.root_;
  src.root_ = nullptr;

  std::cout << "Move assignment\n";
  return *this;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
  root_ = nullptr;
  delete root_;
}

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right)
{
  Node<T>* temp = right.root_;
  right.root_ = left.root_;
  left.root_ = temp;
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(Node<T>* node)
{
  if (node != nullptr)
  {
    if (node->left_ != nullptr)
      deleteSubtree(node->left_);
    if (node->right_ != nullptr)
      deleteSubtree(node->right_);
    delete node;
  }
}

template<class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  Node<T>* x = root_;
  while (x != nullptr && x->key_ != key)
  {
    if (key < x->key_)
      x = x->left_;
    else
      x = x->right_;
  }
  return x;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
{
  out << " (";
  if (root != nullptr) {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ") ";
}

template<class T>
size_t BinarySearchTree<T>::getCountSubTree(const Node<T>* node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
{
  int r, l, height = 0;
  if (node == nullptr)
    return 0;
  else if (node != nullptr)
  {
    r = node->right_ ? getHeightSubTree(node->right_) + 1 : 0;
    l = node->left_ ? getHeightSubTree(node->left_) + 1 : 0;
    height = (r > l ? r : l);
  }
  return height;
}

template<class T>
void BinarySearchTree<T>::recursiveInorderWalk(Node<T>* node) const
{
  if (node != nullptr)
  {
    inorderWalk(node->left_);
    std::cout << " (" << node->key_ << ") ";
    inorderWalk(node->right_);
  }
}


template<class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
  if (root_ == nullptr)
  {
    std::cout << "Error: you tried delete from empty\n";
    return false;
  }

  if (iterativeSearch(key))
  {
    Node<T>* removable = iterativeSearchNode(key);

    if (removable->left_ == nullptr && removable->right_ == nullptr)
    {
      if (removable->par_->left_ == removable)
      {
        removable->par_->left_ = nullptr;
        std::cout << "Delete key-left successor with no successors: ";
        delete removable;
        return true;
      }
      else if (removable->par_->right_ == removable)
      {
        removable->par_->right_ = nullptr;
        std::cout << "Delete key-right successor with no successors: ";
        delete removable; 
        return true;
      }
    }


    if (removable->left_ != nullptr && removable->right_ != nullptr)
    {
      Node<T>* temp = removable->right_;
      Node<T>* currtemp = nullptr;
      if (temp->left_ == nullptr)
        currtemp = temp;
      else
      {
        while (temp != nullptr)
        {
          currtemp = temp;
          temp = temp->left_;
        }
      }

      if (removable->par_->left_ == removable)
      {
        currtemp->par_->right_ = nullptr;
        currtemp->par_ = nullptr;

        removable->par_->left_ = currtemp;
        currtemp->par_ = removable->par_;
        removable->par_ = nullptr;

        removable->left_->par_ = currtemp;
        currtemp->left_ = removable->left_;
        removable->left_ = nullptr;

        if (removable->right_ != nullptr)
        {
          currtemp->right_ = removable->right_;
          removable->right_->par_ = currtemp;
          removable->right_ = nullptr;
        }
        std::cout << "Delete key-left successor with both successors: ";
        delete removable;
        return true;
      }
      else if (removable->par_->right_ == removable) 
      {
        currtemp->par_->left_ = nullptr; 
        currtemp->par_ = nullptr;

        removable->par_->right_ = currtemp; 
        currtemp->par_ = removable->par_;
        removable->par_ = nullptr;

        removable->left_->par_ = currtemp;
        currtemp->left_ = removable->left_;
        removable->left_ = nullptr;

        if (removable->right_ != nullptr)
        {
          currtemp->right_ = removable->right_;
          removable->right_->par_ = currtemp;
          removable->right_ = nullptr;
        }
        std::cout << "Delete key-right successor with both successors: ";
        delete removable; 
        return true;
      }
    }


    if (removable->left_ != nullptr || removable->right_ != nullptr) 
    {
      if (removable->left_ != nullptr)
      {
        if (removable->par_->left_ == removable)
        {
          removable->par_->left_ = removable->left_;
          std::cout << "Delete key-left successor with one left successor: ";
          delete removable;
          return true;
        }
        else if (removable->par_->right_ == removable) 
        {
          removable->par_->right_ = removable->left_;
          std::cout << "Delete key-right successor with one left successor: ";
          delete removable;
          return true;
        }
      }

      else if (removable->right_ != nullptr)
      {
        if (removable->par_->left_ == removable)
        {
          removable->par_->left_ = removable->right_;
          std::cout << "Delete key-left successor with one right successor: ";
          delete removable;
          return true;
        }
        else if (removable->par_->right_ == removable)
        {
          removable->par_->right_ = removable->right_;
          std::cout << "Delete key-right successor with one right successor: ";
          delete removable;
          return true;
        }
      }
    }

  }
  else
  {
    std::cout << "Element cannot delete, because this key not found!: ";
    return false;
  }
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printNode(out, root_);
  out << std::endl;
}

template<class T>
size_t BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template<class T>
void BinarySearchTree<T>::iterativeInfixWalkByStack() const
{
  Node<T>* x = root_;
  StackArray<Node<T>*> stack;
  while (x != nullptr || !stack.isEmpty())
  {
    while (x != nullptr)
    {
      stack.push(x);
      x = x->left_;
    }
    while (!stack.isEmpty())
    {
      x = stack.peek();
      stack.pop();
      std::cout << " (" << x->key_ << ") ";
      x = x->right_;
    }
  }
  std::cout << std::endl;
}

template<typename T>
void BinarySearchTree<T>::iterativeWidthWalkByQueue() const
{
  Node<T>* x = root_;
  size_t tempSize = getCount();
  QueueArray<Node<T>*> queue(tempSize);
  if (x != nullptr)
  {
    queue.enQueue(x);
  }
  while (!queue.isEmpty())
  {
    Node<T>* temp = queue.deQueue();
    std::cout << " (" << temp->key_ << ") ";
    if (temp->left_)
    {
      queue.enQueue(temp->left_);
    }
    if (temp->right_)
    {
      queue.enQueue(temp->right_);
    }
  }
  std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
  inorderWalk(root_);
  std::cout << std::endl;
}

template<class T>
bool BinarySearchTree<T>::insert(const T& key)
{
  Node<T>* current = root_;
  Node<T>* prev = nullptr;
  bool flagOfPos;

  if (root_ == nullptr)
  {
    root_ = new Node<T>(key);
    return true;
  }
  else
  {
    while (current != nullptr)
    {
      flagOfPos = current->key_ > key;
      if (current->key_ == key)
        return false;
      if (flagOfPos)
      {
        prev = current;
        current = current->left_;
      }
      else
      {
        prev = current;
        current = current->right_;
      }
    }
    if (flagOfPos)
    {
      prev->left_ = new Node<T>(key);
      prev->left_->par_ = prev;
    }
    else
    {
      prev->right_ = new Node<T>(key);
      prev->right_->par_ = prev;
    }
    return true;
  }
}

template<class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& other)
{
  if (getCount() != other.getCount())
  {
    std::cout << "Not equal quantity of nodes\n";
    return false;
  }
  return BinarySearchTree<T>::equalNode(root_, other.root_);
}

template<class T>
bool BinarySearchTree<T>::equalNode(const Node<T>* node1, const Node<T>* node2)
{
  if (node1 == nullptr || node2 == nullptr)
  {
    return node1 == node2;
  }
  return (equalNode(node1->left_, node2->left_) && equalNode(node1->right_, node2->right_) && node1->key_ == node2->key_);
}

#endif
