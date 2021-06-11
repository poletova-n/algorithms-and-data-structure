#include <iostream>
#include <algorithm>

template<class T>
class Tree
{
private:
  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    Node* parent_;

    Node(T key, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) :
      key_(key), left_(left), right_(right), parent_(parent)
    {}
  };

  Node* root_;

  void swap(Tree<T>& left, Tree<T>& right) noexcept;
  void deleteSubtree(Node* node);
  Node* iterativeSearchNode(const T& key) const;
  void printNode(std::ostream& out, Node* root) const;
  int getCountSubTree(const Node* node) const;
  int getHeightSubTree(Node* node) const;
  void copyNodes(const Node* root);

public:
  Tree();
  Tree(const Tree<T>& src);
  Tree(Tree<T>&& src) noexcept;
  Tree <T>& operator= (const Tree<T>& src);
  Tree <T>& operator= (Tree<T>&& src) noexcept;
  virtual ~Tree();
  bool iterativeSearch(const T& key) const;
  T nextNode(const T& key) const;
  void insert(const T& value);
  bool deleteKey(const T& key);
  void print(std::ostream& out) const;
  int getCount() const;
  int getHeight() const;
};

template<class T>
Tree<T>::Tree()
{
  root_ = nullptr;
}

template<class T>
Tree<T>::Tree(const Tree<T>& src)
{
  root_ = nullptr;
  copyNodes(src.root_);
}

template<class T>
Tree<T>::Tree(Tree<T>&& src) noexcept
{
  Tree<T> temp(src);
  swap(*this, temp);
  src.root_ = nullptr;
}

template<class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& src)
{
  root_ = nullptr;
  copyNodes(src.root_);

  return *this;
}

template<class T>
Tree<T>& Tree<T>::operator=(Tree<T>&& src) noexcept
{
  Tree<T> temp(src);
  swap(*this, temp);
  src.root_ = nullptr;

  return *this;
}

template<class T>
Tree<T>::~Tree()
{
  deleteSubtree(this->root_);
}

template<class T>
inline void Tree<T>::swap(Tree<T>& left, Tree<T>& right) noexcept
{
  std::swap(left.root_, right.root_);
}

template<class T>
void Tree<T>::deleteSubtree(Node* node)
{
  if (node != nullptr)
  {
    deleteSubtree(node->left_);
    deleteSubtree(node->right_);
    delete node;
  }
  else
  {
    return;
  }
}

template<class T>
typename Tree<T>::Node* Tree<T>::iterativeSearchNode(const T& key) const
{
  Node* t = this->root_;
  while (t)
  {
    if (key == t->key_) return t;

    if (key > t->key_) t = t->right_;
    else t = t->left_;
  }

  return nullptr;
}

template<class T>
void Tree<T>::printNode(std::ostream& out, Node* root) const
{
  if (root != nullptr)
  {
    out << " ";

    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);

    out << " ";
  }
}

template<class T>
int Tree<T>::getCountSubTree(const Node* node) const
{
  if (node == nullptr) return 0;

  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}

template<class T>
int Tree<T>::getHeightSubTree(Node* node) const
{
  if (node == nullptr) return 0;
  return 1 + std::max(getHeightSubTree(node->left_), getHeightSubTree(node->right_));
}

template<class T>
T Tree<T>::nextNode(const T& key) const
{
  Node* current = root_;

  while (current != nullptr)
  {
    if (current->key_ == key)
    {
      if (current->left_ != nullptr)
      {
        return current->left_->key_;
      }
      else if (current->right_ != nullptr)
      {
        return current->right_->key_;
      }
      else
      {
        return key;
      }
    }
    if (current->key_ < key)
    {
      current = current->right_;
    }
    else if (current->key_ > key)
    {
      current = current->left_;
    }
  }

  return current->key_;
}

template<class T>
void Tree<T>::copyNodes(const Node* root)
{
  if (root == nullptr) return;
  this->insert(root->key_);
  copyNodes(root->left_);
  copyNodes(root->right_);
}

