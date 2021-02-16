#include <iostream>
#include "list.h"
int main()
{
	//testing
	List list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list += 4;
	std::cout << "First list:" << std::endl;
	list.outAll();

	std::cout << ((list.searchItem(1)) ? "1 find" : "1 not find") << std::endl;
	std::cout << ((list.searchItem(8)) ? "8 find" : "8 not find") << std::endl;

	List  list1(&list);
	std::cout << "Second list, copied from first:" << std::endl;
	list1.outAll();
	std::cout << "Checking overloaded operator <<:" << std::endl;
	std::cout << list;
	std::cout << "Checking overloaded operator &" << std::endl;
	List list2(list & list1);
	list2.outAll();
	std::cout << "Checking list comparing:" << std::endl;
	bool temp = list == list1;
	std::cout << temp << std::endl;
	list1.insert(5);

	list.merge(list1);
	std::cout << "Merged lists:" << std::endl;
	list.outAll();
	return 0;
}

