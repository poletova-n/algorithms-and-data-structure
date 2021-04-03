#include <iostream>
#include "binarysearchtree.h"

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

  std::cout << "Source tree: ";
  intTree.print(std::cout);

  std::cout << "iterativeInorderWalk: ";
  intTree.iterativeInorderWalk();

  std::cout << "breadthways: ";
  intTree.breadthways();

  BinarySearchTree<int> intTree1;

  intTree1.insertRecursively(10);
  intTree1.insert(3);
  intTree1.insertRecursively(20);
  intTree1.insert(15);
  intTree1.insertRecursively(30);
  intTree1.insert(2);
  intTree1.insertRecursively(5);
  intTree1.insert(32);
  intTree1.insertRecursively(22);

  std::cout << "Next tree: ";
  intTree1.print(std::cout);
  std::cout << (intTree.isEqual(intTree1) ? "Equal" : "Not equal") << '\n';

  BinarySearchTree<int> intTree2;

  intTree2.insertRecursively(11);
  intTree2.insert(3);
  intTree2.insertRecursively(20);
  intTree2.insert(15);
  intTree2.insertRecursively(30);
  intTree2.insert(2);
  intTree2.insertRecursively(5);
  intTree2.insert(32);
  intTree2.insertRecursively(22);

  std::cout << "Next tree: ";
  intTree2.print(std::cout);
  std::cout << (intTree.isEqual(intTree2) ? "Equal" : "Not equal") << '\n';
  return 0;
}
