#include "AVLTree.hpp"
#include <algorithm>

AVLTree::~AVLTree()
{
    removeRecursive(head_);
}

void AVLTree::remove(const std::string& key)
{
    if (head_ == nullptr || key.empty())
    {
        throw EmptyDictionary();
    }
    Node* temp = searchNode(key);
    if (temp == nullptr)
    {
        throw WordIsNotFound(key);
    }
    removeNode(temp);
    if (head_)
    {
        balance(head_);
    }
}

AVLTree::Node *AVLTree::searchNode(const std::string& key) const
{
    Node *temp = head_;
    while (temp->key_ != key)
    {
        if (temp->key_ > key)
        {
           if (temp->left_ != nullptr)
           {
               temp = temp->left_;
           } else {
               temp = nullptr;
               return temp;
           }
        } else {
            if (temp->right_ != nullptr)
            {
                temp = temp->right_;
            } else {
                temp = nullptr;
                return temp;
            }
        }
    }
    return temp;
}

int AVLTree::bFactor(AVLTree::Node *node)
{
  if (!node)
  {
    return 0;
  }
  return getHeight(node->left_) - getHeight(node->right_);
}

int AVLTree::getHeight(AVLTree::Node *node)
{
    if (!node)
    {
        return 0;
    }
    return std::max(getHeight(node->left_), getHeight(node->right_)) +1;
}

AVLTree::Node *AVLTree::rotateRight(AVLTree::Node *node)
{
   Node * temp  = node->left_;
   node->left_ = temp->right_;
   if (temp->right_ != nullptr) {
     temp->right_->parent_ = node;
   }
  if (node->parent_ != nullptr) {
    if (node->parent_->left_ == node) {
      node->parent_->left_ = temp;
    } else {
      node->parent_->right_ = temp;
    }
  } else {
    head_ = temp;
  }
  temp->parent_ = node->parent_;
  node->parent_ = temp;
   temp->right_ = node;
   return temp;
}

AVLTree::Node *AVLTree::rotateLeft(AVLTree::Node *node)
{
    Node *temp = node->right_;
    node->right_ = temp->left_;
  if (temp->left_ != nullptr) {
    temp->right_->parent_ = node;
  }
    if (node->parent_ != nullptr) {
      if (node->parent_->left_ == node) {
        node->parent_->left_ = temp;
      } else {
        node->parent_->right_ = temp;
      }
    } else {
      head_ = temp;
    }
  temp->parent_ = node->parent_;
  node->parent_ = temp;
    temp->left_ = node;
    return temp;
}

AVLTree::Node *AVLTree::balance(AVLTree::Node *node)
{
    int balanceFactor = bFactor(node);

    if (balanceFactor > 1) {
        if (bFactor(node->left_) > 0) {
          rotateRight(node);
        } else if (bFactor(node->left_) < 0) {
          rotateLeft(node->left_);
          rotateRight(node);
        }
    } else if (balanceFactor < -1) {
      if (bFactor(node->right_) > 0) {
        rotateRight(node->right_);
        rotateLeft(node);
      } else if (bFactor(node->right_) < 0) {
        rotateLeft(node);
      }
    }
    if (node->parent_ != nullptr) {
      balance(node->parent_);
    }
    return node;
}

AVLTree::Node* AVLTree::addNode(const std::string& key, List &data, AVLTree::Node *&node, AVLTree::Node *parent)
{
    if (node == nullptr)
    {
        node = new struct Node(key,data);
        node->parent_ = parent;
        return node;
    }
    else
    {
        if (node->key_ > key)
        {
            return addNode(key,data,node->left_,node);
        }
        if (node->key_ < key)
        {
            return addNode(key,data,node->right_,node);
        }
    }
}

void AVLTree::add(std::string str)
{
    int point = str.find("-");
    List info;
    std::string key = str.substr(0,point-1);
    if (!isEnglish((key)))
    {
        throw SyntaxError(key);
    }

    std::string translation = str.substr(point + 2, str.length());

    for (auto symbol: translation)
    {
        if (symbol != ' ' && symbol != '/' && (!isRussian(symbol))
            && symbol != ')' && symbol != '(' && symbol != ',')
        {
            throw SyntaxError(str);
        }
    }
    info.insert(translation);
    Node* temp = addNode(key, info, head_, nullptr);
    balance(temp);
}

bool AVLTree::search(const std::string& key) const
{
    if (head_ == nullptr)
    {
        throw EmptyDictionary();
    }
    Node *temp = searchNode(key);
    if (temp == nullptr)
    {
        return false;
    }
    return true;
}

bool AVLTree::isEnglish(const std::string& word)
{
    for (char s : word) {
        if (s < 'A' | s > 'z') {
            return false;
        }
    }
    return true;
}

bool AVLTree::isRussian(const char c)
{
    if (((static_cast<int>(c) <= -30) && (static_cast<int>(c) >= -130)) || (static_cast<int>(c) == 32))
    {
        return true;
    }
    return false;
}

AVLTree::Node *AVLTree::getSuccessor(AVLTree::Node *node2, AVLTree::Node *node)
{
    if(node2 == nullptr)
    {
        return node2;
    }
    else if(node)
    {
        if(node2->key_ >= node->key_)
        {
            return node2;
        }
        else
        {
            return getSuccessor(node2->parent_, node);
        }
    }
    else if(node2->right_)
    {
        Node *node3 = node2->right_;
        while(node3->left_)
        {
            node3 = node3->left_;
        }
        return node3;
    }
    else
    {
        return getSuccessor(node2->parent_, node2);
    }
}

void AVLTree::removeNode(AVLTree::Node *node)
{
    if((!node->right_) && (!node->left_))
    {
        Node* temp = node->parent_;
        if(temp == nullptr)
        {
            head_ = nullptr;
        }
        else if (temp->right_ == node)
        {
            temp->right_ = nullptr;
        }
        else
        {
            temp->left_ = nullptr;
        }
    }
    else if ((!node->right_) || (!node->left_))
    {
        Node* child;
        if(node->right_ != nullptr)
        {
            child = node->right_;
        }
        else
        {
            child = node->left_;
        }
        Node *parent = node->parent_;
        if (parent == nullptr)
        {
            head_ = child;
        }
        else if(parent->right_ == node)
        {
            parent->right_ = child;
        }
        else
        {
            parent->left_ = child;
        }
        child->parent_ = parent;
    }
    else
    {
        Node *successor = getSuccessor(node);
        node->key_ = successor->key_;
        removeNode(successor);
        if(node->parent_ == nullptr)
        {
            head_ = node;
        }
    }
}

void AVLTree::printNode(std::ostream &os, Node *node)
{
    if (!head_ || !node)
    {
        return;
    }
    std::string outWord;
    if (head_)
    {
        printNode(os, node->left_);
        outWord = node->key_ + ":" + node->data_.print();
        os << outWord ;
        printNode(os, node->right_);
    }
}

void AVLTree::print(std::ostream & os)
{
    printNode(os, head_);
    os << std::endl;
}

void AVLTree::removeRecursive(Node *node)
{
    if (node)
    {
        removeRecursive(node->left_);
        removeRecursive(node->right_);
    }
    delete node;
}
