#include <vector>

#include "sorts.hpp"

void bubbleSort(int *array, size_t count)
{
  int i, k = 1, t, c;
  while (true)
  {
    c = 0;
    for (i = 0; i < count - k; i++)
    {
      if (array[i] > array[i + 1])
      {
        std::swap(array[i], array[i + 1]);
        c++;
      }
    }
    if (c == 0)
    {
      break;
    }
    k++;
  }
}

void bucketSort(int *array, size_t count)
{
  int minValue = array[0];
  int maxValue = array[0];

  for (int i = 1; i < count; i++)
  {
    if (array[i] > maxValue)
    {
      maxValue = array[i];
    }
    if (array[i] < minValue)
    {
      minValue = array[i];
    }
  }
  int bucketLength = maxValue - minValue + 1;
  std::vector<int> *bucket = new std::vector<int>[bucketLength];
  for (int i = 0; i < bucketLength; i++)
  {
    bucket[i] = std::vector<int>();
  }

  for (int i = 0; i < count; i++)
  {
    bucket[array[i] - minValue].push_back(array[i]);
  }
  int k = 0;
  for (int i = 0; i < bucketLength; i++)
  {
    int bucketSize = bucket[i].size();
    if (bucketSize > 0)
    {
      for (int j = 0; j < bucketSize; j++)
      {
        array[k] = bucket[i][j];
        k++;
      }
    }
  }
}

void heapSort(int *array, size_t count)
{
  for (int i = count / 2 - 1; i >= 0; i--)
  {
    heapify(array, count, i);
  }
  for (int i=count-1; i>=0; i--)
  {
    std::swap(array[0], array[i]);
    heapify(array, i, 0);
  }
}

void heapify(int *array, size_t count, int i)
{
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;
  if (l < count && array[l] > array[largest])
  {
    largest = l;
  }
  if (r < count && array[r] > array[largest])
  {
    largest = r;
  }
  if (largest != i)
  {
    std::swap(array[i], array[largest]);
    heapify(array, count, largest);
  }
}
