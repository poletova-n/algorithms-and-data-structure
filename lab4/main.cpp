#include <iostream>
#include "binarySearchTree.h"

int main()
{
  BinarySearchTree<int> tree;
  tree.insert(5);
  tree.insert(7);
  tree.insert(3);
  tree.insert(4);
  tree.print(std::cout);
  std::cout << "\n";
  tree.deleteKey(3);
  tree.print(std::cout);
  std::cout << "\n";
  tree.insert(2);
  tree.insert(10);
  tree.insert(8);
  tree.insert(17);
  tree.print(std::cout);
  std::cout << "\n";
  tree.deleteKey(7);
  tree.print(std::cout);
  std::cout << "\n";
  tree.insert(3);
  tree.insert(1);
  tree.insert(6);
  tree.insert(11);
  tree.print(std::cout);
  std::cout << "\n";
  std::cout << "The number of Nodes is: ";
  std::cout << tree.getCount();
  std::cout << "\n";
  std::cout << "The height is: ";
  std::cout << tree.getHeight();
  std::cout << "\n";
  std::cout << "\n";
  return 0;
}
