#ifndef SORTS_SORTS_H
#define SORTS_SORTS_H

#include <vector>

template<class T>
void  sort1 (std::vector<T> &vector)
{
  size_t size = vector.size();
  T max = vector[0];
  for (size_t i = 0; i < size; i++)
  {
    if (vector[i] > max)
      max = vector[i];
  }
  std::vector<int> tempVec(max + 1);
  for (size_t i = 0; i < max; i++)
  {
    tempVec[i] = 0;
  }
  for (size_t i = 0; i < size; i++)
  {
    tempVec[vector[i]]++;
  }
  size_t j = 0;
  for (size_t i = 0; i < tempVec.size(); i++)
  {
    while (tempVec[i] != 0)
    {
      vector[j] = i;
      tempVec[i]--;
      j++;
    }
  }
};

void sort2(std::vector<int> &vector)
{
  int NRCounter = 10;
  size_t size = vector.size();
  std::vector<int> tempVec(size);
  int max = vector[0];
  for (size_t i = 0; i < size; i++)
  {
    if (vector[i] > max)
      max = vector[i];
  }
  int divider = 1;
  while (max / (NRCounter/10) > 0)
  {
    int numberRank[10];
    for (int i = 0; i < 10; i++)
    {
      numberRank[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
      int rank = (vector[i] % NRCounter) / divider;
      numberRank[rank]++;
    }
    for (int i = 1; i < 10; i++)
    {
      numberRank[i] += numberRank[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
      int newPlace = --numberRank[(vector[i] % NRCounter) / divider];
      tempVec[newPlace] = vector[i];
    }
    vector = tempVec;
    NRCounter *= 10;
    divider *= 10;
  }
}

template<class T>
void  sort3(std::vector<T> &vector)
{
  size_t size = vector.size();
  int bucket[10][size + 1];
  for(int i = 0; i < 10; ++i)
  {
    bucket[i][size] = 0;
  }
  int maxValue = 1000000;
  for(int value = 1; value <= maxValue; value *= 10)
  {
    for(int i = 0; i < size; i++)
    {
      int digit = (vector[i] / value) % 10;
      bucket[digit][bucket[digit][size]++] = vector[i];
    }
    int n = 0;
    for(int i = 0; i < 10; ++i)
    {
      for(int j = 0; j < bucket[i][size]; ++j)
      {
        vector[n++] = bucket[i][j];
      }
      bucket[i][size] = 0;
    }
  }
}

void sort4(std::vector<int> vector)
{
  size_t size = vector.size();
  int sign = 1;
  int s_sort[size];
  int max_n = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (vector[i] > max_n)
      max_n = vector[i];
  }
  while (max_n / sign > 0) {
    int razr[10] = { 0 };
    for (int i = 0; i < size; i++) {
      razr[(vector[i] / sign) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      razr[i] += razr[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
      s_sort[--razr[(vector[i] / sign) % 10]] = vector[i];
    }
    for (int i = 0; i < size; i++) {
      vector[i] = s_sort[i];
    }
    sign *= 10;
  }
}

template<class T>
bool correctSorting (std::vector<T> &vector)
{
  for (size_t i = 0; i != vector.size() - 1;)
  {
    if (vector[i] > vector[++i])
      return false;
  }
  return true;
}

#endif //SORTS_SORTS_H
