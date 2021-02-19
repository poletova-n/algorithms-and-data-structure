#include <iostream>
#include "SLL.h"
#include "DLL.h" 

std::ostream& operator<<(std::ostream& os, SinglyLinkedList& sllst)
{
	sllst.printList();
	return os;
}

int main()
{
	SinglyLinkedList sll;
	DoublyLinkedList dll;
	std::cout << "SLL: \n";
	sll.push_back(23);
	sll.push_back(6);
	sll.push_front(3);
	sll += 44;
	sll.printList();
	SinglyLinkedList secondsll;
	secondsll.push_back(6);
	secondsll.push_back(28);
	secondsll.push_front(3);
	secondsll.push_back(96);
	secondsll.push_front(44);
	secondsll += 55;
	std::cout << "Testing the overloaded insertion operator << (2nd SLL) :\n";
	std::cout << secondsll;
	std::cout << "Testing the overloaded equality operator == :\n";
	std::cout<< (secondsll == sll ? "Lists are identical":"Lists are different");
	std::cout << "\nTesting the overloaded operator & :\n";
	SinglyLinkedList sum;
	sum = sll&secondsll;
	std::cout << sum;
	std::cout << "Testing the overloaded operator | :\n";
	SinglyLinkedList sum2;
	sum2 = sll | secondsll;
	std::cout << sum2;
	std::cout << "Testing Merge() :\n";
	sll.merge(secondsll);
	std::cout << sll;




	std::cout << "\nDLL: \n";
	dll.push_back(36);
	dll.push_front(24);
	dll.push_front(12);
	dll+=100;
	std::cout << dll;
	DoublyLinkedList seconddll;
	seconddll.push_back(56);
	seconddll.push_front(36);
	seconddll += 89;
	std::cout << "Testing the overloaded insertion operator << (2nd DLL) :\n";
	std::cout << seconddll;
	std::cout << "Testing the overloaded equality operator == :\n";
	std::cout << (seconddll == dll ? "Lists are identical" : "Lists are different");
	std::cout << "\nTesting the overloaded operator & :\n";
	DoublyLinkedList dllSum;
	dllSum=dll & seconddll;
	std::cout << dllSum;
	std::cout << "Testing the overloaded operator | :\n";
	DoublyLinkedList dllSum2;
	dllSum2 = dll | seconddll;
	std::cout << dllSum2;
	std::cout << "Testing Merge() :\n";
	dll.merge(seconddll);
	std::cout << dll << "\n" << seconddll;
	return 0;
}


