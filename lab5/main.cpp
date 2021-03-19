#include "stack.h"
#include "queuearray.h"
#include "binarysearchtree.h"

int main()
{
  std::cout << "Making queue and filling it with '4', '5', '6', '7', '8'\n";
  try {
    QueueArray<int> queueOne(5);
    try
    {
      queueOne.enQueue(4);
      queueOne.enQueue(5);
      queueOne.enQueue(6);
      queueOne.enQueue(7);
      queueOne.enQueue(8);
      //queueOne.enQueue(9);  //uncomment to QueueOverflow error
    }
    catch (QueueOverflow error)
    {
      std::cout << error.what() << std::endl;
    }
    std::cout << "Removing numbers one by one and output them:" << std::endl;
    try
    {
      std::cout << queueOne.deQueue()<<" ";
      std::cout << queueOne.deQueue() << " ";
      std::cout << queueOne.deQueue() << " ";
      std::cout << queueOne.deQueue() << " ";
      std::cout << queueOne.deQueue()<<'\n'<<'\n';
      //std::cout << queueOne.deQueue() << '\n';  //uncomment to QueueUnderflow error
    }
    catch (QueueUnderflow error)
    {
      std::cout << error.what() << std::endl;
    }
  }
  catch (WrongQueueSize error)
  {
    std::cout << error.what() << std::endl;
  }

  BinarySearchTree<int> treeOne;
  treeOne.insert(5);
  treeOne.insert(3);
  treeOne.insert(1);
  treeOne.insert(8);
  treeOne.insert(4);
  treeOne.insert(9);
  treeOne.insert(7);
  treeOne.insert(6);
  treeOne.insert(2);
  std::cout << "TreeOne walk by stack:\n";
  treeOne.iterativeInorderWalk();
  std::cout << "TreeOne walk by queue (output by levels):\n";
  treeOne.floorWalk();
  std::cout << "Making one more tree to test similarity: \n";
  BinarySearchTree<int> treeTwo;
  treeTwo.insert(4);
  treeTwo.insert(8);
  treeTwo.insert(5);
  treeTwo.insert(3);
  treeTwo.insert(1);
  treeTwo.insert(9);
  treeTwo.insert(6);
  treeTwo.insert(7);
  treeTwo.insert(2);
  std::cout << "TreeTwo walk by queue (output by levels):\n";
  treeTwo.floorWalk();
  std::cout << (treeOne.isSimilar(treeTwo) ? "they are similar\n" : "they are not similar\n");
  std::cout << "Deleting '9' from treeTwo and inserting '10'\n";
  treeTwo.deleteKey(9);
  treeTwo.insert(10);
  std::cout << "Checking once again: \n";
  std::cout << (treeOne.isSimilar(treeTwo) ? "they are similar\n" : "they are not similar\n");
  std::cout << "Making two empty trees and checking how similar they are :D \n";
  BinarySearchTree<int> empty1;
  BinarySearchTree<int> empty2;
  std::cout << (empty1.isSimilar(empty2) ? "they are similar\n" : "they are not similar\n");
  return 0;
}