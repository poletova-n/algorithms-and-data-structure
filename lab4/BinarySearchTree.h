#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>

template <class T>
class BinarySearchTree
{
public:
	BinarySearchTree();

	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr);

	~BinarySearchTree();

	BinarySearchTree<T>& operator= (const BinarySearchTree<T>& src) = delete;
	BinarySearchTree<T>& operator= (BinarySearchTree<T>&& src);

	void print(std::ostream& out) const;

	bool insert(const T& key);

	bool deleteKey(const T& key);

	int getCount() const;

	bool iterativeSearch(const T& key) const;

	int getHeight() const;

	void iterativeInorderWalk() const;

	void inorderWalk() const;

	bool operator==(const BinarySearchTree <T>& src);

private:
	struct Node
	{
		T key_;
		Node* left_;
		Node* right_;

		Node(T key, Node* right = nullptr, Node* left = nullptr) :
			key_(key), right_(right), left_(left) {}
	};
	Node* root_;

	Node* iterativeSearchNode(const T& key) const;

	void swap(BinarySearchTree <T>&, BinarySearchTree <T>&);

	void deleteSubtree(Node*);

	Node* deleteNode(Node* node, const T& key);

	void printNode(std::ostream&, Node*) const;

	int getCountSubTree(const Node*) const;

	int getHeightSubtree(Node*) const;

	void inorderWalk(Node*) const;

	bool equalNode(const Node*, const Node*);
};

template<class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) : root_(src.root_)
{
	src.root_ = nullptr;

	std::cout << "Move Constructor\n";
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteSubtree(root_);
}

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
{
	this->swap(src);
	return *this;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	return (iterativeSearchNode(key) != nullptr);
}

template<class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	Node* current = root_;
	Node* temp = current;

	if (root_ == nullptr) {
		root_ = new Node(key);
		return true;
	}

	while (current != nullptr)
	{
		if (current->key_ < key) {
			temp = current;
			current = current->right_;
		}
		else if (current->key_ > key) {
			temp = current;
			current = current->left_;
		}
		else {
			std::cout << "The key " << key << "has already been added to the tree\n";
			return false;
		}
	}
	if (temp->key_ < key) {
		temp->right_ = new Node(key);
	}
	else {
		temp->left_ = new Node(key);
	}
	return true;
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
	Node* current = root_;
	if (current == nullptr) {
		return current;
	}

	while (current != nullptr && current->key_ != key)
	{
		if (key > current->key_) {
			current = current->right_;
		}
		else {
			current = current->left_;
		}
	}

	return current;
}


template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	if (!this->iterativeSearch(key))
	{
		std::cout << "No key found\n";
		return false;
	}
	else
	{
		root_ = deleteNode(root_, key);
		return true;
	}
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::deleteNode(Node* node, const T& key)
{
	if (node == nullptr)
		return node;

	if (key == node->key_)
	{
		Node* tmp;
		if (node->right_ == nullptr)
			tmp = node->left_;
		else
		{
			Node* ptr = node->right_;
			if (ptr->left_ == nullptr)
			{
				ptr->left_ = node->left_;
				tmp = ptr;
			}
			else
			{
				Node* min = ptr->left_;
				while (min->left_ != nullptr)
				{
					ptr = min;
					min = ptr->left_;
				}
				ptr->left_ = min->right_;
				min->left_ = node->left_;
				min->right_ = node->right_;
				tmp = min;

			}
		}
		delete node;
		return tmp;
	}
	else if (key < node->key_)
		node->left_ = deleteNode(node->left_, key);
	else
		node->right_ = deleteNode(node->right_, key);
	return node;
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

template<class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeightSubtree(this->root_);
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	Node* root = root_;
	std::stack<Node*> stack;
	while (root != nullptr || !stack.empty())
	{
		while (root != nullptr)
		{
			stack.push(root);
			root = root->left_;
		}
		while (!stack.empty())
		{
			root = stack.top();
			stack.pop();
			std::cout << root->key_ << "- ";
			root = root->right_;
		}
	}
	std::cout << std::endl;
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
	inorderWalk(root_);
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T>& src)
{
	return BinarySearchTree<T>::equalNode(root_, src.root_);
}

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right)
{
	Node time = left.root_;
	left.root_ = right.root_;
	right.root_ = time;
}

template<class T>
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

template<class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
	if (node == nullptr)
		return 0;
	return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeightSubtree(Node* node) const
{
	int right = 0;
	int left = 0;
	if (node != nullptr)
	{
		if (node->right_ != nullptr)
			right = getHeightSubtree(node->right_) + 1;
		else
			right = 1;
		if (node->left_ != nullptr)
			left = getHeightSubtree(node->left_) + 1;
		else
			left = 1;
	}
	int max = std::max(left, right);
	return max;
}

template<class T>
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
	if (node != nullptr)
	{
		inorderWalk(node->left_);
		std::cout << " (" << node->key_ << ") ";
		inorderWalk(node->right_);
	}
};

template<class T>
void BinarySearchTree<T>::deleteSubtree(Node* node)
{
	delete iterativeSearchNode(node->key_);
}

template <class T>
bool BinarySearchTree<T>::equalNode(const Node* l, const Node* r)
{
	if (l == nullptr && r == nullptr) {
		return true;
	}
	else if (r == nullptr || l == nullptr) {
		return false;
	}

	bool isLeftSame = equalNode(l->left_, r->left_);
	bool isRightSame = equalNode(l->right_, r->right_);

	return (l->key_ == r->key_ && isLeftSame && isRightSame);
}
#endif