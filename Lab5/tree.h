#include <iostream>

#include "queue.h"
#include "queueArray.h"
#include "queueException.h"
#include "stackArray.h"
#include "stackOverflow.h"
#include "stackUnderflow.h"
#include "wrongStackSize.h"

template<class T>
class Tree
{
private:
  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;

    Node(T key, Node* left = nullptr, Node* right = nullptr) :
      key_(key), left_(left), right_(right)
    {}
  };

  Node* root_;

  void swap(Tree<T>& left, Tree<T>& right) noexcept;
  void deleteSubtree(Node* node);
  Node* iterativeSearchNode(const T& key) const;
  void printNode(std::ostream& out, Node* root) const;
  int getCountSubTree(const Node* node) const;
  int getHeightSubTree(Node* node) const;
  Node* nextNode(const T& key);
  void copyNodes(const Node* root);

public:
  Tree();
  Tree(const Tree<T>& src);
  Tree(Tree<T>&& src) noexcept;
  Tree <T>& operator= (const Tree<T>& src);
  Tree <T>& operator= (Tree<T>&& src);
  virtual ~Tree();
  bool iterativeSearch(const T& key) const;
  void insert(const T& value);
  bool deleteKey(const T& key);
  void print(std::ostream& out) const;
  int getCount() const;
  int getHeight() const;
  void breadthFirstWalk() const;
  T* iterativeInorderWalk(bool mode) const;
  bool isSimilar(const Tree<T>&) const;
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
Tree<T>& Tree<T>::operator=(Tree<T>&& src)
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
void Tree<T>::swap(Tree<T>& left, Tree<T>& right) noexcept
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
    else
    {
      t = t->left_;
    }
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
  return 1 + Max(getHeightSubTree(node->left_), getHeightSubTree(node->right_));
}

template<class T>
typename Tree<T>::Node* Tree<T>::nextNode(const T& key)
{
  Node* t = this->root_;
  Node* ans = nullptr;

  while (t)
  {
    if (t->key_ > key)
    {
      ans = t;
      t = t->left_;
    }
    else t = t->right_;
  }

  return ans;
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
  if (t == nullptr) return false;

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
  if (!this->iterativeSearch(key)) return false;

  Node* t = this->root_;
  Node* del = nullptr;

  while (t)
  {
    if (t->key_ == key)
    {
      del = t;
      break;
    }
    if (key > t->key_)
    {
      if (t->right_ != nullptr && key == t->right_->key_)
      {
        del = t->right_;
        break;
      }
      else t = t->right_;
    }
    else
    {
      if (t->left_ != nullptr && key == t->left_->key_)
      {
        del = t->left_;
        break;
      }
      else t = t->left_;
    }
  }

  if (del->right_ != nullptr && del->left_ != nullptr)
  {
    Node* nxt = this->nextNode(del->key_);
    T k = nxt->key_;
    if (nxt->left_ == nullptr && nxt->right_ == nullptr)
    {
      this->deleteKey(k);
      nxt = new Node(k);
    }
    if (this->root_->key_ == key)
    {
      this->root_->key_ = k;
      return true;
    }
    nxt->right_ = del->right_;
    nxt->left_ = del->left_;
    if (t->left_ != nullptr && del->key_ == t->left_->key_) t->left_ = nxt;
    else t->right_ = nxt;

    delete del;
  }
  else
  {
    if (del->right_ != nullptr)
    {
      if (t->right_ != nullptr && t->right_->key_ == del->key_) t->right_ = del->right_;
      else t->left_ = del->right_;
      delete del;
    }
    else if (del->left_ != nullptr)
    {
      if (t->left_ != nullptr && t->left_->key_ == del->key_)t->left_ = del->left_;
      else t->right_ = del->left_;
      delete del;
    }
    else
    {
      if (t->left_ != nullptr && t->left_->key_ == del->key_)
      {
        t->left_ = nullptr;
        delete del;
      }
      else
      {
        t->right_ = nullptr;
        delete del;
      }
    }
  }

  return true;
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

template <class T>
T* Tree<T>::iterativeInorderWalk(bool mode) const
{
  StackArray<Node*> stack(getCount());
  Node* temp = root_;
  int index = 0;
  T* arr = new T[getCount()];

  while ((!stack.isEmpty()) || (temp != nullptr))
  {
    if (temp != nullptr)
    {
      stack.push(temp);
      temp = temp->left_;
    }
    else
    {
      temp = stack.top();
      stack.pop();
      arr[index] = temp->key_;
      index++;
      if (mode)
      {
        std::cout << " ";
        std::cout << temp->key_;
        std::cout << " ";
      }
      temp = temp->right_;
    }
  }

  std::cout << "\n";
  return arr;
}

template<class T>
void Tree<T>::breadthFirstWalk() const
{
  QueueArray<Node*> tempQueue(getCount());
  Node* temp = root_;

  if (root_ == nullptr)
  {
    std::cout << "Empty tree\n";
  }
  else
  {
    tempQueue.enQueue(temp);
    while (!tempQueue.isEmpty())
    {
      temp = tempQueue.deQueue();
      std::cout << temp->key_ << " ";
      if (temp->left_ != nullptr)
      {
        tempQueue.enQueue(temp->left_);
      }
      if (temp->right_ != nullptr)
      {
        tempQueue.enQueue(temp->right_);
      }
    }
    std::cout << "\n";
  }
}

template<class T>
bool Tree<T>::isSimilar(const Tree<T>& src) const
{
  int size = getCount();
  int size2 = src.getCount();

  T* arr = this->iterativeInorderWalk(false);
  T* arr2 = src.iterativeInorderWalk(false);

  if (size == size2)
  {
    for (int i = 0; i < size; i++)
    {
      if (arr[i] != arr2[i])
      {
        return false;
      }
    }

    return true;
  }

  return false;
}
