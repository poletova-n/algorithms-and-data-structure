#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include <iostream>

template <class T>
class BinarySearchTree
{
private:
  struct Node
  {
    T key_;
    Node* left_;
    Node* right_;
    int num_;
  };
  Node* root_;
  int curNum;

  Node* ReturnNodePrivate(T key, Node* ptr)
  {
    if (ptr != nullptr)
    {
      if (ptr->key_ == key)
      {
        return ptr;
      }
      else
      {
        if (key < ptr->key_)
        {
          return ReturnNodePrivate(key, ptr->left_);
        }
        if (key > ptr->key_)
        {
          return ReturnNodePrivate(key, ptr->right_);
        }
      }
    }
    else
    {
      return nullptr;
    }

  }

  Node* CreateLeaf(T key, int num)
  {
    Node* n = new Node;
    n->key_ = key;
    n->left_ = nullptr;
    n->right_ = nullptr;
    n->num_ = num;

    return n;
  }


  Node* GetSuccessorPrivate(T key, Node* ptr)
  {
    Node* cur = ReturnNode(key);
    if (cur == nullptr)
    {
      return nullptr;
    }
    if (cur->right_ != nullptr)
    {
      return FindMin(cur->right_);
    }
    else
    {
      Node* successor = nullptr;
      Node* ancestor = ptr;
      while (ancestor != nullptr)
      {
        if (cur->key_ == ancestor->key_)
        {
          successor = ancestor->left_;
          return successor;
        }
        else
          ancestor = ancestor->right_;
      }
    }
  }

  void printNode(std::ostream& out, Node* root) const
  {
    out << '(';
    if (root) {
      out << root->key_;
      printNode(out, root->left_);
      printNode(out, root->right_);
    }
    out << ')';
  }


  void levelOrderTraversalPrivate(Node* root);
  void preOrderTraversalPrivate(Node* root);
  void inOrderTraversalPrivate(Node* root);

  void AddLeafPrivate(T key, Node* ptr);
  void PrintInOrderPrivate(Node* ptr);
  T FindSmallestPrivate(Node* ptr);
  void RemoveNodePrivate(T key, Node* p_);
  void RemoveRootMatch();
  void RemoveMatch(Node* parent, Node* match, bool left_);
  void RemoveSubtree(Node* ptr);

  int getCountSubTree(Node* node) const;

  int getHeightSubTree(Node* root_) const;

public:
  BinarySearchTree() : root_(nullptr) {};
  ~BinarySearchTree();

  void AddLeaf(T key);
  void PrintInOrder();
  T ReturnRootKey();
  void PrintChildren(T key);
  T FindSmallest();
  void RemoveNode(T key);
  void printInfo(int num);
  bool isIdentical(const BinarySearchTree<T>& src);
  T* inOrderSortage() const;

  Node* ReturnNode(T key)
  {
    return ReturnNodePrivate(key, root_);
  }

  Node* FindMin(Node* root_)
  {
    if (root_ == nullptr)
      return nullptr;
    while (root_->left_ != nullptr)
    {
      root_ = root_->left_;
    }
    return root_;
  }
  Node* GetSuccessor(T key)
  {
    return GetSuccessorPrivate(key, root_);
  }

  bool iterativeSearch(const T& key)
  {
    return (ReturnNodePrivate(key, root_) != nullptr);
  }

  int getCount() const
  {
    return getCountSubTree(this->root_);
  }

  int getHeight() const
  {
    return getHeightSubTree(this->root_);
  }

  void print(std::ostream& out) const
  {
    printNode(out, root_);
    out << std::endl;
  }
void levelOrderTraversal()
{
  levelOrderTraversalPrivate(root_);
}

void preOrderTraversal()
{
  preOrderTraversalPrivate(root_);
}

void inOrderTraversal()
{
  inOrderTraversalPrivate(root_);
}
};


template<class T>
void BinarySearchTree<T>::levelOrderTraversalPrivate(Node* root)
{
  QueueList<Node*> queue;
  queue.enQueue(root);
  while (!queue.isEmpty())
  {
    Node* cur = queue.getFront();
    queue.deQueue();
    std::cout << cur->key_ << ' ';
    if (cur->left_ != nullptr)
    {
      queue.enQueue(cur->left_);
    }
    if (cur->right_ != nullptr)
    {
      queue.enQueue(cur->right_);
    }
  }
}

template<class T>
void BinarySearchTree<T>::preOrderTraversalPrivate(Node* root)
{
  StackList<Node*> stack;
  stack.push(root);

  while (!stack.isEmpty())
  {
    Node* cur = stack.peek();
    std::cout << cur->key_ << " ";
    stack.pop();
    if (cur->right_ != nullptr)
      stack.push(cur->right_);
    if (cur->left_ != nullptr)
      stack.push(cur->left_);
  }
}

