#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> test;
    test.insert(2);
    test.insert(7);
    test.insert(6);
    test.insert(-3);
    test.insert(8);
    test.insert(4);
    test.print(std::cout);
    std::cout << test.getHeight() << "\n"
         << test.getCount() << "\n";
    std::cout << "Let's try to find elements in our tree:\n"
        << "1: " << (test.iterativeSearch(1) ? "found" : "not found") << "\n"
        << "2: " << (test.iterativeSearch(2) ? "found" : "not found") << "\n"
        << "-5: " << (test.iterativeSearch(-5) ? "found" : "not found") << "\n"
        << "6: " << (test.iterativeSearch(6) ? "found" : "not found") << "\n";
    test.inorderWalk();
    test.deleteKey(4);
    test.deleteKey(-3);
    test.print(std::cout);
    BinarySearchTree<int> a;
    BinarySearchTree<int> b;
    a.insert(3);
    a.insert(38);
    a.insert(-100);
    b.insert(3);
    b.insert(38);
    b.insert(-100);
    std::cout << "First tree:";
    a.print(std::cout);
    std::cout << "Second tree:";
    b.print(std::cout);
    std::cout << ((a == b) ? "Trees are equal" : "Trees are not equal") << "\n";
    a.insert(49);
    std::cout << "First tree:";
    a.print(std::cout);
    std::cout << "Second tree:";
    b.print(std::cout);
    std::cout << ((a == b) ? "Trees are equal" : "Trees are not equal") << "\n";
    return 0;
}