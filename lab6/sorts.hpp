#ifndef SORTS_HPP
#define SORTS_HPP

#include<cmath>
#include<iostream>
#include<queue>

int binarySearchForInsertionSort(int data, int* array, int left, int right)
{
  if (right <= left) {
    return (data > array[left] ? left + 1 : left);
  }
  else {
    int midPoint = (left + right) / 2;
    if (array[midPoint] < data) {
      return binarySearchForInsertionSort(data, array, midPoint + 1, right);
    }
    else if (array[midPoint] > data) {
      return binarySearchForInsertionSort(data, array, left, midPoint - 1);
    }
    else if (array[midPoint] == data) {
      return midPoint+1;
    }
  }
}

void insertionSort(int* array, int size)
{
  if (size <= 0) {
    std::cerr << "Size must be posititve value\n";
  }
  int data;
  for (int i = 0; i < size; i++) {
    int currentIndex = i;
    data = array[i];
    int needIndex = binarySearchForInsertionSort(data, array, 0, currentIndex);
    while (currentIndex > needIndex) {
      array[currentIndex] = array[currentIndex - 1];
      currentIndex--;
    }
    array[currentIndex] = data;
  }
}

int findMaxForRadixSort(int* array, int size)
{
  int max = array[0];
  for (int i = 1; i < size; i++) {
    max = (array[i] > max) ? array[i] : max;
  }
  return max;
}

void radixSort(int* array, int size)
{
  int max = findMaxForRadixSort(array, size);
  std::queue<int> temp[10];
  for (int n = 1; n <= max; n *= 10) {
    for (int i = 0; i < size; i++) {
      temp[(array[i] / n) % 10].push(array[i]);
    }
    int k = 0;
    for (int j = 0; j < 10; j++) {
      while (!temp[j].empty()) {
        array[k++] = temp[j].front();
        temp[j].pop();
      }
    }
  }
}

//step(1) = size/2; step(i) = step(i-1)/2
void shellSortWithShellStep(int* array, int size)
{
  for (int step = size / 2; step > 0; step /= 2) {
    for (int i = step; i < size; i++) {
      int temp = array[i];
      int j;
      for (j = i; j >= step && array[j - step] > temp; j -= step) {
        array[j] = array[j - step];
      }
      array[j] = temp;
    }
  }
}

//we used "2^(k) < size < 2^(k+1)" and find first step with formula "step = 2^(k) - 1"
//for example, with out size = 10, we have k = 3 and first step = 7
//next "step = 2^(k-1) - 1" where k = 2 and second step = 3
//and last step = 1
void shellSortWithHibbardStep(int* array, int size)
{
  int k = 0;
  k = (int)(log(size) / log(2));
  for (int step = pow(2, k) - 1; k > 0; k--, step = pow(2,k) - 1) {
    for (int i = step; i < size; i++) {
      int temp = array[i];
      int j;
      for (j = i; j >= step && array[j - step] > temp; j -= step) {
        array[j] = array[j - step];
      }
      array[j] = temp;
    }
  }
}

//for counting first Sedgewick's step
int increment(int* array, int size) {
  int p1 = 1, p2 = 1, p3 = 1, s = -1;
  do {
    if (++s % 2) {
      array[s] = 8 * p1 - 6 * p2 + 1;
    }
    else {
      array[s] = 9 * p1 - 9 * p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
    p1 *= 2;
  } while (3 * array[s] < size);

  return s > 0 ? --s : 0;
}

void shellSortWithSedgewickStep(int* array, int size)
{
  int step, i, j, tempArray[40];
  int s = increment(tempArray, size);
  while (s >= 0) {
    step = tempArray[s--];
    for (i = step; i < size; i++) {
      int temp = array[i];
      for (j = i; j >= step && array[j - step] > temp; j -= step)
        array[j] = array[j - step];
      array[j] = temp;
    }
  }
}

#endif
