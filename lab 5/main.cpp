#include <iostream>
#include "BinarySearchTree.h"
#include "QueueArray.hpp"

int main()
{
  std::cout << "QueueArray class test, сreate a queue for 5 items:\n";
  QueueArray<int> test(5);
  test.print();
  try
  {
    std::cout << "Fill the queue for the test\n";
    test.enQueue(1);
    test.enQueue(6);
    test.enQueue(90);
    test.enQueue(12);
    test.print();
  }
  catch (QueueUnderflow error)
  {
    std::cerr << error.what();
  }
  try
  {
    std::cout << "Checking the correctness of deleting items in the queue\n";
    test.deQueue();
    test.deQueue();
    test.print();
    test.deQueue();
    test.deQueue();
    test.print();
  }
  catch (QueueOverflow error)
  {
    std::cerr << error.what();
  }
  std::cout << "\nBinary tree method test:\n";
  BinarySearchTree<int> testTree;
  std::cout << "Let's add different values to our tree \n"
            << "(The entered elements can be repeated, the program takes this into account and displays a message) \n";
  testTree.insert(1);
  testTree.insert(5);
  testTree.insert(7);
  testTree.insert(-1);
  testTree.insert(7);
  testTree.insert(4);
  testTree.insert(-100);
  testTree.insert(45);
  testTree.insert(-12);
  testTree.insert(23);
  testTree.insert(13);
  testTree.insert(666);
  std::cout << "The current state of the tree: ";
  testTree.print(std::cout);
  std::cout << "Iterative traversal of a binary tree:\n";
  testTree.iterativeInorderWalk();
  std::cout << "Breadth traversal of a binary tree:\n";
  testTree.breadthFirstWalk();
  std::cout << "\nTest method similar trees:\n";
  BinarySearchTree<int> secondTestTree;
  std::cout << "Second tree\n";
  secondTestTree.insert(666);
  secondTestTree.insert(5);
  secondTestTree.insert(7);
  secondTestTree.insert(-1);
  secondTestTree.insert(4);
  secondTestTree.insert(7);
  secondTestTree.insert(-100);
  secondTestTree.insert(45);
  secondTestTree.insert(23);
  secondTestTree.insert(-12);
  secondTestTree.insert(13);
  secondTestTree.insert(1);
  std::cout << "The current state of the second tree: ";
  testTree.print(std::cout);
  std::cout << "All items in the first and second trees in ascending order:\n";
  if (testTree.isSimilarTree(secondTestTree))
  {
    std::cout << "Trees are similar\n";
  }
  else
  {
    std::cout << "Trees are not similar\n";
  }
  std::cout << "\nMake the trees look different and repeat the test:\n";
  secondTestTree.deleteKey(13);
  secondTestTree.insert(18);
  if (testTree.isSimilarTree(secondTestTree))
  {
    std::cout << "Trees are similar\n";
  }
  else
  {
    std::cout << "Trees are not similar\n";
  }
  return 0;
}
