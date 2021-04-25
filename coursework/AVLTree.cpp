#include "AVLTree.h"
#include "list.h"
#include "details.h"
#include <iostream>
#include <algorithm>
#include <iomanip>


AVLTree::~AVLTree()
{
  freesMemoryTree(root_);
}

size_t AVLTree::getCount() const
{
  return count(root_);
}

void AVLTree::calculateHeightBalance(Node* current)
{
  if (current != nullptr)
  {
    if (current->right_ != nullptr && current->left_ != nullptr)
    {
      current->height_ = std::max(current->right_->height_, current->left_->height_) + 1;
      current->balanceFactor_ = current->right_->height_ - current->left_->height_;
    }
    else
    {
      if (current->right_ == nullptr && current->left_ != nullptr)
      {
        current->height_ = current->left_->height_ + 1;
        current->balanceFactor_ = -(static_cast<int>(current->left_->height_));
      }
      else
      {
        if (current->left_ == nullptr && current->right_ != nullptr)
        {
          current->height_ = current->right_->height_ + 1;
          current->balanceFactor_ = current->right_->height_;
        }
        else
        {
          current->height_ = 1;
          current->balanceFactor_ = 0;
        }
      }
    }
  }
}

AVLTree& AVLTree::insert(std::string key, std::string word)
{
  if (!isKey(key))
  {
    throw myExceptions::ErrorSyntax("The prefix was syntactically wrong.");
  }
  if (!isWord(word))
  {
    throw myExceptions::ErrorSyntax("The word was syntactically wrong.");
  }
  if (root_ == nullptr)
  {
    root_ = new Node(key);
    root_->data_.insert(word);
  }
  else
  {
    Node* currentNode = root_;
    bool breakWhile = false;
    while (breakWhile == false)
    {
      int cmpKey = compareKey(key, currentNode->key_);
      if (cmpKey == 0)
      {
        currentNode->data_.insert(word);
        return *this;
      }
      else
      {
        if (cmpKey == 1)
        {
          if (currentNode->right_ == nullptr)
          {
            currentNode->right_ = new Node(key);
            currentNode->right_->parent_ = currentNode;
            currentNode = currentNode->right_;
            currentNode->data_.insert(word);
            breakWhile = true;
          }
          else
          {
            currentNode = currentNode->right_;
          }
        }
        else
        {
          if (currentNode->left_ == nullptr)
          {
            currentNode->left_ = new Node(key);
            currentNode->left_->parent_ = currentNode;
            currentNode = currentNode->left_;
            currentNode->data_.insert(word);
            breakWhile = true;
          }
          else
          {
            currentNode = currentNode->left_;
          }
        }
      }
    }
    if (currentNode != root_)
    {
      rebalance(currentNode->parent_);
    }
  }
  return *this;
}

List& AVLTree::search(std::string key)
{
  if (!isKey(key))
  {
    throw myExceptions::ErrorSyntax("The prefix was syntactically wrong.");
  }
  if (root_ == nullptr)
  {
    throw myExceptions::EmptyDictionary();
  }
  Node* currentNode = root_;
  while (currentNode != nullptr)
  {
    int cmpKey = compareKey(key, currentNode->key_);
    if (cmpKey == 0)
    {
      return currentNode->data_;
    }
    else
    {
      if (cmpKey == 1)
      {
        currentNode = currentNode->right_;
      }
      else
      {
        currentNode = currentNode->left_;
      }
    }
  }
  throw myExceptions::NoWordFound();
}

