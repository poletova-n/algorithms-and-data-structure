#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include <iostream>

template <class T>
T bucketSort(const T& container)
{
  const int size = 10;
  T* arrayOfVectors = new T[size];
  T result;
  for (int i = 0; i < size; i++)
  {
    double left = static_cast<double>(i) / 10;
    double right = static_cast<double>(i + 1) / 10;
    for (size_t j = 0; j < container.size(); j++)
    {
      if ((container[j] >= left) && (container[j] < right))
      {
        arrayOfVectors[i].push_back(container[j]);
      }
    }
  }
  for (int i = 0; i < size; i++)
  {
    if (!arrayOfVectors[i].empty())
    {
      sort(arrayOfVectors[i]);
      for (size_t j = 0; j < arrayOfVectors[i].size(); j++)
      {
        result.push_back(arrayOfVectors[i].at(j));
      }
    }
  }
  delete[] arrayOfVectors;
  return result;
}

#endif