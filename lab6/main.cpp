#include <iostream>
#include "test.h"

int main()
{
  std::cout << "Test of bubble sort:\n";
  testOfBubbleSort();

  std::cout << "\nTest of counting sort:\n";
  testOfCountingSort();

  std::cout << "\nTest of merge sort:\n";
  testOfMergeSort();
  return 0;
}
