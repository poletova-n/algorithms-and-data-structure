#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <stdexcept>

#include "queueLinkList.h"
#include "stackLinkList.h"

template<class T>
class BinarySearchTree
{
private:
	struct Node
	{
		T key_;
		Node* left_;
		Node* right_;
		Node* p_;
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{}
	};
	Node* root_;
protected:
	size_t count(Node*) const;
	void addCursive(const T&, Node**);
	void freesMemoryTree(Node*) const;
	size_t heightTree(Node*) const;
public:
	BinarySearchTree() : root_(nullptr) {}
	BinarySearchTree(T key) : root_(new Node(key)) {}
	BinarySearchTree(const BinarySearchTree<T>&) = delete;
	BinarySearchTree(BinarySearchTree<T>&& tree) = delete;
	~BinarySearchTree()
	{
		this->freesMemoryTree(root_);
	}

	BinarySearchTree<T> operator=(const BinarySearchTree<T>&) = delete;
	BinarySearchTree<T> operator=(BinarySearchTree<T>&&) = delete;
	bool insertIterative(const T&);
	void insertCursive(const T&);
	bool searchIterative(const T& key) const;
	T find(const T&, const char[]);
	void deleteElement(const T&);
	size_t getCount() const;
	size_t getHeight() const;
	void printNode(const T&, std::ostream&) const;

	//lab 5
	QueueLinkList<T> browseTreeWidth() const;
	QueueLinkList<T> browseTreePrefix() const;
	bool sameTrees(const BinarySearchTree<T>&) const;
};

template<class T>
void BinarySearchTree<T>::freesMemoryTree(Node* node) const
{
	if (node != nullptr)
	{
		if (node->left_ == nullptr && node->right_ == nullptr)
		{
			delete node;
		}
		else
		{
			freesMemoryTree(node->left_);
			freesMemoryTree(node->right_);
			delete node;
		}
	}
}

template<class T>
bool BinarySearchTree<T>::insertIterative(const T& key)
{
	if (root_ == nullptr)
	{
		root_ = new Node(key);
		return 1;
	}
	else
	{
		Node* temp = root_;
		bool breakWhile = false;
		while (breakWhile == false)
		{
			if (temp->key_ == key)
			{
				return 0;
			}
			else
			{
				if (key < temp->key_)
				{
					if (temp->left_ == nullptr)
					{
						Node* node = new Node(key);
						temp->left_ = node;
						node->p_ = temp;
						return 1;
					}
					temp = temp->left_;
				}
				else
				{
					if (temp->right_ == nullptr)
					{
						Node* node = new Node(key);
						temp->right_ = node;
						node->p_ = temp;
						return 1;
					}
					temp = temp->right_;
				}
			}
		}
	}
	return 0;
}

template<class T>
void BinarySearchTree<T>::addCursive(const T& key, Node** node)
{
	if (*node == nullptr)
	{
		*node = new Node(key);
	}
	else
	{
		if ((*node)->key_ != key)
		{
			if (key < (*node)->key_)
			{
				addCursive(key, &(*node)->left_);
				(*node)->left_->p_ = *node;
			}
			else
			{
				addCursive(key, &(*node)->right_);
				(*node)->right_->p_ = *node;
			}
		}
	}
}

template<class T>
void BinarySearchTree<T>::insertCursive(const T& key)
{
	addCursive(key, &root_);
}

template<class T>
bool BinarySearchTree<T>::searchIterative(const T& key) const
{
	if (root_ == nullptr)
	{
		return 0;
	}
	Node* temp = root_;
	bool breakWhile = false;
	while (breakWhile == false)
	{
		if (temp->key_ == key)
		{
			return 1;
		}
		else
		{
			if (temp->key_ > key)
			{
				if (temp->left_ == nullptr)
				{
					return 0;
				}
				temp = temp->left_;
			}
			else
			{
				if (temp->right_ == nullptr)
				{
					return 0;
				}
				temp = temp->right_;
			}
		}
	}
	return 0;
}

template<class T>
T BinarySearchTree<T>::find(const T& key, const char str[])
{
	if (root_ == nullptr)
	{
		throw std::logic_error("Tree empty.\n");
	}
	else
	{
		bool breakWhile = false;
		Node* node = root_;
		while (breakWhile == false)
		{
			if (node->key_ == key)
			{
				if (str == "p")
				{
					if (node == root_)
					{
						throw std::logic_error("This element has no parents.");
					}
					else
					{
						return node->p_->key_;
					}
				}
				else
				{
					if (str == "left")
					{
						if (node->left_ == nullptr)
						{
							throw std::logic_error("This element has no left child.");
						}
						else
						{
							return node->left_->key_;
						}
					}
					else
					{
						if (str == "right")
						{
							if (node->right_ == nullptr)
							{
								throw std::logic_error("This element has no right child.");
							}
							else
							{
								return node->right_->key_;
							}
						}
					}
				}
				breakWhile = true;
			}
			else
			{
				if (key < node->key_)
				{
					if (node->left_ == nullptr)
					{
						throw std::logic_error("There are no elements to look for.");
					}
					else
					{
						node = node->left_;
					}
				}
				else
				{
					if (node->right_ == nullptr)
					{
						throw std::logic_error("There are no elements to look for.");
					}
					else
					{
						node = node->right_;
					}
				}
			}
		}
	}
	return key;
}

