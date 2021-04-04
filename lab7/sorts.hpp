#ifndef LAB7_SORTS_HPP
#define LAB7_SORTS_HPP

#include <cstddef>

namespace sort
{
  size_t getDigitCount(const int* array, size_t size);

  void count(int* array, size_t size);

  void radix(int* array, size_t size);

  void bucket(int* array, size_t size);
}

#endif
