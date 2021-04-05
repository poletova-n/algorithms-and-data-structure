#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "SortingFunctions.h"

void testInsertionSort();
void testBucketSort();
void testQuickSort();

template <typename T>
void sortTime(void sort(T*, int), T* array, int size);

int main()
{
 srand(time(0));
 testInsertionSort();
 std::cout << "\n\n";
 testBucketSort();
 std::cout << "\n\n";
 testQuickSort();
 return 0;

}
void testInsertionSort()
{
  const int size = 20;
  int averageArray[size] = {1,6,3,8,7,9,4,13,17,0,10,5,11,19,14,18,2,15,16,12};
  std::cout << "--Average case for insertion sort-- \nBefore sort:\n";
  print(averageArray, size);
  //insertionSort(averageArray, size);
  sortTime(insertionSort, averageArray, size);
  std::cout << "After sort: \n";
  print(averageArray, size);
  std::cout << "\n";

  int bestArray[size] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
  std::cout << "--Best case for insertion sort-- \nBefore sort:\n";
  print(bestArray, size);
  //insertionSort(bestArray, size);
  sortTime(insertionSort, bestArray, size);
  std::cout << "After sort: \n";
  print(bestArray, size);
  std::cout << "\n";

  int worstArray[size] = { 19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
  std::cout << "--Worst case for insertion sort-- \nBefore sort:\n";
  print(worstArray, size);
  //insertionSort(worstArray, size);
  sortTime(insertionSort, worstArray, size);
  std::cout << "After sort: \n";
  print(worstArray, size);
  std::cout << "\n";
  }

void testBucketSort()
{
  const int size = 20;
  double averageArray[size];
  for (int i = 0; i < size;i++)
  {
    averageArray[i] = (0 + rand() % 100) * 0.01;
  }
  std::cout << "--Average case for bucket sort-- \nBefore sort:\n";
  print(averageArray, size);
  //bucketSort(averageArray, size);
  sortTime(bucketSort, averageArray, size);
  std::cout << "After sort: \n";
  print(averageArray, size);
  std::cout << "\n";

  double bestArray[size];
  for (int i = 0; i < size;i++)
  {
    bestArray[i] = i*0.01;
  }
  std::cout << "--Worst case for bucket sort-- \nBefore sort:\n";
  print(bestArray, size);
  //bucketSort(bestArray, size);
  sortTime(bucketSort, bestArray, size);
  std::cout << "After sort: \n";
  print(bestArray, size);
  std::cout << "\n";

  double worstArray[size];
  for (int i = 0; i < size;i++)
  {
    worstArray[i] = 0.99 - (i * 0.01);
  }
  std::cout << "--Best case for bucket sort-- \nBefore sort:\n";
  print(worstArray, size);
  //bucketSort(worstArray, size);
  sortTime(bucketSort, worstArray, size);
  std::cout << "After sort: \n";
  print(worstArray, size);
  std::cout << "\n";
}

void testQuickSort()
{
  const int size = 20;
  int averageArray[size] = { 1,6,3,8,7,9,4,13,17,0,10,5,11,19,14,18,2,15,16,12 };
  std::cout << "--Average case for quick sort-- \nBefore sort:\n";
  print(averageArray, size);
  //quickSort(averageArray, size);
  sortTime(quickSort, averageArray, size);
  std::cout << "After sort: \n";
  print(averageArray, size);
  std::cout << "\n";

  int bestArray[size] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };
  std::cout << "--Best case for quick sort-- \nBefore sort:\n";
  print(bestArray, size);
  //quickSort(bestArray, size);
  sortTime(quickSort, bestArray, size);
  std::cout << "After sort: \n";
  print(bestArray, size);
  std::cout << "\n";

  int worstArray[size] = { 1,3,5,7,9,11,13,15,17,19,0,2,4,6,8,10,12,14,16,18 };
  std::cout << "--Worst case for quick sort-- \nBefore sort:\n";
  print(worstArray, size);
  //quickSort(worstArray, size);
  sortTime(quickSort, worstArray, size);
  std::cout << "After sort: \n";
  print(worstArray, size);
  std::cout << "\n";
}

template<typename T>
void sortTime(void sort(T*, int), T* array, int size)
{
  auto t1 = std::chrono::high_resolution_clock::now();
  sort(array, size);
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "Sort time: " << duration << " microseconds\n";
 /* auto start = std::chrono::steady_clock::now();
  sort(array, size);
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "Sort time: " << elapsed_seconds.count() << "s\n";*/
}
