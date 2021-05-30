#include "sorts.hpp"

#include <iostream>
#include <cmath>

size_t sort::getDigitCount(const int* array, size_t size)
{
  size_t maxCountDigits = 0;
  for (size_t i = 0; i < size; ++i)
  {
    int temp = array[i];
    size_t tempCounter = 0;
    while (temp != 0)
    {
      temp /= 10;
      ++tempCounter;
    }
    maxCountDigits = std::max(maxCountDigits, tempCounter);
  }
  return maxCountDigits;
}

void sort::count(int* array, size_t size)
{
  int maxNumber = 0;
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] < 0)
    {
      throw std::invalid_argument("Number in array must be more than 0.");
    }
    if (array[i] > maxNumber)
    {
      maxNumber = array[i];
    }
  }
  size_t sizeOfMassive = maxNumber + 1;
  int massive[sizeOfMassive];
  for (size_t i = 0; i < sizeOfMassive; ++i)
  {
    massive[i] = 0;
  }
  for (size_t i = 0; i < size; ++i)
  {
    ++massive[array[i]];
  }
  size_t count = 0;
  for (size_t i = 0; i <= maxNumber; ++i)
  {
    while (massive[i] != 0)
    {
      array[count] = i;
      ++count;
      --massive[i];
    }
  }
}

void sort::radix(int* array, size_t size)
{
  size_t maxDigitCount = getDigitCount(array, size);
  int maxNumber = static_cast<int>(std::pow(10, maxDigitCount));
  int temp[size];
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] < 0)
    {
      throw std::invalid_argument("Number in array must be more than 0.");
    }
  }
  for (size_t j = 1; j < maxNumber; j *= 10)
  {
    int digits[10] = {0};
    for (size_t i = 0; i < size; ++i)
    {
      ++digits[(array[i] / j) % 10];
    }
    for (size_t i = 1; i < 10; ++i)
    {
      digits[i] += digits[i - 1];
    }
    for (size_t i = 0; i < size; ++i)
    {
      temp[--digits[(array[size - i - 1] / j) % 10]] = array[size - i - 1];
    }
    for (size_t i = 0; i < size; ++i)
    {
      array[i] = temp[i];
    }
  }
}

void sort::bucket(int* array, size_t size)
{
  const size_t N = 10;
  size_t maxNumber = std::pow(10, getDigitCount(array, size));
  size_t loopStep = maxNumber / N;
  size_t length = size + 1;
  int massive[N][length];
  for (size_t i = 0; i < size; ++i)
  {
    if (array[i] < 0)
    {
      throw std::invalid_argument("Number in array must be more than 0.");
    }
  }
  for (size_t i = 0; i < N; ++i)
  {
    for (size_t j = 0; j < size; ++j)
    {
      massive[i][j] = INT_MAX;
    }
    massive[i][size] = 0;
  }
  for (size_t i = 0; i < size; ++i)
  {
    size_t iNumber = static_cast<size_t>(array[i]) / loopStep;
    int* counter = &massive[iNumber][size];
    if (*counter == 0)
    {
      massive[iNumber][0] = array[i];
      ++(*counter);
      continue;
    }
    for (size_t j = 0; j <= *counter; ++j)
    {
      if (array[i] < massive[iNumber][j])
      {
        for (size_t k = 0; k <= *counter - j; ++k)
        {
          massive[iNumber][*counter - k] = massive[iNumber][*counter - k - 1];
        }
        massive[iNumber][j] = array[i];
        ++(*counter);
        break;
      }
    }
  }
  size_t j = 0;
  size_t k = 0;
  for (size_t i = 0; i < size; ++i)
  {
    while (massive[j][size] == 0)
    {
      ++j;
      k = 0;
    }
    array[i] = massive[j][k++];
    --massive[j][size];
  }
}