template<class T>
bool Tree<T>::iterativeSearch(const T& key) const
{
  Node* t = this->iterativeSearchNode(key);

  if (t == nullptr)
  {
    return false;
  }
  else
  {
    return true;
  }
}

template<class T>
void Tree<T>::insert(const T& value)
{
  if (root_ == nullptr)
  {
    root_ = new Node(value);
    return;
  }
  else
  {
    Node* current = root_;
    Node* temp = current;

    if (current->key_ == value)
    {
      return;
    }

    while (current != nullptr)
    {
      temp = current;
      if (value < current->key_)
      {
        current = current->left_;
      }
      else if (value > current->key_)
      {
        current = current->right_;
      }
    }
    if (temp->key_ < value)
    {
      temp->right_ = new Node(value);
    }
    else
    {
      temp->left_ = new Node(value);
    }
  }
}

template<class T>
bool Tree<T>::deleteKey(const T& key)
{
  Node* node = iterativeSearchNode(key);
  if (node == nullptr)
  {
    return false;
  }
  if ((node->left_ == nullptr) && (node->right_ == nullptr))
  {
    if (node->parent_ == nullptr)
    {
      root_ = nullptr;
      delete node;
      return true;
    }
    else
    {
      if ((node->parent_->left_ != nullptr) && (node->parent_->left_->key_ == node->key_))
      {
        node->parent_->left_ = nullptr;
        delete node;
        return true;
      }
      if ((node->parent_->right_ != nullptr) && (node->parent_->right_->key_ == node->key_))
      {
        node->parent_->right_ = nullptr;
        delete node;
        return true;
      }
    }
  }
  else if (((node->left_ != nullptr) && (node->right_ == nullptr)))
  {
    if (node->parent_ == nullptr)
    {
      node->left_->parent_ = nullptr;
      root_ = node->left_;
      delete node;
      return true;
    }
    else
    {
      if ((node->parent_->left_ != nullptr) && (node->parent_->left_->key_ == node->key_))
      {
        node->left_->parent_ = node->parent_;
        node->parent_->left_ = node->left_;
        delete node;
        return true;
      }
      if ((node->parent_->right_ != nullptr) && (node->parent_->right_->key_ == node->key_))
      {
        node->left_->parent_ = node->parent_;
        node->parent_->right_ = node->left_;
        delete node;
        return true;
      }
    }
  }
  else if (((node->left_ == nullptr) && (node->right_ != nullptr)))
  {
    if (node->parent_ == nullptr)
    {
      node->right_->parent_ = nullptr;
      root_ = node->right_;
      delete node;
      return true;
    }
    else
    {
      if ((node->parent_->left_ != nullptr) && (node->parent_->left_->key_ == node->key_))
      {
        node->right_->parent_ = node->parent_;
        node->parent_->left_ = node->right_;
        delete node;
        return true;
      }
      if ((node->parent_->right_ != nullptr) && (node->parent_->right_->key_ == node->key_))
      {
        node->right_->parent_ = node->parent_;
        node->parent_->right_ = node->right_;
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
    if ((currentNode->parent_->left_ != nullptr) && (currentNode->parent_->left_->key_ == currentNode->key_))
    {
      currentNode->parent_->left_ = currentNode->right_;
      if (currentNode->right_ != nullptr)
      {
        currentNode->right_->parent_ = currentNode->parent_;
      }
    }
    if ((currentNode->parent_->right_ != nullptr) && (currentNode->parent_->right_->key_ == currentNode->key_))
    {
      currentNode->parent_->right_ = currentNode->right_;
      if (currentNode->right_ != nullptr)
      {
        currentNode->right_->parent_ = currentNode->parent_;
      }
    }
    node->key_ = currentNode->key_;
    delete currentNode;
    return true;
  }
  return false;
}

template<class T>
void Tree<T>::print(std::ostream& out) const
{
  this->printNode(out, root_);
  out << std::endl;
}

template<class T>
int Tree<T>::getCount() const
{
  return this->getCountSubTree(this->root_);
}

template<class T>
int Tree<T>::getHeight() const
{
  return this->getHeightSubTree(this->root_);
}
