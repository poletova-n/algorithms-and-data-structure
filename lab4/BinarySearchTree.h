#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T> & scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr);

	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src);

	virtual ~BinarySearchTree();
		
	bool iterativeSearch(const T& key) const;
	bool insert(const T& key);
	bool deleteKey(const T& key);
	

	void print(std::ostream& out) const;
	
	
	int getCount() const;
	int getHeight() const;
	
	void iterativeInorderWalk () const;
	void inorderWalk() const;

	bool operator== (const BinarySearchTree <T>& src);	

private:
	template <class T>
	struct Node {
		T  key_;      
		Node<T>* left_;     
		Node<T>* right_; 
						 
		Node(T key, Node* left = nullptr, Node* right = nullptr) :
			key_(key), left_(left), right_(right)
		{}
	};

	Node<T>* root_;

	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);
	Node<T>* insert(Node<T>* node, Node<T>* x);
	Node<T>* deleteNode(Node<T>* node, const T& key);
	void deleteSubtree(Node<T>* node);
	Node<T>* iterativeSearchNode(const T& key) const;
	void printNode(std::ostream& out, Node<T>* root) const;
	int getCountSubTree(const Node<T>* node) const;
	int getHeightSubTree(Node<T>* node) const;
	void iterativeInorderWalk(Node<T>* node) const;
	void inorderWalk(Node<T>* node) const;
	bool equalSubTree(const Node<T>* first, const Node<T>* second) const;
}; 

	template <class T>
	BinarySearchTree<T>::BinarySearchTree(): root_(nullptr){}
	
	template <class T>
	BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& scr)
	{
	  root_ = scr.root_;
	}
    
	template<class T>
	BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
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
	  delete iterativeSearchNode(node->key_);
	}

	template <class T>
	void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
	{
	  std::swap(left.root_, right.root_);
	}

	template <class T>
	bool BinarySearchTree<T>::iterativeSearch(const T& key) const
	{
		return (iterativeSearchNode(key)!=nullptr);
	}

	template <class T>
	BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
	{
	  if (root_ == nullptr)
		return root_;
	  Node<T>* tmp = root_;
	  while (tmp->key_ != key)
	  {
		if (key > tmp->key_)
		  tmp = tmp->right_;
		else if (key < tmp->key_)
		  tmp = tmp->left_;
		if (tmp == nullptr)
		  break;
	  }
	  return tmp;
	}

	template <class T>
	bool BinarySearchTree<T>::insert(const T& key)
	{
	  if (this->iterativeSearch(key))
	  {
		std::cout << "The item has already been added!\n";
		return false;
	  }
	  else
	  {
		Node<T>* tmp = new Node<T>(key);
		this->insert(tmp, root_);
		if (root_ == nullptr)
		  root_ = tmp;
		return true;
	  }
	}

	template <class T>
	 BinarySearchTree<T>:: Node<T>* BinarySearchTree<T>:: insert(Node<T>*node, Node<T>* x)
	{
	  if ( x == nullptr)
		x = node;
	  else
	  {
		if (node->key_ > x->key_)
		  x->right_=insert(node, x->right_);
		else
		  x->left_=insert(node, x->left_);
	  }
	  return x;
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
		root_=deleteNode(root_, key);
		return true;
	  }
	}

	template <class T>
	BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::deleteNode(Node<T>* node, const T& key)
	{
	  if (node == nullptr)
		return node;

	  if (key == node->key_)
	  {
		Node<T>* tmp;
		if (node->right_ == nullptr)
		  tmp = node->left_;
		else
		{
		  Node<T>* ptr = node->right_;
		  if (ptr->left_ == nullptr)
		  {
			ptr->left_ = node->left_;
			tmp = ptr;
		  }
		  else
		  {
			Node<T>* min = ptr->left_;
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
	void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
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
	  int right_height = getHeightSubTree(node->right_)+1;
	  int left_height = getHeightSubTree(node->left_)+1;
	  if (right_height > left_height)
	  {
		return right_height;
	  }
	  else
		return left_height;
	}
	 
	template <class T>
	void BinarySearchTree<T>::iterativeInorderWalk() const
	{ 
	  iterativeInorderWalk(root_);
	  std::cout << "\n";
	}

	template <class T>
	void BinarySearchTree<T>::iterativeInorderWalk(Node<T>* node) const
	{
	  if (node != nullptr)
	  {
		iterativeInorderWalk(node->left_);
		std::cout << node->key_ << " ";
		iterativeInorderWalk(node->right_);
	  }
	}

	template <class T>
	void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
	{
	  if (node != nullptr)
	  {
		std::cout << node->key_ << " ";
		iterativeInorderWalk(node->left_);
		iterativeInorderWalk(node->right_);
	  }
	}

	template<class T>
	bool BinarySearchTree<T>::equalSubTree(const Node<T>* first, const Node<T>* second) const 
	{
	  if (first == nullptr && second == nullptr)
		return true;
	  else if (first == nullptr || second == nullptr)
		return false;
	  else if (first->key_ != second->key_)
		return false;
	  else if (first->key_ == second->key_)
	  {
		return (equalSubTree(first->right_, second->right_) && equalSubTree(first->left_, second->left_));
	  }

	}

	template<class T>
     void BinarySearchTree<T>::inorderWalk() const
	{
	    inorderWalk(this->root_);
		std::cout << "\n";
	}

	template <class T>
	bool BinarySearchTree<T>::operator==(const BinarySearchTree <T>& src)
	{
	  if (src.root_ == nullptr && this->root_ == nullptr)
		return true;
	  else if (src.root_ == nullptr || this->root_ == nullptr)
		return false;
	  return equalSubTree(this->root_->right_, src.root_->right_) && equalSubTree(this->root_->left_, src.root_->left_);
	}
#endif
