#ifndef RADIX_SORT_HPP
#define RADIX_SORT_HPP

#include <iostream>

template <class T>
T radixSort(const T& container, int length, int rang)
{
  T result(container);
  int tempCount = 1;
  for (int count = 0; count < length; count++)
  {
    T temp;
    for (int i = 0; i < rang; i++)
    {
      for (size_t j = 0; j < result.size(); j++)
      {
        if (i == (result[j] / tempCount % 10))
        {
          temp.push_back(result[j]);
        }
      }
    }
    tempCount *= 10;
    result = temp;
  }
  return result;
}

#endif