#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#ifdef WIN32
#include <windows.h>
#endif

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

class AVLTree {
public:
  using List = std::list<std::string>;

  AVLTree();
  ~AVLTree();
  void insert(std::string str);
  [[nodiscard]] std::string search(const std::string& key) const;
  void deleteKey(const std::string& key);
  void print(std::ostream&) const;

private:
  struct Node {
    std::string key_;
    List data_;
    unsigned char height_;
    Node* left_;
    Node* right_;
    Node* parent_;
    Node(const std::string& str, List& list)
    {
      if(!isWord(str))
      {
        throw std::invalid_argument("ERROR: " + str + " isn't english word!");
      }
      key_ = str;
      data_ = list;
      parent_ = left_ = right_ = nullptr;
      height_ = 1;
    }
  };

  Node* head_;
  Node* treeSuccessor(Node* node1, Node* node0 = nullptr);
  [[nodiscard]] Node* searchNode(const std::string& key) const;
  static Node* balance(Node* node);
  static Node* rotateLeft(Node* node);
  static Node* rotateRight(Node* node);
  void recursiveInsert(const std::string& key, List& data, Node*& node, struct Node* parent = nullptr);
  void deleteNode(Node* node);
  static void fixHeight(Node* node);
  static int height (Node* node) ;
  static int balanceFactor(Node* node) ;
  static bool isWord(const std::string& str);
  static bool isRussianWord(std::string elem);
  static bool isEnglishWord(const std::string& elem);
  void printNode(std::ostream&, Node*) const;
};

#endif
