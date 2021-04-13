#ifndef LAB4_BINARYSEARCHTREE_HPP
#define LAB4_BINARYSEARCHTREE_HPP

#include <ostream>

template <class T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    size_t size();
    size_t height();

    void addIterative(T element);

    void addRecursive(T element);

    void remove(T element);

    bool find(T element);

    void print(std::ostream& os = std::cout);

private:
    struct Node
    {
        T key_;
        Node* left_;
        Node* right_;
        Node* p_;

        explicit Node (T key, Node* p = nullptr):
                key_(key),
                left_(nullptr),
                right_(nullptr),
                p_(p)
        { }
    };

    Node* root_;

    size_t sizeSubtree(Node* start);
    size_t heightSubtree(Node* start);
    void printNode(Node* start, std::ostream& os);
    void removeSubtree(Node* start);
    Node* findMax(Node* start);
    Node* findNode(T element);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree():
        root_(nullptr)
{

}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  removeSubtree(root_);
}

template <class T>
size_t BinarySearchTree<T>::size()
{
  if (root_)
  {
    return sizeSubtree(root_);
  }
  else
  {
    return 0;
  }
}

template <class T>
size_t BinarySearchTree<T>::height()
{
  if (root_)
  {
    return 1 + heightSubtree(root_);
  }
  else
  {
    return 0;
  }
}

template <class T>
void BinarySearchTree<T>::addIterative(T element)
{
  if (root_ == nullptr)
  {
    root_ = new Node(element);
    return;
  }
  Node* current = root_;
  while (true)
  {
    if (element < current->key_ && current->left_ == nullptr)
    {
      current->left_ = new Node(element, current);
      return;
    }
    else if (element < current->key_)
    {
      current = current->left_;
    }
    if (element > current->key_ && current->right_ == nullptr)
    {
      current->right_ = new Node(element, current);
      return;
    }
    else if (element > current->key_)
    {
      current = current->right_;
    }
  }
}

template <class T>
void BinarySearchTree<T>::addRecursive(T element)
{
  if (root_ == nullptr)
  {
    root_ = new Node(element);
    return;
  }
  static Node* current = root_;
  if (element < current->key_ && current->left_ == nullptr)
  {
    current->left_ = new Node(element, current);
    return;
  }
  else if (element < current->key_)
  {
    current = current->left_;
    addRecursive(element);
    return;
  }
  if (element > current->key_ && current->right_ == nullptr)
  {
    current->right_ = new Node(element, current);
    return;
  }
  else if (element > current->key_)
  {
    current = current->right_;
    addRecursive(element);
    return;
  }
}

template <class T>
void BinarySearchTree<T>::remove(T element)
{
  Node* node = findNode(element);
  if (node == nullptr)
  {
    throw std::invalid_argument("element did not find.");
  }
  if (node->left_ == node->right_)
  {
    if (node == root_)
    {
      delete root_;
      root_ = nullptr;
    }
    else if (node == node->p_->left_)
    {
      Node* temp = node->p_;
      delete node;
      temp->left_ = nullptr;
    }
    else
    {
      Node* temp = node->p_;
      delete node;
      temp->right_ = nullptr;
    }
  }
  else if (node->left_ == nullptr || node->right_ == nullptr)
  {
    if (node->left_ && sizeSubtree(node->left_) == 1)
    {
      node->key_ = node->left_->key_;
      delete node->left_;
      node->left_ = nullptr;
    }
    else if (node->left_)
    {
      if (node == node->p_->left_)
      {
        node->p_->left_ = node->left_;
      }
      else if (node == node->p_->right_)
      {
        node->p_->right_ = node->left_;
      }
    }
    else if (node->right_ && sizeSubtree(node->right_) == 1)
    {
      node->key_ = node->right_->key_;
      delete node->right_;
      node->right_ = nullptr;
    }
    else if (node->right_)
    {
      if (node == node->p_->left_)
      {
        node->p_->left_ = node->right_;
      }
      else if (node == node->p_->right_)
      {
        node->p_->right_ = node->right_;
      }
    }
  }
  else
  {
    Node* temp = findMax(node->left_);
    T tempKey = temp->key_;
    remove(tempKey);
    node->key_ = tempKey;
  }
}

template <class T>
bool BinarySearchTree<T>::find(T element)
{
  return findNode(element);
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& os)
{
  printNode(root_, os);
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findNode(T element)
{
  Node* current = root_;
  if (current == nullptr || current->key_ == element)
  {
    return current;
  }
  while (current != nullptr)
  {
    if (element == current->key_)
    {
      return current;
    }
    else if (element > current->key_)
    {
      current = current->right_;
    }
    else if (element < current->key_)
    {
      current = current->left_;
    }
  }
  return nullptr;
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::findMax(Node* start)
{
  Node* current = start;
  while (true)
  {
    if (current->right_ == nullptr)
    {
      break;
    }
    current = current->right_;
  }
  return current;
}

template <class T>
void BinarySearchTree<T>::removeSubtree(BinarySearchTree<T>::Node* start)
{
  if (start->left_ || start->right_)
  {
    if (start->left_)
    {
      removeSubtree(start->left_);
      start->left_ = nullptr;
    }
    if (start->right_)
    {
      removeSubtree(start->right_);
      start->right_ = nullptr;
    }
  }
  else
  {
    delete start;
  }
}

template <class T>
void BinarySearchTree<T>::printNode(BinarySearchTree<T>::Node* start, std::ostream& os)
{
  if (start == root_)
  {
    os << "Root is " << start->key_ << "\n";
  }
  else
  {
    os << start->key_ << "\n";
  }
  if (start->left_ != start->right_)
  {
    if (start->left_)
    {
      os << "Left kid of " << start->key_ << " is ";
      printNode(start->left_, os);
    }
    if (start->right_)
    {
      os << "Right kid of " << start->key_ << " is ";
      printNode(start->right_, os);
    }
  }
}

template <class T>
size_t BinarySearchTree<T>::sizeSubtree(BinarySearchTree<T>::Node* start)
{
  size_t count = 0;
  if (start->right_ || start->left_)
  {
    if (start->right_)
    {
      count += sizeSubtree(start->right_);
    }
    if (start->left_)
    {
      count += sizeSubtree(start->left_);
    }
  }
  count += start ? 1 : 0;
  return count;
}

template <class T>
size_t BinarySearchTree<T>::heightSubtree(BinarySearchTree<T>::Node* start)
{
  size_t right = 0;
  size_t left = 0;
  if (start->right_ || start->left_)
  {
    if (start->right_)
    {
      right += 1 + heightSubtree(start->right_);
    }
    if (start->left_)
    {
      left += 1 + heightSubtree(start->left_);
    }
  }
  return right > left ? right : left;
}

#endif

