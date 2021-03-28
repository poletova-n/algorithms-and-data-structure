#ifndef TESTS_HPP
#define TESTS_HPP

#include "sorts.hpp"
#include<iostream>

void printArray(int* array, int size);
bool isTestedCorrect(int* array, int size);
void testingInsertionSort();
void testingRadixSort();
void testingShellSort();

void printArray(int* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

bool isTestCorrect(int* array, int size)
{
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (array[i] > array[j]) {
        return false;
      }
    }
  }
  return true;
}

void testingInsertionSort()
{
  const int size = 10;
  std::cout << "Best case\n";
  int array[size] = { 0, 1, 3, 6, 8, 12, 15, 18, 23, 34 };
  std::cout << "Before sorting: ";
  printArray(array, size);
  insertionSort(array, size);
  std::cout << "After sorting: ";
  printArray(array, size);
  if (isTestCorrect(array, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  std::cout << "\nMiddle case\n";
  int array1[size] = { 4, 3, 5, 8, 15, 16, 1, 9, 23, 54 };
  std::cout << "Before sorting: ";
  printArray(array1, size);
  insertionSort(array1, size);
  std::cout << "After sorting: ";
  printArray(array1, size);
  if (isTestCorrect(array1, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  std::cout << "\nWorst case\n";
  int array2[size] = { 90, 80, 70, 60, 50, 40, 30, 20, 10, 1 };
  std::cout << "Before sorting: ";
  printArray(array2, size);
  insertionSort(array2, size);
  std::cout << "After sorting: ";
  printArray(array2, size);
  if (isTestCorrect(array1, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";
}

void testingRadixSort()
{
  const int size = 10;
  std::cout << "Best case\n";
  int array[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::cout << "Before sorting: ";
  printArray(array, size);
  radixSort(array, size);
  std::cout << "After sorting: ";
  printArray(array, size);
  if (isTestCorrect(array, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  std::cout << "\nMiddle case\n";
  int array1[size] = { 23, 43, 65, 201, 302, 46, 396, 3, 31, 765 };
  std::cout << "Before sorting: ";
  printArray(array1, size);
  radixSort(array1, size);
  std::cout << "After sorting: ";
  printArray(array1, size);
  if (isTestCorrect(array1, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  std::cout << "\nWorst case\n";
  int array2[size] = { 11, 23, 47, 85, 647, 34, 102, 5, 91, 426 };
  std::cout << "Before sorting: ";
  printArray(array2, size);
  radixSort(array2, size);
  std::cout << "After sorting: ";
  printArray(array2, size);
  if (isTestCorrect(array2, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";
}

void testingShellSort()
{
  const int size = 10;
  std::cout << "Best case\n";
  int array[size] = { 2, 3, 5, 7, 8, 9, 11, 12, 15, 20 };
  int array1[size] = { 2, 3, 5, 7, 8, 9, 11, 12, 15, 20 };
  int array2[size] = { 2, 3, 5, 7, 8, 9, 11, 12, 15, 20 };
  std::cout << "Before sorting: ";
  printArray(array, size);

  shellSortWithShellStep(array, size);
  std::cout << "After sorting with Shell's step: ";
  printArray(array, size);
  if (isTestCorrect(array, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithHibbardStep(array1, size);
  std::cout << "After sorting with Hibbard's step: ";
  printArray(array1, size);
  if (isTestCorrect(array1, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithSedgewickStep(array2, size);
  std::cout << "After sorting with Sedgewick's step: ";
  printArray(array2, size);
  if (isTestCorrect(array2, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";


  std::cout << "\nMiddle case\n";
  int array3[size] = { 3, 5, 6, 32, 34, 65, 1, 87, 324, 10 };
  int array4[size] = { 3, 5, 6, 32, 34, 65, 1, 87, 324, 10 };
  int array5[size] = { 3, 5, 6, 32, 34, 65, 1, 87, 324, 10 };
  std::cout << "Before sorting: ";
  printArray(array3, size);

  shellSortWithShellStep(array3, size);
  std::cout << "After sorting with Shell's step: ";
  printArray(array3, size);
  if (isTestCorrect(array3, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithHibbardStep(array4, size);
  std::cout << "After sorting with Hibbard's step: ";
  printArray(array4, size);
  if (isTestCorrect(array4, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithSedgewickStep(array5, size);
  std::cout << "After sorting with Sedgewick's step: ";
  printArray(array5, size);
  if (isTestCorrect(array5, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";


  std::cout << "\nWorst case\n";
  int array6[size] = { 932, 532, 435, 32, 65, 23, 123, 1, 5, 10 };
  int array7[size] = { 932, 532, 435, 32, 65, 23, 123, 1, 5, 10 };
  int array8[size] = { 932, 532, 435, 32, 65, 23, 123, 1, 5, 10 };
  std::cout << "Before sorting: ";
  printArray(array6, size);

  shellSortWithShellStep(array6, size);
  std::cout << "After sorting with Shell's step: ";
  printArray(array6, size);
  if (isTestCorrect(array6, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithHibbardStep(array7, size);
  std::cout << "After sorting with Hibbard's step: ";
  printArray(array7, size);
  if (isTestCorrect(array7, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";

  shellSortWithSedgewickStep(array8, size);
  std::cout << "After sorting with Sedgewick's step: ";
  printArray(array8, size);
  if (isTestCorrect(array8, size))
    std::cout << "Test work correct\n";
  else
    std::cout << "Test work uncorrect\n";
}

#endif
