#include <iostream>
#include "BinarySearchTree.h"

void test();
void test2();

int main()
{
    std::cout << "First test: " << std::endl;
    test();
    std::cout << "\nSecond test: " << std::endl;
    test2();
    return 0;
}

void test()
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

void test2()
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
