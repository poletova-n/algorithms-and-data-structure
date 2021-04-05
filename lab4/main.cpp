#include <iostream>
#include"BinarySearchTree.hpp"

int main ()
{
  BinarySearchTree <int> intTree;

  intTree.insert(1);
  intTree.insert(2);
  intTree.insert(3);
  intTree.insert(4);
  intTree.insert(5);
  intTree.insert(6);
  intTree.insert(7);
  intTree.insert(8);
  intTree.insert(81);
  intTree.insert(9);

  intTree.print(std::cout);

  int keyFound = intTree.iterativeSearch(8);

  std::cout << "Key " << 15 << (keyFound ? " found successfully" : " not found") << " in the tree" << std::endl;

  keyFound = intTree.iterativeSearch(10);

  std::cout << "Key " << 10 << (keyFound ? " found successfully" : " not found") << " in the tree" << std::endl;

  std::cout << "height = " << intTree.getHeight() << std::endl;

  std::cout << "count = " << intTree.getCount() << std::endl;

  intTree.deleteKey(8);

  intTree.print(std::cout);
  
  return 0;
}