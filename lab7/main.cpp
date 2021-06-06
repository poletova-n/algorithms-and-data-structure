#include <iostream>
#include "Sort.hpp"

void printArray(int* array, int size);
void checkErrors(int size);

int main()
{
  std::cout << "Please write the numbers you want to sort and their quantity:" << '\n';
  int size;
  int size2;
  int size3;
  {
    std::cout << "Quantity: ";
    std::cin >> size;
    checkErrors(size);
    std::cout << "Numbers:\n";
    int array[size];
    for (int i = 0; i < size; ++i)
    {
      std::cin >> array[i];
      checkErrors(size);
    }
    try
    {
      std::cout << "Counting sort\n";
      printArray(array, size);
      countingSort(array, size);
      printArray(array, size);
    }
    catch (const std::logic_error &error)
    {
      std::cout << error.what() << '\n';
    }
    sorted(array, size);
  }
  {
    std::cout << "\nRadix sort\n"
              << "Quantity: ";
    std::cin >> size2;
    checkErrors(size2);
    std::cout << "Numbers:\n";
    int arrayTwo[size2];
    for (int i = 0; i < size2; ++i)
    {
      std::cin >> arrayTwo[i];
      checkErrors(size2);
    }
    printArray(arrayTwo, size2);
    radixSort(arrayTwo, size2);
    printArray(arrayTwo, size2);
    sorted(arrayTwo, size2);
  }
  {
    std::cout << "\nBucket sort\n"
              << "Quantity: ";
    std::cin >> size3;
    checkErrors(size3);
    std::cout << "Numbers:\n";
    int arrayThree[size3];
    for (int i = 0; i < size3; ++i)
    {
      std::cin >> arrayThree[i];
      checkErrors(size3);
    }
    printArray(arrayThree, size3);
    bucketSort(arrayThree, size3);
    printArray(arrayThree, size3);
    sorted(arrayThree, size3);
  }
  return 0;
}

void checkErrors(int size) {
  if (size < 0) {
    throw std::invalid_argument("Size can not be less then zero!");
  }
  if (std::cin.fail()) {
    throw std::invalid_argument("You must write only integer numbers!");
  }
}

void printArray(int *array, int size)
{
  for (int i = 0; i < size; ++i)
  {
    std::cout << " [" << array[i] << "] ";
  }
  std::cout << '\n';
}
