#ifndef FOREST_BINARYSEARCHTREE_H
#define FOREST_BINARYSEARCHTREE_H

#include <iostream>
#include <algorithm>

template <class T>
class BinarySearchTree
{
public:

  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree<T> & scr) = delete;
  BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;
  virtual ~BinarySearchTree();
  bool iterativeSearch(const T& key) const;
  bool insert(const T& key);
  bool deleteKey(const T& key);
  void print(std::ostream& out) const;
  int getCount() const;
  int getHeight() const;

private:
  struct Node {
    T key_;
    Node* p_;
    Node* left_;
    Node* right_;
    int number;

    Node(T key, int size, Node* p = nullptr, Node* left = nullptr, Node* right = nullptr) :
      key_(key),
      number(size),
      p_(p),
      left_(left),
      right_(right)
    { }
  };

  int size_;
  Node* root_;
  void deleteSubtree(Node* node);
  Node * SearchNode(const T& key) const;
  void printNode(std::ostream& out, Node* root) const;
  int getCountSubTree(const Node* node) const;
  int getHeightSubTree(const Node* root) const;
};

template <class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr) noexcept {
  root_ = new Node(scr.root_);
  deleteSubtree(scr);
}


template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
  deleteSubtree(root_);
  delete root_;
}

template <class T>
void BinarySearchTree<T>::deleteSubtree(Node* node) {
  if (node->right_ != nullptr) {
    deleteSubtree(node->right_);
  }
  if (node->left_ != nullptr) {
    deleteSubtree(node->left_);
  }
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const {
  return (SearchNode(key) != nullptr);
}

template <class T>
bool BinarySearchTree<T>::insert(const T& key) {
  if (root_ == nullptr) {
    size_++;
    root_ = new Node(key, size_);
    return true;
  }
  else {
    Node *temp = root_;
    Node *tempnext = temp;
    while (tempnext != nullptr) {
      temp = tempnext;
      if (temp->key_ == key) {
        return false;
      }
      if (temp->key_ > key) {
        tempnext = temp->left_;
      }
      else if (temp->key_ < key) {
        tempnext = temp->right_;
      }
    }
    if (temp->key_ > key) {
      size_++;
      temp->left_ = new Node(key, size_, temp);
    }
    if (temp->key_ < key) {
      size_++;
      temp->right_ = new Node(key, size_, temp);
    }
  }
  return true;
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key) {
  Node * temp = SearchNode(key);
  Node * tempprev = temp->p_;
  if ((temp->right_ == nullptr)&&(temp->left_ == nullptr)) {
    if (tempprev->key_ < temp->key_) {
      tempprev->right_ = nullptr;
    }
    if (tempprev->key_ > temp->key_) {
      tempprev->left_ = nullptr;
    }
    delete temp;
    return true;
  }
  if ((temp->right_ != nullptr) || (temp->left_ != nullptr))
  {
    if(temp->right_ == nullptr) {
      if (tempprev->key_ < tempprev->key_) {
        tempprev->left_ = temp->left_;
        delete temp;
      } else if (tempprev->key_ > tempprev->key_) {
        tempprev->right_ = temp->right_;
        delete temp;
        return true;
      }
    }
    if (temp->left_ == nullptr) {
      if (tempprev->key_ < tempprev->key_) {
        tempprev->left_ = temp->left_;
        delete temp;
      }
      else if (tempprev->key_ > tempprev->key_) {
        tempprev->right_ = temp->right_;
        delete temp;
        return true;
      }
    }
  }
}

template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node* root) const {
  out << '(';
  if (root != nullptr) {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}

template <class T>
int BinarySearchTree<T>::getCount() const {
  return getCountSubTree(this->root_);
}

template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const {
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) +
          getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeight() const {
  return getHeightSubTree(root_);
}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::SearchNode(const T &key) const {
  Node * temp = root_;
  while ((temp->key_ != key) || (temp != nullptr)) {
    if (temp->key_ == key) {
      return temp;
    }
    if (temp->key_ > key) {
      temp = temp->left_;
    }
    if (temp->key_ < key) {
      temp = temp->right_;
    }
  }
  return  temp;
}

template<class T>
void BinarySearchTree<T>::print(std::ostream &out) const {
  printNode(out, root_);
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(const BinarySearchTree::Node *root) const {
  if (root != nullptr) {
    return (1 + std::max(getHeightSubTree(root->left_), getHeightSubTree(root->right_)));
  }
  else {
    return 0;
  }
}

#endif //FOREST_BINARYSEARCHTREE_H
