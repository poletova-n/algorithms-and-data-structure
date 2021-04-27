#ifndef SORTS_PRINT_H
#define SORTS_PRINT_H

#include <vector>

#include "sorts.h"

void print(std::vector<int> &vec)
{
  for(size_t i = 0; i != vec.size(); i++)
  {
    std::cout << vec[i] << " ";
  }
  std::cout << "\n";
  std::cout << "Checking correct work of sorting: " << std::boolalpha << correctSorting(vec);
  std::cout << "\n\n";
}

#endif
