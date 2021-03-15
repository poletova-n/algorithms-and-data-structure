#include "BinarySearchTree.hpp"
#include "QueueArray.hpp"
#include <iostream>

void testBinary()
{
    BinarySearchTree<int> tree;
    tree.insert(7);
    std::cout << "Add: " << 7 << std::endl;
    tree.insert(2);
    std::cout << "Add: " << 2 << std::endl;
    tree.insert(3);
    std::cout << "Add: " << 3 << std::endl;
    tree.insert(9);
    std::cout << "Add: " << 9 << std::endl;
    tree.insert(-4);
    std::cout << "Add: " << -4 << std::endl;
    tree.insert(8);
    std::cout << "Add: " << 8 << std::endl;
    tree.insert(3);
    std::cout << "Add: " << 3 << std::endl;
    tree.insert(10);
    std::cout << "Add: " << 10 << std::endl;
    tree.insert(77);
    std::cout << "Add: " << 77 << std::endl;
    std::cout << "Infix tree traversal: ";
    tree.inorderWalk();
    std::cout << "Prefix tree traversal: ";
    tree.iterativeInorderWalk();
    std::cout << "\nCount: " << tree.getCount() << std::endl;
    std::cout << "Height: " << tree.getHeight() << std::endl;
    tree.deleteKey(2);
    std::cout << "Delete key: " << 2 << std::endl;
    tree.deleteKey(3);
    std::cout << "Delete key: " << 3 << std::endl;
    tree.deleteKey(8);
    std::cout << "Delete key: " << 8 << std::endl;
    tree.deleteKey(-4);
    std::cout << "Delete key: " << -4 << std::endl;
}

void testBinary2()
{
    BinarySearchTree<int> tree;
    tree.insert(7);
    tree.insert(8);
    tree.insert(5);
    tree.insert(24);
    tree.insert(1);
    tree.insert(70);
    tree.insert(13);
    tree.insert(-2);
    std::cout << "First tree: ";
    tree.inorderWalk();
    std::cout << "Count: " << tree.getCount() << std::endl;
    std::cout << "Height: " << tree.getHeight() << std::endl;
    BinarySearchTree<int> tree2;
    tree2.insert(7);
    tree2.insert(4);
    tree2.insert(88);
    tree2.insert(2);
    tree2.insert(14);
    tree2.insert(6);
    std::cout << "Second tree: ";
    tree2.inorderWalk();
    std::cout << "Count: " << tree2.getCount() << std::endl;
    std::cout << "Height: " << tree2.getHeight() << std::endl;
    std::cout << ((tree == tree2) ? "Trees are equal\n" : "Trees are not equal\n");
}

void testQueue()
{
    try
    {
        QueueArray<int> q(10);
        try {
            q.enQueue(1);
            std::cout << "Add 1" << std::endl;
            q.enQueue(14);
            std::cout << "Add 14" << std::endl;
            q.enQueue(22);
            std::cout << "Add 22" << std::endl;
            q.enQueue(13);
            std::cout << "Add 13" << std::endl;
            q.enQueue(5);
            std::cout << "Add 5" << std::endl;
            q.enQueue(100);
            std::cout << "Add 100" << std::endl;
            q.enQueue(30);
            std::cout << "Add 30" << std::endl;
            q.printQueue(std::cout);
            std::cout << std::endl;
        }
        catch (QueueOverflow& e)
        {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << "Delete value 1\n";
            std::cout << "Delete value 14\n";
            q.deQueue();
            q.deQueue();
        }
        catch (QueueUnderflow& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "New Queue: \n";
        q.printQueue(std::cout);
    }
    catch (WrongQueueSize& e)
    {
        std::cout << e.what() << std::endl;
    }
}