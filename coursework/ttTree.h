#ifndef TTTREE_H
#define TTTREE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class ttTree
{
public:
  ttTree();
  void printTree(std::ostream& out = std::cout);
  void buildTree(std::ifstream& input);

private:
  struct node {
    node* left;
    node* middle;
    node* right;
    std::string leftKey;
    std::string rightKey;
    std::vector<int> leftLines;
    std::vector<int> rightLines;
  };
  node* root;
  std::vector<std::string> words;
  static ttTree::node* createNode(const std::string& x, node* left, node* middle);
  static bool isLeafNode(node* x);
  static node* add(node* x, node* n);
  node* insert(std::string& key, int line, node* x, int& distWord);
  static void printLines(node* x, bool isLeft, std::ostream& out);
  static void print(node* x, std::ostream& out);
  void printTreeHelper(node* x, std::ostream& out);
  int findHeight(node* x);
};

#endif