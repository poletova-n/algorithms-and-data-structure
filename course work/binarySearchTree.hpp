#ifndef COURSACH_BINARYSEARCHTREE_HPP
#define COURSACH_BINARYSEARCHTREE_HPP

#include <iostream>
#include <string>

#include "list.hpp"

class BinarySearchTree
{
public:
  BinarySearchTree();
  bool insert(std::string &word, List &translation);
  bool remove(std::string &word);
  bool search(std::string &word);
  void print(std::ostream &output);
  void printWithHierarchy(std::ostream &output);

private:
  struct node
  {
    std::string word_;
    List translation_;
    node *left_;
    node *right_;

    node() :
    word_(),
    translation_(),
    left_(nullptr),
    right_(nullptr)
    {}
  };

  node *root_;

  node *iterativeSearchNode(const std::string &word) const;
  void printNode(std::ostream& output, node* node);
  void printNodeWithHierarchy(std::ostream &output, node* node);
  void insert(node *node);
};

#endif
