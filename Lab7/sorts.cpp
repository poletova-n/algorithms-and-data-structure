#include "sorts.hpp"

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>

const int SIZE = 12;

std::vector<int> utility::createVector(size_t size)
{
  std::vector<int> vec;
  srand(time(nullptr));
  for (size_t i = 0; i < size; ++i)
  {
    vec.push_back(rand() % 20);
  }
  return vec;
}

std::vector<double> utility::createDoubleVector(size_t size)
{
  std::vector<double> vec;
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<double> distr(0.0, 1.0);
  for (size_t i = 0; i < size; ++i)
  {
    vec.push_back(distr(eng));
  }
  return vec;
}

int utility::findMax(std::vector<int> vec)
{
  int max = vec[0];
  for (size_t i = 0; i < vec.size(); ++i)
  {
    max = std::max(vec[i], max);
  }
  return max;
}

int utility::findMin(std::vector<int> vec)
{
  int min = vec[0];
  for (size_t i = 0; i < vec.size(); ++i)
  {
    min = std::min(vec[i], min);
  }
  return min;
}

template <class Predicate>
std::vector<int>::iterator utility::partition(std::vector<int>::iterator first, 
                                     std::vector<int>::iterator last,
                                     Predicate predicate)
{
  first = std::find_if_not(first, last, predicate);
  if (first == last)
  {
    return first;
  }
  for (std::vector<int>::iterator i = std::next(first); i != last; ++i) {
    if (predicate(*i)) {
      std::iter_swap(i, first);
      ++first;
    }
  }
  return first;
}

void utility::msd(std::vector<int>::iterator first,
                  std::vector<int>::iterator last,
                  int msb)
{
  if (first != last && msb >= 0)
  {
    std::vector<int>::iterator mid = partition(first, last, Predicate(msb));
    --msb;
    msd(first, mid, msb);
    msd(mid, last, msb);
  }
}

std::vector<int> sorts::countingSort(std::vector<int> vec)
{
  int max = utility::findMax(vec);
  int min = utility::findMin(vec);
  int z = 0;
  int length = max - min + 1;
  std::vector<int> count(length);
  for (size_t i = 0; i < count.size(); ++i)
  {
    count[i] = 0; 
  }
  for (size_t i = 0; i < vec.size(); ++i)
  {
    count[vec[i] - min]++;
  }
  for (int i = min; i <= max; ++i)
  {
    while (count[i - min])
    {
      vec[z++] = i;
      count[i - min]--;
    }
  }
  return vec;
}

std::vector<int> sorts::radixSort(std::vector<int> vec)
{
  utility::msd(vec.begin(), vec.end());
  return vec;
}

std::vector<int> sorts::bucketSort(std::vector<int> vec, int size)
{
  int array[size];
  for (size_t i = 0; i < size; ++i)
  {
    array[i] = vec[i];
  }
  const int max = size;
  int bucket[10][max + 1];
  for (size_t i = 0; i < 10; ++i)
  {
      bucket[i][max] = 0;
  }
  for (int digit = 1; digit <= 1000000000; digit *= 10)
  {
    for (size_t i = 0; i < max; ++i)
    {
      int dig = (array[i] / digit) % 10;
      bucket[dig][bucket[dig][max]++] = array[i];
    }
    int idx = 0;
    for (int x = 0; x < 10; ++x)
    {
      for (int y = 0; y < bucket[x][max]; y++)
      {
        array[idx++] = bucket[x][y];
      }
      bucket[x][max] = 0;
    }
  }
  std::vector<int> vec1(array, array + size);
  return vec1;
}
