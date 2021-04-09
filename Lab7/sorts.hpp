#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>



namespace utility
{
  class Predicate
  {
  public:
    Predicate(int offset):
      bit_(offset)
    {}
    bool operator()(int value) const 
    {
      if (bit_ == 31)
        return value < 0;
      else
        return !(value & (1 << bit_));
    }
  private:
    const int bit_;
  };

  std::vector<int> createVector(size_t size);
  std::vector<double> createDoubleVector(size_t size);

  int findMax(std::vector<int> vec);

  int findMin(std::vector<int> vec);

  template <class Predicate>
  std::vector<int>::iterator partition(std::vector<int>::iterator first,
                                       std::vector<int>::iterator last,
                                       Predicate predicate);

  void msd(std::vector<int>::iterator first, std::vector<int>::iterator second, int msb = 31);

  template <class T>
  void print(std::vector<T> print);

  template <class T>
  bool isSorted(std::vector<T> vec);
}

namespace sorts
{
  std::vector<int> countingSort(std::vector<int> vec);

  std::vector<int> radixSort(std::vector<int> vec);

  std::vector<int> bucketSort(std::vector<int> vec, int size);
}

template <class T>
void utility::print(std::vector<T> vec)
{
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';
}


template <class T>
bool utility::isSorted(std::vector<T> vec)
{
  for (size_t i = 0; i < vec.size() - 1; ++i)
  {
    if (vec[i] > vec[i - 1])
    {
      return false;
    }
  }
  return true;
}

#endif
