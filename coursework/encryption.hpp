#ifndef COURSEWORK_ENCRYPTION_HPP
#define COURSEWORK_ENCRYPTION_HPP

#include <string>
#include <utility>
#include <vector>

#include "utility.hpp"
#include "BinaryTree.hpp"
#include "List.hpp"

namespace encryption
{
  std::vector<bool> encrypt(std::vector<char>, std::map<char, std::vector<bool>>);

  std::vector<BinaryTree::Node*> makeTree(preparation::Symbols&);

  BinaryTree::Node* find(const BinaryTree::Node*, std::vector<BinaryTree::Node*>);

  std::map<char, std::vector<bool>> makeTable(std::vector<BinaryTree::Node*>);

  void buildTable(BinaryTree::Node*, std::vector<bool>&, std::map<char, std::vector<bool>>&);
}

namespace decryption
{
  std::vector<char> decrypt(std::vector<bool>&, BinaryTree::Node*);
}

#endif //COURSEWORK_ENCRYPTION_HPP
