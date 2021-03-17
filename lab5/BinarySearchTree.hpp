#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include "StackArray.hpp"
#include "QueueArray.hpp"

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();

	BinarySearchTree(const BinarySearchTree<T>& src) = delete;

	BinarySearchTree(BinarySearchTree<T>&& src) noexcept;

	BinarySearchTree<T>& operator= (const BinarySearchTree<T>& src) = delete;

	BinarySearchTree<T>& operator= (BinarySearchTree<T>&& src) noexcept;

	bool operator== (const BinarySearchTree<T>& src);

	virtual ~BinarySearchTree();

	bool iterativeSearch(const T& key) const;

	bool insert(const T& key);

	bool deleteKey(const T& key);

	void print(std::ostream& out) const;

	int getCount() const;

	int getHeight() const;

	T* iterativeInorderWalk() const;

	void inorderWalk() const;

	bool isSimilar(const BinarySearchTree<T>&);

private:
	struct Node {
		T  key_;
		Node* left_;
		Node* right_;
		Node* p_;
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{}
	};
	Node* root_;

	void swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right);

	void deleteSubtree(Node* node);

	Node* iterativeSearchNode(const T& key) const;

	void printNode(std::ostream& out, Node* root) const;

	int getCountSubTree(const Node* node) const;

	int getHeightSubTree(Node* node) const;

	bool equalNode(const Node* lhs, const Node* rhs);

	void inorderWalk(Node* node) const;

};

template <class T>
BinarySearchTree<T>::BinarySearchTree() :
	root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) noexcept
{
	root_ = src.root_;
	src.root_ = nullptr;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& src) noexcept
{
	deleteSubtree(root_);
	root_ = src.root_;
	src.root_ = nullptr;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteSubtree(root_);
}

template <class T>
void BinarySearchTree<T>::deleteSubtree(Node* node)
{
	if (node != nullptr)
	{
		if (node->left_ != nullptr)
		{
			deleteSubtree(node->left_);
		}
		if (node->right_ != nullptr)
		{
			deleteSubtree(node->right_);
		}
		if (node->p_ == nullptr)
		{
			root_ = nullptr;
			delete node;
		}
		else
		{
			if ((node->p_->left_ != nullptr) && (node->p_->left_->key_ == node->key_))
			{
				node->p_->left_ = nullptr;
				delete node;
			}
			else if ((node->p_->right_ != nullptr) && (node->p_->right_->key_ == node->key_))
			{
				node->p_->right_ = nullptr;
				delete node;
			}
		}
	}
}

template <class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right)
{
	std::swap(left.root_, right.root_);
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	return (iterativeSearchNode(key) != nullptr);
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
	Node* currentNode = root_;
	while ((currentNode != nullptr) && (currentNode->key_ != key))
	{
		if (key < currentNode->key_)
		{
			currentNode = currentNode->left_;
		}
		else
		{
			currentNode = currentNode->right_;
		}
	}
	return currentNode;
}

