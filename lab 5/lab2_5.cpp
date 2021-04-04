#include <iostream>
#include "BinarySearchTree.h"
#include "Queue.h"

void testQueue(Queue<int>*);

int main()
{
    std::cout << "Test binary tree :\n";
    BinarySearchTree<int> testTree;
    testTree.insert(2);
    testTree.insert(4);
    testTree.insert(9);
    testTree.insert(-3);
    testTree.insert(8);
    testTree.insert(9);
    testTree.insert(-20);
    testTree.insert(67);
    std::cout << "State of the tree: ";
    testTree.print(std::cout);
    std::cout << "Iterative traversal of a binary tree:\n";
    testTree.iterativeInorderWalk();
    std::cout << "Test similar trees:\n";
    BinarySearchTree<int> testTree2;
    std::cout << "Second tree\n";
    testTree2.insert(67);
    testTree2.insert(4);
    testTree2.insert(-3);
    testTree2.insert(9);
    testTree2.insert(8);
    testTree2.insert(9);
    testTree2.insert(-20);
    testTree2.insert(2);
    std::cout << "The current state of the second tree: ";
    testTree.print(std::cout);
    if (testTree.isSimilar(testTree2))
    {
        std::cout << "Trees are similar\n";
    }
    else
    {
        std::cout << "Trees are not similar\n";
    }
    std::cout << "Make the trees look different:\n";
    testTree2.deleteKey(4);
    testTree2.insert(35);
    if (testTree.isSimilar(testTree2))
    {
        std::cout << "Trees are similar\n";
    }
    else
    {
        std::cout << "Trees are not similar\n";
    }
    Queue<int>* queue(nullptr);
    testQueue(queue);
    return 0;
}

void testQueue(Queue<int>* queue)
{
    const int queueSize = 5;
    QueueArray<int> queueArray(queueSize);
    queue = &queueArray;
    for (int i = 0; i < 3 * queueSize; i++) {
        queue->enQueue(i);
        std::cout << queue->deQueue() << ", ";
    }
}