#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "queuelist.h"
#include "stacklist.h"

template <class T>
class BinarySearchTree
{
public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree& other) = delete;
		BinarySearchTree(BinarySearchTree&& other) noexcept;

		BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other) = delete;
		BinarySearchTree<T>& operator=(BinarySearchTree<T>&& other) noexcept;

		virtual ~BinarySearchTree();

		void iterativeAppend(const T& element);
		void recursiveAppend(const T& element);
		size_t getSize() const;
		size_t getHeight() const;
		void freeMemory();
		void deleteElement(const T& element);
		void printInfo(std::ostream& stream, const T& element) const;

		void iterativeSearchInWidth();
		std::vector<T> iterativePrefixSearch();

private:
		struct Node
		{
				T key_;
				Node* left_;
				Node* right_;
				Node* p_;
				Node(T key, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) :
						key_(key),
						left_(left),
						right_(right),
						p_(parent)
				{}
		};
		Node* root_;
		Node* findNext(const T& element) const;
		Node* findByKey(const T& element) const;

		size_t getCountUnder(Node* node) const;

		void findNextUnder(std::vector<T>& vector, Node* node) const;

		void recursiveAppendUnder(Node* node, const T& element, Node* parent);

		void freeElement(Node* node);

		size_t getHeightUnder(Node* node) const;

		Node* findMin(Node* current);
		Node* findMax(Node* current);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree() :
		root_(nullptr)
{}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree&& other) noexcept
{
		root_ = std::move(other.root_);
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree&& other) noexcept
{
		root_ = std::move(other.root_);
		return *this;
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
		freeMemory();
}

template <class T>
void BinarySearchTree<T>::iterativeAppend(const T& element)
{
		if (root_ == nullptr)
		{
				root_ = new Node(element);
				return;
		}
		Node* temp = root_;
		Node* parent = nullptr;
		while (temp != nullptr)
		{
				if (temp->key_ > element)
				{
						parent = temp;
						temp = temp->left_;
				}
				else if (temp->key_ < element)
				{
						parent = temp;
						temp = temp->right_;
				}
				else if (temp->key_ == element)
				{
						return;
				}
		}
		temp = new Node(element);
		temp->p_ = parent;
		if (parent->key_ < temp->key_)
		{
				parent->right_ = temp;
		}
		else
		{
				parent->left_ = temp;
		}
}

template <class T>
void BinarySearchTree<T>::recursiveAppend(const T& element)
{
		recursiveAppendUnder(root_, element, nullptr);
}

