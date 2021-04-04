#include "binarytree.hpp"
#include <iostream>

int main()
{
  BinarySearchTree <int> intTree;
  intTree.insert(10);
  intTree.insert(3);
  intTree.insert(20);
  intTree.insert(15);
  intTree.insert(30);
  intTree.insert(2);
  intTree.insert(5);
  intTree.insert(32);
  intTree.insert(22);
  intTree.recursiveInsert(45);

  intTree.print(std::cout);

  intTree.deleteKey(5);
  intTree.print(std::cout);
  int keyFound = intTree.iterativeSearch(15);
  std::cout << "Key 15" <<
       (keyFound ? " found successfully" : " not found") << " in the tree" << std::endl;
  keyFound = intTree.iterativeSearch(23);
  std::cout << "Key 23" <<
       (keyFound ? " found successfully" : " not found") <<
       " in the tree" << std::endl;
  keyFound = intTree.iterativeSearch(45);
  std::cout << "Key 45" <<
            (keyFound ? " found successfully" : " not found") <<
            " in the tree" << std::endl;

  std::cout << "height = " << intTree.getHeight() << std::endl;
  std::cout << "count = " << intTree.getCount () << std::endl;

  intTree.deleteKey(45);
  intTree.print(std::cout);
  std::cout << "Tests after delete 45" << std::endl;

  intTree.print(std::cout);
  std::cout << "count = " << intTree.getCount () << std::endl;
  keyFound = intTree.iterativeSearch(45);
  std::cout << "Key 45" <<
            (keyFound ? " found successfully" : " not found") <<
            " in the tree" << std::endl;

  intTree.printByKey(std::cout, 2);
  intTree.printByKey(std::cout, 20);

  intTree.findNext(std::cout, 10);

  intTree.freeMemory();

  std::cout << "Test after delete all elements" << std::endl;
  std::cout << "height = " << intTree.getHeight() << std::endl;
  std::cout << "count = " << intTree.getCount () << std::endl;
  return 0;
}
