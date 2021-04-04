#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <memory>

#include "StackArray.h"
#include "Queue.h"

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& src) = delete;
	BinarySearchTree(BinarySearchTree<T>&& src);
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src);
	bool operator== (const BinarySearchTree <T>& src) const;
	bool iterativeSearch(const T& key) const;
	bool insert(const T& key);
	bool deleteKey(const T& key);
	void print(std::ostream& out) const;
	int getCount() const;
	int getHeight() const;
	void iterativeInorderWalk() const;
	void inorderWalk() const;
	bool isSimilar(const BinarySearchTree<T>&) const;
	virtual ~BinarySearchTree();
private:
	struct Node {
		T  key_;
		Node* left_;
		Node* right_;

		Node(T key, Node* left = nullptr, Node* right = nullptr) :
			key_(key),
			left_(left),
			right_(right)
		{}
	};

	Node* root_;
	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);
	void deleteSubtree(Node* node);
	Node* iterativeSearchNode(const T& key) const;
	void printNode(std::ostream& out, Node* root) const;
	int getCountSubTree(const Node* node) const;
	int getHeightSubTree(Node* node) const;
	void inorderWalk(Node*) const;
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() :
	root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src)
{
	root_ = src.root_;
	src.root_ = nullptr;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& src)
{
	swap(*this, src);
	return *this;
}

template <class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree <T>& src) const
{
	return BinarySearchTree<T>::equalSubTrees(root_, src.root_);
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
	while (result != nullptr && result->key_ != key) {
		if (result->key_ > key) {
			result = result->left_;
		}
		else {
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
	Node* prev(nullptr);
	bool followLeftLink;
	while (current != nullptr) {
		if (current->key_ == key) {
			return false;
		}
		prev = current;
		followLeftLink = current->key_ > key;
		if (followLeftLink) {
			current = current->left_;
		}
		else {
			current = current->right_;
		}
	}
	if (followLeftLink) {
		prev->left_ = new Node(key);
	}
	else {
		prev->right_ = new Node(key);
	}
	return true;
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	Node* prev(root_);
	Node* nodeToDelete(root_);
	bool followLeftLink;
	while (nodeToDelete != nullptr && nodeToDelete->key_ != key) {
		prev = nodeToDelete;
		followLeftLink = nodeToDelete->key_ > key;
		if (followLeftLink) {
			nodeToDelete = nodeToDelete->left_;
		}
		else {
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
	}
	else {
		if (nodeToDelete->right_ == nullptr) {
			replacement = nodeToDelete->left_;
		}
		else {
			replacement = nodeToDelete->right_;
		}
	}
	if (nodeToDelete == root_) {
		root_ = replacement;
	}
	else if (followLeftLink) {
		prev->left_ = replacement;
	}
	else {
		prev->right_ = replacement;
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
int BinarySearchTree<T>::getCount() const
{
	return getCountSubTree(this->root_);
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
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	StackArray<Node*> stack;
	Node* current(root_);
	while (current != nullptr || !stack.isEmpty()) {
		while (current != nullptr) {
			stack.push(current);
			current = current->left_;
		}
		current = stack.pop();
		std::cout << current->key_ << ", ";
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

template <typename T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& tree) const
{
	if (root_ == nullptr) {
		return tree.root_ == nullptr;
	}
	if (getCount() != tree.getCount()) {
		return false;
	}
	std::unique_ptr<Queue<Node*>> queue(std::make_unique<QueueArray<Node*>>(getCount() / 2));
	Node* current = root_;
	while (true) {
		if (current->left_ != nullptr) {
			queue->enQueue(current->left_);
		}
		if (current->right_ != nullptr) {
			queue->enQueue(current->right_);
		}
		if (!tree.iterativeSearch(current->key_)) {
			return false;
		}
		if (queue->isEmpty()) {
			break;
		}
		current = queue->deQueue();
	}
	return true;
}

template <class T>
void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
{
	Node* temp = right.root_;
	right.root_ = left.root_;
	left.root_ = temp;
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
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
	if (node == nullptr)
		return 0;
	return (1 + getCountSubTree(node->left_) +
		getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node* node) const
{
	if (node == nullptr) {
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
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
	if (node != nullptr) {
		inorderWalk(node->left_);
		std::cout << '(' << node->key_ << ')';
		inorderWalk(node->right_);
	}
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteSubtree(root_);
}
#endif