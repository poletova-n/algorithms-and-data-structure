#include <iostream>
#include "binarytree.hpp"

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

  BinarySearchTree <int> intTree2;
  intTree2.insert(5);
  intTree2.insert(8);
  intTree2.insert(50);
  intTree2.insert(25);
  intTree2.insert(3);
  intTree2.insert(27);
  intTree2.insert(5);
  intTree2.insert(2);
  intTree2.insert(12);

  BinarySearchTree <int> copyTree;
  copyTree.insert(10);
  copyTree.insert(3);
  copyTree.insert(20);
  copyTree.insert(15);
  copyTree.insert(32);
  copyTree.insert(22);
  copyTree.insert(30);
  copyTree.insert(2);
  copyTree.insert(5);

  std::cout << "width traversal: ";
  intTree.traversalWidth(std::cout);
  std::cout << "\n \n";

  std::cout << "prefix traversal: ";
  intTree2.traversalPr(std::cout);
  std::cout << "\n \n";

  std::cout << "intTree and copyTree is ";
  if (intTree.isEqual(copyTree))
    std::cout << "EQUAL \n";
  else
    std::cout << "NOT EQUAL \n";

  std::cout << "intTree and intTree2 is ";
  if (intTree.isEqual(intTree2))
    std::cout << "EQUAL \n";
  else
    std::cout << "NOT EQUAL \n";

  return 0;
}
