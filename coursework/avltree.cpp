#include "avltree.hpp"

AVLTree::AVLTree():
  head_(nullptr)
{}

AVLTree::~AVLTree()
{
  while (head_) {
    deleteNode(head_);
  }
}

void AVLTree::insert(std::string str)
{
  List data;
  size_t spacePosition = str.find(' ');
  std::string key;
  if (spacePosition == -1) {
    throw std::invalid_argument("ERROR: The place where must be word is empty!");
  }
  spacePosition = str.find('-');
  if ((spacePosition == -1) || (str.substr(spacePosition - 1, 3) != " - ")) {
    throw std::invalid_argument("ERROR: Incorrect enter, there must be \" - \"!");
  }
  key = str.substr(0, spacePosition - 1);
  spacePosition++;
  while (spacePosition != 0) {
    std::string temp;
    size_t nextSpacePosition = str.find(',', spacePosition + 1);
    nextSpacePosition++;
    if (nextSpacePosition == 0) {
      temp = str.substr(spacePosition + 1, str.length() - spacePosition);
      str = '\0';
    } else {
      if (str.substr(nextSpacePosition - 1, 2) != ", ") {
        throw std::invalid_argument("ERROR: incorrect enter translation of the word:" + str.substr(0, spacePosition - 1) +
            "there must be', '" + str.substr(nextSpacePosition, str.length() - nextSpacePosition));
      }
      temp = str.substr(spacePosition + 1, nextSpacePosition - spacePosition - 2);
    }
    data.push_back(temp);
    spacePosition = nextSpacePosition;
  }
  recursiveInsert(key, data, head_, nullptr);
  balance(head_);
}

void AVLTree::recursiveInsert(const std::string& key, List& data, AVLTree::Node*& node, AVLTree::Node* parent)
{
  if (!node) {
    node = new struct Node(key, data);
    node->parent_ = parent;
  } else {
    if (key > node->key_) {
      recursiveInsert(key, data, node->right_, node);
    } else if (key < node->key_) {
      recursiveInsert(key, data, node->left_, node);
    } else {
      if (data == node->data_) {
        throw std::invalid_argument("ERROR: Word " + key + " already exists with this translations!");
      } else {
        node->data_.merge(data);
      }
    }
  }
}

std::string AVLTree::search(const std::string& key) const
{
  if (!head_) {
    throw std::invalid_argument("ERROR: Search in empty dictionary is impossible!");
  }
  if (key.empty()) {
    throw std::invalid_argument("ERROR: Search empty key is impossible!");
  }
  Node* temp = searchNode(key);
  if (!temp) {
    throw std::invalid_argument("ERROR: Such key - " + key + " wasn't found!");
  }

  std::string tempStr;
  tempStr += "English word: ";
  tempStr += temp->key_;
  tempStr += ". Translation: ";

  for (auto i = temp->data_.begin(); i != temp->data_.end(); ++i) {
    tempStr += *i;
    ++i;
    if (i != temp->data_.end()) {
      tempStr += ", ";
    }
    --i;
  }

  return tempStr;
}

AVLTree::Node* AVLTree::searchNode(const std::string& key) const
{
  Node* temp = head_;
  while (temp->key_ != key) {
    if (key >= temp->key_) {
      if (temp->right_) {
        temp = temp->right_;
      } else {
        return nullptr;
      }
    } else {
      if (temp->left_) {
        temp = temp->left_;
      } else {
        return nullptr;
      }
    }
  }
  return temp;
}

void AVLTree::deleteKey(const std::string& key)
{
  if (!head_) {
    throw std::invalid_argument("ERROR: Delete from empty dictionary is impossible!");
  }
  if (key.empty()) {
    throw std::invalid_argument("ERROR: Delete empty key is impossible!");
  }
  Node* temp = searchNode(key);
  if (!temp) {
    throw std::invalid_argument("ERROR: Such key - " + key + " wasn't found");
  }
  deleteNode(temp);
  if (head_) {
    balance(head_);
  }
}

