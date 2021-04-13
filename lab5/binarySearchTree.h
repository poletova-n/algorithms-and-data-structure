#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "stackArray.h"
#include "queue.h"
#include <iostream>
#include <stack>

template <class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
  BinarySearchTree(BinarySearchTree<T>&& scr);
  virtual ~BinarySearchTree();

  BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
  BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src);
  bool operator== (const BinarySearchTree <T>& src);

  bool iterativeSearch(const T& key) const;
  bool insert(const T& key);
  bool deleteKey(const T& key);
  void print(std::ostream& out) const;
  int getCount() const;
  int getHeight() const;
  void iterativeInorderWalk() const;
  void inorderWalk() const;
  void breadthFirstWalk() const;
  bool isSimilar(const BinarySearchTree<T>& src) const;

private:
  template <class T>
  struct Node {
	T key_;
	Node<T>* left_;
	Node<T>* right_;
	Node<T>* p_;

	Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
	  key_(key), left_(left), right_(right), p_(p)
	{ }
  };

  Node<T>* root_;

  void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);
  void deleteSubtree(Node<T>* node);
  Node<T>* iterativeSearchNode(const T& key) const;
  void printNode(std::ostream& out, Node<T>* root) const;
  int getCountSubTree(const Node<T>* node) const;
  int getHeightSubTree(Node<T>* node) const;
  void inorderWalk(Node<T>* node) const;
  bool compareSubTrees(const Node<T>* node1, const Node<T>* node2);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() :
  root_(nullptr)
{
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)
{
  root_ = scr.root_;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& src)
{
  this->swap(src);
  return *this;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
}

template <class T>
void BinarySearchTree<T>::deleteSubtree(Node<T>* node)
{
  if (node)
  {
    if (node->left_)
    {
      deleteSubtree(node->left_);
    }
    if (node->right_)
    {
      deleteSubtree(node->right_);
    }
    delete node;
  }
}

template <class T>
void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
{
  std::swap(left.root_, right.root_);
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
  return (iterativeSearchNode(key));
}

template <class T>
typename BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  Node<T>* curr(root_);
  T currKey;
  if (curr)
  {
    currKey = curr->key_;
  }
  while (curr && currKey != key)
  {
	if (currKey > key)
	{
	  curr = curr->left_;
	}
	if (currKey < key)
	{
	  curr = curr->right_;
	}
	if (curr)
	{
	  currKey = curr->key_;
	}
  }
  return curr;
}

template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
  if (root_ == nullptr)
  {
	root_ = new Node<T>(key);
	return true;
  }
  Node<T>* curr(root_);
  Node<T>* prev(nullptr);
  bool isRight;
  while (curr != nullptr)
  {
	if (key == curr->key_)
	{
	  return false;
	}
	prev = curr;
	isRight = key > curr->key_;
	if (isRight)
	{
	  curr = curr->right_;
	}
	else
	{
	  curr = curr->left_;
	}
  }
  if (isRight)
  {
	prev->right_ = new Node<T>(key, nullptr, nullptr, prev);
  }
  else
  {
	prev->left_ = new Node<T>(key, nullptr, nullptr, prev);
  }
  return true;
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
  Node<T>* deletingNode = iterativeSearchNode(key);
  if (deletingNode == nullptr)
  {
	return false;
  }
  Node<T>* prev = deletingNode->p_;
  bool isRoot = (prev == nullptr) ? true : false;
  bool isRight;
  if (!isRoot)
  {
	isRight = (deletingNode->key_ > prev->key_) ? true : false;
  }
  if (deletingNode->left_ == nullptr && deletingNode->right_ == nullptr)
  {
	if (!isRoot)
	{
	  if (isRight)
	  {
		prev->right_ = nullptr;
	  }
	  else
	  {
		prev->left_ = nullptr;
	  }
	}
	delete deletingNode;
  }
  else if (deletingNode->left_ != nullptr && deletingNode->right_ == nullptr)
  {
	if (isRoot)
	{
	  root_ = deletingNode->left_;
	}
	else
	{
	  Node<T>* leftChild = deletingNode->left_;
	  if (isRight)
	  {
		prev->right_ = leftChild;
	  }
	  else
	  {
		prev->left_ = leftChild;
	  }
	  leftChild->p_ = prev;
	}
	delete deletingNode;
  }
  else if (deletingNode->left_ == nullptr && deletingNode->right_ != nullptr)
  {
	if (isRoot)
	{
	  root_ = deletingNode->right_;
	}
	else
	{
	  Node<T>* rightChild = deletingNode->right_;
	  if (isRight)
	  {
		prev->right_ = rightChild;
	  }
	  else
	  {
		prev->left_ = rightChild;
	  }
	  rightChild->p_ = prev;
	}
	delete deletingNode;
  }
  else
  {
	Node<T>* curr = deletingNode->left_;
	while (curr->right_ != nullptr)
	{
	  curr = curr->right_;
	}
	T temp = curr->key_;
	deleteKey(temp);
	deletingNode->key_ = temp;
  }
  return true;
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printNode(out, root_);
  out << std::endl;
}

