#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <iostream>

template<class T>
T countingSort(const T& container, size_t size, int maxElement)
{
  T tempArray(maxElement + 1, 0);
  T result;
  for (int i = 0; i <= maxElement; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (container[j] == i)
      {
        tempArray[i]++;
      }
    }
  }
  for (size_t i = 0; i < tempArray.size(); i++)
  {
    for (int j = 0; j < tempArray[i]; j++)
    {
      result.push_back(i);
    }
  }
  return result;
}

#endif