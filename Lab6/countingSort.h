#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>

template<typename T>
T getMax(const std::vector<T>& vect)
{
  T max = vect[0];
  for (size_t i = 0; i < vect.size(); ++i)
  {
    max = std::max(vect[i], max);
  }

  return max;
}

template<typename T>
T getMin(const std::vector<T>& vect)
{
  T min = vect[0];
  for (size_t i = 0; i < vect.size(); ++i)
  {
    min = std::min(vect[i], min);
  }

  return min;
}

template<typename T>
void countingSort(std::vector<T>& vect, int size)
{
  T max = getMax(vect);
  T min = getMin(vect);

  int z = 0;
  int length = max - min + 1;

  std::vector<T> count(length);
  for (size_t i = 0; i < count.size(); ++i)
  {
    count[i] = 0;
  }
  for (size_t i = 0; i < vect.size(); ++i)
  {
    count[vect[i] - min]++;
  }
  for (int i = min; i <= max; ++i)
  {
    while (count[i - min])
    {
      vect[z++] = i;
      count[i - min]--;
    }
  }
}

template<typename T>
void print(std::ostream& out, const std::vector<T>& vect, int size, const char* delimeter)
{
  for (int i = 0; i < size; i++)
  {
    out << vect[i] << delimeter;
  }

  out << std::endl;
}

#endif
