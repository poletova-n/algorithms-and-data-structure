#include <iostream>

#include "binarySearchTree.h"
#include "queue.h"

int main()
{
  QueueArray<int> queue(5);
  queue.enQueue(5);
  queue.enQueue(7);
  queue.enQueue(0);
  try
  {
    queue.enQueue(9);
  }
  catch (const QueueOverflow& e)
  {
    std::cerr << e.what() << '\n';
  }
  for (size_t i = 0; i < 4; i++)
  {
    try
    {
      std::cout << queue.deQueue() << ' ';
    }
    catch (const QueueUnderflow& e)
    {
      std::cout << '\n';
      std::cerr << e.what() << '\n';
    }
  }
  std::cout << "Queue is empty: " << std::boolalpha
            << queue.isEmpty() << '\n';
  queue.enQueue(8);
  queue.enQueue(10);
  std::cout << queue.deQueue() << ' ';
  queue.enQueue(-81);
  std::cout << queue.deQueue() << ' '
            << queue.deQueue() << '\n';

  BinarySearchTree<int> emptyTree;
  emptyTree.breadthFirstWalk();
  emptyTree.iterativeInorderWalk();

  BinarySearchTree<int> pathologicalTree;
  pathologicalTree.insert(1);
  pathologicalTree.insert(5);
  pathologicalTree.insert(8);
  pathologicalTree.insert(16);
  pathologicalTree.insert(59);
  pathologicalTree.insert(101);
  pathologicalTree.breadthFirstWalk();
  pathologicalTree.iterativeInorderWalk();

  BinarySearchTree<int> tree1;
  tree1.insert(72);
  tree1.insert(23);
  tree1.insert(75);
  tree1.insert(28);
  tree1.insert(50);
  tree1.breadthFirstWalk();
  tree1.iterativeInorderWalk();

  std::cout << "Create similar tree\n";
  BinarySearchTree<int> tree2;
  tree2.insert(28);
  tree2.insert(72);
  tree2.insert(50);
  tree2.insert(23);
  tree2.insert(75);
  std::cout << "Trees are equal: "
            << (tree1 == tree2) << '\n'
            << "Trees are similar: "
            << tree1.isSimilar(tree2) << '\n';

  return 0;
}
