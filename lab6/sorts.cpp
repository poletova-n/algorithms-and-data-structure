#include <cstdlib>
#include <algorithm>
#include <stack>
#include <ostream>
#include <iostream>

void shakerSort(int *array, size_t size)
{
  int left, right, i;
  left = 0;
  right = size - 1;
  while (left <= right)
  {
    for (i = right; i > left; i--)
    {
      if (array[i - 1] > array[i])
      {
        int temp;
        temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
      }
    }
    left++;
    for (i = left; i <= right; i++)
    {
      if (array[i - 1] > array[i])
      {
        int temp;
        temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
      }
    }
    right--;
  }
}

void bucketSort(int * array, size_t size)
{
  const int max = size;
  int bucket[10][max+1];
  for(size_t x = 0; x < 10; x++)
    bucket[x][max] = 0;
  for(int digit = 1; digit <= 1000000000; digit *= 10)
  {
    for(size_t i = 0; i < max; i++)
    {
      int dig = (array[i] / digit) % 10;
      bucket[dig][bucket[dig][max]++] = array[i];
    }
    size_t idx = 0;
    for(size_t i = 0; i < 10; i++)
    {
      for(size_t j = 0; j < bucket[i][max]; j++)
      {
        array[idx++] = bucket[i][j];
      }
      bucket[i][max] = 0;
    }
  }
}


void quickSort(int *array, size_t size)
{
  int mid, left, right, l, r;
  mid = left = right = l = r = 0;
  std::stack <int> st;

  st.push(size - 1);
  st.push(0);
  do {
    left = st.top();
    st.pop();
    right = st.top();
    st.pop();
    {
      mid = array[(left + right) / 2];
      l = left;
      r = right;
      while (l < r)
      {
        while (array[l] < mid)
        {
          l++;
        }
        while (mid < array[r])
        {
          r--;
        }
        if (l <= r)
        {
          std::swap(array[l], array[r]);
          l++;
          r--;
        }
      }
    }
    if (left < r)
    {
      st.push(r);
      st.push(left);
    }
    if (l < right)
    {
      st.push(right);
      st.push(l);
    }
  } while (!st.empty());
}
