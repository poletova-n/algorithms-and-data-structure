#include <iostream>

#include "SingleLinkedList.h"

int main()
{
  SinglyLinkedOrderedList list1;

  list1.insertItem(4);
  list1.insertItem(134);
  list1.insertItem(124);
  list1.insertItem(54);
  list1.insertItem(1);

  std::cout << "Ordered list1: " << list1 << std::endl;
  std::cout << "list1 has 99 in it: " << list1.searchItem(99) << std::endl;

  list1.deleteNode(134);
  std::cout << "Node with 134 removed, now list1: " << list1 << std::endl;

  SinglyLinkedOrderedList list2;

  list2.insertItem(9);
  list2.insertItem(134);
  list2.insertItem(1);
  list2.insertItem(-99);

  std::cout << "Ordered list2: " << list2 << std::endl;
  std::cout << "Difference in lists: " << (list1 - list2);
  std::cout << "Combining lists: " << (list1 + list2);
  std::cout << "Intersection of lists: " << (list1 * list2);
}
