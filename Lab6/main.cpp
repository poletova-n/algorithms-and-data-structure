#include <iostream>
#include <vector>

#include "countingSort.h"
#include "quickSort.h"
#include "pyramidSort.h"

void one()
{
  int size = 5;
  std::vector<int> intVect;
  std::cout << "Enter elements:" << std::endl;
  for (int i = 0; i < size; i++)
  {
    int input;
    std::cin >> input;

    intVect.push_back(input);
  }
  std::cout << "Array before Sorting: ";
  print(std::cout, intVect, size, " ");
  countingSort(intVect, size);
  std::cout << "Array after Sorting: ";
  print(std::cout, intVect, size, " ");
  std::cout << std::endl;
}

void two()
{
  std::vector<char> charVect;
  std::cout << "Enter elements:" << std::endl;
  char input;
  while (true)
  {
    std::cin >> input;
    if (input == '0')
    {
      break;
    }

    charVect.push_back(input);
  }
  std::cout << "Array before Sorting: ";
  print(std::cout, charVect, charVect.size(), "");
  countingSort(charVect, charVect.size());
  std::cout << "Array after Sorting: ";
  print(std::cout, charVect, charVect.size(), "");
  std::cout << std::endl;
}

void countingSortDemo()
{
  one();
  two();
}

void quickSortDemo()
{
  std::vector<int> arr = { 4, 3, 5, 2, 1, 3, 2, 3 };

  quickSort(arr, 0, arr.size() - 1);

  print(std::cout, arr, arr.size(), " ");
  std::cout << std::endl;
}

void pyramidSortDemo()  //Also known as heap sort
{
  std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };

  pyramidSort(arr, arr.size());

  print(std::cout, arr, arr.size(), " ");
  std::cout << std::endl;
}

int main()
{
  countingSortDemo();
  quickSortDemo();
  pyramidSortDemo();

  return 0;
}
