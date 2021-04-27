#include <iostream>
#include "sortingFunctions.hpp"

int main() {
  std::cout << "Testing bubble sort\n";
  const int size = 8;
  std::cout << "\nBest case {1,2,3,4,5,6,7,8}\n";
  int bestCase1[size] = {1, 2, 3, 4, 5, 6, 7,8};
  bubbleSort(bestCase1, size);
  for (int i :bestCase1)
  {
    std::cout << i << " ";
  }
  std::cout << "\nWorst case {30,10,5,20,3,2,2,1}\n";
  int worstCase1[size] = {30, 10, 5, 20, 3, 2, 2, 1};
  bubbleSort(worstCase1, size);
  for (int i :worstCase1)
  {
    std::cout << i << " ";
  }
  std::cout << "\nMiddle case {5,3,10,7,20,25,60,90}\n";
  int middleCase1[size] = {5, 3, 10, 7, 20, 25, 60, 90};
  bubbleSort(middleCase1, size);
  for (int i :middleCase1)
  {
    std::cout << i << " ";
  }

  std::cout << "\n\nTesting radix sort\n";

  std::cout << "\nBest case {1,2,3,4,5,6,7,8}\n";
  int bestCase2[size] = { 1, 2, 3, 4, 5, 6, 7, 8};
  radixSort(bestCase2, size);
  for (int i :bestCase2)
  {
    std::cout << i << " ";
  }
  std::cout << "\nWorst case {100,50,25,80,75,95,10,5}\n";
  int worstCase2[size] = { 100, 50, 25, 80, 75, 95, 10, 5};
  radixSort(worstCase2, size);
  for (int i :worstCase2)
  {
    std::cout << i << " ";
  }
  std::cout << "\nMiddle case {5,65,10,7,15,20,60,100}\n";
  int middleCase2[size] = { 5, 65, 10, 7, 15, 20, 60, 100};
  radixSort(middleCase2, size);
  for (int i :middleCase2)
  {
    std::cout << i << " ";
  }

  std::cout<<"\n\nTesting quick sort\n";

  std::cout << "\nBest case {1,2,3,4,5,6,7,8}\n";
  int bestCase[size] = {1, 2, 3, 4, 5, 6, 7, 8};
  quickSort(bestCase, size);
  for (int i :bestCase)
  {
    std::cout << i << " ";
  }
  std::cout << "\nWorst case {1,3,7,10,1,1,3,7}\n";
  int worstCase [size] = {1, 3, 7, 10, 1, 1, 3, 7};
  quickSort(worstCase, size);
  for (int i :worstCase)
  {
    std::cout << i<< " ";
  }
  std::cout << "\nMiddle case {1,7,10,3,5,7,1,3}\n";
  int middleCase [size] = {1, 7, 10, 3, 5, 7, 1, 3};
  quickSort(middleCase, size);
  for (int i :middleCase)
  {
    std::cout << i << " ";
  }
  return 0;
}
