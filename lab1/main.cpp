#include <iostream>
#include "DoubleLinkedList.h"
int main()
{
  DoubleLinkedList list;
  list.insertHead(9);
  list.insertHead(6);
  list.insertHead(1);
  list.outAll();
  std::cout << ((list.searchItem (6)) ? "6 found" : "6 was not found")<< std::endl;
  std::cout << ((list.searchItem(8)) ? "8 found" : "8 was not found")<< std::endl;
  DoubleLinkedList list1;
  list1.insertHead(7);
  list1.insertTail(21);
  list1.insertHead(5);
  list1.deleteHead();
  list1.outAll();
  list1.insertHead(4);
  list1.insertTail(4);
  list1.outAll();
  list1.replaceItem(4, 72);
  std::cout << "replace everything from 4 to 72: " << list1;
  list1.deleteItem(72);
  std::cout << "delete all 72 72: " << list1;
  list1.insertTail(2);
  list1.insertTail(17);
  list1.insertTail(29);
  list1.deleteTail();
  list1.outAll();
  list1.unite(list);
  std::cout << "after addAll(list): " << list1 << "empty list: " << list;
  list1.deleteItem(21);
  std::cout << "delete one 21: " << list1;
  list1.replaceItem(17, 81);
  std::cout << "replace one from 17 to 81: " << list1;
  DoubleLinkedList list2(list1);
  std::cout << ((list1 == list2) ? "List1 and List2 are equal" : "List1 and List2 are not equal") << std::endl;
  std::cout << ((list2.searchItem(9)) ? "List2 contains 9" : "List1 does not contain 9") << std::endl;
  list2.deleteTail();
  std::cout << ((list2.searchItem(9)) ? "List2 contains 9" : "List1 does not contain 9") << std::endl;
  std::cout << ((list1 == list2) ? "List1 and List2 are equal" : "List1 and List2 are not equal") << std::endl;
}
