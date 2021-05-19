#ifndef COURSEWORK_BINARYTREE_HPP
#define COURSEWORK_BINARYTREE_HPP

#include <string>

class BinaryTree
{
public:
  struct Node
  {
    std::string key_;
    Node* left_;
    Node* right_;
    Node* p_;
    Node(std::string key, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr) :
      key_(key),
      left_(left),
      right_(right),
      p_(parent)
    {}
  };

  BinaryTree();
  BinaryTree(const BinaryTree& other) = delete;
  BinaryTree(BinaryTree&& other) noexcept;

  BinaryTree& operator=(const BinaryTree& other) = delete;
  BinaryTree& operator=(BinaryTree&& other) noexcept;

  ~BinaryTree() = default;

private:
  Node* root_;
};

#endif //COURSEWORK_BINARYTREE_HPP
