#ifndef LAB4_BINARYSEARCHTREE_HPP
#define LAB4_BINARYSEARCHTREE_HPP

#include <ostream>
#include <queue>

template <class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();

  void mostUsed();

  void add(T elem);

private:
  struct Node
  {
    T key_;
    size_t count_;
    Node* left_;
    Node* right_;
    Node* p_;

    Node(T key, Node* p = nullptr):
      key_(key),
      count_(1),
      left_(nullptr),
      right_(nullptr),
      p_(p)
    {}
  };

  Node* root_;

  void printNode(Node* start, std::ostream& os);
  void removeSubtree(Node* start);
  void remove(T elem);
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
void BinarySearchTree<T>::mostUsed()
{
  if (root_ == nullptr)
  {
    std::cout << "0 words was detected.\n";
    return;
  }

  Node* first = nullptr;
  Node* second = nullptr;
  Node* third = nullptr;

  std::queue<Node*> queue;
  queue.push(root_);

  while (!queue.empty())
  {
    Node* temp = queue.front();
    queue.pop();
    if (first == nullptr)
    {
      first = temp;
    }
    else if (temp->count_ >= first->count_)
    {
      third = second;
      second = first;
      first = temp;
    }
    else if (second == nullptr)
    {
      second = temp;
    }
    else if (temp->count_ >= second->count_)
    {
      third = second;
      second = temp;
    }
    else if (third == nullptr || temp->count_ >= third->count_)
    {
      third = temp;
    }
    if (temp->left_ != nullptr)
    {
      queue.push(temp->left_);
    }
    if (temp->right_ != nullptr)
    {
      queue.push(temp->right_);
    }
  }

  if (first != nullptr)
  {
    std::cout << "Word \"" << first->key_ << "\" was " << first->count_ << " times.\n";
  }
  if (second != nullptr)
  {
    std::cout << "Word \"" << second->key_ << "\" was " << second->count_ << " times.\n";
  }
  if (third != nullptr)
  {
    std::cout << "Word \"" << third->key_ << "\" was " << third->count_ << " times.\n";
  }
}

template <class T>
void BinarySearchTree<T>::add(T elem)
{
  if (root_ == nullptr)
  {
    root_ = new Node(elem);
    return;
  }
  if (findNode(elem))
  {
    ++findNode(elem)->count_;
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
    T tempKey = temp->key_;
    remove(tempKey);
    node->key_ = tempKey;
  }
}

template <class T>
void BinarySearchTree<T>::removeSubtree(BinarySearchTree<T>::Node* start)
{
  if (start == nullptr)
  {
    return;
  }
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
    os << "Root is { " << start->key_ << " }. It's used " << start->count_ << " times.\n";
  }
  else
  {
    os << "{ " << start->key_ << " }. It's used " << start->count_ << " times.\n";
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

#endif
