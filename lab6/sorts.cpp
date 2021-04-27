#include <algorithm>

int binarySearch(int* array, int left, int right, int value)
{
  int middle = 0;
  while (true)
  {
    middle = (left + right) / 2;

    if (value < array[middle])
    {
      right = middle - 1;
    }
    else if (value > array[middle])
    {
      left = middle + 1;
    }
    else
    {
      return middle;
    }
    if (right <= left)
    {
      return (value > array[left] ? left + 1 : left);
    }
  }
}

void doInsertSort(int* array, int size)
{
  int loc, j, selected;

  for (int i = 0; i < size; i++)
  {
    j = i;
    selected = array[i];
    loc = binarySearch(array, 0, j - 1, selected);
    while (j > loc)
    {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = selected;
  }
}

void doCountSort(int* array, int size)
{
  int max = INT_MIN, min = INT_MAX;
  for (int i = 0; i < size; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  int* c = new int[max + 1 - min];
  for (int i = 0; i < max + 1 - min; i++)
  {
    c[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    c[array[i] - min] = c[array[i] - min] + 1;
  }
  int i = 0;
  for (int j = min; j < max + 1; j++)
  {
    while (c[j - min] != 0)
    {
      array[i] = j;
      c[j - min]--;
      i++;
    }
  }
  delete[] c;
}

void siftHeap(int* array, int size, int root)
{
  int largest = root;
  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && array[left] > array[largest])
  {
    largest = left;
  }
  if (right < size && array[right] > array[largest])
  {
    largest = right;
  }
  if (largest != root)
  {
    std::swap(array[root], array[largest]);
    siftHeap(array, size, largest);
  }
}

void doPyramidSort(int* array, int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    siftHeap(array, size, i);
  }
  for (int i = size - 1; i >= 0; i--)
  {
    std::swap(array[0], array[i]);
    siftHeap(array, i, 0);
  }
}