template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
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

template <class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node<T>* node) const
{
  if (node == nullptr)
	return 0;
  return (1 + getCountSubTree(node->left_) +
	getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
{
  if (node == nullptr)
  {
	return 0;
  }
  int heightRightSubTree = getHeightSubTree(node->right_) + 1;
  int heightLeftSubTree = getHeightSubTree(node->left_) + 1;
  return (heightRightSubTree > heightLeftSubTree) ?
	heightRightSubTree : heightLeftSubTree;
}

template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
  StackArray<Node<T>*> stack(getCount());
  Node<T>* curr(root_);
  while (!stack.isEmpty() || curr)
  {
	if (curr)
	{
	  stack.push(curr);
	  curr = curr->left_;
	}
	else
	{
	  curr = stack.pop();
	  std::cout << curr->key_ << " ";
	  curr = curr->right_;
	}
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
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
{
  if (node != nullptr)
  {
	inorderWalk(node->left_);
	std::cout << node->key_ << " ";
	inorderWalk(node->right_);
  }
}

template <class T>
void BinarySearchTree<T>::breadthFirstWalk() const
{
  QueueArray<Node<T>*> queue(getCount());
  Node<T>* curr = root_;
  if (curr)
  {
    queue.enQueue(curr);
  }
  while (!queue.isEmpty())
  {
    curr = queue.deQueue();
    std::cout << curr->key_ << " ";
    if (curr->left_)
    {
      queue.enQueue(curr->left_);
    }
    if (curr->right_)
    {
      queue.enQueue(curr->right_);
    }
  }
  std::cout << '\n';
}

template <class T>
bool BinarySearchTree<T>::compareSubTrees(const Node<T>* node1, const Node<T>* node2)
{
  if (node1 == nullptr && node2 == nullptr)
  {
	return true;
  }
  else if (node1 == nullptr || node2 == nullptr)
  {
	return false;
  }
  bool isLeftEqual = compareSubTrees(node1->left_, node2->left_);
  bool isRightEqual = compareSubTrees(node1->right_, node2->right_);
  return (node1->key_ == node2->key_ && isLeftEqual && isRightEqual);
}

template <class T>
bool BinarySearchTree<T>::operator== (const BinarySearchTree <T>& src)
{
  return compareSubTrees(root_, src.root_);
}

template <class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T> &src) const
{
  if ((!root_ && !src.root_) || (getCount() != src.getCount()))
  {
    return false;
  }
  StackArray<Node<T>*> stack(getCount());
  Node<T>* curr(root_);
  while (!stack.isEmpty() || curr)
  {
    if (curr && !src.iterativeSearch(curr->key_))
    {
      return false;
    }
    if (curr)
    {
      stack.push(curr);
      curr = curr->left_;
    }
    else
    {
      curr = stack.pop();
      curr = curr->right_;
    }
  }
  return true;
}

#endif
