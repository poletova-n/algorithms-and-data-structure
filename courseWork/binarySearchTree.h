#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
template <class T>
class BinarySearchTree
{
private:
	template <class T>
	struct Word
	{
		std::string key_; // значение ключа, содержащееся в узле
		int count_;       // количество упоминаний слова
		Word<T>* left_;   // указатель на левое поддерево
		Word<T>* right_;  // указатель на правое поддерево
		Word<T>* p_;      // указатель на родителя
		// Конструктор узла
		Word(std::string key, int count = 1, Word* left = nullptr, Word* right = nullptr, Word* p = nullptr) :
			key_(key), count_(count), left_(left), right_(right), p_(p)
		{ }
	};
	// Дерево реализовано в виде указателя на корневой узел.
	Word<T>* root_;
	void deleteSubtree(Word<T>* node);
	size_t getCountSubTree(Word<T>* node) const;
	Word<T>* iterativeSearchNode(const std::string& key) const;

public:
	// Конструктор
	// "по умолчанию" создает пустое дерево
	BinarySearchTree();
	virtual ~BinarySearchTree();
	// 1.1 Функция поиска по ключу в бинарном дереве поиска
	bool iterativeSearch(const std::string& key) const;
	// 2 Вставка нового элемента в дерево: true,если элемент добавлен; false, если элемент уже был
	bool insert(const std::string& key);
	// 3.1 Удаление элемента из дерева, не нарушающее порядка элементов
	// true,если элемент удален; false, если элемента не было
	bool deleteKey(const std::string& key);
	// 5.1 Определение количества узлов дерева
	size_t getCount() const;
	// 7 Инфиксный обход дерева (итеративный)
	std::string* iterativeInorderWalk() const;
	int getRepeatCount(const std::string& key);
	void mostRepeated();
};


template<class T>
BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteSubtree(root_);
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const std::string& key) const
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
bool BinarySearchTree<T>::insert(const std::string& key)
{
	if (this->iterativeSearch(key) == 1)
	{
		this->iterativeSearchNode(key)->count_++;
		return true;
	}
	if (this->root_ == nullptr)
	{
		root_ = new Word<T>(key);
		return true;
	}
	Word<T>* temp;
	temp = this->root_;
	int size = this->getCount();
	for (int i = 0;i < size + 1;i++)
	{
		if ((temp->left_ == nullptr) || (temp->right_ == nullptr))
		{
			if (key < temp->key_)
			{
				if (temp->left_ != nullptr)
				{
					temp = temp->left_;
					continue;
				}
				temp->left_ = new Word<T>(key);
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
				temp->right_ = new Word<T>(key);
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
size_t BinarySearchTree<T>::getCountSubTree(Word<T>* node) const
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
std::string* BinarySearchTree<T>::iterativeInorderWalk() const
{
	std::cout << "-----------In alphabetical order--------\n";
	std::cout << "             WORD           REPEAT COUNT\n";
	std::cout << "----------------------------------------\n";
	if (!this->root_)
	{
		std::cout << "Tree is empty\n";
		return nullptr;
	}
	int i = 0;
	Word<T>* temp;
	temp = root_;
	std::stack<Word<T>*> treeStack;
	std::string* tempArray = new std::string[this->getCount()];
	while (temp != nullptr || !treeStack.empty())
	{
		if (temp != nullptr)
		{
			treeStack.push(temp);
			temp = temp->left_;
		}
		else
		{
			temp = treeStack.top();
			treeStack.pop();
			std::cout << std::setw(17) << temp->key_ << "           " << temp->count_ << "\n";
			tempArray[i] = temp->key_;
			i++;
			temp = temp->right_;
		}
	}
	std::cout << "\n";
	return tempArray;
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(Word<T>* node)
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
bool BinarySearchTree<T>::deleteKey(const std::string& key)
{
	if (root_ == nullptr)
	{
		return false;
	}
	if (this->iterativeSearch(key) == false)
	{
		return false;
	}
	Word<T>* keyNode;
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

	if ((keyNode == root_) && ((keyNode->left_ != nullptr || keyNode->right_ != nullptr) && (!(keyNode->left_ != nullptr && keyNode->right_ != nullptr))))
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

	if ((keyNode->left_ != nullptr || keyNode->right_ != nullptr) && (!(keyNode->left_ != nullptr && keyNode->right_ != nullptr)))
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
		Word<T>* temp = keyNode;
		if (keyNode->right_->left_ != nullptr)
		{
			temp = temp->right_;
		}
		while (temp->left_ != nullptr && temp->right_ != nullptr)
		{
			temp = temp->left_;
		}
		keyNode->key_ = temp->key_;
		temp->p_->left_ = nullptr;
		return true;
	}
	return false;
}

template<class T>
BinarySearchTree<T>::Word<T>* BinarySearchTree<T>::iterativeSearchNode(const std::string& key) const
{
	if (root_ == nullptr)
	{
		return root_;
	}
	std::string tempKey = key;
	int lenght = key.length();
	Word<T>* temp = root_;
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
int BinarySearchTree<T>::getRepeatCount(const std::string& key)
{
	return iterativeSearchNode(key)->count_;
}

template<class T>
void BinarySearchTree<T>::mostRepeated()
{
	Word<T>* array[3] = {};
	if (!this->root_)
	{
		std::cout << "Tree is empty\n\n";
		return;
	}
	else if ((this->root_->left_) && (!this->root_->right_)|| (!this->root_->left_) && (this->root_->right_))
	{
		std::cout << "Only to words were given\n\n";
		return;
	}
	std::cout << "------------Most repeated words------------\n";
	Word<T>* temp;
	std::queue<Word<T>*> tempQueue;
	tempQueue.push(root_);
	while (!(tempQueue.empty()))
	{
		temp = tempQueue.front();
		tempQueue.pop();
		if (array[0] == nullptr)
	  {
	  array[0] = temp;
		}
		else if (temp->count_ >= array[0]->count_)
		{
			array[2] = array[1];
			array[1] = array[0];
			array[0] = temp;
		}
		else if (array[1] == nullptr)
		{
			array[1] = temp;
		}
		else if (temp->count_ >= array[1]->count_)
		{
			array[2] = array[1];
			array[1] = temp;
		}
		else if (array[2] == nullptr || temp->count_ >= array[2]->count_)
		{
			array[2] = temp;
		}
		if (temp->left_ != nullptr)
		{
			tempQueue.push(temp->left_);
		}
		if (temp->right_ != nullptr)
		{
			tempQueue.push(temp->right_);
		}
	}
	std::cout << "Word: " << array[0]->key_ << "  repeat count: " << array[0]->count_ << "\n";
	std::cout << "Word: " << array[1]->key_ << "  repeat count: " << array[1]->count_ << "\n";
	std::cout << "Word: " << array[2]->key_ << "  repeat count: " << array[2]->count_ << "\n\n";
}

#endif 
