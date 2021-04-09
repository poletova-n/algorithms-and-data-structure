#include <iostream>
#include "QueueArray.h"
#include "Tree.h"

int main()
{
  QueueArray<int> queue(5);
  queue.enQueue(5);
  queue.enQueue(6);
  queue.enQueue(2);
  queue.enQueue(8);
  queue.enQueue(20);
  queue.printQueue();

  std::cout << "\n---------------Binary tree---------------\n";

  Tree<int> tree;
  tree.insert(10);
  tree.insert(5);
  tree.insert(11);
  tree.insert(12);
  tree.insert(2);
  tree.insert(25);
  std::cout << "Tree\n";
  tree.print(std::cout);
  std::cout << "Breadth tree traversal: ";
  tree.breadthFirstWalk();
  std::cout << "Prefix tree traversal: ";
  tree.iterativeInorderWalk(true);
  Tree<int> treeTwo;
  std::cout << "Second tree\n";
  treeTwo.insert(10);
  treeTwo.insert(3);
  treeTwo.insert(15);
  treeTwo.insert(11);
  treeTwo.insert(2);
  treeTwo.insert(42);
  std::cout << "Tree\n";
  treeTwo.print(std::cout);
  std::cout << "Check compare trees";
  std::cout << (tree.isSimilar(treeTwo)? "True" : "False");
  return 0;
}
