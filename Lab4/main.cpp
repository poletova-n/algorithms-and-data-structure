#include "tree.h"
#include <iostream>

int main()
{
  BinarySearchTree<int> tree;
  tree.iterativeAppend(5);
  tree.iterativeAppend(9);
  tree.iterativeAppend(6);
  tree.iterativeAppend(8);
  tree.iterativeAppend(4);
  tree.recursiveAppend(10);
  tree.recursiveAppend(17);
  tree.recursiveAppend(19);
  tree.recursiveAppend(16);
  //creating a tree and adding elements

  tree.printInfo(std::cout, 6);
  std::cout << "Tree height: " << tree.getHeight() << '\n';
  std::cout << "Tree size: " << tree.getSize() << '\n';
  tree.deleteElement(10);
  std::cout << "Watch if there is element 10 left: " << '\n';
  tree.printInfo(std::cout, 10);
  tree.freeMemory();
  std::cout << "Called free method. " << '\n';
  return 0;
}