#include "tree.hpp"

#include <stdexcept>
#include <vector>

Tree::~Tree()
{
  deleteSubtree(root_);
}

void Tree::insert(std::string key, std::string value)
{
  for (int i = 0; i < key.size(); i++)
  {
    if (key[i] < 'A' || key[i] > 'z')
    {
      throw std::invalid_argument("Invalid symbol");
    }
  }
  Node* node = new Node(key, parse(value));
  if (root_ == nullptr)
  {
    root_ = node;
    root_->color_ = false;
    return;
  }
  Node* temp(root_);
  while (true)
  {
    if (temp->key_ > node->key_)
    {
      if (temp->left_ == nullptr)
      {
        temp->left_ = node;
        break;
      }
      temp = temp->left_;
    }
    else
    {
      if (temp->right_ == nullptr)
      {
        temp->right_ = node;
        break;
      }
      temp = temp->right_;
    }
  }
  node->parent_ = temp;
  while (node->parent_ != nullptr && node->parent_->color_)
  {
    if (node->parent_->parent_ != nullptr)
    {
      Node *uncle;
      if (node->parent_ == node->parent_->parent_->left_)
      {
        uncle = node->parent_->parent_->right_;
      }
      else
      {
        uncle = node->parent_->parent_->left_;
      }
      if (uncle != nullptr && uncle->color_)
      {
        node->parent_->parent_->color_ = true;
        node->parent_->color_ = false;
        uncle->color_ = false;
        node = node->parent_->parent_;
      }
      else
      {
        bool sameSide = ((node == node->parent_->right_) && node->parent_ == (node->parent_->parent_->right_))
                        || ((node == node->parent_->left_) && (node->parent_ == node->parent_->parent_->left_));
        if (!sameSide)
        {
          if (node == node->parent_->right_)
          {
            node = node->parent_;
            rotateLeft(node);
          }
          else
          {
            node = node->parent_;
            rotateRight(node);
          }
        }
        else
        {
          node->parent_->color_ = false;
          node->parent_->parent_->color_ = true;
          if (node == node->parent_->right_)
          {
            rotateLeft(node->parent_->parent_);
          }
          else
          {
            rotateRight(node->parent_->parent_);
          }
        }
      }
    }
  }
  root_->color_ = false;
}

void Tree::remove(std::string key)
{
  Node* nodeToDelete(root_);
  while (nodeToDelete != nullptr && nodeToDelete->key_ != key)
  {
    if (nodeToDelete->key_ > key)
    {
      nodeToDelete = nodeToDelete->left_;
    } else
    {
      nodeToDelete = nodeToDelete->right_;
    }
  }
  if (nodeToDelete == nullptr)
  {
    throw std::runtime_error("Error remove");
  }
  deleteKey(nodeToDelete);
}

bool Tree::search(std::string key) const
{
  Node *temp(root_);
  while (temp != nullptr)
  {
    if (temp->key_ > key)
    {
      temp = temp->left_;
    }
    else if (temp->key_ < key)
    {
      temp = temp->right_;
    }
    else
    {
      return true;
    }
  }
  return false;
}

void Tree::print(std::ostream& out) const
{
  print(root_, out);
}

void Tree::deleteKey(Node* node)
{
  Node* temp(find(node));
  if (node->parent_ != nullptr)
  {
    if (node->parent_->right_ == node)
    {
      node->parent_->right_ = temp;
    }
    else
    {
      node->parent_->left_ = temp;
    }
  }
  else
  {
    root_ = temp;
  }
  if (temp != nullptr)
  {
    if (node->left_ != nullptr && node->right_ != nullptr)
    {
      temp->left_ = node->left_;
      if (temp->parent_ != node)
      {
        temp->parent_->left_ = temp->right_;
        temp->right_ = node->right_;
      }
      node->right_->parent_ = temp;
      node->left_->parent_ = temp;
    }
    temp->parent_ = node->parent_;
  }
  if (node->color_)
  {
    if (temp == nullptr || temp->color_)
    {
      return;
    }
    temp->color_ = true;
  }
  else if (temp != nullptr && temp->color_)
  {
    temp->color_ = false;
    return;
  }
  Node *parent(node->parent_);
  if (node->left_ != nullptr && node->right_ != nullptr)
  {
    node = temp->right_;
    parent = temp->parent_;
  }
  else
  {
    node = temp;
  }
  while (node != root_ && (node == nullptr || !node->color_))
  {
    bool isLeftChild = parent->left_ == node;
    Node* sibling;
    if (parent->right_ == node)
    {
      sibling = parent->left_;
    }
    else
    {
      sibling =  parent->right_;
    }
    if (sibling != nullptr && sibling->color_)
    {
      sibling->color_ = false;
      parent->color_ = true;
      if (isLeftChild)
      {
        rotateLeft(parent);
      }
      else
      {
        rotateRight(parent);
      }
      if (parent->right_ == node)
      {
        sibling = parent->left_;
      }
      else
      {
        sibling =  parent->right_;
      }
    }
    bool siblingRightChildColor = sibling->right_ != nullptr && sibling->right_->color_;
    bool siblingLeftChildColor = sibling->left_ != nullptr && sibling->left_->color_;
    if (!siblingLeftChildColor && !siblingRightChildColor)
    {
      sibling->color_ = true;
      node = parent;
      parent = node->parent_;
      if (node->color_)
      {
        break;
      }
    }
    else if (isLeftChild && siblingLeftChildColor || !isLeftChild && siblingRightChildColor)
    {
      sibling->color_ = true;
      if (isLeftChild)
      {
        sibling->left_->color_ = false;
        rotateRight(sibling);
      }
      else
      {
        sibling->right_->color_ = false;
        rotateLeft(sibling);
      }
    }
    else
    {
      sibling->color_ = parent->color_;
      parent->color_ = false;
      if (isLeftChild)
      {
        sibling->right_->color_ = false;
        rotateLeft(parent);
      }
      else
      {
        sibling->left_->color_ = false;
        rotateRight(parent);
      }
      return;
    }
  }
  node->color_ = false;
  delete node;
}

