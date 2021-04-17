#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <string>
#include <iostream>

#include "DoubleLinkedList.hpp"

class RedBlackTree
{
public:
  RedBlackTree():
    root_(nullptr)
  {}

  ~RedBlackTree();

  void add(std::string, std::string);
  bool remove(std::string);
  bool find(std::string) const;
  void print(std::ostream&) const;
private:
  struct Node
  {
    Node* right_;
    Node* left_;
    Node* parent_;
    bool color_; //true == red && false == black
    std::string key_;
    DoubleLinkedList value_;

    Node(std::string key, const DoubleLinkedList& value, bool color = true, Node* right = nullptr,
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

  void remove(Node*);
  void insertAsInBinary(Node*);
  void fixAfterInsertion(Node*);
  void fixAfterRemoval(Node*, Node*);
  void rotateLeft(Node*);
  void rotateRight(Node*);
  static void print(Node*, std::ostream&);
  static Node* findReplacement(Node*);
  static Node* getSibling(Node*, Node*);
  static DoubleLinkedList parseRussianStringByComma(std::string);
  static void deleteSubtree(Node*);
};

#endif
