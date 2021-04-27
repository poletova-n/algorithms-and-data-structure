#include <iostream>

#include "sorts.h"

void printArray(int* array, int size);
void testInsertSort();
void testCountSort();
void testPyramidSort();

int main()
{
  testInsertSort();
  testCountSort();
  testPyramidSort();
  return 0;
}

void printArray(int* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    std::cout << array[i];
    if (i < size - 1)
    {
      std::cout << ' ';
    }
  }
  std::cout << '\n';
}

void testInsertSort()
{
  std::cout << "Insert Sort Test\n";

  const int size = 10;
  std::cout << "Least complexity:\n";
  int array1[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  printArray(array1, size);
  std::cout << "Sorted array:\n";
  doInsertSort(array1, size);
  printArray(array1, size);

  std::cout << "Middle complexity:\n";
  int array2[size] = { 34, 2, 45, 6, 9, 60, 67, 10, 70, 25 };
  printArray(array2, size);
  std::cout << "Sorted array:\n";
  doInsertSort(array2, size);
  printArray(array2, size);

  std::cout << "Highest complexity:\n";
  int array3[size] = { 90, 70, 68, 56, 30, 26, 23, 6, 2, -6 };
  printArray(array3, size);
  std::cout << "Sorted array:\n";
  doInsertSort(array3, size);
  printArray(array3, size);

  std::cout << '\n';
}

void testCountSort()
{
  std::cout << "Count Sort Test\n";

  const int size = 10;
  std::cout << "Least complexity:\n";
  int array1[size] = { -10, -4, 0, 3, 17, 58, 66, 79, 101, 125 };
  printArray(array1, size);
  std::cout << "Sorted array:\n";
  doCountSort(array1, size);
  printArray(array1, size);

  std::cout << "Middle complexity:\n";
  int array2[size] = { 12, 18, -5, -2, 29, 1, 34, 5, 40, 9 };
  printArray(array2, size);
  std::cout << "Sorted array:\n";
  doCountSort(array2, size);
  printArray(array2, size);

  std::cout << "Highest complexity:\n";
  int array3[size] = { 87, 76, 56, 45, 43, 40, 38, 35, 27, 24 };
  printArray(array3, size);
  std::cout << "Sorted array:\n";
  doCountSort(array3, size);
  printArray(array3, size);

  std::cout << '\n';
}

void testPyramidSort()
{
  std::cout << "Pyramid Sort Test\n";

  const int size = 10;
  std::cout << "Least complexity:\n";
  int array1[size] = { -45, -39, -35, -34, -29, -24, -20, -18, 0, 1 };
  printArray(array1, size);
  std::cout << "Sorted array:\n";
  doPyramidSort(array1, size);
  printArray(array1, size);

  std::cout << "Middle complexity:\n";
  int array2[size] = { 2, 5, 10, 12, 20, 18, 17, 15, 11, 3 };
  printArray(array2, size);
  std::cout << "Sorted array:\n";
  doPyramidSort(array2, size);
  printArray(array2, size);

  std::cout << "Highest complexity:\n";
  int array3[size] = { 7, 5, 3, 1, -4, -10, -12, -27, -30, -39 };
  printArray(array3, size);
  std::cout << "Sorted array:\n";
  doPyramidSort(array3, size);
  printArray(array3, size);
}
