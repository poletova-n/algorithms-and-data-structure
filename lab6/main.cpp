#include <iostream>
#include "test.hpp"
int main()
{
	std::cout << "Binary Insertion Sort: \n";
	testSelectionSort();
	std::cout << "Radix Sort: \n";
	testRadixSort();\
    std::cout << "\nMerge Sort: \n";
	testMergeSort();
	return 0;
}
