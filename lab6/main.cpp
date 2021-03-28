#include "tests.hpp"

int main()
{
	std::cout << "\tInsertion Sort:\n";
	testingInsertionSort();
	std::cout << "\n\tRadix Sort:\n";
	testingRadixSort();
	std::cout << "\n\tShell Sort:\n";
	testingShellSort();
	return 0;
}
