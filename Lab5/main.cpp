#include <iostream>

#include "queueArray.h"
#include "tree.h"

int main()
{
  QueueArray<int> queue(5);

  queue.enQueue(5);
  queue.enQueue(6);
  queue.enQueue(2);
  queue.enQueue(8);
  queue.enQueue(20);
  queue.printQueue();

  std::cout << "\nTree";

  Tree<int> tree1;
  tree1.insert(21);
  tree1.insert(11);
  tree1.insert(2000);
  tree1.insert(9);
  tree1.insert(3);
  tree1.insert(7);
  tree1.insert(1);

  tree1.print(std::cout);

  std::cout << "Breadth tree traversal: ";
  tree1.breadthFirstWalk();

  std::cout << "Prefix tree traversal: ";
  tree1.iterativeInorderWalk(true);

  Tree<int> tree2;
  std::cout << "Second tree ";

  tree2.insert(10);
  tree2.insert(3);
  tree2.insert(15);
  tree2.insert(11);
  tree2.insert(2);
  tree2.insert(42);

  tree2.print(std::cout);

  std::cout << "\nTree comparasion ";
  if (tree1.isSimilar(tree2))
  {
    std::cout << "true\n";
  }
  else
  {
    std::cout << "false\n";
  }

  return 0;
}
