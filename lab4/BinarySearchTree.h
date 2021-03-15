#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>
template <class T>
class BinarySearchTree
{
private:
	// Описание структуры узла со ссылками на детей
	template <class T>
	struct Node
	{
		T key_; // значение ключа, содержащееся в узле
		Node<T>* left_; // указатель на левое поддерево
		Node<T>* right_; // указатель на правое поддерево
		Node<T>* p_; // указатель на родителя !!! не используется
		// Конструктор узла
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ }
	};
	// Дерево реализовано в виде указателя на корневой узел.
	Node<T>* root_;
	void swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right);
	void deleteSubtree(Node<T>* node);
	size_t getCountSubTree(Node<T>* node) const;
	int getHeightSubTree(Node<T>* node) const;
	void inorderWalk(Node<T>* node) const;
	void printNode(std::ostream& out, Node<T>* root) const;
	Node<T>* iterativeSearchNode(const T& key) const;
	bool isSubtreeEqual(Node<T>* temp1, Node<T>* temp2);

public:
	// Конструкторы
	// "по умолчанию" создает пустое дерево
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& scr) = delete;
	BinarySearchTree(BinarySearchTree<T>&& scr) noexcept;
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete;
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept;
	virtual ~BinarySearchTree();
	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const T& key) const;
	// 2 Вставка нового элемента в дерево: true,если элемент добавлен; false, если элемент уже был
	bool insert(const T& key);
	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const T& key);
	// 4.1 Печать строкового изображения дерева в выходной поток out
	void print(std::ostream& out) const;
	// 5.1 Определение количества узлов дерева
	size_t getCount() const;
	// 6.1 Определение высоты дерева
	int getHeight() const;
	// 7 Инфиксный обход дерева (итеративный)
	void iterativeInorderWalk() const;
	// 8.1 Инфиксный обход дерева (рекурсивный)
	void inorderWalk() const;
	// 9 Сравнение деревьев: true, если все узлы деревьев одинаковые
	bool operator== (const BinarySearchTree <T>& src);
};


template<class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) noexcept
{
	this->root_ = src.root_;
	src.root_ = nullptr;
}