template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	Node* currentNode = root_;
	Node* parentNode = nullptr;
	if (root_ == nullptr)
	{
		Node* newRoot = new Node(key, nullptr, nullptr, nullptr);
		root_ = newRoot;
		return true;
	}
	while (currentNode != nullptr)
	{
		if (currentNode->key_ == key)
		{
			return false;
		}
		parentNode = currentNode;
		if (key < currentNode->key_)
		{
			currentNode = currentNode->left_;
		}
		else
		{
			currentNode = currentNode->right_;
		}
	}
	if (key < parentNode->key_)
	{
		parentNode->left_ = new Node(key, nullptr, nullptr, parentNode);
		return true;
	}
	else
	{
		parentNode->right_ = new Node(key, nullptr, nullptr, parentNode);
		return true;
	}
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	Node* node = iterativeSearchNode(key);
	if (node == nullptr)
	{
		return false;
	}
	if ((node->left_ == nullptr) && (node->right_ == nullptr))
	{
		if (node->p_ == nullptr)
		{
			root_ = nullptr;
			delete node;
			return true;
		}
		else
		{
			if ((node->p_->left_ != nullptr) && (node->p_->left_->key_ == node->key_))
			{
				node->p_->left_ = nullptr;
				delete node;
				return true;
			}
			if ((node->p_->right_ != nullptr) && (node->p_->right_->key_ == node->key_))
			{
				node->p_->right_ = nullptr;
				delete node;
				return true;
			}
		}
	}
	else if (((node->left_ != nullptr) && (node->right_ == nullptr)))
	{
		if (node->p_ == nullptr)
		{
			node->left_->p_ = nullptr;
			root_ = node->left_;
			delete node;
			return true;
		}
		else
		{
			if ((node->p_->left_ != nullptr) && (node->p_->left_->key_ == node->key_))
			{
				node->left_->p_ = node->p_;
				node->p_->left_ = node->left_;
				delete node;
				return true;
			}
			if ((node->p_->right_ != nullptr) && (node->p_->right_->key_ == node->key_))
			{
				node->left_->p_ = node->p_;
				node->p_->right_ = node->left_;
				delete node;
				return true;
			}
		}
	}
	else if (((node->left_ == nullptr) && (node->right_ != nullptr)))
	{
		if (node->p_ == nullptr)
		{
			node->right_->p_ = nullptr;
			root_ = node->right_;
			delete node;
			return true;
		}
		else
		{
			if ((node->p_->left_ != nullptr) && (node->p_->left_->key_ == node->key_))
			{
				node->right_->p_ = node->p_;
				node->p_->left_ = node->right_;
				delete node;
				return true;
			}
			if ((node->p_->right_ != nullptr) && (node->p_->right_->key_ == node->key_))
			{
				node->right_->p_ = node->p_;
				node->p_->right_ = node->right_;
				delete node;
				return true;
			}
		}
	}
	else if (((node->left_ != nullptr) && (node->right_ != nullptr)))
	{
		Node* currentNode = node->right_;
		while (currentNode->left_ != nullptr)
		{
			currentNode = currentNode->left_;
		}
		if ((currentNode->p_->left_ != nullptr) && (currentNode->p_->left_->key_ == currentNode->key_))
		{
			currentNode->p_->left_ = currentNode->right_;
			if (currentNode->right_ != nullptr)
			{
				currentNode->right_->p_ = currentNode->p_;
			}
		}
		if ((currentNode->p_->right_ != nullptr) && (currentNode->p_->right_->key_ == currentNode->key_))
		{
			currentNode->p_->right_ = currentNode->right_;
			if (currentNode->right_ != nullptr)
			{
				currentNode->right_->p_ = currentNode->p_;
			}
		}
		node->key_ = currentNode->key_;
		delete currentNode;
		return true;
	}
	return false;
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& os) const
{
	printNode(os, root_);
	os << std::endl;
}

template <class T>
void BinarySearchTree<T>::printNode(std::ostream& os, Node* root) const
{
	os << '(';
	if (root != nullptr)
	{
		os << root->key_;
		printNode(os, root->left_);
		printNode(os, root->right_);
	}
	os << ')';
}

template <class T>
int BinarySearchTree<T>::getCount() const
{
	return getCountSubTree(root_);
}

template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeightSubTree(root_) - 1;
}

template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	return std::max(1 + getHeightSubTree(node->left_), 1 + getHeightSubTree(node->right_));
}

template <class T>
bool BinarySearchTree<T>::equalNode(const Node* lhs, const Node* rhs)
{
	if (lhs == nullptr && rhs == nullptr) {
		return true;
	}
	else if (rhs == nullptr || lhs == nullptr) {
		return false;
	}
	bool isLeftSame = equalNode(lhs->left_, rhs->left_);
	bool isRightSame = equalNode(lhs->right_, rhs->right_);
	return (lhs->key_ == rhs->key_ && isLeftSame && isRightSame);
}

template <class T>
T* BinarySearchTree<T>::iterativeInorderWalk() const
{
	StackArray<Node*> stack(getCount());
	Node* temp = root_;
	int index = 0;
	T* arr = new T[getCount()];
	while ((!stack.isEmpty()) || (temp != nullptr))
	{
		if (temp != nullptr)
		{
			stack.push(temp);
			temp = temp->left_;
		}
		else
		{
			temp = stack.top();
			stack.pop();
			arr[index] = temp->key_;
			index++;
			std::cout << temp->key_;
			std::cout << ", ";
			temp = temp->right_;
		}
	}
	std::cout << "\n";
	return arr;
}

template <class T>
void BinarySearchTree<T>::inorderWalk() const
{
	inorderWalk(root_);
	std::cout << "\n";
}

template<typename T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& src)
{
	int size = getCount();
	int size2 = src.getCount();
	T* arr = this->iterativeInorderWalk();
	T* arr2 = src.iterativeInorderWalk();
	if (size == size2)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] != arr2[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

template <class T>
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
	if (node != nullptr)
	{
		inorderWalk(node->left_);
		std::cout << node->key_;
		std::cout << " ";
		inorderWalk(node->right_);
	}
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T>& src)
{
	return BinarySearchTree<T>::equalNode(root_, src.root_);
}

#endif