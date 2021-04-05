#include <iostream>
#include "queueArray.h"
#include "queueList.h"
#include "stackList.h"
#include "stackArray.h"
#include "binarySearchTree.h"


int main()
{
  std::cout << "\n-------------------------------------------------------------------\n" << "QUEUE ON ARRAY\n\n";

  int queueArray[14] = { 50, 67, 45, 3, 98, 56 , 46 ,74, 48, 59, 39, 4, 12,8 };
  QueueArray <int> myQueue;
  for (int i = 0; i < 14; i++)
  {
    myQueue.enQueue(queueArray[i]);
  }
  myQueue.printQueue();
  std::cout << " Number of elements before deleting: " << myQueue.nElements() << "\n";
  myQueue.deQueue();
  myQueue.deQueue();
  myQueue.deQueue();
  std::cout << " Original queue: ";
  myQueue.printQueue();
  QueueArray <int> copiedQueue(myQueue);
  std::cout << " Number of elements after  deleting: " << myQueue.nElements() << "\n";
  std::cout << " Copied   queue: ";
  copiedQueue.printQueue();

  std::cout << "\n-------------------------------------------------------------------\n"<<"QUEUE ON LIST\n\n";

  int queueArrayList[14] = { 17, 33, 43, 3, 98, 11 , 47 ,51, 48, 92, 39, 4, 6,8 };
  QueueList <int> myQueueList;
  for (int i = 0; i < 14; i++)
  {
    myQueueList.enQueue(queueArrayList[i]);
  }
  myQueueList.printQueue();
  std::cout << " Number of elements before deleting: " << myQueueList.nElements() << "\n";
  myQueueList.deQueue();
  myQueueList.deQueue();
  myQueueList.deQueue();
  std::cout << " Original queue: ";
  myQueueList.printQueue();
  QueueList <int> copiedQueueList(myQueueList);
  std::cout << " Number of elements after  deleting: " << myQueueList.nElements() << "\n";
  std::cout << " Copied   queue: ";
  copiedQueueList.printQueue();

  std::cout << "\n-------------------------------------------------------------------\n";

  int TreeKeys[10] = { 50, 67, 45, 3, 98, 56 , 46 ,74, 48, 59};
  BinarySearchTree <int> myFirstTree;
  for (int i = 0; i < 10; i++)
  {
    myFirstTree.AddLeaf(TreeKeys[i]);
  }
  int TreeKeys2[10] = {  98, 56 , 46 ,74, 48, 59, 50, 67, 45, 3};
  BinarySearchTree <int> mySecondTree;
  for (int i = 0; i < 10; i++)
  {
    mySecondTree.AddLeaf(TreeKeys2[i]);
  }
  myFirstTree.PrintInOrder();
  std::cout << std::endl;
  mySecondTree.PrintInOrder();
  std::cout << "Are trees identical? " << (myFirstTree.isIdentical(mySecondTree) ? " YES\n\n" : " NO\n\n");

  int TreeKeys3[5] = { 6, 4, 3, 7, 5 };
  BinarySearchTree <int> myThirdTree;
  for (int i = 0; i < 5; i++)
  {
    myThirdTree.AddLeaf(TreeKeys3[i]);
  }
  int TreeKeys4[5] = { 1, 4, 6, 5, 7 };
  BinarySearchTree <int> myFourthTree;
  for (int i = 0; i < 5; i++)
  {
    myFourthTree.AddLeaf(TreeKeys4[i]);
  }
  myThirdTree.PrintInOrder();
  std::cout << std::endl;
  myFourthTree.PrintInOrder();
  std::cout << "Are trees identical? " << (myThirdTree.isIdentical(myFourthTree) ? " YES\n\n" : " NO\n\n");

  std::cout << "\nLevel order traversal using queue: ";
  myFirstTree.levelOrderTraversal();
  std::cout << "\nPreorder  traversal  using  stack: ";
  myFirstTree.preOrderTraversal();
  std::cout << "\nInorder   traversal  using  stack: ";
  myFirstTree.inOrderTraversal();

  std::cout << "\n\nLevel order traversal using queue: ";
  myThirdTree.levelOrderTraversal();
  std::cout << "\nPreorder  traversal  using  stack: ";
  myThirdTree.preOrderTraversal();
  std::cout << "\nInorder   traversal  using  stack: ";
  myThirdTree.inOrderTraversal();

  return 0;
}