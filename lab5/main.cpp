#include <iostream>
#include "myException.h"
#include "queueArray.h"
#include "queueLinkList.h"
#include "binarySearchTree.h"

int main()
{
  // Error in the object declaration
  try
  {
    QueueArray<int> errorQueue(-3);
    errorQueue.enQueue(2);
    std::cout << errorQueue.isEmpty() << '\n';
  }
  catch (WrongQueueSize& exp)
  {
	  std::cout << exp.what() << "\n\n";
  }

  //Successful object declaration

  std::cout << "Queue with array:\n";
  QueueArray<int> queueArray(5);
  std::cout << "Queue status(haven't added an element yet): " << ((queueArray.isEmpty()) ? "empty.\n" : "not empty.\n");

  for (int i = 0; i < 5; i++)
  {
	queueArray.enQueue(i + 10);
  }
  std::cout << "Queue status(when adding an element): " << ((queueArray.isEmpty()) ? "empty.\n" : "not empty.\n");
  try
  {
    queueArray.enQueue(100);
  }
  catch (QueueOverflow& exp)
  {
    std::cout << exp.what() << '\n';
  }
  for (int i = 0; i < 5; i++)
  {
    std::cout << queueArray.deQueue() << "  ";
  }
  std::cout << '\n';
  try
  {
    std::cout << queueArray.deQueue();
  }
  catch (QueueUnderflow& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << '\n';



  std::cout << "Queue with list:\n";
  QueueLinkList<int> queueList;
  std::cout << "Queue status(haven't added an element yet): " << ((queueList.isEmpty()) ? "empty.\n" : "not empty.\n");
  for (int i = 0; i < 8; i++)
  {
    queueList.enQueue(i + 20);
  }
  std::cout << "Queue status(when adding an element): " << ((queueList.isEmpty()) ? "empty.\n" : "not empty.\n");
  for (int i = 0; i < 8; i++)
  {
    std::cout << queueList.deQueue() << "  ";
  }
  std::cout << '\n';
  try
  {
    std::cout << queueList.deQueue();
  }
  catch (QueueUnderflow& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\n\n";

  //===============================================//
  //Test the developed classes and methods:
  //Iterative Algorithms for Traversing Binary Trees

  BinarySearchTree<int> tree;
  tree.insertIterative(4);
  tree.insertIterative(10);
  tree.insertIterative(0);
  tree.insertIterative(3);
  tree.insertIterative(1);
  tree.insertIterative(8);
  tree.insertIterative(9);
  tree.insertCursive(12);
  tree.insertCursive(5);
  tree.insertCursive(14);
  size_t count = tree.getCount();
  std::cout << "The number of elements in the tree: " << count << '\n';
  QueueLinkList<int> dataTree1 = tree.browseTreeWidth();
  std::cout << "Browsing a binary tree level by level (widthwise): \n";
  for (size_t i = 0; i < count; i++)
  {
    std::cout << dataTree1.deQueue() << "  ";
  }
  std::cout << "\n\n";

  QueueLinkList<int> dataTree2 = tree.browseTreePrefix();
  std::cout << "Browsing a binary tree from left to right(prefix): \n";
  for (size_t i = 0; i < count; i++)
  {
    std::cout << dataTree2.deQueue() << "  ";
  }
  std::cout << "\n\n";

  BinarySearchTree<int> tree2;
  tree2.insertIterative(4);
  tree2.insertIterative(10);
  tree2.insertIterative(0);
  tree2.insertIterative(3);
  tree2.insertIterative(1);
  tree2.insertIterative(8);
  tree2.insertIterative(9);
  tree2.insertCursive(12);
  tree2.insertCursive(5);
  tree2.insertCursive(14);
  std::cout << (tree2.sameTrees(tree) ? "The second tree is like the first" : "The second tree is not the same as the first");
  std::cout << "\n\n";
  std::cout << "After adding 1 element. \n";
  tree2.insertCursive(-1);
  std::cout << (tree2.sameTrees(tree) ? "The second tree is like the first" : "The second tree is not the same as the first");
  std::cout << '\n';

	return 0;
}
