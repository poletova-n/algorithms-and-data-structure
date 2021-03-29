#ifndef LAB4_BINARYSEARCHTREE_HPP
#define LAB4_BINARYSEARCHTREE_HPP

#include <iostream>

template <class T>
class BinarySearchTree
{
private:
  struct Node
  {
    T key_;
    Node * left_;
    Node * right_;
    Node * p_;

    Node(const T& key, Node * left = nullptr, Node * right = nullptr, Node * p = nullptr) :
        key_(key), left_(left), right_(right), p_(p)
    { }
  };
  Node * root_;

public:

  BinarySearchTree() : root_(nullptr) {}

  virtual ~BinarySearchTree()
{
  deleteSubtree(root_);
}

  void print(std::ostream& out) const
{
  printNode(out,root_);
  out << std::endl;
}

  bool iterativeSearch(const T& key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

  void insert(const T& key)
{
  if (root_ == nullptr)
  {
    root_ = new Node(key);
    return;
  }

  Node * node = root_;
  Node * parent = nullptr;

  while (node != nullptr)
  {
    if (key != node->key_)
    {
      parent = node;

      if (node->key_ > key)
      {
        node = node->left_;
      }

      else
      {
        node = node->right_;
      }
    }

    else
    {
      return;
    }
  }

  node = new Node(key);
  node->p_ = parent;

  if (node->key_ < parent->key_)
  {
    parent->left_ = node;
  }
  else
  {
    parent->right_ = node;
  }
}

  void deleteKey(const T& key)
{
  Node * node = iterativeSearchNode(key);
  if (node == nullptr )
  {
    return;
  }

  if (node->left_ == nullptr && node->right_ == nullptr)
  {
    Node * parent = node->p_;
    if (parent->right_ == node)
    {
      delete node;
      parent->right_ == nullptr;
      return;
    }
    else if (parent->left_ == node)
    {
      delete node;
      parent->left_ == nullptr;
      return;
    }

    if (node->left_ == nullptr && node->right_ != nullptr && node->p_ == nullptr)
    {
      root_ = node->right_;
      root_->p_ = nullptr;
      return;
    }
    if (node->right_ == nullptr && node->left_ != nullptr && node->p_ == nullptr)
    {
      root_ = node->left_;
      root_->p_ = nullptr;
      return;
    }
    if ((node->left_ == nullptr && node->right_ != nullptr) || (node->left_ != nullptr && node->right_ == nullptr))
    {
      if (node->left_ == nullptr && node->right_ != nullptr)
      {
        node->right_->p_ = node->p_;
        node->p_->right_ = node->right_;
        delete node;
        return;
      }
      if (node->left_ != nullptr && node->right_ == nullptr)
      {
        node->left_->p_ = node->p_;
        node->p_->left_ = node->left_;
        delete node;
        return;
      }
    }
  }
}

  int getCount() const
{
  if (root_ == nullptr)
    return 0;

  return getCountSubTree(this->root_);
}

  int getHeight() const
{
  if (root_ == nullptr)
    return 0;
  return getHeightSubTree(this->root_);
}

private:
  Node* iterativeSearchNode(const T& key) const
  {
    Node* parent = root_;
    Node* node = nullptr;
    if (key > parent->key_)
    {
      node = parent->right_;
    }
    else if (key < parent->key_)
    {
      node = parent->left_;
    }
    else if (parent->key_ = key)
    {
      node = parent;
    }
    while (node->key_ != key)
    {
      if (parent->key_ > key)
      {
        node = parent->left_;
        parent = node;
      }
      else if (parent->key_ < key)
      {
        node = parent->right_;
        parent = node;
      }
      if (node == nullptr)
      {
        return node;
      }
    }
    return node;
  }

  void deleteSubtree(Node* node)
  {
    if (node == nullptr)
    {
      return;
    }
    deleteSubtree(node->left_);
    deleteSubtree(node->right_);
    delete node;
  }

  int getCountSubTree(Node* node) const
  {
    if (node == nullptr)
      return 0;
    return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
  }

  int getHeightSubTree(Node* node) const
  {
    if (node->left_ == nullptr && node->right_ == nullptr)
    {
      return 1;
    }
    if (node->left_ != nullptr && node->right_ != nullptr)
    {
      if (getHeightSubTree(node->left_) >= getHeightSubTree(node->right_))
      {
        return getHeightSubTree(node->left_) + 1;
      }
      if (getHeightSubTree(node->right_) > getHeightSubTree(node->left_))
      {
        return getHeightSubTree(node->right_) + 1;
      }
    }
    if (node->left_ != nullptr && node->right_ == nullptr)
    {
      return getHeightSubTree(node->left_) + 1;
    }
    if (node->left_ == nullptr && node->right_ != nullptr)
    {
      return getHeightSubTree(node->right_) + 1;
    }
  }

  void printNode(std::ostream& out, Node* root) const
  {
    out << '(';
    if (root)
    {
      out << root->key_;
      printNode(out, root->left_);
      printNode(out, root->right_);
    }
    out << ')';
  }
};
#endif