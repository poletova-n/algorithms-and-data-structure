#include "BinarySearchTree.h"

template<class T>
inline void Tree<T>::swap(Tree<T>& left, Tree<T>& right) noexcept
{
  std::swap(left.root_, right.root_);
}

template<class T>
void Tree<T>::deleteSubtree(Node<T>* node)
{
  if (node == nullptr) return;
  deleteSubtree(node->left_);
  deleteSubtree(node->right_);
  free(node);
}

template<class T>
Tree<T>::Node<T>* Tree<T>::iterativeSearchNode(const T& key) const
{
  Node<T>* t = this->root_;
  while (t)
  {
    if (key == t->key_) return t;

    if (key > t->key_) t = t->right_;
    else t = t->left_;
  }
  return nullptr;
}

template<class T>
void Tree<T>::printNode(std::ostream& out, Node<T>* root) const
{
  while (root != nullptr)
  {
    printNode(out, root->left_);
    out << root->key_ << " ";
    printNode(out, root->right_);
  }
}

template<class T>
int Tree<T>::getCountSubTree(const Node<T>* node) const
{
  if (node == nullptr) return 0;

  return (1 + getCountSubTree(node->left_) +
    getCountSubTree(node->right_));
}

template<class T>
int Tree<T>::getHeightSubTree(Node<T>* node) const
{
  if (node == nullptr) return 0;
  return 1 + Max(getHeightSubTree(node->left_), getHeightSubTree(node->right_));
}

template<class T>
Tree<T>::Node<T>* Tree<T>::nextNode(const T& key)
{
  Node<T>* t = this->root_;
  Node<T>* ans = nullptr;
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
void Tree<T>::copyNodes(const Node<T>* root)
{
  if (root == nullptr) return;
  this->insert(root->key_);
  copyNodes(root->left_);
  copyNodes(root->right_);
}

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
bool Tree<T>::iterativeSearch(const T& key) const
{
  Node<T>* t = this->iterativeSearchNode(key);
  if (t == nullptr) return false;
  else return true;
}

template<class T>
bool Tree<T>::insert(const T& key)
{
  if (root_ == nullptr)
  {
    root_ = new Node<T>(key);
    return true;
  }
  Node<T>* t = root_;
  while (t)
  {
    if (key > t->key_)
    {
      if (t->right_ == nullptr)
      {
        t->right_ = new Node<T>(key);
        return true;
      }
      else t = t->right_;
    }
    else
    {
      if (key == t->key_) return false;
      if (t->left_ == nullptr)
      {
        t->left_ = new Node<T>(key);
        return true;
      }
      else t = t->left_;
    }
  }
  return true;
}

template<class T>
bool Tree<T>::deleteKey(const T& key)
{
  if (!this->iterativeSearch(key)) return false;

  Node<T>* t = this->root_;
  Node<T>* del = nullptr;

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
    Node<T>* nxt = this->nextNode(del->key_);
    T k = nxt->key_;
    if (nxt->left_ == nullptr && nxt->right_ == nullptr)
    {
      this->deleteKey(k);
      nxt = new Node<T>(k);
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
  this->printNode(out, this->root_);
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