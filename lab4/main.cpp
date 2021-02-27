#include <iostream>
#include "BinarySearchTree.h"
int main()
{
  std::cout << "Create first tree\n";
  BinarySearchTree<int> firstTree;
  std::cout << "Fill in first tree\n";
  firstTree.insert(45);
  firstTree.insert(-98);
  firstTree.insert(0);
  firstTree.insert(8);
  firstTree.insert(-9);
  firstTree.insert(100);
  firstTree.insert(9876);
  firstTree.insert(-3);
  firstTree.insert(3);
  std::cout << "Print first tree: \n";
  firstTree.print(std::cout);
  std::cout << "Let's try to add a key that already exists\n";
  firstTree.insert(3);
  std::cout << "Let's delete the key with the value 0 and print the tree\n";
  firstTree.deleteKey(0);
  firstTree.print(std::cout);
  std::cout << "Let's delete the key with the value 45 and print the tree\n";
  firstTree.deleteKey(45);
  firstTree.print(std::cout);
  std::cout << "Let's delete the key with the value 45(it is not in the tree)\n";
  firstTree.deleteKey(45);
  std::cout << "Number of keys in the tree: " << firstTree.getCount() << "\n";
  std::cout << "Tree height: " << firstTree.getHeight() << "\n";
  std::cout << "Infix tree traversal: " << "\n";
  firstTree.iterativeInorderWalk();
  std::cout << "Prefix tree traversal: " << "\n";
  firstTree.inorderWalk();
  std::cout << "Create second tree\n";
  BinarySearchTree<int> secondTree;
  std::cout << "We will not fill it in and compare it with the first tree: \n";
  std::cout << (!(secondTree == firstTree) ? "Trees are not equal\n" : "Trees are equal\n");
  std::cout << "Let's create a third tree and fill the second and third trees equally and check if they are equal\n";
  BinarySearchTree<int> thirdTree;
  thirdTree.insert(5);
  thirdTree.insert(9);
  thirdTree.insert(10);
  thirdTree.insert(4);
  thirdTree.insert(2);
  secondTree.insert(5);
  secondTree.insert(9);
  secondTree.insert(10);
  secondTree.insert(4);
  secondTree.insert(2);
  std::cout << (secondTree == thirdTree ? "Trees are equal\n" : "Trees are not equal\n");
  return 0;
}