template<class T>
void BinarySearchTree<T>::inOrderTraversalPrivate(Node* root)
{
  StackList<Node*> stack;
  Node* cur = root;

  while (!stack.isEmpty() || cur != nullptr)
  {
    if (cur != nullptr)
    {
      stack.push(cur);
      cur = cur->left_;
    }
    else
    {
      cur = stack.peek();
      stack.pop();
      std::cout << cur->key_ << " ";
      cur = cur->right_;
    }
  }
}

template<class T>
void BinarySearchTree<T>::AddLeafPrivate(T key, Node* ptr)
{
  if (root_ == nullptr)
  {
    curNum++;
    root_ = CreateLeaf(key, curNum);
  }
  else if (key < ptr->key_)
  {
    if (ptr->left_ != nullptr)
    {
      AddLeafPrivate(key, ptr->left_);
    }
    else
    {
      curNum++;
      ptr->left_ = CreateLeaf(key, curNum);
    }
  }
  else if (key > ptr->key_)
  {
    if (ptr->right_ != nullptr)
    {
      AddLeafPrivate(key, ptr->right_);
    }
    else
    {
      curNum++;
      ptr->right_ = CreateLeaf(key, curNum);
    }
  }
  else
  {
    std::cout << "\nThe key " << key << " has already been added to the tree. \n";
  }
}

template<class T>
void BinarySearchTree<T>::PrintInOrderPrivate(Node* ptr)
{
  if (root_ != nullptr)
  {
    if (ptr->left_ != nullptr)
    {
      PrintInOrderPrivate(ptr->left_);
    }
    std::cout << ptr->key_ << " ";
    if (ptr->right_ != nullptr)
    {
      PrintInOrderPrivate(ptr->right_);
    }
  }
  else
  {
    std::cout << "\nThe tree is empty.\n";
  }

}

template<class T>
T BinarySearchTree<T>::FindSmallestPrivate(Node* ptr)
{
  if (root_ == nullptr)
  {
    std::cout << "\nThe tree is empty\n";
    return -1;
  }
  else
  {
    if (ptr->left_ != nullptr)
    {
      return FindSmallestPrivate(ptr->left_);
    }
    else
    {
      return ptr->key_;
    }
  }
}

template<class T>
void BinarySearchTree<T>::RemoveNodePrivate(T key, Node* parent)
{
  if (root_ != nullptr)
  {
    if (root_->key_ == key)
    {
      RemoveRootMatch();
    }
    else
    {
      if (key < parent->key_ && parent->left_ != nullptr)
      {
        parent->left_->key_ == key ? RemoveMatch(parent, parent->left_, true) : RemoveNodePrivate(key, parent->left_);
      }
      else if (key > parent->key_ && parent->right_ != nullptr)
      {
        parent->right_->key_ == key ? RemoveMatch(parent, parent->right_, false) : RemoveNodePrivate(key, parent->right_);
      }
      else
      {
        std::cout << "\nThe key " << key << " was not found in the tree";
      }
    }
  }
  else
  {
    std::cout << "\nThe tree is empty\n";
  }
}

template<class T>
void BinarySearchTree<T>::RemoveRootMatch()
{
  if (root_ != nullptr)
  {
    Node* delPtr = root_;
    T rootKey = root_->key_;
    T smallestInRightSubtree;
    if (root_->left_ == nullptr && root_->right_ == nullptr)
    {
      root_ = nullptr;
      delete delPtr;
    }
    else if (root_->left_ == nullptr && root_->right_ != nullptr)
    {
      root_ = root_->right_;
      delPtr->right_ = nullptr;
      delete delPtr;
      std::cout << "\nThe root node with key " << rootKey << " was deleted.The new root contains key " << root_->key_ << std::endl;

    }
    else if (root_->right_ == nullptr && root_->left_ != nullptr)
    {
      root_ = root_->left_;
      delPtr->left_ = nullptr;
      delete delPtr;
      std::cout << "\nThe root node with key " << rootKey << " was deleted.The new root contains key " << root_->key_ << std::endl;
    }
    else
    {
      smallestInRightSubtree = FindSmallestPrivate(root_->right_);
      RemoveNodePrivate(smallestInRightSubtree, root_);
      root_->key_ = smallestInRightSubtree;
      std::cout << "\nThe root key containing key " << rootKey << " was overwritten with key " << root_->key_ << std::endl;
    }
  }
  else
  {
    std::cout << "\nCannot remove the root. The tree is empty\n ";
  }
}

