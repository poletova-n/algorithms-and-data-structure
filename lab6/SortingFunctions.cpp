#include "SortingFunctions.h"

int binarySearch(int data, int* array, int left, int right)
{
  if (right <= left)
  {
    return (data > array[left] ? left + 1 : left);
  }
  else
  {
    int middle = (left + right) / 2;
    if (array[middle] < data)
    {
      return binarySearch(data, array, middle + 1, right);
    }
    else if (array[middle] > data)
    {
      return binarySearch(data, array, left, middle - 1);
    }
    else if (array[middle] == data)
    {
      return middle + 1;
    }
  }
}

void insertionSort(int* array, int size)
{
  if (size <= 0)
  {
    throw ("incorrect size");
    return;
  }
  int forSort = 0;
  for (int i = 0;i < size;i++)
  {
    int j = i;
    forSort = array[i];
    while (j > binarySearch(forSort, array, 0, j - 1))
    {
      array[j] = array[j - 1];
      j--;
    }
    array[j] = forSort;
  }
}

void bucketSort(double* array, int size)
{
  std::forward_list<double> tempArray[11];
  for (int i = 0;i < size;i++)
  {
    for (int j = 0;j < 11;j++)
    {
      if ((j * 0.1) <= (array[i]) < ((j * 0.1) + 0.1))
      {
        tempArray[j].push_front(array[i]);
        tempArray[j].sort();
        break;
      }
    }
  }
  for (int k = 1;k < 11;k++)
  {
    tempArray[0].merge(tempArray[k]);
  }
  for (int k = 0;k < size;k++)
  {
    array[k] = tempArray[0].front();
    //std::cout << tempArray[0].front()<<"  ";
    tempArray[0].pop_front();
  }
}

void quickSort(int* array, int size)
{
  std::stack <int> stack;
  stack.push(0);
  stack.push(size - 1);
  int  middlePoint, l, r, i, j;
  while (!stack.empty())
  {
    r = stack.top();
    stack.pop();
    l = stack.top();
    stack.pop();
    i = l;
    j = r;
    middlePoint = ((l + r) / 2);
    while (i < j)
    {
      while (array[i] < array[middlePoint])
      {
        i++;
      }
      while (array[middlePoint] < array[j])
      {
        j--;
      }
      if (i <= j)
      {
        std::swap(array[i], array[j]);
        i++;
        j--;
      }
    }
    if (l < j)
    {
      stack.push(l);
      stack.push(j);
    }
    if (i < r)
    {
      stack.push(i);
      stack.push(r);
    }
  }
}

bool isSorted(int* array, int size)
{
  int count = 0;
  for (int i = 0; i < size - 1; i++)
  {
    if (array[i] <= array[i + 1])
    {
      count++;
    }
  }
  if (count == size - 1)
  {
    return true;
  }
  return false;
}