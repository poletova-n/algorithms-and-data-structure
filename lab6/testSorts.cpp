#include <cstdlib>
#include <ostream>
#include <iostream>
#include "testSorts.hpp"
#include "sorts.hpp"

bool isSorted(const int *array, size_t size)
{
  size_t count = 1;
  for (int i = 0; i < size - 1; i++)
  {
    if (array[i] <= array[i + 1])
      count++;
  }
  if(count == size)
    return true;
  return false;

}

void printArray(int* array, size_t size, std::ostream &out)
{
  for (size_t i = 0; i < size; i++)
  {
    out << array[i] << ' ';
  }
  out << "\n";
}

void testShakerSort()
{
  std::cout<<"SHAKER SORT\n\n";
  const size_t size = 10;
  std::cout<<"Best case:\n";
  int bestCase [size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printArray(bestCase, size, std::cout);
  shakerSort(bestCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(bestCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(bestCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Middle case:\n";
  int middleCase [size] = {1, 4, 3, 2, 7, 6, 5, 8, 9, 10};
  printArray(middleCase, size, std::cout);
  shakerSort(middleCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(middleCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(middleCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Worst case:\n";
  int worstCase [size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  printArray(worstCase, size, std::cout);
  shakerSort(worstCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(worstCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(worstCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";
}

void testBucketSort()
{
  std::cout<<"BUCKET SORT\n\n";
  const size_t size = 10;
  std::cout<<"Best case:\n";
  int bestCase [size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printArray(bestCase, size, std::cout);
  bucketSort(bestCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(bestCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(bestCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Middle case:\n";
  int middleCase [size] = {1, 4, 3, 2, 7, 6, 5, 8, 9, 10};
  printArray(middleCase, size, std::cout);
  bucketSort(middleCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(middleCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(middleCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Worst case:\n";
  int worstCase [size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  printArray(worstCase, size, std::cout);
  bucketSort(worstCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(worstCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(worstCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";
}

void testQuickSort()
{
  std::cout<<"QUICK SORT\n\n";
  const size_t size = 9;
  std::cout<<"Best case:\n";
  int bestCase [size] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  printArray(bestCase, size, std::cout);
  quickSort(bestCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(bestCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(bestCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Middle case:\n";
  int middleCase [size] = {1, 7, 8, 2, 5, 6, 1, 3, 9};
  printArray(middleCase, size, std::cout);
  quickSort(middleCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(middleCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(middleCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";

  std::cout<<"Worst case:\n";
  int worstCase [size] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
  printArray(worstCase, size, std::cout);
  quickSort(worstCase, size);
  std::cout<<"Array after sorting:\n";
  printArray(worstCase, size, std::cout);
  std::cout<<"Array is sorted?: ";
  if(isSorted(worstCase, size))
    std::cout<<"yes\n\n";
  else
    std::cout<<"no\n\n";
}
