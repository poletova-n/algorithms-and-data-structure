#include <iostream>

#include "sorts.hpp"

void printArray(int *array, size_t count);

int main()
{
  size_t count = 8;
  std::cout << "BUBBLE SORT\n" << "Best case:\n";
  int bestCaseBubble[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "Source array: ";
  printArray(bestCaseBubble, count);
  bubbleSort(bestCaseBubble, count);
  std::cout << "Sorted array: ";
  printArray(bestCaseBubble, count);

  std::cout << "\nMiddle case:\n";
  int middleCaseBubble[8] = {1, 3, 2, 4, 5, 7, 6, 8};
  std::cout << "Source array: ";
  printArray(middleCaseBubble, count);
  bubbleSort(middleCaseBubble, count);
  std::cout << "Sorted array: ";
  printArray(middleCaseBubble, count);

  std::cout << "\nWorst case:\n";
  int worstCaseBubble[8] = {8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Source array: ";
  printArray(worstCaseBubble, count);
  bubbleSort(worstCaseBubble, count);
  std::cout << "Sorted array: ";
  printArray(worstCaseBubble, count);

  std::cout << "\nBUCKET SORT\n" << "Best case:\n";
  int bestCaseBucket[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "Source array: ";
  printArray(bestCaseBucket, count);
  bubbleSort(bestCaseBucket, count);
  std::cout << "Sorted array: ";
  printArray(bestCaseBucket, count);

  std::cout << "\nMiddle case:\n";
  int middleCaseBucket[8] = {1, 2, 4, 3, 5, 8, 6, 7};
  std::cout << "Source array: ";
  printArray(middleCaseBucket, count);
  bubbleSort(middleCaseBucket, count);
  std::cout << "Sorted array: ";
  printArray(middleCaseBucket, count);

  std::cout << "\nWorst case:\n";
  int worstCaseBucket[8] = {8, 7, 6, 5, 4, 3, 2, 1};
  std::cout << "Source array: ";
  printArray(worstCaseBucket, count);
  bubbleSort(worstCaseBucket, count);
  std::cout << "Sorted array: ";
  printArray(worstCaseBucket, count);

  std::cout << "\nHEAP SORT\n" << "Best case:\n";
  int bestCaseHeap[8] = {8, 8, 8, 8, 8, 8, 8, 8};
  std::cout << "Source array: ";
  printArray(bestCaseHeap, count);
  bubbleSort(bestCaseHeap, count);
  std::cout << "Sorted array: ";
  printArray(bestCaseHeap, count);

  std::cout << "\nMiddle case:\n";
  int middleCaseHeap[8] = {1, 2, 5, 3, 4, 8, 6, 7};
  std::cout << "Source array: ";
  printArray(middleCaseHeap, count);
  bubbleSort(middleCaseHeap, count);
  std::cout << "Sorted array: ";
  printArray(middleCaseHeap, count);

  std::cout << "\nWorst case:\n";
  int worstCaseHeap[8] = {1, 3, 2, 4, 6, 5, 8, 7};
  std::cout << "Source array: ";
  printArray(worstCaseHeap, count);
  bubbleSort(worstCaseHeap, count);
  std::cout << "Sorted array: ";
  printArray(worstCaseHeap, count);

  return 0;
}

void printArray(int *array, size_t count)
{
  for (size_t i = 0; i < count; i++)
  {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}
