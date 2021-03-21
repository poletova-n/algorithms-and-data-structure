#include <iostream>
#include "test-sort.hpp"

int main()
{
  std::cout << "Test bubble sort\n";
  testBubbleSort();
  std::cout << "\n\nTest counting sort\n";
  testCountingSort();
  std::cout << "\n\nTest heap sort\n";
  testHeapSort();
  return 0;
}
