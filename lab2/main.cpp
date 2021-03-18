#include <iostream>
#include "LinkedList.h"

int main()
{
    SinglyLinkedOrderedList list1;

    list1.insertItem(9);
    list1.insertItem(6);
    list1.insertItem(3);

    std::cout << "упорядоченный list1: " << list1 << std::endl;
    std::cout << "list1 имеет 6 в нем: " << list1.searchItem(6) << std::endl;
    list1.deleteNode(6);
    std::cout << "Узел с 6 удален, теперь list1: " << list1 << std::endl;

    SinglyLinkedOrderedList list2;

    list2.insertItem(9);
    list2.insertItem(-1);

    std::cout << "упорядоченный list2: " << list2 << std::endl;
    std::cout << "Разница в списках: " << (list1 - list2);
    std::cout << "Объединение списков: " << (list1 + list2);
    std::cout << "Пересечение списков: " << (list1 * list2);
}
