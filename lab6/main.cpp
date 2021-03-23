#include <iostream>
#include <random>
#include <ctime>
#include <chrono>

#include "sort-algorithms.hpp"

void demonstrateSort(void (int*, size_t));

void testShakerSortTime();

void testCountingSortTime();

void testHeapSortTime();

void fillArrayWithRandom(int*& array, size_t size);

void print(int*, size_t, std::ostream&);

void measureSortTime(void (int*, size_t), int*, size_t);

int main()
{
  std::cout << "Shaker sort demonstration:\n";
  demonstrateSort(shakerSort);
  testShakerSortTime();

  std::cout << "\nCounting sort demonstration:\n";
  demonstrateSort(countingSort);
  testCountingSortTime();

  std::cout << "\nHeap sort demonstration:\n";
  demonstrateSort(heapSort);
  testHeapSortTime();

  return 0;
}

void demonstrateSort(void sort(int*, size_t))
{
  const int size = 14;
  int* averageArray = new int[size];
  fillArrayWithRandom(averageArray, size);
  std::cout << "Before:\n";
  print(averageArray, size, std::cout);
  sort(averageArray, size);
  std::cout << "After:\n";
  print(averageArray, size, std::cout);
  delete[] averageArray;
}

void testShakerSortTime()
{
  const int size = 1000;
  std::cout << "\nShaker sort tests with arrays of 1000 ints:\n";

  std::cout << "Average case:\n";
  int* averageArray = new int[size];
  fillArrayWithRandom(averageArray, size);
  measureSortTime(shakerSort, averageArray, size);
  delete[] averageArray;

  std::cout << "Worst case (all elements are in reverse order):\n";
  int* worstArray = new int[size];
  for (int i = 0; i < size; i++) {
    worstArray[i] = size - i;
  }
  measureSortTime(shakerSort, worstArray, size);
  delete[] worstArray;

  std::cout << "Best case (all elements are in correct order):\n";
  int* bestArray = new int[size];
  for (int i = 0; i < size; i++) {
    bestArray[i] = i;
  }
  measureSortTime(shakerSort, bestArray, size);
  delete[] bestArray;
}

void testCountingSortTime()
{
  const int size = 1000;
  std::cout << "\nCounting sort tests with arrays of 1000 ints:\n";

  std::cout << "Average case (maximum difference between elements is under 10.000):\n";
  int* averageArray = new int[size];
  fillArrayWithRandom(averageArray, size);
  measureSortTime(countingSort, averageArray, size);
  delete[] averageArray;

  std::cout << "Worst case (maximum difference between elements is 1.000.000):\n";
  int* worstArray = new int[size];
  for (int i = 0; i < size; i++) {
    worstArray[i] = i * i;
  }
  measureSortTime(countingSort, worstArray, size);
  delete[] worstArray;

  std::cout << "Best case (maximum difference between elements is 1):\n";
  int* bestArray = new int[size];
  for (int i = 0; i < size; i++) {
    bestArray[i] = (i % 2) + 1;
  }
  measureSortTime(countingSort, bestArray, size);
  delete[] bestArray;
}

void testHeapSortTime()
{
  const int size = 1000;
  std::cout << "\nHeap sort tests with arrays of 1000 ints:\n";

  std::cout << "Average case:\n";
  int* averageArray = new int[size];
  fillArrayWithRandom(averageArray, size);
  measureSortTime(heapSort, averageArray, size);
  delete[] averageArray;

  std::cout << "Worst case (every heapify in first cycle results in swap):\n";
  int* worstArray = new int[size];
  for (int i = 0; i < size / 2; i++) {
    worstArray[i] = size - i;
    worstArray[2 * i + 1] = worstArray[i] + i;
    worstArray[2 * i + 1 + size % 2] = worstArray[i] + size;
  }
  measureSortTime(heapSort, worstArray, size);
  delete[] worstArray;
  std::cout << "In general worst case should be very close to average case\n";

  std::cout << "Best case (no heapify results in swap):\n";
  int* bestArray = new int[size];
  for (int i = 0; i < size / 2; i++) {
    bestArray[i] = 1;
  }
  measureSortTime(heapSort, bestArray, size);
  delete[] bestArray;
}

void fillArrayWithRandom(int*& array, size_t size)
{
  const int min = 0;
  const int max = 10000;
  static std::default_random_engine engine(time(nullptr));
  std::uniform_int_distribution<int> distribution(min, max);
  for (int i = 0; i < size; i++) {
    array[i] = distribution(engine);
  }
}

void print(int* array, size_t size, std::ostream& out)
{
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      out << " ";
    }
    out << array[i];
  }
  out << '\n';
}

void measureSortTime(void sort(int*, size_t), int* array, size_t size)
{
  auto startTime = std::chrono::steady_clock::now();
  sort(array, size);
  auto endTime = std::chrono::steady_clock::now();
  std::cout << "Duration of sort: " << (endTime - startTime).count() << " nanoseconds\n";
}
