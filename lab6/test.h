#ifndef TEST_H
#define TEST_H

#include "sort.h"
#include <ctime>
#include <random>
#include <chrono>

template<typename T>
void initializeRandom(T *array, const size_t SIZE, const size_t BITNESS = 1000)
{
  srand(time(0));
  for (size_t i = 0; i < SIZE; i++)
  {
    array[i] = rand() % BITNESS + 1;
  }
}

template<typename T>
void printArray(T *array, const size_t size)
{
  for (int i = 0; i < size; ++i)
  {
    std::cout << array[i] << ' ';
  }
  std::cout << '\n';
}

template<typename T>
void printSort(void (*sort)(T *array, const size_t size), T *array, const size_t size)
{
  std::cout << "Before: ";
  printArray(array, size);
  sort(array, size);
  std::cout << "After: ";
  printArray(array, size);
  std::cout << '\n';
}

template<typename T>
void test(T *array, const size_t SIZE, void (*sort)(T *array, const size_t SIZE))
{
  auto BEGIN = std::chrono::high_resolution_clock::now();
  sort(array, SIZE);
  auto END = std::chrono::high_resolution_clock::now();
  std::chrono::duration<long double> RESULT = END - BEGIN;
  std::cout << "Time of sort: " << RESULT.count() << '\n';
}


void testOfBubbleSort()
{
  const size_t SIZE1 = 8;
  int array1[SIZE1];
  initializeRandom(array1, SIZE1, 7);
  printSort(bubbleSort, array1, SIZE1);

  const size_t SIZE2 = 8;
  int array2[SIZE2];
  initializeRandom(array2, SIZE2, 19);
  printSort(bubbleSort, array2, SIZE2);

  const size_t SIZE3 = 8;
  int array3[SIZE3];
  initializeRandom(array3, SIZE3, 61);
  printSort(bubbleSort, array3, SIZE3);
}

void testOfCountingSort()
{
  const size_t SIZE1 = 16;
  int array1[SIZE1];
  initializeRandom(array1, SIZE1, 3);
  printSort(countingSort, array1, SIZE1);

  const size_t SIZE2 = 5;
  int array2[SIZE2];
  initializeRandom(array2, SIZE2, 7);
  printSort(countingSort, array2, SIZE2);

  const size_t SIZE3 = 2;
  int array3[SIZE3];
  initializeRandom(array3, SIZE3, 34);
  printSort(countingSort, array3, SIZE3);

  const size_t SIZE4 = 8;
  int array4[SIZE4];
  initializeRandom(array4, SIZE4, 678);
  printSort(countingSort, array4, SIZE4);
}

void testOfMergeSort()
{
  const size_t SIZE1 = 4;
  int array1[SIZE1];
  initializeRandom(array1, SIZE1, 55);
  printSort(mergeSort, array1, SIZE1);

  const size_t SIZE2 = 20;
  int array2[SIZE2];
  initializeRandom(array2, SIZE2, 20);
  printSort(mergeSort, array2, SIZE2);

  const size_t SIZE3 = 13;
  int array3[SIZE3];
  initializeRandom(array3, SIZE3, 9);
  printSort(mergeSort, array3, SIZE3);

  const size_t SIZE4 = 6;
  int array4[SIZE4];
  initializeRandom(array4, SIZE4, 43);
  printSort(mergeSort, array4, SIZE4);
}

#endif
