#include "RedBlackTree.hpp"

#include <stdexcept>

RedBlackTree::~RedBlackTree()
{
  deleteSubtree(root_);
}

void RedBlackTree::add(std::string key, std::string value)
{
  for (int i = 0; i < key.size(); i++) {
    if (key[i] < 'A' || key[i] > 'z') {
      throw std::invalid_argument("Invalid english word");
    }
  }
  Node* node = new Node(key, parseRussianStringByComma(value));
  insertAsInBinary(node);
  fixAfterInsertion(node);
}

bool RedBlackTree::remove(std::string key)
{
  Node* nodeToDelete(root_);
  while (nodeToDelete != nullptr && nodeToDelete->key_ != key) {
    if (nodeToDelete->key_ > key) {
      nodeToDelete = nodeToDelete->left_;
    } else {
      nodeToDelete = nodeToDelete->right_;
    }
  }
  if (nodeToDelete == nullptr) {
    return false;
  }
  remove(nodeToDelete);
  return true;
}

bool RedBlackTree::find(std::string key)
{
  Node* temp(root_);
  while (temp != nullptr) {
    if (temp->key_ > key) {
      temp = temp->left_;
    } else if (temp->key_ < key){
      temp = temp->right_;
    } else {
      return true;
    }
  }
  return false;
}

void RedBlackTree::print(std::ostream& out)
{
  print(root_, out);
}

void RedBlackTree::remove(Node* node)
{
  Node* replacement(findReplacement(node));
  if (node->parent_ != nullptr) {
    if (node->parent_->right_ == node) {
      node->parent_->right_ = replacement;
    } else {
      node->parent_->left_ = replacement;
    }
  } else {
    root_ = replacement;
  }
  if (replacement != nullptr) {
    if (node->left_ != nullptr && node->right_ != nullptr) {
      replacement->left_ = node->left_;
      if (replacement->parent_ != node) {
        replacement->parent_->left_ = replacement->right_;
        replacement->right_ = node->right_;
      }
      node->right_->parent_ = replacement;
      node->left_->parent_ = replacement;
    }
    replacement->parent_ = node->parent_;
  }
  fixAfterRemoval(node, replacement);
  delete node;
}

void RedBlackTree::insertAsInBinary(Node* node)
{
  if (root_ == nullptr) {
    root_ = node;
    root_->color_ = false;
    return;
  }
  Node* temp(root_);
  while (true) {
    if (temp->key_ > node->key_) {
      if (temp->left_ == nullptr) {
        temp->left_ = node;
        break;
      }
      temp = temp->left_;
    } else {
      if (temp->right_ == nullptr) {
        temp->right_ = node;
        break;
      }
      temp = temp->right_;
    }
  }
  node->parent_ = temp;
}

void RedBlackTree::fixAfterInsertion(Node* node)
{
  while (node->parent_ != nullptr && node->parent_->color_) {
    if (node->parent_->parent_ != nullptr) {
      Node* uncle;
      if (node->parent_ == node->parent_->parent_->left_) {
        uncle = node->parent_->parent_->right_;
      } else {
        uncle = node->parent_->parent_->left_;
      }
      if (uncle != nullptr && uncle->color_) {
        node->parent_->parent_->color_ = true;
        node->parent_->color_ = false;
        uncle->color_ = false;
        node = node->parent_->parent_;
      } else {
        bool sameSide = ((node == node->parent_->right_) && node->parent_ == (node->parent_->parent_->right_))
            || ((node == node->parent_->left_) && (node->parent_ == node->parent_->parent_->left_));
        if (!sameSide) {
          if (node == node->parent_->right_) {
            node = node->parent_;
            rotateLeft(node);
          } else {
            node = node->parent_;
            rotateRight(node);
          }
        } else {
          node->parent_->color_ = false;
          node->parent_->parent_->color_ = true;
          if (node == node->parent_->right_) {
            rotateLeft(node->parent_->parent_);
          } else {
            rotateRight(node->parent_->parent_);
          }
        }
      }
    }
  }
  root_->color_ = false;
}

