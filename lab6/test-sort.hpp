#ifndef TEST_SORT_HPP
#define TEST_SORT_HPP

#include <iostream>

#include "functionSort.hpp"

void testBubbleSort()
{
  const int size = 8;
  std::cout << "\nBest case {0,1,2,3,4,5,6,7}\n";
  int array1[size] = {0, 1, 2, 3, 4, 5, 6, 7};
  bubbleSort(array1, size);
  for (int i : array1)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nWorst case {32,20,16,10,5,4,4,2}\n";
  int array2[size] = {32, 20, 16, 10, 5, 4, 4, 2};
  bubbleSort(array2, size);
  for (int i : array2)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nMiddle case {6,3,8,2,18,20,53,86}\n";
  int array3[size] = {6, 3, 8, 2, 18, 20, 53, 86};
  bubbleSort(array3, size);
  for (int i : array3)
  {
    std::cout << i << " ";
  }
}
void testCountingSort()
{
  const int size = 8;
  std::cout << "\nBest case {20,20,20,20,20,20,20,20}\n";
  int array1[size] = {20, 20, 20, 20, 20, 20, 20, 20};
  countingSort(array1, size, 20);
  for (int i : array1)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nWorst case {0,1,2,3,4,5,6,7} \n";
  int array2[size] = {0, 1, 2, 3, 4, 5, 6, 7};
  countingSort(array2, size, 7);
  for (int i : array2)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nMiddle case {3,3,3,2,2,8,8,6}\n";
  int array3[size] = {3, 3, 3, 2, 2, 8, 8, 6};
  countingSort(array3, size, 8);
  for (int i : array3)
  {
    std::cout << i << " ";
  }
}
void testHeapSort()
{
  const int size = 8;
  std::cout << "\nBest case {1,1,1,1,1,1,1,1}\n";
  int array1[size] = {1, 1, 1, 1, 1, 1, 1, 1};
  heapSort(array1, size);
  for (int i : array1)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nWorst case {1,3,2,4,-2,7,6,12} \n";
  int array2[size] = {1, 3, 2, 4, -2, 7, 6, 12};
  heapSort(array2, size);
  for (int i : array2)
  {
    std::cout << i << " ";
  }
  std::cout << "\n\nMiddle case {12,10,8,13,2,5,1,15}\n";
  int array3[size] = {12, 10, 8, 13, 2, 5, 1, 15};
  heapSort(array3, size);
  for (int i : array3)
  {
    std::cout << i << " ";
  }
}
#endif
