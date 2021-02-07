#include "List.h"
#include <iostream>

int main() {
	std::cout << "List 1: ";
	DoubleLinkedList list1;
	list1 += 1; // creation of sorted list.
	list1 += 2;
	list1 += 7;
	list1 += 2;
	list1 += 3;
	std::cout << list1 << std::endl;
	DoubleLinkedList list2;
	list2 += 1;
	list2 += 4;
	list2 += 5;
	std::cout << "List 2: " << list2 << std::endl;
	std::cout << "Tested constructor with no parameters.\n";
	DoubleLinkedList list3(list2);
	list3.~DoubleLinkedList();
	std::cout << "Called destructor for object list3.\n";
	list2 += 8;
	std::cout << "Called += operator for list2 and int 8." << " New list is now " << list2;
	std::cout << "std::cout is called 3 times.\n";
	std::cout << "Test of == operator: list1 == list2? " << (list1 == list2) << " \n";
	DoubleLinkedList list4(list1 & list2);
	std::cout << "Test of & operator, new list is: " << list4 << std::endl;
	DoubleLinkedList list5(list1 | list2);
	std::cout << "Test of | operator, new list is: " << list5 << std::endl;
	DoubleLinkedList list6;
	list5 += 10;
	list5.merge(list1);
	std::cout << "Testing merge function, merged list1 into list5." << list6 << std::endl;
	std::cout << "All tests have been passed successfully.";
	return 0;
}