#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>

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
  
  // 1.1 Функция поиска по ключу в бинарном дереве поиска
  bool iterativeSearch(const T& key) const;
  
  // 2 Вставка нового элемента в дерево: true,если элемент добавлен; false, если элемент уже был
  bool insert(const T& key);
  
  // 3.1 Удаление элемента из дерева, не нарушающее порядка элементов: true,если элемент удален; false, если элемента не было
  bool deleteKey(const T& key);
  
  // 4.1 Печать строкового изображения дерева в выходной поток out
  void print(std::ostream& out) const;
  
  // 5.1 Определение количества узлов дерева
  int getCount() const;
  
  // 6.1 Определение высоты дерева
  int getHeight() const;
  
  // 7 Инфиксный обход дерева (итеративный) 
  void iterativeInorderWalk () const;
  
  // 8.1 Инфиксный обход дерева (рекурсивный) 
  void inorderWalk() const;
  
  // 9 Сравнение деревьев: true, если все узлы деревьев одинаковые
  bool operator== (const BinarySearchTree <T>& src);

  

private:
  // Описание структуры узла со ссылками на детей и родителя
  struct Node
  {
	T key_;         // значение ключа, содержащееся в узле
	Node* left_;     // указатель на левое поддерево
	Node* right_;    // указатель на правое поддерево
	Node* p_;        // указатель на  родителя 
						 
	Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
	  key_(key),
	  left_(left),
	  right_(right),
	  p_(p)
	{
	}
  };
  
  // Дерево реализовано в виде указателя на корневой узел.
  Node* root_;
  
  void swap(BinarySearchTree<T>& left, BinarySearchTree<T>& right);
  
  // Рекурсивная функция для освобождения памяти
  void deleteSubtree(Node* node);
  
  // 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
  Node* iterativeSearchNode(const T& key) const;
  
  // 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
  void printNode(std::ostream& out, Node* root) const;
  
  // 5.2 Рекурсивная функция определения количества узлов дерева
  int getCountSubTree(const Node* node) const;
  
  // 6.2 Рекурсивная функция определения высоты дерева
  int getHeightSubTree(Node* node) const;

  // 8.2 Рекурсивная функция для организации обхода узлов дерева.
  void inorderWalk(Node* node) const;

  bool walk2(Node* node1, Node* node2);

  T getMinKey(Node* node) const;
};
   
// Конструктор "по умолчанию" создает пустое дерево
template <class T>
BinarySearchTree<T>::BinarySearchTree(): root_(nullptr)
{
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src):
  root_(src.root_)
{
  src.root_ = nullptr;
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src)
{
  root_ = src.root_;
  src.root_ = nullptr;
}

// Деструктор освобождает память, занятую узлами дерева
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  //std::cout << "del: ";
  deleteSubtree(root_);
}

// Рекурсивная функция для освобождения памяти
template <class T>
void BinarySearchTree<T>::deleteSubtree(Node* node)
{
  if (node == nullptr)
	return;
  deleteSubtree(node->right_);
  deleteSubtree(node->left_);
  if (node->left_ == nullptr && node->right_ == nullptr)
  {
	if (node != root_)
	{
	  if (node == node->p_->right_)
		node->p_->right_ = nullptr;
	  else if (node == node->p_->left_)
		node->p_->left_ = nullptr;
	}
	//std::cout << node->key_ << " ";
	delete node;
	return;
  }
}

template <class T>
void BinarySearchTree<T>::swap(BinarySearchTree <T>& left, BinarySearchTree <T>& right)
{
  std::swap(left.root_, right.root_);
}

// 1.1 Функция поиска по ключу в бинарном дереве поиска
template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key)  const
{
  return (iterativeSearchNode(key) != nullptr);
}

// 1.2 Функция поиска адреса узла по ключу в бинарном дереве поиска
template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  if (root_ == nullptr)
	return nullptr;
  Node* current = root_;
  while (current != nullptr && current->key_ != key)
  {
	if (key > current->key_)
	  current = current->right_;
	else if (key < current->key_)
	  current = current->left_;
  }
  return current;
}
	
// 2. Вставка нового элемента в дерево: true,если элемент добавлен; false, если элемент уже был
template <class T>
bool BinarySearchTree<T>::insert(const T& key)
{
  if (root_ == nullptr)
  {
	Node* newNode = new Node(key);
	root_ = newNode;
	return true;
  }
  else if (iterativeSearch(key) == true)
	return false;
  else
  {
	Node* newNode = new Node(key);
	Node* current = root_;
	while (true)
	{
	  if (key > current->key_)
	  {
		if (current->right_ != nullptr)
		  current = current->right_;
		else
		  break;
	  }
	  else if (key < current->key_)
	  {
		if (current->left_ != nullptr)
		  current = current->left_;
		else
		  break;
	  }
	}
	if (key > current->key_)
	  current->right_ = newNode;
	else
	  current->left_ = newNode;
	newNode->p_ = current;
	return true;
  }
}

