#include <iostream>

#include "sorts.h"
#include "print.h"

int main()
{
  int element;

  std::vector<int> vector1;
  while (!std::cin.eof() || std::cin.fail())
  {
    std::cin >> element;
    vector1.push_back(element);
  }
  if (!std::cin.eof())
  {
    std::cerr << "Input failed";
  }
  std::cin.clear();
  std::cin.seekg(0);

  sort1(vector1);
  print(vector1);

  std::vector<int> vector2;
  while (!std::cin.eof())
  {
    std::cin >> element;
    vector2.push_back(element);
  }
  if (!std::cin.eof() || std::cin.fail())
  {
    std::cerr << "Input failed";
  }
  std::cin.clear();
  std::cin.seekg(0);

  sort2(vector2);
  print(vector2);

  std::vector<int> vector3;
  while (!std::cin.eof())
  {
    std::cin >> element;
    vector3.push_back(element);
  }
  if (!std::cin.eof() || std::cin.fail())
  {
    std::cerr << "Input failed";
  }
  std::cin.clear();
  std::cin.seekg(0);

  sort3(vector3);
  print(vector3);

  return 0;
}
