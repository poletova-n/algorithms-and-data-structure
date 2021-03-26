#include "binarysearchtree.h"
#include <iostream>

int main()
{
  BinarySearchTree<int> intTree;

  intTree.insertRecursively(10);
  intTree.insert(3);
  intTree.insertRecursively(20);
  intTree.insert(15);
  intTree.insertRecursively(30);
  intTree.insert(2);
  intTree.insertRecursively(5);
  intTree.insert(32);
  intTree.insertRecursively(22);

  intTree.print(std::cout);

  auto keyFound = intTree.iterativeSearch(15);
  std::cout << "Key " << 15 <<
       (keyFound ? " found successfully" : " not found") <<  " in the tree\n";

  keyFound = intTree.iterativeSearch(23);
  std::cout << "Key " << 23 <<
       (keyFound ? " found successfully" : " not found") <<
       " in the tree\n";

  std::cout << "height = " << intTree.getHeight() << '\n';
  std::cout << "count = " << intTree.getCount () << '\n';
  return 0;
}