// 3. Удаление элемента из дерева, не нарушающее порядка элементов
template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key)
{
  if (iterativeSearch(key) == 0)
	return false;
  Node* delNode = iterativeSearchNode(key);
  if (delNode->left_ == nullptr && delNode->right_ == nullptr)
  {
	if (delNode == delNode->p_->right_)
	  delNode->p_->right_ = delNode->right_;
	else
	  delNode->p_->left_ = delNode->right_;
	delete delNode;
  }
  else if (delNode->left_ == nullptr && delNode->right_ != nullptr)
  {
	if(delNode == delNode->p_->right_)
	  delNode->p_->right_ = delNode->right_;
	else
	  delNode->p_->left_ = delNode->right_;
	delNode->right_->p_ = delNode->p_;
	delete delNode;
  }
  else if (delNode->left_ != nullptr && delNode->right_ == nullptr)
  {
	if (delNode == delNode->p_->right_)
	  delNode->p_->right_ = delNode->left_;
	else
	  delNode->p_->left_ = delNode->left_;
	delNode->left_->p_ = delNode->p_;
	delete delNode;
  }
  else
  {
	T minKey = getMinKey(delNode->right_);
	deleteKey(minKey);
	delNode->key_ = minKey;
  }
  return true;
}

// 4.1 Печать строкового изображения дерева в выходной поток out
template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printNode(out, root_);
  out << std::endl;
}

// 4.2 Рекурсивная функция для вывода изображения дерева в выходной поток
template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node* root) const
{
  // Изображение дерева заключается в круглые скобки.
  out << '(';
  if (root != nullptr) {
	// Для узлов дерева должна быть определена (или переопределена)
	// операция вывода в выходной поток <<
	out << root->key_;
	printNode(out, root->left_);
	printNode(out, root->right_);
  }
  out << ')';
}

//5.1 Определение количества узлов дерева
template <class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

// 5.2 Рекурсивная функция определения количества узлов дерева
template <class T>
int BinarySearchTree<T>::getCountSubTree(const Node* node) const
{
  if (node == nullptr)
	return 0;
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

// 6.1 Определение высоты дерева
template <class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

// 6.2 Рекурсивная функция определения высоты дерева
template <class T>
int BinarySearchTree<T>::getHeightSubTree(Node* node) const
{
  if (node == nullptr)
	return 0;
  return std::max(getHeightSubTree(node->left_) + 1, getHeightSubTree(node->right_) + 1);
}

// 7. Инфиксный обход дерева (итеративный) 
template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
  std::stack<Node*> stack;
  Node* current = root_;
  while (stack.size() != 0 || current != nullptr)
  {
	if (current != nullptr)
	{
	  stack.push(current);
	  current = current->left_;
	}
	else
	{
	  current = stack.top();
	  stack.pop();
	  std::cout << current->key_ << " ";
	  current = current->right_;
	}
  }
}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
  inorderWalk(root_);
}
	
// 8.1 Инфиксный обход дерева (рекурсивный) 
template <class T>
void BinarySearchTree<T>::inorderWalk(Node* node) const
{
  if (node != nullptr)
  {
	inorderWalk(node->left_);
	std::cout << node->key_ << " ";
	inorderWalk(node->right_);
  }
}

// 9. Сравнение деревьев: true, если все узлы деревьев одинаковые
template <class T>
bool BinarySearchTree<T>::operator== (const BinarySearchTree <T>& src)
{
  return walk2(root_, src.root_);
}

template<class T>
bool BinarySearchTree<T>::walk2(Node* node1, Node* node2)
{
  if (node1 == nullptr)
  {
	if (node2 != nullptr)
	  return false;
	else
	  return true;
  }
  if (node2 == nullptr)
  {
	if (node1 != nullptr)
	  return false;
	else
	  return true;
  }
  return (node1->key_ == node2->key_) && (walk2(node1->left_, node2->left_)) && (walk2(node1->right_, node2->right_));
}

template<class T>
T BinarySearchTree<T>::getMinKey(Node* node) const
{
  while (node->left_ != nullptr)
	node = node->left_;
  return node->key_;
}

#endif /* BINARY_SEARCH_TREE_H */