void Tree::rotateLeft(Node* node)
{
  Node* temp = node->right_;
  temp->parent_ = node->parent_;
  if (node->parent_ == nullptr)
  {
    root_ = temp;
  }
  else
  {
    if (node->parent_->left_ == node)
    {
      node->parent_->left_ = temp;
    } else
    {
      node->parent_->right_ = temp;
    }
  }
  node->parent_ = temp;
  if (temp->left_ != nullptr)
  {
    temp->left_->parent_ = node;
  }
  node->right_ = temp->left_;
  temp->left_ = node;
}

void Tree::rotateRight(Node* node)
{
  Node* temp = node->left_;
  temp->parent_ = node->parent_;
  if (node->parent_ == nullptr)
  {
    root_ = temp;
  } else
  {
    if (node->parent_->left_ == node)
    {
      node->parent_->left_ = temp;
    } else
    {
      node->parent_->right_ = temp;
    }
  }
  node->parent_ = temp;
  if (temp->right_ != nullptr)
  {
    temp->right_->parent_ = node;
  }
  node->left_ = temp->right_;
  temp->right_ = node;
}

void Tree::print(Node* node, std::ostream& out)
{
  if (node != nullptr)
  {
    print(node->left_, out);
    out << node->key_ << ": " << node->value_.getValueAsString();
    out << '\n';
    print(node->right_, out);
  }
}

Tree::Node *Tree::find(Node* node)
{
  Node* temp(node->right_);
  if (temp == nullptr)
  {
    temp = node->left_;
  } else
  {
    while (temp->left_ != nullptr)
    {
      temp = temp->left_;
    }
  }
  return temp;
}

List Tree::parse(std::string synonymString)
{
  if (synonymString.empty())
  {
    throw std::invalid_argument("Empty synonym string");
  }
  List inStr;
  std::vector<char> firstLatter;
  int separator = synonymString.find(',');
  while (separator != -1)
  {
    std::string word = synonymString.substr(0, separator);
    for (int i = 0; i < word.size(); i++)
    {
      if (word[i] < 'A' || word[i] > 'z')
      {
        throw std::invalid_argument("Invalid symbol in synonym string");
      }
    }
    firstLatter.push_back(word[0]);
    synonymString.erase(0, separator + 1);
    if (!synonymString.empty() && synonymString[0] != ' ')
    {
      throw std::invalid_argument("Invalid string with synonyms");
    }
    inStr.add(word);
    synonymString.erase(0, 1);
    separator = synonymString.find(',');
  }
  for (int i = 0; i < synonymString.size(); i++)
  {
    if (synonymString[i] < 'A' || synonymString[i] > 'z')
    {
      throw std::invalid_argument("Invalid string with synonyms");
    }
  }
  firstLatter.push_back(synonymString[0]);
  inStr.add(synonymString);
  for (int j = 0; j < firstLatter.size() - 1; j++)
  {
    for (int i = 0; i < firstLatter.size() - 1; i++)
    {
      if (firstLatter[i] > firstLatter[i+1])
      {
        std::swap(firstLatter[i], firstLatter[i+1]);
        inStr.Swap(i, i+1);
      }
    }
  }
  return inStr;
}

void Tree::deleteSubtree(Node* node)
{
  if (node == nullptr)
  {
    return;
  }
  deleteSubtree(node->left_);
  deleteSubtree(node->right_);
  delete node;
}
