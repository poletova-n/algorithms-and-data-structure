#include<iostream>



int main()
{
	int a = 10;
	int* nhan = &a;
	int* van = nhan;
	(*van)++;
	std::cout << (*nhan) << '\n';
	int b = 20;
	van = &b;
	std::cout << *van << "   " << *nhan <<'\n';

	return 0;
}