void AVLTree::deleteNode(AVLTree::Node* tempNode)
{
  if ((tempNode->right_ == nullptr) && (tempNode->left_ == nullptr)) {
    Node* par = tempNode->parent_;
    if (!par) {
      head_ = nullptr;
    } else if (par->right_ == tempNode) {
      par->right_ = nullptr;
    } else {
      par->left_ = nullptr;
    }
    delete tempNode;
  } else if ((tempNode->right_ != nullptr) && (tempNode->left_ != nullptr)) {
    Node* successor = treeSuccessor(tempNode);
    tempNode->key_ = successor->key_;
    deleteNode(successor);
    if (tempNode->parent_ == nullptr) {
      head_ = tempNode;
    }
  } else {
    Node* child;
    if (tempNode->right_ != nullptr) {
      child = tempNode->right_;
    } else {
      child = tempNode->left_;
    }
    Node* par = tempNode->parent_;
    if (par == nullptr) {
      head_ = child;
    } else if (par->right_ == tempNode) {
      par->right_ = child;
    } else {
      par->left_ = child;
    }
    child->parent_ = par;
    delete tempNode;
  }
}

AVLTree::Node* AVLTree::treeSuccessor(AVLTree::Node* node1, AVLTree::Node* node0)
{
  if (!node1) {
    return nullptr;
  } else if (node0) {
    if (node1->key_ >= node0->key_) {
      return node1;
    } else {
      return treeSuccessor(node1->parent_, node0);
    }
  } else if (node1->right_) {
    Node* node2 = node1->right_;
    while (node2->left_) {
      node2 = node2->left_;
    }
    return node2;
  } else {
    return treeSuccessor(node1->parent_, node1);
  }
}

int AVLTree::balanceFactor(AVLTree::Node* node)
{
  int balanceFactor = height(node->right_) - height(node->left_);
  return balanceFactor;
}

AVLTree::Node* AVLTree::balance(AVLTree::Node* node)
{
  fixHeight(node);
  if (balanceFactor(node) == 2) {
    if (balanceFactor(node->right_) < 0) {
      node->right_ = rotateRight(node->right_);
    }
    return rotateLeft(node);
  }
  if (balanceFactor(node) == -2) {
    if (balanceFactor(node->left_) > 0) {
      node->left_ = rotateLeft(node->left_);
    }
    return rotateRight(node);
  }
  return node;
}

AVLTree::Node* AVLTree::rotateRight(AVLTree::Node* node)
{
  AVLTree::Node* temp = node->left_;
  node->left_ = temp->right_;
  temp->right_ = node;
  fixHeight(node);
  fixHeight(temp);
  return temp;
}

AVLTree::Node* AVLTree::rotateLeft(AVLTree::Node* node)
{
  AVLTree::Node* temp = node->right_;
  node->right_ = temp->left_;
  temp->left_ = node;
  fixHeight(node);
  fixHeight(temp);
  return temp;
}

int AVLTree::height(AVLTree::Node* node)
{
  return node ? node->height_ : 0;
}

void AVLTree::fixHeight(AVLTree::Node* node)
{
  unsigned char heightLeft = height(node->left_);
  unsigned char heightRight = height(node->right_);
  node->height_ = (heightLeft > heightRight ? heightLeft : heightRight);
}

bool AVLTree::isWord(const std::string& word)
{
  return isRussianWord(word) || isEnglishWord(word);
}

bool AVLTree::isRussianWord(std::string elem)
{
  for (int i = 0; elem[i] != '\0'; i++ )
  {
    if (((static_cast<int>(elem[i]) >= 0) || (static_cast<int>(elem[i]) <= -65)) && static_cast<int>(elem[i]) != 32
        && static_cast<int>(elem[i]) != 47 && static_cast<int>(elem[i]) != 40 && static_cast<int>(elem[i]) != 41
        && static_cast<int>(elem[i]) != 45 && static_cast<int>(elem[i]) != 46)
    {
      return false;
    }
  }
  return true;
}

bool AVLTree::isEnglishWord(const std::string& elem)
{
  for (char i : elem)
  {
    if ((static_cast<int>(i) < 65 || static_cast<int>(i > 122)) && static_cast<int>(i) != 32) {
      return false;
    }
  }
  return true;
}

void AVLTree::printNode(std::ostream& out, AVLTree::Node* node) const
{
  if ((head_ == nullptr) || (node == nullptr)) {
    return;
  }
  printNode(out, node->left_);
  out << node->key_ + " - ";
  for (auto i = node->data_.begin(); i != node->data_.end(); ++i) {
    out << *i;
    ++i;
    if (i != node->data_.end()) {
      out << ", ";
    }
    --i;
  }
  out << '\n';
  printNode(out, node->right_);
}
void AVLTree::print(std::ostream& out) const
{
  printNode(out, head_);
}