template<class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src) noexcept
{
	if (&src == this)
	{
		return *this;
	}
	delete root_;
	root_ = src.root_;
	src.root_ = nullptr;
	return *this;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteSubtree(root_);
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const
{
	if (this->iterativeSearchNode(key) != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
bool BinarySearchTree<T>::insert(const T& key)
{
	if (this->iterativeSearch(key) == 1)
	{
		return false;
	}
	if (this->root_ == nullptr)
	{
		root_ = new Node<T>(key);
		return true;
	}
	Node<T>* temp;
	temp = this->root_;
	int size = this->getCount();
	for (int i = 0;i <size+1;i++)
	{
		if ((temp->left_ == nullptr) || (temp->right_ == nullptr))
		{
			if (key < temp->key_)
			{
				if (temp->left_!=nullptr)
				{
					temp = temp->left_;
					continue;
				}
				temp->left_ = new Node<T>(key);
				temp->left_->p_ = temp;
				return true;
			}
			if (key > temp->key_)
			{
				if (temp->right_ != nullptr)
				{
					temp = temp->right_;
					continue;
				}
				temp->right_ = new Node<T>(key);
				temp->right_->p_ = temp;
				return true;
			}
		}
		else if (key < temp->key_)
		{
			temp = temp->left_;
		}
		else if (key > temp->key_)
		{
			temp = temp->right_;
		}
	}
	return false;
}

template<class T>
size_t BinarySearchTree<T>::getCountSubTree(Node<T>* node) const
{
	if (node == nullptr) {
		return 0;
	}
	return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
size_t BinarySearchTree<T>::getCount() const
{
	return getCountSubTree(this->root_);
}

template<class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const
{
	if (node != nullptr)
	{
		inorderWalk(node->left_);
		std::cout << node->key_ << "   ";
		inorderWalk(node->right_);
	}
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
	inorderWalk(root_);
	std::cout << "\n";
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
	Node<T>* temp;
	temp = root_;
	std::stack<Node<T>*> treeStack;
	while (temp != nullptr || !treeStack.empty())
	{
		while (temp != nullptr)
		{
			treeStack.push(temp);
			temp = temp->left_;
		}
		while (!treeStack.empty())
		{
			temp = treeStack.top();
			treeStack.pop();
			std::cout << temp->key_ << "   ";
		  temp = temp->right_;
		}
	}
	std::cout << "\n";
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(Node<T>* node) const
{
	int counterLeft = 0;
	int counterRight = 0;
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		if (node->left_)
		{
			counterLeft = getHeightSubTree(node->left_) + 1;
		}
		if (node->right_)
		{
			counterRight = getHeightSubTree(node->right_) + 1;
		}
	}
	if (counterLeft > counterRight)
	{
		return counterLeft;
	}
	else
	{
		return counterRight;
	}
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
	return getHeightSubTree(this->root_);
}


template<class T>
void BinarySearchTree<T>::swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right)
{
	Node<T>* temp = left.root_;
	left.root_ = right.root_;
	right.root_ = temp;
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(Node<T>* node)
{
	if (node != nullptr)
	{
		if (node->left_ != nullptr)
			deleteSubtree(node->left_);
		if (node->right_ != nullptr)
			deleteSubtree(node->right_);
		delete node;
	}
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root) const
{
	if (root != nullptr)
	{
		out << root->key_;
		out << "   ";
		printNode(out, root->left_);
		printNode(out, root->right_);
	}
}

template<class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
	if (root_==nullptr)
	{
		return false;
	}
	if (this->iterativeSearch(key)==false)
	{
		return false;
	}
	Node<T>* keyNode;
	keyNode = iterativeSearchNode(key);

	if (keyNode->left_ == nullptr && keyNode->right_ == nullptr)
	{
		if (keyNode->key_ < keyNode->p_->key_)
		{
			keyNode->p_->left_ = nullptr;
		}
		else
		{
			keyNode->p_->right_ = nullptr;
		}
		delete keyNode;
		return true;
	}

	if ((keyNode==root_)&& ((keyNode->left_ != nullptr || keyNode->right_ != nullptr) && (!(keyNode->left_ != nullptr && keyNode->right_ != nullptr))))
	{
		if (keyNode->left_ != nullptr && keyNode->right_ == nullptr)
		{
			root_ = keyNode->left_;
			keyNode->left_->p_ = nullptr;
			return true;
		}
		if (keyNode->right_ != nullptr && keyNode->left_ == nullptr)
		{
			root_ = keyNode->right_;
			keyNode->right_->p_ = nullptr;
			return true;
		}
	}

	if ((keyNode->left_ != nullptr || keyNode->right_ != nullptr)&&(!(keyNode->left_ != nullptr && keyNode->right_ != nullptr)))
	{
		if (keyNode->left_ != nullptr && keyNode->right_ == nullptr)
		{
			if (keyNode->key_ < keyNode->p_->key_)
			{
				keyNode->p_->left_ = keyNode->left_;
				delete keyNode;
				return true;
			}
			else
			{
				keyNode->p_->right_ = keyNode->left_;
				delete keyNode;
				return true;
			}
		}
		if (keyNode->right_ != nullptr && keyNode->left_ == nullptr)
		{
			if (keyNode->key_ < keyNode->p_->key_)
			{
				keyNode->p_->left_ = keyNode->right_;
				delete keyNode;
				return true;
			}
			else
			{
				keyNode->p_->right_ = keyNode->right_;
				delete keyNode;
				return true;
			}
		}
	}

	if (keyNode->left_ != nullptr && keyNode->right_ != nullptr)
	{
		Node<T>* temp = keyNode;
		if (keyNode->right_->left_ != nullptr)
		{
			temp = temp->right_;
		}
		while (temp->left_ != nullptr && temp->right_ != nullptr)
		{
			temp=temp->left_;
		}
		keyNode->key_ = temp->key_;
		temp->p_->left_ = nullptr;
		return true;
	}
	return false;
}

template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
	printNode(out, root_);
	out << "\n";
}

template<class T>
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
if (root_ == nullptr)
	{
		return root_;
	}
Node<T>* temp;
temp = root_;
while (true)
{
	if (temp == nullptr)
	{	
		return nullptr;
	}
	if (key == temp->key_)
	{
		return temp;
	}
	if (key < temp->key_)
	{
		temp = temp->left_;
		continue;
	}
	if (key > temp->key_)
	{
		temp = temp->right_;
		continue;
	}
}
return temp;
}

template<class T>
bool BinarySearchTree<T>::isSubtreeEqual(Node<T>* temp1, Node<T>* temp2)
{
	if (temp1 == nullptr || temp2 == nullptr)
	{
		return (temp1 == temp2);
	}
		bool leftSubtree = isSubtreeEqual(temp1->left_, temp2->left_);
		bool rightSubtree = isSubtreeEqual(temp1->right_, temp2->right_);
		return ((temp1->key_ == temp2->key_) && leftSubtree && rightSubtree);
}


template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T>& src)
{
	if (this->getCount() != src.getCount())
	{
		return false;
	}
	if (this->root_ == nullptr && src.root_ == nullptr)
	{
		return true;
	}	
	if (this->root_ == nullptr || src.root_ == nullptr)
	{
		return false;
	}
	return (isSubtreeEqual(this->root_,src.root_));
}


#endif