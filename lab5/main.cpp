#include <iostream>
#include "queueArray.hpp"
#include "BinarySearchTree.hpp"
int main() {
    try
    {
      std::cout << "Testing exceptions\n";
      QueueArray<int> Queue(3);
      Queue.enQueue(1);
      Queue.enQueue(2);
      Queue.enQueue(3);
      Queue.enQueue(4);
      Queue.enQueue(5);
      Queue.enQueue(6);
    }
    catch (const QueueOverflow &e)
    {
      std::cout << "\n" << e.what() << "\n";
    }
    try
    {
      QueueArray<int> Queue(9);
      Queue.enQueue(1);
      Queue.enQueue(2);
      Queue.enQueue(3);
      Queue.deQueue();
      Queue.deQueue();
      Queue.deQueue();
      Queue.deQueue();
    }
    catch (const QueueUnderflow &e)
    {
      std::cout << "\n" << e.what() << "\n";
    }
  try
  {
    QueueArray<int> Queue(-9);
  }
  catch (const WrongQueueSize &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
    try
    {
      std::cout << "\nTesting queue(deleting and adding items)\n";
      QueueArray<int> Queue(6);
      Queue.enQueue(2);
      Queue.enQueue(3);
      Queue.enQueue(4);
      Queue.enQueue(5);
      std::cout << "\nQueue: ";
      Queue.printQueue(std::cout);
      std::cout << "\nDelete 2 times\n";
      Queue.deQueue();
      Queue.deQueue();
      Queue.printQueue(std::cout);
      std::cout << "\nInsert 1, 1, 3, -8\n";
      Queue.enQueue(1);
      Queue.enQueue(1);
      Queue.enQueue(3);
      Queue.enQueue(-8);
      Queue.printQueue(std::cout);
    }
    catch (const QueueUnderflow &e)
    {
      std::cerr << "\n" << e.what() << "\n";
    }
    catch (const QueueOverflow &e)
    {
      std::cerr << "\n" << e.what() << "\n";
    }
    catch (const WrongQueueSize &e)
    {
      std::cout << "\n" << e.what() << "\n";
    }

  BinarySearchTree<double> tree1;
  std::cout << "\n\n\nTesting tree\ntree1\n";
  if (tree1.insert(8))
    std::cout << "8 added\n";
  if (tree1.insert(9))
    std::cout << "9 added\n";
  if (tree1.insert(-6))
    std::cout << "-6 added\n";
  if (tree1.insert(-8.56))
    std::cout << "-8.56 added\n";
  if (tree1.insert(4.79))
    std::cout << "4.79 added\n";
  if (tree1.insert(0))
    std::cout << "0 added\n";

  BinarySearchTree<double> tree2;
  std::cout << "tree2\n";
  if (tree2.insert(8))
    std::cout << "8 added\n";
  if (tree2.insert(9))
    std::cout << "9 added\n";
  if (tree2.insert(-6))
    std::cout << "-6 added\n";
  if (tree2.insert(-8.56))
    std::cout << "-8.56 added\n";
  if (tree2.insert(4.79))
    std::cout << "4.79 added\n";
  if (tree2.insert(0))
    std::cout << "0 added\n";

  BinarySearchTree<double> tree3;
  std::cout << "tree3\n";
  if (tree3.insert(1))
    std::cout << "1 added\n";
  if (tree3.insert(1.8))
    std::cout << "1.8 added\n";
  if (tree3.insert(-4))
    std::cout << "-4 added\n";
  if (tree3.insert(5.55))
    std::cout << "5.55 added\n";
  if (tree3.insert(88))
    std::cout << "88 added\n";

  std::cout << "tree4\n";
  BinarySearchTree<int> tree4;
  if (tree4.insert(3))
    std::cout << "3 added\n";
  if (tree4.insert(1))
    std::cout << "1 added\n";
  if (tree4.insert(2))
    std::cout << "2 added\n";
  if (tree4.insert(4))
    std::cout << "4 added\n";

  std::cout << "tree5\n";
  BinarySearchTree<int> tree5;
  if (tree5.insert(2))
    std::cout << "2 added\n";
  if (tree5.insert(1))
    std::cout << "1 added\n";
  if (tree5.insert(3))
    std::cout << "3 added\n";
  if (tree5.insert(4))
    std::cout << "4 added\n";

  BinarySearchTree<int> tree6;

  BinarySearchTree<int> tree7;

  std::cout << "tree8\n";
  BinarySearchTree<int> tree8;
  if (tree8.insert(0))
    std::cout << "0 added\n";
  if (tree8.insert(-1))
    std::cout << "-1 added\n";
  if (tree8.insert(-5))
    std::cout << "-5 added\n";
  if (tree8.insert(-7))
    std::cout << "-7 added\n";
  if (tree8.insert(-8))
    std::cout << "-8 added\n";

  std::cout << "tree9\n";
  BinarySearchTree<int> tree9;
  if (tree9.insert(8))
    std::cout << "8 added\n";
  if (tree9.insert(5))
    std::cout << "5 added\n";
  if (tree9.insert(-8))
    std::cout << "-8 added\n";

  BinarySearchTree<int> tree10;
  std::cout << "tree10\n";
  if (tree10.insert(0))
    std::cout << "0 added\n";
  if (tree10.insert(-1))
    std::cout << "-1 added\n";
  if (tree10.insert(-5))
    std::cout << "-5 added\n";
  if (tree10.insert(-7))
    std::cout << "-7 added\n";
  if (tree10.insert(-8))
    std::cout << "-8 added\n";

  std::cout << "\nTesting traversing in width\n";
  std::cout << "\ntree1 = ";
  tree1.traversingInWidth();
  std::cout << "\ntree3 = ";
  tree3.traversingInWidth();
  std::cout << "\ntree4 = ";
  tree4.traversingInWidth();
  std::cout << "\ntree5 = ";
  tree5.traversingInWidth();
  std::cout << "\ntree7 = ";
  tree7.traversingInWidth();
  std::cout << "\ntree8 = ";
  tree8.traversingInWidth();
  std::cout << "\ntree9 = ";
  tree9.traversingInWidth();

  std::cout << "\n\nTesting not similar trees\n";
  std::cout << "\ntree3 = ";
  tree3.print(std::cout);
  std::cout << "\ntree2 = ";
  tree2.print(std::cout);
  std::cout << (tree3.similarTree(tree2) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting similar trees\n";
  std::cout << "\ntree1 = ";
  tree1.print(std::cout);
  std::cout << "\ntree2 = ";
  tree2.print(std::cout);
  std::cout << (tree1.similarTree(tree2) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting similar trees(common cases)\n";
  std::cout << "\ntree4 = ";
  tree4.print(std::cout);
  std::cout << "\ntree5 = ";
  tree5.print(std::cout);
  std::cout << (tree4.similarTree(tree5) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting empty trees\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "\ntree7 =";
  tree7.print(std::cout);
  std::cout << (tree6.similarTree(tree7) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting empty tree and ordinary tree\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "\ntree4 =";
  tree4.print(std::cout);
  std::cout << (tree6.similarTree(tree4) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting empty tree and degenerate tree\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << (tree6.similarTree(tree8) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting degenerate tree and ordinary tree\n";
  std::cout << "\ntree5 =";
  tree5.print(std::cout);
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << (tree5.similarTree(tree8) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting similar degenerate trees\n";
  std::cout << "\ntree10 =";
  tree10.print(std::cout);
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << (tree10.similarTree(tree8) ? "\n\nTrees are similar\n\n" :
                "\n\nTrees are not similar\n\n");

  std::cout << "\nTesting not similar degenerate trees\n";
  std::cout << "\ntree9 =";
  tree9.print(std::cout);
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << (tree9.similarTree(tree8) ? "\n\nTrees are similar\n" :
                "\n\nTrees are not similar\n");

  return 0;
}
