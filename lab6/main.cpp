#include <iostream>
#include "sort-algorithms.h"

void print(int* arr, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << " ";
  }
}

void testInsertionSort()
{
  const int size = 10;
  int arr1[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Best case:\nBefore: ";
  print(arr1, size);
  insertionSort(arr1, size);
  std::cout << "\nAfter: ";
  print(arr1, size);

  int arr2[size] = {9, 4, 5, 1, 3, 8, 6, 2, 7, 10};
  std::cout << "\nAverage case:\nBefore: ";
  print(arr2, size);
  insertionSort(arr2, size);
  std::cout << "\nAfter: ";
  print(arr2, size);

  int arr3[size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "\nWorst case:\nBefore: ";
  print(arr3, size);
  insertionSort(arr3, size);
  std::cout << "\nAfter: ";
  print(arr3, size);
  std::cout << std::endl;
}

void testCountingSort()
{
  const int size = 10;
  int arr1[size] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << "Best case:\nBefore: ";
  print(arr1, size);
  countingSort(arr1, size);
  std::cout << "\nAfter: ";
  print(arr1, size);

  int arr2[size] = {1, 2, 3, 3, 2, 1, 2, 3, 1, 2};
  std::cout << "\nAverage case:\nBefore: ";
  print(arr2, size);
  countingSort(arr2, size);
  std::cout << "\nAfter: ";
  print(arr2, size);

  int arr3[size] = {9999, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "\nWorst case:\nBefore: ";
  print(arr3, size);
  countingSort(arr3, size);
  std::cout << "\nAfter: ";
  print(arr3, size);
  std::cout << std::endl;
}

void testMergeSort()
{
  const int size = 10;
  int arr1[size] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  std::cout << "Best case:\nBefore: ";
  print(arr1, size);
  mergeSort(arr1, size);
  std::cout << "\nAfter: ";
  print(arr1, size);

  int arr2[size] = {9, 4, 5, 1, 3, 8, 6, 2, 7, 10};
  std::cout << "\nAverage case:\nBefore: ";
  print(arr2, size);
  mergeSort(arr2, size);
  std::cout << "\nAfter: ";
  print(arr2, size);

  int arr3[size] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "\nWorst case:\nBefore: ";
  print(arr3, size);
  mergeSort(arr3, size);
  std::cout << "\nAfter: ";
  print(arr3, size);
  std::cout << std::endl;
}

int main()
{
  std::cout << "Insertion sort:\n";
  testInsertionSort();
  std::cout << "\nCounting sort:\n";
  testCountingSort();
  std::cout << "\nMerge sort:\n";
  testMergeSort();
  return 0;
}
