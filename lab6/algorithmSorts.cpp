#include <iostream>
#include <vector>
#include <algorithm>

#include "algorithmSorts.h"


//This function can sort negative numbers as well
void countingSort(int* array, size_t size)
{
  int max = array[0], min = array[0];
  for (size_t i = 1; i < size; i++)
  {
    if (max < array[i])
    {
      max = array[i];
    }
    //find the smallest value to avoid the case that the array's range is far from 0
    if (min > array[i])
    {
      min = array[i];
    }
  }
  int maxIndexTempArr = max - min;
  int* tempArr = new int[maxIndexTempArr + 1]{};

  for (size_t i = 0; i < size; i++)
  {
    tempArr[array[i] - min]++;
  }
  int indexArraySort = 0;
  for (int i = 0; i <= maxIndexTempArr; i++)
  {
    if (tempArr[i] != 0)
    {
      for (int j = 1; j <= tempArr[i]; j++)
      {
        array[indexArraySort++] = i + min;
      }
    }
  }
  delete[] tempArr;
}

//This function works with arrays of positive numbers
void radixSort(int* array, size_t size)
{
  int max = array[0];
  for (size_t i = 1; i < size; i++)
  {
    if (array[i] < 0)
    {
      std::cout << "Array containing negative numbers.\n";
      return;
    }
    if (max < array[i])
    {
      max = array[i];
    }
  }

  int* tempArr = new int[size];

  int radixNumber = 1;
  while (max / radixNumber > 0)
  {
    int radixArr[10]{};
    for (size_t i = 0; i < size; i++)
    {
      radixArr[(array[i] / radixNumber) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
      radixArr[i] += radixArr[i - 1];
    }
    for (int i = size - 1; i >= 0; --i)
    {
      tempArr[--radixArr[(array[i] / radixNumber) % 10]] = array[i];
    }
    for (size_t i = 0; i < size; i++)
    {
      array[i] = tempArr[i];
    }
    radixNumber *= 10;
  }
  delete[] tempArr;
}

void bucketSort(double* array, size_t size)
{
  double max = array[0], min = array[0];
  for (size_t i = 1; i < size; i++)
  {
    if (array[i] < 0)
    {
      std::cout << "Array containing negative numbers.\n";
      return;
    }
    if (max < array[i])
    {
      max = array[i];
    }
    if (min > array[i])
    {
      min = array[i];
    }
  }

  double spacingRange = (max - min) / 10;
  std::vector<double> tempArr[10];

  for (size_t i = 0; i < size; i++)
  {
    if (array[i] == max)
    {
      tempArr[9].push_back(max);
    }
    else
    {
      tempArr[static_cast<int>((array[i] - min) / spacingRange)].push_back(array[i]);
    } 
  }
  for (int i = 0; i < 10; i++)
  {
    if (tempArr[i].size() > 1)
    {
      std::sort(tempArr[i].begin(), tempArr[i].end());
    }
  }
  int indexSortArray = 0;
  for (int i = 0; i < 10; i++)
  {
    size_t sizeTempArr = tempArr[i].size();
    for (size_t j = 0; j < sizeTempArr; j++)
    {
      array[indexSortArray++] = tempArr[i][j];
    }
  }
}

void print(int* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
}

void print(double* array, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
}
