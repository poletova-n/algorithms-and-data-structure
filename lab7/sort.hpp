#ifndef LAB7_SORT_HPP
#define LAB7_SORT_HPP

#include <vector>
#include <cmath>
#include <algorithm>

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
  int c[max + 1];
  for (int i = 0; i < max + 1; i++)
  {
    c[i] = 0;
  }
  for (int i = 0; i < array.size(); i++)
  {
    c[array[i]]++;
  }
  int j = 0;
  for (int i = 0; i < max + 1; i++)
  {
    for (int counter = 0; counter < c[i]; counter++)
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
  int maxL = 0;
  std::vector<int> tempArray = array;

  while (temp > 0)
  {
    temp = temp / 10;
    maxL++;
  }

  int del = 0;
  for (int k = 1; k <= maxL; k++)
  {
    del = pow(10, k);
    for (int j = 0; j < tempArray.size(); j++)
    {
      for (int i = 0; i < tempArray.size() - 1; i++)
      {
        if (tempArray[i] % del > tempArray[i + 1] % del)
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

void print(std::vector<int>& array)
{
  for (int i = 0; i < array.size(); i++)
    std::cout << array[i] << " ";
}

void isSorted(std::vector<int>& originArray, std::vector<int>& array)
{
  std::sort(originArray.begin(), originArray.end());
  if (originArray == array)
  {
    std::cout << "Sorted is correct\n";
  }
  else
  {
    std::cout << "Sorted is not correct\n";
  }
}

#endif
