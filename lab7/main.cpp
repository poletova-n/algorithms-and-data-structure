#include <iostream>
#include <vector>
#include "sort.h"

int main()
{
  std::cout << "\n<------count sort------>\n";

  std::cout << "unsorted array: ";
  std::vector<int> firstArr = {34, 75, 18, 63, 88, 49, 40, 24, 94};
  print(firstArr);
  std::cout << "\n";
  countingSort(firstArr);
  std::cout << "sorted array: ";
  print(firstArr);
  std::cout << "\n";


  std::cout << "\n<------radix sort------>\n";

  std::vector<int> secondArr = {61, 48, 49, 24, 86, 124, 73, 33, 37, 19};
  std::cout << "unsorted array: ";
  print(secondArr);
  std::cout << "\n";
  radixSort(secondArr);
  std::cout << "sorted array: ";
  print(secondArr);
  std::cout << "\n";


  std::cout << "\n<------bucket sort------>\n";

  std::cout << "unsorted array: ";
  std::vector<int> thirdArr = {33,56,1,54,86,26,64,65,54,22,55,64,57,54,6};
  print(thirdArr);
  std::cout << "\n";
  bucketSort(thirdArr);
  std::cout << "sorted array: ";
  print(thirdArr);
  std::cout << "\n";

std::cout << "\n<------insertion sort------>\n";

  std::cout << "unsorted array: ";
  std::vector<int> fourthArr = {33,56,1,54,86,26,64,65,54,22,55,64,57,54,6};
  print(fourthArr);
  std::cout << "\n";
  insertionSort(fourthArr);
  std::cout << "sorted array: ";
  print(fourthArr);
  std::cout << "\n";

  std::cout << "\n<------Shell sort------>\n";

  std::cout << "unsorted array: ";
  std::vector<int> fifthArr = {33,56,1,54,86,26,64,65,54,22,55,64,57,54,6};
  print(fifthArr);
  std::cout << "\n";
  shellSort(fifthArr);
  std::cout << "sorted array: ";
  print(fifthArr);
  std::cout << "\n";

  return 0;
}
