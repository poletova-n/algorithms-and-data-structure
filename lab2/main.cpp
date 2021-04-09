#include <iostream>
#include "LinkedList.h"

int main()
{
    SinglyLinkedOrderedList list1;

    list1.insertItem(9);
    list1.insertItem(6);
    list1.insertItem(3);

    std::cout << "Ordered list1: " << list1 << std::endl;
    std::cout << "list1 has 6 in it: " << list1.searchItem(6) << std::endl;
    list1.deleteNode(6);
    std::cout << "Node with 6 removed, now list1: " << list1 << std::endl;

    SinglyLinkedOrderedList list2;

    list2.insertItem(9);
    list2.insertItem(-1);

    std::cout << "Ordered list2: " << list2 << std::endl;
    std::cout << "Difference in lists: " << (list1 - list2);
    std::cout << "Combining lists: " << (list1 + list2);
    std::cout << "Intersection of lists: " << (list1 * list2);
}
