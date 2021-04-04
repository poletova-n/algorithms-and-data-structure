#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "stack.hpp"
#include "queue.hpp"
#include "stacklist.hpp"
#include "queueList.hpp"
template <class T>
class BinarySearchTree
{
private:
  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    Node* p_;
    Node(const T& key, Node* left = nullptr, Node* right = nullptr,
         Node* p = nullptr) :
      key_(key), left_(left), right_(right), p_(p)
    { }
  };
  Node* root_;
public:
  BinarySearchTree() : root_(nullptr){}

  virtual ~BinarySearchTree()
  {
    deleteSubtree(root_);
  }

  void print(std::ostream& out) const
  {
    printNode(out, root_);
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
    Node* node = root_;
    Node* parent = nullptr;
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

  void recursiveInsert(const T& key)
  {
    recursiveInsertChild(root_, key, nullptr);
  }

  void deleteKey(const T& key)
  {
    Node* node = iterativeSearchNode(key);
    if (node == nullptr)
    {
      std::cout << "There is no such element \n";
      return;
    }
    if (node->left_ == nullptr && node->right_ == nullptr)
    {
      Node* parent = node->p_;
      if (parent->right_ == node)
      {
        delete node;
        parent->right_ = nullptr;
        return;
      }
      else if (parent->left_ == node)
      {
        delete node;
        parent->left_ = nullptr;
        return;
      }
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

    if (node->left_ != nullptr && node->right_ != nullptr)
    {
      Node* temp = node->right_;
      Node* minR = nullptr;
      while(temp->left_ != nullptr)
      {
        temp = temp->left_;
      }
      minR = temp;
      node->key_ = minR->key_;
      if (minR->p_->left_ == minR)
      {
        minR->p_->left_ = minR->right_;
        if (minR->right_ != nullptr)
        {
          minR->right_->p_ = minR->p_;
        }
      }
      else
      {
        minR->p_->right_ = minR->right_;
        if (minR->right_ != nullptr)
        {
          minR->right_->p_ = minR->p_;
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

  Node printByKey(std::ostream& out, const T& key)
  {
    Node* node = iterativeSearchNode(key);
    out << "Info by key " << key << ": ";
    if (node == nullptr)
    {
      out << "Tree is empty";
    }
    if (node->p_ != nullptr)
    {
      out << "parent: " << node->p_->key_ << "; ";
    }
    if (node->right_ != nullptr)
    {
      out << "right child: " << node->right_->key_ << "; ";
    }
    if (node->left_ != nullptr)
    {
      out << "left child: " << node->left_->key_ << "; ";
    }
    out << "\n";
  }

  void freeMemory()
  {
    deleteSubtree(root_);
    root_ = nullptr;
  }

  Node findNext(std::ostream& out, const T& key)
  {
    out << "Next (" << key << "): ";
    Node* node = root_;
    while (node != nullptr)
    {
      if (key < node->key_)
      {
        node = node->left_;
      }
      else if (key > node->key_)
      {
        node = node->right_;
      }
      else if (key == node->key_)
      {
        if (node->right_ != nullptr)
        {
          out << node->right_->key_ << "\n";
          break;
        }
        else if (node->left_ != nullptr)
        {
          out << node->left_->key_ << "\n";
          break;
        }
        else
        {
          out << "Not found \n";
          break;
        }
      }
    }
  }

  void traversalWidth(std::ostream& out)
  {
    QueueList<Node*> queue;
    queue.enQueue(root_);
    while (!(queue.isEmpty()))
    {
      Node* temp = queue.getEl();
      queue.deQueue();
      out << temp->key_ << ' ';
      if (temp->left_ != nullptr)
      {
        queue.enQueue(temp->left_);
      }
      if (temp->right_ != nullptr)
      {
        queue.enQueue(temp->right_);
      }
    }
  }

  void traversalPr(std::ostream& out)
  {
    std::vector<T> array;
    StackList<Node*> stack;
    stack.push(root_);
    while (!stack.isEmpty())
    {
      Node *node = stack.pop();
      out << node->key_ << ' ';
      if (node->right_ != nullptr)
      {
        stack.push(node->right_);
      }
      if (node->left_ != nullptr)
      {
        stack.push(node->left_);
      }
    }
  }

  std::vector<T> getTree(std::ostream& out)
  {
    std::vector<T> array;
    StackList<Node*> stack;
    stack.push(root_);
    while (!stack.isEmpty())
    {
      Node *node = stack.pop();
      array.push_back(node->key_);
      if (node->right_ != nullptr)
      {
        stack.push(node->right_);
      }
      if (node->left_ != nullptr)
      {
        stack.push(node->left_);
      }
    }
    return array;
  }

  bool isEqual(BinarySearchTree<T>& right)
  {
    if (right.getCount() != getCount())
    {
      return false;
    }
    std::vector<T> firstvec = getTree(std::cout);
    std::vector<T> secondvec = right.getTree(std::cout);

    std::sort(firstvec.begin(), firstvec.end());
    std::sort(secondvec.begin(), secondvec.end());
    for (size_t i = 0; i < firstvec.size(); ++i)
    {
      if (firstvec[i] != secondvec[i])
      {
        return false;
      }
    }
    return true;
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
      if(getHeightSubTree(node->left_) >= getHeightSubTree(node->right_))
      {
        return getHeightSubTree(node->left_) + 1;
      }
      if(getHeightSubTree(node->right_) > getHeightSubTree(node->left_))
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

  void recursiveInsertChild(Node* node, const T& key, Node* parent)
  {
    if (root_ == nullptr)
    {
      root_ = new Node(key);
      return;
    }
    if (node == nullptr)
    {
      if (parent->key_ < key)
      {
        node = new Node(key);
        parent->right_ = node;
        node->p_ = parent;
        return;
      }
      else if (parent->key_ > key)
      {
        node = new Node(key);
        parent->left_ = node;
        node->p_ = parent;
        return;
      }
    }
    if (node->key_ == key)
    {
      return;
    }
    if (node->key_ > key)
    {
      recursiveInsertChild(node->left_, key, node);
    }
    else if (node->key_ < key)
    {
      recursiveInsertChild(node->right_, key, node);
    }
  }


};

#endif
