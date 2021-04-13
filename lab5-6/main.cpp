#include <iostream>
#include <string>

#include "queue/queue.h"
#include "queue/QueueArray.h"
#include "queue/QueueList.h"
#include "stack/stackList.h"
#include "BinarySearchTree.h"

int main()
{
  try
  {
    std::cout << "Queue\n";
    Queue<int> *queue;
    QueueArray<int> queueArray(3);
    queue = &queueArray;
    queue->enQueue(1);
    queue->enQueue(2);
    queue->enQueue(3);
    queue->print(std::cout);
    std::cout << "\n" << queue->deQueue() << "\n";
    queue->enQueue(1);
    queue->print(std::cout);
    std::cout << "\n";
  }
  catch (std::exception &error)
  {
    std::cerr << error.what();
    return 1;
  }
  try
  {
    std::cout << "\n";
    Queue<int> *queue;
    QueueList<int> queueList;
    queue = &queueList;
    queue->enQueue(1);
    queue->enQueue(2);
    queue->enQueue(3);
    queue->print(std::cout);
    std::cout << "\n" << queue->deQueue() << "\n";
    queue->enQueue(1);
    queue->print(std::cout);
  }
  catch (std::exception &error)
  {
    std::cerr << error.what();
    return 1;
  }
  try
  {
    std::cout << "\n\nCreate first tree with nodes: 100, 70, 150, 50, 90, 200\n";
    BinarySearchTree<int> forest1;
    forest1.addIterative(100);
    forest1.addIterative(70);
    forest1.addRecursive(150);
    forest1.addRecursive(50);
    forest1.addIterative(90);
    forest1.addIterative(200);
    std::cout << "Walk the tree in width:\n";
    forest1.breadthWalk();
    std::cout << "\nWalk the tree in order:\n";
    forest1.inOrderWalk();
    std::cout << "\nCreate two similar trees, but not similar to the first with nodes 5, 10, 12, 13, 14\n";
    BinarySearchTree<int> forest2;
    BinarySearchTree<int> forest3;
    forest2.addIterative(5);
    forest2.addIterative(10);
    forest2.addIterative(12);
    forest2.addIterative(13);
    forest2.addIterative(14);
    forest3.addIterative(13);
    forest3.addIterative(10);
    forest3.addIterative(5);
    forest3.addIterative(14);
    forest3.addIterative(12);
    std::cout << "Compare the first and second trees: ";
    if (forest1.isSimilarTree(forest2))
    {
      std::cout << "similar\n";
    }
    else
    {
      std::cout << "dissimilar\n";
    }
    std::cout << "Compare the second and third trees: ";
    if (forest2.isSimilarTree(forest3))
    {
      std::cout << "similar\n";
    }
    else
    {
      std::cout << "dissimilar\n";
    }
  }
  catch (std::exception &error)
  {
    std::cerr << error.what();
    return 1;
  }
  return 0;
}
