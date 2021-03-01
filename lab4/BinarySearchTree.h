#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <ostream>
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

	Node* searchMinNode(Node*) const;

	void swap(BinarySearchTree <T>&, BinarySearchTree <T>&);

	void deleteSubtree(Node*);

	void deleteRoot();

	void deleteFromTree(Node*);

	void printNode(std::ostream&, Node*) const;

	int getCountSubTree(const Node*) const;

	int getHeightSubtree(Node*) const;

	void inorderWalk(Node*) const;

	bool equalNode(const Node*, const Node*);
};

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

template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right)
{
	std::swap(left.root_, right.root_);
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(Node* node)
{
	delete iterativeSearchNode(node->key_);
}

template<class T>
void BinarySearchTree<T>::deleteRoot()
{
	if (root_ == nullptr) {
		std::cout << "The tree is empty!\n";
	}
	else {
		Node* temp = root_;

		if (root_->left_ == nullptr && root_->right_ == nullptr) {
			root_ = nullptr;
			delete temp;
		}
		else if (root_->left_ == nullptr && root_->right_ != nullptr) {
			root_ = root_->right_;
			temp->right_ = nullptr;
			delete temp;
		}
		else if (root_->left_ != nullptr && root_->right_ == nullptr) {
			root_ = root_->left_;
			temp->left_ = nullptr;
			delete temp;
		}
		else {
			T minRightSubtree;
			minRightSubtree = searchMinNode(root_->right_)->key_;
			deleteKey(minRightSubtree);
			root_->key_ = minRightSubtree;
		}
	}
}

template <class T>
void BinarySearchTree<T>::deleteFromTree(Node* node)
{
	Node* temp;

	if (node == nullptr) {
		std::cout << "The tree is empty\n";
	}

	else if (node->left_ == nullptr && node->right_ == nullptr)
	{
		temp = node;
		node = nullptr;
		delete temp;
	}

	else if (node->left_ == nullptr)
	{
		temp = node;
		node = node->right_;
		delete temp;
	}

	else if (node->right_ == nullptr)
	{
		temp = node;
		node = node->left_;
		delete temp;
	}

	else
	{
		Node* current;
		Node* trc;

		current = node->left_;
		trc = nullptr;
		while (current->right_ != nullptr)
		{
			trc = current;
			current = current->right_;
		}
		node->key_ = current->key_;
		if (trc == nullptr) {
			node->left_ = current->left_;
		}
		else {
			trc->right_ = current->left_;
		}
		delete current;
	}
}


template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::searchMinNode(Node* node) const
{
	if (node == nullptr) {
		return node;
	}
	if (node->left_ != nullptr) {
		return searchMinNode(node->left_);
	}

	return node;
}

template<class T>
int BinarySearchTree<T>::getHeightSubtree(Node* node) const
{
	if (node == 0 || (node->left_ == nullptr && node->right_ == nullptr))
		return 0;
	return 1 + std::max(getHeightSubtree(node->left_), getHeightSubtree(node->right_));
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


template<class T>
BinarySearchTree<T>::BinarySearchTree() :root_(nullptr) {}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)
{
	root_ = scr.root_;
	scr.root_ = nullptr;
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
void BinarySearchTree<T>::print(std::ostream& out) const
{
	printNode(out, root_);
	out << std::endl;
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
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	if (root_ == nullptr) {
		std::cout << " The tree is empty!\n";
		return false;
	}
	else {
		Node* current = root_;
		bool found = false;

		while (current != nullptr && !found)
		{
			if (current->key_ == key) {
				found = true;
			}
			else {
				if (current->key_ > key) {
					current = current->left_;
				}
				else {
					current = current->right_;
				}
			}
		}

		if (found) {
			if (current == root_) {
				deleteRoot();
			}
			else {
				deleteFromTree(current);
			}
			return true;
		}
		return false;
	}
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

template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
	if (node == nullptr) {
		return 0;
	}
	return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template <class T>
int BinarySearchTree<T>::getCount() const
{
	return getCountSubTree(this->root_);
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	return (iterativeSearchNode(key) != nullptr);
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeightSubtree(this->root_);
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
	inorderWalk(root_);
	std::cout << std::endl;
}

template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	std::stack<Node*> stack;
	Node* root = this->root_;
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
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
	if (node == nullptr) {
		return;
	}
	inorderWalk(node->left_);
	std::cout << node->key_ << " ";
	inorderWalk(node->right_);
}

template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T>& src)
{
	return BinarySearchTree<T>::equalNode(root_, src.root_);
}

#endif