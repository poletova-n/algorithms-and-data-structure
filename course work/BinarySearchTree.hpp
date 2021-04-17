#ifndef LAB4_BINARYSEARCHTREE_HPP
#define LAB4_BINARYSEARCHTREE_HPP

#include <string>
#include <list>
#include <vector>

template<class T>
class BinarySearchTree
{
public:
  BinarySearchTree();
  ~BinarySearchTree();
  void insert(T value);
  bool searchNode(const T& key) const;
  void print(std::ostream& out) const;
  void printTree(std::ostream& out) const;
  size_t getCount() const;
  size_t getHeight() const;

private:
  struct Node
  {
    T key_;
    std::vector<std::list<T>> array_;
    Node* parent_;
    Node* left_;
    Node* right_;

    Node(const T& key, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr):
      key_(key),
      parent_(nullptr),
      left_(left),
      right_(right)
    {}
  };

  Node* iterativeSearchNode(const T& key) const;
  void printNode(std::ostream& out, BinarySearchTree<T>::Node* root) const;
  void printListNode(std::ostream& out, BinarySearchTree<T>::Node* root) const;
  size_t getCountSubTree(Node* node) const;
  size_t getHeightSubTree(Node* node) const;
  void freeUpMemory(Node* node);

  Node* root_;
};

template<class T>
BinarySearchTree<T>::BinarySearchTree():
  root_(nullptr)
{}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  freeUpMemory(root_);
  root_ = nullptr;
}

template<class T>
void BinarySearchTree<T>::insert(T value)
{
  std::string prefix;
  for (int i = 0; i < value.length(); ++i)
  {
    if (value[i] < 'A' || value[i] > 'Z')
    {
      if (value[i] < 'a' || value[i] > 'z')
      {
        if (value[i] == '-')
        {
          continue;
        }
        else if (value[i] == '\'')
        {
          return;
        }
        else
        {
          if (value[value.length()-1] == '!', '.', ',', ':', ';')
          {
            value = value.substr(0, value.length()-1);
            break;
          }
          return;
        }
      }
    }
  }
  prefix = value.substr(0, 2);
  if (prefix.size() == 2)
  {
    if(root_ == nullptr)
    {
      root_ = new Node(prefix);
      root_->array_.resize(100);
      root_->array_[0].push_back(value);
      return;
    }
    else
    {
      Node *current = root_;
      Node *temp = current;
      if (current->key_ == prefix)
      {
        current->array_[0].push_back(value);
        return;
      }
      while(current != nullptr)
      {
        temp = current;
        if (prefix == current->key_)
        {
          current->array_[0].push_back(value);
          return;
        }
        if (prefix < current->key_)
        {
          current = current->left_;

        }
        else if (prefix > current->key_)
        {
          current = current->right_;
        }
      }
      if (temp->key_ < prefix)
      {
        temp->right_ = new Node(prefix);
        temp->right_->array_.resize(100);
        temp->right_->array_[0].push_back(value);
      }
      else
      {
        temp->left_ = new Node(prefix);
        temp->left_->array_.resize(100);
        temp->left_->array_[0].push_back(value);
      }
    }
  }
}

template<class T>
bool BinarySearchTree<T>::searchNode(const T& key) const
{
  return (iterativeSearchNode(key) != nullptr);
}

template<class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::iterativeSearchNode(const T& key) const
{
  if (root_ == nullptr)
  {
    return nullptr;
  }
  Node* current = root_;
  while ((current != nullptr) && (current->key_ != key))
  {
    if (current->key_ < key)
    {
      current = current->right_;
    }
    else
    {
      current = current->left_;
    }
  }
  return current;
}

template<class T>
void BinarySearchTree<T>::freeUpMemory(BinarySearchTree::Node* node)
{
  if (node != nullptr)
  {
    freeUpMemory(node->left_);
    freeUpMemory(node->right_);
    delete node;
  }
  else
  {
    return;
  }
}

template<class T>
void BinarySearchTree<T>::print(std::ostream& out) const
{
  printListNode(out, root_);
  out << std::endl;
}

template<class T>
void BinarySearchTree<T>::printTree(std::ostream& out) const
{
  printNode(out, root_);
  out << std::endl;
}

template<class T>
void BinarySearchTree<T>::printNode(std::ostream& out, BinarySearchTree<T>::Node* root) const
{
  // Prefix tree traversal
  if (root != nullptr)
  {
    printNode(out, root->left_);
    out << root->key_ << " /";
    printNode(out, root->right_);
  }
}

template<class T>
void BinarySearchTree<T>::printListNode(std::ostream &out, BinarySearchTree<T>::Node *root) const
{
  if (root != nullptr)
  {
    static size_t count;
    for (int i = 0; i < root->array_.size(); ++i)
    {
      if (!root->array_[i].empty())
      {
        out << ++count << ')' << "List of words with a prefix - " << root->key_ << ":";
        for (auto x: root->array_[i])
        {
          out << "  " << x;
        }
        out << "\n";
      }
    }
    printListNode(out, root->left_);
    printListNode(out, root->right_);
  }
}

template<class T>
size_t BinarySearchTree<T>::getCount() const
{
  size_t count = getCountSubTree(root_);
  return count;
}

template<class T>
size_t BinarySearchTree<T>::getCountSubTree(BinarySearchTree::Node* node) const
{
  static size_t count = 0;
  if (node != nullptr)
  {
    count++;
    getCountSubTree(node->left_);
    getCountSubTree(node->right_);
  }
  return count;
}

template<class T>
size_t BinarySearchTree<T>::getHeight() const
{
  size_t height = getHeightSubTree(root_);
  return height;
}

template<class T>
size_t BinarySearchTree<T>::getHeightSubTree(BinarySearchTree::Node *node) const
{
  size_t height = 0;
  size_t heightLeft = 0;
  size_t heightRight = 0;
  if(node != nullptr)
  {
    heightLeft = getHeightSubTree(node->left_);
    heightRight = getHeightSubTree(node->right_);
    height = heightLeft > heightRight ? heightLeft + 1 : heightRight + 1;
  }
  return height;
}

#endif
