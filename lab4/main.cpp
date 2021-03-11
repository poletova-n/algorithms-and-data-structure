#include <iostream>
#include "BinarySearchTree.hpp"

int main()
{
  BinarySearchTree<int> a;
  a.addIterative(10);
  a.addIterative(5);
  a.addIterative(12);
  a.addIterative(3);
  a.addIterative(7);
  a.addIterative(2);
  a.addIterative(6);
  a.addIterative(8);
  std::cout << "Created tree with elements 10,5,12,3,8,7,6,2.\n";
  a.printInfo(3);
  if (a.findElement(7))
  {
    std::cout << "Element with value 7 was found\n";
  }
  std::cout << "Number of nodes is " << a.numberOfNodes() << "\n";
  std::cout << "Height of tree is " << a.height() << "\n";
  a.removeElement(5);
  std::cout << "Checking third node after deleting node with key 5: \n";
  a.printInfo(3);
  a.deleteTreeRecursive();
  return 0;
}

