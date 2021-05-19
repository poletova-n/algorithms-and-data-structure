#include "encryption.hpp"

#include <vector>
#include <algorithm>

#include "utility.hpp"

BinaryTree::Node* encryption::find(const BinaryTree::Node* node, std::vector<BinaryTree::Node*> vec)
{
  for (auto it = vec.begin(); it != vec.end(); ++it)
  {
    if ((*it)->key_ == node->key_)
    {
      return (*it);
    }
  }
  return nullptr;
}

std::vector<BinaryTree::Node*> encryption::makeTree(preparation::Symbols& map)
{
  std::vector<BinaryTree::Node*> arr;
  BinaryTree::Node* parent = nullptr;
  while (map.getMap().size() > 1)
  {
    auto first = map.findMin();
    std::pair<std::string, unsigned> firstPair = *(first);
    map.getMap().erase(first);
    auto second = map.findMin();
    std::pair<std::string, unsigned> secondPair = *(second);
    map.getMap().erase(second);
    std::string newString = firstPair.first + secondPair.first;
    unsigned newFreq = firstPair.second + secondPair.second;
    BinaryTree::Node* firstNode = new BinaryTree::Node(firstPair.first);
    BinaryTree::Node* secondNode = new BinaryTree::Node(secondPair.first);
    auto firstChild = find(firstNode, arr);
    auto secondChild = find(secondNode, arr);
    if (firstChild == nullptr)
    {
      if (secondChild == nullptr)
      {
        parent = new BinaryTree::Node(newString, firstNode, secondNode);
      }
      else
      {
        parent = new BinaryTree::Node(newString, firstNode, secondChild);
        delete secondNode;
      }
    }
    else
    {
      if (secondChild == nullptr)
      {
        parent = new BinaryTree::Node(newString, firstChild, secondNode);
        delete firstNode;
      }
      else
      {
        parent = new BinaryTree::Node(newString, firstChild, secondChild);
        delete firstNode;
        delete secondNode;
      }
    }
    if (firstChild == nullptr)
    {
      firstNode->p_ = parent;
      arr.push_back(firstNode);
    }
    else
    {
      firstChild->p_ = parent;
    }
    if (secondChild == nullptr)
    {
      secondNode->p_ = parent;
      arr.push_back(secondNode);
    }
    else
    {
      secondChild->p_ = parent;
    }
    arr.push_back(parent);
    map.getMap().insert({newString, newFreq});
  }
  return arr;
}

void encryption::buildTable(BinaryTree::Node* root, std::vector<bool>& code, std::map<char, std::vector<bool>>& table)
{
  if (root->left_)
  {
    code.push_back(0);
    buildTable(root->left_, code, table);
  }
  if (root->right_)
  {
    code.push_back(1);
    buildTable(root->right_, code, table);
  }
  if (root->key_.size() == 1)
    table[root->key_[0]] = code;
  if (code.size())
    code.pop_back();
}

std::map<char, std::vector<bool>> encryption::makeTable(std::vector<BinaryTree::Node*> vec)
{
  BinaryTree::Node* root = details::findRoot(vec);
  std::vector<bool> code;
  std::map<char, std::vector<bool>> table;
  buildTable(root, code, table);
  return table;
}

std::vector<bool> encryption::encrypt(std::vector<char> vec, std::map<char, std::vector<bool>> table)
{
  std::vector<bool> encryptedText;
  for (auto it = vec.begin(); it != vec.end(); ++it)
  {
    char sym = *it;
    for (auto i = table[sym].begin(); i != table[sym].end(); ++i)
    {
      encryptedText.push_back(*i);
    }
  }
  return encryptedText;
}

std::vector<char> decryption::decrypt(std::vector<bool>& enc, BinaryTree::Node* root)
{
  std::vector<char> text;
  BinaryTree::Node* temp = root;
  while (!enc.empty())
  {
    bool c = enc.front();
    if (c)
    {
      if (temp->right_ == nullptr)
      {
        text.push_back(temp->key_[0]);
        temp = root;
      }
      else
      {
        temp = temp->right_;
        enc.erase(enc.begin());
      }
    }
    else
    {
      if (temp->left_ == nullptr)
      {
        text.push_back(temp->key_[0]);
        temp = root;
      }
      else
      {
        temp = temp->left_;
        enc.erase(enc.begin());
      }
    }
  }
  text.push_back(temp->key_[0]);
  return text;
}
