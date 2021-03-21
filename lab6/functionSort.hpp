#ifndef FUNCTIONSORT_HPP
#define FUNCTIONSORT_HPP

#include "iostream"

template<typename T>
void bubbleSort(T *array, size_t size)
{
  int i = 0;
  bool isSwapped = true;
  while (isSwapped)
  {
    isSwapped = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
        isSwapped = true;
      }
    }
    i++;
  }
}
template<typename T>
void countingSort(T *array, size_t size, int mx)
{
  int *counter = new int[mx + 1];
  for (int i = 0; i <= mx; i++)
  {
    counter[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    counter[array[i]]++;
  }
  int i = 0;
  for (int j = 0; j <= mx; j++)
  {
    for (int k = counter[j]; counter[j] > 0; k--)
    {
      while (counter[j] != 0)
      {
        array[i] = j;
        counter[j]--;
        i++;
      }
    }
  }
}
template<typename T>
void offset(T *array, size_t size, int i)
{
  int parent = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < size && array[left] > array[parent])
  {
    parent = left;
  }
  if (right < size && array[right] > array[parent])
  {
    parent = right;
  }
  if (parent != i)
  {
    std::swap(array[i], array[parent]);
    offset(array, size, parent);
  }
}
void heapSort(int *array, size_t size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    offset(array, size, i);
  }
  for (int i = size - 1; i >= 0; i--)
  {
    std::swap(array[0], array[i]);
    offset(array, i, 0);
  }
}
#endif
