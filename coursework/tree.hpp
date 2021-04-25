#ifndef LAB8_TREE_HPP
#define LAB8_TREE_HPP

#include <string>
#include <iostream>

#include "list.hpp"

class Tree
{
public:
  Tree():
    root_(nullptr)
  {}

  ~Tree();

  void insert(std::string, std::string);
  void remove(std::string);
  bool search(std::string) const;
  void print(std::ostream&) const;
private:
  struct Node
  {
    bool color_;
    std::string key_;
    List value_;
    Node* right_;
    Node* left_;
    Node* parent_;

    Node(std::string key, const List& value, bool color = true, Node* right = nullptr,
         Node* left = nullptr, Node* parent = nullptr):
      right_(right),
      left_(left),
      parent_(parent),
      color_(color),
      key_(key),
      value_(value)
    {}
  };
  Node* root_;

  void rotateLeft(Node* node);
  void rotateRight(Node* node);
  static void print(Node* node, std::ostream& out);
  static Node* find(Node* node);
  static List parse(std::string synonymString);
  static void deleteSubtree(Node* node);
  void deleteKey(Node* node);
};

#endif
