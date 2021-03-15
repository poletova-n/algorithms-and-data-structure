#include <iostream>

#include "BinarySearchTree.h"
#include "Queue.h"

void testEmptyTrees();

void fillTrees(BinarySearchTree<int>&, BinarySearchTree<int>&);

void testFilledTrees(BinarySearchTree<int>&, BinarySearchTree<int>&);

void testEmptyQueue();

void testQueue(Queue<int>*);

int main()
{
  testEmptyTrees();

  BinarySearchTree<int> tree1;
  BinarySearchTree<int> tree2;
  fillTrees(tree1, tree2);
  testFilledTrees(tree1, tree2);

  testEmptyQueue();

  Queue<int>* queue1(nullptr);
  testQueue(queue1);

  return 0;
}

void testEmptyTrees()
{
  BinarySearchTree<int> emptyTree1;
  BinarySearchTree<int> emptyTree2;
  std::cout << "Level order traversal for empty tree:\n";
  emptyTree1.levelWalk();
  std::cout << "Infix order traversal for empty tree:\n";
  emptyTree1.iterativeInorderWalk();
  std::cout << "Empty trees are " << (emptyTree1.isSimilar(emptyTree2) ? "" : "not ") << "similar\n\n";
}

void fillTrees(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2)
{
  tree1.insert(8);
  tree1.insert(3);
  tree1.insert(10);
  tree1.insert(1);
  tree1.insert(6);
  tree1.insert(4);
  tree1.insert(7);
  tree1.insert(14);

  tree2.insert(7);
  tree2.insert(1);
  tree2.insert(14);
  tree2.insert(3);
  tree2.insert(10);
  tree2.insert(4);
  tree2.insert(8);
  tree2.insert(6);
}

void testFilledTrees(BinarySearchTree<int>& tree1, BinarySearchTree<int>& tree2)
{
  std::cout << "Level order traversal for tree1:\n";
  tree1.levelWalk();
  std::cout << "Infix order traversal for tree1:\n";
  tree1.iterativeInorderWalk();

  std::cout << "Level order traversal for tree2:\n";
  tree2.levelWalk();
  std::cout << "Infix order traversal for tree2:\n";
  tree2.iterativeInorderWalk();

  std::cout << "tree1 and tree2 are " << (tree1.isSimilar(tree2) ? "" : "not ") << "similar\n\n";

  tree2.deleteKey(10);
  std::cout << "After deleting 10 in tree2 infix order traversal for tree2:\n";
  tree2.iterativeInorderWalk();
  std::cout << "tree1 and tree2 are " << (tree1.isSimilar(tree2) ? "" : "not ") << "similar\n\n";
}

void testEmptyQueue()
{
  QueueArray<int> queueArray(1);
  Queue<int>* queue = &queueArray;
  std::cout << "Empty queue is " << (queue->isEmpty() ? "empty\n" : "not empty\n");

  std::cout << "Attempt to get object from empty queue:\n";
  try {
    queue->deQueue();
  } catch (const QueueUnderflow& e) {
    std::cout << e.what() << '\n';
  }

  queue->enQueue(1);
  std::cout << "Attempt to put object into full queue:\n";
  try {
    queue->enQueue(3);
  } catch (const QueueOverflow& e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "Attempt to create queue with 0 size:\n";
  try {
    QueueArray<int> zeroSizeQueue(0);
  } catch (const WrongQueueSize& e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "Attempt to create queue with negative size:\n";
  try {
    QueueArray<int> negativeSizeQueue(-8);
  } catch (const WrongQueueSize& e) {
    std::cout << e.what() << "\n\n";
  }
}

void testQueue(Queue<int>* queue)
{
  const int queueSize = 10;
  QueueArray<int> queueArray(queueSize);
  queue = &queueArray;

  std::cout << "Queue's circularity allows infinite iterations of enqueuing and dequeuing"
            << "as long as they are performed one after another sequentially \n";
  for (int i = 0; i < 3 * queueSize; i++) {
    queue->enQueue(i);
    std::cout << queue->deQueue() << ", ";
  }
}