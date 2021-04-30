#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>
class AvlTree
{
public:
  AvlTree();
  AvlTree(const AvlTree& src) = delete;
  AvlTree(AvlTree&& src) noexcept;

  AvlTree& operator= (const AvlTree& src) = delete;
  AvlTree& operator=(AvlTree&& src) noexcept;

  ~AvlTree();

  bool insert(const std::string& key);

  bool deleteKey(const std::string& key);

  void print(std::ostream& out) const;

  int getFrequency(const std::string& key) const;

  int getHeight() const;

  void inorderWalk(std::ostream& out) const;

  bool iterativeSearch(const std::string& key)  const;

  int getCount();

  void printMostCommonWords(std::ostream& out);

  bool isBalanced() const;

private:
  struct Node
  {
    std::string key_;
    Node* left_;
    Node* right_;
    Node* p_;
    int height_;
    int balanceFactor_;
    int frequency_;

    Node(std::string key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr, int height = 0, int balanceFactor = 0, int frequency = 1) :
      key_(key),
      left_(left),
      right_(right),
      p_(p),
      height_(height),
      balanceFactor_(balanceFactor),
      frequency_(frequency)
    { }
  };

  Node* root_;

  void swap(AvlTree& src);

  void deleteSubtree(Node* node);

  Node* iterativeSearchNode(const std::string& key) const;

  void printNode(std::ostream& out, Node* root) const;

  void inorderWalk(std::ostream& out, Node* node) const;

  Node* treeMinimum(Node* root);

  int getHeightSubTree(Node* node) const;

  Node* makeRightSmallRotate(Node* tree);

  Node* makeLeftSmallRotate(Node* tree);

  int getBalanceFactor(Node* node) const;

  void fixNodeHeight(Node* node);

  Node* balanceTree();

  int getCountSubTree(Node* node) const;
};
#endif