template <class T>
void BinarySearchTree<T>::recursiveAppendUnder(BinarySearchTree<T>::Node* node, const T& element, Node* parent)
{
		if (root_ == nullptr)
		{
				root_ = new Node(element);
				return;
		}
		if (node == nullptr)
		{
				if (parent->key_ < element)
				{
						node = new Node(element);
						parent->right_ = node;
						node->p_ = parent;
						return;
				}
				else if (parent->key_ > element)
				{
						node = new Node(element);
						parent->left_ = node;
						node->p_ = parent;
						return;
				}
		}
		if (node->key_ == element)
		{
				return;
		}
		if (node->key_ > element)
		{
				recursiveAppendUnder(node->left_, element, node);
		}
		else if (node->key_ < element)
		{
				recursiveAppendUnder(node->right_, element, node);
		}
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findByKey(const T& element) const
{
		Node* temp = root_;
		while (temp != nullptr)
		{
				if (temp->key_ == element)
				{
						return temp;
				}
				else if (temp->key_ < element)
				{
						temp = temp->right_;
				}
				else if (temp->key_ > element)
				{
						temp = temp->left_;
				}
		}
		return nullptr;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findNext(const T& element) const
{
		if (root_ == nullptr)
		{
				return nullptr;
		}
		std::vector<T> container;
		container.insert(root_->key_);
		container = findNextUnder(container);
		std::sort(container.begin(), container.end());
		for (size_t i = 0; i < container.size(); ++i)
		{
				if (i == container.size() - 1)
				{
						return nullptr;
				}
				if (container[i] == element)
				{
						return findByKey(container[i + 1]);
				}
		}
}

template <class T>
void BinarySearchTree<T>::findNextUnder(std::vector<T>& vector, Node* node) const
{
		if (node == nullptr)
		{
				return;
		}
		vector.push_back(node->key_);
		findNextUnder(vector, node->left_);
		findNextUnder(vector, node->right_);
}

template <class T>
size_t BinarySearchTree<T>::getSize() const
{
		return (getCountUnder(root_));
}

template <class T>
size_t BinarySearchTree<T>::getCountUnder(BinarySearchTree<T>::Node* node) const
{
		if (node == nullptr)
		{
				return 0;
		}
		return getCountUnder(node->right_) + getCountUnder(node->left_) + 1;
}

template <class T>
void BinarySearchTree<T>::freeMemory()
{
		freeElement(root_);
		root_ = nullptr;
}

template<class T>
void BinarySearchTree<T>::deleteElement(const T& element)
{
		Node* temp = findByKey(element);
		if (temp == nullptr)
		{
				std::cout << "There is no element to delete. \n";
				return;
		}
		if (getSize() == 1)
		{
				delete root_;
				root_ = nullptr;
		}
		if (temp->left_ == nullptr && temp->right_ == nullptr)
		{
				Node* parent = temp->p_;
				if (parent->right_ == temp)
				{
						delete temp;
						parent->right_ = nullptr;
						return;
				}
				else if (parent->left_ == temp)
				{
						delete temp;
						parent->left_ = nullptr;
						return;
				}
		}
		if (temp->left_ == nullptr && temp->right_ != nullptr && temp->p_ == nullptr)
		{
				root_ = temp->right_;
				root_->p_ = nullptr;
				return;
		}
		if (temp->right_ == nullptr && temp->left_ != nullptr && temp->p_ == nullptr)
		{
				root_ = temp->left_;
				root_->p_ = nullptr;
				return;
		}
		if ((temp->left_ == nullptr && temp->right_ != nullptr) || (temp->left_ != nullptr && temp->right_ == nullptr))
		{
				if (temp->left_ == nullptr && temp->right_ != nullptr)
				{
						temp->right_->p_ = temp->p_;
						temp->p_->right_ = temp->right_;
						delete temp;
						return;
				}
				if (temp->left_ != nullptr && temp->right_ == nullptr)
				{
						temp->left_->p_ = temp->p_;
						temp->p_->left_ = temp->left_;
						delete temp;
						return;
				}
		}
		if (temp->left_ != nullptr && temp->right_ != nullptr)
		{
				Node* rightmin = findMin(temp->right_);
				temp->key_ = rightmin->key_;
				if (rightmin->p_->left_ == rightmin)
				{
						rightmin->p_->left_ = rightmin->right_;
						if (rightmin->right_ != nullptr)
						{
								rightmin->right_->p_ = rightmin->p_;
						}
				}
				else
				{
						rightmin->p_->right_ = rightmin->right_;
						if (rightmin->right_ != nullptr)
						{
								rightmin->right_->p_ = rightmin->p_;
						}
				}
		}
}

template <class T>
void BinarySearchTree<T>::freeElement(BinarySearchTree<T>::Node* node)
{
		if (node == nullptr)
		{
				return;
		}
		freeElement(node->left_);
		freeElement(node->right_);
		delete node;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMin(Node* current)
{
		while (current->left_ != nullptr)
		{
				current = current->left_;
		}
		return current;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMax(Node* current)
{
		while (current->right_ != nullptr)
		{
				current = current->right_;
		}
		return current;
}

template <class T>
void BinarySearchTree<T>::printInfo(std::ostream& stream, const T& element) const
{
		stream << "Element info: \n";
		Node* temp = findByKey(element);
		if (temp == nullptr)
		{
				stream << "This element is not listed in the tree. \n";
				return;
		}
		if (temp->p_ == nullptr)
		{
				stream << "There is no parent for this element. \n";
		}
		else
		{
				stream << "Parent is: " << temp->p_->key_ << '\n';
		}
		if (temp->left_ == nullptr)
		{
				stream << "There is no left sub element for this element. \n";
		}
		else
		{
				stream << "Left element is: " << temp->left_->key_ << '\n';

		}
		if (temp->right_ == nullptr)
		{
				stream << "There is no right sub element for this element. \n";
		}
		else
		{
				stream << "Right element is: " << temp->right_->key_ << '\n';
		}
}

template <class T>
size_t BinarySearchTree<T>::getHeight() const
{
		return (getHeightUnder(root_));
}

template <class T>
size_t BinarySearchTree<T>::getHeightUnder(BinarySearchTree<T>::Node* node) const
{
		if (node->left_ == nullptr && node->right_ == nullptr)
		{
				return 1;
		}
		if (node->left_ != nullptr && node->right_ == nullptr)
		{
				return 1 + getHeightUnder(node->left_);
		}
		if (node->left_ == nullptr && node->right_ != nullptr)
		{
				return 1 + getHeightUnder(node->right_);
		}
		if (node->left_ != nullptr && node->right_ != nullptr)
		{
				return 1 + std::max(getHeightUnder(node->right_), getHeightUnder(node->left_));
		}
}

template <class T>
void BinarySearchTree<T>::iterativeSearchInWidth()
{
		QueueList<Node*> queue;
		queue.enQueue(this->root_);
		while (!queue.isEmpty())
		{
				Node* node = queue.deQueue();
				std::cout << node->key_ << ' ';
				if (node->left_ != nullptr)
				{
						queue.enQueue(node->left_);
				}
				if (node->right_ != nullptr)
				{
						queue.enQueue(node->right_);
				}
		}
}

template <class T>
std::vector<T> BinarySearchTree<T>::iterativePrefixSearch()
{
		StackList<Node*> stack;
		std::vector<T> vec;
		Node* node = this->root_;
		while (!stack.isEmpty() || node != nullptr)
		{
				if (node != nullptr)
				{
						stack.push(node);
						vec.push_back(node->key_);
						node = node->left_;
				}
				else
				{
						node = stack.pop();
						node = node->right_;
				}
		}
		return vec;
}

template <class T>
bool areSame(BinarySearchTree<T>& first, BinarySearchTree<T>& second)
{
		std::vector<T> firstvec = first.iterativePrefixSearch();
		std::vector<T> secondvec = second.iterativePrefixSearch();
		if (firstvec.size() != secondvec.size())
		{
				return false;
		}
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

#endif