template<class T>
void BinarySearchTree<T>::RemoveMatch(Node* parent, Node* match, bool left_)
{
  if (root_ != nullptr)
  {
    Node* delPtr;
    T matchKey = match->key_;
    T smallestInRightSubtree;

    if (match->left_ == nullptr && match->right_ == nullptr)
    {
      delPtr = match;
      left_ == true ? parent->left_ = nullptr : parent->right_ = nullptr;
      delete delPtr;
      std::cout << "\nThe node containing key " << matchKey << " was removed";
    }
    else if (match->left_ == nullptr && match->right_ != nullptr)
    {
      left_ == true ? parent->left_ = match->right_ : parent->right_ = match->right_;
      match->right_ = nullptr;
      delPtr = match;
      delete delPtr;
      std::cout << "\nThe node containing key " << matchKey << " was removed";
    }
    else if (match->left_ != nullptr && match->right_ == nullptr)
    {
      left_ == true ? parent->left_ = match->left_ : parent->right_ = match->left_;
      match->left_ = nullptr;
      delPtr = match;
      delete delPtr;
      std::cout << "\nThe node containing key " << matchKey << "was removed";
    }
    else
    {
      smallestInRightSubtree = FindSmallestPrivate(match->right_);
      RemoveNodePrivate(smallestInRightSubtree, match);
      match->key_ = smallestInRightSubtree;
    }
  }
  else
  {
    std::cout << "\nCannot remove match. The tree is empty.\n";
  }
}


template<class T>
void BinarySearchTree<T>::RemoveSubtree(Node* ptr)
{
  if (ptr != nullptr)
  {
    if (ptr->left_ != nullptr)
    {
      RemoveSubtree(ptr->left_);
    }
    if (ptr->right_ != nullptr)
    {
      RemoveSubtree(ptr->right_);
    }
    delete ptr;
  }
}

template<class T>
int BinarySearchTree<T>::getCountSubTree(Node* node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) +
    getCountSubTree(node->right_));
}

template<class T>
int BinarySearchTree<T>::getHeightSubTree(Node* root_) const
{
  if (root_ == nullptr)
    return 0;
  else
  {
    int lh = getHeightSubTree(root_->left_);
    int rh = getHeightSubTree(root_->right_);
    if (lh > rh)
      return (lh + 1);
    else return (rh + 1);
  }
}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  RemoveSubtree(root_);
}

template<class T>
void BinarySearchTree<T>::AddLeaf(T key)
{
  AddLeafPrivate(key, root_);
}

template<class T>
void BinarySearchTree<T>::PrintInOrder()
{
  PrintInOrderPrivate(root_);
}

template<class T>
T BinarySearchTree<T>::ReturnRootKey()
{
  return root_->key_;
}

template<class T>
void BinarySearchTree<T>::PrintChildren(T key)
{
  Node* ptr = ReturnNode(key);

  if (ptr != nullptr)
  {
    std::cout << "\nParent Node = " << ptr->key_ << std::endl;
    if (ptr->left_ == nullptr)
    {
      std::cout << "Left  Child = nullptr \n";
    }
    else
    {
      std::cout << "Left  Child = " << ptr->left_->key_ << std::endl;
    }
    if (ptr->right_ == nullptr)
    {
      std::cout << "Right Child = nullptr \n";
    }
    else
    {
      std::cout << "Right Child = " << ptr->right_->key_ << std::endl;
    }
  }
  else
  {
    std::cout << "\nKey " << key << "is not in the tree\n";
  }
}

template<class T>
T BinarySearchTree<T>::FindSmallest()
{
  return FindSmallestPrivate(root_);
}

template<class T>
void BinarySearchTree<T>::RemoveNode(T key)
{
  RemoveNodePrivate(key, root_);
}

template<class T>
void BinarySearchTree<T>::printInfo(int num)
{
  printNode(root_, num);
}


template<class T>
bool BinarySearchTree<T>::isIdentical(const BinarySearchTree<T>& src)
{
  if (this->getCount() != src.getCount())
  {
    return false;
  }
  T* firstArray = this->inOrderSortage();
  T* secondArray = src.inOrderSortage();
  for (int i = 0; i < getCount(); i++)
  {
    if (firstArray[i] != secondArray[i])
    {
      return false;
    }
  }
  return true;
}\


template<class T>
T* BinarySearchTree<T>::inOrderSortage() const
{
  if (!this->root_)
  {
    std::cout << "The tree is empty\n";
    return nullptr;
  }
  int i = 0;
  Node* temp = root_;
  StackArray<Node*> stack(this->getCount());
  T* sortedArray = new T[this->getCount()];
  while (temp != nullptr || !stack.isEmpty())
  {
    if (temp != nullptr)
    {
      stack.push(temp);
      temp = temp->left_;
    }
    else
    {
      temp = stack.peek();
      stack.pop();
      sortedArray[i] = temp->key_;
      i++;
      temp = temp->right_;
    }
  }
  std::cout << "\n";
  return sortedArray;
}

#endif
