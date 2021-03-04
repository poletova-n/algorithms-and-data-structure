#include <iostream>
#include "BinarySearchTree.h"

int main()
{
  std::cout << "BinarySearchTree project\n"
            << "---------------------------------------------------------\n";
  BinarySearchTree<int> test;
  std::cout << "Let's add different values to our tree \n"
            << "(The entered elements can be repeated, the program takes this into account and displays a message) \n";
  test.insert(1);
  test.insert(5);
  test.insert(7);
  test.insert(-1);
  test.insert(7);
  test.insert(4);
  test.insert(-100);
  test.insert(45);
  test.insert(-12);
  test.insert(23);
  test.insert(13);
  test.insert(666);
  std::cout << "The current state of the tree: ";
  test.print(std::cout);
  std::cout << "Tree height: " << test.getHeight() << "\n"
            << "Number of elements in the tree: " << test.getCount() << "\n";
  std::cout << "Let's try to find elements in our tree:\n"
            << "13: " << (test.iterativeSearch(13) ? "found" : "not found") << "\n"
            << "228: " << (test.iterativeSearch(228) ? "found" : "not found") << "\n"
            << "-12: " << (test.iterativeSearch(-12) ? "found" : "not found") << "\n"
            << "1000: " << (test.iterativeSearch(1000) ? "found" : "not found") << "\n";
  std::cout << "An infix traversal of our tree: ";
  test.inorderWalk();
  std::cout << "\nLet's remove elements from our tree:\n"
            << "(If this element is not in the tree, a message appears)\n";
  test.deleteKey(45);
  test.deleteKey(-12);
  test.deleteKey(228);
  test.deleteKey(-100);
  std::cout << "The current state of the tree: ";
  test.print(std::cout);
  std::cout << "Operator test == :" << "\n";
  BinarySearchTree<int> comparisonTreeOne;
  BinarySearchTree<int> comparisonTreeTwo;
  comparisonTreeOne.insert(3);
  comparisonTreeOne.insert(38);
  comparisonTreeOne.insert(-100);
  comparisonTreeOne.insert(10);
  comparisonTreeTwo.insert(3);
  comparisonTreeTwo.insert(38);
  comparisonTreeTwo.insert(-100);
  comparisonTreeTwo.insert(10);
  std::cout << "First tree:";
  comparisonTreeOne.print(std::cout);
  std::cout << "Second tree:";
  comparisonTreeTwo.print(std::cout);
  std::cout << ((comparisonTreeOne==comparisonTreeTwo) ? "Trees are equal" : "Trees are not equal") << "\n";
  comparisonTreeTwo.insert(-1000);
  std::cout << "First tree:";
  comparisonTreeOne.print(std::cout);
  std::cout << "Second tree:";
  comparisonTreeTwo.print(std::cout);
  std::cout << ((comparisonTreeOne==comparisonTreeTwo) ? "Trees are equal" : "Trees are not equal") << "\n";
  return 0;
}
