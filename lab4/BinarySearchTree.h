#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>

#include "StackArray.h"

template <class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree<T> &) = delete;
  BinarySearchTree(BinarySearchTree<T>&&);
  virtual ~BinarySearchTree();

  BinarySearchTree <T>& operator= (const BinarySearchTree <T>&) = delete;
  BinarySearchTree <T>& operator= (BinarySearchTree <T>&&);
  bool operator== (const BinarySearchTree <T>&);

  bool iterativeSearch(const T& key) const;
  bool insert(const T& key);
  bool deleteKey(const T& key);
  void print(std::ostream& out) const;
  T getRootKey() const;
  int getCount() const;
  int getHeight() const;
  void iterativeInorderWalk() const;
  void inorderWalk() const;
  BinarySearchTree<T> copy() const;

private:
  struct Node {
    T  key_;
    Node* left_;
    Node* right_;

    Node(T key, Node* left = nullptr, Node* right = nullptr):
      key_(key),
      left_(left),
      right_(right)
    {}
  };

  Node* root_;

  void swap(BinarySearchTree <T>&, BinarySearchTree <T>&);
  void deleteSubtree(Node*);
  Node* iterativeSearchNode(const T&) const;
  void printNode(std::ostream&, Node*) const;
  int getCountSubTree(const Node*) const;
  int getHeightSubTree(Node*) const;
  void inorderWalk(Node*) const;
  void copySubTree(const Node*, BinarySearchTree<T>&) const;
  static bool equalSubTrees(const Node*, const Node*);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src)
{
  swap(*this, src);
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& src)
{
  swap(*this, src);
  return *this;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
}

template <class T>
void BinarySearchTree<T>::deleteSubtree(Node* node)
{
  if (node == nullptr) {
    return;
  }
  if (node->left_ != nullptr) {
    deleteSubtree(node->left_);
  }
  if (node->right_ != nullptr) {
    deleteSubtree(node->right_);
  }
  delete node;
}

template <class T>
void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
{
  Node* temp = right.root_;
  right.root_ = left.root_;
  left.root_ = temp;
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
  return iterativeSearchNode(key) != nullptr;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  Node* result(root_);
  while(result != nullptr && result->key_ != key) {
    if (result->key_ > key){
      result = result->left_;
    } else {
      result = result->right_;
    }
  }
  return result;
}

template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
  if (root_ == nullptr) {
    root_ = new Node(key);
    return true;
  }
  Node* current(root_);
  Node* previous(nullptr);
  bool followLeftLink;
  while(current != nullptr) {
    if (current->key_ == key) {
      return false;
    }
    previous = current;
    followLeftLink = current->key_ > key;
    if (followLeftLink) {
      current = current->left_;
    } else {
      current = current->right_;
    }
  }
  if (followLeftLink) {
    previous->left_ = new Node(key);
  } else {
    previous->right_ = new Node(key);
  }
  return true;
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
  Node* previous(root_);
  Node* nodeToDelete(root_);
  bool followLeftLink;
  while(nodeToDelete != nullptr && nodeToDelete->key_ != key) {
    previous = nodeToDelete;
    followLeftLink = nodeToDelete->key_ > key;
    if (followLeftLink){
      nodeToDelete = nodeToDelete->left_;
    } else {
      nodeToDelete = nodeToDelete->right_;
    }
  }
  if (nodeToDelete == nullptr) {
    return false;
  }
  Node* replacement;
  if (nodeToDelete->left_ != nullptr && nodeToDelete->right_ != nullptr) {
    Node* previousForReplacement(nodeToDelete);
    replacement = nodeToDelete->right_;
    while (replacement->left_ != nullptr) {
      previousForReplacement = replacement;
      replacement = replacement->left_;
    }
    replacement->left_ = nodeToDelete->left_;
    if (previousForReplacement != nodeToDelete) {
      previousForReplacement->left_ = replacement->right_;
      replacement->right_ = nodeToDelete->right_;
    }
  } else {
    if (nodeToDelete->right_ == nullptr) {
      replacement = nodeToDelete->left_;
    } else {
      replacement = nodeToDelete->right_;
    }
  }
  if (followLeftLink) {
    previous->left_ = replacement;
  } else {
    previous->right_ = replacement;
  }
  if (nodeToDelete == root_) {
    root_ = replacement;
  }
  delete nodeToDelete;
  return true;
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printNode(out, root_);
  out << std::endl;
}

template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node* root) const
{
  out << '(';
  if (root != nullptr) {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}

template <class T>
T BinarySearchTree<T>::getRootKey() const
{
  return root_->key_;
}

template <class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) +
            getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeight() const
{
  if (root_ == nullptr) {
    return 0;
  }
  return getHeightSubTree(this->root_) - 1;
}

template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node* node) const
{
  if (node == nullptr){
    return 0;
  }
  int rightSubTreeHeight = getHeightSubTree(node->right_) + 1;
  int leftSubTreeHeight = getHeightSubTree(node->left_) + 1;
  if (rightSubTreeHeight < leftSubTreeHeight) {
    return leftSubTreeHeight;
  }
  return rightSubTreeHeight;
}

template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
  StackArray<Node*> stack;
  Node* current(root_);
  while(current != nullptr || !stack.isEmpty()) {
    while (current != nullptr) {
      stack.push(current);
      current = current->left_;
    }
    current = stack.pop();
    std::cout << '(' << current->key_ << ')';
    current = current->right_;
  }
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::inorderWalk() const
{
  inorderWalk(root_);
  std::cout << '\n';
}

template <class T>
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
  if (node != nullptr) {
    inorderWalk(node->left_);
    std::cout << '(' << node->key_ << ')';
    inorderWalk(node->right_);
  }
}

template <class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree <T>& src)
{
  return BinarySearchTree<T>::equalSubTrees(root_, src.root_);
}

template <class T>
BinarySearchTree<T> BinarySearchTree<T>::copy() const
{
  BinarySearchTree<T> result;
  if (root_ == nullptr) {
    return result;
  }
  copySubTree(root_, result);
  return result;
}

template <class T>
void BinarySearchTree<T>::copySubTree(const Node* node, BinarySearchTree<T>& destination) const
{
  if (node != nullptr) {
    destination.insert(node->key_);
    copySubTree(node->left_, destination);
    copySubTree(node->right_, destination);
  }
}

template <class T>
bool BinarySearchTree<T>::equalSubTrees(const Node* node1, const Node* node2)
{
  if (node1 == nullptr || node2 == nullptr) {
    return node1 == node2;
  }
  return equalSubTrees(node1->left_, node2->left_) &&
          equalSubTrees(node1->right_, node2->right_) &&
            node1->key_ == node2->key_;
}

#endif
