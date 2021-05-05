#ifndef RBTREE
#define RBTREE
#include <iostream>
#include <string>
#include "SinglyLinkedOrderedList.h"
class RBTree
{
public:
  RBTree();
  void insert(std::string& word, SinglyLinkedOrderedList& synonyms);
  void remove(std::string& word);
  bool search(std::string& word);
  void print(std::ostream& output);
  void printHierarchy(std::ostream& output);
private:
  struct Node
  {
    std::string word_;
    SinglyLinkedOrderedList synonyms_;
    bool color_;
    Node* parent_;
    Node* right_;
    Node* left_;

    Node() :
      word_(nullptr),
      synonyms_(),
      color_(false),
      parent_(nullptr),
      right_(nullptr),
      left_(nullptr)
    {}

    Node(std::string word, const SinglyLinkedOrderedList& synonyms, bool color = false, Node* parent = nullptr,
        Node* right = nullptr, Node* left = nullptr):
      word_(word),
      synonyms_(synonyms),
      color_(true),
      parent_(nullptr),
      right_(nullptr),
      left_(nullptr)
    {}
  };

  Node* root_;

  void insertPrivate(std::string& word, SinglyLinkedOrderedList& synonyms);
  void insert1(Node *node);
  void insert2(Node *node);
  void insert3(Node *node);
  void insert4(Node *node);
  void insert5(Node *node);
  Node* grandparent(Node* node);
  Node* uncle(Node* node);
  Node* successor(Node* node);
  Node* sibling(Node* node);
  void leftRotate(Node* node);
  void rightRotate(Node* node);
  Node* searchNode(std::string& word);
  void deleteNode(Node* node);
  void fixUpTreeForRemove(Node* node);
  void printNode(std::ostream& output, Node* node);
  bool parse(std::string& word);
  void printNodeForHierarchy(std::ostream& output, Node* node);
};

#endif
