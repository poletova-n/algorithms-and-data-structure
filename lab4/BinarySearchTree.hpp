#ifndef LAB4_BINARYSEARCHTREE_HPP
#define LAB4_BINARYSEARCHTREE_HPP

#include <ostream>

template <class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();

  size_t size();
  size_t height();

  void addIterative(T elem);
  void addRecursive(T elem);
  void remove(T elem);
  bool find(T elem);
  void print(std::ostream& os = std::cout);

private:
  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    Node* p_;

    Node(T key, Node* p = nullptr):
      key_(key),
      left_(nullptr),
      right_(nullptr),
      p_(p)
    {}
  };

  Node* root_;

  size_t sizeSubtree(Node* start);
  size_t heightSubtree(Node* start);
  void printNode(Node* start, std::ostream& os);
  void removeSubtree(Node* start);
  Node* findMax(Node* start);
  Node* findNode(T elem);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  removeSubtree(root_);
}

template <class T>
size_t BinarySearchTree<T>::size()
{
  return root_ ? sizeSubtree(root_) : 0;
}

template <class T>
size_t BinarySearchTree<T>::height()
{
  return root_ ? 1 + heightSubtree(root_) : 0;
}

template <class T>
void BinarySearchTree<T>::addIterative(T elem)
{
  if (root_ == nullptr)
  {
    root_ = new Node(elem);
    return;
  }
  Node* current = root_;
  while (true)
  {
    if (elem < current->key_ && current->left_ == nullptr)
    {
      current->left_ = new Node(elem, current);
      return;
    }
    else if (elem < current->key_)
    {
      current = current->left_;
    }
    if (elem > current->key_ && current->right_ == nullptr)
    {
      current->right_ = new Node(elem, current);
      return;
    }
    else if (elem > current->key_)
    {
      current = current->right_;
    }
  }
}

template <class T>
void BinarySearchTree<T>::addRecursive(T elem)
{
  if (root_ == nullptr)
  {
    root_ = new Node(elem);
    return;
  }
  static Node* current = root_;
  if (elem < current->key_ && current->left_ == nullptr)
  {
    current->left_ = new Node(elem, current);
    return;
  }
  else if (elem < current->key_)
  {
    current = current->left_;
    addRecursive(elem);
    return;
  }
  if (elem > current->key_ && current->right_ == nullptr)
  {
    current->right_ = new Node(elem, current);
    return;
  }
  else if (elem > current->key_)
  {
    current = current->right_;
    addRecursive(elem);
    return;
  }
}

template <class T>
void BinarySearchTree<T>::remove(T elem)
{
  Node* node = findNode(elem);
  if (node == nullptr)
  {
    throw std::invalid_argument("Element did not find.");
  }
  if (node->left_ == node->right_)
  {
    if (node == root_)
    {
      delete root_;
      root_ = nullptr;
    }
    else if (node == node->p_->left_)
    {
      Node* temp = node->p_;
      delete node;
      temp->left_ = nullptr;
    }
    else
    {
      Node* temp = node->p_;
      delete node;
      temp->right_ = nullptr;
    }
  }
  else if (node->left_ == nullptr || node->right_ == nullptr)
  {
    if (node->left_ && sizeSubtree(node->left_) == 1)
    {
      node->key_ = node->left_->key_;
      delete node->left_;
      node->left_ = nullptr;
    }
    else if (node->left_)
    {
      if (node == node->p_->left_)
      {
        node->p_->left_ = node->left_;
      }
      else if (node == node->p_->right_)
      {
        node->p_->right_ = node->left_;
      }
    }
    else if (node->right_ && sizeSubtree(node->right_) == 1)
    {
      node->key_ = node->right_->key_;
      delete node->right_;
      node->right_ = nullptr;
    }
    else if (node->right_)
    {
      if (node == node->p_->left_)
      {
        node->p_->left_ = node->right_;
      }
      else if (node == node->p_->right_)
      {
        node->p_->right_ = node->right_;
      }
    }
  }
  else
  {
    Node* temp = findMax(node->left_);
    remove(temp->key_);
    node->key_ = temp->key_;
  }
}

template <class T>
bool BinarySearchTree<T>::find(T elem)
{
  return findNode(elem);
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& os)
{
  printNode(root_, os);
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findNode(T elem)
{
  Node* current = root_;
  if (current == nullptr || current->key_ == elem)
  {
    return current;
  }
  while (current != nullptr)
  {
    if (elem == current->key_)
    {
      return current;
    }
    else if (elem > current->key_)
    {
      current = current->right_;
    }
    else if (elem < current->key_)
    {
      current = current->left_;
    }
  }
  return nullptr;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMax(Node* start)
{
  Node* current = start;
  while (true)
  {
    if (current->right_ == nullptr)
    {
      break;
    }
    current = current->right_;
  }
  return current;
}

template <class T>
void BinarySearchTree<T>::removeSubtree(BinarySearchTree<T>::Node* start)
{
  if (start->left_ || start->right_)
  {
    if (start->left_)
    {
      removeSubtree(start->left_);
      start->left_ = nullptr;
    }
    if (start->right_)
    {
      removeSubtree(start->right_);
      start->right_ = nullptr;
    }
  }
  else
  {
    delete start;
  }
}

template <class T>
void BinarySearchTree<T>::printNode(BinarySearchTree<T>::Node* start, std::ostream& os)
{
  if (start == root_)
  {
    os << "Root is { " << start->key_ << " }\n";
  }
  else
  {
    os << "{ " << start->key_ << " }\n";
  }
  if (start->left_ != start->right_)
  {
    if (start->left_)
    {
      os << "Left kid of { " << start->key_ << " } is ";
      printNode(start->left_, os);
    }
    if (start->right_)
    {
      os << "Right kid of { " << start->key_ << " } is ";
      printNode(start->right_, os);
    }
  }
}

template <class T>
size_t BinarySearchTree<T>::sizeSubtree(BinarySearchTree<T>::Node* start)
{
  size_t count = 0;
  if (start->right_ || start->left_)
  {
    if (start->right_)
    {
      count += sizeSubtree(start->right_);
    }
    if (start->left_)
    {
      count += sizeSubtree(start->left_);
    }
  }
  count += start ? 1 : 0;
  return count;
}

template <class T>
size_t BinarySearchTree<T>::heightSubtree(BinarySearchTree<T>::Node* start)
{
  size_t right = 0;
  size_t left = 0;
  if (start->right_ || start->left_)
  {
    if (start->right_)
    {
      right += 1 + heightSubtree(start->right_);
    }
    if (start->left_)
    {
      left += 1 + heightSubtree(start->left_);
    }
  }
  return right > left ? right : left;
}

#endif
