#include <algorithm>
#include "sorts.h"

void countingSort(int* arr, size_t size, size_t maxNumber)
{
  int* count = new int[maxNumber];
  for (size_t i = 0; i < maxNumber; ++i) {
    count[i] = 0;
  }

  for (size_t i = 0; i < size; ++i) {
    ++count[arr[i]];
  }

  size_t pos = 0;

  for (size_t i = 0; i < maxNumber; ++i) {
    for (size_t j = 0; j < count[i]; ++j) {
      arr[pos] = i;
      ++pos;
    }
  }
}

int getMax(const int A[], size_t n)
{
  int i = 1;
  int max = A[0];
  for (; i < n; i++) {
    if (A[i] > max)
      max = A[i];
  }
  return max;
}

void radixSort(int A[], size_t n)
{
  size_t i, digitPos = 1;
  int result[n];
  int maxNumber = getMax(A, n);
  while (maxNumber / digitPos > 0) {
    int count[10] = {0};
    for (i = 0; i < n; ++i) {
      ++count[(A[i] / digitPos) % 10];
    }
    for (i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; --i) {
      result[count[(A[i] / digitPos) % 10] - 1] = A[i];
      --count[(A[i] / digitPos) % 10];
    }
    for (i = 0; i < n; ++i) {
      A[i] = result[i];
    }
    digitPos *= 10;
  }
}

void bucketSort(int arr[], size_t size)
{
  int bucket[10][size + 1];
  for (size_t x = 0; x < 10; x++)
    bucket[x][size] = 0;
  for (int digit = 1; digit <= 1000000000; digit *= 10) {
    for (size_t i = 0; i < size; ++i) {
      int dig = (arr[i] / digit) % 10;
      bucket[dig][bucket[dig][size]++] = arr[i];
    }
    size_t idx = 0;
    for (size_t i = 0; i < 10; ++i) {
      for (size_t j = 0; j < bucket[i][size]; ++j) {
        arr[idx++] = bucket[i][j];
      }
      bucket[i][size] = 0;
    }
  }
}