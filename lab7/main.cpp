#include <iostream>
#include <limits>
#include <vector>
#include "sorts.hpp"

int main()
{
  std::vector<int> vector;
  size_t size = 0;
  std::cout << "Input int numbers for sort it:\n";
  while (true)
  {
    int input;
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    vector.push_back(input);
    ++size;
  }
  int* arrayForCount = vector.data();

  int arrayForRadix[size];
  for (size_t i = 0; i < size; ++i)
  {
    arrayForRadix[i] = arrayForCount[i];
  }

  int arrayForBucket[size];
  for (size_t i = 0; i < size; ++i)
  {
    arrayForBucket[i] = arrayForCount[i];
  }

  try
  {
    sort::count(arrayForCount, size);
  }
  catch (std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return 1;
  }

  std::cout << "After count sort: ";
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arrayForCount[i] << ' ';
  }

  try
  {
    sort::radix(arrayForRadix, size);
  }
  catch (std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return 1;
  }

  std::cout << "\nAfter radix sort: ";
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arrayForRadix[i] << ' ';
  }

  try
  {
    sort::bucket(arrayForBucket, size);
  }
  catch (std::invalid_argument& exception)
  {
    std::cerr << exception.what();
    return 1;
  }

  std::cout << "\nAfter bucket sort: ";
  for (size_t i = 0; i < size; ++i)
  {
    std::cout << arrayForBucket[i] << ' ';
  }

  return 0;
}