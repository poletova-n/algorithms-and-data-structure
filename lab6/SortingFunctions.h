#ifndef SORTING_FUNCTION_H
#define SORTING_FUNCTION_H

#include <iostream>
#include <forward_list>
#include <stack>

int binarySearch(int data, int* array, int left, int right);
void insertionSort(int* array, int size);
void bucketSort(double* array, int size);
void quickSort(int* array, int size);
bool isSorted(int* array, int size);

template <typename T>
void print(T* array, int size)
{
  for (int i = 0;i < size;i++)
  {
    std::cout << array[i] << "  ";
  }
  std::cout << "\n";
}

#endif