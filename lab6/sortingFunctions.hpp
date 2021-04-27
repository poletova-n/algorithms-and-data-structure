#ifndef SORTING_FUNCTIONS_HPP
#define SORTING_FUNCTIONS_HPP

#include <exception>
#include <algorithm>
#include <stack>
#include <iostream>

void bubbleSort(int*arr, size_t size)
{
  bool b = true;
  int i = 0;
  while (b)
  {
    b = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        std::swap(arr[j], arr[j + 1]);
        b = true;
      }
    }
    i++;
  }
}
void radixSort(int* arr, int size) {
  if (size <= 0) {
    throw std::exception("Size must be >=0");
  }
  int max = arr[0];
  for (int i = 1; i < size; i++)
  {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  for (int i = 1; max / i > 0; i *= 10) {
    int* out = new int[size];
    int c[10] = { 0 };
    for (int j = 0; j < size; j++){
      c[(arr[j] / i) % 10]++;
    }
    for (int j = 1; j < 10; j++) {
      c[j] += c[j-1];
    }
    for (int j = size-1; j >= 0; j--) {
      out[c[(arr[j] / i) % 10] - 1] = arr[j];
      c[(arr[j] / i) % 10]--;
    }
    for (int j = 0; j < size; j++) {
      arr[j] = out[j];
    }
    delete[] out;
  }
}
void quickSort(int *array, size_t size)
{
  std::stack <int> stack;
  stack.push(0);
  stack.push(size - 1);
  int  middle, l, r, l1, r1;
  while (!stack.empty())
  {
    r = stack.top();
    stack.pop();
    l = stack.top();
    stack.pop();
    l1 = l;
    r1 = r;
    middle = ((l + r) / 2);
    while (l1 < r1)
    {
      while (array[l1] < array[middle])
      {
        l1++;
      }
      while (array[middle] < array[r1])
      {
        r1--;
      }
      if (l1 <= r1)
      {
        std::swap(array[l1], array[r1]);
        l1++;
        r1--;
      }
    }
    if (l1 < r)
    {
      stack.push(l1);
      stack.push(r);
    }
    if (l < r1)
    {
      stack.push(l);
      stack.push(r1);
    }
  }
}

#endif