void AVLTree::deleteKey(std::string key)
{
  if (!isKey(key))
  {
    throw myExceptions::ErrorSyntax("The prefix was syntactically wrong.");
  }
  if (root_ == nullptr)
  {
    throw myExceptions::EmptyDictionary();
  }
  else
  {
    Node** currentNode = &root_;
    bool breakWhile = false;
    Node* unbalancedNode = nullptr;
    while (breakWhile == false)
    {
      int cmpKey = compareKey(key, (*currentNode)->key_);
      if (cmpKey == 0)
      {
        unbalancedNode = (*currentNode)->parent_;
        if ((*currentNode)->left_ == nullptr && (*currentNode)->right_ == nullptr)
        {
          (*currentNode)->parent_ = nullptr;
          delete* currentNode;
          (*currentNode) = nullptr;
        }
        else
        {
          if ((*currentNode)->left_ != nullptr && (*currentNode)->right_ != nullptr)
          {
            Node* tempNode = (*currentNode);
            currentNode = &(*currentNode)->left_;
            while ((*currentNode)->right_ != nullptr)
            {
              currentNode = &(*currentNode)->right_;
            }
            tempNode->key_ = (*currentNode)->key_;
            tempNode->data_ = (*currentNode)->data_;
            unbalancedNode = (*currentNode)->parent_;
            if ((*currentNode)->left_ == nullptr)
            {
              (*currentNode)->parent_ = nullptr;
              delete* currentNode;
              (*currentNode) = nullptr;
            }
            else
            {
              (*currentNode)->left_->parent_ = (*currentNode)->parent_;
              (*currentNode)->parent_ = nullptr;
              Node* tempNode = (*currentNode)->left_;
              (*currentNode)->left_ = nullptr;
              delete* currentNode;
              (*currentNode) = tempNode;
            }
          }
          else
          {
            if ((*currentNode)->left_ != nullptr && (*currentNode)->right_ == nullptr)
            {
              (*currentNode)->left_->parent_ = (*currentNode)->parent_;
              (*currentNode)->parent_ = nullptr;
              Node* tempNode = (*currentNode)->left_;
              (*currentNode)->left_ = nullptr;
              delete* currentNode;
              (*currentNode) = tempNode;
            }
            else
            {
              (*currentNode)->right_->parent_ = (*currentNode)->parent_;
              (*currentNode)->parent_ = nullptr;
              Node* tempNode = (*currentNode)->right_;
              (*currentNode)->right_ = nullptr;
              delete* currentNode;
              (*currentNode) = tempNode;
            }
          }
        }
        if (root_ != nullptr)
        {
          rebalance(unbalancedNode);
        }
        breakWhile = true;

      }
      else
      {
        if (cmpKey == -1)
        {
          if ((*currentNode)->left_ != nullptr)
          {
            currentNode = &((*currentNode)->left_);
          }
          else
          {
            breakWhile = true;
          }
        }
        else
        {
          if ((*currentNode)->right_ != nullptr)
          {
            currentNode = &((*currentNode)->right_);
          }
          else
          {
            breakWhile = true;
          }
        }
      }
    }
  }
}

void AVLTree::printTree(std::ostream& out)
{
  if (root_ == nullptr)
  {
    std::cout << "The tree is empty.\n";
  }
  else
  {
    printNode(root_, out);
  }
}

void AVLTree::freesMemoryTree(Node* node)
{
  if (node != nullptr)
  {
    if (node->left_ == nullptr && node->right_ == nullptr)
    {
      delete node;
    }
    else
    {
      freesMemoryTree(node->left_);
      freesMemoryTree(node->right_);
      delete node;
    }
  }
}

size_t AVLTree::count(Node* node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  if ((node->left_ == nullptr) && (node->right_ == nullptr))
  {
    return 1;
  }
  return count(node->left_) + count(node->right_) + 1;
}

void AVLTree::rightRotation(Node* node)
{
  node->parent_->left_ = node->right_;
  node->right_ = node->parent_;
  Node* tempNode = node->parent_;
  node->parent_ = node->parent_->parent_;
  tempNode->parent_ = node;
  if (node->parent_ != nullptr)
  {
    if (node->parent_->left_ == tempNode)
    {
      node->parent_->left_ = node;
    }
    if (node->parent_->right_ == tempNode)
    {
      node->parent_->right_ = node;
    }
  }
  if (tempNode == root_)
  {
    root_ = node;
  }
}

void AVLTree::leftRotation(Node* node)
{
  Node* tempNode = node->parent_;
  tempNode->right_ = node->left_;
  node->left_ = tempNode;
  node->parent_ = tempNode->parent_;
  tempNode->parent_ = node;
  if (node->parent_ != nullptr)
  {
    if (node->parent_->right_ == tempNode)
    {
      node->parent_->right_ = node;
    }
    if (node->parent_->left_ == tempNode)
    {
      node->parent_->left_ = node;
    }
  }
  if (tempNode == root_)
  {
    root_ = node;
  }
}

void AVLTree::rebalance(Node* node)
{
  calculateHeightBalance(node);
  if (node->balanceFactor_ > 1)
  {
    if (node->right_->balanceFactor_ == -1)
    {
      rightRotation(node->right_->left_);
      leftRotation(node->right_);
      calculateHeightBalance(node);
      calculateHeightBalance(node->parent_->right_);
    }
    else
    {
      if (node->right_->balanceFactor_ == 1)
      {
        leftRotation(node->right_);
        calculateHeightBalance(node);
      }
    }
  }
  else
  {
    if (node->balanceFactor_ < -1)
    {
      if (node->left_->balanceFactor_ == -1)
      {
        rightRotation(node->left_);
        calculateHeightBalance(node);
      }
      else
      {
        if (node->left_->balanceFactor_ == 1)
        {
          leftRotation(node->left_->right_);
          rightRotation(node->left_);
          calculateHeightBalance(node);
          calculateHeightBalance(node->parent_->left_);
        }
      }
    }
  }
  if (node != root_)
  {
    rebalance(node->parent_);
  }
}

void AVLTree::printNode(Node* node, std::ostream& out)
{
  if (node != nullptr)
  {
    printNode(node->left_, out);
    printNode(node->right_, out);
    out << node->key_ << "(" << node->height_ << ", " << node->balanceFactor_ << ")" << " :  " ;
    node->data_.print(out);
    out << '\n';
  }
}
