#include "BinarySearchTree.hpp"
#include "QueueArray.hpp"
#include <iostream>

void testBinary()
{
    BinarySearchTree<int> tree;
    tree.insert(1);
    std::cout << "Add: " << 1 << std::endl;
    tree.insert(2);
    std::cout << "Add: " << 2 << std::endl;
    tree.insert(3);
    std::cout << "Add: " << 3 << std::endl;
    tree.insert(4);
    std::cout << "Add: " << 4 << std::endl;
    tree.insert(5);
    std::cout << "Add: " << 5 << std::endl;
    tree.insert(6);
    std::cout << "Add: " << 6 << std::endl;
    tree.insert(7);
    std::cout << "Add: " << 7 << std::endl;
    tree.insert(8);
    std::cout << "Add: " << 8 << std::endl;
    tree.insert(9);
    std::cout << "Add: " << 9 << std::endl;
    std::cout << "Infix tree traversal: ";
    tree.inorderWalk();
    std::cout << "Prefix tree traversal: ";
    tree.iterativeInorderWalk();
    std::cout << "Count: " << tree.getCount() << std::endl;
    std::cout << "Height: " << tree.getHeight() << std::endl;
    tree.deleteKey(2);
    std::cout << "\nDelete key: " << 2 << std::endl;
    tree.deleteKey(3);
    std::cout << "Delete key: " << 3 << std::endl;
    tree.deleteKey(8);
    std::cout << "Delete key: " << 8 << std::endl;
    tree.deleteKey(7);
    std::cout << "Delete key: " << 7 << std::endl;
    std::cout << "Infix tree traversal: ";
    tree.inorderWalk();
    std::cout << "Prefix tree traversal: ";
    tree.iterativeInorderWalk();
    std::cout << "\nCount: " << tree.getCount() << std::endl;
    std::cout << "Height: " << tree.getHeight() << std::endl;

}

void testBinary2()
{
    BinarySearchTree<int> tree;
    std::cout << "Add to tree: 7, 8, 5, 24, 1, 70, 13, -2\n";
    tree.insert(7);
    tree.insert(8);
    tree.insert(5);
    tree.insert(24);
    tree.insert(1);
    tree.insert(70);
    tree.insert(13);
    tree.insert(-2);
    std::cout << "Infix first tree traversal: ";
    tree.inorderWalk();
    std::cout << "Count: " << tree.getCount() << std::endl;
    std::cout << "Height: " << tree.getHeight() << std::endl;
    BinarySearchTree<int> tree2;
    std::cout << "Add to tree2: 7, 4, 88, 2, 14, 6, 14, 6\n";
    tree2.insert(7);
    tree2.insert(4);
    tree2.insert(88);
    tree2.insert(2);
    tree2.insert(14);
    tree2.insert(6);
    std::cout << "Infix second tree traversal: ";
    tree2.inorderWalk();
    std::cout << "Count: " << tree2.getCount() << std::endl;
    std::cout << "Height: " << tree2.getHeight() << std::endl;
    std::cout << "Compare first tree with second tree: " << std::endl;
    std::cout << ((tree.isSimilar(tree2)) ? "Trees are similar\n" : "Trees are not similar\n") << std::endl;

    BinarySearchTree<int> tree3;
    std::cout << "Add to tree3: 7, 5, 8, 1, 24, 70, 13, -2\n";
    tree3.insert(7);
    tree3.insert(5);
    tree3.insert(8);
    tree3.insert(1);
    tree3.insert(24);
    tree3.insert(70);
    tree3.insert(13);
    tree3.insert(-2);
    std::cout << "Infix third tree traversal: ";
    tree.inorderWalk();
    std::cout << "Count: " << tree3.getCount() << std::endl;
    std::cout << "Height: " << tree3.getHeight() << std::endl;
    std::cout << "Compare first tree with third tree: " << std::endl;
    std::cout << ((tree.isSimilar(tree3)) ? "Trees are similar\n" : "Trees are not similar\n") << std::endl;
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
            std::cout << "Delete value 14\n\n";
            q.deQueue();
            q.deQueue();
        }
        catch (QueueUnderflow& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "New Queue\n";
        q.printQueue(std::cout);
    }
    catch (WrongQueueSize& e)
    {
        std::cout << e.what() << std::endl;
    }
}