#include <iostream>
#include "BinarySearchTree.hpp"

int main()
{
  BinarySearchTree<int> tree;

  tree.insert(1);
  tree.insertRecursive(2);
  tree.insert(3);
  tree.insertRecursive(4);
  tree.insertRecursive(5);
  tree.insert(6);

  BinarySearchTree<int> treeTwo;

  treeTwo.insert(1);
  treeTwo.insertRecursive(2);
  treeTwo.insert(3);
  treeTwo.insertRecursive(4);
  treeTwo.insertRecursive(5);
  treeTwo.insert(6);

  std::cout << "Width Traversal:\n";
  tree.widthTraversal(std::cout);
  std::cout << '\n'

            << "Prefix Traversal:\n";
  tree.prefixTraversal(std::cout, true);
  std::cout << '\n'

            << "Compare Trees:\n";
  std::cout << (tree.sameTrees(treeTwo) ? "True" : "False");
  return 0;
}