void RedBlackTree::fixAfterRemoval(Node* node, Node* replacement)
{
  if (node->color_) {
    if (replacement == nullptr || replacement->color_) {
      return;
    }
    replacement->color_ = true;
  } else if (replacement != nullptr && replacement->color_) {
    replacement->color_ = false;
    return;
  }
  Node* parent(node->parent_);
  if (node->left_ != nullptr && node->right_ != nullptr) {
    node = replacement->right_;
    parent = replacement->parent_;
  } else {
    node = replacement;
  }
  while (node != root_ && (node == nullptr || !node->color_)) {
    bool isLeftChild = parent->left_ == node;
    Node* sibling(getSibling(node, parent));
    if (sibling != nullptr && sibling->color_) {
      sibling->color_ = false;
      parent->color_ = true;
      if (isLeftChild) {
        rotateLeft(parent);
      } else {
        rotateRight(parent);
      }
      sibling = getSibling(node, parent);
    }
    bool siblingRightChildColor = sibling->right_ != nullptr && sibling->right_->color_;
    bool siblingLeftChildColor = sibling->left_ != nullptr && sibling->left_->color_;
    if (!siblingLeftChildColor && !siblingRightChildColor) {
      sibling->color_ = true;
      node = parent;
      parent = node->parent_;
      if (node->color_) {
        break;
      }
    } else if (isLeftChild && siblingLeftChildColor || !isLeftChild && siblingRightChildColor) {
      sibling->color_ = true;
      if (isLeftChild) {
        sibling->left_->color_ = false;
        rotateRight(sibling);
      } else {
        sibling->right_->color_ = false;
        rotateLeft(sibling);
      }
    } else {
      sibling->color_ = parent->color_;
      parent->color_ = false;
      if (isLeftChild) {
        sibling->right_->color_ = false;
        rotateLeft(parent);
      } else {
        sibling->left_->color_ = false;
        rotateRight(parent);
      }
      return;
    }
  }
  node->color_ = false;
}

RedBlackTree::Node* RedBlackTree::getSibling(Node* node, Node* parent)
{
  if (parent->right_ == node) {
    return  parent->left_;
  }
  return parent->right_;
}

void RedBlackTree::rotateLeft(Node* node)
{
  Node* replacement = node->right_;
  replacement->parent_ = node->parent_;
  if (node->parent_ == nullptr) {
    root_ = replacement;
  } else {
    if (node->parent_->left_ == node) {
      node->parent_->left_ = replacement;
    } else {
      node->parent_->right_ = replacement;
    }
  }
  node->parent_ = replacement;
  if (replacement->left_ != nullptr) {
    replacement->left_->parent_ = node;
  }
  node->right_ = replacement->left_;
  replacement->left_ = node;
}

void RedBlackTree::rotateRight(Node* node)
{
  Node* replacement  = node->left_;
  replacement->parent_ = node->parent_;
  if (node->parent_ == nullptr) {
    root_ = replacement;
  } else {
    if (node->parent_->left_ == node) {
      node->parent_->left_ = replacement;
    } else {
      node->parent_->right_ = replacement;
    }
  }
  node->parent_ = replacement;
  if (replacement->right_ != nullptr) {
    replacement->right_->parent_ = node;
  }
  node->left_ = replacement->right_;
  replacement->right_ = node;
}

void RedBlackTree::print(Node* node, std::ostream& out)
{
  if (node != nullptr) {
    print(node->left_, out);
    out << node->key_ << ": " << node->value_.getValueAsString();
    out << '\n';
    print(node->right_, out);
  }
}

RedBlackTree::Node* RedBlackTree::findReplacement(Node* node)
{
  Node* replacement(node->right_);
  if (replacement == nullptr) {
    replacement = node->left_;
  } else {
    while (replacement->left_ != nullptr) {
      replacement = replacement->left_;
    }
  }
  return replacement;
}

DoubleLinkedList RedBlackTree::parseRussianStringByComma(std::string stringWithRussianWords)
{
  if (stringWithRussianWords.empty()) {
    throw std::invalid_argument("Empty string with russian words");
  }
  DoubleLinkedList result;
  int endIndex = stringWithRussianWords.find(',');
  while (endIndex != -1) {
    std::string word = stringWithRussianWords.substr(0, endIndex);
    for (int i = 0; i < word.size(); i++) {
      if (word[i] > -30 || word[i] < -130) {
        throw std::invalid_argument("Invalid string with russian words");
      }
    }
    stringWithRussianWords.erase(0, endIndex + 1);
    if (!stringWithRussianWords.empty() && stringWithRussianWords[0] != ' ') {
      throw std::invalid_argument("Invalid string with russian words");
    }
    result.pushBack(word);
    stringWithRussianWords.erase(0,1);
    endIndex = stringWithRussianWords.find(',');
  }
  for (int i = 0; i < stringWithRussianWords.size(); i++) {
    if (stringWithRussianWords[i] > -30 || stringWithRussianWords[i] < -130) {
      throw std::invalid_argument("Invalid string with russian words");
    }
  }
  result.pushBack(stringWithRussianWords);
  return result;
}

void RedBlackTree::deleteSubtree(Node* node)
{
  if (node == nullptr) {
    return;
  }
  deleteSubtree(node->left_);
  deleteSubtree(node->right_);
  delete node;
}
