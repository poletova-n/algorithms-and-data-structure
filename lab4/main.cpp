#include <iostream>
#include "BinarySearchTree.h"

int main()
{
  BinarySearchTree<int> tree1;
  tree1.insert(50);
  std::cout << "Add: 50\n";
  tree1.insert(60);
  std::cout << "Add: 60\n";
  tree1.insert(40);
  std::cout << "Add: 40\n";
  tree1.insert(48);
  std::cout << "Add: 48\n";
  tree1.insert(45);
  std::cout << "Add: 45\n";
  tree1.insert(55);
  std::cout << "Add: 55\n";
  tree1.insert(60);
  std::cout << "Add: 60\n";
  tree1.insert(66);
  std::cout << "Add: 66\n";
  std::cout << "Recursive walk of first tree: ";
  tree1.inorderWalk();
  std::cout << "Counf of first tree: " << tree1.getCount() << '\n';
  std::cout << "Height of first tree: " << tree1.getHeight() << '\n';
  tree1.deleteKey(60);
  std::cout << "Delete: 60\n";
  tree1.deleteKey(45);
  std::cout << "Delete: 45\n";
  std::cout << "Recursive walk of first tree: ";
  tree1.inorderWalk();

  BinarySearchTree<int> tree2;
  tree2.insert(35);
  std::cout << "Add: 35\n";
  tree2.insert(10);
  std::cout << "Add: 10\n";
  tree2.insert(-6);
  std::cout << "Add: -6\n";
  tree2.insert(0);
  std::cout << "Add: 0\n";
  tree2.insert(30);
  std::cout << "Add: 30\n";
  tree2.insert(55);
  std::cout << "Add: 55\n";
  std::cout << "Iterative walk of second tree: ";
  tree2.iterativeInorderWalk();
  std::cout << "Count of second tree: " << tree2.getCount() << '\n';
  std::cout << "Height of second tree: " << tree2.getHeight() << '\n';
  std::cout << ((tree1 == tree2) ? "Trees are equal\n" : "Trees are not equal\n");
  return 0;
}
