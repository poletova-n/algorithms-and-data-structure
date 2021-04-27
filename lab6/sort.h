#ifndef SORT_H
#define SORT_H

template<typename T>
void bubbleSort(T *array, size_t size)
{
  int i = 0;
  bool isSwapped = true;
  while (isSwapped)
  {
    isSwapped = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        std::swap(array[j], array[j + 1]);
        isSwapped = true;
      }
    }
    i++;
  }
}

template<typename T>
void countingSort(T *array, const size_t size)
{
  T max = array[0];
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  T min = array[0];
  for (size_t i = 0; i < size; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }

  T *counter = new T[max - min + 1];
  for (size_t i = 0; i < max - min + 1; i++)
  {
    counter[i] = 0;
  }

  for (size_t i = 0; i < size; i++)
  {
    counter[array[i] - min]++;
  }
  int i = 0;
  for (size_t j = 0; j < max - min + 1; j++)
  {
    while (counter[j] != 0)
    {
      array[i++] = j + min;
      counter[j]--;
    }
  }
  delete[] counter;
}

template<typename T>
void mergeSort(T *array, const size_t size)
{
  T *tempArray = new T[size];
  int right, rightEnd;
  int i, j, tempIndex;
  for (int k = 1; k < size; k *= 2)
  {
    for (int left = 0; left + k < size; left += k * 2)
    {
      right = left + k;
      rightEnd = right + k;
      if (rightEnd > size)
      {
        rightEnd = size;
      }
      tempIndex = left;
      i = left;
      j = right;
      while (i < right && j < rightEnd)
      {
        if (array[i] <= array[j])
        {
          tempArray[tempIndex] = array[i++];
        }
        else
        {
          tempArray[tempIndex] = array[j++];
        }
        tempIndex++;
      }
      while (i < right)
      {
        tempArray[tempIndex++] = array[i++];
      }
      while (j < rightEnd)
      {
        tempArray[tempIndex++] = array[j++];
      }
      for (tempIndex = left; tempIndex < rightEnd; tempIndex++)
      {
        array[tempIndex] = tempArray[tempIndex];
      }
    }
  }
  delete[] tempArray;
}

#endif
