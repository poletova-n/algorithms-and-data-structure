#include "binarySearchTree.hpp"

#include <stdexcept>
#include <iomanip>

BinarySearchTree::BinarySearchTree() :
root_(nullptr)
{}

bool BinarySearchTree::search(std::string &word)
{
  return (iterativeSearchNode(word) != nullptr);
}

BinarySearchTree::node *BinarySearchTree::iterativeSearchNode(const std::string &word) const
{
  if (root_ == nullptr)
  {
    return root_;
  }
  else
  {
    node *temp = root_;
    while (true)
    {
      if (word == temp->word_)
      {
        return temp;
      }
      if (word > temp->word_)
      {
        temp = temp->right_;
      }
      else if (word < temp->word_)
      {
        temp = temp->left_;
      }
      if (temp == nullptr)
      {
        return nullptr;
      }
    }
  }
}

bool BinarySearchTree::insert(std::string &word, List &translation)
{
  for (int i = 0; word[i] != '\0'; i++)
  {
    if ((word[i] < 65 || word[i] > 90) && (word[i] < 97 || word[i] > 122) && (word[i] != '-'))
    {
      throw std::invalid_argument("The translation was entered incorrectly, the entered word is not English");
    }
  }
  if (search(word))
  {
    throw std::invalid_argument("The word has already been added");
  }
  node *tempNode = new node();
  tempNode->word_ = word;
  tempNode->translation_ = translation;
  node *temp = root_;
  if (root_ == nullptr)
  {
    root_ = tempNode;
    return true;
  }
  while (temp != nullptr)
  {
    if (tempNode->word_ > temp->word_)
    {
      if (temp->right_ == nullptr)
      {
        temp->right_ = tempNode;
        return true;
      }
      temp = temp->right_;
    }
    else if (tempNode->word_ < temp->word_)
    {
      if (temp->left_ == nullptr)
      {
        temp->left_ = tempNode;
        return true;
      }
      temp = temp->left_;
    }
  }
}

void BinarySearchTree::print(std::ostream &output)
{
  if (root_ != nullptr)
  {
    output << '\n' << "word:               translation:" << '\n';
  }
  printNode(output, root_);
}

void BinarySearchTree::printNode(std::ostream &output, node *node)
{
  if (node != nullptr)
  {
    printNode(output, node->left_);
    output << std::setw(20) << std::left << node->word_ << node->translation_.print() << '\n';
    printNode(output, node->right_);
  }
}

void BinarySearchTree::printNodeWithHierarchy(std::ostream &output, BinarySearchTree::node *node)
{
  output << '(';
  if (node != nullptr)
  {
    output << node->word_ << " - " << node->translation_.print();
    printNodeWithHierarchy(output, node->left_);
    printNodeWithHierarchy(output, node->right_);
  }
  output << ')';
}

void BinarySearchTree::printWithHierarchy(std::ostream &output)
{
  printNodeWithHierarchy(output, root_);
}

bool BinarySearchTree::remove(std::string &word)
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("Tree is empty. Deletion is not possible");
  }
  if (!search(word))
  {
    throw std::invalid_argument("Element with not found in tree. Unable to delete");
  }
  node *toDelete;
  node *temp = root_;
  node *previousTemp = root_;
  if (root_->word_ == word)
  {
    toDelete = root_;
    temp = root_->left_;
    root_ = root_->right_;
    this->insert(temp);
    delete toDelete;
    return true;
  }
  while (true)
  {
    if (temp->word_ == word)
    {
      if ((temp->right_ == nullptr) && (temp->left_ == nullptr))
      {
        if ((previousTemp->left_ != nullptr) && (previousTemp->left_->word_ == temp->word_))
        {
          previousTemp->left_ = nullptr;
          delete temp;
          return true;
        }
        else
        {
          previousTemp->right_ = nullptr;
          delete temp;
          return true;
        }
      }
      else if (temp->right_ == nullptr)
      {
        if (previousTemp->left_->word_ == temp->word_)
        {
          previousTemp->left_ = temp->right_;
          return true;
        }
        else
        {
          previousTemp->right_ = temp->left_;
          return true;
        }
      }
      else if (temp->left_ == nullptr)
      {
        if ((temp->word_ == previousTemp->right_->word_) && (nullptr != previousTemp->right_))
        {
          previousTemp->left_ = temp->right_;
          previousTemp->right_ = nullptr;
          return true;
        }
        else
        {
          previousTemp->right_ = temp->left_;
          previousTemp->left_ = nullptr;
          return true;
        }
      }
      else
      {
        if ((previousTemp->left_ != nullptr) && (previousTemp->left_->word_ == word))
        {
          previousTemp->left_ = temp->right_;
          this->insert(temp->left_);
          return true;
        }
        else if ((previousTemp->right_ != nullptr) && (previousTemp->right_->word_ == word))
        {
          previousTemp->right_ = temp->right_;
          this->insert(temp->left_);
          return true;
        }
      }
    }
    else if (word > temp->word_)
    {
      previousTemp = temp;
      temp = temp->right_;
    }
    else if (word < temp->word_)
    {
      previousTemp = temp;
      temp = temp->left_;
    }
  }
}

void BinarySearchTree::insert(node *node)
{
  int flag = 0;
  BinarySearchTree::node *temp = root_;
  if (root_ == nullptr)
  {
    root_ = node;
  }
  while ((temp != nullptr) && (flag != 1))
  {
    if (node->word_ > temp->word_)
    {
      if (temp->right_ == nullptr)
      {
        temp->right_ = node;
        flag = 1;
      }
      temp = temp->right_;
    }
    else if (node->word_ < temp->word_)
    {
      if (temp->left_ == nullptr)
      {
        temp->left_ = node;
        flag = 1;
      }
      temp = temp->left_;
    }
  }
}
