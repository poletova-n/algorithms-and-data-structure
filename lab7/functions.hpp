#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

template <class T>
void print(const T& container, std::ostream& output)
{
  for (auto i = container.begin(); i != container.end(); i++)
  {
    output << *i << " ";
  }
}

template <class T>
void sort(T& container)
{
  for (size_t i = 0; i < container.size() - 1; i++)
  {
    for (size_t j = i + 1; j < container.size(); j++)
    {
      if (container[i] > container[j])
      {
        auto temp = container[i];
        container[i] = container[j];
        container[j] = temp;
      }
    }
  }
}

#endif