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
	BinarySearchTree<T>& operator=(const BinarySearchTree<T>& src) = delete;
	BinarySearchTree<T>& operator=(BinarySearchTree<T>&& scr) noexcept;
	virtual ~BinarySearchTree();

	bool iterativeSearch(const T& key) const;

	bool insert(const T& key);

	bool deleteKey(const T& key);

	void print(std::ostream& out) const;

	int getCount() const;

	int getHeight() const;

	void iterativeInorderWalk() const;

	void inorderWalk() const;

	bool operator== (const BinarySearchTree <T>& src);

private:

	template <class T>
	struct Node {
		T  key_;        
		Node<T>* left_;    
		Node<T>* right_;    
		Node<T>* p_;        

		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{  }
	};

	Node<T>* root_;

	void deleteSubtree(Node<T>* node);

	Node<T>* iterativeSearchNode(const T& key) const;

	void printNode(std::ostream& out, Node<T>* root) const;

	int getCountSubTree(const Node<T>* node) const;

	int getHeightSubTree(Node<T>* node) const;

	void inorderWalk(Node<T>* node) const;

	bool equalSubTree(const Node<T>* x, const Node<T>* y) const;
}; 

template <class T>
BinarySearchTree<T>::BinarySearchTree() :
	root_(nullptr)
{}
template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)
{
	root_ = scr.root_;
	scr.root_ = nullptr;
}
template <class T>
BinarySearchTree <T>& BinarySearchTree<T>::operator= (BinarySearchTree <T>&& scr) noexcept
{
	if (root_ == scr.root) {
		return *this;
	}
	root_ = scr.root_;
	scr.root_ = nullptr;
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
	if (node == nullptr) {
		delete node;
	}
	else {
		deleteSubtree(node->left_);
		deleteSubtree(node->right_);
		if (node != root_)
		{
			Node<T>* parentNode = node->p_;
			if (parentNode->left_ == node)
			{
				parentNode->left_ = nullptr;
				delete node;
			}
			else
			{
				parentNode->right_ = nullptr;
				delete node;
			}

		}
	}
}
template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key)  const
{
	return (iterativeSearchNode(key) != nullptr);
}
template <class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
	Node<T>* x = root_;
	if (x == nullptr)
	{
		return x;
	}
	while (x != nullptr && x->key_ != key) {
		if (key > x->key_) {
			x = x->right_;
		}
		else
			x = x->left_;
	}
	return x; 
}
template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	if (iterativeSearch(key))
	{
		std::cout << "Such a node already exists: " << key<<'\n';
		return false;
	}
	Node<T> * m = new Node<T>(key);
	Node<T>* x = root_;
	if (x == nullptr) {
		root_ = m;
		return true;
	}
	while (x != nullptr) {
		if (key > x->key_) {
			m->p_ = x;
			if (x->right_ == nullptr)
			{
				x->right_ = m;
				return true;
			}
			x = x->right_;
		}
		else {
			if (x->left_ == nullptr)
			{
				m->p_ = x;
				x->left_ = m;
				return true;
			}
			x = x->left_;
		}
	}
	m->p_ = x;
	if (m->key_ < x->key_)
		x->left_ = m;
	else
		x->right_ = m;
	return true;
}
template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	Node <T>* x = root_;
	Node <T>* node = iterativeSearchNode(key);
	if (root_->key_ == key) {
		root_->left_->p_ = root_->right_;
		root_ = root_->right_;
	}
	if (!(iterativeSearch(key))) {
		std::cout << "Node with this value does not exist " <<  " \n";
		return false;
	}
	if (root_ == nullptr)
	{
		std::cout << "You can't delete a node from an empty tree\n";
		return false;
	}
	if (iterativeSearch(key))
	{
		if (node->left_ == nullptr && node->right_ == nullptr)
		{
			if (node->p_->left_ == node)
			{
				node->p_->left_ = nullptr;
				delete node;
				return true;
			}
			else if (node->p_->right_ == node)
			{
				node->p_->right_ = nullptr;
				delete node;
				return true;
			}
		}
		if (node->left_ != nullptr && node->right_ != nullptr)
		{
			Node<T>* y = node->right_;
			Node<T>* current = nullptr;
			if (y->left_ == nullptr)
				current = y;
			else
			{
				while (y != nullptr)
				{
					current = y;
					y = y->left_;
				}
			}
			if (node->p_->left_ == node)
			{
				current->p_->right_ = nullptr;
				current->p_ = nullptr;

				node->p_->left_ = current;
				current->p_ = node->p_;
				node->p_ = nullptr;

				node->left_->p_ = current;
				current->left_ = node->left_;
				node->left_ = nullptr;

				if (node->right_ != nullptr)
				{
					current->right_ = node->right_;
					node->right_->p_ = current;
					node->right_ = nullptr;
				}
				delete node;
				return true;
			}
			else if (node->p_->right_ == node)
			{
				current->p_->left_ = nullptr;
				current->p_ = nullptr;

				node->p_->right_ = current;
				current->p_ = node->p_;
				node->p_ = nullptr;

				node->left_->p_ = current;
				current->left_ = node->left_;
				node->left_ = nullptr;

				if (node->right_ != nullptr)
				{
					current->right_ = node->right_;
					node->right_->p_ = current;
					node->right_ = nullptr;
				}
				delete node;
				return true;
			}
		}
		if (node->left_ != nullptr || node->right_ != nullptr)
		{
			if (node->left_ != nullptr)
			{
				if (node->p_->left_ == node)
				{
					node->p_->left_ = node->left_;
					delete node;
					return true;
				}
				else if (node->p_->right_ == node)
				{
					node->p_->right_ = node->left_;
					delete node;
					return true;
				}
			}
			else if (node->right_ != nullptr)
			{
				if (node->p_->left_ == node)
				{
					node->p_->left_ = node->right_;
					delete node;
					return true;
				}
				else if (node->p_->right_ == node)
				{
					node->p_->right_ = node->right_;
					delete node;
					return true;
				}
			}
		}
	}
}
template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
	printNode(out, root_);
	out << std::endl;
}
template<class T>
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
	return ( getHeightSubTree(this->root_));
}
template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
{
	int count_right = 0;
	int count_left = 0;
	if (node == nullptr)
		return 0;
	count_right = getHeightSubTree(node->right_) + 1;
	count_left = getHeightSubTree(node->left_) + 1;
	if (count_right > count_left)
		return count_right;
	else
		return count_left;
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
	if (node != nullptr) {
		inorderWalk(node->left_);
		std::cout << '(' << node->key_ << ')';
		inorderWalk(node->right_);
	}
}
template<class T>
bool BinarySearchTree<T>::equalSubTree(const Node<T>* x, const Node<T>* y) const
{
	if (x == nullptr && y == nullptr)
		return true;
	else if (x == nullptr || y == nullptr)
		return false;
	else if (x->key_ != y->key_)
		return false;
	else if (x->key_ == y->key_)
	{
		return (equalSubTree(x->left_, y->left_) && equalSubTree(x->right_, y->right_));
	}
}
template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	std::stack<Node<T>*> stack;
	Node<T>* root(root_);
	while (root != nullptr || !stack.empty()) {
		while (root != nullptr) {
			stack.push(root);
			root = root->left_;
		}
		if (stack.size() == 0) {
			return;
		}
		root = stack.top();
		stack.pop();
		std::cout << root->key_ << " ";
		root = root->right_;
	}
}
template <class T>
bool BinarySearchTree<T>::operator== (const BinarySearchTree <T>& src)
{
	if (root_ == nullptr && src.root_ == nullptr)
		return true;
	else if (root_ == nullptr || src.root_ == nullptr)
		return false;
	return (equalSubTree(src.root_->left_, root_->left_) && equalSubTree(src.root_->right_, root_->right_));
}

#endif