template<class T>
void BinarySearchTree<T>::deleteElement(const T& key)
{
	if (root_ != nullptr)
	{
		Node** node = &root_;
		bool breakWhile = false;
		while (breakWhile == false)
		{
			if ((*node)->key_ == key)
			{
				if ((*node)->left_ == nullptr && (*node)->right_ == nullptr)
				{
					(*node)->p_ = nullptr;
					delete* node;
					(*node) = nullptr;
				}
				else
				{
					if ((*node)->left_ != nullptr && (*node)->right_ != nullptr)
					{
						Node* temp = (*node)->left_;
						while (temp->right_ != nullptr)
						{
							temp = temp->right_;
						}
						T tempKey = temp->key_;
						deleteElement(temp->key_);
						(*node)->key_ = tempKey;
					}
					else
					{
						if ((*node)->left_ != nullptr && (*node)->right_ == nullptr)
						{
							(*node)->left_->p_ = (*node)->p_;
							(*node)->p_ = nullptr;
							Node* temp = (*node)->left_;
							(*node)->left_ = nullptr;
							delete* node;
							(*node) = temp;
						}
						else
						{
							(*node)->right_->p_ = (*node)->p_;
							(*node)->p_ = nullptr;
							Node* temp = (*node)->right_;
							(*node)->right_ = nullptr;
							delete* node;
							(*node) = temp;
						}
					}
				}
				breakWhile = true;
			}
			else
			{
				if ((*node)->key_ > key)
				{
					if ((*node)->left_ != nullptr)
					{
						node = &((*node)->left_);
					}
					else
					{
						breakWhile = true;
					}
				}
				else
				{
					if ((*node)->right_ != nullptr)
					{
						node = &((*node)->right_);
					}
					else
					{
						breakWhile = true;
					}
				}
			}
		}
	}
}

template<class T>
size_t BinarySearchTree<T>::count(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	if ((node->left_ == nullptr) && (node->right_ == nullptr))
	{
		return 1;
	}
	return count(node->left_) + count(node->right_) + 1;
}

template<class T>
size_t BinarySearchTree<T>::getCount() const
{
	return count(root_);
}

template<class T>
size_t BinarySearchTree<T>::heightTree(Node* node) const
{
	if (node == nullptr)
	{
		return 0;
	}
	if (node->left_ == nullptr && node->right_ == nullptr)
	{
		return 1;
	}
	int left = heightTree(node->left_);
	int right = heightTree(node->right_);
	return (left >= right ? (left + 1) : (right + 1));
}

template<class T>
size_t BinarySearchTree<T>::getHeight() const
{
	return heightTree(root_);
}

template<class T>
void BinarySearchTree<T>::printNode(const T& key, std::ostream& out) const
{
	if (root_ == nullptr)
	{
		out << "The tree is empty, so no element can be found to output the information to the screen.\n";
	}
	else
	{
		Node* temp = root_;
		bool breakWhile = false;
		while (breakWhile == false)
		{
			if (temp->key_ == key)
			{
				out << "Value of the current node is: " << temp->key_ << '\n';
				out << "the value of the parent node is: " << temp->p_->key_ << '\n';
				if (temp->left_ != nullptr)
				{
					out << "the value of the left child node is: " << temp->left_->key_ << '\n';
				}
				if (temp->right_ != nullptr)
				{
					out << "the value of the right child node is: " << temp->right_->key_ << '\n';
				}
				breakWhile = true;
			}
			else
			{
				if (key < temp->key_)
				{
					if (temp->left_ != nullptr)
					{
						temp = temp->left_;
					}
					else
					{
						out << "The tree does not have an element that needs to be printed on the screen.\n";
						breakWhile = true;
					}
				}
				else
				{
					if (temp->right_ != nullptr)
					{
						temp = temp->right_;
					}
					else
					{
						out << "The tree does not have an element that needs to be printed on the screen.\n";
						breakWhile = true;
					}
				}
			}
		}
	}
}

template<class T>
QueueLinkList<T> BinarySearchTree<T>::browseTreeWidth() const
{
	if (root_ == nullptr)
	{
		throw std::logic_error("Tree empty.");
	}
	QueueLinkList<Node*> bfQueue;
	bfQueue.enQueue(root_);
	QueueLinkList<T> arrQueueData;
	while (!bfQueue.isEmpty())
	{
		Node* current = bfQueue.deQueue();
		arrQueueData.enQueue(current->key_);
		if (current->left_ != nullptr)
		{
			bfQueue.enQueue(current->left_);
		}
		if (current->right_ != nullptr)
		{
			bfQueue.enQueue(current->right_);
		}
	}
	return arrQueueData;
}

template<class T>
QueueLinkList<T> BinarySearchTree<T>::browseTreePrefix() const
{
	if (root_ == nullptr)
	{
		throw std::logic_error("Tree empty.");
	}
	QueueLinkList<T> arrQueuedata;

	StackLinkedList<Node*> bfStack;
	bfStack.push(root_);

	while (!bfStack.isEmpty())
	{
		Node* current = bfStack.pop();
		arrQueuedata.enQueue(current->key_);
		if (current->right_ != nullptr)
		{
			bfStack.push(current->right_);
		}
		while (current->left_ != nullptr)
		{
			current = current->left_;
			arrQueuedata.enQueue(current->key_);
			if (current->right_ != nullptr)
			{
				bfStack.push(current->right_);
			}
			
		}
	}
	return arrQueuedata;
}

template<class T>
bool BinarySearchTree<T>::sameTrees(const BinarySearchTree<T>& tree) const
{
	size_t count = this->getCount();
	if (count != tree.getCount())
	{
		return 0;
	}
	QueueLinkList<T> dataTree = tree.browseTreeWidth();
	QueueLinkList<T> dataThisTree = this->browseTreeWidth();
	for (size_t i = 0; i < count; i++)
	{
		if (dataTree.deQueue() != dataThisTree.deQueue())
		{
			return 0;
		}
	}
	return 1;
}

#endif
