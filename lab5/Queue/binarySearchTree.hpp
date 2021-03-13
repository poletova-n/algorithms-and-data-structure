#ifndef BINARYSEARCHTREE_HPP_
#define BINARYSEARCHTREE_HPP_

#include <iostream>
#include <stdexcept>

#include "queueArray.hpp"
#include "stackArray.hpp"

template<class T>
class BinarySearchTree
{
public:

  BinarySearchTree();

  BinarySearchTree(const BinarySearchTree<T> &scr) = delete;

  BinarySearchTree(BinarySearchTree<T> &&scr) noexcept;

  BinarySearchTree<T> &operator=(const BinarySearchTree<T> &src) = delete;

  BinarySearchTree<T> &operator=(BinarySearchTree<T> &&src) noexcept; //СДЕЛАНО

  virtual ~BinarySearchTree();

  bool iterativeSearch(const T &key) const;

  bool insert(const T &key);

  bool deleteKey(const T &key);

  void print(std::ostream &out) const;

  int getCount() const;

  int getHeight() const;

  void iterativeInorderWalk() const;

  void inorderWalk() const;
  void horizontalPass() const;
  bool operator==(const BinarySearchTree<T> &src);
  BinarySearchTree<T> rValue();
  bool similarTree(const BinarySearchTree<T> &src);
private:

  template<typename T1>
  struct Node
  {
    T1 key_;
    Node<T1> *left_;
    Node<T1> *right_;
    Node<T1> *p_;
    explicit Node(T1 key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr) :
      key_(key), left_(left), right_(right), p_(p)
    {
    }
  };
  Node<T> *root_;

  void deleteSubtree(Node<T> *node);

  Node<T> *searchMinNode(Node<T> *node) const;

  Node<T> *iterativeSearchNode(const T &key) const;

  void printNode(std::ostream &out, Node<T> *root) const;

  int getCountSubTree(const Node<T> *node) const;

  int getHeightSubTree(Node<T> *node) const;

  void inorderWalk(Node<T> *node) const;

};

template<class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  deleteSubtree(root_);
  root_ = nullptr;
  delete root_;
}

