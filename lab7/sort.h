#ifndef LAB7_SORT_HPP
#define LAB7_SORT_HPP

#include <cmath>
#include <vector>
#include <algorithm>

void print(std::vector<int>& array)
{
  for (int i = 0; i < array.size(); i++)
    std::cout << array[i] << " ";
}

void countingSort(std::vector<int>& array)
{
  int max = 0;

  for (int i = 0; i < array.size(); ++i)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  int tempArray[max + 1];

  for (int i = 0; i < max + 1; i++)
  {
    tempArray[i] = 0;
  }
  for (int i = 0; i < array.size(); i++)
  {
    tempArray[array[i]]++;
  }
  int j = 0;
  for (int i = 0; i < max + 1; i++)
  {
    for (int counter = 0; counter < tempArray[i]; counter++)
    {
      array[j] = i;
      j++;
    }
  }
}

void radixSort(std::vector<int>& array)
{
  int max = 0;
  for (int i = 0; i < array.size(); ++i)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  int temp = max;
  int maxNumber = 0;
  std::vector<int> tempArray = array;

  while (temp > 0)
  {
    temp = temp / 10;
    maxNumber++;
  }

  int exp = 0;
  for (int k = 1; k <= maxNumber; k++)
  {
    exp = pow(10, k);
    for (int j = 0; j < tempArray.size(); j++)
    {
      for (int i = 0; i < tempArray.size() - 1; i++)
      {
        if (tempArray[i] % exp > tempArray[i + 1] % exp)
        {
          std::swap(tempArray[i], tempArray[i + 1]);
        }
      }
    }
  }
  array = tempArray;
}

void bucketSort(std::vector<int>& array)
{
  const int SIZE = 1000000000;

  const int max = array.size();

  int bucket[10][max + 1];

  for (int i = 0; i < 10; i++)
  {
    bucket[i][max] = 0;
  }
  for (int value = 1; value <= SIZE; value *= 10)
  {
    for (int i = 0; i < max; i++)
    {
      int digit = (array[i] / value) % 10;
      bucket[digit][bucket[digit][max]++] = array[i];
    }
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < bucket[i][max]; j++)
      {
        array[index++] = bucket[i][j];
      }
      bucket[i][max] = 0;
    }
  }

}

void insertionSort(std::vector<int>& array)
{
  for (int i =  0; i < array.size(); ++i)
  {
    int key = array[i];
    int lo = 0;
    int hi = i;
    while (lo < hi)
    {
      int mid = (hi + lo) / 2;
      //int mid = lo + (hi - lo) / 2;
      if (key < array[mid])
      {
        hi = mid;
      }
      else
      {
        lo = mid + 1;
      }
    }
      for (int j = i; j > lo; --j)
      {
        array[j] = array[j-1];
      }
      array[lo] = key;
  }
}

void shellSort(std::vector<int>& array)
{
  int inc = array.size() / 2;
  while (inc > 0)
  {
    for (int i = 0; i < array.size() - inc; i++)
    {
      int j = i;
      while(j >= 0 && array[j] > array[j + inc])
      {
        int temp = array[j];
        array[j] =array[j + 1];
        array[j + 1] = temp;
        j--;
      }
    }
    inc = inc / 2;
  }
}

#endif
