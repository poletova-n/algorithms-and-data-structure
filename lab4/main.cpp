#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> a;
	a.insert(4);
	a.insert(5);
	a.insert(2);
	a.insert(8);
	a.insert(1);
	a.insert(7);
	a.insert(3);
	a.insert(9);
	std::cout << "insertion complete:" << '\n';
	a.print(std::cout);
	if (a.iterativeSearch(9))
	{
		std::cout<< "'9' was found" << '\n';
	}
	if (a.iterativeSearch(8))
	{
		std::cout << "'8' was found" << '\n';
	}
	if (a.deleteKey(8))
	{
		std::cout << "8 was deleted"<<'\n';
	}
	if (!(a.iterativeSearch(8)))
	{
		std::cout << "'8' was not found(it was deleted)" << '\n';
	}
	std::cout << "Now inserting '8','10','6':" << '\n';
	a.insert(8);
	a.insert(10);
	a.insert(6);
	a.print(std::cout);
	std::cout << "Number of Nodes of this tree:  " <<a.getCount() << '\n';
	std::cout << "Height of this tree:  " << a.getHeight() << '\n';
	std::cout << "iterativeInorderWalk of this tree:  ";
	a.iterativeInorderWalk();
	std::cout << "InorderWalk of this tree:  ";
	a.inorderWalk();
	std::cout << "making new tree:" << '\n';
	BinarySearchTree<int> r;
	r.insert(4);
	r.insert(5);
	r.insert(2);
	r.print(std::cout);
	std::cout << "making another new tree:" << '\n';
	BinarySearchTree<int> c;
	c.insert(4);
	c.insert(5);
	c.insert(2);
	c.insert(6);
	c.print(std::cout);
	std::cout << "Compairing these 2 trees:" << '\n';
	std::cout << ((r == c) ? "they are equal" : "they are not equal");
	std::cout << '\n';
	std::cout << "Now deleting '6' from second tree:" << '\n';
	if (c.deleteKey(6))
	{
		std::cout << "6 was deleted" << '\n';
	}
	c.print(std::cout);
	std::cout << "Compairing trees once again:" << '\n';
	std::cout << ((r == c) ? "they are equal" : "they are not equal");
	std::cout << '\n';
	return 0;
}