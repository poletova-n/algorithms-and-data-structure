#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>

#include "list.h"
#include "details.h"

class AVLTree
{
public:
  AVLTree() : root_(nullptr) {}
  ~AVLTree();
  AVLTree(const AVLTree&) = delete;
  AVLTree(AVLTree&&) = delete;
  AVLTree& operator= (const AVLTree&) = delete;
  AVLTree& operator= (AVLTree&&) = delete;
  size_t getCount() const;
  AVLTree& insert(std::string, std::string);
  List& search(std::string);
  void deleteKey(std::string);
  void printTree(std::ostream&);
private:
  struct Node
  {
    Node* left_;
    Node* right_;
    Node* parent_;
    std::string key_;
    List data_;
    size_t height_;
    int balanceFactor_;
    Node(std::string key)
    {
      if (!isKey(key))
      {
        throw myExceptions::ErrorSyntax("The prefix was syntactically incorrect.");
      }
      key_ = key;
      left_ = right_ = parent_ = nullptr;
      height_ = 1;
      balanceFactor_ = 0;
    }
  };
  
  Node* root_;
  void freesMemoryTree(Node*);
  size_t count(Node*) const;
  void rightRotation(Node*);
  void leftRotation(Node*);
  void rebalance(Node*);
  void printNode(Node*, std::ostream&);
  void calculateHeightBalance(Node*);

};

#endif
