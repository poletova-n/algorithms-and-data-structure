// lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> tree;
    tree.insert(78);
    tree.insert(32);
    tree.insert(0);
    tree.insert(700);
    tree.insert(-99);
    tree.insert(1000);
    tree.insert(97865764);
    tree.insert(-1);
    tree.insert(3);
    std::cout << "Print tree: \n";
    tree.print(std::cout);
    std::cout << "Create second tree\n";
    BinarySearchTree<int> tree1;
    std::cout << "Compare it with the first tree: \n";
    std::cout << (tree1 == tree ? "Trees are equal\n" : "Trees are not equal\n");
    std::cout << "Fill the second tree and check if it equal with first \n";
    tree1.insert(78);
    tree1.insert(32);
    tree1.insert(0);
    tree1.insert(700);
    tree1.insert(-99);
    tree1.insert(1000);
    tree1.insert(97865764);
    tree1.insert(-1);
    tree1.insert(3);
    std::cout << (tree1 == tree ? "Trees are equal\n" : "Trees are not equal\n");
    std::cout << "Find the key with the value 7\n";
    std::cout<<(tree.iterativeSearch(7) == 1 ? "Key with value 7 exists\n" : "Key with value 7 doesn't exist\n");
    std::cout << "Find the key with the value 32\n";
    std::cout << (tree.iterativeSearch(32) == 1 ? "Key with value 32 exists\n" : "Key with value 32 doesn't exist\n");
    std::cout << "Delete the key with the value 0 and print tree\n";
    tree.deleteKey(0);
    tree.print(std::cout);
    std::cout << "Delete the key with the value 0 one more time\n";
    tree.deleteKey(0);
    std::cout << "Add a key that already exists\n";
    tree.insert(3);
    std::cout << "Tree height: " << tree.getHeight() << "\n";
    std::cout << "Number of keys in the tree: " << tree.getCount() << "\n";
    std::cout << "Infix tree traversal: " << "\n";
    tree.iterativeInorderWalk();
    std::cout << "\nPrefix tree traversal: " << "\n";
    tree.inorderWalk();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
