#include "binarySearchTree.h"

int main()
{																						//											  4
	BinarySearchTree<int> nhan;								//								 0								 10
	nhan.insertIterative(4);									//					        	 3				8			    12
	nhan.insertIterative(10);									//							     1			 5     9          14
	nhan.insertIterative(0);									//																			   13     16
	nhan.insertIterative(3);									//																					          17
	nhan.insertIterative(1);
	nhan.insertIterative(8);
	nhan.insertIterative(9);
	nhan.insertCursive(12);
	nhan.insertCursive(5);
	nhan.insertCursive(14);
	nhan.insertIterative(16);
	nhan.insertIterative(17);
	nhan.insertIterative(13);
	std::cout << "The number of elements in the tree before deleting: " << nhan.getCount() << '\n';
	int a{};
	std::cout << "Enter the element to be deleted: ";
	std::cin >> a;
	nhan.deleteElement(a);
	std::cout << "The number of tree elements after deletion: " << nhan.getCount() << '\n';
	if (nhan.searchIterative(a))
	{
		std::cout << "Find the element you are looking for.\n";
	}
	else
	{
		std::cout << "Can not find the element you want.\n";
	}
	std::cout << "Tree height after deletion: " << nhan.getHeight() << '\n';
	nhan.printNode(8, std::cout);
	try
	{
		std::cout << "The value of the parent element of element 0 is: " << nhan.find(0 , "p") << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}
	try
	{
		std::cout << "The value of the left child element of element 0 is: " << nhan.find(0, "left") << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}
	try
	{
		std::cout << "The value of the child element on the side of the element 0 is: " << nhan.find(0, "right") << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}

	return 0;
}
