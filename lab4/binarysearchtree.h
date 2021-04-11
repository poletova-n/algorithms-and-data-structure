#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <ostream>

template<typename T>
class BinarySearchTree {
public:
  BinarySearchTree();

  virtual ~BinarySearchTree();

  void print(std::ostream& out) const;

  bool iterativeSearch(const T& key) const;

  void insert(const T& key);

  void insertRecursively(const T& key);

  void deleteKey(const T& key);

  [[nodiscard]] size_t getCount() const;

  [[nodiscard]] size_t getHeight() const;

private:
  struct Node {
    T key_;
    Node* left_;
    Node* right_;

    Node(const T& key, Node* left = nullptr, Node* right = nullptr):
      key_(key),
      left_(left),
      right_(right)
    {}
  };

  void addRecursively(BinarySearchTree<T>::Node* &node, const T& key);

  Node* iterativeSearchNode(const T& key) const;

  void destroyRecursive(Node* node);

  void deleteSubtree(Node* node);

  size_t getCountSubTree(Node* node) const;

  size_t getHeightSubTree(Node* node) const;

  void printNode(std::ostream& out, Node* root) const;

  Node* root_;
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
  destroyRecursive(root_);
}

template<typename T>
void BinarySearchTree<T>::destroyRecursive(Node* node)
{
  if (node)
  {
    destroyRecursive(node->left_);
    destroyRecursive(node->right_);
    delete node;
  }
}

template<typename T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printNode(out, root_);
  out << '\n';
}

template<typename T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<typename T>
void BinarySearchTree<T>::insert(const T& key)
{
  if (root_ == nullptr) {
    root_ = new Node(key);
    return;
  }
  Node* current = root_;
  Node* temp = current;
  while (current != nullptr) {
    if (current->key_ == key) {
      return;
    }
    temp = current;
    if (current->key_ < key) {
      current = current->right_;
    } else {
      current = current->left_;
    }
  }
  if (temp->key_ < key) {
    temp->right_ = new Node(key);
  } else {
    temp->left_ = new Node(key);
  }
}

template<typename T>
void BinarySearchTree<T>::insertRecursively(const T& key)
{
  addRecursively(root_, key);
}

template<typename T>
void BinarySearchTree<T>::addRecursively(BinarySearchTree<T>::Node* &node, const T& key)
{
  if (root_ == nullptr) {
    root_ = new Node(key);
    return;
  }
  if (node == nullptr) {
    node = new Node(key);
  }
  if (key < node->key_) {
    addRecursively(node->left_, key);
  } else if (key > node->key_) {
    addRecursively(node->right_, key);
  }
}

template<typename T>
void BinarySearchTree<T>::deleteKey(const T& key)
{
  if (root_ == nullptr) {
    return;
  }
  delete iterativeSearchNode(key);
}

template<typename T>
size_t BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template<typename T>
size_t BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template<typename T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  if (root_ == nullptr) {
    return nullptr;
  }
  Node* current = root_;
  while ((current != nullptr) && (current->key_ != key)) {
    if (current->key_ < key) {
      current = current->right_;
    } else {
      current = current->left_;
    }
  }
  return current;
}

template<typename T>
void BinarySearchTree<T>::deleteSubtree(BinarySearchTree::Node* node)
{
  delete iterativeSearchNode(node->key_);
}

template<typename T>
size_t BinarySearchTree<T>::getCountSubTree(BinarySearchTree::Node* node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) +
          getCountSubTree(node->right_));
}

template<typename T>
size_t BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node* node) const
{
  if (node == nullptr) {
    return 0;
  }
  return 1 + std::max(getHeightSubTree(node->left_), getHeightSubTree(node->right_));
}

template<typename T>
void BinarySearchTree<T>::printNode(std::ostream& out, BinarySearchTree::Node* root) const
{
  out << '(';
  if (root) {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
}

#endif