template<class T>
bool BinarySearchTree<T>::iterativeSearch(const T &key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<class T>
void BinarySearchTree<T>::print(std::ostream &out) const
{
  printNode(out, root_);
  out << std::endl;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream &out, Node<T> *root) const
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

template<class T>
int BinarySearchTree<T>::getCount() const
{
  return getCountSubTree(this->root_);
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(const Node<T> *node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) +
    getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeight() const
{
  return getHeightSubTree(this->root_);
}

template<class T>
void BinarySearchTree<T>::inorderWalk(Node<T> *node) const
{
  if (node != nullptr)
  {
    inorderWalk(node->left_);
    std::cout << node->key_ << " ";
    inorderWalk(node->right_);
  }
}

template<typename T>

typename BinarySearchTree<T>::
template Node<T> *BinarySearchTree<T>::iterativeSearchNode(const T &key) const
{
  Node<T> *head = root_;
  if (head == nullptr)
  {
    return head;
  }
  while (head != nullptr && head->key_ != key)
  {
    if (key > head->key_)
      head = head->right_;
    else if (key < head->key_)

      head = head->left_;
  }
  return head;
}

template<typename T>
bool BinarySearchTree<T>::insert(const T &key)
{
  if (iterativeSearch(key))
  {
    std::cout << "Node with the key = " << key << " field already exists\n";
    return false;
  }
  auto *tempNode = new Node<T>(key);
  Node<T> *head = root_;
  if (head == nullptr)
  {
    root_ = tempNode;
    return true;
  }

  while (head != nullptr)
  {
    if (tempNode->key_ < head->key_)
    {
      if (head->left_ == nullptr)
      {
        tempNode->p_ = head;
        head->left_ = tempNode;
        return true;
      }
      head = head->left_;
    } else if (tempNode->key_ > head->key_)
    {
      tempNode->p_ = head;
      if (head->right_ == nullptr)
      {
        head->right_ = tempNode;
        return true;
      }
      head = head->right_;
    }
  }
  tempNode->p_ = head;
  if (tempNode->key_ < head->key_)
    head->left_ = tempNode;
  else
    head->right_ = tempNode;
  return true;
}

template<class T>
void BinarySearchTree<T>::deleteSubtree(BinarySearchTree::Node<T> *node) //
{
  if (node != nullptr)
  {
    deleteSubtree(node->left_);
    deleteSubtree(node->right_);
    if (node != root_)
    {
      Node<T> *parentNode = node->p_;
      if (parentNode->left_ == node)
      {
        parentNode->left_ = nullptr;
        delete node;
      } else
      {
        parentNode->right_ = nullptr;
        delete node;
      }

    } else
      delete node;
  }

}

template<class T>
void BinarySearchTree<T>::inorderWalk() const
{
  inorderWalk(root_);
}

template<class T>
void BinarySearchTree<T>::iterativeInorderWalk() const
{
  Node<T> *temp = root_;
  if (temp == nullptr)
  {
    std::cout << "Empty";
    return;
  }
  StackArray < Node<T> * > tempStack(getHeight() + 1);
  while (true)
  {
    if (temp != nullptr)
    {
      tempStack.push(temp);
      temp = temp->left_;
    } else
    {
      if (tempStack.isEmpty())
        break;
      else
      {
        temp = tempStack.top();
        tempStack.pop();
        std::cout << temp->key_ << " ";
        temp = temp->right_;
      }
    }
  }
/*  while(!tempStack.isEmpty())
  {
    tempStack.pop();
  }*/
}
template<class T>
bool BinarySearchTree<T>::deleteKey(const T &key)
{
  if (root_ == nullptr)
  {
    std::cout << "You can't delete a node from an empty tree\n";
    return false;
  }
  if (!iterativeSearch(key))
  {
    std::cout << "there is no node with the key = " << key << " field\n";
    return false;
  } else if (iterativeSearchNode(key) == root_)
  {
    std::cout << "You can't delete the root\n";
    return false;
  } else
  {
    Node<T> *deleteNode = iterativeSearchNode(key);
    Node<T> *parentNode = deleteNode->p_;
    if (deleteNode->left_ != nullptr && deleteNode->right_ != nullptr)
    {
      Node<T> *minNode = searchMinNode(deleteNode->right_);
      if (parentNode->left_ == deleteNode)
      {
        parentNode->left_ = minNode;
        if (minNode->right_ != nullptr)
        {
          minNode->left_ = deleteNode->left_;
          minNode->p_ = parentNode;
        } else
        {
          minNode->left_ = deleteNode->left_;
          minNode->p_ = parentNode;
        }
        delete deleteNode;
      } else
      {
        parentNode->right_ = minNode;
        if (minNode->right_ != nullptr)
        {
          minNode->left_ = deleteNode->left_;
          minNode->p_ = parentNode;
        } else
        {
          minNode->left_ = deleteNode->left_;
          minNode->right_ = nullptr;
          minNode->p_ = parentNode;
        }
        delete deleteNode;
      }
    } else if (deleteNode->right_ != nullptr)
    {
      Node<T> *nextNode = deleteNode->right_;
      if (parentNode->right_ == deleteNode)
      {
        parentNode->right_ = nextNode;
        nextNode->p_ = parentNode;
      } else
      {
        parentNode->left_ = nextNode;
        nextNode->p_ = parentNode;
      }
      delete deleteNode;
    } else if (deleteNode->left_ != nullptr)
    {
      Node<T> *nextNode = deleteNode->left_;
      if (parentNode->right_ == deleteNode)
      {
        parentNode->right_ = nextNode;
        nextNode->p_ = parentNode;
      } else
      {
        parentNode->left_ = nextNode;
        nextNode->p_ = parentNode;
      }
      delete deleteNode;
    } else
    {
      if (parentNode->right_ == deleteNode)
        parentNode->right_ = nullptr;
      else
        parentNode->left_ = nullptr;
      delete deleteNode;
    }
  }
  return true;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T> &&scr) noexcept
{
  this->root_ = scr.root_;
  scr.root_ = nullptr;
}
template<class T>
int BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node<T> *node) const
{
  int countLeft = 1, countRight = 1;
  if (node == nullptr)
    return 0;
  else
  {
    if (node->left_ != nullptr)
    {
      countLeft = getHeightSubTree(node->left_) + 1;
    } else
      countLeft--;
    if (node->right_ != nullptr)
      countRight = getHeightSubTree(node->right_) + 1;
    else
      countRight--;
  }

  return (std::max(countLeft, countRight));
}
template<class T>
bool BinarySearchTree<T>::operator==(const BinarySearchTree<T> &src)
{
  StackArray < Node<T> * > tempStack(std::max(getCount(), src.getCount()));
  StackArray < Node<T> * > thisTreeStack(getCount());
  StackArray < Node<T> * > srcTreeStack(src.getCount());
  Node<T> *thisNode = root_;
  Node<T> *srcNode = src.root_;
  while (true)
  {
    if (thisNode != nullptr)
    {
      tempStack.push(thisNode);
      thisTreeStack.push(thisNode);
      thisNode = thisNode->left_;
    } else
    {
      if (tempStack.isEmpty())
        break;
      else
      {
        thisNode = tempStack.top();
        tempStack.pop();
        thisNode = thisNode->right_;
      }
    }
  }
  while (true)
  {
    if (srcNode != nullptr)
    {
      tempStack.push(srcNode);
      srcTreeStack.push(srcNode);
      srcNode = srcNode->left_;
    } else
    {
      if (tempStack.isEmpty())
        break;
      else
      {
        srcNode = tempStack.top();
        tempStack.pop();
        srcNode = srcNode->right_;
      }
    }
  }
  std::cout << std::endl;
  if (!thisTreeStack.isEmpty())
    return false;
  while (!thisTreeStack.isEmpty() && !srcTreeStack.isEmpty())
  {
    Node<T> *thisTreeStackTop = thisTreeStack.top();
    Node<T> *srcTreeStackTop = srcTreeStack.top();
    if (thisTreeStackTop->key_ != srcTreeStackTop->key_)
    {
      return false;
    }
    thisTreeStack.pop();
    srcTreeStack.pop();
  }
  return true;
}
template<class T>
BinarySearchTree<T> &BinarySearchTree<T>::operator=(BinarySearchTree<T> &&src) noexcept
{
  if (root_ == src.root_)
    std::cout << "The same tree is passed\n";
  root_ = src.root_;
  src.root_ = nullptr;
  return *this;
}
template<class T>
BinarySearchTree<T> BinarySearchTree<T>::rValue()
{
  return (std::move(*this));
}
template<class T>
typename BinarySearchTree<T>::
template Node<T> *BinarySearchTree<T>::searchMinNode(BinarySearchTree::Node<T> *node) const
{
  Node<T> *minNode = node;
  while (minNode->left_ != nullptr)
  {
    if (minNode->left_ == nullptr)
      break;
    minNode = minNode->left_;
  }
  return minNode;
}
template<class T>
bool BinarySearchTree<T>::similarTree(const BinarySearchTree<T> &src)
{
  if (root_ == nullptr && src.root_ != nullptr || root_ != nullptr && src.root_ == nullptr)
    return false;
  if (root_ == nullptr && src.root_ == nullptr)
    return true;
  StackArray < Node<T> * > tempStack(std::max(getHeight() + 1, src.getHeight() + 1));
  StackArray<T> thisKeys(getCount());
  StackArray<T> srcKeys(src.getCount());
  Node<T> *temp = root_;
  while (true)
  {
    if (temp != nullptr)
    {
      tempStack.push(temp);
      temp = temp->left_;
    } else
    {
      if (tempStack.isEmpty())
        break;
      else
      {
        temp = tempStack.top();
        tempStack.pop();
        thisKeys.push(temp->key_);
        temp = temp->right_;
      }
    }
  }
  temp = src.root_;
  while (true)
  {
    if (temp != nullptr)
    {
      tempStack.push(temp);
      temp = temp->left_;
    } else
    {
      if (tempStack.isEmpty())
        break;
      else
      {
        temp = tempStack.top();
        tempStack.pop();
        srcKeys.push(temp->key_);
        temp = temp->right_;
      }
    }
  }
  while (!srcKeys.isEmpty() && !thisKeys.isEmpty() && srcKeys.top() == thisKeys.top())
  {
    srcKeys.pop();
    thisKeys.pop();
  }
  if (srcKeys.isEmpty() && thisKeys.isEmpty())
    return true;
  while(!srcKeys.isEmpty())
  {
    srcKeys.pop();
  }
  while(!thisKeys.isEmpty())
  {
    thisKeys.pop();
  }
  return false;
}
template<class T>
void BinarySearchTree<T>::horizontalPass() const
{
  if (root_ == nullptr)
  {
    std::cout << "Empty";
    return;
  }
  QueueArray<Node<T> *> tempQueue(getCount());
  Node<T> *temp = root_;
  tempQueue.enQueue(temp);
  while (true)
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
    if (tempQueue.isEmpty())
      break;
  }
}
#endif
