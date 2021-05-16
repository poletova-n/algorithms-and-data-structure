#include "sort-algorithms.h"

int binarySearch(int* arr, int element, int leftBound, int rightBound)
{
  if (rightBound == leftBound)
  {
    return rightBound;
  }
  int middle = (rightBound + leftBound) / 2;
  if (arr[middle] > element)
  {
    return binarySearch(arr, element, leftBound, middle);
  }
  return binarySearch(arr, element, middle + 1, rightBound);
}

void insertionSort(int* arr, int size)
{
  for (int i = 1; i < size; i++)
  {
    int element = arr[i];
    int place = binarySearch(arr, element, 0, i);
    for (int j = i; j > place; j--)
    {
      arr[j] = arr[j - 1];
    }
    arr[place] = element;
  }
}

void countingSort(int* arr, int size)
{
  int max = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (arr[i] > max)
    {
      max = arr[i];
    }
  }
  int* counters = new int[max + 1];
  for (int i = 0; i < max + 1; i++)
  {
    counters[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    counters[arr[i]]++;
  }
  for (int i = 1; i < max + 1; i++)
  {
    counters[i] += counters[i - 1];
  }
  int* sortedArr = new int[size];
  for (int i = size - 1; i >= 0; i--)
  {
    sortedArr[counters[arr[i]]-- - 1] = arr[i];
  }
  for (int i = 0; i < size; i++)
  {
    arr[i] = sortedArr[i];
  }
  delete[] sortedArr;
  delete[] counters;
}

void merge(int* arr, int left1, int right1, int left2, int right2)
{
  int* temp = new int[right2 - left1 + 1];
  int i = 0;
  int startIndex = left1;
  while (left1 <= right1 && left2 <= right2)
  {
    if (arr[left1] < arr[left2])
    {
      temp[i++] = arr[left1++];
    }
    else
    {
      temp[i++] = arr[left2++];
    }
  }
  while (left1 <= right1)
  {
    temp[i++] = arr[left1++];
  }
  while (left2 <= right2)
  {
    temp[i++] = arr[left2++];
  }
  for (int j = 0; j < i; j++)
  {
    arr[startIndex + j] = temp[j];
  }
  delete[] temp;
}

void mergeSort(int* arr, int size)
{
  for (int i = 1; i < size; i *= 2)
  {
    for (int j = 0; j < size; j += 2 * i)
    {
      int left1 = j;
      int right1 = j + i - 1;
      int left2 = i + j;
      int right2 = j + 2 * i - 1;
      if (left2 >= size)
      {
        break;
      }
      if (right2 >= size)
      {
        right2 = size - 1;
      }
      merge(arr, left1, right1, left2, right2);
    }
  }
}
